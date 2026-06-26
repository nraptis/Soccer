#include "TwistExpander_Badminton_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Badminton_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCD665ED16BFEA663ULL + 0xA8DCF620794CA3F0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEE8B0FF9CAF8785BULL + 0xBE86526C5A8BB2C7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xECBCBF8BB949D29BULL + 0xDCC080AF926BD3F1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8DB831A50753618FULL + 0x9F5E43195EC1BA66ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x842D9A10A46B6A69ULL + 0x9702A57B2E590AF2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9D8C5E22E7331AC3ULL + 0xC6C5481E23F736F7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE9AFBB671F12392FULL + 0x8CDB5CA1B29FC46BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE0091507A95FB9CBULL + 0x9F4C48B7BEE8102CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDAEDBF2934E97A5DULL + 0xC96D76682D7342DDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCABC54A9CD9EF5EDULL + 0xB6A9C575A0C4F95EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAC3E37341D6EEEBBULL + 0xDABFDBC6207096B9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD67D142893CD046DULL + 0xC30674C987025950ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE2536D947D546051ULL + 0x92765B90B17824A6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9CA4218403113F59ULL + 0xEAC553AB621FEF82ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x805103ACAEC44287ULL + 0x86DA7FEC61EC3A50ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBEBD6291EFBF3041ULL + 0xD700AC501487A1DAULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2714U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((aIndex + 2673U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3790U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1380U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 19U)) + (RotL64(aCross, 38U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 44U)) + 2571116506511057880U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 21U)) + 13112435411509707292U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 57U)) + 10403251762787357256U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 8461951095541400405U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 9890793478557463815U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 19U)) + 3030229465991783707U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 37U)) + 7273848154043719247U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 51U)) + 10681774862516028276U) + aNonceWordO;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 39U)) + 7105082755586853104U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 11U)) + 6588579345319551129U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 54U)) + RotL64(aCarry, 21U)) + 14616333550242386092U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15439666290229654921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3360304356760164799U;
            aOrbiterE = RotL64((aOrbiterE * 5164191920584106237U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14438730801970761889U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14515616787452085729U;
            aOrbiterA = RotL64((aOrbiterA * 2041601927968559821U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4167853822635132419U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8950982233003320239U;
            aOrbiterH = RotL64((aOrbiterH * 887144270884244907U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12391327853728029953U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7100871010552394421U;
            aOrbiterI = RotL64((aOrbiterI * 16552349374101955967U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15381697462381887944U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6801677551341079401U;
            aOrbiterB = RotL64((aOrbiterB * 13325954438427340703U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 947011315719204867U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6356920162398333481U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5566721941682667419U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8910262020598577378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8778455415977526457U;
            aOrbiterG = RotL64((aOrbiterG * 4092470497616637283U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5585696961453127223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9670655481681494412U;
            aOrbiterK = RotL64((aOrbiterK * 7863197168965036383U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10713004007087085729U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4036355047492922339U;
            aOrbiterD = RotL64((aOrbiterD * 6923922258047667173U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14580156873863533497U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7049502932205025182U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 8665428649262370727U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 12707521269341941677U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2571116506511057880U;
            aOrbiterF = RotL64((aOrbiterF * 2388236789245943699U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 54U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterB, 37U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 4U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aScatter, 18U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterD, 29U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 22U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterD, 53U)) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7686U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7218U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 10852U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7370U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 40U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 57U)) + 701291026547470433U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 3U)) + 17283292650462111643U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 19U)) + 9969124091931303406U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aCross, 11U)) + 889176772718046988U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererB + RotL64(aScatter, 37U)) + 6054541844643748084U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 39U)) + 14703226235143028132U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 21U)) + 7977975878522921062U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 16894322614172266274U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 12160451749345900570U) + aNonceWordP;
            aOrbiterC = (aWandererC + RotL64(aCross, 53U)) + 10870847008043897470U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 44U)) + 8159920947172520247U) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2440099120969517932U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2428396147731468007U;
            aOrbiterE = RotL64((aOrbiterE * 9363073341539598441U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2213226274394673479U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7079731443427765333U;
            aOrbiterJ = RotL64((aOrbiterJ * 16918930776877030559U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 958896789550478970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10788682955708075458U;
            aOrbiterD = RotL64((aOrbiterD * 913321215613559729U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2003386579317564870U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8419686358774204999U;
            aOrbiterA = RotL64((aOrbiterA * 6547052526438697621U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6989167615157578904U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 17636634003643824148U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11038576417283732937U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13824962118933907859U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9543912892587859646U;
            aOrbiterK = RotL64((aOrbiterK * 14736710162285997415U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15729878041027706114U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9542137475454825463U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11420547128115090491U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5327302277575009955U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2707383132257428583U;
            aOrbiterB = RotL64((aOrbiterB * 6120763309390182129U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9008601903853562620U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11050463189491777908U;
            aOrbiterH = RotL64((aOrbiterH * 9178386878636430553U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14683684132116778056U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 5390271065690907120U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 17903005409098232619U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5183407290520277451U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 701291026547470433U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 16329261100139524239U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 6U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 40U) + RotL64(aOrbiterK, 39U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterB, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 58U)) + aOrbiterB) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15464U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 12344U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 13542U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((aIndex + 13387U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 22U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererA + RotL64(aScatter, 21U)) + 6068543441070417854U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 35U)) + 2995980468193441856U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 39U)) + 18020277482171594003U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 60U)) + 4293807434721230702U;
            aOrbiterK = (aWandererE + RotL64(aCross, 41U)) + 7980599111583893156U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 53U)) + 8593141111851052016U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 5903487523900084325U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 15112035513447930209U) + aNonceWordE;
            aOrbiterH = (aWandererH + RotL64(aCross, 11U)) + 9854037263057006439U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 14U)) + 16759760289688823193U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 12622628933030601390U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1264668857268123425U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16302812053619101593U;
            aOrbiterC = RotL64((aOrbiterC * 18291400055836111547U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16087995784896123610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7970269262800468363U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 14924752223305807461U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5331477046030959632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16534913204255550893U;
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11042821902537871209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8069677512345031660U;
            aOrbiterK = RotL64((aOrbiterK * 13622218526054132397U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 5737130058129936372U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1076627182956662997U;
            aOrbiterI = RotL64((aOrbiterI * 14342191224014199929U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13911061091801078190U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15397603151098990373U;
            aOrbiterJ = RotL64((aOrbiterJ * 1802890451633592245U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15137326716738637972U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11248737008959896786U;
            aOrbiterF = RotL64((aOrbiterF * 90789374131547005U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1847847987633923657U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10560748778679145431U;
            aOrbiterB = RotL64((aOrbiterB * 2919333327817231099U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2703726238610290251U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12950671360471467310U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7490327691501537047U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10331504168520449467U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1541527607705280906U;
            aOrbiterH = RotL64((aOrbiterH * 14197400812600186171U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9135056476214341809U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6068543441070417854U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14102524444094948875U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 56U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 6U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 23U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterC, 21U)) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterK, 37U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 19U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 60U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19221U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17254U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19477U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18638U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 20U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 58U)) + 1888427424966603593U;
            aOrbiterF = (aWandererH + RotL64(aCross, 21U)) + 5436761445660415091U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 17322876217962143270U) + aNonceWordP;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 29U)) + 9728299982740564979U) + aNonceWordB;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 301720335271716921U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 37U)) + 8069685428854814396U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 39U)) + 1973715500949100991U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 87666408799854155U) + aNonceWordG;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 56U)) + 12195436904339035245U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 43U)) + 4578742069143400295U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 35U)) + 7828776048774876484U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17203146364542781833U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16913369550858890466U;
            aOrbiterB = RotL64((aOrbiterB * 13534417587921978507U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9632761514552265402U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9106637671877341286U;
            aOrbiterC = RotL64((aOrbiterC * 9073709119482640391U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15423680889126750876U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 6087310684583331882U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 8964465129744898619U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5420955876411796789U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14166807419730848032U;
            aOrbiterD = RotL64((aOrbiterD * 442659738632823751U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8118312450347026824U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4253043584558403086U;
            aOrbiterK = RotL64((aOrbiterK * 5651748455190536467U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8810774678371762700U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12218479555589447835U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11026364205248516355U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11389930523582876358U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16334420553471379915U;
            aOrbiterH = RotL64((aOrbiterH * 13830132212033904777U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18201289372553710279U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7196540389657785361U;
            aOrbiterG = RotL64((aOrbiterG * 13058135202554889791U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2601046573550065116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2243003381737071984U;
            aOrbiterI = RotL64((aOrbiterI * 10518763530499878945U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6058992247656841580U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10083863011670540073U;
            aOrbiterF = RotL64((aOrbiterF * 17908394295613117155U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8505005026063156940U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1888427424966603593U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18298382581929885653U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 18U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterK, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 10U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 12U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterI, 19U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26154U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 25049U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25559U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 26963U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 27U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 14U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 26U)) + 6469584119078165548U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 23U)) + 14329756366517987910U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 12890831797059772123U;
            aOrbiterE = (aWandererD + RotL64(aCross, 5U)) + 3164503807500018990U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 47U)) + 177531431387646836U;
            aOrbiterC = (aWandererI + RotL64(aCross, 38U)) + 3167421392893561015U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 2813174781844753460U) + aNonceWordO;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 41U)) + 10953270419153249857U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 16911518309710356951U) + aNonceWordL;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 29U)) + 6616750447844893150U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 21U)) + 10276741398025985982U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6206043608461213208U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12021552904553405793U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10023362889960174909U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15283586234744144846U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5923238786775948571U;
            aOrbiterC = RotL64((aOrbiterC * 8200882393521882651U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11044014510971660078U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9351141024085076044U;
            aOrbiterJ = RotL64((aOrbiterJ * 13316079344614432317U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17703395981862992420U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10154548848376027087U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 12324478347590509035U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8836420852291617425U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10193385413543886344U;
            aOrbiterI = RotL64((aOrbiterI * 824935982418585449U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8248580084535685190U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3910083671888152974U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 17825311776715895927U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12350341628569930642U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2565977481575002842U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18233446879833776677U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9271041067874027417U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14289254596554201861U;
            aOrbiterK = RotL64((aOrbiterK * 7985522692852251413U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5981802134118235214U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14047813418129636856U;
            aOrbiterD = RotL64((aOrbiterD * 15961435325216504877U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11808443842149398212U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11380858372643695792U;
            aOrbiterH = RotL64((aOrbiterH * 100198424024622179U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10385375464069162356U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6469584119078165548U;
            aOrbiterF = RotL64((aOrbiterF * 5263876933019848989U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + aNonceWordI);
            aWandererD = aWandererD + ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterG, 23U));
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 18U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterA, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 34U)) + aOrbiterD) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32745U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28610U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32637U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29364U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 9855743441035905047U;
            aOrbiterA = (aWandererD + RotL64(aCross, 53U)) + 8426286937143990276U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 35U)) + 7146752367170267002U) + aNonceWordD;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 11U)) + 12947210066678101726U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 24U)) + 15902163559925328965U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 8506649889346449469U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 29U)) + 8226286036430263052U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 2703047093452420216U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 18U)) + 6769351326360139560U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 27U)) + 9857025533281333281U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 3U)) + 238297452132277585U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7203572312072908931U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12497027346166575632U;
            aOrbiterI = RotL64((aOrbiterI * 1703586436725662307U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 473851890609048879U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1664484956453886047U;
            aOrbiterJ = RotL64((aOrbiterJ * 8566500756326590209U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4635095143004754116U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17695676150967345793U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 5780416541584439301U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15628965269863402796U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9190117464399730235U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 5586437438425999715U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17835918238346011086U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4398005402429282682U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 14828737209913317463U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10902589938246551273U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15124274429081385923U;
            aOrbiterH = RotL64((aOrbiterH * 13524180348258805367U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8747233520702236018U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5445611443463112371U;
            aOrbiterE = RotL64((aOrbiterE * 10294109295823410447U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16296005217836151910U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6468336224317602364U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7369779919748367133U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3827976387089403774U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7773383658122100111U;
            aOrbiterC = RotL64((aOrbiterC * 9784711300597525161U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 18273794621528918389U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8401424792700263455U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13003420427441089595U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11402828934846813949U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9855743441035905047U;
            aOrbiterG = RotL64((aOrbiterG * 7339549576423555273U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 28U)) + aOrbiterH) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 30U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterC, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 21U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_Badminton_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB1FEE5F55000E9E9ULL + 0xA39F917B442DA529ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF724F0742A44453FULL + 0xDF6BB0F2EB44AC89ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE93DF0898C6B6F21ULL + 0xC1C157AA030DC53EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC1E48E721DBF2795ULL + 0x987F8DAF2BE91E46ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x943129BCCD0E9EC5ULL + 0xCCE871CC73DA8712ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC3A394627DC50A6BULL + 0xAC543F38A99A9E69ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA81326800EA57A29ULL + 0xC09A0A3BFBEE09F3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xABF088A716D265D9ULL + 0x94EE703A3BD5AA3BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB1D48B4A3B72EB67ULL + 0xA2A7363C51A3618AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x86545243AB24F71FULL + 0xC8D9DFB087ED572FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE9248CF208D9BEC5ULL + 0xDA1850F36BC56562ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB94C3FA439C43655ULL + 0xC168F6C8300A528BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD96D1DB2AE35A3BFULL + 0xD2FFEAA79BF1FEABULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x974E4FFD783B8B59ULL + 0xBD6A4439443E3136ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE467858B434A9A43ULL + 0xC294AFCEC23C052EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9EE64F1189DDB619ULL + 0xB9B7DCE2B676F3A4ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5816U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7763U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6293U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5563U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererG + RotL64(aIngress, 5U)) + 7948891781097675369U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 13928362874228230226U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 10776180542602258926U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 24U)) + 5735115172149470447U) + aNonceWordJ;
            aOrbiterF = (aWandererA + RotL64(aScatter, 51U)) + 5353591822981766987U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 19U)) + 562301708107268570U) + aNonceWordC;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 10467810247578364868U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aCross, 29U)) + 14541630141152308564U) + aNonceWordL;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 58U)) + 2350076897065139429U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17519109078651162228U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6061035173339902910U;
            aOrbiterK = RotL64((aOrbiterK * 10021905773432907835U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15654836633731000065U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13723521735153718904U;
            aOrbiterI = RotL64((aOrbiterI * 14459516479283070563U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2849680038315532197U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17336102435576647923U;
            aOrbiterH = RotL64((aOrbiterH * 10984689101753586739U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7671010488872356142U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11485114338165600777U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 4162584865462407791U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8759060657343458985U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11009137869375286581U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8741417343929809115U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15792999392743144135U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6180808423175992479U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13681230339693676907U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 361487389591183005U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15292753806514404853U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17478232597253311153U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14929153438443362045U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7904556383593914086U;
            aOrbiterC = RotL64((aOrbiterC * 2484130486635511403U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3793180909904286848U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10391957637467171320U;
            aOrbiterF = RotL64((aOrbiterF * 505484041943467117U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 54U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 30U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterC, 26U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterA, 11U));
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 38U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9626U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15578U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11856U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9236U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 48U)) + 2786079456995203065U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 53U)) + 7237256119153857253U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 9310834010563647604U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 17361734905706517877U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 57U)) + 15837111231884647451U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 11U)) + 18065431964418026445U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 43U)) + 3029123922999952652U) + aNonceWordL;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 5166926595573507837U) + aNonceWordJ;
            aOrbiterE = (aWandererK + RotL64(aCross, 28U)) + 1918425684273807598U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4724551751012661440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1818014487579644390U;
            aOrbiterB = RotL64((aOrbiterB * 14904092108647864911U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6670090372241084216U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8485757110007268693U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11876760095108618363U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4928130251509514742U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2528788422725346792U;
            aOrbiterF = RotL64((aOrbiterF * 1855982047967756661U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2860387120895147503U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12927802338151379368U;
            aOrbiterJ = RotL64((aOrbiterJ * 8876144125458603029U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 18029699867733207083U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13361836994951253312U;
            aOrbiterE = RotL64((aOrbiterE * 5349767426256597073U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11957294454794128079U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3755417922063414648U;
            aOrbiterI = RotL64((aOrbiterI * 13896364063651241401U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18001157153447913032U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16214145724690286854U;
            aOrbiterK = RotL64((aOrbiterK * 5874139687703360515U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3860958772090975562U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12395621524459640173U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 722817135977510161U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3402035664910754484U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2139099117325745602U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14008983756425796029U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 5U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aCross, 42U) + RotL64(aOrbiterB, 28U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 44U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + aNonceWordM) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19062U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 16825U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17305U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23405U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 40U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aPrevious, 19U)) + 12849591986267890852U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 60U)) + 8232614804696815750U;
            aOrbiterG = ((((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 12141567259210877281U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aWandererI + RotL64(aScatter, 5U)) + 2928641981037885644U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 47U)) + 980733350554783938U) + aNonceWordB;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 2683985177993350746U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 14532148403815527355U;
            aOrbiterB = (aWandererH + RotL64(aCross, 54U)) + 7736296629433884203U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 13U)) + 10428437770166310549U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18327174144859461029U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6810436935194432002U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2715987179577753597U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12606153309690753435U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17123256945895150555U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13469111258504672565U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9057777759026189541U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16478485918911194442U;
            aOrbiterI = RotL64((aOrbiterI * 11054247078884894131U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18064460487552100483U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11477276762421684083U;
            aOrbiterJ = RotL64((aOrbiterJ * 3886501230380184395U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18318375441973295081U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13849305985380030986U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12962140243967824959U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10240409420338313641U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 18360586077779529086U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 18196875422391501927U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16801797158622424257U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4950305991208513887U;
            aOrbiterD = RotL64((aOrbiterD * 4437082499761416951U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15790878572843321918U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9808781805065559728U;
            aOrbiterB = RotL64((aOrbiterB * 9394280083159162953U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11974996650410830731U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4955004489435232515U;
            aOrbiterH = RotL64((aOrbiterH * 13301966529515483085U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (RotL64(aOrbiterH, 26U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterD, 11U));
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + RotL64(aOrbiterG, 24U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 19U));
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterF, 36U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterB, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 24759U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 26355U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24787U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31579U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 36U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 51U)) + 12136097566601676613U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 35U)) + 7969431322248040056U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 26U)) + 10530676021510553889U) + aNonceWordB;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 8740777303075445264U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 57U)) + 13249434169895564739U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 15529577005925628472U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 344627093687331562U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 6U)) + 8824277416519988893U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 39U)) + 5636276438449709875U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2079413361031851552U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7807998179168655561U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 961456853699784753U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13589392896232029112U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10733011474804473996U;
            aOrbiterA = RotL64((aOrbiterA * 361749145931578805U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15934162328347805968U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7573511217796245232U;
            aOrbiterH = RotL64((aOrbiterH * 10694563909931636155U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4828475187337891975U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13284974329890393113U;
            aOrbiterB = RotL64((aOrbiterB * 10831075817642374287U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13173869918669643112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15841507674783398167U;
            aOrbiterE = RotL64((aOrbiterE * 15632933198136963277U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14168272451055700516U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11134471485501999898U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8019507184494591705U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2611858916687822610U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17863271539727513641U;
            aOrbiterK = RotL64((aOrbiterK * 4987884722174985677U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8874401993454249066U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5131480593493950665U;
            aOrbiterJ = RotL64((aOrbiterJ * 8585874663602346121U), 53U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 9366563022381918996U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7890729519928340296U;
            aOrbiterI = RotL64((aOrbiterI * 11428572374057899517U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 50U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 52U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterA, 6U));
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 12U) + aOrbiterB) + RotL64(aOrbiterI, 60U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Badminton_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8B80E31B06E34CA7ULL + 0xBA58B41C41179F6BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9231ED6ABBAF96F7ULL + 0xABCB6287ED06824DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x84BE943807FC200DULL + 0x9D706549A41D4650ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x853BE150279D9893ULL + 0xE5EEB739E7BE9772ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA2761203FC8D393FULL + 0xE6F780CD77060EF3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC094FFA07AAD13DDULL + 0xA41CEC9BD1C5A69CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC4CD52A55B14173DULL + 0x97E85DC834D98269ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8857D2B2E801BB93ULL + 0xFE66EDB158D139EAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB4A760B57D503AF3ULL + 0xDE11565CE5EB0B61ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE096A80E74E98BD9ULL + 0xCE056FF6C8A3EFBDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9DEB971656E2B40BULL + 0xBD179B1B2E295448ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFD8834EAA4F5CBA9ULL + 0xC5042B2B4393D01CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEAEAEF47F583FC59ULL + 0x99F6C1CBCFBEBC50ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA3DDF26232FDFA57ULL + 0xE686C399050F4DE8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB1A6710DB68275BFULL + 0xD8856452D6B6BE92ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE2C7AD33FDB89BCDULL + 0xCBED064EFF659781ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5178U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2585U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 358U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2117U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 51U)) + 5576732410244514238U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 2833808925935929629U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 3670188682914544792U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 28U)) + RotL64(aCarry, 3U)) + 15759072378887814995U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 13U)) + 13934007231137439994U) + aNonceWordO;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11022225696007690512U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16989177104453635790U;
            aOrbiterC = RotL64((aOrbiterC * 14156758251105809453U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9256930045263527091U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17788596104417068290U;
            aOrbiterF = RotL64((aOrbiterF * 675554110563253305U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17044369456673337625U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1310908395523250343U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16305084373037705921U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 12067065689034065422U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15130844248737512262U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9409499577465934107U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14532689204495587494U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8198147292120244178U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 1418356389507740991U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 48U)) + aOrbiterA) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterJ, 3U)) + aNonceWordJ);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 21U)) + aNonceWordL) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9768U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 10274U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11959U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15461U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aPrevious, 20U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererK + RotL64(aScatter, 22U)) + RotL64(aCarry, 3U)) + 15904465836916519864U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 17725629806317789307U) + aNonceWordF;
            aOrbiterF = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 13794170125914914828U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 43U)) + 2149055907476874332U) + aNonceWordE;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 51U)) + 5342047776745074649U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8268148484060546838U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10821151364028563719U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13626634259250509711U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4294213820894407378U) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10884726101307943090U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1116128870387229159U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16432210042202444824U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 15196602644336228055U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 12680438355124070237U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14117787670220328165U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 219833877949480215U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 10736293047771972173U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3326396981881473962U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 14918513066311426279U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14269763278564574663U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 27U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 60U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererI = aWandererI + (((((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 39U)) + aNonceWordB) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordG);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19975U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 22580U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16717U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 20758U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 13U)) + (RotL64(aCarry, 56U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aCross, 51U)) + 17470880031634374199U) + aNonceWordE;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 21U)) + 757565846006937746U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 9419282475801345674U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 2014248014107898196U;
            aOrbiterD = ((((aWandererD + RotL64(aCross, 6U)) + RotL64(aCarry, 53U)) + 15113928519446490441U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7346126964886259935U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5594123113093162359U;
            aOrbiterB = RotL64((aOrbiterB * 18043634828891483403U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5659237263369402005U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11565709683423969703U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 16731289017588574671U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16782863743534856287U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13499100900072115907U;
            aOrbiterA = RotL64((aOrbiterA * 5567729598873214433U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11414447651044205242U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 7545993795121430538U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 10758488381206257261U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11778229237616454988U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2544793391976514665U;
            aOrbiterD = RotL64((aOrbiterD * 4021060413798523299U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 54U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 52U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 41U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30457U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 25793U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30841U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 31561U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 50U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 4U)) + 4622023259121087483U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 10253505250223501352U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 17133877904420462669U) + aNonceWordB;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 6162827793741796700U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 53U)) + 9610986424765907615U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11210747154264753754U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16554205219580654546U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12754735039924859911U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10352576357413766388U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3651845783283479752U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1011289824180799641U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18145542190463500476U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5415609566767162857U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6474184559323816389U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2033734872464201570U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3507213117125813345U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 5453058336688881113U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8716253393049851856U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 695984869565941856U;
            aOrbiterA = RotL64((aOrbiterA * 8377921610764044735U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 53U)) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterB, 48U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterB) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Badminton_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x923D1626DD32A84BULL + 0xF369723287336582ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB006AE07D4BB0AABULL + 0xA98273812504C645ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC08BBCA1A9C06F3DULL + 0x8E04A53B5A047320ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDA1FF5BEC94AC6B5ULL + 0xECE79578345E2FE3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF1F99E49FBEFFE43ULL + 0xFBF595CE5D8A482AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9321F8A104637049ULL + 0x86471BE84548568CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xED897953FA64249DULL + 0xD1C2BBB54059E985ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC20236693AEF6DA7ULL + 0x816E43812451BCFAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF9EC36563E726915ULL + 0xD80D986048D91057ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE7F879F6B882AF01ULL + 0x815330D651C5AFF4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xED6857C48CBB563FULL + 0xAA2E1C9B6F0AD678ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA2C47AD45A872673ULL + 0xFA9840AB4040D15EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEF69FE56673D71EFULL + 0xF211C4FE83F9E3E5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC62E6F6DD2D4FA5FULL + 0x835FB0BFD4E560A5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCC79F57BB569C0D7ULL + 0xCBE9E087F8D8789FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEC4A8A22749702BFULL + 0xAC9CE84C07B3D7C5ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 226U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4113U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7937U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5342U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 34U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 23U)) + 2617613537256538553U) + aNonceWordH;
            aOrbiterK = (aWandererA + RotL64(aCross, 43U)) + 16642868916835132715U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 29U)) + 10860291124337073254U) + aNonceWordB;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 6432511273906902472U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 7505375005848241910U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 11086616004678821329U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 36U)) + 3298830587569881951U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9775143140064220979U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4147601326580823120U;
            aOrbiterH = RotL64((aOrbiterH * 13462244678782260871U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12245920269898100415U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8391940489176734499U;
            aOrbiterE = RotL64((aOrbiterE * 9119606167674098007U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17876893379544668477U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 18301882058180370541U;
            aOrbiterI = RotL64((aOrbiterI * 16680384667098921309U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6869225862715140102U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15404118372589259800U;
            aOrbiterF = RotL64((aOrbiterF * 5766851935950389915U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17757381020518233814U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17677969146092374455U;
            aOrbiterJ = RotL64((aOrbiterJ * 3469432916562405063U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15783378556632870114U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5792858258663697864U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12008981883482080427U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11737803388202260296U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16001927091970715330U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 3062030309852922061U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 54U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterE, 37U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10215U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 11707U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9618U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14291U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 12046647397183218524U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 2760779375026461991U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 13735454443176855650U) + aNonceWordE;
            aOrbiterB = (aWandererK + RotL64(aCross, 57U)) + 4370377000586647724U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 42U)) + 14566322384189969094U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 35U)) + 5056565959818422786U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 27U)) + 8795403810686579209U) + aNonceWordP;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9625947666256011567U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1703669290934254701U;
            aOrbiterC = RotL64((aOrbiterC * 5763881345676123583U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6664070663184147951U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2104148316797553431U;
            aOrbiterA = RotL64((aOrbiterA * 12887842067180975983U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1197910004222596145U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9922977170060903197U;
            aOrbiterB = RotL64((aOrbiterB * 13047828062605568603U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2048376210852567829U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12568990647075931409U;
            aOrbiterH = RotL64((aOrbiterH * 9860242601194210927U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 15026894775772902751U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3439447160137900629U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1813754963043785165U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6532671388552829796U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17261098369835997661U;
            aOrbiterE = RotL64((aOrbiterE * 568292591215203521U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3171300991007459947U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5935563269327662024U;
            aOrbiterI = RotL64((aOrbiterI * 11271790283157765003U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 60U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 20U));
            aWandererK = aWandererK + ((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 34U) + aOrbiterA) + RotL64(aOrbiterH, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16614U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 24183U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17996U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 16394U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 4970414922752555648U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aIngress, 29U)) + 9462756592787669327U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 5U)) + 3948790686662213095U;
            aOrbiterD = (aWandererF + RotL64(aCross, 51U)) + 14542857212241578311U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 35U)) + 3387479009827029547U) + aNonceWordM;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 1411421370057797877U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 22U)) + RotL64(aCarry, 37U)) + 16894451466895681236U) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12727136462290223542U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4625389198191960525U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 5726474430977810191U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3471881403786164913U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6433115856048534831U;
            aOrbiterI = RotL64((aOrbiterI * 9363233870194144053U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9825592965466157982U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1553125767261293088U;
            aOrbiterK = RotL64((aOrbiterK * 411535191177308781U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9951616357109647617U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11231080382787286889U;
            aOrbiterD = RotL64((aOrbiterD * 14024961994986659187U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 13419663264017317947U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4835055642466215566U;
            aOrbiterF = RotL64((aOrbiterF * 17898065852351759171U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14558747666410946768U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13120938960926874504U;
            aOrbiterH = RotL64((aOrbiterH * 5681766019285559739U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11910501376797343986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15074100100781785300U;
            aOrbiterC = RotL64((aOrbiterC * 228976960937473851U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterD, 37U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + aNonceWordH);
            aWandererE = aWandererE + ((RotL64(aScatter, 50U) + RotL64(aOrbiterI, 30U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29939U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30633U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28326U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25025U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aCross, 53U)) + 8506388683755208267U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 41U)) + 2179323259055019735U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 3345902531140983016U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 60U)) + 17456139311481306584U) + aNonceWordK;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 11U)) + 14587864088462311164U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 13178947246650647057U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 12866578138946916962U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13098524333655118173U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15451329483787541982U;
            aOrbiterE = RotL64((aOrbiterE * 13580376920467431451U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9494299579678389385U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 15581954810375490643U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 13670002280188424825U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4487042505730624892U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2774455928791636186U;
            aOrbiterA = RotL64((aOrbiterA * 15847933919136777451U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12435319582397755819U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10077180055177766823U;
            aOrbiterB = RotL64((aOrbiterB * 3924363471701748703U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10391963896910956455U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6149237416725301794U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10115917698918612823U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15673402771629639978U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14729117178956592426U;
            aOrbiterH = RotL64((aOrbiterH * 9070464269215820531U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14492001279368870240U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6278248084483259952U;
            aOrbiterI = RotL64((aOrbiterI * 16731228350971263873U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 60U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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

void TwistExpander_Badminton_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8A3D76080C81C4D1ULL + 0xFBD076EB48CA3BFAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE0F896F6717775AFULL + 0xD6622AE30AB15148ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF9B5A276BA0EC773ULL + 0xEBA1E37CDD8EB55AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCB7E397AC1FA4983ULL + 0x9281F387C54F87EAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCE1386AA75677A9FULL + 0x87C3F7D399729A81ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8C817F6410A9925DULL + 0xC8195272CCAB592BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9D566C49224D755DULL + 0xF6B08D0E7EB3E6F4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE42C663F2AAA4B9BULL + 0xFB66CAF3B0A02D08ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAE16623BF71F324BULL + 0xE04E71AB9C0D77D5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD27925086956A037ULL + 0x85563DB3458FEBDCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x924431C4B75288A5ULL + 0xB92D6272C12E623CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB478C2369945C56FULL + 0xF1DBEF1B97717A5DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE399D451579C831BULL + 0xDBE4742EA8055DDCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x98E41FA2D69794D7ULL + 0xA5E3FDAD756675DAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEE31654E880B5E57ULL + 0x80C865816B2214D3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x979D9F863887C0D3ULL + 0xC73E9FD717F2E893ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 6859U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 6872U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2805U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 1222U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 29U)) + (RotL64(aCarry, 10U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererE + RotL64(aCross, 23U)) + 15920462086654025436U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aWandererD + RotL64(aScatter, 57U)) + 487844076858004017U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 29U)) + 14502883786442630566U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 47U)) + 3787107318658233674U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 12548777544693755491U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 4907309444075181683U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 14U)) + RotL64(aCarry, 39U)) + 18342396700266492072U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13503051997624242670U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17845742460521374571U;
            aOrbiterC = RotL64((aOrbiterC * 1366356786138085155U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8640887211877858169U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5273913123709097537U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 1661149444148461791U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17756844173695563883U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6713055830729302951U;
            aOrbiterH = RotL64((aOrbiterH * 2832836748513174311U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5106468334224035972U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10228769728713526172U;
            aOrbiterA = RotL64((aOrbiterA * 9760310686414358435U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7687649520668883142U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7757480627354711605U;
            aOrbiterG = RotL64((aOrbiterG * 7222553727737349209U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10876291698508634557U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8149278085586014186U;
            aOrbiterK = RotL64((aOrbiterK * 8577133863470695381U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15592893988925610485U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8639028256640537165U;
            aOrbiterI = RotL64((aOrbiterI * 1880655276432963955U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterK, 10U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 28U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aNonceWordB) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13882U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14609U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10152U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10778U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 51U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 21U)) + 7893287783892523139U) + aNonceWordL;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 44U)) + 10257331997383491153U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 14562226733652231753U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 14320342577110737851U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 27U)) + 9816717579822880756U) + aNonceWordI;
            aOrbiterC = ((aWandererG + RotL64(aCross, 37U)) + 9558926960095881953U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 9230371862654338324U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6414274291252913420U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13868546184398350849U;
            aOrbiterG = RotL64((aOrbiterG * 1547986864837497409U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16940736952569949038U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2866957764814864371U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3554702178644797003U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7916721976073979724U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1602444214978842275U;
            aOrbiterE = RotL64((aOrbiterE * 11072503711308122385U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9529061385251008037U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8402775110887376588U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13980225144628227381U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15003592180290390713U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14195681406520825751U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 11455000833788877217U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3263577002367714202U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12019422062655581928U;
            aOrbiterC = RotL64((aOrbiterC * 5002313835338447799U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8508638054582582917U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6536618106353552880U;
            aOrbiterD = RotL64((aOrbiterD * 6233964121117511885U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + aNonceWordF) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 44U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 21U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterC, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterI, 38U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22464U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16745U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21912U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 23087U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 22U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 35U)) + 14686411261024919129U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 13U)) + 7514582233957632005U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 6520710480103365552U) + aNonceWordF;
            aOrbiterI = (aWandererJ + RotL64(aCross, 46U)) + 1983621978676188036U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 9003524602590749672U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 3U)) + 6428568234045228995U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 8656552687136446989U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16916248288415922490U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9740237548002535784U;
            aOrbiterK = RotL64((aOrbiterK * 7970729853948983849U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 907561000814618339U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4751108900841197631U;
            aOrbiterJ = RotL64((aOrbiterJ * 4545395964730641957U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 167774899400732287U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11907484918310854962U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7213139491146402985U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14910318613649863924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14882888155751455276U;
            aOrbiterI = RotL64((aOrbiterI * 11394136445442060201U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16175942562693781908U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11022373758481651102U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 6836331461393816027U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12548405399045031548U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10850926364556828443U;
            aOrbiterF = RotL64((aOrbiterF * 16231561687709867431U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13391684887911141790U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14648937281264822988U;
            aOrbiterC = RotL64((aOrbiterC * 6533299316940026059U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 39U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 48U)) + aOrbiterF) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28334U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27389U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27804U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30218U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 38U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 14179205183062705133U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 210032324058740920U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 27U)) + 7387115089142500152U) + aNonceWordM;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 17583362781238061430U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 44U)) + 4991442849150005943U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 53U)) + 2891376254689854555U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 19U)) + 10523274382407446239U) + aNonceWordK;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3861893764676218667U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3366674459852093746U;
            aOrbiterA = RotL64((aOrbiterA * 14005994095369483813U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5898492634386601145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7047353571244768721U;
            aOrbiterG = RotL64((aOrbiterG * 2257518291062508467U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14374108805453186316U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8763667021501226510U;
            aOrbiterJ = RotL64((aOrbiterJ * 7694695426430267863U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 18261523829316379575U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 650477532238860965U;
            aOrbiterI = RotL64((aOrbiterI * 8291758490821819851U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2162326554604894042U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5776546692501825278U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14911545784585246537U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3501863793638415049U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14853789267425352958U;
            aOrbiterF = RotL64((aOrbiterF * 10590325397179928739U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 15399673014671329743U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12253428583438990426U;
            aOrbiterH = RotL64((aOrbiterH * 12052855472196447849U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 12U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + aNonceWordN);
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterA, 41U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterC, 20U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
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

void TwistExpander_Badminton_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9B65D839B6F75959ULL + 0xF7A07C9D00D9F790ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD94DD45EF8B9B3A9ULL + 0xF27E77BDB68131A9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDF789131DC269453ULL + 0xDD44139DBD5CA05EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB0C7F02D6AA42467ULL + 0x96292FBF5C1F009FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB3B77C77CA823DF5ULL + 0xB2808D7EFDB652D1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB1104AAA5E7BC81FULL + 0xA7DE404649F8CD48ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF50A12958C96FCDBULL + 0xF252E3CE7284E913ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD12F493B48FC4743ULL + 0xFB8ADF58C66A2F45ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD71B472CDF2E826DULL + 0xC1F09A41862D51FBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB387D2652ECE00B5ULL + 0xD9EDF7EC9CB5C8D7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x80BF470D65F622F1ULL + 0xD3B11780B492D5DFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD6F3270B79EC07B1ULL + 0xE01DC99D0694A142ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x90DDAACC1D71CF07ULL + 0xB51A5ABE581AB9A7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xED06EF3DA12501B7ULL + 0xDFC14640086AFC66ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC1030C3BE0BDE2D7ULL + 0x97CAECBF3ABDAC51ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB92D581C69176F5BULL + 0x8AE265E71D522574ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2956U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5196U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7122U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4390U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 6068543441070417854U;
            aOrbiterC = (aWandererH + RotL64(aCross, 39U)) + 2995980468193441856U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 60U)) + 18020277482171594003U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 57U)) + 4293807434721230702U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 35U)) + 7980599111583893156U;
            aOrbiterG = ((((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 8593141111851052016U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aWandererF + RotL64(aIngress, 51U)) + 5903487523900084325U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 27U)) + 15112035513447930209U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 54U)) + 9854037263057006439U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 19U)) + 16759760289688823193U) + aNonceWordM;
            aOrbiterK = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 12622628933030601390U) + aNonceWordG;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1264668857268123425U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16302812053619101593U;
            aOrbiterA = RotL64((aOrbiterA * 18291400055836111547U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16087995784896123610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7970269262800468363U;
            aOrbiterG = RotL64((aOrbiterG * 14924752223305807461U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5331477046030959632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16534913204255550893U;
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11042821902537871209U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8069677512345031660U;
            aOrbiterB = RotL64((aOrbiterB * 13622218526054132397U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5737130058129936372U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1076627182956662997U;
            aOrbiterF = RotL64((aOrbiterF * 14342191224014199929U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13911061091801078190U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15397603151098990373U;
            aOrbiterE = RotL64((aOrbiterE * 1802890451633592245U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15137326716738637972U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11248737008959896786U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 90789374131547005U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 1847847987633923657U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10560748778679145431U;
            aOrbiterC = RotL64((aOrbiterC * 2919333327817231099U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2703726238610290251U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12950671360471467310U;
            aOrbiterJ = RotL64((aOrbiterJ * 7490327691501537047U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10331504168520449467U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1541527607705280906U;
            aOrbiterI = RotL64((aOrbiterI * 14197400812600186171U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9135056476214341809U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6068543441070417854U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14102524444094948875U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterB, 11U));
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 27U));
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterG, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterG, 20U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 47U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterB, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 38U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9059U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9929U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13150U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8697U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 11450949896247900941U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 21U)) + 3905542253538116335U) + aNonceWordP;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 9529740545977785305U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 41U)) + 1856876631533143492U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 13U)) + 84253466320181686U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 36U)) + 12577480918745432444U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + 5625703170397704029U) + aNonceWordO;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 27U)) + 694608607323629282U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 5U)) + 3993981243536262204U) + aNonceWordJ;
            aOrbiterF = (aWandererI + RotL64(aCross, 19U)) + 4119215953484892051U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 21U)) + 8785040118556157146U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16234403619456882890U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10398727475672860610U;
            aOrbiterE = RotL64((aOrbiterE * 5086871400049644715U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18327987141759096769U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2645964788056875452U;
            aOrbiterI = RotL64((aOrbiterI * 8778681366114628045U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2859452497983106129U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7196557924940881076U;
            aOrbiterH = RotL64((aOrbiterH * 14415389907490256711U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 930127943984174668U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15673596916054795749U;
            aOrbiterD = RotL64((aOrbiterD * 7505660488733199479U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16673140529110941163U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2258448294877833760U;
            aOrbiterA = RotL64((aOrbiterA * 1821550319748977445U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6870209259643931219U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12749790107942194104U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 4871407285968611725U), 39U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 17131374134617173866U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6426448390733751612U;
            aOrbiterB = RotL64((aOrbiterB * 12490559588384058417U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15592826434339731146U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14182944418026376183U;
            aOrbiterC = RotL64((aOrbiterC * 7218860482893476233U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17447476498234456596U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 972861017466618022U;
            aOrbiterK = RotL64((aOrbiterK * 9610670431280153921U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13185309156950240549U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14442284480744008537U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2907844852105175837U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7816745313858811117U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11450949896247900941U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18317765298694454463U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 40U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererG = aWandererG + (((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 13U)) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC + (((RotL64(aCross, 48U) + aOrbiterD) + RotL64(aOrbiterA, 14U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 60U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 26U) + aOrbiterB) + RotL64(aOrbiterG, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24253U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((aIndex + 21826U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19260U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 22920U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 36U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aIngress, 42U)) + 8020711767807230555U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 23U)) + 15368693777246341570U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 35U)) + 5117523734225562401U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 19U)) + 13155269151097507808U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 9879303753623578272U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 1165799257173794826U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 27U)) + 930641942062732091U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 60U)) + 11330571332221123153U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 57U)) + 2862963158282518899U) + aNonceWordC;
            aOrbiterB = (aWandererE + RotL64(aScatter, 37U)) + 6019186399361476659U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 1924419843785161958U) + aNonceWordM;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12618629043591380461U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9334176504266512405U;
            aOrbiterK = RotL64((aOrbiterK * 18239109235362925739U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16829692481030013551U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5604784396927022709U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2833893610883508353U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16124030106598549644U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16571659812830230677U;
            aOrbiterH = RotL64((aOrbiterH * 4668250364992383549U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15171089673591843703U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2826755560293849328U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9397017963457655287U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9976785768283589291U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11845100564714691809U;
            aOrbiterE = RotL64((aOrbiterE * 4935139932585319251U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7318560453127859950U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3039196878830506712U;
            aOrbiterB = RotL64((aOrbiterB * 3140508261330698717U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8850992055588337843U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4219373528176869146U;
            aOrbiterA = RotL64((aOrbiterA * 1310964742529956743U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1341474458715938799U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15937557372891732898U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 11437307017920192915U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7512741986101399499U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4304636545688233645U;
            aOrbiterJ = RotL64((aOrbiterJ * 1948671766238131953U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11460886069492094055U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2019818350627642126U;
            aOrbiterG = RotL64((aOrbiterG * 9802784763505584769U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3190374588085859096U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8020711767807230555U;
            aOrbiterI = RotL64((aOrbiterI * 12055760672321414929U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 4U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterB, 6U)) + aNonceWordP) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 10U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterG, 27U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterA, 12U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterK, 23U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29864U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 31139U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26593U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 26699U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 4U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 27U)) + 9471546960258473684U) + aNonceWordC;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 11U)) + 18050235435948942244U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 29U)) + 3005107102671544641U) + aNonceWordH;
            aOrbiterD = (aWandererE + RotL64(aIngress, 6U)) + 17898396434573801850U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 15071602525497771648U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 5780119462702672108U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 37U)) + 13301326224151025687U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 48U)) + RotL64(aCarry, 39U)) + 18129323022260575961U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 43U)) + 1199228670638790709U;
            aOrbiterC = (aWandererA + RotL64(aCross, 41U)) + 1839199978088021020U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 19U)) + 4999517042246790165U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8788607633376516299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15143903839930468749U;
            aOrbiterH = RotL64((aOrbiterH * 12735914889325422675U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16674732686428431869U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15908873150953195581U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 18049755517524334107U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11204775359756474667U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2525984309543939465U;
            aOrbiterG = RotL64((aOrbiterG * 3988529812023791571U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4566345170476825512U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14876612901557406267U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 9047956948845135339U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14926290877038883931U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12710203178186614846U;
            aOrbiterA = RotL64((aOrbiterA * 14841163494801662515U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7315094513967387996U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11050116830482816766U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3702999495721152019U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4505368486032503953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17905748055257551092U;
            aOrbiterC = RotL64((aOrbiterC * 14775870175093453197U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5728886950801376350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17998141690182325170U;
            aOrbiterF = RotL64((aOrbiterF * 16008599930125391379U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4325978018819134558U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13526905108565989379U;
            aOrbiterI = RotL64((aOrbiterI * 14121321495714166291U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10597169665474269506U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7500801022830471869U;
            aOrbiterE = RotL64((aOrbiterE * 3702717219742363777U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17063616328548689935U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9471546960258473684U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3029748230803396737U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterE) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterB, 54U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 3U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterB, 11U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 40U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 19U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Badminton_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCA9605BEE917982DULL + 0xD85865525BBD4BE3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD0ECCC4AE5CC4FCFULL + 0xFE88BF22D5E5A04DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDCBEDA1AD5E0E9D1ULL + 0xF0F64AD1B6B27503ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE697F9523FC21DDDULL + 0xFB2910E33F68348CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBC4A4C18067CB633ULL + 0xBDA25DABE186D8F8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAE2DCD9EE69B3EF1ULL + 0xF6753C2398F0F78CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB5174BD8BE930893ULL + 0xCA28F265911A0A96ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x988A010F799214E9ULL + 0x84ACC1D3806EA4CBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB57028FDBD43C96FULL + 0x8A34F5F3565982A6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x98898DCDAFCB9713ULL + 0xE03AC58950F76203ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAA3E7C6F8630FDB3ULL + 0xC3F2AF0BA8126744ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC98A28D4A32B3A1FULL + 0x875DA0A9B864BD8AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDA1DE720A353EB13ULL + 0xC6957E34DD63B552ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8A78469CAD940AF3ULL + 0xDD1B510983B565BCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD6C6A9C34C7DA079ULL + 0xAFB32A614EC98BA0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC8572827396231A9ULL + 0x97858FAFA9D1B27BULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 721U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 513U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3983U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 3536U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 12535417189990029950U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 13U)) + 6204401443676390273U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 6U)) + RotL64(aCarry, 13U)) + 869613505613154672U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 51U)) + 15053590879563855802U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 27U)) + 13338989605204591428U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 57U)) + 18306470022403825392U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aCross, 23U)) + 1150696349434090218U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 13549541786420596437U) + aNonceWordN;
            aOrbiterA = (aWandererF + RotL64(aIngress, 18U)) + 14302878430259588461U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4660437084477165225U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1653628537860912069U;
            aOrbiterJ = RotL64((aOrbiterJ * 2624835201155303123U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5594199757006711631U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11008472193138708891U;
            aOrbiterI = RotL64((aOrbiterI * 13645764762027798301U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3668516817279364310U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 128159531749679984U;
            aOrbiterB = RotL64((aOrbiterB * 4523246859249826987U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6378674346113979108U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 11438762460659123362U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 2733309638158283953U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10624263004446482910U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12546839706919241411U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11468326687628079347U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 8466639576503293921U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5828694979857951504U;
            aOrbiterG = RotL64((aOrbiterG * 7835487310289634515U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16496305151014092976U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 589464613876410567U;
            aOrbiterK = RotL64((aOrbiterK * 13190816610718051897U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4168532743415647825U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15944887793736489375U;
            aOrbiterD = RotL64((aOrbiterD * 17273403561158196717U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11642456814106259483U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1609897693632334867U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12912773555616819941U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterA, 3U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 52U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 57U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 18U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + aNonceWordB);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterC, 44U)) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6224U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((aIndex + 6377U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7855U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9730U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 43U)) + 11210042748013785976U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 58U)) + 4584747303233477454U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 8878765929792969517U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 2172232330280041122U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 27U)) + 8378937026022264016U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 8683007464695824208U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 5U)) + 9564352997357118134U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 35U)) + 11713878436769887528U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 10U)) + 8052917623074021077U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7720597162792145185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2602847785328475621U;
            aOrbiterC = RotL64((aOrbiterC * 14065077077207224525U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17813669222300509724U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8724263063156573013U;
            aOrbiterF = RotL64((aOrbiterF * 3632927017737834359U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6882429835961613492U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13213313479525717359U;
            aOrbiterD = RotL64((aOrbiterD * 2411431247725974895U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2401526093648669573U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3616448566579979749U;
            aOrbiterA = RotL64((aOrbiterA * 13323155103752121393U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 18268262471839710401U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5116424918948694752U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7641143782996332069U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11405305689555640431U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12427591396711015574U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 8112834135715541223U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16960781161508084626U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12382604781005282628U;
            aOrbiterB = RotL64((aOrbiterB * 17196168631120103115U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10054839091354729292U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 4167641616532985407U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 919291747187787625U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14383737233143309039U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16258779988369405932U;
            aOrbiterI = RotL64((aOrbiterI * 8348773195366160215U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterF, 10U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 34U) + aOrbiterD) + RotL64(aOrbiterI, 19U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 39U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterC, 27U)) + aOrbiterA);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 39U)) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterG, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12112U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 15360U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14431U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((aIndex + 13518U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 47U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 4U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 35U)) + 9435962834163239322U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 10524704356081318973U;
            aOrbiterD = ((((aWandererH + RotL64(aPrevious, 24U)) + RotL64(aCarry, 39U)) + 7403401305665208680U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererE + RotL64(aCross, 29U)) + 7525414805023556493U) + aNonceWordF;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 43U)) + 1116686470029070951U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 51U)) + 13257612299137802420U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 9181543003986598283U;
            aOrbiterG = (aWandererF + RotL64(aCross, 57U)) + 9739384852307501107U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 10U)) + 11308402900229016057U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14935167593705272337U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7171824007631943535U;
            aOrbiterD = RotL64((aOrbiterD * 4839974427616194289U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8068411284829563567U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12350207458513447578U;
            aOrbiterH = RotL64((aOrbiterH * 813973258659041895U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17039236343991574134U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18291683592714999632U;
            aOrbiterE = RotL64((aOrbiterE * 7771718817924840713U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6239616841884430968U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10604527977569876774U;
            aOrbiterK = RotL64((aOrbiterK * 6972820410084939637U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1707724300671717658U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3802268808625297647U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 11296811630387191563U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9423064323799920219U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 242153923313096551U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12117679073775630197U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 945801070951928277U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13094814302414492064U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14638176479878969775U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7572219725951040117U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16494986983782503428U;
            aOrbiterG = RotL64((aOrbiterG * 2739189408707408171U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10949497978229234856U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11219643352002119905U;
            aOrbiterB = RotL64((aOrbiterB * 16900635614259262873U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 34U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterH, 60U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterH, 37U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 11U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 4U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 23U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17464U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 17085U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16458U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 17177U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 20U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 57U)) + 5568146815535263910U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 7736084960873834666U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 23U)) + 1336413621817562093U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 5218462026934984692U) + aNonceWordH;
            aOrbiterG = (aWandererI + RotL64(aCross, 18U)) + 7048890985969555935U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 29U)) + 13415955213864702118U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 43U)) + 5657023257021528548U;
            aOrbiterF = ((((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 14338310943137497116U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 48U)) + 12305161641833950473U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14514226578370459131U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12692904083266024340U;
            aOrbiterJ = RotL64((aOrbiterJ * 14800805065279908839U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11012959130001327964U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7106471380403489078U;
            aOrbiterG = RotL64((aOrbiterG * 515626559384817223U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3718101961355280891U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13364192077222322664U;
            aOrbiterD = RotL64((aOrbiterD * 1411328915372590283U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6720867800318913440U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14497243926965866546U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13595058589060114653U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5789056168233262435U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14438482587495779937U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10593535547917767263U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 313917798940179945U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15241845511889502917U;
            aOrbiterE = RotL64((aOrbiterE * 16483477103771326107U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3591957424821693032U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1559050939014453558U;
            aOrbiterF = RotL64((aOrbiterF * 17933346117866604725U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15340590914441451383U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5538037287390050110U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 4082576643144951473U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4151270491894969214U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 263593701314144898U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10372046955804512457U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 12U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterA, 46U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterD) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterH, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 50U)) + aOrbiterB) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23941U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22177U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24742U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 23895U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 18U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 14686411261024919129U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 7514582233957632005U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 14U)) + 6520710480103365552U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererA + RotL64(aCross, 57U)) + 1983621978676188036U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 47U)) + 9003524602590749672U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 43U)) + 6428568234045228995U) + aNonceWordD;
            aOrbiterE = (aWandererK + RotL64(aCross, 4U)) + 8656552687136446989U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 16916248288415922490U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 39U)) + 9740237548002535784U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 907561000814618339U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4751108900841197631U;
            aOrbiterA = RotL64((aOrbiterA * 4545395964730641957U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 167774899400732287U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11907484918310854962U;
            aOrbiterH = RotL64((aOrbiterH * 7213139491146402985U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14910318613649863924U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14882888155751455276U;
            aOrbiterD = RotL64((aOrbiterD * 11394136445442060201U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16175942562693781908U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11022373758481651102U;
            aOrbiterB = RotL64((aOrbiterB * 6836331461393816027U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12548405399045031548U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10850926364556828443U;
            aOrbiterJ = RotL64((aOrbiterJ * 16231561687709867431U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13391684887911141790U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14648937281264822988U;
            aOrbiterI = RotL64((aOrbiterI * 6533299316940026059U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8298658887198526821U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13822977698661348891U;
            aOrbiterE = RotL64((aOrbiterE * 17769262972278410937U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7505646847564645719U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3238749538197209166U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15394286542600778567U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15853506915123709257U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8426329899401071248U;
            aOrbiterC = RotL64((aOrbiterC * 1330397096577715113U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 44U));
            aWandererI = aWandererI + (((((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 57U)) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererK = aWandererK + ((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 48U)) + aOrbiterH) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28127U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29886U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29467U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 31996U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 43U)) + 12426357877879529292U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 14U)) + RotL64(aCarry, 47U)) + 12604900366173639176U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 13511119007338929401U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 51U)) + 9878720081166788060U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 35U)) + 15463195409806395076U;
            aOrbiterK = ((((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 6407922778852833423U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 39U)) + 7690427254160734016U) + aNonceWordJ;
            aOrbiterI = (((aWandererK + RotL64(aCross, 10U)) + 18030974031722143619U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aWandererE + RotL64(aScatter, 57U)) + 17983938038322737041U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16605512170117753884U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 681802273302348322U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 14608920184802647123U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 15550312921312083819U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17824154101711884508U;
            aOrbiterC = RotL64((aOrbiterC * 7358612830654795357U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1939207786756735430U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 3132864634777826569U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13606281919426730325U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12822929773923954849U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16576106045887115660U;
            aOrbiterI = RotL64((aOrbiterI * 16370914370769903051U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2398825881649235260U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13700821892926092479U;
            aOrbiterF = RotL64((aOrbiterF * 10830623703416956043U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2439833784883391606U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15870638514107637833U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3797380922767479287U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9165457123134229670U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8736642509192659417U;
            aOrbiterD = RotL64((aOrbiterD * 16219277537523484065U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9232719746484835693U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7826680628853322541U;
            aOrbiterK = RotL64((aOrbiterK * 12578050118133526187U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14323652326982518782U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2254524512851399313U;
            aOrbiterG = RotL64((aOrbiterG * 4119339547645451149U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 12U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterC, 21U)) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterG, 39U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 28U)) + aOrbiterF) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 43U)) + aOrbiterF) + aNonceWordD);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 48U) + aOrbiterE) + RotL64(aOrbiterB, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordL;
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

void TwistExpander_Badminton_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE68D766676A05B1DULL + 0x8F7E8C06A8D2B98AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE856A6DB3BDEFD41ULL + 0x830322C28ACA9F1DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE5617EFB2650256FULL + 0xCA1E26384A16011CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFCACE42DB99974E7ULL + 0xAD911488465A6682ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE90AB0B115B0DC49ULL + 0xAD9CC4D298404EEAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE51547F4610F714DULL + 0xF8862F4FABC259D9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB65EEB0952AA3383ULL + 0xE5B34582C446AD2AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE45E6B12ACB91DD3ULL + 0x9810790CFB911857ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB6F27C14D64F8611ULL + 0x974C9A467445682EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8A8D019C46560C69ULL + 0xEE2813EC49FECE56ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8BC92B2DA926FDDFULL + 0xAACFFDAA247D7C94ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDA7F00469CF79907ULL + 0xC4F098B725702AD9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFFB86CC58D30567FULL + 0x897C4C536232B9C8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xED3AD90F486C02B5ULL + 0x81F3C2478DBDE135ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9C2AC844A5C22F57ULL + 0xDE586EF088543343ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xECA83CEB737D6F7BULL + 0xA5303D9114FC54BAULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4380U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 1020U)) & W_KEY1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4915U)) & W_KEY1], 40U) ^ RotL64(mSource[((aIndex + 2941U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 26U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aScatter, 57U)) + 6973892330986118220U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 21U)) + 9886813896272094864U;
            aOrbiterJ = ((((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 10996306582517553173U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererD + RotL64(aCross, 50U)) + RotL64(aCarry, 37U)) + 8490648283899856223U) + aPhaseAOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 27U)) + 105141713530704655U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 3114337422810562588U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 43U)) + 980857684690886131U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6562042345807072665U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15665371138706353619U;
            aOrbiterJ = RotL64((aOrbiterJ * 8086237578564620623U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 18113013571374375028U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17405346422601997299U;
            aOrbiterC = RotL64((aOrbiterC * 11162604605443005253U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5130876096426182506U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1813821672299154629U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15478100342425611875U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15793814882743306728U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13925299440495476399U;
            aOrbiterF = RotL64((aOrbiterF * 12049601510660117401U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9924458846049579438U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7810034662781768090U;
            aOrbiterH = RotL64((aOrbiterH * 10310594595026622513U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12812586478656872854U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5709576448057435237U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9101555233909853025U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7839807649914541516U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 4717944526755429647U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 8515229146471335721U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 10U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterE, 23U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 4U) + aOrbiterH) + RotL64(aOrbiterE, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10459U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7844U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6801U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[((aIndex + 9220U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 52U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 53U)) + 17019646486641172469U) + aPhaseAOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 27U)) + 12276141179299971572U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 3617241694029841555U) + aPhaseAOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 12U)) + 6967963401259371737U) + aNonceWordC;
            aOrbiterC = (aWandererG + RotL64(aScatter, 47U)) + 6340709284279891017U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 456065368903896482U) + aNonceWordB;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 17686765719908116203U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1322045955429785736U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5163772703302372887U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3193272189179082313U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13268431135020363252U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6538789950366849332U;
            aOrbiterD = RotL64((aOrbiterD * 5352960308459065837U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10390344544314544893U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5087084271300584267U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13423071121590981727U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 18324443012024134729U;
            aOrbiterH = RotL64((aOrbiterH * 15814349432207734533U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4129091815978464507U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17024797553831962245U;
            aOrbiterC = RotL64((aOrbiterC * 3137753479364378175U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6501545108779991661U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11930037791867597447U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4904739567549702851U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4667298703308315851U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6315980380900062127U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 12080555704907924637U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA) + aNonceWordH) + aPhaseAWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterB, 23U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 44U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + aPhaseAWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 44U)) + aOrbiterH) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14209U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 11048U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12585U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 15379U)) & W_KEY1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 12U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 16519040829220310189U) + aNonceWordL;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 3U)) + 6888002778416941825U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 1310832187746534025U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aIngress, 29U)) + 5890888009051281674U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 19U)) + 5143864838362464857U) + aNonceWordJ;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 15591534069452660003U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 48U)) + 1466867671765325096U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 13931443680107902488U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15400747367673245552U;
            aOrbiterB = RotL64((aOrbiterB * 7011651369456453127U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2836975369734495759U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2370720358274970117U;
            aOrbiterG = RotL64((aOrbiterG * 4615571902817575375U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 3470677184188006133U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7175584278499266723U;
            aOrbiterA = RotL64((aOrbiterA * 10067096593682482345U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6095078817776863055U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2176637999243513070U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12215701810843975501U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5580391239754903129U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15196125567953871184U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12686361960729564519U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12787014151503209931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1523153207064063495U;
            aOrbiterE = RotL64((aOrbiterE * 3113907543551927561U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12973289026485937829U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9087439766232078173U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5817029335999350327U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 12U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 23U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + aPhaseAWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 46U)) + aOrbiterA) + aPhaseAWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 20U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18985U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 19445U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20289U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((aIndex + 17450U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aPrevious, 13U)) + 8020711767807230555U;
            aOrbiterH = (aWandererC + RotL64(aCross, 57U)) + 15368693777246341570U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 5117523734225562401U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 13155269151097507808U) + aPhaseAOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 19U)) + 9879303753623578272U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 4U)) + RotL64(aCarry, 29U)) + 1165799257173794826U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 41U)) + 930641942062732091U) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11330571332221123153U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2862963158282518899U;
            aOrbiterE = RotL64((aOrbiterE * 13782195862525974199U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6019186399361476659U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1924419843785161958U;
            aOrbiterA = RotL64((aOrbiterA * 9485557122500346869U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12618629043591380461U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9334176504266512405U;
            aOrbiterH = RotL64((aOrbiterH * 18239109235362925739U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16829692481030013551U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 5604784396927022709U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2833893610883508353U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16124030106598549644U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16571659812830230677U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4668250364992383549U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15171089673591843703U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2826755560293849328U;
            aOrbiterD = RotL64((aOrbiterD * 9397017963457655287U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9976785768283589291U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11845100564714691809U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4935139932585319251U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 46U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterH, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + aNonceWordB) + aPhaseAWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterK, 60U)) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 44U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterE, 37U));
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24974U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 24189U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22699U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26239U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 47U)) + 9774364261626083532U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 18059001521926116420U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 19U)) + 10615626210406381148U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 10536484278007898620U) + aNonceWordP;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 40U)) + RotL64(aCarry, 43U)) + 13320663045139972700U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 27U)) + 17127001787268166583U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 3U)) + 16742574590844166551U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 8347719720758228053U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13502468705946051986U;
            aOrbiterE = RotL64((aOrbiterE * 13822952083584784695U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3512687886188904904U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 495660316165795934U;
            aOrbiterK = RotL64((aOrbiterK * 6724596801190194913U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5092722552034477356U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15641128019608284015U;
            aOrbiterF = RotL64((aOrbiterF * 3621036395703527059U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15421873776811085458U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17978775513204574125U;
            aOrbiterH = RotL64((aOrbiterH * 18359600395119440183U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16617179197537669849U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1931805387534012528U;
            aOrbiterJ = RotL64((aOrbiterJ * 3400139345857733775U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 9544923119559308431U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12930999400470173353U;
            aOrbiterC = RotL64((aOrbiterC * 16791006919271490005U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13673733276226249890U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2032263473309124738U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3088728329261360607U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 27U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererB = aWandererB + (((((RotL64(aCross, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordE) + aPhaseAWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + RotL64(aOrbiterC, 20U)) + aOrbiterJ) + aNonceWordA) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 52U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27827U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 27833U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28343U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30742U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aPrevious, 19U)) + 16124889768301047791U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 51U)) + 11912338587186717280U;
            aOrbiterB = (aWandererB + RotL64(aCross, 3U)) + 8594012868813114354U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 28U)) + RotL64(aCarry, 35U)) + 18281043566156682815U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 16853106130200942302U) + aNonceWordB;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 2611212958619673086U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 43U)) + 18039472325066855180U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14495785571345122046U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4556063793412832418U;
            aOrbiterB = RotL64((aOrbiterB * 13166927543135467627U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14896419970271244358U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 880028529183500036U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14228281807461251361U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2379557167489415783U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11854373946064529806U;
            aOrbiterD = RotL64((aOrbiterD * 150755294320438887U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1487252775956449964U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 12777924204511625545U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 1366019527386994789U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15998631485222477969U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8864212892296191613U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 579242788050369815U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17069347835763226743U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7443008171694679791U;
            aOrbiterJ = RotL64((aOrbiterJ * 748894368884566607U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17334256152350782002U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8986626119086556393U;
            aOrbiterG = RotL64((aOrbiterG * 2258172145924120235U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + aPhaseAWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 10U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererC, 12U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordH;
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

void TwistExpander_Badminton_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA670EB257AAEF269ULL + 0xA99F1B9452D2819BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8454F90A9CEF00BDULL + 0x91EBDA89261B504BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9AD8AC515432D35FULL + 0xCF22A679F2A3F7B6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xABD5B0D0EDC7A009ULL + 0x822074A92882D706ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8BF6C6C6B4F24307ULL + 0xA4E747F5F599351DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB048FB20415A630BULL + 0xD6FBA683FDA275CFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEDF53973215D9667ULL + 0x919799AD6185FF4EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8C2DD894FDEFB3B9ULL + 0x909D53D4D471F3D5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x82DD868FD57C6625ULL + 0xF71E4D658300C13EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB1F8D933BB1CFC87ULL + 0xF3604ABFA6A9ABA4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC28D6644D5E56B93ULL + 0xA5671706D5615412ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA36C6B62A441CEADULL + 0xCE12B903CE66A949ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB3E32CA38A7B73CBULL + 0xA38524883CB34128ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA29615EE4B1AAB63ULL + 0xB5A81E10C3DB1F9EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x87D78DEAC1E474ABULL + 0xBF14B93015E70D3DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFD3CB404574BC943ULL + 0x970430D90A2EEF27ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1591U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1681U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4926U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 5125U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (((aWandererJ + RotL64(aCross, 22U)) + 7960325128608297381U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 12773836012104052042U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 5U)) + 3173972621347773016U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 3708401356314308171U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 950774285720019449U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4170092315705438265U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17000449130864980747U;
            aOrbiterB = RotL64((aOrbiterB * 7710635557693533263U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8793910540062893860U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 520277969543516469U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 4150613128885828229U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12762214857389827271U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2932451184340207695U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7513337346940091655U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11062179998786293839U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7919119215271524178U;
            aOrbiterC = RotL64((aOrbiterC * 9053677007180081359U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1774988449597115155U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3799792889466518953U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 34U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 52U)) + aOrbiterB) + aNonceWordM);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8990U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 8430U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9383U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5622U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 14U)) + 4752759164691497960U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 12088872623537639782U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 3734943577379734227U) + aPhaseBOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 43U)) + 8854778183012444234U) + aPhaseBOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 16948373492893967275U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7962415690046184385U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1872682375669714454U;
            aOrbiterB = RotL64((aOrbiterB * 959061892772099785U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7776801806943853566U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16665439117257230732U;
            aOrbiterE = RotL64((aOrbiterE * 6866375628213114965U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11088186766134265676U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10850237991780969350U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7547414856143095121U), 23U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 6464817712131305812U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 244557182884209844U;
            aOrbiterH = RotL64((aOrbiterH * 2394270354887582889U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13261563971157415841U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2323811103717827362U;
            aOrbiterJ = RotL64((aOrbiterJ * 11483723582415081925U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterI, 14U)) + aNonceWordN) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + aPhaseBWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12002U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 15215U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13819U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15643U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 13U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 18144572925667544139U) + aPhaseBOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 50U)) + 5659758077574059728U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 29U)) + 6343330616999166392U) + aPhaseBOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 17754639838410839447U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 9451843819849581729U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7957854457197462212U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1461994799722205010U;
            aOrbiterA = RotL64((aOrbiterA * 13431080873536691809U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18002214276252170177U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14689869073147027164U;
            aOrbiterI = RotL64((aOrbiterI * 12242482963989582191U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3978104368003440293U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8512135845221335386U;
            aOrbiterE = RotL64((aOrbiterE * 10506667163729414667U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1477533446382953439U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2166717790929947990U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6538884492418324461U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 8082437060686606995U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4363687722464700362U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7199165810993478887U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 58U);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordH) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterK, 38U)) + aNonceWordC) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterF, 19U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20665U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 20502U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20102U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19120U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 27U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((((aWandererD + RotL64(aIngress, 26U)) + RotL64(aCarry, 53U)) + 8020711767807230555U) + aPhaseBOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 15368693777246341570U) + aNonceWordI;
            aOrbiterF = ((aWandererA + RotL64(aCross, 11U)) + 5117523734225562401U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 13155269151097507808U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 43U)) + 9879303753623578272U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 1165799257173794826U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 930641942062732091U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17151944851548731159U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11330571332221123153U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2862963158282518899U;
            aOrbiterB = RotL64((aOrbiterB * 13782195862525974199U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6019186399361476659U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1924419843785161958U;
            aOrbiterK = RotL64((aOrbiterK * 9485557122500346869U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12618629043591380461U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 9334176504266512405U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 18239109235362925739U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16829692481030013551U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5604784396927022709U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 2833893610883508353U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 34U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 50U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordM) + aPhaseBWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22654U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 24092U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26429U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 23409U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 36U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 15045917390223766480U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 10763054007033668758U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 13U)) + 13190170142593666607U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aScatter, 38U)) + RotL64(aCarry, 29U)) + 9657025731441167065U) + aNonceWordC;
            aOrbiterB = (aWandererF + RotL64(aCross, 5U)) + 11433367178975954211U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17904920143996810366U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3244383020512113283U;
            aOrbiterE = RotL64((aOrbiterE * 552521443123433353U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6538815775171139091U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7195368312757976343U;
            aOrbiterB = RotL64((aOrbiterB * 10515679176134176565U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 18134430713910279374U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6571776588427107976U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11916502085252589161U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11830778129647517758U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9793702760907767365U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 4096246227968677179U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2287235876793192036U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8951959188326141794U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9968356718110753845U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterB, 13U));
            aWandererD = aWandererD + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordI) + aPhaseBWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterB, 22U)) + aNonceWordF);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordE) + aPhaseBWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererG, 40U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31718U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29360U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29776U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30150U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 9855743441035905047U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 5U)) + 8426286937143990276U;
            aOrbiterI = ((((aWandererC + RotL64(aCross, 56U)) + RotL64(aCarry, 43U)) + 7146752367170267002U) + aPhaseBOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 12947210066678101726U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 21U)) + 15902163559925328965U) + aPhaseBOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8506649889346449469U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8226286036430263052U;
            aOrbiterI = RotL64((aOrbiterI * 7264199281303956141U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2703047093452420216U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6769351326360139560U;
            aOrbiterH = RotL64((aOrbiterH * 5318104980014706265U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9857025533281333281U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 238297452132277585U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12974709749856065985U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7203572312072908931U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12497027346166575632U;
            aOrbiterA = RotL64((aOrbiterA * 1703586436725662307U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 473851890609048879U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1664484956453886047U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8566500756326590209U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + aPhaseBWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 44U) + RotL64(aOrbiterG, 10U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + aNonceWordI) + aPhaseBWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordI;
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

void TwistExpander_Badminton_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC11D25733ED55FFDULL + 0xB92EEBCF7308F09DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x92770476D2C18E91ULL + 0xE8DCE991880007B2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9684C442BFF8133FULL + 0xAAD26A25849569DDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEB52246C5AEC38D9ULL + 0xE02A7345069640F4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE3E4A1E4EC2C770DULL + 0xA8882959E4F5909BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8081FD864C0E1095ULL + 0x97F70F741DC299FBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x99ADAAD61454DC1FULL + 0xA6C5FBCFA605B533ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDBD5FCC3ED0D0C33ULL + 0x97A44B2FAC0FFB4CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB81FDCFFB8CB9B1DULL + 0xD7E03B0C4D37AD28ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAC1EAD7FF9BFED5FULL + 0xA81BA130F3654F22ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFE3ECCE849EC5E47ULL + 0xA924FBA2D3454DCBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEBF917003DB39B83ULL + 0x839D096F755B965BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9B927D9ABA79CD07ULL + 0x908BA5A38514DA89ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF61228337771E3D1ULL + 0xF320C8FE19F46750ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x94145935CAC5A3FDULL + 0xE503D75B47812E6DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD80E45544DEDE14BULL + 0xBD6EBFFFD1C049AEULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7930U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7818U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4218U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 60U)) + 701291026547470433U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 13U)) + 17283292650462111643U) + aNonceWordG;
            aOrbiterC = (aWandererD + RotL64(aCross, 39U)) + 9969124091931303406U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 889176772718046988U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 6054541844643748084U) + aNonceWordD;
            aOrbiterK = ((aWandererG + RotL64(aCross, 43U)) + 14703226235143028132U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 56U)) + RotL64(aCarry, 27U)) + 7977975878522921062U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 51U)) + 16894322614172266274U) + aNonceWordM;
            aOrbiterF = (aWandererC + RotL64(aCross, 3U)) + 12160451749345900570U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10870847008043897470U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8159920947172520247U;
            aOrbiterC = RotL64((aOrbiterC * 4833194641611011805U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2440099120969517932U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2428396147731468007U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 9363073341539598441U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2213226274394673479U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7079731443427765333U;
            aOrbiterA = RotL64((aOrbiterA * 16918930776877030559U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 958896789550478970U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10788682955708075458U;
            aOrbiterF = RotL64((aOrbiterF * 913321215613559729U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2003386579317564870U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8419686358774204999U;
            aOrbiterG = RotL64((aOrbiterG * 6547052526438697621U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6989167615157578904U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17636634003643824148U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 11038576417283732937U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13824962118933907859U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9543912892587859646U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14736710162285997415U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15729878041027706114U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9542137475454825463U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11420547128115090491U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5327302277575009955U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2707383132257428583U;
            aOrbiterJ = RotL64((aOrbiterJ * 6120763309390182129U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 40U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 10U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + aPhaseCWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterH, 39U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterD, 34U)) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 21U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16017U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((aIndex + 15572U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15783U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11446U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aScatter, 5U)) + 6069475454765660321U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 14U)) + 11483704742497268068U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 47U)) + 11055697447388986418U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 10897095046039997004U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 57U)) + 4731637118230457840U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 13855839187084986751U) + aPhaseCOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 5328208115460188239U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 30U)) + 12479538544291412985U) + aNonceWordK;
            aOrbiterA = (aWandererE + RotL64(aScatter, 53U)) + 10740165998792608231U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6492798157284955373U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13056825957483891921U;
            aOrbiterH = RotL64((aOrbiterH * 14882112110627751751U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2068184064919194657U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5656302738780746294U;
            aOrbiterG = RotL64((aOrbiterG * 16493021179127646345U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11193756120230763294U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17306750816837208999U;
            aOrbiterB = RotL64((aOrbiterB * 7949360041241439741U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12952818800389361804U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15380412293642628312U;
            aOrbiterC = RotL64((aOrbiterC * 2914662289178925547U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7706090204767242996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14598802276412649570U;
            aOrbiterA = RotL64((aOrbiterA * 4821408736292041399U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17819762117328075515U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6481384240915075101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4836701121865783029U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 754936290510338717U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15510875946573720154U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2994718968852184303U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9245381722813944586U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2629847912019726214U;
            aOrbiterK = RotL64((aOrbiterK * 6718795794951106961U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3909987749797113773U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9277056074757335265U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 11580847505996697115U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 34U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + aNonceWordF);
            aWandererB = aWandererB + (((((RotL64(aIngress, 42U) + RotL64(aOrbiterF, 39U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordI) + aPhaseCWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterB, 4U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + RotL64(aOrbiterK, 47U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aScatter, 26U) + RotL64(aOrbiterA, 23U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterF, 52U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17880U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 23802U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23191U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 24159U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 47U) + RotL64(aCross, 4U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aCross, 35U)) + 9914837590440975587U) + aNonceWordA;
            aOrbiterA = (aWandererA + RotL64(aScatter, 11U)) + 6706125076401958051U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 53U)) + 16570817772679258409U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 27U)) + 6843705658115186948U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 29U)) + 16099930446791572351U) + aNonceWordJ;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 5U)) + 5420550009556030459U) + aNonceWordH;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 5729549069420177477U) + aPhaseCOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 15590601126188675834U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 48U)) + 13044027390998620029U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11068338135659636772U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6584988841809544332U;
            aOrbiterD = RotL64((aOrbiterD * 1683336180438945439U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8516813219883915404U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10647314042912492785U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15559481057047148785U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 201691689889605304U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15512161798401184003U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 11473219183982564709U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3883760518944464145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13861805129175491145U;
            aOrbiterA = RotL64((aOrbiterA * 17194438894492581181U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12019138626550801486U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13030350224959652248U;
            aOrbiterE = RotL64((aOrbiterE * 11724200983306280107U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2643807255422544248U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4127143302485631794U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5441038881111578487U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14602951930809633069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4555737199162278494U;
            aOrbiterH = RotL64((aOrbiterH * 12415825635220991865U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6343143902997169834U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10404783711336491985U;
            aOrbiterK = RotL64((aOrbiterK * 6235474458879439079U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7406959231434835393U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6684368109277850196U;
            aOrbiterB = RotL64((aOrbiterB * 8760360417572331159U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 10U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 44U) + aOrbiterB) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterD, 57U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aPhaseCWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32405U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28082U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32221U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 26093U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 28U) + RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 39U)) + 826930775230515406U) + aNonceWordP;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 5137814617363250861U) + aNonceWordE;
            aOrbiterJ = (aWandererA + RotL64(aCross, 5U)) + 14761561947426681616U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 53U)) + 12773023438753662590U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 14U)) + 7331345852207096322U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 3899381212671247460U) + aNonceWordF;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 43U)) + 10072004147620068599U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 3424585039401897560U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 34U)) + 8246760141625966321U) + aPhaseCOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3655992860610853290U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11154618022505863898U;
            aOrbiterJ = RotL64((aOrbiterJ * 4791494171286145231U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15629361991059709973U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10842068502278489664U;
            aOrbiterF = RotL64((aOrbiterF * 17223002513104960799U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5571312349016336686U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 589313823745748879U;
            aOrbiterG = RotL64((aOrbiterG * 1356685926549786027U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13633457935771935260U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12684602052812183096U;
            aOrbiterC = RotL64((aOrbiterC * 4689206269919806711U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5711307583717354204U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7181854170553728211U;
            aOrbiterE = RotL64((aOrbiterE * 9835601115561325911U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1884620014396115821U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1471516373272364262U;
            aOrbiterD = RotL64((aOrbiterD * 5126319375714848029U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 742739371092077733U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8075893317715227838U;
            aOrbiterB = RotL64((aOrbiterB * 11208274111743259795U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8179547722249281263U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15305282712174742323U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 7951986906055462929U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1430543231751281079U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14585341768267283387U;
            aOrbiterK = RotL64((aOrbiterK * 313213844964269133U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterD, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 34U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterE, 47U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aPhaseCWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 53U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 4U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_Badminton_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x878F9C45602554C3ULL + 0xF1D8D6FCA8B65BCBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x91CF3639BB658639ULL + 0xA552A7115C33F4ADULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF17DEDC388F17023ULL + 0xFBBEF24193361178ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBDB1D7D5264B4EDDULL + 0xF7C6331CF364AB87ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB98C46F0788533DBULL + 0xC75ACD91A9F8E034ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA3815A3D3A85F3F1ULL + 0xD2E1365FDAF6C4FDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA9E06FDA4A98AEB9ULL + 0x84BA8995E003A5ACULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA88F4589EA6EC17DULL + 0xA8BD39D510CD6769ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8832E74CFA8AA2F1ULL + 0xE3B2A23C4E3B6E13ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEC32CFFC65E8D027ULL + 0xBD955E5B48D0AD6BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD2B467ACE9FC592FULL + 0xF130AB3198AA9141ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x935D27AB8A06D8F9ULL + 0xDFB045EB8AD8CA45ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEF36548BF2D40D43ULL + 0x9ECED6E381CBAA95ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8B5C1CA5D0741563ULL + 0xCBDDE70B7EBFAA24ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE0D37702F787C433ULL + 0xE3DC5D42BAD464CFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC8B25C84F056CCADULL + 0x8E36F2A4591615CFULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 259U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1291U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5103U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 695U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 51U)) + 3448371607470865612U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 3743742913651580573U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 21U)) + 13069491287948807280U;
            aOrbiterE = (aWandererB + RotL64(aCross, 41U)) + 16872779275586545632U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 30U)) + RotL64(aCarry, 51U)) + 17945792656755062795U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 18199747196793731853U;
            aOrbiterB = (aWandererH + RotL64(aCross, 13U)) + 15953311878379809513U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 27U)) + 941268763494588338U;
            aOrbiterH = (aWandererA + RotL64(aCross, 57U)) + 10090221530365796809U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 37U)) + 8335698093307607001U) + aPhaseDOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aWandererG + RotL64(aIngress, 44U)) + 6147498804734306100U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5980246079567570090U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4152167624425912978U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10019421651535123573U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14990418790239735916U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3418668387496597219U;
            aOrbiterC = RotL64((aOrbiterC * 12814077238529863119U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4206650904177199425U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3905470780938996069U;
            aOrbiterF = RotL64((aOrbiterF * 16030122739273137005U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9968672788233080924U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 602258075661864866U;
            aOrbiterE = RotL64((aOrbiterE * 2615726693066300065U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17751667243048041383U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2414054413585296027U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1049512574773201893U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6523322402744047752U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6729901917767398779U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 8039939871405367139U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11460169185076814539U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7559640379553110573U;
            aOrbiterK = RotL64((aOrbiterK * 9864654321914036135U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17271150091827475028U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3541809324556914646U;
            aOrbiterI = RotL64((aOrbiterI * 12655168871428868639U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10332471447306597185U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12580133010006951091U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1159183486084705865U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17333553613777910945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14179392055698682109U;
            aOrbiterJ = RotL64((aOrbiterJ * 17675559451285279251U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3996830751779338356U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3448371607470865612U;
            aOrbiterD = RotL64((aOrbiterD * 5375529914102609947U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterF, 12U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + aNonceWordF);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterE, 27U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 35U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 26U) + aOrbiterG) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 53U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + aNonceWordG) + aPhaseDWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6713U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9531U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9584U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5946U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 1364174714924216027U) + aPhaseDOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 57U)) + 13561796874229506613U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 35U)) + 11845572344206238305U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 39U)) + 15762708240326773763U) + aNonceWordH;
            aOrbiterG = (aWandererF + RotL64(aScatter, 6U)) + 1157119665207900473U;
            aOrbiterE = (aWandererC + RotL64(aCross, 3U)) + 6823546624372055260U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 14465564210523945121U;
            aOrbiterJ = ((((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 10667464548080807531U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 51U)) + 13445737493224316575U) + aNonceWordA;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 37U)) + 3009837893785957665U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 44U)) + 2886920524111083752U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10886177449328249656U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15067759884678100433U;
            aOrbiterH = RotL64((aOrbiterH * 5724566815989860041U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18307930462682331536U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8791864377579255801U;
            aOrbiterF = RotL64((aOrbiterF * 9265158882471421767U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 805797468642992351U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5743305867058244964U;
            aOrbiterG = RotL64((aOrbiterG * 16263000753351131717U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17102025528234481273U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1841579177327486899U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 3841603385577825265U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2189493507896508972U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18209567010094914374U;
            aOrbiterK = RotL64((aOrbiterK * 3737080408976852351U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6697069234216868330U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 927471474577415372U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10680760991009199309U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13155854301197725408U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1014625081915435892U;
            aOrbiterD = RotL64((aOrbiterD * 11592754232949990435U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12697209921410914931U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11555096613655648647U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4598821388864997089U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9335308231651271690U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3160859883353473444U;
            aOrbiterJ = RotL64((aOrbiterJ * 4753600703924906409U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15681189182414315768U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3147692210581710663U;
            aOrbiterB = RotL64((aOrbiterB * 6271949093080510861U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5373388632562432117U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1364174714924216027U;
            aOrbiterA = RotL64((aOrbiterA * 4694926665965807945U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterD, 11U));
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 6U)) + aOrbiterB) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterK, 39U));
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterK, 18U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 23U)) + aOrbiterD) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14716U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 14441U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16114U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 15727U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 20U)) + 11521331427196538632U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 16653824187682957632U) + aPhaseDOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 11654676587350088289U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 8010313317412193584U) + aNonceWordN;
            aOrbiterK = (aWandererG + RotL64(aCross, 53U)) + 1108775560502907471U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 27U)) + 243952321439823521U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 39U)) + 2324945800401240403U) + aPhaseDOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 47U)) + 9257554497543369657U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 14U)) + 16701314607244592540U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 3U)) + 3900445848034341782U) + aNonceWordG;
            aOrbiterD = (aWandererF + RotL64(aScatter, 5U)) + 7652316487347103658U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14980368605272070578U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2001165460948764796U;
            aOrbiterA = RotL64((aOrbiterA * 8110980921827107649U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1911044015666991050U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11366207111147818339U;
            aOrbiterG = RotL64((aOrbiterG * 17234439040652553865U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16469329744002456607U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8062793687044950815U;
            aOrbiterB = RotL64((aOrbiterB * 5856142259851144369U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15364721421972807872U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8979915611483540231U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 10899377466171153383U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7654234623563110457U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1526832460342135008U;
            aOrbiterC = RotL64((aOrbiterC * 12766083052650723051U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1596625448797520938U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15723912914858523080U;
            aOrbiterF = RotL64((aOrbiterF * 6003857787643420337U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7664226719746532168U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13767298788411473401U;
            aOrbiterH = RotL64((aOrbiterH * 15663266144965532019U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8371251860069346385U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10143279934304029980U;
            aOrbiterJ = RotL64((aOrbiterJ * 12764966547132248131U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10034920090729616747U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14450253491131954914U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15877567779079226909U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9450697155749555210U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14051719612902917300U;
            aOrbiterI = RotL64((aOrbiterI * 7659810299163085295U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 659383614060726993U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11521331427196538632U;
            aOrbiterD = RotL64((aOrbiterD * 1068009283450923005U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 12U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterB, 58U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 22U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + aNonceWordB);
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterH, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aNonceWordF);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterB, 51U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterC, 19U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + aPhaseDWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 42U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordI);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 18002U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21321U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18769U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 18186U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererD + RotL64(aIngress, 52U)) + 16183871922837164759U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 11U)) + 7002058258090219055U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 5650868611888303705U) + aPhaseDOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 43U)) + 11899839660943876690U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 37U)) + 15349649504488111111U;
            aOrbiterD = (aWandererK + RotL64(aCross, 29U)) + 14060149569086744970U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 3U)) + 12920917574225030112U) + aNonceWordH;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 2831994965175330135U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 18312543585028439192U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aScatter, 23U)) + 11657562205118394239U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 26U)) + 10850792819281246052U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17810371216216125323U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7963413941144223128U;
            aOrbiterG = RotL64((aOrbiterG * 534217972450595401U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5498715358793875584U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9256727548911651373U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10498848323914000989U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17246360111302191699U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 18309978718113983369U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18267472694666221077U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3100998994319502921U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8129301860291235970U;
            aOrbiterH = RotL64((aOrbiterH * 17847033539279176187U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1889641029473279114U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16538494307002917945U;
            aOrbiterB = RotL64((aOrbiterB * 8081488217920885783U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5432230549146849322U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2634437941396090817U;
            aOrbiterK = RotL64((aOrbiterK * 7612999214758935211U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16940172599174185058U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13151669140593952203U;
            aOrbiterI = RotL64((aOrbiterI * 16225319638131723487U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3995064294869931681U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 913081077665768816U;
            aOrbiterJ = RotL64((aOrbiterJ * 9299514648768060453U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2469001696075411481U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2167390955194185443U;
            aOrbiterA = RotL64((aOrbiterA * 11805065572289005223U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1574066406534010796U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8736976961589874013U;
            aOrbiterE = RotL64((aOrbiterE * 5980070607180321955U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4233621443153132083U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16183871922837164759U;
            aOrbiterC = RotL64((aOrbiterC * 4030569514959370895U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 50U)) + aOrbiterA) + aPhaseDWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterF, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterI, 53U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterE, 39U));
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 5U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 14U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererD, 18U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 26838U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23454U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24126U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26943U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 22U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aIngress, 43U)) + 2558105147674438050U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 30U)) + 15856662514774702561U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 13346869226246584582U) + aNonceWordA;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 57U)) + 7632111846116243973U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 37U)) + 2102101361626976279U;
            aOrbiterB = (aWandererG + RotL64(aCross, 35U)) + 5605968705067851563U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 6842483186584326681U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 5559797213819425064U) + aNonceWordC;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 21U)) + 12422313931331576759U) + aNonceWordE;
            aOrbiterF = (aWandererC + RotL64(aCross, 54U)) + 2751024420047872601U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 41U)) + 11031320239359798610U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14366375309473793217U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11971479429768505316U;
            aOrbiterD = RotL64((aOrbiterD * 10063001532313098203U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3947595951884469542U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17882767922372770896U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3361906348965810211U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 513871456983509223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5951677013597794294U;
            aOrbiterJ = RotL64((aOrbiterJ * 8508629569649935293U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 437626309049021931U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 466674061172005705U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1310502572084891157U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12362602809233133718U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10525852878882195702U;
            aOrbiterI = RotL64((aOrbiterI * 17755022180514914325U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17927000184308583095U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 566723721423470052U;
            aOrbiterA = RotL64((aOrbiterA * 17710534355278632573U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9504585484034413577U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4614306037721859929U;
            aOrbiterE = RotL64((aOrbiterE * 170807293799483539U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1463218357720031588U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4036696102163560633U;
            aOrbiterG = RotL64((aOrbiterG * 15389914226155130065U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9907678911300898726U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11804311892289601322U;
            aOrbiterH = RotL64((aOrbiterH * 13986106774841242253U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6514645538508331396U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17246364354815744899U;
            aOrbiterC = RotL64((aOrbiterC * 12800661037742526999U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6725706155285333764U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2558105147674438050U;
            aOrbiterK = RotL64((aOrbiterK * 6752457079901154727U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterG, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 30U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 18U) + aOrbiterD) + RotL64(aOrbiterG, 13U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + aPhaseDWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterB) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterE, 39U));
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 20U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32472U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 30730U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28243U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 31888U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 42U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aCross, 43U)) + 8101351470141807662U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 6965474099521076705U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 46U)) + 6803828268885684784U) + aNonceWordL;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 57U)) + 13454235922950972488U) + aPhaseDOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aIngress, 35U)) + 11678091885751244777U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 5307134544628507141U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 27U)) + 4873703518950429353U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 8542156221858586039U;
            aOrbiterA = (aWandererB + RotL64(aCross, 6U)) + 3993726182905296513U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 53U)) + 12113047622035464386U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 39U)) + 1944244448665721151U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12914188029425467576U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2486762763475327024U;
            aOrbiterG = RotL64((aOrbiterG * 12319769994433811617U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14580191602982245481U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12093414832400135066U;
            aOrbiterI = RotL64((aOrbiterI * 12720286833215690663U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13623906997320021065U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9977356009806428696U;
            aOrbiterD = RotL64((aOrbiterD * 2005536391712733499U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3694954095397810851U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11453812627797091638U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 13730420725113907161U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 542311345544726351U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3024285045990499484U;
            aOrbiterH = RotL64((aOrbiterH * 5153745952148205645U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 15397664082460849530U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10716856680110815056U;
            aOrbiterA = RotL64((aOrbiterA * 13947203772929252823U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 833342121331428547U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1111339940097269219U;
            aOrbiterK = RotL64((aOrbiterK * 17991642769781175473U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9312963978841402871U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8225496710723213204U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 894499195498817065U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7947419530949269753U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5028446114139808517U;
            aOrbiterB = RotL64((aOrbiterB * 5593084899736787263U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9818957208200746975U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17549192719666647522U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4705007748877441833U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16389708540378477737U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8101351470141807662U;
            aOrbiterJ = RotL64((aOrbiterJ * 9858235486537441981U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterJ, 38U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterA, 19U));
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 4U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterK, 60U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordC);
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

void TwistExpander_Badminton_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB87D4F22A34F9B85ULL + 0xACAAABA252F36784ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA98F8794DF57E283ULL + 0xBFFD024E1F0819D3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x93C427F70ACBAA47ULL + 0xD01396993A4629D8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE7B92716FF8587A5ULL + 0x97AE13D5862F7AD6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC016685BC59BD2F1ULL + 0x828C8F830EA2FE77ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE60E127F20B6A0E1ULL + 0xB824944B305A0ED4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9925ADBCC2F093FFULL + 0xBCEAE96C8A7E4891ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA786D733C4A23C59ULL + 0xCD8610D3176AA335ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x91BB497189452C7BULL + 0xEFA3B533BACC0739ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC6FD542DD59A9067ULL + 0x9CAD122A231F4345ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCD61E200EBA60EAFULL + 0xB750905690762503ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB48400BA91AA4827ULL + 0xDA18492D9A3CA716ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC153DEE50A9972C7ULL + 0x84ED54DEE624D8FFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCD412E243B52FC4DULL + 0xD22FE5217B9456AAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x99DE52652FC99F27ULL + 0xB09BCE389ED0CDA3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEAB990AC21D5F159ULL + 0xBE2002F1DE7625A9ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1340U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 2930U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 4818U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 26U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 6916817163240024692U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 10U)) + 14554930751292077817U) + aNonceWordH;
            aOrbiterG = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 1098305064484336101U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 41U)) + 12192821172420471527U;
            aOrbiterH = (aWandererA + RotL64(aCross, 51U)) + 2435134991707318845U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 27U)) + 1896745368738512624U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 4U)) + 1114996424222923873U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 13U)) + 9839135798371512656U;
            aOrbiterC = ((((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 8037967239603177043U) + aPhaseEOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererD + RotL64(aCross, 37U)) + 15185468738487237432U) + aNonceWordI;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 19U)) + 4912098316394854543U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13142688607850380888U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4507379759608945839U;
            aOrbiterG = RotL64((aOrbiterG * 2989332387754215967U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7299006009652289342U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5390655277207053627U;
            aOrbiterD = RotL64((aOrbiterD * 10973744708856143715U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6744737023577785725U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15539737698867067285U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4686092035261336911U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13329866734681377952U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 13284937458969166257U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 3965985432462699445U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8695002088915702168U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3858059421620839286U;
            aOrbiterJ = RotL64((aOrbiterJ * 9559783727301092937U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6609163873243179836U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9416165620556710540U;
            aOrbiterC = RotL64((aOrbiterC * 240385043740268229U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1578449067529000433U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14309000104419489303U;
            aOrbiterB = RotL64((aOrbiterB * 7599078306153684729U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15785180680737461320U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10099222679918382021U;
            aOrbiterE = RotL64((aOrbiterE * 2012232597046182581U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10666287769220108179U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13648647399222807034U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 10772381733103127201U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9292207828896796810U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9155130791347443553U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16838229790655977057U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11334395119119245556U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6916817163240024692U;
            aOrbiterI = RotL64((aOrbiterI * 9640906826978028183U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 54U) + aOrbiterA) + RotL64(aOrbiterH, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 58U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 5U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 53U));
            aWandererD = aWandererD + ((RotL64(aScatter, 52U) + RotL64(aOrbiterI, 51U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterA, 34U)) + aPhaseEWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + RotL64(aOrbiterB, 11U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 13U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10394U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneD[((aIndex + 9152U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8034U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6672U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aCross, 58U)) + 3255291173184001106U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 21U)) + 15308468160116255528U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 23U)) + 18186972408589866656U) + aNonceWordB;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 5U)) + 4439324265978331914U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 13099263173016322486U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 50U)) + RotL64(aCarry, 13U)) + 7041561081767500660U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 6196422612687812971U;
            aOrbiterE = (aWandererD + RotL64(aCross, 3U)) + 7664260932541281413U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 39U)) + 17802347823020441056U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 47U)) + 4253107484061190446U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 37U)) + 13799496534030645312U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14252892847595951926U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5663527578664291422U;
            aOrbiterJ = RotL64((aOrbiterJ * 18314294235895182465U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11148755959699137661U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17036900929333594592U;
            aOrbiterA = RotL64((aOrbiterA * 16041243617369003291U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2403828181385259549U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17813580350434928194U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13666780980793857831U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5623611126885414523U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7293224381174846969U;
            aOrbiterH = RotL64((aOrbiterH * 7032561584670788117U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10602620906929686163U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 18015916257203385982U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10684090189688871993U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13592915735376305773U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13995866908043417505U;
            aOrbiterG = RotL64((aOrbiterG * 3802175869395887331U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8200465989447697618U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9866671660800629464U;
            aOrbiterK = RotL64((aOrbiterK * 2138851839905326265U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11557528777230608777U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 131060617338185060U;
            aOrbiterD = RotL64((aOrbiterD * 11068705423012265209U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 13404720733342982167U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13128574378042136042U;
            aOrbiterE = RotL64((aOrbiterE * 5805270317312187011U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15879295432652112238U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9433361543323748909U;
            aOrbiterC = RotL64((aOrbiterC * 3592390041363796221U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6262775775981534941U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3255291173184001106U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 2748492753337241005U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 54U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterC, 4U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + aNonceWordK);
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 52U) + aOrbiterE) + RotL64(aOrbiterB, 6U)) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterC, 51U));
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11633U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 13056U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11924U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 16156U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCross, 24U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 53U)) + 9630214189402543339U) + aNonceWordP;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 4072576573737526819U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 15994787452709618869U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 6403240137132259482U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 19U)) + 10229266900170507720U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 21U)) + 5025294577989748989U) + aPhaseEOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 11U)) + 16696461238217956883U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 5U)) + 9878318855341719119U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 37U)) + 16086635438116177346U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 51U)) + 12295437783084203730U;
            aOrbiterB = (aWandererC + RotL64(aCross, 14U)) + 7681150419912842402U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2639104034287637448U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12298170009332243573U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9397919591171238575U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3485932317267669626U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16569551670038752475U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8139802826402217631U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4448490103784103954U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14510534073046885941U;
            aOrbiterD = RotL64((aOrbiterD * 7777192047386438305U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4286195398675733451U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15790355933840266463U;
            aOrbiterA = RotL64((aOrbiterA * 13342257823027075501U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6362891510370156055U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15121822034579983174U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7268045994574844937U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13817341015719915628U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14113474087906143783U;
            aOrbiterI = RotL64((aOrbiterI * 12838910141533126059U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9988301252236121106U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11287477288382171758U;
            aOrbiterE = RotL64((aOrbiterE * 4979297247881426383U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9491727010910328644U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7961202721830514030U;
            aOrbiterK = RotL64((aOrbiterK * 16300364540313620767U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10058066852293995222U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 541563830282750968U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 1516823517052019845U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7791201128863372861U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8334318157449352359U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2924838607279239375U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6861081455774799715U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9630214189402543339U;
            aOrbiterB = RotL64((aOrbiterB * 10837610668580336781U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 30U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 44U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 22U) + aOrbiterJ) + RotL64(aOrbiterI, 23U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 53U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 42U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterB) + aNonceWordF) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20437U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 19934U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21824U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 20670U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 21U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aCross, 60U)) + 8604208734152026945U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 1374329953253889829U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 27U)) + 5779278910548228339U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 21U)) + 17670451230882805140U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 5U)) + 8193848740764866860U) + aNonceWordF;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 35U)) + 15801168428145650104U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 47U)) + 2584718176087499066U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 14950366247822737997U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 54U)) + RotL64(aCarry, 51U)) + 9779293225265670135U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 11U)) + 8688968319288372383U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 39U)) + 13665723186950342601U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9395428688359973510U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2152719218018108418U;
            aOrbiterJ = RotL64((aOrbiterJ * 15271961483518392671U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1350324137411377992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8729317951386057921U;
            aOrbiterC = RotL64((aOrbiterC * 6008790836417785083U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6317310451893678411U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10175620379041384281U;
            aOrbiterE = RotL64((aOrbiterE * 14079679617394330781U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1203082119358827708U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 523869107818193101U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4629501113595689157U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4028324959540432983U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15447631947468213912U;
            aOrbiterG = RotL64((aOrbiterG * 6037306615787729185U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14225888694733041031U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11925000696281947629U;
            aOrbiterK = RotL64((aOrbiterK * 4337022940520411253U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15015531024930608745U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16752579225076943550U;
            aOrbiterH = RotL64((aOrbiterH * 15551083683579981439U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2432733494869267901U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10103430321388601485U;
            aOrbiterA = RotL64((aOrbiterA * 18372919379972432569U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15943360147468638325U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9782703760233558733U;
            aOrbiterB = RotL64((aOrbiterB * 685056980418243879U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 18345087852012669037U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8897505040792027675U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14333687539092412967U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7402581293947129667U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8604208734152026945U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9965525485538037673U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 28U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterB, 46U));
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 53U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aNonceWordN);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 48U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 22U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26108U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 23666U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22350U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 26462U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 58U)) ^ (RotL64(aPrevious, 29U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 16462052553719977502U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 23U)) + 12337064059566619581U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 60U)) + 15801005007094515447U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 37U)) + 8228706742665081656U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 11006723027845190869U) + aNonceWordL;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 18173765337829177450U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 19U)) + 530215083653542558U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 42U)) + 6608611827035564511U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 29U)) + 2246051826221626809U) + aNonceWordB;
            aOrbiterG = (aWandererD + RotL64(aIngress, 13U)) + 5228575308895381421U;
            aOrbiterC = (aWandererE + RotL64(aCross, 21U)) + 10999213210689606857U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3773371037240485696U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8887985779436152504U;
            aOrbiterB = RotL64((aOrbiterB * 698713082830739677U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11150566414723818350U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8336366151003049546U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9033771197242493699U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13233968794237090787U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8172558473508478819U;
            aOrbiterA = RotL64((aOrbiterA * 17837070423649268435U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 133564480283347997U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15104810248883567064U;
            aOrbiterG = RotL64((aOrbiterG * 706802420642303533U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9138629520201127075U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13993086066341664080U;
            aOrbiterJ = RotL64((aOrbiterJ * 4875046427147105077U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6547273508580516932U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9838727018769865759U;
            aOrbiterD = RotL64((aOrbiterD * 11395273371936839815U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11685694999526122626U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8945983172566303116U;
            aOrbiterE = RotL64((aOrbiterE * 17791527981004597623U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17606249889617356327U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9296903152000480008U;
            aOrbiterI = RotL64((aOrbiterI * 18066622289408024413U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14248192861977167583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5467843420970464193U;
            aOrbiterC = RotL64((aOrbiterC * 10121398470914323221U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17072313558131700643U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7932446176598954438U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 11684711939539349335U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15377107166135929052U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16462052553719977502U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9057188521274832217U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterH, 30U));
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 6U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + aNonceWordF) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterD, 43U));
            aWandererC = aWandererC + ((RotL64(aIngress, 14U) + RotL64(aOrbiterC, 48U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31681U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 32353U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31048U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 30160U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 12U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aIngress, 13U)) + 13583136155674166402U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 41U)) + 12830472187484919497U;
            aOrbiterC = (aWandererG + RotL64(aCross, 57U)) + 18081197909484522509U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 18U)) + 8680634051297891550U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 13939998767458656823U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 23U)) + 1795730579103692594U) + aNonceWordJ;
            aOrbiterD = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 17369751719734069999U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 224769585901248068U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 3U)) + 4133547085925268180U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 26U)) + 7022512056309567391U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 5U)) + 10319484359046945495U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10483878349412282069U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6481381149199985736U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 9701719367082506253U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13721077228796934509U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9704818014314175007U;
            aOrbiterJ = RotL64((aOrbiterJ * 760445624027740287U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6253040047758584339U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16890211690273641226U;
            aOrbiterK = RotL64((aOrbiterK * 5622534399866057841U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6216227831265032436U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2023609047004658739U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3252332895698310147U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9201669637050388263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5106927540934338576U;
            aOrbiterI = RotL64((aOrbiterI * 6368134569042291431U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10080368957861445998U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10784789383436485808U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3794918350254445939U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15426339824951793026U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17637144549368340331U;
            aOrbiterH = RotL64((aOrbiterH * 10971293914614704441U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9941300382181962134U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8118046374121322097U;
            aOrbiterB = RotL64((aOrbiterB * 8481945819050983127U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5138086185042567633U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7279942739248982986U;
            aOrbiterA = RotL64((aOrbiterA * 12911998308338410917U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12135610639038562853U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12945353426409788798U;
            aOrbiterE = RotL64((aOrbiterE * 7434977715954413699U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7534876598022096222U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13583136155674166402U;
            aOrbiterG = RotL64((aOrbiterG * 8194058098043157015U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 54U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterE, 5U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 40U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterK, 19U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 22U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Badminton_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEBA64C76CD19150DULL + 0xEB6C1D545DBC5D45ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC9E0D3B30BDE41AFULL + 0xE161954B7B8A08C7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x91BAE12E0DE01069ULL + 0x86E6939927CC28B5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xACC8920D167D64C1ULL + 0xAE1000FA11FC841EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF2B96FD9A38F8133ULL + 0xD128647B915409DBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBD20DFA203B86EE3ULL + 0xF953DF9782735C42ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x897478317E3CBFD5ULL + 0xB5044016A9D44F3CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE9AE69EA20CEA461ULL + 0x99B8F3EE35434BF4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x99312D00B8821083ULL + 0xEB4ABFB2CA039DC7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAE20E6E34EB49CD5ULL + 0x94C0CB432D850C0AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDAE75ED0392E3511ULL + 0xC8B8F6943C94F4BFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBBAB20623587CDDFULL + 0xE0AC2FEDE184CF41ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF6FE31F30915BD61ULL + 0xC40F49B37FA4D109ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xADA3EBE596AFB48BULL + 0xF3F774E796A84AEEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB1FC84ECF89496BBULL + 0xC6DDFD0414024D32ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x94F7B92ECC332231ULL + 0x982BACB107FA0B19ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 246U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 821U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 707U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 5139U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 14U) + RotL64(aCross, 27U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aCross, 54U)) + 7896237440058555694U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 29U)) + 11870529476037558635U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 43U)) + 9158983227801569448U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 4710172270996950329U) + aPhaseFOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 14634482800356647630U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 27U)) + 8822207952170610891U) + aNonceWordL;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 13755891414028982553U) + aPhaseFOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 11U)) + 4555293067488040719U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 22U)) + 2816805148093762081U) + aNonceWordB;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 47U)) + 2122631477965135190U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 5U)) + 4592922416380416071U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7102471666524164715U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17274623547879474204U;
            aOrbiterF = RotL64((aOrbiterF * 5443572270546181789U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 938587316977094680U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18258015823797023523U;
            aOrbiterE = RotL64((aOrbiterE * 6068819567674605919U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5809987756043471595U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5083075160112581620U;
            aOrbiterK = RotL64((aOrbiterK * 3313957222154937503U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5960021727750946496U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5967477320950630150U;
            aOrbiterH = RotL64((aOrbiterH * 330964768256424655U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6578428711689296132U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5601728218197771276U;
            aOrbiterJ = RotL64((aOrbiterJ * 9552559022315971847U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7923809409017855241U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16479366540906497019U;
            aOrbiterA = RotL64((aOrbiterA * 7118578387798460919U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 17000467091738009736U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6801634573655508028U;
            aOrbiterI = RotL64((aOrbiterI * 10584635770060137089U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 123668445682719574U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14462802805503986316U;
            aOrbiterD = RotL64((aOrbiterD * 12398236364304875941U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2433338393261685871U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13869012262404991729U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12443261517483942937U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4832421585086516998U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11284414949564414958U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1586650935440790991U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17872556812561387030U) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7896237440058555694U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16784165278693056013U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 48U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aIngress, 18U) + aOrbiterH) + RotL64(aOrbiterF, 60U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 40U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + aNonceWordC) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordF);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10814U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9926U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7344U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((aIndex + 10879U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 58U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererC + RotL64(aCross, 19U)) + 1898718075389870739U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 5631794889237247403U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 47U)) + 18219714659484524607U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 41U)) + 15419581386225732921U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 51U)) + 9125575431710198210U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 4U)) + 12205871520544965505U;
            aOrbiterK = (aWandererB + RotL64(aCross, 57U)) + 7617534300497343422U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 18017579105368135814U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 10693882161946020042U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 24U)) + 11669615701700895306U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 21U)) + 11045110212889232165U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 18019107802806469913U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12315940560472528716U;
            aOrbiterG = RotL64((aOrbiterG * 4505122470351404065U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4899009736070044310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17412253404253730364U;
            aOrbiterH = RotL64((aOrbiterH * 10791901166391946485U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4826286251927854181U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4523455921321845084U;
            aOrbiterD = RotL64((aOrbiterD * 14534103906736598099U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4132514462154182215U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7164745605985109269U;
            aOrbiterK = RotL64((aOrbiterK * 14107325508977225261U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6297434295807635654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8813887638672996646U;
            aOrbiterB = RotL64((aOrbiterB * 17495632530773158201U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11086381278955626084U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5660733992573928887U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11248164458720777889U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14851044686208609882U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12707776386060264479U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4470919091467313071U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11508023384209716657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11752973809740920034U;
            aOrbiterC = RotL64((aOrbiterC * 10212754472298834769U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16746821150860017820U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9659421716296641396U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7530071874978553673U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3192309064305104593U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11409078048681398061U;
            aOrbiterF = RotL64((aOrbiterF * 14991409124701807765U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 315359495275427324U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1898718075389870739U;
            aOrbiterI = RotL64((aOrbiterI * 13126661894614781343U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 10U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 48U));
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterA, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + aNonceWordG);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterA, 60U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 18U) + aOrbiterF) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15556U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 16145U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16191U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 15599U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 26U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 41U)) + 11274974230580265396U) + aNonceWordN;
            aOrbiterG = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 16658438747342741547U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 16612986966106053844U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 37U)) + 9329502236843231290U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 44U)) + 14088261356708344656U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 13692608802007789581U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 39U)) + 6824473946645682398U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 11U)) + 2072915876348570040U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 54U)) + 7420507753044460759U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 5U)) + 4677557318688502593U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 23U)) + 15081678577055628459U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 7026792817486507482U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14871665922943969918U;
            aOrbiterC = RotL64((aOrbiterC * 694073180313083145U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6807734532159292872U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17882797335141303280U;
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9233542707022629190U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1205501586581350876U;
            aOrbiterG = RotL64((aOrbiterG * 2596053290311090589U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10878718669747466677U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8066049063548639241U;
            aOrbiterH = RotL64((aOrbiterH * 3031382633089381605U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 861295180226875235U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9134969787937288583U;
            aOrbiterE = RotL64((aOrbiterE * 7565008208670843555U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6726642007159809594U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8061661744643240470U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6703498926835391813U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13541412083111962884U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8617442758729315637U;
            aOrbiterA = RotL64((aOrbiterA * 15471862889276160953U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16884403561131293362U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9490680911678221233U;
            aOrbiterK = RotL64((aOrbiterK * 15988763830018001033U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10486145044311386738U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10200001044821063684U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 16149790736141571017U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6997073594007878034U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13585783612009989767U;
            aOrbiterB = RotL64((aOrbiterB * 11425303157774550449U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3847846040256340653U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11274974230580265396U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13970270689108369205U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterB, 34U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 24U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 42U) + aOrbiterH) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21178U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19750U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21324U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16893U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 13U)) + 9888431329297626900U) + aNonceWordE;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 26U)) + 2937735167534624403U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 17626022970343789617U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 5665660859333693743U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 19U)) + 1060537034632076669U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 21U)) + 743777763907175800U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 5744905970181808845U) + aNonceWordA;
            aOrbiterG = ((((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 3545351394494002180U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererI + RotL64(aScatter, 51U)) + 4877547088414106007U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 54U)) + 11669378338379598445U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 5U)) + 2961072441706158212U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13984945589234919765U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1433097875470903205U;
            aOrbiterK = RotL64((aOrbiterK * 451996840039906781U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 716415411025451152U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8542286150858297810U;
            aOrbiterC = RotL64((aOrbiterC * 9139015340823332449U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12932391786479661299U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14005503313299177013U;
            aOrbiterB = RotL64((aOrbiterB * 802663466907819743U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9382792812676318046U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5138554251079724724U;
            aOrbiterH = RotL64((aOrbiterH * 6386016499265056247U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8522380066269546172U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11825536408101906458U;
            aOrbiterG = RotL64((aOrbiterG * 17042837108792016849U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15504062350899452495U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1219010998820336744U;
            aOrbiterD = RotL64((aOrbiterD * 10650635772711590803U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6442717843380349632U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1047843426279085117U;
            aOrbiterE = RotL64((aOrbiterE * 4074561571072878005U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10611039527108679173U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5092816736177358221U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 14342779343820140833U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12327496881352988530U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6405703847824845457U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12094143526751620113U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8906613392335197542U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5962698890029858689U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9136193803330500489U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2610083915800734277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9888431329297626900U;
            aOrbiterI = RotL64((aOrbiterI * 3794133356691218671U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 30U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterF, 11U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 42U) + RotL64(aOrbiterK, 21U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterH, 53U)) + aNonceWordO) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 28U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 5U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 57U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 50U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24931U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24543U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22496U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 23813U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 22U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 5U)) + 12775735908960052604U) + aNonceWordG;
            aOrbiterA = (aWandererB + RotL64(aCross, 37U)) + 11791373812080296887U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 54U)) + 5537362877706057303U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 43U)) + 2023912048504189380U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 17668828109963766893U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 558908629933941224U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 1479633119685446888U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 23U)) + 15460320397843364063U;
            aOrbiterD = (aWandererD + RotL64(aCross, 51U)) + 10059749397555469054U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 13U)) + 9987633811929693924U) + aNonceWordH;
            aOrbiterE = (aWandererA + RotL64(aScatter, 10U)) + 10087337844580228269U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4446204415503364254U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 15106063243302192717U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 13273756657334709803U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9430197906134676162U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1226048679997253363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14247538885252664127U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10611580584157624739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3137391249289641509U;
            aOrbiterF = RotL64((aOrbiterF * 5462682413239873181U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9327201928815412810U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7890659377013147073U;
            aOrbiterI = RotL64((aOrbiterI * 13827717178378062047U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10675114832750356941U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8804440385852327267U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12871947817782057116U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11015991745792051390U;
            aOrbiterG = RotL64((aOrbiterG * 17152451500505815031U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6320437975845673731U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 702457937087191287U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17491257114676739589U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16629064896250312921U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6054107387816339103U;
            aOrbiterD = RotL64((aOrbiterD * 6983767878966747219U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13274874838094190290U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12211422735294360321U;
            aOrbiterE = RotL64((aOrbiterE * 5113738196151089817U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15338616110718583619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1475787183754511373U;
            aOrbiterA = RotL64((aOrbiterA * 10904607643785840003U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15486810401396777742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12775735908960052604U;
            aOrbiterK = RotL64((aOrbiterK * 7478156942468930207U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 40U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 37U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterE, 57U));
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterG, 14U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererA, 6U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30698U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30076U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29558U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 28869U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 46U)) + 6916817163240024692U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 14554930751292077817U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 27U)) + 1098305064484336101U) + aPhaseFOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aIngress, 39U)) + 12192821172420471527U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 50U)) + 2435134991707318845U) + aNonceWordO;
            aOrbiterH = (aWandererI + RotL64(aScatter, 41U)) + 1896745368738512624U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 21U)) + 1114996424222923873U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 9839135798371512656U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 27U)) + 8037967239603177043U;
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 15185468738487237432U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 43U)) + 4912098316394854543U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13142688607850380888U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4507379759608945839U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2989332387754215967U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7299006009652289342U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5390655277207053627U;
            aOrbiterF = RotL64((aOrbiterF * 10973744708856143715U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6744737023577785725U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15539737698867067285U;
            aOrbiterH = RotL64((aOrbiterH * 4686092035261336911U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13329866734681377952U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13284937458969166257U;
            aOrbiterE = RotL64((aOrbiterE * 3965985432462699445U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8695002088915702168U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3858059421620839286U;
            aOrbiterC = RotL64((aOrbiterC * 9559783727301092937U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6609163873243179836U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9416165620556710540U;
            aOrbiterK = RotL64((aOrbiterK * 240385043740268229U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1578449067529000433U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14309000104419489303U;
            aOrbiterA = RotL64((aOrbiterA * 7599078306153684729U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15785180680737461320U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10099222679918382021U;
            aOrbiterJ = RotL64((aOrbiterJ * 2012232597046182581U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10666287769220108179U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13648647399222807034U;
            aOrbiterG = RotL64((aOrbiterG * 10772381733103127201U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9292207828896796810U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9155130791347443553U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16838229790655977057U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11334395119119245556U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6916817163240024692U;
            aOrbiterI = RotL64((aOrbiterI * 9640906826978028183U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterG, 34U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 54U) + aOrbiterI) + RotL64(aOrbiterH, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterC, 48U));
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 41U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 38U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordH);
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

void TwistExpander_Badminton_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD12B338366232DD7ULL + 0xD060E8B1665D0756ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB87535AB151E8187ULL + 0xD2A6E83F07A2C937ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x91BBB2C72550C35FULL + 0xF925D33032D80375ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDD0E0B33014C3F6DULL + 0xFD9E792207CA62C4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBC6E831999295669ULL + 0xAB1879FACF2E2C37ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x825C26B48005B6B1ULL + 0x9C9ED802ED2785F0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBFDE37D25A11E26BULL + 0xFA1B18F9756E68B6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF3E181FFDF6FB79DULL + 0xC6998F2EFAF38138ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA93B13E4314BC5ADULL + 0xEE8036A50EF4148BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA720B4CFE9371E89ULL + 0xACABA479B6907B7FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF17C8658DE969869ULL + 0x9CA80A2DFA0BC723ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE373C74A3A75C01DULL + 0xA4B22F8AB00A73E6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE980B6FC8044D451ULL + 0xF94517AF2452FA03ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB0398222B85B4CCDULL + 0x942E7FDFE9D602A2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA5E9C7C298F24C55ULL + 0x9652B508EF73C487ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCC3F314553C87069ULL + 0xF13DB94D8A976F93ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2910U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((aIndex + 5155U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1841U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4457U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U)) + (RotL64(aIngress, 54U) + RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 47U)) + 6068543441070417854U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 53U)) + 2995980468193441856U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 18020277482171594003U;
            aOrbiterB = (aWandererG + RotL64(aCross, 50U)) + 4293807434721230702U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 11U)) + 7980599111583893156U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 23U)) + 8593141111851052016U) + aNonceWordH;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 57U)) + 5903487523900084325U) + aNonceWordA;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 27U)) + 15112035513447930209U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 6U)) + 9854037263057006439U;
            aOrbiterD = ((((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 16759760289688823193U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 12622628933030601390U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1264668857268123425U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16302812053619101593U;
            aOrbiterK = RotL64((aOrbiterK * 18291400055836111547U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16087995784896123610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7970269262800468363U;
            aOrbiterG = RotL64((aOrbiterG * 14924752223305807461U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5331477046030959632U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16534913204255550893U;
            aOrbiterF = RotL64((aOrbiterF * 1013433634373673565U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11042821902537871209U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8069677512345031660U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13622218526054132397U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5737130058129936372U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1076627182956662997U;
            aOrbiterI = RotL64((aOrbiterI * 14342191224014199929U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13911061091801078190U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15397603151098990373U;
            aOrbiterJ = RotL64((aOrbiterJ * 1802890451633592245U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15137326716738637972U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11248737008959896786U;
            aOrbiterA = RotL64((aOrbiterA * 90789374131547005U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1847847987633923657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10560748778679145431U;
            aOrbiterE = RotL64((aOrbiterE * 2919333327817231099U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2703726238610290251U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12950671360471467310U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7490327691501537047U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 10331504168520449467U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1541527607705280906U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14197400812600186171U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9135056476214341809U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6068543441070417854U;
            aOrbiterD = RotL64((aOrbiterD * 14102524444094948875U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterE, 22U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + aNonceWordK);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 42U) + RotL64(aOrbiterE, 43U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterG, 56U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterK, 37U)) + aNonceWordI) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9821U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6766U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8761U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9368U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 18U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aCross, 35U)) + 3255291173184001106U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 30U)) + 15308468160116255528U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 41U)) + 18186972408589866656U) + aNonceWordF;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 39U)) + 4439324265978331914U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 13099263173016322486U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 7041561081767500660U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 14U)) + RotL64(aCarry, 57U)) + 6196422612687812971U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 47U)) + 7664260932541281413U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 37U)) + 17802347823020441056U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 11U)) + 4253107484061190446U;
            aOrbiterE = (aWandererF + RotL64(aCross, 51U)) + 13799496534030645312U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14252892847595951926U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5663527578664291422U;
            aOrbiterJ = RotL64((aOrbiterJ * 18314294235895182465U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11148755959699137661U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17036900929333594592U;
            aOrbiterH = RotL64((aOrbiterH * 16041243617369003291U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2403828181385259549U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17813580350434928194U;
            aOrbiterC = RotL64((aOrbiterC * 13666780980793857831U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5623611126885414523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7293224381174846969U;
            aOrbiterA = RotL64((aOrbiterA * 7032561584670788117U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10602620906929686163U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18015916257203385982U;
            aOrbiterG = RotL64((aOrbiterG * 10684090189688871993U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13592915735376305773U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13995866908043417505U;
            aOrbiterI = RotL64((aOrbiterI * 3802175869395887331U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8200465989447697618U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9866671660800629464U;
            aOrbiterK = RotL64((aOrbiterK * 2138851839905326265U), 51U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 11557528777230608777U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 131060617338185060U;
            aOrbiterF = RotL64((aOrbiterF * 11068705423012265209U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13404720733342982167U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13128574378042136042U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5805270317312187011U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15879295432652112238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9433361543323748909U;
            aOrbiterD = RotL64((aOrbiterD * 3592390041363796221U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6262775775981534941U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3255291173184001106U;
            aOrbiterE = RotL64((aOrbiterE * 2748492753337241005U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 42U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterF, 46U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 41U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 37U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 46U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 58U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 6U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13654U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 13321U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15142U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11550U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 43U)) + 12262991801139086177U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 35U)) + 7963038771924890197U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 54U)) + RotL64(aCarry, 53U)) + 15540520327933568896U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 57U)) + 8745565892055020722U) + aNonceWordO;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 16619329199683755286U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 47U)) + 10865705026433867260U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 41U)) + 2743368697984518059U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 37U)) + 5556006271515473135U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 30U)) + 5355833281353498588U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 8313616108963479829U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 19U)) + 16657121016801866434U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16532226425013000833U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5800465874932467232U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5966395771690704577U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17882948163883121328U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15029375310296563175U;
            aOrbiterC = RotL64((aOrbiterC * 17021415832288477713U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10170682648007918739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11829089574189398773U;
            aOrbiterF = RotL64((aOrbiterF * 15755874363488568849U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1746524867389196322U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10217423427886742775U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9166162099575333519U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1338457710729082656U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1319981417675542556U;
            aOrbiterA = RotL64((aOrbiterA * 9518448254565489715U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3985281993069194761U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7281264481139915593U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 13498446162967276739U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 17394503335338855566U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1430703546991948227U;
            aOrbiterG = RotL64((aOrbiterG * 1623206122475721175U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 472559435062214929U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8065899137826178995U;
            aOrbiterD = RotL64((aOrbiterD * 13287499768933229539U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3377996409668333322U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10456089146891981998U;
            aOrbiterB = RotL64((aOrbiterB * 12037044781049717633U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5246784368779537905U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8518987022368391332U;
            aOrbiterI = RotL64((aOrbiterI * 4046763804695058779U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7791883487780325967U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12262991801139086177U;
            aOrbiterE = RotL64((aOrbiterE * 3409890579914160747U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 58U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + aNonceWordB) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 24U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 13U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aScatter, 12U) + RotL64(aOrbiterE, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21668U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 20303U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17244U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18416U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 12U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 37U)) + 8988572360732005217U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 10U)) + RotL64(aCarry, 3U)) + 17889613225105985335U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 43U)) + 15563478320513948626U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 51U)) + 3441351228410524816U) + aNonceWordL;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 4425592689451435346U) + aNonceWordD;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 4U)) + 12733160231627305928U) + aNonceWordF;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 57U)) + 3574152157304607854U;
            aOrbiterC = (aWandererI + RotL64(aCross, 21U)) + 15167631896729808783U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 53U)) + 15822667973915417055U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 13U)) + 17181685481076577637U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 9979204751408873468U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1334240485667164762U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9190066751460137016U;
            aOrbiterF = RotL64((aOrbiterF * 14585141844653660363U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15465215829109246336U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2305208282453624419U;
            aOrbiterK = RotL64((aOrbiterK * 10257861974108363283U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16951510027310993926U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11117938943423526901U;
            aOrbiterB = RotL64((aOrbiterB * 7805486716716924787U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12461379120662979432U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11719697049048823897U;
            aOrbiterG = RotL64((aOrbiterG * 14880996802304818757U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6843357278142933570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12727898578324702374U;
            aOrbiterC = RotL64((aOrbiterC * 9786435451654365097U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 18127999660067652233U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11754709060558683082U;
            aOrbiterA = RotL64((aOrbiterA * 12798744012150745847U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 16940151146420516184U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12924950783056761895U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8898170377271926745U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14829713915929878471U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 840466047621042565U;
            aOrbiterE = RotL64((aOrbiterE * 10748511630509529489U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11469637840333471085U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5561780312837795893U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 11935079844970978957U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1059834104159730610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10122108814456766430U;
            aOrbiterI = RotL64((aOrbiterI * 2184693583782179921U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14857099570072635006U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8988572360732005217U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 14409836741925393077U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 58U));
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 23U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterF, 46U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterC, 51U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24495U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26323U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22991U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24946U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 42U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aIngress, 37U)) + 5960680319644404115U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 43U)) + 16050752633567034185U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 6U)) + 8447503223226854741U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 14176813813397917591U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 10534915376130006644U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererG + RotL64(aCross, 27U)) + 6866224454375302514U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 3U)) + 16506374165041008396U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 18U)) + RotL64(aCarry, 47U)) + 7167814023968794098U) + aNonceWordP;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 47U)) + 13870852197416596664U) + aNonceWordE;
            aOrbiterC = (aWandererB + RotL64(aCross, 11U)) + 18064038854848993105U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 51U)) + 9869630811507771691U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 863613100452759380U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16597969741225436529U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 2680793528887208903U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6575347108051310653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17062262265485019063U;
            aOrbiterJ = RotL64((aOrbiterJ * 7601045488473620019U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7193399224636409133U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14146747818810433849U;
            aOrbiterD = RotL64((aOrbiterD * 5273185769989530041U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9441449106442431427U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4303295336545399503U;
            aOrbiterC = RotL64((aOrbiterC * 8829695296836242587U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12604760768543193458U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15779327512379787715U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14000905201441272597U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15553000781122708728U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17162740616060079717U;
            aOrbiterI = RotL64((aOrbiterI * 9458662233556750239U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1032374679817715156U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16413393156165548232U;
            aOrbiterG = RotL64((aOrbiterG * 549659738811935015U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14056855000013992045U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7399202019042538829U;
            aOrbiterA = RotL64((aOrbiterA * 6103508549612077695U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2218389473339103389U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4679497280975967770U;
            aOrbiterF = RotL64((aOrbiterF * 9228353578259815023U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7620538119914173747U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3118355627808424159U;
            aOrbiterK = RotL64((aOrbiterK * 12481319980496032783U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16787092219237931175U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5960680319644404115U;
            aOrbiterE = RotL64((aOrbiterE * 10727217147056112401U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 58U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 51U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterK, 46U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterE, 43U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 37U)) + aOrbiterG) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31069U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27476U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30437U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27811U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 53U)) + 6916817163240024692U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 21U)) + 14554930751292077817U) + aNonceWordK;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 39U)) + 1098305064484336101U;
            aOrbiterC = (aWandererF + RotL64(aCross, 46U)) + 12192821172420471527U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 2435134991707318845U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 27U)) + 1896745368738512624U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 13U)) + 1114996424222923873U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 9839135798371512656U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 43U)) + 8037967239603177043U) + aNonceWordG;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 51U)) + 15185468738487237432U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 18U)) + RotL64(aCarry, 53U)) + 4912098316394854543U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13142688607850380888U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 4507379759608945839U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2989332387754215967U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7299006009652289342U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5390655277207053627U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10973744708856143715U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6744737023577785725U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15539737698867067285U;
            aOrbiterG = RotL64((aOrbiterG * 4686092035261336911U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13329866734681377952U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13284937458969166257U;
            aOrbiterK = RotL64((aOrbiterK * 3965985432462699445U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8695002088915702168U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3858059421620839286U;
            aOrbiterB = RotL64((aOrbiterB * 9559783727301092937U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6609163873243179836U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9416165620556710540U;
            aOrbiterE = RotL64((aOrbiterE * 240385043740268229U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1578449067529000433U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14309000104419489303U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 7599078306153684729U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15785180680737461320U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10099222679918382021U;
            aOrbiterF = RotL64((aOrbiterF * 2012232597046182581U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10666287769220108179U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13648647399222807034U;
            aOrbiterD = RotL64((aOrbiterD * 10772381733103127201U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9292207828896796810U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9155130791347443553U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16838229790655977057U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11334395119119245556U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6916817163240024692U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 9640906826978028183U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 52U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterF) + aNonceWordD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterF, 37U));
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 6U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 3U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterK, 44U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterK, 39U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordG);
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

void TwistExpander_Badminton_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5154U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5277U)) & W_KEY1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 8174U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 6581U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererF + RotL64(aIngress, 4U)) + 15036852811491820366U;
            aOrbiterI = (aWandererD + RotL64(aCross, 53U)) + 305637140752898475U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 11948631574496129610U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 5321623592482991426U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 13U)) + 4075270159062690728U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 19U)) + 15111580500356908928U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 47U)) + 7244150695504160363U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 5131563519577488862U) + aPhaseCOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 34U)) + 5881954992088651371U) + aPhaseCOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12780935808751507998U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12599159643925470226U;
            aOrbiterF = RotL64((aOrbiterF * 17690046932587062701U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9466589929741834066U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6093158735705189789U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17461243886150519249U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15456408913739900718U;
            aOrbiterJ = RotL64((aOrbiterJ * 16093292401746174671U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 11260643903290392780U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7870342756041882616U;
            aOrbiterA = RotL64((aOrbiterA * 2431528656086173419U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 134484990005888936U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10626896209992890407U;
            aOrbiterG = RotL64((aOrbiterG * 12034131076645285597U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14031164129515132292U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1771835705730244212U;
            aOrbiterH = RotL64((aOrbiterH * 186981668443596623U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16395472745067254664U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1455944290845294254U;
            aOrbiterC = RotL64((aOrbiterC * 6757824754363319079U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17866422769075350837U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10226884082632410805U;
            aOrbiterI = RotL64((aOrbiterI * 206035536985843815U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14474587247775371703U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8501763445324525303U;
            aOrbiterD = RotL64((aOrbiterD * 5298694643596784007U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 18U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 52U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 53U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 28U)) + aPhaseCWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 57U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 12U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13526U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((aIndex + 8239U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12608U)) & W_KEY1], 54U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13412U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aScatter, 19U)) + 18255347001097480328U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 13679246790311505735U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 5U)) + 10565839529765027116U;
            aOrbiterI = (aWandererB + RotL64(aCross, 43U)) + 14327172566224769901U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 16239024612038195174U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 23U)) + 13800012174212131890U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 5U)) + 13900288860157577583U;
            aOrbiterK = (aWandererD + RotL64(aCross, 13U)) + 4144386119777112740U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 51U)) + 3154558262670631372U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7456728543137614001U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11709519851158935384U;
            aOrbiterE = RotL64((aOrbiterE * 7016689518570071587U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15607438907832240304U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9276575329661725624U;
            aOrbiterD = RotL64((aOrbiterD * 8879744070762412745U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6459435969129449226U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6442382118416542275U;
            aOrbiterC = RotL64((aOrbiterC * 2921027306686588233U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12117432107282150865U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6831279293184793243U;
            aOrbiterK = RotL64((aOrbiterK * 2435360641135249073U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9520022957804572889U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8322178689474588679U;
            aOrbiterA = RotL64((aOrbiterA * 1627707191467537115U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4162401591586869316U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8994015844714895961U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15421910378057951895U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10038095909727959633U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 17756404450592957616U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14255952184627347295U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3379089265413427719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11341713098678108441U;
            aOrbiterH = RotL64((aOrbiterH * 2500587373161411961U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4030296130743454165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6332387792111212064U;
            aOrbiterF = RotL64((aOrbiterF * 16490982218150897861U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 26U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterH, 30U));
            aWandererK = aWandererK + ((RotL64(aScatter, 44U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 47U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 26U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 5U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19152U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20736U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20041U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 18613U)) & W_KEY1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 24U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 3U)) + 4739486756133131180U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 22U)) + 16089707555501328184U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 15310047330238536453U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 7901411596386834955U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 39U)) + 4357555491060982163U) + aPhaseCOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 57U)) + 15667085602825720102U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 47U)) + 8520635334382269253U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 34U)) + 1772509779231068315U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 15336170957886025677U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8628770833489469980U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15469234024247246228U;
            aOrbiterJ = RotL64((aOrbiterJ * 8905266995119987947U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10796430900884288328U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10660110397012853289U;
            aOrbiterE = RotL64((aOrbiterE * 9140007610912037461U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11202284258711214794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17509491802893182994U;
            aOrbiterK = RotL64((aOrbiterK * 9329107599972703671U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16212572740740103554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2190030203761579226U;
            aOrbiterH = RotL64((aOrbiterH * 3101886685668871045U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12014337082293041909U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3733531010807001506U;
            aOrbiterA = RotL64((aOrbiterA * 5797362244066062299U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7100994963061975529U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17837541162838600258U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8745987361678166553U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3311518938023146951U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7709505172646831553U;
            aOrbiterD = RotL64((aOrbiterD * 7121143171245765213U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4979968094554018443U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16822214821463034107U;
            aOrbiterG = RotL64((aOrbiterG * 8618262120451291765U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8376124175020587079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11084586282092424876U;
            aOrbiterC = RotL64((aOrbiterC * 5835632742522563537U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 18U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 4U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterC, 18U)) + aPhaseCWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterE, 28U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28373U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27602U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30441U)) & S_BLOCK1], 22U) ^ RotL64(mSource[((aIndex + 31014U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 29U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 13U)) + 3236820517816085022U) + aPhaseCOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 57U)) + 741288875914097926U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 26U)) + 8417246926007729580U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 53U)) + 9715717805774537170U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 14360243844821619482U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 10760908100206775334U;
            aOrbiterC = (aWandererE + RotL64(aCross, 5U)) + 3434641779946167811U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 7885568822756234567U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 48U)) + 3041563437672051294U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15761355327564963516U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1158633562785937421U;
            aOrbiterI = RotL64((aOrbiterI * 15511324886867188235U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9338581575871970653U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9172038894262857354U;
            aOrbiterK = RotL64((aOrbiterK * 3110871165285625807U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14653924713599790081U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3854497592598563309U;
            aOrbiterC = RotL64((aOrbiterC * 11737111068815795303U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16286980180327600557U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5092583772591249756U;
            aOrbiterB = RotL64((aOrbiterB * 13955105624639442903U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4288397994175567333U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15584236478994873104U;
            aOrbiterJ = RotL64((aOrbiterJ * 1860480595862755379U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5557463939827483792U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2659814275753280856U;
            aOrbiterE = RotL64((aOrbiterE * 17702430405693184643U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6941807963525063449U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2040598555191211307U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14750544987531722765U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 347572666231116258U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 779304821185302523U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14180254150318109855U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10632524582873079742U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9761308771280517212U;
            aOrbiterH = RotL64((aOrbiterH * 13926235411726048921U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 22U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 52U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 28U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF + ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 47U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterI, 28U)) + aPhaseCWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 42U) + aOrbiterE) + RotL64(aOrbiterH, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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

void TwistExpander_Badminton_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7646U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5599U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5424U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 264U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 6069475454765660321U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 11U)) + 11483704742497268068U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 11055697447388986418U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 26U)) + RotL64(aCarry, 57U)) + 10897095046039997004U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 3U)) + 4731637118230457840U) + aPhaseDOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13855839187084986751U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5328208115460188239U;
            aOrbiterC = RotL64((aOrbiterC * 3800417611141123383U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12479538544291412985U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10740165998792608231U;
            aOrbiterE = RotL64((aOrbiterE * 14046827922294477379U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6492798157284955373U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13056825957483891921U;
            aOrbiterD = RotL64((aOrbiterD * 14882112110627751751U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2068184064919194657U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5656302738780746294U;
            aOrbiterA = RotL64((aOrbiterA * 16493021179127646345U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11193756120230763294U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17306750816837208999U;
            aOrbiterI = RotL64((aOrbiterI * 7949360041241439741U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 43U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterI, 57U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 18U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12627U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14093U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11018U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12500U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 12122689833405846292U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 9640400270962766788U) + aPhaseDOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 20U)) + RotL64(aCarry, 53U)) + 9141937998266739071U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 11U)) + 12899395770434090537U) + aPhaseDOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 29U)) + 13457918115408031842U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15134784483576000943U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12540961268790055438U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3295706140418040089U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6306886773092764230U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13573343491337243121U;
            aOrbiterE = RotL64((aOrbiterE * 15893457012357368707U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8545588657348974413U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10891410570357275120U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5399310978367842841U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2877137119767060151U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9178097682386595144U;
            aOrbiterD = RotL64((aOrbiterD * 3524486002084427513U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15528007881855616978U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11368419529245281435U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12433207037378339309U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 14U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 46U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + aPhaseDWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 58U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21871U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 23795U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18527U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((aIndex + 21333U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 14U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 9751314027302668907U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 4U)) + RotL64(aCarry, 43U)) + 12175450995523107056U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 17519694958730119552U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 13U)) + 9093525527925682263U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 35U)) + 3713831321786810138U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10108355209191835040U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12956307447311314768U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9198936928658626667U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1904298513945877359U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4658049993308574460U;
            aOrbiterF = RotL64((aOrbiterF * 10482422152074338611U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9826333658248851902U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12058666914724365134U;
            aOrbiterH = RotL64((aOrbiterH * 964233873188373939U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2516574707110528099U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13335308331049750235U;
            aOrbiterJ = RotL64((aOrbiterJ * 5880227828760598587U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8230749255538495304U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16536559486797811486U;
            aOrbiterK = RotL64((aOrbiterK * 7097036838156464969U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 23U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 14U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 14U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31100U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 25631U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31507U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32659U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 16651241552253078315U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 3U)) + 4558144676982478003U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 47U)) + 8814884320080367550U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 16011579668555672117U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 4738918668759862438U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12526083125540985108U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8048723561746000552U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11914807994597963481U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1082218464034639039U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8432043246965946816U;
            aOrbiterB = RotL64((aOrbiterB * 7801965585991025451U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9982080524048636852U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6720069955755215919U;
            aOrbiterF = RotL64((aOrbiterF * 1025046364205332059U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1019035028070247757U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7360619079463870467U;
            aOrbiterJ = RotL64((aOrbiterJ * 6623074813047915863U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10893918488381348474U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1390297670907738019U;
            aOrbiterD = RotL64((aOrbiterD * 11909657437658597735U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterF, 47U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 50U) + RotL64(aOrbiterB, 30U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Badminton_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 901U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 4680U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 665U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3982U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 36U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererF + RotL64(aCross, 19U)) + 12615321415808640429U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 27U)) + 15712784676459931207U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 11U)) + 11013335427004930046U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 8298733856304768806U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 6207732959150824216U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 51U)) + 9769864876127544038U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 10782181918651152563U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5790454015845620939U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15606578025386733803U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7079287329365566355U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5522352539991175304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5993355818572869649U;
            aOrbiterA = RotL64((aOrbiterA * 15221467311057431139U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10864534396947622047U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12090053126235913528U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7250801471645972261U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14191181677234981396U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2258570108233924592U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8307541155393855209U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8448114811381534603U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2702389315763499817U;
            aOrbiterH = RotL64((aOrbiterH * 6710443836432274393U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17202184076718780200U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 150549910056015002U;
            aOrbiterE = RotL64((aOrbiterE * 195034681254956335U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4910512055808124967U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4783477997418403079U;
            aOrbiterF = RotL64((aOrbiterF * 861977492146512865U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 41U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 10U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 48U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterA, 21U)) + aPhaseEWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10545U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10328U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9711U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 14297U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererH + RotL64(aIngress, 5U)) + 1210605127156905516U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 57U)) + 11964595428173569519U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 37U)) + 16277319029916258482U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 12369497463101824572U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 6201248574067068202U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 35U)) + 1727477025667206661U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 19U)) + 1404510627789806851U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6948213591282018925U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 6688865181284421478U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12619122841662247279U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3351130769402360855U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12681032488906270823U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3680893896579741263U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3591412591193726763U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16153817571210878589U;
            aOrbiterA = RotL64((aOrbiterA * 4165137036092246349U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3808228354421006630U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1427373776207504205U;
            aOrbiterE = RotL64((aOrbiterE * 4534374093769595531U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1831554180932501132U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1114853085120949215U;
            aOrbiterF = RotL64((aOrbiterF * 4264176108298812905U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2080935638828366835U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16104777999646489828U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15205199362011777473U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9782806013673440791U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3721620299829386454U;
            aOrbiterI = RotL64((aOrbiterI * 6286765834910272409U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 22U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 29U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 37U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterA, 44U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23709U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 20021U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19345U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18171U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 3621877681473089725U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 19U)) + 4451752751536414717U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 11371625415377772117U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 47U)) + 6046792758881150619U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 8213166120394461682U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 54U)) + 4343156661140422645U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 11U)) + 11105271483234947905U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 348904609985341372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12924652822526858767U;
            aOrbiterD = RotL64((aOrbiterD * 2801892489296408735U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7461211697358520287U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16551553555297890558U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16432952324635746293U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11908056404140782995U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9147367258259948715U;
            aOrbiterE = RotL64((aOrbiterE * 10777628928376261667U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8876461054692728610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10546855952702525404U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10071104785895309677U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4748636139110443794U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 783046909529525098U;
            aOrbiterK = RotL64((aOrbiterK * 8969157702460927215U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16683965945838696665U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12385412690177109575U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10795062772707143187U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8210546822184469023U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13146493623236979963U;
            aOrbiterJ = RotL64((aOrbiterJ * 13199947810161148155U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 4U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterC, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterE, 41U));
            aWandererH = aWandererH + (((RotL64(aCross, 50U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29532U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 32290U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29007U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32073U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 43U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 13U)) + 5171470532667965920U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 37U)) + 750549462358682403U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 50U)) + 3325689257577120525U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 18031575461559790826U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 13874739537012288677U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 4250029868785016865U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 19U)) + 8211158803112611161U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1083939790236786027U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3446525462376962464U;
            aOrbiterH = RotL64((aOrbiterH * 13603702473750888213U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6973817815000417325U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15230876489676945543U;
            aOrbiterF = RotL64((aOrbiterF * 7737039082964537651U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9359727659738755880U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8775170107816327654U;
            aOrbiterB = RotL64((aOrbiterB * 6910680458261008653U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11958941755525038545U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16966819714283167348U;
            aOrbiterA = RotL64((aOrbiterA * 16363457661846050749U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14556087985619763243U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17915047508377045221U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6727635453185130109U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8578745677485367222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7002181668717618866U;
            aOrbiterK = RotL64((aOrbiterK * 12329703532414955235U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3569939503066735457U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2956247934282522184U;
            aOrbiterI = RotL64((aOrbiterI * 9946650822131152531U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterD, 37U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 44U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Badminton_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2241U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 989U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3320U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 2173U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 10U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 19U)) + 6733949564325516029U) + aPhaseFOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 7304098437143918796U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aScatter, 38U)) + RotL64(aCarry, 13U)) + 3923949518391777800U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 14243591003388927124U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 47U)) + 18329498724605410406U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13118172167747037249U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5272025143849174212U;
            aOrbiterG = RotL64((aOrbiterG * 9935990954321437743U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16075917179214318424U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15263590648674658399U;
            aOrbiterI = RotL64((aOrbiterI * 9918239923411740337U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13730046728289525921U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7703141464499623408U;
            aOrbiterE = RotL64((aOrbiterE * 5886009900621521987U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 1382279753822135359U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2973369221699098292U;
            aOrbiterB = RotL64((aOrbiterB * 7440242040663550631U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11578274119583013219U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3419411247737896674U;
            aOrbiterD = RotL64((aOrbiterD * 17814942652262802991U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 28U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 3U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 58U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 22U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13104U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 8295U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8505U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 8283U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 29U)) + (RotL64(aCross, 60U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 12849591986267890852U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 8232614804696815750U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 36U)) + 12141567259210877281U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 2928641981037885644U;
            aOrbiterK = (aWandererA + RotL64(aCross, 3U)) + 980733350554783938U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2683985177993350746U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14532148403815527355U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15985362037094864225U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7736296629433884203U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10428437770166310549U;
            aOrbiterK = RotL64((aOrbiterK * 326634742742373401U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18327174144859461029U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6810436935194432002U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2715987179577753597U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12606153309690753435U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17123256945895150555U;
            aOrbiterJ = RotL64((aOrbiterJ * 13469111258504672565U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9057777759026189541U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16478485918911194442U;
            aOrbiterD = RotL64((aOrbiterD * 11054247078884894131U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 37U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 37U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 48U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 20U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21618U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 22786U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18557U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19806U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 11274974230580265396U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 16658438747342741547U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 60U)) + 16612986966106053844U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 9329502236843231290U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 14088261356708344656U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13692608802007789581U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6824473946645682398U;
            aOrbiterJ = RotL64((aOrbiterJ * 13619437545775237601U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2072915876348570040U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7420507753044460759U;
            aOrbiterC = RotL64((aOrbiterC * 13239288539564571257U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4677557318688502593U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15081678577055628459U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16659305295251177155U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7026792817486507482U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14871665922943969918U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 694073180313083145U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6807734532159292872U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17882797335141303280U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15439872930381050291U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aIngress, 20U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterK, 60U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29883U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 24641U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30309U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26400U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 21U)) + 13296600294247799698U) + aPhaseFOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 5818503518080877515U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 6735784238734173597U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 56U)) + RotL64(aCarry, 5U)) + 7368398209488856201U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 13U)) + 961734029066455638U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 797011946660892011U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12841876018396622350U;
            aOrbiterB = RotL64((aOrbiterB * 14056540056414153277U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16213253970483895623U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15186950557113470375U;
            aOrbiterD = RotL64((aOrbiterD * 4647470430467908107U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5117930310827477341U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12265429373166094162U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1522823535151532249U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13920531346698601568U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14695405206998211456U;
            aOrbiterE = RotL64((aOrbiterE * 13950964363414164279U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7851960904825938443U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9501511171732550190U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5614164120361489613U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 26U);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 50U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Badminton_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 238U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 902U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5482U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 7790U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 37U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 15920462086654025436U) + aPhaseGOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 37U)) + 487844076858004017U) + aPhaseGOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 21U)) + 14502883786442630566U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 3787107318658233674U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 12548777544693755491U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4907309444075181683U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 18342396700266492072U;
            aOrbiterA = RotL64((aOrbiterA * 14842961036061482089U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13503051997624242670U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17845742460521374571U;
            aOrbiterI = RotL64((aOrbiterI * 1366356786138085155U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8640887211877858169U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5273913123709097537U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1661149444148461791U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17756844173695563883U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6713055830729302951U;
            aOrbiterG = RotL64((aOrbiterG * 2832836748513174311U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5106468334224035972U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10228769728713526172U;
            aOrbiterJ = RotL64((aOrbiterJ * 9760310686414358435U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 38U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 38U));
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + aPhaseGWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 38U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14150U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneC[((aIndex + 8722U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14105U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14699U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 12U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aScatter, 5U)) + 12206125048349568300U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 5843520589343188818U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 12195046124287121687U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 16769779119214020640U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 27U)) + 5257603646260695833U) + aPhaseGOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8523523946234886745U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7316024684200084096U;
            aOrbiterG = RotL64((aOrbiterG * 11620083021691341337U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11996978575084115207U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15491711479085513628U;
            aOrbiterF = RotL64((aOrbiterF * 15136690392026011819U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6036648530996821484U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 926323222234121863U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6639661141258803779U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2700323841295743492U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5852273765810284935U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16665696735016345215U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11697397483133538067U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17777142964957007194U;
            aOrbiterH = RotL64((aOrbiterH * 6338967222543284999U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterH, 10U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterB) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 26U) + aOrbiterG) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 21841U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneD[((aIndex + 20236U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20368U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 23957U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 50U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererB + RotL64(aScatter, 48U)) + RotL64(aCarry, 39U)) + 12136097566601676613U) + aPhaseGOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 35U)) + 7969431322248040056U;
            aOrbiterH = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 10530676021510553889U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 8740777303075445264U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 23U)) + 13249434169895564739U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15529577005925628472U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 344627093687331562U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3226087371456521323U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8824277416519988893U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5636276438449709875U;
            aOrbiterC = RotL64((aOrbiterC * 222817930773618893U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2079413361031851552U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7807998179168655561U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 961456853699784753U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13589392896232029112U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10733011474804473996U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 361749145931578805U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15934162328347805968U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7573511217796245232U;
            aOrbiterG = RotL64((aOrbiterG * 10694563909931636155U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterH, 22U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 30825U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 32674U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27710U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 32289U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 41U)) + 5568146815535263910U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 47U)) + 7736084960873834666U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 1336413621817562093U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 5218462026934984692U) + aPhaseGOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 29U)) + 7048890985969555935U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13415955213864702118U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5657023257021528548U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5200798937081797819U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14338310943137497116U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12305161641833950473U;
            aOrbiterG = RotL64((aOrbiterG * 11949964304435964395U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14514226578370459131U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12692904083266024340U;
            aOrbiterK = RotL64((aOrbiterK * 14800805065279908839U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11012959130001327964U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7106471380403489078U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 515626559384817223U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3718101961355280891U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13364192077222322664U;
            aOrbiterF = RotL64((aOrbiterF * 1411328915372590283U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 30U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 30U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 30U);
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

void TwistExpander_Badminton_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 1971U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 5661U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3050U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2558U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 20U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 50U)) + 16451272412693907816U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 10099485419723255462U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 17668900099534923192U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 5497093724143181753U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 41U)) + 10354044773550071706U) + aPhaseHOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12728258851198019099U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4144050505314242618U;
            aOrbiterF = RotL64((aOrbiterF * 13629477513971467419U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14133805325480076530U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 308863673210602899U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2672613556981540433U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11741180130160569753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12926863156769180448U;
            aOrbiterA = RotL64((aOrbiterA * 9726030996091054939U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 211920854786494259U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13234608842479411078U;
            aOrbiterE = RotL64((aOrbiterE * 2556747209733759467U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9164711974854618892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6667377062281954219U;
            aOrbiterD = RotL64((aOrbiterD * 2603737166987437649U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + aPhaseHWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 48U) + aOrbiterD) + RotL64(aOrbiterC, 22U));
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererB, 38U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 9231U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11077U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13780U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 8812U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 14U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 57U)) + 6733949564325516029U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 37U)) + 7304098437143918796U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 12U)) + RotL64(aCarry, 37U)) + 3923949518391777800U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 14243591003388927124U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 18329498724605410406U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13118172167747037249U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5272025143849174212U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9935990954321437743U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16075917179214318424U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 15263590648674658399U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9918239923411740337U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13730046728289525921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7703141464499623408U;
            aOrbiterE = RotL64((aOrbiterE * 5886009900621521987U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1382279753822135359U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2973369221699098292U;
            aOrbiterF = RotL64((aOrbiterF * 7440242040663550631U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11578274119583013219U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3419411247737896674U;
            aOrbiterH = RotL64((aOrbiterH * 17814942652262802991U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 52U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18810U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18339U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23746U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 23005U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 21U)) + 16424657151168221875U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 17150123681886380361U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 30U)) + RotL64(aCarry, 57U)) + 16041993588694572757U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 9871185846434828537U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 11U)) + 11227236398354430757U) + aPhaseHOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5399325217402192631U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9248828789282890454U;
            aOrbiterI = RotL64((aOrbiterI * 6733832755349139621U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9041370494203701062U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14944424084524970764U;
            aOrbiterC = RotL64((aOrbiterC * 10283363059424655079U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5481938174456671041U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14783648629543752715U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7260164783191886395U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12355573914530445723U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9863991559011968318U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8495251211794343179U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16149688605937250965U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 106041828692026825U;
            aOrbiterA = RotL64((aOrbiterA * 12199934305374582599U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 58U)) + aOrbiterB) + aPhaseHWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 38U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 29631U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31426U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31436U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 30461U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 22U)) + RotL64(aCarry, 53U)) + 4384716820085860551U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 9715780315942116888U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 15963520052789178632U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 13U)) + 14346700690686392938U) + aPhaseHOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 57U)) + 6005518012489966643U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2506732930310252119U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16782163084851775826U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1527050617428162663U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 823673076571076303U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1634084509064077736U;
            aOrbiterK = RotL64((aOrbiterK * 1128407326773234517U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1288134975466877686U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2998220403162908444U;
            aOrbiterI = RotL64((aOrbiterI * 4321412662318298283U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 220430672180734911U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10223923547068528867U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12577370238343872139U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11696469696177647608U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6545430420379636963U;
            aOrbiterH = RotL64((aOrbiterH * 8387163146257553773U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 6U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 46U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterA, 50U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
