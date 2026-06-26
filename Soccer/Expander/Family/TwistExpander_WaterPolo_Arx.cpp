#include "TwistExpander_WaterPolo_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_WaterPolo_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE27D1723A5673837ULL + 0xFF462FD09595A315ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA41D7B26A057358BULL + 0xC80568BA53F7256EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x89330A9969000A31ULL + 0xA2B558CA5A741A53ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8FF2D39A49294A89ULL + 0xAC7274AFF799D5CDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9C84F1714D46E611ULL + 0x96A371EF121D37C7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9426FB9B381D474DULL + 0xFAFED86504D0A089ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA71D2E6FECD723ADULL + 0xCD30A1FC783B0AF4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF093816A28B089ADULL + 0x9C19EB5658850FB2ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 24U) ^ RotL64(aNonceWordA, 43U)) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 504U)) & S_BLOCK1], 13U) ^ RotL64(mSnow[((aIndex + 196U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 46U) ^ RotL64(aNonceWordC, 27U)) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2691U)) & S_BLOCK1], 19U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 253U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aPrevious, 10U)) + 5171470532667965920U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 43U)) + 750549462358682403U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 35U)) + 3325689257577120525U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 37U)) + 18031575461559790826U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 29U)) + 13874739537012288677U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 3U)) + 4250029868785016865U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 51U)) + 8211158803112611161U) + RotL64(aNonceWordE, 58U);
            aOrbiterB = ((aWandererE + RotL64(aIngress, 6U)) + RotL64(aCarry, 23U)) + 1083939790236786027U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 53U)) + 3446525462376962464U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 6973817815000417325U) + RotL64(aNonceWordG, 43U);
            aOrbiterA = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 15230876489676945543U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9359727659738755880U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8775170107816327654U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6910680458261008653U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11958941755525038545U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16966819714283167348U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16363457661846050749U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14556087985619763243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17915047508377045221U;
            aOrbiterG = RotL64((aOrbiterG * 6727635453185130109U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8578745677485367222U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7002181668717618866U;
            aOrbiterH = RotL64((aOrbiterH * 12329703532414955235U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3569939503066735457U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2956247934282522184U;
            aOrbiterK = RotL64((aOrbiterK * 9946650822131152531U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4285180013402474041U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 5976239869535619811U) ^ RotL64(aNonceWordH, 17U);
            aOrbiterE = RotL64((aOrbiterE * 3458095419039067465U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2424524955161695463U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6849595426583763537U;
            aOrbiterA = RotL64((aOrbiterA * 12727902040238318101U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11414890686374886716U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5668287266836153445U;
            aOrbiterJ = RotL64((aOrbiterJ * 8011885266143066285U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9976985606260445887U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9223940029500676834U;
            aOrbiterC = RotL64((aOrbiterC * 8508023992488499955U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4480967907876921958U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5132766654502526597U;
            aOrbiterB = RotL64((aOrbiterB * 321625389942019245U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12921555132452983464U) + RotL64(aNonceWordB, 11U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5171470532667965920U;
            aOrbiterI = RotL64((aOrbiterI * 9710487797420618879U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterB, 58U)) + RotL64(aNonceWordC, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 47U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 20U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 37U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 22U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + RotL64(aNonceWordD, 49U)) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 38U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 30U) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 10070U)) & S_BLOCK1], 13U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 6133U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordD, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6043U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6920U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aCross, 57U)) + 10336802574069791273U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 13U)) + 169025388197058936U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 6541354188379168846U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 5U)) + 16223920526599306104U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 54U)) + 12756613707692514808U) + RotL64(aNonceWordH, 11U);
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 5082475548176484035U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 11U)) + 4907435526952698526U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 35U)) + 14236627073831834337U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 37U)) + 11502511046130497584U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 3679044835550219497U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 46U)) + 11254838916686736746U) + RotL64(aNonceWordE, 59U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10582608424233200966U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10449735026385340313U;
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4628253464169957835U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17664454668473204465U;
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3798386391743884889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1379331161819246587U;
            aOrbiterC = RotL64((aOrbiterC * 13086160171095077295U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9816600392407327227U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16781971616348376878U;
            aOrbiterF = RotL64((aOrbiterF * 12503867584828289879U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4807797577690520554U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2492057261148595922U;
            aOrbiterA = RotL64((aOrbiterA * 9453302540675483005U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 7909676419643119585U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 256053568910383007U;
            aOrbiterD = RotL64((aOrbiterD * 11965085163352053161U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16179914439220412472U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3968867762761955845U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7473632378251893139U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7474832923901283742U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4736994731050735779U) ^ RotL64(aNonceWordG, 24U);
            aOrbiterJ = RotL64((aOrbiterJ * 9839654409121414047U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 596484364660389193U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13822222274464306169U;
            aOrbiterE = RotL64((aOrbiterE * 1723502278319885511U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16307920280681985443U) + RotL64(aNonceWordF, 19U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3505106171801702915U;
            aOrbiterH = RotL64((aOrbiterH * 8479675421552861243U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4987142580981135150U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10336802574069791273U;
            aOrbiterG = RotL64((aOrbiterG * 2670706512498539705U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + RotL64(aNonceWordA, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 40U) + RotL64(aOrbiterE, 54U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 29U)) + aOrbiterG) + RotL64(aCarry, 51U)) + RotL64(aNonceWordB, 35U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 48U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterC, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererB, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordH, 4U)) ^ RotL64(aNonceWordF, 29U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 12029U)) & S_BLOCK1], 57U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 14568U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordA, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14011U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11436U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 35U)) + (RotL64(aIngress, 47U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 37U)) + 7896237440058555694U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 60U)) + 11870529476037558635U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 9158983227801569448U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 51U)) + 4710172270996950329U) + RotL64(aNonceWordC, 3U);
            aOrbiterF = (aWandererC + RotL64(aIngress, 43U)) + 14634482800356647630U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 5U)) + 8822207952170610891U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 13755891414028982553U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 4555293067488040719U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 30U)) + 2816805148093762081U) + RotL64(aNonceWordG, 23U);
            aOrbiterG = (aWandererG + RotL64(aScatter, 13U)) + 2122631477965135190U;
            aOrbiterC = (aWandererF + RotL64(aCross, 47U)) + 4592922416380416071U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7102471666524164715U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17274623547879474204U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5443572270546181789U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 938587316977094680U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18258015823797023523U;
            aOrbiterE = RotL64((aOrbiterE * 6068819567674605919U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5809987756043471595U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5083075160112581620U;
            aOrbiterB = RotL64((aOrbiterB * 3313957222154937503U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5960021727750946496U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5967477320950630150U;
            aOrbiterF = RotL64((aOrbiterF * 330964768256424655U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6578428711689296132U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5601728218197771276U;
            aOrbiterK = RotL64((aOrbiterK * 9552559022315971847U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7923809409017855241U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16479366540906497019U;
            aOrbiterG = RotL64((aOrbiterG * 7118578387798460919U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17000467091738009736U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6801634573655508028U;
            aOrbiterD = RotL64((aOrbiterD * 10584635770060137089U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 123668445682719574U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14462802805503986316U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12398236364304875941U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2433338393261685871U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13869012262404991729U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12443261517483942937U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4832421585086516998U) + RotL64(aNonceWordF, 36U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11284414949564414958U) ^ RotL64(aNonceWordA, 27U);
            aOrbiterH = RotL64((aOrbiterH * 1586650935440790991U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17872556812561387030U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7896237440058555694U;
            aOrbiterC = RotL64((aOrbiterC * 16784165278693056013U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterG, 5U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + RotL64(aNonceWordB, 39U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 48U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + RotL64(aNonceWordE, 9U));
            aWandererF = aWandererF + ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterK, 58U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 24U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 18538U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 16773U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17140U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 18576U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aCross, 39U)) + 14823268998003220191U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 46U)) + 15295237288788213847U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 13U)) + 16434853402001133899U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 7555911304407871631U) + RotL64(aNonceWordH, 61U);
            aOrbiterJ = (aWandererE + RotL64(aIngress, 5U)) + 14977248264994834620U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 19U)) + 9707764144919392380U;
            aOrbiterF = (aWandererG + RotL64(aCross, 35U)) + 1277304385464681529U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 58U)) + 3089786220465849395U;
            aOrbiterI = ((((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 3700503853358695085U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordE, 3U);
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 37U)) + 3240054112993517371U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 16897532076915366859U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 18167359289798364307U) + RotL64(aNonceWordF, 57U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8870819278575769863U;
            aOrbiterC = RotL64((aOrbiterC * 9334066154398059075U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15363069206212330251U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14858164441499725158U;
            aOrbiterJ = RotL64((aOrbiterJ * 14931933411393847915U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5357144808788707522U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2910681277417754860U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13170868582159347059U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9824408699018165151U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 368370224788793300U;
            aOrbiterF = RotL64((aOrbiterF * 14358982366258729959U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7095398304588825115U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11418879758164313554U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5983520332639771791U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2171599720681913272U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17593730219647495033U;
            aOrbiterI = RotL64((aOrbiterI * 12926053208918563087U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17755947635188715523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14565740605227022106U;
            aOrbiterA = RotL64((aOrbiterA * 15866418354612945335U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14538017880915584414U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6174566474851449123U;
            aOrbiterB = RotL64((aOrbiterB * 179569008593475683U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3806438394748643441U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13737114463856719285U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13439346068497710151U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3698379331577470045U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1097081284062708554U) ^ RotL64(aNonceWordD, 37U);
            aOrbiterK = RotL64((aOrbiterK * 3498627643013255777U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 215117138867597766U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14823268998003220191U;
            aOrbiterH = RotL64((aOrbiterH * 12131828437975771377U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 24U) + aOrbiterB) + RotL64(aOrbiterK, 53U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 10U)) + aOrbiterE) + RotL64(aNonceWordC, 53U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordA, 56U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterE, 42U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererA, 14U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordE, 19U)) ^ RotL64(aNonceWordA, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 27262U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23250U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordC, 41U)) ^ RotL64(aNonceWordH, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22559U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24795U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 380024772508948442U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 37U)) + 7649029098162567210U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 11U)) + 5329304598870421851U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 12306118665045151326U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 13U)) + 960751560457324256U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 44U)) + 3244070254386191876U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 3U)) + 15733408571609521746U) + RotL64(aNonceWordD, 57U);
            aOrbiterB = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 17623448932647018544U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 39U)) + 8787759896149035829U) + RotL64(aNonceWordF, 53U);
            aOrbiterK = (aWandererF + RotL64(aCross, 58U)) + 14741681792348288162U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 51U)) + 8801731213568307302U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9872248187499779222U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15407371518644528235U;
            aOrbiterG = RotL64((aOrbiterG * 1245102406469471673U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4242060317152943062U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9942784962409917541U;
            aOrbiterI = RotL64((aOrbiterI * 888649755587764533U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7296348796484458631U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15061417216070157797U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10349554676953256231U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3233185810644297433U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9241229457641024287U;
            aOrbiterK = RotL64((aOrbiterK * 2728237515724597517U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8464051359381554575U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3307872165699029375U;
            aOrbiterF = RotL64((aOrbiterF * 4859663401033023433U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5482617843966711997U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4442149210462943872U;
            aOrbiterD = RotL64((aOrbiterD * 8979352218576515647U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10591636597580147381U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14925122230279312217U;
            aOrbiterH = RotL64((aOrbiterH * 15038171961638724013U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9772367878232735350U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15800661165607190092U;
            aOrbiterE = RotL64((aOrbiterE * 10493976952980533589U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1571665862499272194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3162847040693387901U;
            aOrbiterJ = RotL64((aOrbiterJ * 2747235335326991399U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4868791925868749848U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 13134549226315884613U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) ^ RotL64(aNonceWordE, 20U);
            aOrbiterC = RotL64((aOrbiterC * 3551955270718495869U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7830447320021657240U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 380024772508948442U) ^ RotL64(aNonceWordB, 49U);
            aOrbiterA = RotL64((aOrbiterA * 5143324968958616357U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 20U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 20U) + RotL64(aOrbiterB, 58U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterI, 56U)) + RotL64(aNonceWordC, 35U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 39U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterC) + RotL64(aNonceWordG, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordC, 37U)) ^ RotL64(aNonceWordE, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 32672U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31060U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 6U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordF, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27359U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 32611U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 23U)) + 4259993311776766595U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 35U)) + 2857813330021126753U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 57U)) + 1345396841329442896U) + RotL64(aNonceWordG, 7U);
            aOrbiterC = (aWandererC + RotL64(aIngress, 46U)) + 320992148982301024U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 21U)) + 5619109532065293074U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 13U)) + 10380157329426706345U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 11U)) + 12449831150625409695U) + RotL64(aNonceWordB, 5U);
            aOrbiterA = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 7847096607042268396U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 11707184096803214678U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 50U)) + RotL64(aCarry, 47U)) + 9893643746186827088U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 5U)) + 333687403830908774U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13837360705077441580U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4367119682175710689U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10295744669174603401U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1193493435041306784U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15062951612027370606U) ^ RotL64(aNonceWordE, 45U);
            aOrbiterH = RotL64((aOrbiterH * 2509383510565136549U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16000173839235429105U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15294482444605409961U;
            aOrbiterD = RotL64((aOrbiterD * 1031800997944302665U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5720749055549773527U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17248674962996093668U;
            aOrbiterI = RotL64((aOrbiterI * 15730637462755795591U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16956840483882091059U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 9637715107943515594U) ^ RotL64(aNonceWordC, 44U);
            aOrbiterA = RotL64((aOrbiterA * 8878362378343603463U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7147495779349862274U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7508890985889484275U;
            aOrbiterF = RotL64((aOrbiterF * 17728368447504622035U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4407738164617959366U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17027017782352660454U;
            aOrbiterJ = RotL64((aOrbiterJ * 417183060881259295U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3174658601748235285U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9779053567370714831U;
            aOrbiterK = RotL64((aOrbiterK * 6383245776181968033U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16256981360027888091U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12778335633397105924U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10821225965811763659U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13985909343937844583U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14307218309393008729U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12053366452617039877U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15549857305890093491U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4259993311776766595U;
            aOrbiterC = RotL64((aOrbiterC * 13703695714360435719U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 12U)) + RotL64(aNonceWordD, 61U));
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterC, 5U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + RotL64(aNonceWordA, 27U));
            aWandererK = aWandererK + (((RotL64(aIngress, 20U) + aOrbiterE) + RotL64(aOrbiterF, 10U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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

void TwistExpander_WaterPolo_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC48292A1FDFB4375ULL + 0xEC4D7FF0F8267F69ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBBCECA46B9538ACFULL + 0xE09734BCC3C0AE11ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB7D40BC2CA4EE28FULL + 0xC6609DC85B211A80ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD12208CB80440573ULL + 0xDAE3183BCD686E9FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBAE2689924CF8E85ULL + 0xFD2D0495B15525FAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB8A9618A7DCBABB7ULL + 0xEC5531CA8220ED20ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCAA1258671CA953FULL + 0xB9DDD34509E239B5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC042BF2119697E8FULL + 0xAA983AF51CE00E3AULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 6U) ^ RotL64(aNonceWordA, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1056U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4194U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 28U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1373U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 2498U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 21U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aPrevious, 53U)) + 5088525177670191619U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 35U)) + 9966456257813932112U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 39U)) + 7707646574027146307U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 12U)) + 75480203757681173U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 47U)) + 384659134071835163U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 14U);
            aOrbiterJ = (aWandererG + RotL64(aIngress, 43U)) + 3158769775373307778U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 17360830943513941272U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 6U)) + RotL64(aCarry, 51U)) + 5317278822721604586U) + RotL64(aNonceWordC, 47U);
            aOrbiterB = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 1371427105215954781U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3162710551223553423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5332921933853550756U;
            aOrbiterF = RotL64((aOrbiterF * 11709546145149357887U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10572462410297815854U) + RotL64(aNonceWordD, 15U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10234389605554817892U;
            aOrbiterJ = RotL64((aOrbiterJ * 2130374833440291193U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13421365517991380605U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10186643614984034083U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8554471709467808453U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4742438973260817120U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6081590345899008846U;
            aOrbiterB = RotL64((aOrbiterB * 7069396301823124931U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15360092808493795340U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12186413069553132646U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3815981440611914267U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16756221656224451552U) + RotL64(aNonceWordF, 39U);
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12232880965861373143U;
            aOrbiterG = RotL64((aOrbiterG * 14196910735715726471U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10090954323470840557U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15615770271463853537U;
            aOrbiterK = RotL64((aOrbiterK * 13544181592829027283U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 556029032505658411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13311879111583579039U;
            aOrbiterA = RotL64((aOrbiterA * 3924744868168749003U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8646360871497847336U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2064833941982069154U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10016546852137913163U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 10U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterE, 56U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aNonceWordH, 11U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + RotL64(aNonceWordG, 29U));
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterG, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 20U) ^ RotL64(aNonceWordB, 57U)) ^ RotL64(aNonceWordH, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11391U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11434U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordF, 13U)) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14194U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 9101U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 47U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 27U)) + 5697928251815176134U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 56U)) + 337587740689259575U) + RotL64(aNonceWordB, 25U);
            aOrbiterG = (aWandererG + RotL64(aIngress, 21U)) + 4927686903263973950U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 43U)) + 3742409032569801033U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 39U)) + 1608092659172197650U) + RotL64(aNonceWordF, 6U);
            aOrbiterK = (((aWandererF + RotL64(aIngress, 52U)) + RotL64(aCarry, 53U)) + 15848744267145717509U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 35U)) + 15300174177963339253U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 14162868453323648628U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 12020167069983729869U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16259538291658723956U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4731296903548893627U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3722184575520553132U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5663609293306386784U;
            aOrbiterC = RotL64((aOrbiterC * 14364218128780764749U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15265344442454471986U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3050323350098829515U;
            aOrbiterF = RotL64((aOrbiterF * 5890624677162388135U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1093356813820599238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15167726103772238440U;
            aOrbiterJ = RotL64((aOrbiterJ * 5719466863561311069U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15170797965325981472U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17826286701992981628U) ^ RotL64(aNonceWordD, 41U);
            aOrbiterH = RotL64((aOrbiterH * 11186808881726573677U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14710892030473425181U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 397194787697553904U;
            aOrbiterB = RotL64((aOrbiterB * 14368930300818752833U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1273724124862533034U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13018397560392545616U;
            aOrbiterI = RotL64((aOrbiterI * 4644812473262395329U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9638716186445643730U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7255587739807843785U;
            aOrbiterK = RotL64((aOrbiterK * 6055682981584011189U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 9272350563697399628U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordA, 37U);
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1040729335295009339U;
            aOrbiterA = RotL64((aOrbiterA * 17825687660830291443U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 44U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterI, 5U)) + aOrbiterH) + RotL64(aNonceWordH, 59U));
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterG, 58U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterF, 53U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 4U) + RotL64(aOrbiterB, 36U)) + aOrbiterC) + RotL64(aNonceWordG, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordF, 4U)) ^ RotL64(aNonceWordB, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19358U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 23762U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17317U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 18773U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 24U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 18U)) + RotL64(aCarry, 19U)) + 16124889768301047791U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 27U)) + 11912338587186717280U;
            aOrbiterB = (aWandererG + RotL64(aCross, 5U)) + 8594012868813114354U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 23U)) + 18281043566156682815U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 53U)) + 16853106130200942302U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 42U)) + RotL64(aCarry, 57U)) + 2611212958619673086U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 57U)) + 18039472325066855180U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 14495785571345122046U) + RotL64(aNonceWordF, 31U);
            aOrbiterA = (((aWandererK + RotL64(aScatter, 13U)) + 4556063793412832418U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14896419970271244358U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 880028529183500036U;
            aOrbiterB = RotL64((aOrbiterB * 14228281807461251361U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2379557167489415783U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11854373946064529806U;
            aOrbiterE = RotL64((aOrbiterE * 150755294320438887U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1487252775956449964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12777924204511625545U;
            aOrbiterC = RotL64((aOrbiterC * 1366019527386994789U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15998631485222477969U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8864212892296191613U;
            aOrbiterF = RotL64((aOrbiterF * 579242788050369815U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17069347835763226743U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 7443008171694679791U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) ^ RotL64(aNonceWordG, 12U);
            aOrbiterI = RotL64((aOrbiterI * 748894368884566607U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17334256152350782002U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8986626119086556393U;
            aOrbiterD = RotL64((aOrbiterD * 2258172145924120235U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8528180968228358674U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12702290928064582589U;
            aOrbiterK = RotL64((aOrbiterK * 15673603224146737631U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7742438100860023610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3729687240959702198U) ^ RotL64(aNonceWordE, 27U);
            aOrbiterG = RotL64((aOrbiterG * 3756794766163746783U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 426129097367382096U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16782175452274911213U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1041477289638333659U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 34U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 6U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterA, 41U));
            aWandererK = aWandererK + ((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterE, 37U));
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 46U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + RotL64(aNonceWordA, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + RotL64(aNonceWordH, 53U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererE, 54U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordF, 14U)) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29951U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25328U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 12U) ^ RotL64(aNonceWordH, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29951U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 27044U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 29U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererG + RotL64(aPrevious, 12U)) + 17019646486641172469U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 12276141179299971572U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 3617241694029841555U) + RotL64(aNonceWordF, 3U);
            aOrbiterJ = (((aWandererC + RotL64(aCross, 29U)) + 6967963401259371737U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordE, 51U);
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 35U)) + 6340709284279891017U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 41U)) + 456065368903896482U;
            aOrbiterC = (aWandererA + RotL64(aCross, 52U)) + 17686765719908116203U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 23U)) + 1322045955429785736U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 5163772703302372887U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13268431135020363252U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6538789950366849332U;
            aOrbiterK = RotL64((aOrbiterK * 5352960308459065837U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10390344544314544893U) + RotL64(aNonceWordB, 41U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5087084271300584267U;
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13423071121590981727U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 18324443012024134729U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15814349432207734533U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4129091815978464507U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17024797553831962245U;
            aOrbiterD = RotL64((aOrbiterD * 3137753479364378175U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6501545108779991661U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11930037791867597447U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4904739567549702851U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4667298703308315851U) + RotL64(aNonceWordD, 21U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6315980380900062127U;
            aOrbiterI = RotL64((aOrbiterI * 12080555704907924637U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12732382340390769888U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7792095326183864547U;
            aOrbiterE = RotL64((aOrbiterE * 12645556660611824631U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17428384983571405782U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3193205313177048443U;
            aOrbiterH = RotL64((aOrbiterH * 14488006565106259731U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2813743367131107264U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2742138679703780981U;
            aOrbiterB = RotL64((aOrbiterB * 18356569025783532225U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 26U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 34U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + RotL64(aNonceWordG, 9U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterB, 10U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + RotL64(aNonceWordA, 34U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterB, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD1F1FB800163F8FFULL + 0xC20E00B65DF6FA9BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFA1A311D7309575BULL + 0xCA101C5290B5C534ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x811534DC855FACF1ULL + 0xEDEEEE5AE3C77587ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE0D6776B4C3B31EFULL + 0xBC8B2838F35CCF0DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD67150E8212A7CF5ULL + 0xD7128FB027953B6FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x965983FEA463D765ULL + 0xC279E1454EB2CBD7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBCA45217F3A190DFULL + 0xB613686DB6679168ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA4FDD37DA1941F61ULL + 0xEE059467E27015A9ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordD, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1896U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((aIndex + 1108U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordA, 56U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1773U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 267U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 5576732410244514238U;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 53U)) + 2833808925935929629U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordE, 30U);
            aOrbiterF = ((aWandererG + RotL64(aCross, 43U)) + 3670188682914544792U) + RotL64(aNonceWordF, 25U);
            aOrbiterE = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 15759072378887814995U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 14U)) + RotL64(aCarry, 27U)) + 13934007231137439994U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11022225696007690512U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16989177104453635790U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14156758251105809453U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9256930045263527091U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17788596104417068290U;
            aOrbiterH = RotL64((aOrbiterH * 675554110563253305U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17044369456673337625U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 1310908395523250343U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) ^ RotL64(aNonceWordB, 57U);
            aOrbiterE = RotL64((aOrbiterE * 16305084373037705921U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12067065689034065422U) + RotL64(aNonceWordA, 47U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15130844248737512262U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9409499577465934107U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14532689204495587494U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8198147292120244178U;
            aOrbiterG = RotL64((aOrbiterG * 1418356389507740991U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + RotL64(aCarry, 27U)) + RotL64(aNonceWordG, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterG, 23U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + RotL64(aCarry, 41U)) + RotL64(aNonceWordD, 37U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 10U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 6U) ^ RotL64(aNonceWordD, 27U)) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12927U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8844U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordB, 21U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12664U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14831U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 10U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 2330952702412094686U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 6U)) + 7820188225935060799U) + RotL64(aNonceWordH, 27U);
            aOrbiterI = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 9347644591709839145U;
            aOrbiterF = ((((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 2288624878446846870U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordE, 11U);
            aOrbiterJ = (aWandererH + RotL64(aCross, 43U)) + 9358977729492824128U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1858511275052455039U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13715478509322292552U;
            aOrbiterI = RotL64((aOrbiterI * 15552121744869003235U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16413396625604260455U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 17714322215518432705U) ^ RotL64(aNonceWordB, 31U);
            aOrbiterJ = RotL64((aOrbiterJ * 1904184102419934333U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16188315436202861122U) + RotL64(aNonceWordA, 7U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5564445841368207813U;
            aOrbiterH = RotL64((aOrbiterH * 14125834616162835983U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13717068949900594673U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14143659432287313765U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5729546141908425670U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4297827922736712074U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13631630436759768885U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 18U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 11U)) + RotL64(aNonceWordC, 49U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 34U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + RotL64(aNonceWordD, 34U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordB, 54U)) ^ RotL64(aNonceWordA, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19925U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 21633U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordH, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17033U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21315U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 22U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aPrevious, 41U)) + 966899917801652720U;
            aOrbiterC = ((((aWandererK + RotL64(aIngress, 14U)) + RotL64(aCarry, 27U)) + 10996327672320748649U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordG, 43U);
            aOrbiterJ = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 4188171566846621107U) + RotL64(aNonceWordC, 4U);
            aOrbiterG = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 5886209243097387959U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 57U)) + 14940428957136728111U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 179187285531914832U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 6685351948936817752U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15533370414711696803U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1894506461704029700U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4182760368636977082U;
            aOrbiterC = RotL64((aOrbiterC * 972988091869133921U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12523318028514940790U) + RotL64(aNonceWordA, 59U);
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5059306166973366892U;
            aOrbiterB = RotL64((aOrbiterB * 2857409765717296483U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5890872367917643851U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17747338389865221534U;
            aOrbiterG = RotL64((aOrbiterG * 5306740664798049267U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13906227834259884100U) + RotL64(aNonceWordE, 29U);
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7152105382899756368U;
            aOrbiterK = RotL64((aOrbiterK * 6772157117358310485U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 40U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 52U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordH, 41U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 19U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 58U)) + RotL64(aNonceWordD, 17U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordC, 39U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30389U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 27112U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordG, 39U)) ^ RotL64(aNonceWordA, 48U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27453U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26800U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 36U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 43U)) + 13278949403988203974U) + RotL64(aNonceWordD, 45U);
            aOrbiterB = ((aWandererK + RotL64(aCross, 30U)) + RotL64(aCarry, 43U)) + 9213599924054673756U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 5U)) + 1255746482932381798U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 11575321997144516122U) + RotL64(aNonceWordE, 17U);
            aOrbiterA = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 15881587525529432437U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9846195809864862707U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12319815691858217670U;
            aOrbiterG = RotL64((aOrbiterG * 14271546305640811091U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16322617427294439587U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16332130810525887437U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7588076439690559343U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4920951156015336794U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16767126455124552329U;
            aOrbiterI = RotL64((aOrbiterI * 4440352337076842603U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12553595911087945223U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 1437522202135436142U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) ^ RotL64(aNonceWordA, 10U);
            aOrbiterB = RotL64((aOrbiterB * 2001992794165550905U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12313100454852227143U) + RotL64(aNonceWordB, 23U);
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2761983020631055729U;
            aOrbiterA = RotL64((aOrbiterA * 3874839760378039509U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 40U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aNonceWordF, 47U));
            aWandererG = aWandererG + (((((RotL64(aCross, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + RotL64(aCarry, 43U)) + RotL64(aNonceWordG, 37U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterI, 38U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterB, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_WaterPolo_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9D81F1710A5BA1B3ULL + 0x911AE9E8F60AB067ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCCB9BCB950573789ULL + 0xD9FBE9DCA4C4EC38ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC12F51BB7E29C417ULL + 0x95EB469305EDC5B8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8686721608641DC1ULL + 0xDD1AEA5E0F6ADFCFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF4D6B99ED1488F21ULL + 0xE5C03730866B02E8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8E756721891F2B03ULL + 0xDF2E417AAA63BE59ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA23A868184BB26BDULL + 0x8126E8DFEBE81547ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8B5ADE52EB7F357DULL + 0xA5318AE7E72D8E32ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4493U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 7705U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 58U) ^ RotL64(aNonceWordH, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6103U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3992U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 4476099022490972343U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aCross, 46U)) + RotL64(aCarry, 43U)) + 16836423700375760429U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 5U)) + 8850577488928703557U) + RotL64(aNonceWordH, 21U);
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 7091631824560042743U) + RotL64(aNonceWordF, 27U);
            aOrbiterE = (aWandererF + RotL64(aCross, 57U)) + 12560498899956759494U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 19U)) + 7797973377112012161U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 39U)) + 6173820673874805794U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10805025132310245348U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7139216143268029968U) ^ RotL64(aNonceWordE, 57U);
            aOrbiterK = RotL64((aOrbiterK * 8349754682635765573U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8241544862261635722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4735527016563596150U;
            aOrbiterE = RotL64((aOrbiterE * 6621354217673598381U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5166171126690294033U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 11117641762075368393U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordA, 6U);
            aOrbiterJ = RotL64((aOrbiterJ * 4980156869201219393U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6312932356458415421U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1304139291184508668U;
            aOrbiterD = RotL64((aOrbiterD * 90744653170922319U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10085025354842771067U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16745854428789531080U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1945983905747274355U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2497187958708890337U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16069701876646548995U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16606039730973709495U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17242004368025978091U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12334315722243232121U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16528598396696346719U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 34U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 47U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 60U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aNonceWordD, 59U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 41U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordG, 15U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordC, 24U)) ^ RotL64(aNonceWordH, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13084U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13864U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordG, 29U)) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9951U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 10384U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 12206125048349568300U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 5U)) + 5843520589343188818U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordC, 36U);
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 12195046124287121687U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 16769779119214020640U;
            aOrbiterB = (aWandererH + RotL64(aCross, 28U)) + 5257603646260695833U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 43U)) + 8523523946234886745U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 21U)) + 7316024684200084096U) + RotL64(aNonceWordA, 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11996978575084115207U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15491711479085513628U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15136690392026011819U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6036648530996821484U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 926323222234121863U;
            aOrbiterH = RotL64((aOrbiterH * 6639661141258803779U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2700323841295743492U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5852273765810284935U;
            aOrbiterF = RotL64((aOrbiterF * 16665696735016345215U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 11697397483133538067U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17777142964957007194U;
            aOrbiterJ = RotL64((aOrbiterJ * 6338967222543284999U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10892176201151170298U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11759700374509499684U;
            aOrbiterB = RotL64((aOrbiterB * 14247697264744736081U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11343756773329590643U) + RotL64(aNonceWordH, 29U);
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15785048929757652350U;
            aOrbiterK = RotL64((aOrbiterK * 17208103574389502597U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7508839228498497238U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 13088508510402094665U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) ^ RotL64(aNonceWordB, 55U);
            aOrbiterC = RotL64((aOrbiterC * 15730279447009669103U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + RotL64(aNonceWordD, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 51U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + RotL64(aNonceWordG, 21U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterB, 20U)) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 54U) ^ RotL64(aNonceWordH, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16713U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20139U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22400U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((aIndex + 23000U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 10881271196314989997U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 41U)) + 6406461249988567558U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 17255067918280095959U) + RotL64(aNonceWordD, 40U);
            aOrbiterE = ((aWandererD + RotL64(aCross, 34U)) + RotL64(aCarry, 13U)) + 16690850682497718411U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 47U)) + 5576201059361086866U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 13U)) + 11991259685693687554U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 27U)) + 14652535244217836909U) + RotL64(aNonceWordH, 31U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1701789037170782122U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 953429054903473833U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13482379459700651427U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12064513610469714211U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7993881398822002424U;
            aOrbiterA = RotL64((aOrbiterA * 11572884842788918377U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14421313768013320050U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11112386845630998889U;
            aOrbiterC = RotL64((aOrbiterC * 11771526352030371669U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17069630896535699015U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3308240081138623373U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10449509484417835159U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17615529807112933619U) + RotL64(aNonceWordF, 19U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11782807146851563541U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12992075832343669221U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14401645829607611983U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6736397344219993532U) ^ RotL64(aNonceWordC, 7U);
            aOrbiterF = RotL64((aOrbiterF * 1667287547938175641U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6446974060524700550U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7840991992443308254U;
            aOrbiterI = RotL64((aOrbiterI * 6891023544882740107U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + RotL64(aNonceWordG, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + RotL64(aNonceWordE, 15U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 23U) ^ RotL64(aNonceWordG, 50U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29066U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 27911U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 52U) ^ RotL64(aNonceWordA, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32063U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25162U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCross, 21U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 35U)) + 12029393034357490020U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 47U)) + 4526754731580694987U) + RotL64(aNonceWordF, 47U);
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 28U)) + RotL64(aCarry, 5U)) + 17060419646421271853U) + RotL64(aNonceWordH, 43U);
            aOrbiterE = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 4128488893837059683U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 57U)) + 12706894827547160110U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 11U)) + 12506324593645825056U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 21U)) + 12581344490649250025U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14357032418199130132U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15341977701796331249U;
            aOrbiterH = RotL64((aOrbiterH * 6332369248718076031U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 7086602307544733241U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordG, 46U);
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12398300065276832486U;
            aOrbiterK = RotL64((aOrbiterK * 18157408831225635333U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2499745046076601988U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7249361592814001829U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14597139848072319685U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3254456186337366437U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3472973415969046680U;
            aOrbiterI = RotL64((aOrbiterI * 14583566953969168353U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7905718972111691591U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15941413652144021522U;
            aOrbiterA = RotL64((aOrbiterA * 3473779492962783565U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10583964125960308762U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13659925272340853715U) ^ RotL64(aNonceWordD, 29U);
            aOrbiterE = RotL64((aOrbiterE * 16708294803316630743U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9487054537489454887U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13287757570441887517U;
            aOrbiterG = RotL64((aOrbiterG * 17351439045329892107U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 20U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterH) + RotL64(aNonceWordB, 37U));
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aNonceWordC, 35U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 4U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x80B0EF81F303676DULL + 0xCAD839C770753665ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE1FA6C1CDA22EB5DULL + 0xE61C97BF71E01892ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAD1D5DFECD8E99EFULL + 0xB49517F74787FA31ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD953E0291B9E5D23ULL + 0x855A6F36D1178BE1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x87A6B4120A08899DULL + 0x990E6A3825699105ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x959B2958CC8BE34FULL + 0xB15B344CC97EB7DAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBEE3919B6B45AF23ULL + 0xA23855E8C7697DA7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBCA9DDEE4C7239BDULL + 0xBC9745D24784AA05ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordC, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1464U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 188U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordG, 4U)) ^ RotL64(aNonceWordD, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 847U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 490U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 52U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 10881271196314989997U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 13U)) + 6406461249988567558U) + RotL64(aNonceWordF, 51U);
            aOrbiterC = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 17255067918280095959U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 29U)) + 16690850682497718411U;
            aOrbiterH = (aWandererD + RotL64(aCross, 41U)) + 5576201059361086866U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 19U)) + 11991259685693687554U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordG, 43U);
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 14652535244217836909U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1701789037170782122U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 953429054903473833U;
            aOrbiterC = RotL64((aOrbiterC * 13482379459700651427U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12064513610469714211U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7993881398822002424U;
            aOrbiterH = RotL64((aOrbiterH * 11572884842788918377U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14421313768013320050U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11112386845630998889U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11771526352030371669U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17069630896535699015U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3308240081138623373U;
            aOrbiterK = RotL64((aOrbiterK * 10449509484417835159U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17615529807112933619U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 11782807146851563541U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordC, 21U);
            aOrbiterD = RotL64((aOrbiterD * 12992075832343669221U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14401645829607611983U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6736397344219993532U;
            aOrbiterF = RotL64((aOrbiterF * 1667287547938175641U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6446974060524700550U) + RotL64(aNonceWordB, 7U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7840991992443308254U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6891023544882740107U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 42U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + RotL64(aNonceWordE, 45U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 58U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordA, 16U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 58U) ^ RotL64(aNonceWordH, 41U)) ^ RotL64(aNonceWordF, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16152U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 12388U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 30U) ^ RotL64(aNonceWordA, 41U)) ^ RotL64(aNonceWordG, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9519U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15199U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 4U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aCross, 28U)) + 16189787374324972735U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 11U)) + 17563763730956242224U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 10572803498593789385U) + RotL64(aNonceWordD, 10U);
            aOrbiterK = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 7713105232072974166U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 35U)) + 10760839534772718139U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 13397069448391230253U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 47U)) + 4569255679998375682U) + RotL64(aNonceWordE, 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9888769350817876949U) + RotL64(aNonceWordC, 49U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11351796060878856300U;
            aOrbiterJ = RotL64((aOrbiterJ * 13356749147334008399U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18153775071965707204U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1282846411145853435U;
            aOrbiterF = RotL64((aOrbiterF * 12294455920906257823U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16457743979262460660U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 173493260775251032U;
            aOrbiterK = RotL64((aOrbiterK * 4935807229040883505U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3927345926316409630U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5158769729850853623U;
            aOrbiterD = RotL64((aOrbiterD * 2446452358663812945U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12331351600010165154U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3940794200348684050U;
            aOrbiterC = RotL64((aOrbiterC * 13248997263062075043U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11248514843822945425U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1391497323278226522U) ^ RotL64(aNonceWordH, 53U);
            aOrbiterB = RotL64((aOrbiterB * 8376841806072565005U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13265623528678787307U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2802033745265647317U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3437626962562016147U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 42U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + RotL64(aNonceWordB, 29U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterC, 28U)) + RotL64(aNonceWordG, 31U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordC, 58U)) ^ RotL64(aNonceWordD, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17884U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18170U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 28U) ^ RotL64(aNonceWordB, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18051U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17490U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 11U)) + 7960325128608297381U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 37U)) + 12773836012104052042U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 47U)) + 3173972621347773016U) + RotL64(aNonceWordF, 41U);
            aOrbiterK = (aWandererB + RotL64(aIngress, 29U)) + 3708401356314308171U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 950774285720019449U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 4170092315705438265U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 17000449130864980747U) + RotL64(aNonceWordH, 49U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8793910540062893860U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 520277969543516469U;
            aOrbiterH = RotL64((aOrbiterH * 4150613128885828229U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12762214857389827271U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2932451184340207695U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7513337346940091655U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11062179998786293839U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7919119215271524178U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9053677007180081359U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1774988449597115155U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3799792889466518953U) ^ RotL64(aNonceWordG, 45U);
            aOrbiterK = RotL64((aOrbiterK * 17512791286490623455U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1815062051307896589U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15260373951371654483U) ^ RotL64(aNonceWordB, 29U);
            aOrbiterC = RotL64((aOrbiterC * 2208604434669491625U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12867546628945676853U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7772820973895846946U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7581704643538761985U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14213957831821966834U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16561105721170419454U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2540533987337175367U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 5U)) + aOrbiterB) + RotL64(aCarry, 47U)) + RotL64(aNonceWordA, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterK, 58U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + RotL64(aNonceWordD, 54U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32485U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 30807U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31271U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((aIndex + 26465U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 50U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aPrevious, 5U)) + 13880995121909552664U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 14534942818069300546U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 17745973100886007133U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 19U)) + 2249805580771946872U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 11U)) + 4460116116396439410U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 47U)) + 3378683994078106878U) + RotL64(aNonceWordB, 29U);
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 38U)) + RotL64(aCarry, 23U)) + 3992996501048809123U) + RotL64(aNonceWordC, 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12057768808864451929U) + RotL64(aNonceWordG, 41U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4115362079047921130U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12263015903331031345U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15297384955502206698U) + RotL64(aNonceWordE, 44U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17623548383481905636U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7487278217901483685U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3559213898000162417U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12311605719074507335U;
            aOrbiterA = RotL64((aOrbiterA * 3982199462062847697U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14807313864347885885U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11222085523291581822U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12580941911587215653U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 916681229436292462U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2441350114032314686U;
            aOrbiterK = RotL64((aOrbiterK * 7336079498999018067U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7361470539894653271U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12153585147213579808U;
            aOrbiterE = RotL64((aOrbiterE * 3040327545467672961U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13566300726101613579U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14875254144748509128U;
            aOrbiterB = RotL64((aOrbiterB * 13699179902908972403U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 39U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterA, 3U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordF, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterF, 57U)) + RotL64(aNonceWordD, 7U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterF, 30U));
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 57U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDC726FF1BAE48D09ULL + 0xA19AD0488FD7B904ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8FAC0BB14FBD7023ULL + 0xB3E5F4562D5A6A72ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF292E4AA810E915DULL + 0xD2D9556FCD4A96A2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE49DDF7F3912B95DULL + 0x94C5D35D7270843EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEBB47AF22E502ABDULL + 0xDDCBE3049A52F19BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9A3783F653BDFE39ULL + 0xEC947FC9D28B487EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x98D91FB61E0E3D27ULL + 0xAEEDD44F7130A839ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF09A1EECB5709E73ULL + 0x94C46E01B62FB480ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordD, 29U)) ^ RotL64(aNonceWordE, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7328U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5543U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1328U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 6481U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 60U)) + 13174219512651137892U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 13U)) + 2715455762789269341U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 1338018183235594313U) + RotL64(aNonceWordG, 24U);
            aOrbiterC = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 16566866551729552930U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 41U)) + 6901845297307236726U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 44U)) + 2476078302049201718U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 39U)) + 15531109473927052260U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 4087849380858572351U) + RotL64(aNonceWordC, 15U);
            aOrbiterI = ((aWandererD + RotL64(aIngress, 51U)) + 5167830630098599644U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 35U)) + 7275995452428627217U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 29U)) + 14794340370010024117U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8509217403041662849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2321522025240806996U;
            aOrbiterF = RotL64((aOrbiterF * 113568101672878697U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5676672952755594051U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2304681269233504384U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15731441084605554497U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8383399721062437300U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13181984036942227666U;
            aOrbiterE = RotL64((aOrbiterE * 1648761328771932069U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13602604532551684210U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12725687663616352843U;
            aOrbiterC = RotL64((aOrbiterC * 4684699861686199753U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5831790822416009806U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4535048543735457407U;
            aOrbiterB = RotL64((aOrbiterB * 12076777878870257053U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10617608605149381858U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5244225377862618630U;
            aOrbiterI = RotL64((aOrbiterI * 15307177251167023999U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 18229989093139888456U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9728120630096192811U;
            aOrbiterD = RotL64((aOrbiterD * 16052574428163231023U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1312233443099767304U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8043115602160128619U) ^ RotL64(aNonceWordD, 43U);
            aOrbiterK = RotL64((aOrbiterK * 9365756845731616963U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4679339316686216023U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 211799535650113758U;
            aOrbiterA = RotL64((aOrbiterA * 1478368466990144107U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 13307123762743628190U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordF, 57U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7093673238704478497U;
            aOrbiterH = RotL64((aOrbiterH * 13273906568866802561U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16396459072175632290U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13174219512651137892U;
            aOrbiterG = RotL64((aOrbiterG * 7581008806810219369U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 46U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterC, 42U)) + RotL64(aNonceWordE, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + RotL64(aNonceWordB, 35U));
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 56U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterH, 37U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 36U) + aOrbiterG) + RotL64(aOrbiterI, 35U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 30U) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8277U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8451U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordG, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15380U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((aIndex + 16105U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 42U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 35U)) + 5171470532667965920U) + RotL64(aNonceWordB, 8U);
            aOrbiterH = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 750549462358682403U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 26U)) + 3325689257577120525U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 37U)) + 18031575461559790826U) + RotL64(aNonceWordF, 19U);
            aOrbiterD = (aWandererG + RotL64(aScatter, 57U)) + 13874739537012288677U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 11U)) + 4250029868785016865U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 39U)) + 8211158803112611161U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 5U)) + 1083939790236786027U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 3446525462376962464U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 60U)) + 6973817815000417325U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 15230876489676945543U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9359727659738755880U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 8775170107816327654U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) ^ RotL64(aNonceWordA, 13U);
            aOrbiterI = RotL64((aOrbiterI * 6910680458261008653U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11958941755525038545U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16966819714283167348U;
            aOrbiterH = RotL64((aOrbiterH * 16363457661846050749U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14556087985619763243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17915047508377045221U;
            aOrbiterD = RotL64((aOrbiterD * 6727635453185130109U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8578745677485367222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7002181668717618866U;
            aOrbiterJ = RotL64((aOrbiterJ * 12329703532414955235U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3569939503066735457U) + RotL64(aNonceWordH, 43U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2956247934282522184U;
            aOrbiterC = RotL64((aOrbiterC * 9946650822131152531U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4285180013402474041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5976239869535619811U;
            aOrbiterG = RotL64((aOrbiterG * 3458095419039067465U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2424524955161695463U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6849595426583763537U;
            aOrbiterF = RotL64((aOrbiterF * 12727902040238318101U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11414890686374886716U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5668287266836153445U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8011885266143066285U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9976985606260445887U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9223940029500676834U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8508023992488499955U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4480967907876921958U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5132766654502526597U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 321625389942019245U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12921555132452983464U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5171470532667965920U;
            aOrbiterA = RotL64((aOrbiterA * 9710487797420618879U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 54U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + RotL64(aNonceWordE, 37U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterH, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordC, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 54U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterE, 56U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24246U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22580U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21134U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 18722U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererG + RotL64(aIngress, 40U)) + 18144572925667544139U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 29U)) + 5659758077574059728U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 43U)) + 6343330616999166392U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordF, 16U);
            aOrbiterH = (aWandererC + RotL64(aScatter, 37U)) + 17754639838410839447U;
            aOrbiterB = (aWandererH + RotL64(aCross, 12U)) + 9451843819849581729U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 21U)) + 7957854457197462212U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 1461994799722205010U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 18002214276252170177U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 14689869073147027164U) + RotL64(aNonceWordB, 25U);
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 5U)) + 3978104368003440293U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 51U)) + 8512135845221335386U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1477533446382953439U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2166717790929947990U;
            aOrbiterE = RotL64((aOrbiterE * 6538884492418324461U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 8082437060686606995U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordA, 57U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4363687722464700362U;
            aOrbiterK = RotL64((aOrbiterK * 7199165810993478887U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15782763348014924206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8572509150015960728U;
            aOrbiterF = RotL64((aOrbiterF * 3340528604891897779U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12248271773316742521U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9602078627638561949U;
            aOrbiterB = RotL64((aOrbiterB * 1860631869877427405U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17244849374768558859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1030743048280579012U;
            aOrbiterI = RotL64((aOrbiterI * 10858949914285817051U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17722342363541914280U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15667504059789880034U;
            aOrbiterD = RotL64((aOrbiterD * 15872269872168533709U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12645332941998550794U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9938135244509986497U;
            aOrbiterJ = RotL64((aOrbiterJ * 16548185968987392957U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4024609904162105979U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6732064218696157303U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3815409766145891393U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 14314117137220703583U) + RotL64(aNonceWordC, 31U);
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15244765904057473814U;
            aOrbiterA = RotL64((aOrbiterA * 4034571710808047959U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17441241682018169245U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11958974379114644873U;
            aOrbiterC = RotL64((aOrbiterC * 11315689206845170303U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8310839846793796473U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18144572925667544139U;
            aOrbiterG = RotL64((aOrbiterG * 11668203295511168011U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + RotL64(aNonceWordE, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 52U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterC, 36U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordD, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 26U) + aOrbiterH) + RotL64(aOrbiterE, 29U));
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterG, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 3U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 34U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordD, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 24652U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30237U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordH, 37U)) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25982U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29175U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 21U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aPrevious, 39U)) + 18087125778766689269U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 37U)) + 13710545066503235196U;
            aOrbiterI = (aWandererF + RotL64(aCross, 41U)) + 1701939704736254645U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 47U)) + 8064093611384019909U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aPrevious, 34U)) + 16623332751533885431U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 15590129153794910109U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 7413312683079107383U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 4186064478651458810U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 23U)) + 5501191643940735954U) + RotL64(aNonceWordC, 23U);
            aOrbiterD = (aWandererH + RotL64(aCross, 12U)) + 11064645242200570835U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 57U)) + 13825922087298055833U) + RotL64(aNonceWordA, 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5944980709887369970U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8181136916070569646U;
            aOrbiterI = RotL64((aOrbiterI * 395183021205661827U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 15442336949157292482U) + RotL64(aNonceWordG, 11U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11580554435240641337U;
            aOrbiterH = RotL64((aOrbiterH * 6654637892858767739U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11240018128174598322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2027565596050777471U;
            aOrbiterC = RotL64((aOrbiterC * 18048186560314431815U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16425887196883725233U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16828683527588834095U;
            aOrbiterF = RotL64((aOrbiterF * 17746289103235902485U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9923829146479008804U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6669171007279929454U;
            aOrbiterB = RotL64((aOrbiterB * 681823450939955099U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3902430046523165149U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6739998149289590041U;
            aOrbiterK = RotL64((aOrbiterK * 2675037435528416821U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 16014401255534234075U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordE, 45U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14741857638680634564U;
            aOrbiterD = RotL64((aOrbiterD * 8723611021403369393U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5064807861673260054U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 968747317273200299U;
            aOrbiterJ = RotL64((aOrbiterJ * 14122304002722582329U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5282686212362051427U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6902253563196129760U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7682808024658992049U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4995580401402368332U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14949762584793646470U;
            aOrbiterA = RotL64((aOrbiterA * 3539183342072953803U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2378815735788107402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 18087125778766689269U;
            aOrbiterE = RotL64((aOrbiterE * 16799380528404446281U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 26U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 58U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + RotL64(aNonceWordB, 24U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterK, 11U));
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 56U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + RotL64(aNonceWordF, 17U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererB, 40U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBB95FE0B876EF8E9ULL + 0xB04F5DE6EA0ECB47ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF3E1F5FC276CF8DBULL + 0xA1B45024A978E01BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE3FF60F481CA1EB3ULL + 0x816CEE0C92047F1EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCED14F71FA89C337ULL + 0x9DAD5EFDC2574BFCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA26311D50B7E5DF1ULL + 0xB3469BF1AAE2DE5CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFB1A90003383F481ULL + 0xF3F448197ED8D367ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEA64BE23003D1FD5ULL + 0xAA4DC49E8253A7E7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBFD82415ADA2962FULL + 0x88CB06E98FB3D797ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordB, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4794U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((aIndex + 1881U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordH, 22U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1991U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 657U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererD + RotL64(aIngress, 3U)) + 16519040829220310189U;
            aOrbiterB = (aWandererI + RotL64(aCross, 41U)) + 6888002778416941825U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 12U)) + RotL64(aCarry, 13U)) + 1310832187746534025U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 27U)) + 5890888009051281674U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 53U)) + 5143864838362464857U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 19U)) + 15591534069452660003U) + RotL64(aNonceWordC, 39U);
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 1466867671765325096U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 13931443680107902488U) + RotL64(aNonceWordF, 18U);
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 34U)) + 15400747367673245552U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2836975369734495759U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2370720358274970117U;
            aOrbiterG = RotL64((aOrbiterG * 4615571902817575375U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3470677184188006133U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7175584278499266723U) ^ RotL64(aNonceWordG, 55U);
            aOrbiterF = RotL64((aOrbiterF * 10067096593682482345U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6095078817776863055U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2176637999243513070U;
            aOrbiterC = RotL64((aOrbiterC * 12215701810843975501U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5580391239754903129U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15196125567953871184U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12686361960729564519U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12787014151503209931U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1523153207064063495U;
            aOrbiterA = RotL64((aOrbiterA * 3113907543551927561U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12973289026485937829U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9087439766232078173U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5817029335999350327U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16318022893068674015U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11089160685103562409U;
            aOrbiterD = RotL64((aOrbiterD * 17087834321385147603U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8680037953925067235U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3112588943274158119U;
            aOrbiterB = RotL64((aOrbiterB * 9214011370307670371U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16749015684369649821U) + RotL64(aNonceWordH, 43U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9419550535891334966U;
            aOrbiterE = RotL64((aOrbiterE * 5421312787569114811U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterB, 41U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordB, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterA, 58U)) + RotL64(aNonceWordE, 57U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 19U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 12U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 54U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordA, 27U)) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10110U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((aIndex + 8759U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6910U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7785U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aPrevious, 53U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 5573188770530340913U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 34U)) + 1431772230889897111U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 4809192776429682319U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 27U)) + 5576603692574369341U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 53U)) + 2720143226007220386U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 23U)) + 17220328778565331629U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 9629485808442089423U) + RotL64(aNonceWordC, 59U);
            aOrbiterA = ((aWandererA + RotL64(aCross, 39U)) + 1136998437010390983U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 46U)) + 11893390497814523841U) + RotL64(aNonceWordB, 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1764986431917532370U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1741014798007010376U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13414914086049500731U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12221368453236547044U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7694538641172350430U;
            aOrbiterK = RotL64((aOrbiterK * 8439120733670016501U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17472344518811560603U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 3308740700728172984U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) ^ RotL64(aNonceWordF, 23U);
            aOrbiterD = RotL64((aOrbiterD * 15290400462887712083U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9535358833412446771U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11192312491731312451U;
            aOrbiterA = RotL64((aOrbiterA * 17405609148475445743U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14850451970047190039U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11932493299452443256U) ^ RotL64(aNonceWordG, 3U);
            aOrbiterB = RotL64((aOrbiterB * 7964808728820467795U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5972619895614731870U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17174497535809891690U;
            aOrbiterE = RotL64((aOrbiterE * 15471084511364572533U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17412894714378898351U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14675615208706549810U;
            aOrbiterJ = RotL64((aOrbiterJ * 7864845089606499769U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16116792108013658523U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9702262005960966336U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 970452849653781703U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17337264966818542841U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7004462033775827275U;
            aOrbiterF = RotL64((aOrbiterF * 11943575980344402681U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterH, 10U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordE, 30U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 6U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + RotL64(aNonceWordH, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 58U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 44U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 56U) ^ RotL64(aNonceWordB, 37U)) ^ RotL64(aNonceWordD, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15270U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13547U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordH, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14093U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneC[((aIndex + 11628U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 18U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 57U)) + 6163290588946759209U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 41U)) + 7342672468560105447U) + RotL64(aNonceWordC, 47U);
            aOrbiterI = (aWandererD + RotL64(aScatter, 19U)) + 11574563167017282321U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 2254820206194758964U) + RotL64(aNonceWordB, 5U);
            aOrbiterC = (aWandererE + RotL64(aPrevious, 52U)) + 1469783447473099498U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 13U)) + 14174828900676165088U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 5U)) + 16277954291890598132U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aIngress, 37U)) + 14845750668693136766U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 150099699692047766U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1200784917165131703U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9469982764806754302U;
            aOrbiterI = RotL64((aOrbiterI * 17851969334511301943U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10956702761701710182U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7915506894975487807U) ^ RotL64(aNonceWordF, 42U);
            aOrbiterA = RotL64((aOrbiterA * 8874108311712727983U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17335794183733623213U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 557028996286989506U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3993359298602424281U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1597385667771002414U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 4376417959915162639U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4626236858205178149U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 549770198518993876U) + RotL64(aNonceWordH, 49U);
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 756554555648070919U;
            aOrbiterC = RotL64((aOrbiterC * 16272320259614325355U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 7298557532533152193U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3336802611342112013U;
            aOrbiterJ = RotL64((aOrbiterJ * 14679103452120080499U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2314938232094714365U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12215066333571149153U;
            aOrbiterF = RotL64((aOrbiterF * 10747052773052630601U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7762752719356805046U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6519429915769040078U;
            aOrbiterH = RotL64((aOrbiterH * 15548676502167938513U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7556691736109752918U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13731245903412646404U;
            aOrbiterD = RotL64((aOrbiterD * 15581965016668635409U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterI, 51U)) + RotL64(aNonceWordG, 59U));
            aWandererK = aWandererK + ((RotL64(aIngress, 22U) + RotL64(aOrbiterH, 34U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 36U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterH, 12U));
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + RotL64(aNonceWordD, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordB, 43U)) ^ RotL64(aNonceWordE, 14U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18481U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 17303U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordD, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18392U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19861U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 26U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 57U)) + 16451272412693907816U;
            aOrbiterH = (aWandererE + RotL64(aCross, 44U)) + 10099485419723255462U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 27U)) + 17668900099534923192U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 19U)) + 5497093724143181753U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 10354044773550071706U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + 12728258851198019099U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 40U)) + 4144050505314242618U) + RotL64(aNonceWordC, 59U);
            aOrbiterA = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 14133805325480076530U) + RotL64(aNonceWordB, 47U);
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 308863673210602899U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11741180130160569753U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12926863156769180448U;
            aOrbiterD = RotL64((aOrbiterD * 9726030996091054939U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 211920854786494259U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13234608842479411078U;
            aOrbiterC = RotL64((aOrbiterC * 2556747209733759467U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9164711974854618892U) + RotL64(aNonceWordF, 55U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6667377062281954219U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2603737166987437649U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4559040002406721850U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1749875480850675109U;
            aOrbiterE = RotL64((aOrbiterE * 15822640067349481089U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9555365165561936366U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 18289733999504213574U) ^ RotL64(aNonceWordA, 9U);
            aOrbiterG = RotL64((aOrbiterG * 14156217554673229429U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8727162691639622461U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 291406782452963706U;
            aOrbiterK = RotL64((aOrbiterK * 8413500075082350243U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8294911802626492257U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15853578397277298548U;
            aOrbiterA = RotL64((aOrbiterA * 13256191781365357747U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11535146194939658681U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2177540476748375661U;
            aOrbiterJ = RotL64((aOrbiterJ * 15791341922007841029U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2705306323728084136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17617871830709148043U;
            aOrbiterH = RotL64((aOrbiterH * 3449981219502809255U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 60U)) + aOrbiterA) + RotL64(aNonceWordG, 25U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 39U)) + aOrbiterH);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordH, 22U)) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterK, 24U));
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordD, 38U)) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24617U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23045U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordE, 53U)) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22796U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 25730U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 30U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 4U)) + 18255347001097480328U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 13679246790311505735U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 27U)) + 10565839529765027116U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordH, 15U);
            aOrbiterF = (aWandererC + RotL64(aCross, 53U)) + 14327172566224769901U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 16239024612038195174U) + RotL64(aNonceWordF, 28U);
            aOrbiterE = (aWandererJ + RotL64(aCross, 18U)) + 13800012174212131890U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 39U)) + 13900288860157577583U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 43U)) + 4144386119777112740U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 3154558262670631372U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7456728543137614001U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11709519851158935384U;
            aOrbiterK = RotL64((aOrbiterK * 7016689518570071587U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15607438907832240304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9276575329661725624U;
            aOrbiterE = RotL64((aOrbiterE * 8879744070762412745U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6459435969129449226U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6442382118416542275U;
            aOrbiterH = RotL64((aOrbiterH * 2921027306686588233U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 12117432107282150865U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6831279293184793243U;
            aOrbiterG = RotL64((aOrbiterG * 2435360641135249073U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9520022957804572889U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8322178689474588679U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1627707191467537115U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4162401591586869316U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8994015844714895961U;
            aOrbiterF = RotL64((aOrbiterF * 15421910378057951895U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10038095909727959633U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17756404450592957616U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14255952184627347295U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3379089265413427719U) + RotL64(aNonceWordG, 23U);
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11341713098678108441U;
            aOrbiterI = RotL64((aOrbiterI * 2500587373161411961U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4030296130743454165U) + RotL64(aNonceWordB, 11U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6332387792111212064U;
            aOrbiterD = RotL64((aOrbiterD * 16490982218150897861U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 48U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 18U) + aOrbiterC) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 43U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterG, 11U)) + RotL64(aNonceWordC, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterF, 56U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aNonceWordA, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 26U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordB, 5U)) ^ RotL64(aNonceWordG, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27916U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 31941U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 51U) ^ RotL64(aNonceWordF, 6U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27858U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30361U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 16183871922837164759U) + RotL64(aNonceWordE, 59U);
            aOrbiterE = ((aWandererE + RotL64(aScatter, 54U)) + RotL64(aCarry, 39U)) + 7002058258090219055U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 35U)) + 5650868611888303705U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 11U)) + 11899839660943876690U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 39U)) + 15349649504488111111U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 19U)) + 14060149569086744970U) + RotL64(aNonceWordH, 11U);
            aOrbiterF = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 12920917574225030112U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 43U)) + 2831994965175330135U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 24U)) + 18312543585028439192U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11657562205118394239U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10850792819281246052U;
            aOrbiterI = RotL64((aOrbiterI * 10663100544207879337U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17810371216216125323U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 7963413941144223128U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) ^ RotL64(aNonceWordC, 20U);
            aOrbiterK = RotL64((aOrbiterK * 534217972450595401U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5498715358793875584U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9256727548911651373U;
            aOrbiterF = RotL64((aOrbiterF * 10498848323914000989U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17246360111302191699U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18309978718113983369U;
            aOrbiterD = RotL64((aOrbiterD * 18267472694666221077U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3100998994319502921U) + RotL64(aNonceWordD, 43U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8129301860291235970U;
            aOrbiterH = RotL64((aOrbiterH * 17847033539279176187U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1889641029473279114U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16538494307002917945U;
            aOrbiterJ = RotL64((aOrbiterJ * 8081488217920885783U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5432230549146849322U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2634437941396090817U;
            aOrbiterA = RotL64((aOrbiterA * 7612999214758935211U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16940172599174185058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13151669140593952203U;
            aOrbiterG = RotL64((aOrbiterG * 16225319638131723487U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3995064294869931681U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 913081077665768816U;
            aOrbiterE = RotL64((aOrbiterE * 9299514648768060453U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 30U) + aOrbiterK) + RotL64(aOrbiterD, 34U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + RotL64(aNonceWordF, 49U));
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + RotL64(aNonceWordG, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 20U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_WaterPolo_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9B5E36004B40719FULL + 0x9A59C5FFD75B00D0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAEB3B2D4338B725FULL + 0x8581D97CD418EC09ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x96C8D3C218A729D7ULL + 0xCC419981F9EEA3F0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9875AD3CC83AB519ULL + 0xD751FBDA8C90A638ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x816A5ED60077335FULL + 0xCED4606F58B05455ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAC36C8A501BD81CDULL + 0xEF7EE0B8A19B3E70ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x80A7AFF28500569BULL + 0x9128885F4F19CC42ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8F8A00ED6EE55453ULL + 0xBC0D169FD65EA59DULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordA, 5U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2619U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[((aIndex + 5074U)) & W_KEY1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordF, 11U)) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1962U)) & W_KEY1], 20U) ^ RotL64(mSource[((aIndex + 4218U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 24U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aPrevious, 34U)) + 13333509828310369865U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 7645352517103840797U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 3U)) + 5310766306660062655U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 5165635069832352932U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 15684141764734281849U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 57U)) + 3327963374225061738U) + aPhaseAOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordA, 57U);
            aOrbiterH = ((aWandererG + RotL64(aIngress, 13U)) + 8625811794878848871U) + RotL64(aNonceWordG, 45U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7598657468430485291U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2881171216276746485U;
            aOrbiterC = RotL64((aOrbiterC * 3331350584102843605U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10237691227222918101U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6419254255884834497U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3816625473642865305U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4238455444646479956U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14936613353493061492U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3544216916806292273U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15324699725208372627U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 9506640480601832011U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) ^ RotL64(aNonceWordC, 15U);
            aOrbiterH = RotL64((aOrbiterH * 12819564111348390227U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3709149613660215641U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1724290199312754307U;
            aOrbiterK = RotL64((aOrbiterK * 12597580418257897965U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13191172833570139194U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3686087945377837886U;
            aOrbiterB = RotL64((aOrbiterB * 10883609557429936283U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10418330386245397022U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5383531313632347245U) ^ RotL64(aNonceWordB, 49U);
            aOrbiterF = RotL64((aOrbiterF * 2987755379396160073U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 48U) + aOrbiterK) + RotL64(aOrbiterC, 19U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordF, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + RotL64(aNonceWordD, 24U)) + aPhaseAWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterH, 6U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordB, 5U)) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5916U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8632U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordC, 41U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6472U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8642U)) & W_KEY1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 14U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 6467297102954816305U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 41U)) + 7921154109831114952U) + aPhaseAOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 4U)) + 5701131763215638919U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 10022999076719002684U) + RotL64(aNonceWordD, 61U);
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 11U)) + 4367135243038982316U) + RotL64(aNonceWordB, 43U);
            aOrbiterC = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 14445846824810383592U;
            aOrbiterB = (aWandererI + RotL64(aCross, 19U)) + 7683697954545773253U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17517006750428030899U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2052484792684025476U;
            aOrbiterF = RotL64((aOrbiterF * 12463117571122469643U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6279463052085808926U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 679280153651813684U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3047031560593583881U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2939516520188460569U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1960616434964712325U;
            aOrbiterA = RotL64((aOrbiterA * 15145998415466343039U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12273819390719947361U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5685033154709449397U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9845666295874714959U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 9314494172199500653U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordF, 51U);
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15757631834636427621U;
            aOrbiterE = RotL64((aOrbiterE * 15483543888965744529U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10878078046389399574U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3583495913766365232U) ^ RotL64(aNonceWordG, 15U);
            aOrbiterC = RotL64((aOrbiterC * 2913540984990155225U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7385544065754622301U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16839599460207922881U;
            aOrbiterB = RotL64((aOrbiterB * 240651605910592561U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 4U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordA, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 50U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + RotL64(aNonceWordE, 20U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 21U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 48U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordH, 5U)) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16183U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13267U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordD, 51U)) ^ RotL64(aNonceWordC, 43U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16277U)) & W_KEY1], 24U) ^ RotL64(aKeyRowReadB[((aIndex + 11566U)) & W_KEY1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aIngress, 57U)) + 13499155707765393469U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 3740324981823726185U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 5470765363949735652U) + aPhaseAOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 3446436171274452326U;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 50U)) + 1778929412631211933U) + aPhaseAOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordE, 27U);
            aOrbiterE = (aWandererD + RotL64(aIngress, 27U)) + 14666308799855220954U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 41U)) + 4548410236791175055U) + RotL64(aNonceWordD, 55U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5829739767694190372U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14319231414903675748U;
            aOrbiterH = RotL64((aOrbiterH * 4966501102515775601U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1513851750246111405U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1685620217748986019U) ^ RotL64(aNonceWordG, 44U);
            aOrbiterG = RotL64((aOrbiterG * 9286548037413609445U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16284162182006054402U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6271539598462003309U) ^ RotL64(aNonceWordB, 15U);
            aOrbiterK = RotL64((aOrbiterK * 13923286694131331137U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12669312437565969473U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11894755313393001665U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12556759675372354075U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6315983824634946566U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17106616474222892782U;
            aOrbiterD = RotL64((aOrbiterD * 167205520766791073U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13350266700180455548U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4608846311203767162U;
            aOrbiterE = RotL64((aOrbiterE * 2504857468837437365U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14195866746143604365U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7917977448256795054U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5927771378657284557U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterA, 12U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + RotL64(aNonceWordH, 7U));
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + RotL64(aNonceWordA, 49U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordB, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18200U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21635U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordE, 4U)) ^ RotL64(aNonceWordG, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16708U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 19775U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 29U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 57U)) + 5960680319644404115U) + aPhaseAOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 16050752633567034185U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 50U)) + 8447503223226854741U) + RotL64(aNonceWordH, 29U);
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 14176813813397917591U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 10534915376130006644U) + RotL64(aNonceWordA, 11U);
            aOrbiterJ = (aWandererD + RotL64(aIngress, 19U)) + 6866224454375302514U;
            aOrbiterB = (aWandererA + RotL64(aCross, 27U)) + 16506374165041008396U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7167814023968794098U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13870852197416596664U;
            aOrbiterH = RotL64((aOrbiterH * 17015971222069856463U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18064038854848993105U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9869630811507771691U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13723164383800461387U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 863613100452759380U) + RotL64(aNonceWordD, 30U);
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16597969741225436529U;
            aOrbiterG = RotL64((aOrbiterG * 2680793528887208903U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6575347108051310653U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17062262265485019063U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7601045488473620019U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7193399224636409133U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14146747818810433849U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5273185769989530041U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9441449106442431427U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4303295336545399503U;
            aOrbiterF = RotL64((aOrbiterF * 8829695296836242587U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12604760768543193458U) + RotL64(aNonceWordF, 47U);
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15779327512379787715U;
            aOrbiterB = RotL64((aOrbiterB * 14000905201441272597U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordG, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 10U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterG, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 4U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 27U)) + aOrbiterH) + RotL64(aNonceWordC, 51U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordG, 27U)) ^ RotL64(aNonceWordF, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22672U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22840U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordH, 50U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23295U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 22704U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 40U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 5U)) + 13583136155674166402U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordB, 37U);
            aOrbiterB = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 12830472187484919497U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 18081197909484522509U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 8680634051297891550U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 60U)) + 13939998767458656823U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 29U)) + 1795730579103692594U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 37U)) + 17369751719734069999U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordE, 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 224769585901248068U) + RotL64(aNonceWordA, 61U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4133547085925268180U;
            aOrbiterK = RotL64((aOrbiterK * 2611561365156544735U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7022512056309567391U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10319484359046945495U;
            aOrbiterJ = RotL64((aOrbiterJ * 3400140531307001933U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10483878349412282069U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6481381149199985736U;
            aOrbiterI = RotL64((aOrbiterI * 9701719367082506253U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13721077228796934509U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 9704818014314175007U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 760445624027740287U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6253040047758584339U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16890211690273641226U;
            aOrbiterC = RotL64((aOrbiterC * 5622534399866057841U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6216227831265032436U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2023609047004658739U;
            aOrbiterE = RotL64((aOrbiterE * 3252332895698310147U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9201669637050388263U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 5106927540934338576U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ RotL64(aNonceWordD, 57U);
            aOrbiterG = RotL64((aOrbiterG * 6368134569042291431U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 28U) + RotL64(aOrbiterI, 5U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aPhaseAWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + RotL64(aNonceWordC, 49U));
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aNonceWordG, 4U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterK, 28U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordF, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30704U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31667U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 46U) ^ RotL64(aNonceWordG, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31624U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 31891U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aScatter, 29U)) + 9435962834163239322U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 10524704356081318973U;
            aOrbiterD = ((((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 7403401305665208680U) + aPhaseAOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordD, 10U);
            aOrbiterA = (aWandererG + RotL64(aPrevious, 35U)) + 7525414805023556493U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 1116686470029070951U) + RotL64(aNonceWordF, 17U);
            aOrbiterH = (aWandererD + RotL64(aPrevious, 51U)) + 13257612299137802420U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 44U)) + 9181543003986598283U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9739384852307501107U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11308402900229016057U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12690186771773188967U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14935167593705272337U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7171824007631943535U;
            aOrbiterE = RotL64((aOrbiterE * 4839974427616194289U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 8068411284829563567U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordE, 43U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12350207458513447578U;
            aOrbiterH = RotL64((aOrbiterH * 813973258659041895U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17039236343991574134U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 18291683592714999632U) ^ RotL64(aNonceWordH, 51U);
            aOrbiterJ = RotL64((aOrbiterJ * 7771718817924840713U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6239616841884430968U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10604527977569876774U;
            aOrbiterC = RotL64((aOrbiterC * 6972820410084939637U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1707724300671717658U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3802268808625297647U;
            aOrbiterA = RotL64((aOrbiterA * 11296811630387191563U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9423064323799920219U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 242153923313096551U;
            aOrbiterG = RotL64((aOrbiterG * 12117679073775630197U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 56U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterG, 10U)) + RotL64(aNonceWordC, 27U));
            aWandererA = aWandererA + (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + aPhaseAWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + RotL64(aNonceWordA, 35U));
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA649C790DE972E33ULL + 0x96EAD17467EC7C1CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBDE45891DD33E889ULL + 0xEBB45E281B07F2E9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8A99027A2D025913ULL + 0xA4238B8415BE716CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE97D13FB6A95E8D1ULL + 0xE57CEEAA8D8D5826ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCA4879667E4A95A1ULL + 0xDC3EF46EF761E956ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC6789358F83BDA11ULL + 0x84D799857D3A41FBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE3F405FCB17474BFULL + 0xDAF4277A7E5E6EEEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF9905FFB276E55F1ULL + 0xC2508E3AA89EFAEFULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 14U) ^ RotL64(aNonceWordC, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5453U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 350U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordF, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 389U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3091U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 56U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 29U)) + 1708250618750199233U) + RotL64(aNonceWordB, 27U);
            aOrbiterF = ((aWandererF + RotL64(aScatter, 44U)) + RotL64(aCarry, 39U)) + 12009147777553691142U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 8393982703399156592U) + aPhaseBOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 3247327098356831221U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 3U)) + 3403590155376353737U) + aPhaseBOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordA, 49U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18197244558104735044U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3096253642040701606U;
            aOrbiterG = RotL64((aOrbiterG * 6656168712438620783U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8012692688785412179U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17531946907545680745U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16510602981731506381U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17687695944270225817U) + RotL64(aNonceWordH, 8U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16147773866007628769U;
            aOrbiterI = RotL64((aOrbiterI * 16926442582711557877U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 18244641303026196497U) + RotL64(aNonceWordD, 11U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8839160526348897457U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14268021129087663397U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10599266240854068246U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2056723540756216155U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + aPhaseBWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 12U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aNonceWordG, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 44U)) + aOrbiterI) + RotL64(aCarry, 35U)) + RotL64(aNonceWordE, 7U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 23U)) + aOrbiterD) + aPhaseBWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordF, 14U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9166U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 8781U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordB, 34U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7619U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6650U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 43U)) ^ (RotL64(aIngress, 24U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererA + RotL64(aIngress, 24U)) + RotL64(aCarry, 37U)) + 252059974543142812U) + RotL64(aNonceWordE, 7U);
            aOrbiterG = ((aWandererC + RotL64(aScatter, 3U)) + 11690823093681457368U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 13282189752890971123U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 9507416294305708435U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 51U)) + 14053038174390776539U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordH, 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14605253312318725009U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18138286582677863671U;
            aOrbiterD = RotL64((aOrbiterD * 10595905899691011321U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8530091235978489988U) + RotL64(aNonceWordA, 25U);
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 14381731677571170073U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordC, 11U);
            aOrbiterK = RotL64((aOrbiterK * 11675896999665768253U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13316413456378978456U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3910529530149320706U;
            aOrbiterI = RotL64((aOrbiterI * 16000139333493588429U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6302070286831566901U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12324134652758551396U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17136438281540250165U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4773478557638475048U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4031153435446078944U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3876928995240982769U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 52U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + RotL64(aNonceWordG, 26U));
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 46U)) + aOrbiterD) + RotL64(aCarry, 39U)) + RotL64(aNonceWordD, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 58U) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14004U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 12075U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordD, 35U)) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12866U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 15639U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCross, 60U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aIngress, 23U)) + 6973892330986118220U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 9886813896272094864U) + RotL64(aNonceWordD, 51U);
            aOrbiterK = ((((aWandererD + RotL64(aPrevious, 56U)) + RotL64(aCarry, 23U)) + 10996306582517553173U) + aPhaseBOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordE, 55U);
            aOrbiterF = (((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 8490648283899856223U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 47U)) + 105141713530704655U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3114337422810562588U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 980857684690886131U;
            aOrbiterK = RotL64((aOrbiterK * 17407927633910728721U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6562042345807072665U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15665371138706353619U) ^ RotL64(aNonceWordH, 54U);
            aOrbiterA = RotL64((aOrbiterA * 8086237578564620623U), 23U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 18113013571374375028U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 11U);
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17405346422601997299U;
            aOrbiterD = RotL64((aOrbiterD * 11162604605443005253U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5130876096426182506U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1813821672299154629U;
            aOrbiterF = RotL64((aOrbiterF * 15478100342425611875U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15793814882743306728U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13925299440495476399U;
            aOrbiterB = RotL64((aOrbiterB * 12049601510660117401U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 48U) + RotL64(aOrbiterB, 53U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + RotL64(aNonceWordA, 45U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordB, 9U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterF, 6U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19503U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21060U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordC, 5U)) ^ RotL64(aNonceWordF, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20609U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 20456U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 50U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 10805654776556844351U) + RotL64(aNonceWordH, 39U);
            aOrbiterF = (aWandererA + RotL64(aPrevious, 56U)) + 582794182442795335U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 2858343650974681068U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 5U)) + 8189584049022064284U) + aPhaseBOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 1565100751996962893U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordD, 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8062028016947611891U) + RotL64(aNonceWordF, 43U);
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8280504280578451745U;
            aOrbiterG = RotL64((aOrbiterG * 5212851648135050483U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11326869194491655350U) + RotL64(aNonceWordE, 7U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1671695656567777163U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7511554500524257921U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2349843105293943452U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13015545152052004254U;
            aOrbiterA = RotL64((aOrbiterA * 1316662811685429983U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16703354404749291869U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8713231044374305801U;
            aOrbiterF = RotL64((aOrbiterF * 9242480982197688625U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11118401674497783533U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14857556493734710364U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3452566050389715195U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordA, 12U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterB, 21U)) + RotL64(aNonceWordC, 31U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 58U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 52U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordE, 26U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23957U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 26083U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 26U) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27175U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 26021U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 9471546960258473684U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordG, 9U);
            aOrbiterC = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 18050235435948942244U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 30U)) + 3005107102671544641U) + RotL64(aNonceWordE, 27U);
            aOrbiterB = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 17898396434573801850U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + 15071602525497771648U) + aPhaseBOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 5780119462702672108U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordD, 7U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13301326224151025687U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2868878978993219351U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 18129323022260575961U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1199228670638790709U;
            aOrbiterD = RotL64((aOrbiterD * 1780426336211781025U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1839199978088021020U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 4999517042246790165U) ^ RotL64(aNonceWordF, 59U);
            aOrbiterG = RotL64((aOrbiterG * 4585813675677234577U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8788607633376516299U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15143903839930468749U;
            aOrbiterC = RotL64((aOrbiterC * 12735914889325422675U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16674732686428431869U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15908873150953195581U;
            aOrbiterB = RotL64((aOrbiterB * 18049755517524334107U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterE, 48U)) + RotL64(aNonceWordC, 56U)) + aPhaseBWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 48U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterC, 29U)) + RotL64(aNonceWordH, 29U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererF, 56U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordB, 46U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28263U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31019U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 37U) ^ RotL64(aNonceWordC, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30041U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 28074U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 42U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 9446153639709651566U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 10550762260670758167U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 35U)) + 7062634922142578383U) + RotL64(aNonceWordE, 59U);
            aOrbiterF = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 9178499097812764515U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 56U)) + 6887103379773525538U) + RotL64(aNonceWordD, 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6239750312052010257U) + RotL64(aNonceWordB, 52U);
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17645022614523287959U;
            aOrbiterG = RotL64((aOrbiterG * 14448140327044053545U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3639618183259408272U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3131737117548745095U;
            aOrbiterD = RotL64((aOrbiterD * 6585057380704940395U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7253994382396406554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15217993711938379561U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17853313384747259923U), 23U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 12594152227603630033U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordG, 15U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11250170200489647869U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 546800378327864723U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12936942656624279424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10990736056052106149U;
            aOrbiterB = RotL64((aOrbiterB * 7123916809953459187U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 22U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordH, 55U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterB, 42U)) + aOrbiterD) + aPhaseBWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + RotL64(aCarry, 43U)) + RotL64(aNonceWordF, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 37U);
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

void TwistExpander_WaterPolo_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBE0D4138E9C1A0BDULL + 0x99BBAEB24E2C98CBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA8A8E2A40E80D471ULL + 0xFA51B83B90144BABULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFF7AFAE2700C8B09ULL + 0x9ED94BE10A1FCA45ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBC322CE8E3526A37ULL + 0xA70F728150662337ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC447E8C590CBA3A5ULL + 0xE10E606FF94F165BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA2C9EA0E4F142B1DULL + 0xD4BEC4DF24060CFDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA9D0EFB4247A32FBULL + 0xB9F3ED700A53BA96ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCBBA0F5A8D3332D7ULL + 0x851D0BD1721F0DD0ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordF, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5384U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2502U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 53U) ^ RotL64(aNonceWordB, 22U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1824U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 6769U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aPrevious, 34U)) + 3236820517816085022U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 741288875914097926U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 8417246926007729580U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 9715717805774537170U) + RotL64(aNonceWordG, 35U);
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 39U)) + 14360243844821619482U) + RotL64(aNonceWordC, 41U);
            aOrbiterF = ((aWandererG + RotL64(aCross, 4U)) + 10760908100206775334U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aScatter, 57U)) + 3434641779946167811U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 27U)) + 7885568822756234567U;
            aOrbiterI = (aWandererF + RotL64(aCross, 11U)) + 3041563437672051294U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15761355327564963516U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1158633562785937421U;
            aOrbiterK = RotL64((aOrbiterK * 15511324886867188235U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9338581575871970653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9172038894262857354U;
            aOrbiterF = RotL64((aOrbiterF * 3110871165285625807U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14653924713599790081U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3854497592598563309U;
            aOrbiterE = RotL64((aOrbiterE * 11737111068815795303U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16286980180327600557U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5092583772591249756U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13955105624639442903U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4288397994175567333U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15584236478994873104U;
            aOrbiterC = RotL64((aOrbiterC * 1860480595862755379U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 5557463939827483792U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordA, 48U);
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2659814275753280856U;
            aOrbiterB = RotL64((aOrbiterB * 17702430405693184643U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6941807963525063449U) + RotL64(aNonceWordD, 55U);
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2040598555191211307U;
            aOrbiterG = RotL64((aOrbiterG * 14750544987531722765U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 347572666231116258U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 779304821185302523U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14180254150318109855U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10632524582873079742U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9761308771280517212U;
            aOrbiterJ = RotL64((aOrbiterJ * 13926235411726048921U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 26U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 42U)) + aOrbiterD) + RotL64(aNonceWordF, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 3U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + RotL64(aNonceWordE, 61U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 12U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordB, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16254U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14206U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 51U) ^ RotL64(aNonceWordD, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15714U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10622U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 44U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 6469584119078165548U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 18U)) + 14329756366517987910U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 51U)) + 12890831797059772123U) + RotL64(aNonceWordF, 25U);
            aOrbiterA = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 3164503807500018990U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 39U)) + 177531431387646836U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 3167421392893561015U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 22U)) + 2813174781844753460U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 29U)) + 10953270419153249857U) + RotL64(aNonceWordH, 40U);
            aOrbiterJ = ((aWandererI + RotL64(aCross, 57U)) + 16911518309710356951U) + aPhaseCOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6616750447844893150U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10276741398025985982U;
            aOrbiterH = RotL64((aOrbiterH * 6824712685896987133U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6206043608461213208U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12021552904553405793U;
            aOrbiterD = RotL64((aOrbiterD * 10023362889960174909U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15283586234744144846U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5923238786775948571U;
            aOrbiterB = RotL64((aOrbiterB * 8200882393521882651U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11044014510971660078U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9351141024085076044U) ^ RotL64(aNonceWordA, 21U);
            aOrbiterG = RotL64((aOrbiterG * 13316079344614432317U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17703395981862992420U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10154548848376027087U;
            aOrbiterJ = RotL64((aOrbiterJ * 12324478347590509035U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8836420852291617425U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10193385413543886344U;
            aOrbiterI = RotL64((aOrbiterI * 824935982418585449U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8248580084535685190U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3910083671888152974U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17825311776715895927U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12350341628569930642U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2565977481575002842U;
            aOrbiterC = RotL64((aOrbiterC * 18233446879833776677U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9271041067874027417U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14289254596554201861U) ^ RotL64(aNonceWordG, 55U);
            aOrbiterE = RotL64((aOrbiterE * 7985522692852251413U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 40U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterG, 4U)) + aPhaseCWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterA, 53U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + RotL64(aNonceWordC, 47U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordD, 17U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterE, 34U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 26U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordD, 54U)) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23874U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 20783U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordE, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24220U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 16962U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 34U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 7075016829833562104U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 8783765886115517036U) + RotL64(aNonceWordB, 48U);
            aOrbiterF = (aWandererB + RotL64(aScatter, 42U)) + 2996723892384565829U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 9494134707342189476U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 47U)) + 5052642981395679904U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 35U)) + 8766787055127962238U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 3U)) + 4467211954388738079U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 60U)) + 8030255604633658608U) + RotL64(aNonceWordC, 53U);
            aOrbiterB = ((aWandererH + RotL64(aIngress, 29U)) + 16962408063455702251U) + aPhaseCOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3768222186567699076U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14930990410207899871U;
            aOrbiterF = RotL64((aOrbiterF * 10930005786146268241U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14179761938395502502U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1879084742719898108U;
            aOrbiterK = RotL64((aOrbiterK * 16783034788172670121U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5535012408925981515U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12792553516710295939U;
            aOrbiterH = RotL64((aOrbiterH * 8577530993755159329U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8979253163346099252U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5559189896063990740U;
            aOrbiterG = RotL64((aOrbiterG * 8832485423727331621U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13937564337299044079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2393376759689394948U;
            aOrbiterE = RotL64((aOrbiterE * 2352815657830413941U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12647519563697356479U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10946871249960389549U) ^ RotL64(aNonceWordH, 9U);
            aOrbiterD = RotL64((aOrbiterD * 6272580371881237173U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13376798695582123147U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10958115913599631271U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18233981473003345217U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4283914227806672773U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 910842005516235816U) ^ RotL64(aNonceWordD, 3U);
            aOrbiterA = RotL64((aOrbiterA * 6722229871617873429U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1509644316619370324U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 165987596716078174U;
            aOrbiterB = RotL64((aOrbiterB * 13600064054240185123U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 54U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterK, 12U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + RotL64(aNonceWordE, 13U));
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + aPhaseCWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 41U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + RotL64(aNonceWordF, 49U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 52U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordB, 51U)) ^ RotL64(aNonceWordF, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27926U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 30849U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordG, 23U)) ^ RotL64(aNonceWordH, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30331U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 29341U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = (((aWandererC + RotL64(aCross, 46U)) + RotL64(aCarry, 43U)) + 12122689833405846292U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 57U)) + 9640400270962766788U) + RotL64(aNonceWordG, 13U);
            aOrbiterF = (aWandererI + RotL64(aIngress, 11U)) + 9141937998266739071U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 12899395770434090537U;
            aOrbiterC = (aWandererF + RotL64(aCross, 41U)) + 13457918115408031842U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 3U)) + 15134784483576000943U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 23U)) + 12540961268790055438U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 35U)) + 6306886773092764230U) + RotL64(aNonceWordF, 57U);
            aOrbiterE = ((aWandererD + RotL64(aCross, 3U)) + 13573343491337243121U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8545588657348974413U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10891410570357275120U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5399310978367842841U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2877137119767060151U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9178097682386595144U) ^ RotL64(aNonceWordC, 39U);
            aOrbiterC = RotL64((aOrbiterC * 3524486002084427513U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15528007881855616978U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11368419529245281435U;
            aOrbiterJ = RotL64((aOrbiterJ * 12433207037378339309U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5932738914934356645U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5551842263864055419U;
            aOrbiterI = RotL64((aOrbiterI * 16093776759971522681U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3824433359595690603U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 17184628855571662441U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) ^ RotL64(aNonceWordD, 15U);
            aOrbiterH = RotL64((aOrbiterH * 691208053136187317U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8724462245014132623U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7481349499528092352U;
            aOrbiterD = RotL64((aOrbiterD * 8212182934509617583U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6908362960248294718U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5354057969992655314U;
            aOrbiterG = RotL64((aOrbiterG * 16586084885820679343U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11138301629323903147U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14164180536320940750U;
            aOrbiterE = RotL64((aOrbiterE * 9099767681053390287U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 709942920176922902U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17128241237359414945U;
            aOrbiterA = RotL64((aOrbiterA * 14063385518459963529U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 54U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterD, 48U)) + RotL64(aNonceWordE, 55U));
            aWandererG = aWandererG + ((((RotL64(aCross, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + RotL64(aCarry, 51U)) + RotL64(aNonceWordA, 38U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterC, 34U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFBBBD01BBF5D8829ULL + 0xF9FCF9E353AFC9F3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA5EB3F6A2E8D0213ULL + 0xEE2DC2E1F6990C09ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x92059B88FCF521EFULL + 0x981818BD761F75DDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA06FFF2186D4233FULL + 0xDAC14792B898FB19ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF4A17A752521DAB1ULL + 0xD3780EE4696E4FB6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9E72A2CC7D7FB441ULL + 0x999F32DF58EFF1BFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB47F25A3D0583EC3ULL + 0xD3B8D3307B6FA155ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDD56ADD1CC8E8FE3ULL + 0x8898EC70F97E2656ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordF, 3U)) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2369U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 712U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordG, 38U)) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4685U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1696U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 10U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 3U)) + 6318740973868639425U) + aPhaseDOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 53U)) + 5487840061430920881U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 10258706763248072672U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 14U)) + 18356875269730338208U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 12883160282903147010U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 57U)) + 1010140474942697730U) + RotL64(aNonceWordH, 11U);
            aOrbiterD = (aWandererB + RotL64(aCross, 27U)) + 17733939421700898293U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 41U)) + 13693055887924981201U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordB, 55U);
            aOrbiterH = (aWandererA + RotL64(aCross, 48U)) + 14574732452793385269U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 5U)) + 10832873941223609012U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 8212600587135328040U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5312744319781971178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6173741211706546923U;
            aOrbiterE = RotL64((aOrbiterE * 12854414066390848249U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3693249147883790810U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 18365859989736602556U;
            aOrbiterA = RotL64((aOrbiterA * 3348463719324104997U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10645056678337549771U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1175668356822251045U) ^ RotL64(aNonceWordA, 53U);
            aOrbiterB = RotL64((aOrbiterB * 6579675292775345579U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13556844570541823717U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4790355739411849736U) ^ RotL64(aNonceWordD, 59U);
            aOrbiterF = RotL64((aOrbiterF * 4083544011788850307U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14905575502272644116U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17047244574558476634U;
            aOrbiterD = RotL64((aOrbiterD * 2356386971503880047U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10161614295718414869U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13413914082651612468U;
            aOrbiterH = RotL64((aOrbiterH * 16224039093981079491U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6072693130156927774U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4333656233793103787U;
            aOrbiterG = RotL64((aOrbiterG * 9374745547133955709U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17209776289202130250U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11752001118070361543U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4416523594812872339U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15367365111105608277U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8650687767097460704U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11430451559660578667U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18074648514448405693U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10857586858462237581U;
            aOrbiterC = RotL64((aOrbiterC * 3722891011080095849U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17219932344278345591U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6318740973868639425U;
            aOrbiterJ = RotL64((aOrbiterJ * 8846295038878812229U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + RotL64(aNonceWordC, 22U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 57U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 39U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + RotL64(aNonceWordE, 25U)) + aPhaseDWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererC = aWandererC + ((((RotL64(aCross, 53U) + RotL64(aOrbiterE, 50U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterB, 24U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordF, 28U)) ^ RotL64(aNonceWordE, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8642U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 7234U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordA, 19U)) ^ RotL64(aNonceWordB, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9202U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9264U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 24U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererG + RotL64(aCross, 36U)) + 12380376990224645149U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 23U)) + 18296928500297384014U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 11U)) + 3550626816361145100U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 2667792936946706027U) + RotL64(aNonceWordA, 49U);
            aOrbiterC = (aWandererA + RotL64(aCross, 21U)) + 12020969779370926953U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 5U)) + 737340727886903447U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aScatter, 38U)) + RotL64(aCarry, 35U)) + 1681797651799760502U) + aPhaseDOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aPrevious, 13U)) + 2956186342689489064U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 41U)) + 1876852870402977177U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 29U)) + 6433205819353555071U) + RotL64(aNonceWordC, 41U);
            aOrbiterJ = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 9065076854974222998U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3254410578766789992U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2005081975473815576U;
            aOrbiterH = RotL64((aOrbiterH * 9947701153722014085U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15992999234834560419U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3458344156815120948U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1668460113964608051U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17069783053664877727U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1260234710193913099U;
            aOrbiterC = RotL64((aOrbiterC * 4561226779897414381U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3825186451876061335U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2905344294992827535U;
            aOrbiterA = RotL64((aOrbiterA * 2469896090698580795U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18141402347899180617U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8760129857609925066U;
            aOrbiterG = RotL64((aOrbiterG * 2507999156108123047U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 594052473780678210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13216719212966128379U;
            aOrbiterK = RotL64((aOrbiterK * 10691355329696722303U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10029948739466316169U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11912428807431992996U;
            aOrbiterB = RotL64((aOrbiterB * 85016510811938307U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8735634019801417287U) + RotL64(aNonceWordF, 27U);
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12785916159063273545U;
            aOrbiterF = RotL64((aOrbiterF * 1161917531260663357U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 367752057919802452U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3961036242431041564U;
            aOrbiterE = RotL64((aOrbiterE * 16352646009782597315U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3858415336170090719U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14325258358254321551U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12080431158781060059U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16872184337970977180U) + RotL64(aNonceWordH, 15U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12380376990224645149U;
            aOrbiterJ = RotL64((aOrbiterJ * 16559121155413059221U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 42U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + RotL64(aNonceWordG, 10U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 12U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + RotL64(aNonceWordD, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterC, 26U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 51U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 23U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 50U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordB, 48U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11103U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12171U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordC, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16235U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 14235U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 47U)) ^ (RotL64(aCross, 6U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 898812731947995389U) + RotL64(aNonceWordB, 58U);
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 48U)) + 8677347622525527167U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 770321564027567654U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 13U)) + 11020474858081526395U;
            aOrbiterI = (aWandererF + RotL64(aCross, 39U)) + 17289793580414993470U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 11U)) + 10111912559295118444U) + aPhaseDOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 8083622125544542011U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 23U)) + 7149858558922988240U) + RotL64(aNonceWordG, 11U);
            aOrbiterH = (aWandererD + RotL64(aIngress, 35U)) + 5919683821379905699U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 27U)) + 6860902846079238714U;
            aOrbiterD = (aWandererG + RotL64(aCross, 44U)) + 15083517836867542075U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14852868368708376381U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9860233289028878323U;
            aOrbiterG = RotL64((aOrbiterG * 13418143547952204667U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 772406119079116272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7971141501337627589U;
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8478568022896691911U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4027604850785607101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4826627523578901467U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17199331557841535430U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7515957656979776361U;
            aOrbiterI = RotL64((aOrbiterI * 5468950152869656599U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17138249294921502391U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16236812863923234668U;
            aOrbiterA = RotL64((aOrbiterA * 2925542836624164807U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16941524155859123682U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11240343728857342866U;
            aOrbiterC = RotL64((aOrbiterC * 7281012444214294659U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15163914964139858328U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6673576554415729652U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1558880328574736975U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5399050402101642989U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11806006719060024615U;
            aOrbiterF = RotL64((aOrbiterF * 15782156615926092159U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9812148913932011655U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 4737919734590584193U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2739737604370936959U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3415477403346468057U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5922725868927615919U) ^ RotL64(aNonceWordF, 7U);
            aOrbiterH = RotL64((aOrbiterH * 12390148483052777871U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17435294951520465659U) + RotL64(aNonceWordA, 39U);
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 898812731947995389U;
            aOrbiterD = RotL64((aOrbiterD * 17248379279729365007U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 24U);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 24U) + RotL64(aOrbiterC, 38U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aNonceWordD, 13U));
            aWandererH = aWandererH + ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + RotL64(aCarry, 37U)) + RotL64(aNonceWordE, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterE, 11U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterK, 19U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterF, 54U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordD, 48U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19004U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20132U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16505U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 16656U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 21U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aPrevious, 38U)) + 7651355040951791298U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 27U)) + 13988210277931659312U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 19U)) + 9846849412579537783U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 12746719939495876158U) + RotL64(aNonceWordC, 15U);
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 11498066185182895284U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 21U)) + 11101058955193080232U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 53U)) + 15513734459555672046U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 15711108675349394643U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 56U)) + 4771231759949468556U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 5U)) + 11449258010811305256U) + RotL64(aNonceWordE, 13U);
            aOrbiterH = (aWandererD + RotL64(aCross, 11U)) + 17036938391509986723U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6999245666776654250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2106819066263369528U;
            aOrbiterF = RotL64((aOrbiterF * 13005885810757743129U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12716183358903477216U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16752724547046059889U;
            aOrbiterE = RotL64((aOrbiterE * 11475905692393034141U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17623077680983093163U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6726003022297274986U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14709385877103232653U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2842410225096524740U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9235178377537910514U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11813751114775673845U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2619888019860844610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6295481948199619613U;
            aOrbiterG = RotL64((aOrbiterG * 15429161806953951205U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9724921158061115570U) + RotL64(aNonceWordH, 3U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4070976180958458679U;
            aOrbiterD = RotL64((aOrbiterD * 6080566609081811453U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5864247978960125554U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 7771249710071026757U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4787660062590737657U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15006900854988166845U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2755659268987119046U;
            aOrbiterH = RotL64((aOrbiterH * 8043939381186802359U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1922321482806966418U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13910818219761929659U;
            aOrbiterI = RotL64((aOrbiterI * 8895973123729951173U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7540972911473176026U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5419023469522423893U) ^ RotL64(aNonceWordB, 11U);
            aOrbiterJ = RotL64((aOrbiterJ * 1380429266266313945U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2349651834739320824U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7651355040951791298U;
            aOrbiterK = RotL64((aOrbiterK * 3713776056028698433U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 52U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 5U)) + RotL64(aNonceWordA, 35U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 14U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterE, 29U));
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 12U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 27U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + RotL64(aNonceWordG, 6U));
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 28U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 18U) ^ RotL64(aNonceWordE, 39U)) ^ RotL64(aNonceWordA, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23383U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23311U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordC, 47U)) ^ RotL64(aNonceWordB, 10U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23662U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 23716U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 40U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 47U)) + 11998579547770778580U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 60U)) + 8409465187298704610U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 27U)) + 3470222286110333500U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 53U)) + 5704486785203069994U) + aPhaseDOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordA, 3U);
            aOrbiterC = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 10334944660253279633U) + RotL64(aNonceWordH, 15U);
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 7626852700722567477U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 14631310754943209743U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 13U)) + 807160297237854120U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 11U)) + 5624154783624196107U;
            aOrbiterG = (aWandererA + RotL64(aCross, 6U)) + 4971444394698940423U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 43U)) + 6340057638461027062U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9003019862787819481U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13632057463595873033U) ^ RotL64(aNonceWordB, 13U);
            aOrbiterB = RotL64((aOrbiterB * 12575202147280216765U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12766104026871797746U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 4062118445824915939U) ^ RotL64(aNonceWordF, 23U);
            aOrbiterH = RotL64((aOrbiterH * 13130770039048080701U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5258212525426469978U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9956946981015983939U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8106382657040497669U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10837606223056473999U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13292864885504191134U;
            aOrbiterG = RotL64((aOrbiterG * 4445739587553669471U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 166087925900318658U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6786842221885441388U;
            aOrbiterJ = RotL64((aOrbiterJ * 4411147600413147773U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16888086378070246404U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5240855484445974002U;
            aOrbiterD = RotL64((aOrbiterD * 402652898573422271U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6874866669211571608U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 732890824978127460U;
            aOrbiterI = RotL64((aOrbiterI * 3776365957702257453U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5541380495707308058U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17947326584411475765U;
            aOrbiterE = RotL64((aOrbiterE * 10920952349981652899U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15060679340045767910U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1675974028461383576U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15127962310365242819U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 226889112033170368U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4290719734244011388U;
            aOrbiterF = RotL64((aOrbiterF * 6453598182035414143U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7712233480730639084U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11998579547770778580U;
            aOrbiterC = RotL64((aOrbiterC * 11599893373156816375U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 34U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + RotL64(aNonceWordC, 35U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 28U) + aOrbiterI) + RotL64(aOrbiterA, 21U)) + RotL64(aNonceWordG, 40U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterA, 50U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterE, 19U));
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 4U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + aPhaseDWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordF, 56U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28294U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27325U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 39U) ^ RotL64(aNonceWordG, 30U)) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27760U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31728U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 10U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 41U)) + 2330952702412094686U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 41U)) + 7820188225935060799U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 9347644591709839145U) + RotL64(aNonceWordC, 25U);
            aOrbiterB = (aWandererE + RotL64(aPrevious, 21U)) + 2288624878446846870U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 19U)) + 9358977729492824128U) + aPhaseDOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 39U)) + 1858511275052455039U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 47U)) + 13715478509322292552U) + RotL64(aNonceWordA, 43U);
            aOrbiterK = (aWandererC + RotL64(aIngress, 54U)) + 16413396625604260455U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 17714322215518432705U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 43U)) + 16188315436202861122U;
            aOrbiterC = (aWandererK + RotL64(aCross, 5U)) + 5564445841368207813U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13717068949900594673U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14143659432287313765U;
            aOrbiterD = RotL64((aOrbiterD * 17281441046722262917U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5729546141908425670U) + RotL64(aNonceWordE, 23U);
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4297827922736712074U;
            aOrbiterG = RotL64((aOrbiterG * 13631630436759768885U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 829520109395163673U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11547160328525174295U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4759690159673049775U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2907177944512117206U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11100346409065275671U;
            aOrbiterJ = RotL64((aOrbiterJ * 17927994356809011637U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1344592529249949068U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6470438516791143572U;
            aOrbiterK = RotL64((aOrbiterK * 13339390828725370475U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5217751823741520847U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5371275223586938039U) ^ RotL64(aNonceWordG, 8U);
            aOrbiterE = RotL64((aOrbiterE * 12318403075523724125U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14218103150268532919U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1367628876596800571U;
            aOrbiterH = RotL64((aOrbiterH * 13777531272321533137U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2372041991018455610U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9870744274890595581U;
            aOrbiterC = RotL64((aOrbiterC * 12093443117747395585U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15531376915156611594U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11166549148968363252U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10024372567841218915U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8555942275137258839U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3304132937209624841U;
            aOrbiterF = RotL64((aOrbiterF * 7965093976633155809U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14825330575158830172U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2330952702412094686U;
            aOrbiterB = RotL64((aOrbiterB * 9146641978165131495U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 36U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordH, 7U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 34U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 48U));
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aNonceWordB, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9A3F7651B5F3468FULL + 0xC7B3414BA82F85C4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD2B13D3F9BBD18EBULL + 0x9BC09078AF29E195ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x92F0F060E53D4443ULL + 0x8F195D3FFB0DBB4EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE4E198C9968F145FULL + 0xC83E90F5B1E60D86ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF81FE9F5C5A6DA71ULL + 0xE273D0026A0AF94DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC3DF7F7472BC29E5ULL + 0xEF8F868B3851998CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA3248940A9952D13ULL + 0xADC54EB4478DA032ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC7F5392193D8A4FBULL + 0xD7E17ECDB07D9792ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1024U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1289U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordC, 41U)) ^ RotL64(aNonceWordD, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2714U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3025U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 60U)) + 3917730204724097072U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 37U)) + 1874642340716212824U) + RotL64(aNonceWordF, 61U);
            aOrbiterB = (aWandererK + RotL64(aCross, 41U)) + 6900165757434854160U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 23U)) + 12750946097023807161U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 6563216048479513594U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 48U)) + 14960240191349450795U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 11U)) + 16306180275951788289U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 29U)) + 6502066618271045547U) + RotL64(aNonceWordE, 39U);
            aOrbiterG = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 6219852857850888738U) + aPhaseEOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 51U)) + 2272931312452845850U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 3028929882263199463U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6067393030073568112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10094809900437037258U;
            aOrbiterB = RotL64((aOrbiterB * 18095564940730322769U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5962414178157074575U) + RotL64(aNonceWordA, 57U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15755563045799129417U;
            aOrbiterH = RotL64((aOrbiterH * 3692603590609922031U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6321455513889880590U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1197435601998121700U;
            aOrbiterF = RotL64((aOrbiterF * 17693996266260557625U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12496949381666299968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6357070235648527030U;
            aOrbiterJ = RotL64((aOrbiterJ * 2931486644220862433U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8423760160877540210U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8090246492554850768U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2949407491181921633U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11436635942985063755U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17086363141014359856U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10504127577318206801U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10734017887545474935U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 375515325165740779U) ^ RotL64(aNonceWordB, 7U);
            aOrbiterC = RotL64((aOrbiterC * 9980486695448151709U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5217148491945389821U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14696058217023530058U;
            aOrbiterD = RotL64((aOrbiterD * 11026674782236654799U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11869055287836412650U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16951500118659983436U;
            aOrbiterK = RotL64((aOrbiterK * 4304372681583055077U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7866300390953569803U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 18017335943787362993U;
            aOrbiterA = RotL64((aOrbiterA * 15683049583437004889U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2477944286851267725U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3917730204724097072U;
            aOrbiterI = RotL64((aOrbiterI * 6617615984203047419U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE + ((RotL64(aScatter, 34U) + aOrbiterA) + RotL64(aOrbiterF, 53U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 44U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + RotL64(aNonceWordG, 36U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 37U)) + aOrbiterK) + RotL64(aNonceWordD, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 14U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordG, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7738U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10327U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordF, 52U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6671U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 8298U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 17019646486641172469U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 12276141179299971572U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 39U)) + 3617241694029841555U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 6967963401259371737U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 23U)) + 6340709284279891017U) + RotL64(aNonceWordE, 15U);
            aOrbiterK = ((aWandererD + RotL64(aScatter, 37U)) + 456065368903896482U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 53U)) + 17686765719908116203U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 21U)) + 1322045955429785736U) + RotL64(aNonceWordC, 47U);
            aOrbiterF = (aWandererH + RotL64(aPrevious, 51U)) + 5163772703302372887U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 14U)) + 13268431135020363252U;
            aOrbiterG = (aWandererK + RotL64(aCross, 19U)) + 6538789950366849332U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10390344544314544893U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5087084271300584267U;
            aOrbiterJ = RotL64((aOrbiterJ * 15149302947570776165U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13423071121590981727U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 18324443012024134729U) ^ RotL64(aNonceWordD, 5U);
            aOrbiterD = RotL64((aOrbiterD * 15814349432207734533U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4129091815978464507U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17024797553831962245U;
            aOrbiterA = RotL64((aOrbiterA * 3137753479364378175U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6501545108779991661U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11930037791867597447U;
            aOrbiterC = RotL64((aOrbiterC * 4904739567549702851U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4667298703308315851U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6315980380900062127U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12080555704907924637U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12732382340390769888U) + RotL64(aNonceWordF, 12U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7792095326183864547U;
            aOrbiterE = RotL64((aOrbiterE * 12645556660611824631U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17428384983571405782U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3193205313177048443U;
            aOrbiterH = RotL64((aOrbiterH * 14488006565106259731U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2813743367131107264U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2742138679703780981U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18356569025783532225U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6270291142961043031U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3490174937775044998U;
            aOrbiterB = RotL64((aOrbiterB * 13879285210885619613U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13182535825771438942U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13047228760732694484U;
            aOrbiterI = RotL64((aOrbiterI * 10365428317468779549U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17926326514553542739U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17019646486641172469U;
            aOrbiterG = RotL64((aOrbiterG * 13978838314848228053U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 20U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 46U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + RotL64(aNonceWordB, 3U));
            aWandererE = aWandererE + ((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + RotL64(aNonceWordA, 55U));
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 27U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 40U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererC, 50U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordD, 27U)) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13761U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 16065U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordG, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12586U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15564U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 47U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 51U)) + 13204735390996728477U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 26U)) + RotL64(aCarry, 3U)) + 851171359595647173U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 53U)) + 16745304202825290723U) + aPhaseEOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 562392736584913979U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 3244267012529053918U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 21U)) + 17282536111067869133U) + RotL64(aNonceWordB, 9U);
            aOrbiterJ = (aWandererC + RotL64(aCross, 11U)) + 14851130066471729068U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 58U)) + 5256130407952363129U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + 2904742485828362001U) + aPhaseEOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 13U)) + 3723346325449225387U) + RotL64(aNonceWordF, 22U);
            aOrbiterK = (aWandererD + RotL64(aScatter, 47U)) + 5344621093694027341U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12919263300833603026U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17989801264160996071U;
            aOrbiterG = RotL64((aOrbiterG * 15468293047311883751U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 5022175042377172157U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordA, 39U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16684822380107847758U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2834049270263837537U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2740326510600876682U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13981423865219318820U;
            aOrbiterI = RotL64((aOrbiterI * 14593082145080056441U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 231945878229848395U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14139797734944312580U;
            aOrbiterC = RotL64((aOrbiterC * 6492256080432266407U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16704102101387552373U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8506734780526852552U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4684566118627414659U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2774630043988894695U) + RotL64(aNonceWordG, 17U);
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12490034334296488127U;
            aOrbiterB = RotL64((aOrbiterB * 16765455396278233145U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 545238171291436006U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1023872898002379590U;
            aOrbiterH = RotL64((aOrbiterH * 8626333831510136515U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5065187021047872560U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10391809965648089863U;
            aOrbiterE = RotL64((aOrbiterE * 10912471108849550469U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5576919045471579002U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9761904001375034639U;
            aOrbiterJ = RotL64((aOrbiterJ * 8612901811320541361U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2001472279505185946U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11576457012366242134U;
            aOrbiterF = RotL64((aOrbiterF * 1070815118051466731U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17713147845216099336U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13204735390996728477U;
            aOrbiterK = RotL64((aOrbiterK * 10889281795183444943U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 50U));
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterI, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 34U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 18U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterB, 37U)) + RotL64(aNonceWordE, 37U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + RotL64(aNonceWordC, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterK, 27U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 20U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordB, 5U)) ^ RotL64(aNonceWordA, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18376U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20314U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 50U) ^ RotL64(aNonceWordG, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16945U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17100U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 20U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aScatter, 11U)) + 7651355040951791298U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 13988210277931659312U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 9846849412579537783U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 48U)) + 12746719939495876158U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 35U)) + 11498066185182895284U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 57U)) + 11101058955193080232U) + RotL64(aNonceWordB, 25U);
            aOrbiterJ = (aWandererI + RotL64(aScatter, 3U)) + 15513734459555672046U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 5U)) + 15711108675349394643U) + aPhaseEOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 4771231759949468556U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 43U)) + 11449258010811305256U) + RotL64(aNonceWordF, 45U);
            aOrbiterD = (aWandererJ + RotL64(aIngress, 54U)) + 17036938391509986723U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6999245666776654250U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2106819066263369528U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13005885810757743129U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12716183358903477216U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16752724547046059889U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11475905692393034141U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17623077680983093163U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6726003022297274986U;
            aOrbiterB = RotL64((aOrbiterB * 14709385877103232653U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2842410225096524740U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9235178377537910514U;
            aOrbiterJ = RotL64((aOrbiterJ * 11813751114775673845U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2619888019860844610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6295481948199619613U) ^ RotL64(aNonceWordH, 43U);
            aOrbiterG = RotL64((aOrbiterG * 15429161806953951205U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9724921158061115570U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4070976180958458679U;
            aOrbiterA = RotL64((aOrbiterA * 6080566609081811453U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5864247978960125554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7771249710071026757U) ^ RotL64(aNonceWordC, 23U);
            aOrbiterK = RotL64((aOrbiterK * 4787660062590737657U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15006900854988166845U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2755659268987119046U;
            aOrbiterD = RotL64((aOrbiterD * 8043939381186802359U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1922321482806966418U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13910818219761929659U;
            aOrbiterF = RotL64((aOrbiterF * 8895973123729951173U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7540972911473176026U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5419023469522423893U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1380429266266313945U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2349651834739320824U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7651355040951791298U;
            aOrbiterC = RotL64((aOrbiterC * 3713776056028698433U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 4U) + aOrbiterK) + RotL64(aOrbiterE, 14U));
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 37U)) + RotL64(aNonceWordD, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 5U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 24U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + RotL64(aNonceWordE, 28U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 36U) + aOrbiterB) + RotL64(aOrbiterH, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 40U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordE, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26711U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24201U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 44U) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26862U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26504U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 22U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 51U)) + 17711946802293254150U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 57U)) + 16652362590489569378U) + RotL64(aNonceWordA, 19U);
            aOrbiterH = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 6972810344198183097U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 14U)) + 13117100889782940546U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 13199305696782626591U;
            aOrbiterA = (aWandererB + RotL64(aCross, 5U)) + 992156184392760945U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 23U)) + 13791265442074543880U;
            aOrbiterI = ((((aWandererA + RotL64(aPrevious, 54U)) + RotL64(aCarry, 35U)) + 17057087245252294859U) + aPhaseEOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordH, 30U);
            aOrbiterB = ((aWandererE + RotL64(aIngress, 37U)) + 13444195995883541046U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 3U)) + 6723678233676059420U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 19U)) + 7913379431208430475U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4481887195529300665U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11892724101424384078U;
            aOrbiterH = RotL64((aOrbiterH * 3468639499716604111U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7700902083270424194U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1888001433557140271U;
            aOrbiterA = RotL64((aOrbiterA * 8975562955027025349U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14996753906788986929U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 939004845422123765U;
            aOrbiterI = RotL64((aOrbiterI * 2507090308972292313U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11922230289291941807U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15681187459741147199U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10124947739653819101U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9119043713532718155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8327697433992362166U;
            aOrbiterC = RotL64((aOrbiterC * 11157657162184304567U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13630755116592440359U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 771252613886022889U;
            aOrbiterG = RotL64((aOrbiterG * 2958918915223536519U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 8524239721467527770U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordF, 57U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17732617735422435572U;
            aOrbiterD = RotL64((aOrbiterD * 13992947983987668631U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5265753270696005619U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14456128349522985053U;
            aOrbiterB = RotL64((aOrbiterB * 5406509991740849617U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12909993509014176457U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10113568710432654194U;
            aOrbiterF = RotL64((aOrbiterF * 6857806395910432831U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14818978163348513071U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17843349910031998923U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13608449524810499593U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12589077818524017161U) + RotL64(aNonceWordD, 13U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17711946802293254150U;
            aOrbiterE = RotL64((aOrbiterE * 9454569713107675231U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 22U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 23U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterK) + RotL64(aNonceWordE, 7U)) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 28U)) + aOrbiterJ) + RotL64(aNonceWordC, 21U));
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 52U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + aPhaseEWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordE, 53U)) ^ RotL64(aNonceWordB, 24U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30772U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 32081U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordC, 47U)) ^ RotL64(aNonceWordG, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27313U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29561U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 28U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 6163290588946759209U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 23U)) + 7342672468560105447U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 41U)) + 11574563167017282321U) + RotL64(aNonceWordD, 35U);
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 2254820206194758964U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 46U)) + RotL64(aCarry, 47U)) + 1469783447473099498U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 39U)) + 14174828900676165088U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 43U)) + 16277954291890598132U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 21U)) + 14845750668693136766U) + aPhaseEOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 27U)) + 150099699692047766U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 53U)) + 1200784917165131703U) + RotL64(aNonceWordH, 9U);
            aOrbiterI = (aWandererA + RotL64(aPrevious, 14U)) + 9469982764806754302U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10956702761701710182U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7915506894975487807U;
            aOrbiterA = RotL64((aOrbiterA * 8874108311712727983U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17335794183733623213U) + RotL64(aNonceWordB, 14U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 557028996286989506U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3993359298602424281U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1597385667771002414U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4376417959915162639U;
            aOrbiterK = RotL64((aOrbiterK * 4626236858205178149U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 549770198518993876U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 756554555648070919U;
            aOrbiterD = RotL64((aOrbiterD * 16272320259614325355U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7298557532533152193U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3336802611342112013U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14679103452120080499U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2314938232094714365U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12215066333571149153U;
            aOrbiterG = RotL64((aOrbiterG * 10747052773052630601U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7762752719356805046U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6519429915769040078U;
            aOrbiterH = RotL64((aOrbiterH * 15548676502167938513U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 7556691736109752918U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13731245903412646404U;
            aOrbiterI = RotL64((aOrbiterI * 15581965016668635409U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5910925625723735162U) + RotL64(aNonceWordF, 11U);
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16037704866415841869U;
            aOrbiterB = RotL64((aOrbiterB * 11628217027073824759U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12605882248192797360U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9579778913978981884U;
            aOrbiterE = RotL64((aOrbiterE * 5372577227818787957U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6063171520266734946U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6163290588946759209U;
            aOrbiterF = RotL64((aOrbiterF * 291843698316138251U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 50U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterK) + RotL64(aNonceWordC, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + RotL64(aNonceWordA, 49U));
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterH, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterE, 44U)) + aPhaseEWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 38U) + RotL64(aOrbiterF, 39U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_WaterPolo_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD058D54642E72BD7ULL + 0xD9F1BEAA59C16140ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEA143DE601412777ULL + 0xDD4BDB50A8B3B0FCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8E207385979DAA4DULL + 0xB8BAF87868D78F21ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFE2F8A8761DDB7E5ULL + 0xFB02599F4EB4F9C2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x97CF8C0F070B316BULL + 0xCD79271D27EA0F53ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x827A63CC24890859ULL + 0x821EF25F4EF1135CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xACE99ED4BBF67B8BULL + 0xD00892A2A3C99A26ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDD79317B396C7D91ULL + 0xE2DF1D05751B95A5ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 53U) ^ RotL64(aNonceWordA, 27U)) ^ RotL64(aNonceWordC, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1773U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3995U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordE, 30U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4986U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1515U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererI + RotL64(aIngress, 14U)) + 3236820517816085022U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 19U)) + 741288875914097926U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 43U)) + 8417246926007729580U) + aPhaseFOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordD, 29U);
            aOrbiterC = (aWandererK + RotL64(aCross, 23U)) + 9715717805774537170U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 14360243844821619482U;
            aOrbiterE = (aWandererF + RotL64(aCross, 39U)) + 10760908100206775334U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 27U)) + 3434641779946167811U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordB, 41U);
            aOrbiterF = (aWandererH + RotL64(aPrevious, 3U)) + 7885568822756234567U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 50U)) + RotL64(aCarry, 41U)) + 3041563437672051294U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 57U)) + 15761355327564963516U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 1158633562785937421U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9338581575871970653U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9172038894262857354U;
            aOrbiterI = RotL64((aOrbiterI * 3110871165285625807U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 14653924713599790081U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordF, 54U);
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3854497592598563309U;
            aOrbiterE = RotL64((aOrbiterE * 11737111068815795303U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16286980180327600557U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5092583772591249756U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13955105624639442903U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4288397994175567333U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15584236478994873104U;
            aOrbiterC = RotL64((aOrbiterC * 1860480595862755379U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5557463939827483792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2659814275753280856U;
            aOrbiterK = RotL64((aOrbiterK * 17702430405693184643U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6941807963525063449U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2040598555191211307U;
            aOrbiterH = RotL64((aOrbiterH * 14750544987531722765U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 347572666231116258U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 779304821185302523U;
            aOrbiterB = RotL64((aOrbiterB * 14180254150318109855U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10632524582873079742U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9761308771280517212U;
            aOrbiterG = RotL64((aOrbiterG * 13926235411726048921U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2097439707055737964U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2813977930321463948U;
            aOrbiterD = RotL64((aOrbiterD * 14983538728730662603U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6080592019313796689U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5396623654821376409U;
            aOrbiterF = RotL64((aOrbiterF * 15478858835919398677U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8460497459575045342U) + RotL64(aNonceWordC, 27U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3236820517816085022U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5530411244458067093U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 38U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 10U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterA, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 47U));
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aCarry, 35U)) + RotL64(aNonceWordH, 11U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aNonceWordG, 23U));
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 6U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 12U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 4U) ^ RotL64(aNonceWordC, 57U)) ^ RotL64(aNonceWordA, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5689U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9328U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordH, 54U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10352U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 6520U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 42U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 19U)) + 12632404972795375757U) + RotL64(aNonceWordG, 13U);
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 39U)) + 5351879979055988456U) + RotL64(aNonceWordD, 17U);
            aOrbiterD = (aWandererB + RotL64(aScatter, 37U)) + 3597737727467443413U;
            aOrbiterC = (aWandererF + RotL64(aCross, 11U)) + 2830846754917852318U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 17311925960294518018U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 2083584640523695383U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 5U)) + 15049343611387010158U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 35U)) + 6443050378205811147U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 13U)) + 6021965178697344070U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 23U)) + 5080289878758029976U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 28U)) + 576927745306972983U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4728489691382690859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6184355840165758855U;
            aOrbiterD = RotL64((aOrbiterD * 1515043910404156423U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11220539885798595450U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11091438724966718214U;
            aOrbiterH = RotL64((aOrbiterH * 8225347114759391961U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17184210490020062419U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2150997767099116408U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8058553821648892499U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7021953562676903717U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17159676348343312834U;
            aOrbiterG = RotL64((aOrbiterG * 13877284519668483549U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10367891770525239784U) + RotL64(aNonceWordE, 12U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11922478487264201233U;
            aOrbiterK = RotL64((aOrbiterK * 9195137452661956029U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17815162358981720634U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9582631251085100284U) ^ RotL64(aNonceWordH, 59U);
            aOrbiterA = RotL64((aOrbiterA * 11838992994130850483U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 872593750259572264U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17832330100262167302U;
            aOrbiterC = RotL64((aOrbiterC * 1114416841510028467U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16601139856969287418U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14931287111691324985U;
            aOrbiterI = RotL64((aOrbiterI * 16757174577841001179U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11413072442039115924U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15253605470589905889U;
            aOrbiterB = RotL64((aOrbiterB * 10832817442285245673U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3653487723581514107U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14891378240114471865U;
            aOrbiterJ = RotL64((aOrbiterJ * 1386594204573386051U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15659724464711852035U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12632404972795375757U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2407347385127296647U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 40U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aNonceWordF, 43U));
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 39U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterE, 46U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + RotL64(aNonceWordB, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordG, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12303U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 15695U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordB, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12873U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13456U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 40U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aCross, 37U)) + 13924571355038625040U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 21U)) + 16328300979357156658U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 19U)) + 3947771961206012461U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 60U)) + 15428284250569311285U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 57U)) + 5777369485254032486U) + RotL64(aNonceWordD, 51U);
            aOrbiterF = (aWandererF + RotL64(aCross, 47U)) + 16813320300717644673U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 11U)) + 16689933050200758251U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 1856422419049390708U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 14U)) + 18214498743831925517U) + aPhaseFOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 18278550878494094923U) + RotL64(aNonceWordH, 57U);
            aOrbiterC = (aWandererH + RotL64(aPrevious, 11U)) + 797712062039591797U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15854849439012341347U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 996882939768167773U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14936703950807908575U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3005829974130671692U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8793495343509953906U;
            aOrbiterF = RotL64((aOrbiterF * 14065479348374612031U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7710453029930631112U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9511995836117707047U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7250766204781428201U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 670902975693341744U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9045820304668279777U;
            aOrbiterG = RotL64((aOrbiterG * 18373074917532639027U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12417212387607119470U) + RotL64(aNonceWordA, 3U);
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12816983560669985622U;
            aOrbiterD = RotL64((aOrbiterD * 8406003970221889847U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17245432086377688540U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6806521945548502014U;
            aOrbiterH = RotL64((aOrbiterH * 11335859481858640857U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8947500746292365294U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4468060468522895852U;
            aOrbiterI = RotL64((aOrbiterI * 7022481284816599797U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9892975931958803992U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3042599331526937836U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3308512896171443645U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12991568221485810891U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8551331172836260315U;
            aOrbiterJ = RotL64((aOrbiterJ * 4509997595920847057U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 183547209633334407U) + RotL64(aNonceWordB, 37U);
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17275712817092769452U;
            aOrbiterA = RotL64((aOrbiterA * 15677355290000929085U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12743863879392372723U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13924571355038625040U;
            aOrbiterC = RotL64((aOrbiterC * 11966689345179279407U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 52U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 10U) + aOrbiterD) + RotL64(aOrbiterJ, 50U));
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + RotL64(aNonceWordC, 40U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterA, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterE, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterK, 60U)) + RotL64(aNonceWordE, 9U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererF, 18U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 10U) ^ RotL64(aNonceWordG, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20438U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18984U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordH, 21U)) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21518U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((aIndex + 21304U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 7948891781097675369U) + RotL64(aNonceWordG, 28U);
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 18U)) + RotL64(aCarry, 53U)) + 13928362874228230226U) + RotL64(aNonceWordA, 35U);
            aOrbiterC = ((aWandererB + RotL64(aIngress, 57U)) + 10776180542602258926U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 5735115172149470447U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 3U)) + 5353591822981766987U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 43U)) + 562301708107268570U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 5U)) + 10467810247578364868U;
            aOrbiterF = (aWandererG + RotL64(aCross, 35U)) + 14541630141152308564U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 51U)) + 2350076897065139429U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 10U)) + 17519109078651162228U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 13U)) + 6061035173339902910U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15654836633731000065U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13723521735153718904U;
            aOrbiterC = RotL64((aOrbiterC * 14459516479283070563U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2849680038315532197U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17336102435576647923U;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7671010488872356142U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11485114338165600777U) ^ RotL64(aNonceWordB, 45U);
            aOrbiterI = RotL64((aOrbiterI * 4162584865462407791U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8759060657343458985U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11009137869375286581U;
            aOrbiterK = RotL64((aOrbiterK * 8741417343929809115U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15792999392743144135U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6180808423175992479U;
            aOrbiterF = RotL64((aOrbiterF * 13681230339693676907U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 361487389591183005U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15292753806514404853U;
            aOrbiterA = RotL64((aOrbiterA * 17478232597253311153U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14929153438443362045U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7904556383593914086U;
            aOrbiterD = RotL64((aOrbiterD * 2484130486635511403U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3793180909904286848U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10391957637467171320U;
            aOrbiterH = RotL64((aOrbiterH * 505484041943467117U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11648765065563798353U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17601185776537566611U) ^ RotL64(aNonceWordF, 31U);
            aOrbiterE = RotL64((aOrbiterE * 4753179291885740011U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2907499704986356444U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17048858067202291241U;
            aOrbiterG = RotL64((aOrbiterG * 2607549567999666889U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4340465159886930775U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7948891781097675369U;
            aOrbiterJ = RotL64((aOrbiterJ * 12913104720552907335U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 54U) + aOrbiterI) + RotL64(aOrbiterD, 26U)) + RotL64(aNonceWordE, 15U)) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + RotL64(aNonceWordD, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 11U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterD, 38U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererA, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordG, 34U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23320U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23934U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 47U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordB, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24286U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 26988U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 57U)) + 9471546960258473684U) + RotL64(aNonceWordF, 27U);
            aOrbiterC = (((aWandererA + RotL64(aCross, 46U)) + RotL64(aCarry, 39U)) + 18050235435948942244U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 3005107102671544641U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 3U)) + 17898396434573801850U) + RotL64(aNonceWordB, 24U);
            aOrbiterJ = (aWandererH + RotL64(aIngress, 13U)) + 15071602525497771648U;
            aOrbiterH = (aWandererB + RotL64(aCross, 20U)) + 5780119462702672108U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 53U)) + 13301326224151025687U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 5U)) + 18129323022260575961U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 1199228670638790709U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 51U)) + 1839199978088021020U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 43U)) + 4999517042246790165U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8788607633376516299U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15143903839930468749U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12735914889325422675U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16674732686428431869U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15908873150953195581U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18049755517524334107U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11204775359756474667U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2525984309543939465U;
            aOrbiterI = RotL64((aOrbiterI * 3988529812023791571U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4566345170476825512U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14876612901557406267U;
            aOrbiterF = RotL64((aOrbiterF * 9047956948845135339U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14926290877038883931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12710203178186614846U;
            aOrbiterE = RotL64((aOrbiterE * 14841163494801662515U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7315094513967387996U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11050116830482816766U) ^ RotL64(aNonceWordC, 49U);
            aOrbiterG = RotL64((aOrbiterG * 3702999495721152019U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4505368486032503953U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17905748055257551092U;
            aOrbiterD = RotL64((aOrbiterD * 14775870175093453197U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5728886950801376350U) + RotL64(aNonceWordA, 15U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17998141690182325170U;
            aOrbiterA = RotL64((aOrbiterA * 16008599930125391379U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4325978018819134558U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13526905108565989379U;
            aOrbiterB = RotL64((aOrbiterB * 14121321495714166291U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10597169665474269506U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7500801022830471869U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3702717219742363777U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17063616328548689935U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9471546960258473684U;
            aOrbiterJ = RotL64((aOrbiterJ * 3029748230803396737U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 56U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterA, 36U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterD, 23U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + RotL64(aNonceWordD, 51U));
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 46U) + aOrbiterG) + RotL64(aOrbiterJ, 39U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 10U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + RotL64(aNonceWordH, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 28U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordH, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30497U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31640U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 46U) ^ RotL64(aNonceWordD, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28411U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 31253U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aPrevious, 29U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererJ + RotL64(aIngress, 14U)) + 9914837590440975587U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 6706125076401958051U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 16570817772679258409U) + RotL64(aNonceWordA, 24U);
            aOrbiterG = (aWandererE + RotL64(aPrevious, 37U)) + 6843705658115186948U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 16099930446791572351U;
            aOrbiterH = (aWandererI + RotL64(aCross, 19U)) + 5420550009556030459U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 44U)) + 5729549069420177477U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 3U)) + 15590601126188675834U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 27U)) + 13044027390998620029U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 5U)) + 11068338135659636772U) + RotL64(aNonceWordF, 29U);
            aOrbiterC = (aWandererC + RotL64(aScatter, 51U)) + 6584988841809544332U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8516813219883915404U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10647314042912492785U;
            aOrbiterI = RotL64((aOrbiterI * 15559481057047148785U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 201691689889605304U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15512161798401184003U;
            aOrbiterK = RotL64((aOrbiterK * 11473219183982564709U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3883760518944464145U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 13861805129175491145U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ RotL64(aNonceWordD, 37U);
            aOrbiterH = RotL64((aOrbiterH * 17194438894492581181U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12019138626550801486U) + RotL64(aNonceWordG, 41U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13030350224959652248U;
            aOrbiterF = RotL64((aOrbiterF * 11724200983306280107U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2643807255422544248U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4127143302485631794U;
            aOrbiterA = RotL64((aOrbiterA * 5441038881111578487U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14602951930809633069U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4555737199162278494U;
            aOrbiterE = RotL64((aOrbiterE * 12415825635220991865U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6343143902997169834U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10404783711336491985U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6235474458879439079U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7406959231434835393U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6684368109277850196U;
            aOrbiterC = RotL64((aOrbiterC * 8760360417572331159U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4835889355927954728U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7917682889852676712U;
            aOrbiterB = RotL64((aOrbiterB * 9045350756570117327U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10268055422944417055U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5563744562922937643U;
            aOrbiterD = RotL64((aOrbiterD * 12442484191329795173U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17244672945880141679U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9914837590440975587U;
            aOrbiterG = RotL64((aOrbiterG * 12269340309792850489U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 10U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterB, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 41U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterF, 18U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 6U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + RotL64(aCarry, 41U)) + RotL64(aNonceWordH, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 37U)) + aOrbiterD) + RotL64(aNonceWordC, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB8C2E2808214BF2DULL + 0xE5AC1C764440936EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCB62C1A2286C2DA1ULL + 0xF980E50CE00228E4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF6B50D21361B3153ULL + 0xEC91594F647574B2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB58928902D8910D7ULL + 0xE8057FC65CFF2375ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE7D2ABD2F487F941ULL + 0x92B4AC825C67C0C6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA29574FB19201AD5ULL + 0xBDA2DDA70FF2F129ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9C211DB64DC37BD3ULL + 0xEC9FD2FF48E6A85DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9347A736A08F1BC1ULL + 0xB5FFE5BF5BD0B2C1ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordA, 56U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1650U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 58U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordC, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1124U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3658U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 54U)) + 3621877681473089725U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 23U)) + 4451752751536414717U) + RotL64(aNonceWordE, 61U);
            aOrbiterC = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 11371625415377772117U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 6046792758881150619U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 29U)) + 8213166120394461682U;
            aOrbiterK = (aWandererG + RotL64(aCross, 19U)) + 4343156661140422645U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 5U)) + 11105271483234947905U) + aPhaseFOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 3U)) + 348904609985341372U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 12924652822526858767U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 42U)) + 7461211697358520287U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 57U)) + 16551553555297890558U) + RotL64(aNonceWordB, 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11908056404140782995U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9147367258259948715U;
            aOrbiterC = RotL64((aOrbiterC * 10777628928376261667U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8876461054692728610U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10546855952702525404U;
            aOrbiterK = RotL64((aOrbiterK * 10071104785895309677U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4748636139110443794U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 783046909529525098U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8969157702460927215U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16683965945838696665U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12385412690177109575U;
            aOrbiterG = RotL64((aOrbiterG * 10795062772707143187U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8210546822184469023U) + RotL64(aNonceWordH, 45U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13146493623236979963U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13199947810161148155U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13857628148804187115U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7241297989337473475U;
            aOrbiterH = RotL64((aOrbiterH * 16223448508809614229U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 773904571213804946U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7660676598236419707U;
            aOrbiterA = RotL64((aOrbiterA * 14467390638468925567U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16822672435156055469U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6514707119190640433U) ^ RotL64(aNonceWordG, 46U);
            aOrbiterE = RotL64((aOrbiterE * 7097496727567460535U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17784153215885060832U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16027189961519690419U;
            aOrbiterD = RotL64((aOrbiterD * 3248782394761733169U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 821916530432611671U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8764650990196504963U;
            aOrbiterB = RotL64((aOrbiterB * 6269514974278082251U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5987370764866753332U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3621877681473089725U;
            aOrbiterI = RotL64((aOrbiterI * 14763908964222787377U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 60U));
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 6U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + RotL64(aNonceWordD, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 53U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + RotL64(aNonceWordF, 31U));
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 36U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 10U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 10U) ^ RotL64(aNonceWordD, 27U)) ^ RotL64(aNonceWordC, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5588U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8456U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordB, 40U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8851U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10050U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 10U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 6469584119078165548U) + aPhaseFOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 14329756366517987910U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 10U)) + 12890831797059772123U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 3U)) + 3164503807500018990U;
            aOrbiterF = (aWandererA + RotL64(aCross, 35U)) + 177531431387646836U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 27U)) + 3167421392893561015U) + RotL64(aNonceWordC, 53U);
            aOrbiterK = (aWandererG + RotL64(aScatter, 46U)) + 2813174781844753460U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 53U)) + 10953270419153249857U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 16911518309710356951U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 57U)) + 6616750447844893150U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 39U)) + 10276741398025985982U) + RotL64(aNonceWordG, 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6206043608461213208U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12021552904553405793U;
            aOrbiterB = RotL64((aOrbiterB * 10023362889960174909U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15283586234744144846U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5923238786775948571U;
            aOrbiterG = RotL64((aOrbiterG * 8200882393521882651U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11044014510971660078U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9351141024085076044U) ^ RotL64(aNonceWordD, 11U);
            aOrbiterF = RotL64((aOrbiterF * 13316079344614432317U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17703395981862992420U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10154548848376027087U;
            aOrbiterK = RotL64((aOrbiterK * 12324478347590509035U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8836420852291617425U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10193385413543886344U;
            aOrbiterD = RotL64((aOrbiterD * 824935982418585449U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8248580084535685190U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3910083671888152974U;
            aOrbiterI = RotL64((aOrbiterI * 17825311776715895927U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12350341628569930642U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 2565977481575002842U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) ^ RotL64(aNonceWordA, 41U);
            aOrbiterC = RotL64((aOrbiterC * 18233446879833776677U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9271041067874027417U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14289254596554201861U;
            aOrbiterE = RotL64((aOrbiterE * 7985522692852251413U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5981802134118235214U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14047813418129636856U;
            aOrbiterA = RotL64((aOrbiterA * 15961435325216504877U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11808443842149398212U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11380858372643695792U;
            aOrbiterH = RotL64((aOrbiterH * 100198424024622179U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10385375464069162356U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6469584119078165548U;
            aOrbiterJ = RotL64((aOrbiterJ * 5263876933019848989U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterI, 60U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterB, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + RotL64(aNonceWordB, 51U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 21U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordE, 46U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 54U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aIngress, 48U) + aOrbiterC) + RotL64(aOrbiterG, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterG, 37U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordE, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14164U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13498U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15865U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((aIndex + 11453U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 52U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 47U)) + 17074147006464019918U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 10559516626129419928U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 56U)) + 13280363679503946221U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 53U)) + 17657115422132457413U;
            aOrbiterE = (aWandererF + RotL64(aCross, 13U)) + 13325837013304973008U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 41U)) + 3059707750486106037U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 5U)) + 4529045702503050852U) + RotL64(aNonceWordF, 7U);
            aOrbiterD = (aWandererG + RotL64(aScatter, 21U)) + 10726578475550904292U;
            aOrbiterC = ((((aWandererA + RotL64(aIngress, 38U)) + RotL64(aCarry, 27U)) + 14832537837996659885U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1]) + RotL64(aNonceWordD, 5U);
            aOrbiterF = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 220094417441809246U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 11U)) + 15343130035105342194U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 16592263353426409884U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordC, 25U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15649290906447931918U;
            aOrbiterH = RotL64((aOrbiterH * 8405875177836650731U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11437410545843708269U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5859769136073011444U;
            aOrbiterK = RotL64((aOrbiterK * 1065016088086441107U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15188064100307340341U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4367466521843260049U;
            aOrbiterJ = RotL64((aOrbiterJ * 15916715854192820923U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8482617283860566845U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2585745804937342972U;
            aOrbiterE = RotL64((aOrbiterE * 8267269625632139809U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1687641344403425541U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13667916445979421400U;
            aOrbiterD = RotL64((aOrbiterD * 8191322670355590027U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7684258716388029228U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14764266202380443369U;
            aOrbiterF = RotL64((aOrbiterF * 1746254773647650741U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12685190466981675661U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9958374400222383893U;
            aOrbiterB = RotL64((aOrbiterB * 12696606920219838929U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1352584794098160330U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16057453941015251708U;
            aOrbiterA = RotL64((aOrbiterA * 6051546505117202495U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5642244742563733299U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2946279435712646692U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3711867103848631343U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17305358424001395035U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1831722001182742673U;
            aOrbiterC = RotL64((aOrbiterC * 13867284970939557547U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12354430852596737299U) + RotL64(aNonceWordE, 30U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17074147006464019918U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17316050599218057961U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterI, 5U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 10U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + RotL64(aNonceWordA, 61U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterC, 29U));
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 24U)) + aOrbiterB) + RotL64(aNonceWordG, 19U));
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 41U) ^ RotL64(aNonceWordH, 14U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18485U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 17711U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordF, 12U)) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20412U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 20754U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 50U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 6U)) + 3255291173184001106U) + RotL64(aNonceWordE, 50U);
            aOrbiterA = (aWandererG + RotL64(aIngress, 53U)) + 15308468160116255528U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 27U)) + 18186972408589866656U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 29U)) + 4439324265978331914U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 57U)) + 13099263173016322486U) + aPhaseFOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 7041561081767500660U) + RotL64(aNonceWordB, 31U);
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 6196422612687812971U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 7664260932541281413U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 51U)) + 17802347823020441056U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 11U)) + 4253107484061190446U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 38U)) + 13799496534030645312U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14252892847595951926U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5663527578664291422U;
            aOrbiterF = RotL64((aOrbiterF * 18314294235895182465U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11148755959699137661U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17036900929333594592U;
            aOrbiterD = RotL64((aOrbiterD * 16041243617369003291U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2403828181385259549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17813580350434928194U;
            aOrbiterC = RotL64((aOrbiterC * 13666780980793857831U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5623611126885414523U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7293224381174846969U;
            aOrbiterJ = RotL64((aOrbiterJ * 7032561584670788117U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10602620906929686163U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 18015916257203385982U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10684090189688871993U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13592915735376305773U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13995866908043417505U;
            aOrbiterH = RotL64((aOrbiterH * 3802175869395887331U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8200465989447697618U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9866671660800629464U;
            aOrbiterB = RotL64((aOrbiterB * 2138851839905326265U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11557528777230608777U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 131060617338185060U;
            aOrbiterG = RotL64((aOrbiterG * 11068705423012265209U), 23U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 13404720733342982167U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordH, 11U);
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13128574378042136042U;
            aOrbiterE = RotL64((aOrbiterE * 5805270317312187011U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15879295432652112238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9433361543323748909U;
            aOrbiterA = RotL64((aOrbiterA * 3592390041363796221U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6262775775981534941U) + RotL64(aNonceWordF, 47U);
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3255291173184001106U;
            aOrbiterK = RotL64((aOrbiterK * 2748492753337241005U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 56U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterJ, 34U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + aPhaseFWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 10U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 37U)) + aOrbiterA) + RotL64(aNonceWordC, 19U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + RotL64(aNonceWordA, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 18U) ^ RotL64(aNonceWordD, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26665U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26542U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordE, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26565U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22758U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 7825479804710770560U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 5298124167101358123U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 29U)) + 17774541024369233726U) + aPhaseFOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 37U)) + 7679371833537454082U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 3U)) + 5385914900748772224U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 18U)) + 3879781930908486531U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 51U)) + 659110346638873236U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 10749021728538539749U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 39U)) + 3631252455767429457U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordF, 55U);
            aOrbiterB = (aWandererG + RotL64(aCross, 48U)) + 2271978810960685021U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 5U)) + 5963558780692551176U) + RotL64(aNonceWordG, 22U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 974909966119198104U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9296998242911152296U;
            aOrbiterF = RotL64((aOrbiterF * 2613629915877957661U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2245318466901521959U) + RotL64(aNonceWordC, 15U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13391076374843288568U;
            aOrbiterC = RotL64((aOrbiterC * 18094558036982107419U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6184487746594236737U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1563385912137291418U;
            aOrbiterK = RotL64((aOrbiterK * 4805455299959232321U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1744840092006498629U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2100927276837188416U;
            aOrbiterB = RotL64((aOrbiterB * 3541788262067077997U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9998911862807246338U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12239948725635220096U;
            aOrbiterG = RotL64((aOrbiterG * 7098620484129489129U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3307447094994950246U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12746613971448298932U;
            aOrbiterA = RotL64((aOrbiterA * 9463975886346934681U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11577488293733790649U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 191108997585598809U;
            aOrbiterJ = RotL64((aOrbiterJ * 9574978681405356871U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18096145693841273722U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10026281133603934071U;
            aOrbiterI = RotL64((aOrbiterI * 17261343107314203471U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2346682418062064668U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2996178204018644206U;
            aOrbiterD = RotL64((aOrbiterD * 2552965800703390909U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 15085425896818988223U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1589593231782852588U;
            aOrbiterE = RotL64((aOrbiterE * 1535556765195388675U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17170695588248383518U) + RotL64(aNonceWordB, 11U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7825479804710770560U;
            aOrbiterH = RotL64((aOrbiterH * 7434218282170150533U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 48U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 30U) + aOrbiterG) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 60U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + RotL64(aNonceWordA, 43U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterI, 37U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + RotL64(aNonceWordH, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 12U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordD, 58U)) ^ RotL64(aNonceWordF, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31594U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30941U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordB, 12U)) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29083U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31136U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 27U)) + (RotL64(aCarry, 42U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aIngress, 37U)) + 9914837590440975587U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 11U)) + 6706125076401958051U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 27U)) + 16570817772679258409U) + aPhaseFOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 13U)) + 6843705658115186948U;
            aOrbiterD = ((((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 16099930446791572351U) + aPhaseFOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + RotL64(aNonceWordH, 59U);
            aOrbiterI = (aWandererA + RotL64(aIngress, 56U)) + 5420550009556030459U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 47U)) + 5729549069420177477U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 15590601126188675834U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 13044027390998620029U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 20U)) + 11068338135659636772U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 39U)) + 6584988841809544332U) + RotL64(aNonceWordD, 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8516813219883915404U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10647314042912492785U;
            aOrbiterC = RotL64((aOrbiterC * 15559481057047148785U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 201691689889605304U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15512161798401184003U;
            aOrbiterD = RotL64((aOrbiterD * 11473219183982564709U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3883760518944464145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13861805129175491145U;
            aOrbiterI = RotL64((aOrbiterI * 17194438894492581181U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 12019138626550801486U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordB, 18U);
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13030350224959652248U;
            aOrbiterH = RotL64((aOrbiterH * 11724200983306280107U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2643807255422544248U) + RotL64(aNonceWordG, 17U);
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4127143302485631794U;
            aOrbiterF = RotL64((aOrbiterF * 5441038881111578487U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14602951930809633069U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4555737199162278494U;
            aOrbiterK = RotL64((aOrbiterK * 12415825635220991865U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6343143902997169834U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10404783711336491985U;
            aOrbiterB = RotL64((aOrbiterB * 6235474458879439079U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7406959231434835393U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6684368109277850196U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8760360417572331159U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4835889355927954728U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7917682889852676712U;
            aOrbiterA = RotL64((aOrbiterA * 9045350756570117327U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10268055422944417055U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5563744562922937643U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12442484191329795173U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17244672945880141679U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9914837590440975587U;
            aOrbiterE = RotL64((aOrbiterE * 12269340309792850489U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 14U)) + aOrbiterG) + RotL64(aNonceWordA, 51U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterK, 41U));
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + RotL64(aNonceWordE, 19U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 60U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 38U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 640U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2890U)) & W_KEY1], 30U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1512U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 7579U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 57U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 6U)) + 1087148170018530502U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 51U)) + 15530846874509311414U) + aPhaseCOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 23U)) + 16987358651515511212U;
            aOrbiterD = (aWandererI + RotL64(aCross, 35U)) + 12504143181007924259U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 29U)) + 393322117322732418U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 14325937299241887166U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 14U)) + 9395262907017475742U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 13658510441418344769U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 6410754322737005336U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9257290738538818434U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7489828960857692286U;
            aOrbiterA = RotL64((aOrbiterA * 16519674788777989043U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4118778591214588387U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16619215231168796563U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14876884956536265157U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11326283811003573430U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1865401866017614604U;
            aOrbiterK = RotL64((aOrbiterK * 8378326058282460073U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 670150121105733604U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1499331510641068749U;
            aOrbiterC = RotL64((aOrbiterC * 16623742535540383107U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1116410848560838532U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2696841341036281779U;
            aOrbiterI = RotL64((aOrbiterI * 9598953298074904869U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5487352391229549881U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12008243050943342979U;
            aOrbiterD = RotL64((aOrbiterD * 9087261224804582459U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 552859665927882960U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8426942688524814473U;
            aOrbiterH = RotL64((aOrbiterH * 10916963622695549105U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1613287981244830815U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15592897923468694288U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6600750586743893303U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7629853970631002676U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13778028957247561272U;
            aOrbiterG = RotL64((aOrbiterG * 4063798788229605659U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterI, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 58U)) + aOrbiterH) + aPhaseCWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8453U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 8225U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15480U)) & W_KEY1], 36U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12898U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererD + RotL64(aCross, 19U)) + 11177787645248006236U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 14U)) + 3808340254579817169U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 53U)) + 828030667598518279U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 16177835921238398371U;
            aOrbiterC = (aWandererK + RotL64(aCross, 39U)) + 5518747735458708741U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 29U)) + 17346319082399995165U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 6397156921893030937U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 15559381654710713582U) + aPhaseCOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 29U)) + 940404446491415088U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8047166032048732645U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4688468645859470491U;
            aOrbiterI = RotL64((aOrbiterI * 14383536431614496369U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3710878044770337260U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 116343189456629220U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5637725064169289339U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 883908030159391659U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 18058691521694880482U;
            aOrbiterH = RotL64((aOrbiterH * 3132200449123497619U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17521015077103586117U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3668332225435714918U;
            aOrbiterJ = RotL64((aOrbiterJ * 12658899101297839881U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12229480388278883300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16206524049491531816U;
            aOrbiterK = RotL64((aOrbiterK * 11122340196620859805U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5743265849441077466U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2812293020719282236U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8903956475200417109U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13718364781538837074U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 861529717259766236U;
            aOrbiterG = RotL64((aOrbiterG * 17019744777211266685U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4862687502126693872U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7722024283321020761U;
            aOrbiterF = RotL64((aOrbiterF * 18086944039541060829U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8205803118233399853U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15130160926615050422U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1454552751453996765U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 30U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 53U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 22U)) + aOrbiterF) + aPhaseCWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterB, 57U));
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 46U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18380U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 18632U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 24305U)) & W_KEY1], 20U) ^ RotL64(aKeyRowReadB[((aIndex + 22339U)) & W_KEY1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererB + RotL64(aIngress, 10U)) + 12692813903177772178U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 7112496446691277899U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 23U)) + 2112247138290568813U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 5U)) + 3699421080882855947U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 19U)) + 13761832028354380922U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 47U)) + 9243822514887600214U) + aPhaseCOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 6863833516853046129U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 8863897995943098018U;
            aOrbiterH = (aWandererE + RotL64(aCross, 60U)) + 13346785686701467520U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15309543066305531619U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17515530938817919111U;
            aOrbiterJ = RotL64((aOrbiterJ * 16625193986319048245U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 760493237816424254U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7282586354117620860U;
            aOrbiterI = RotL64((aOrbiterI * 2327153408185290635U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4129706068526969105U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7020175432730888755U;
            aOrbiterC = RotL64((aOrbiterC * 10095158356907592239U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9102258982216515596U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10822031305361453690U;
            aOrbiterF = RotL64((aOrbiterF * 2036205056490578491U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12571477440964330246U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 8436347026653095199U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17930734781213681573U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 14214789872073941940U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12915911919403385001U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13161681603528031511U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15443240166233851298U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7311369180113240915U;
            aOrbiterD = RotL64((aOrbiterD * 13339195007946889423U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12976516224995960015U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7823308381434556721U;
            aOrbiterB = RotL64((aOrbiterB * 502385172763861451U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4829417661664149137U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16306394751966719700U;
            aOrbiterH = RotL64((aOrbiterH * 5294376579588592157U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 6U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 56U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterI, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31018U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 24628U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26420U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30034U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 34U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererF + RotL64(aPrevious, 23U)) + 13915875634607599122U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 43U)) + 1695770381382411673U) + aPhaseCOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 3709105579778295511U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 52U)) + 7673376335333251804U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 35U)) + 8814147709738503518U) + aPhaseCOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 13451412605350381172U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 29U)) + 6447870234069609538U;
            aOrbiterB = (aWandererE + RotL64(aCross, 57U)) + 13419487997946496825U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 6U)) + RotL64(aCarry, 43U)) + 5478309847615220345U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3635184969215610049U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12527903812035294828U;
            aOrbiterJ = RotL64((aOrbiterJ * 12540800512035534967U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1684685110885338814U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12860354576326835090U;
            aOrbiterI = RotL64((aOrbiterI * 12743745087733307255U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9081823570147481835U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14369321778210049109U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17865953349448767035U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11518132079084873250U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11893535026126957389U;
            aOrbiterC = RotL64((aOrbiterC * 15751374986135615095U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7084079180579206226U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2999676609847603277U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14602698397511266403U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17683445810614029153U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11576460512964896969U;
            aOrbiterE = RotL64((aOrbiterE * 5243651036457051155U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13429800604736567949U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14661785761747367546U;
            aOrbiterB = RotL64((aOrbiterB * 4765843989277333421U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12837164345582888950U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6222666313184669392U;
            aOrbiterA = RotL64((aOrbiterA * 17402483466567712319U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5358647039491079457U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12459911673401497180U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13605465035256188065U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 40U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterE, 42U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 37U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterB, 46U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 28U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 43U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6045U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 6747U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6569U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 1067U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 47U)) + 16160838483846078448U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 56U)) + 15404960896190227946U) + aPhaseDOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 16904160594024977199U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 17790460246821031802U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 16395168254086971959U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7484373204039901786U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 18026814691322913510U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12688155753775099489U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15244817793136966450U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5795491730356335666U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13253529465289332171U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3163873518027801504U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2690791759507349172U;
            aOrbiterI = RotL64((aOrbiterI * 16677948635136515083U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 17898067251167087906U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8028010015006604239U;
            aOrbiterG = RotL64((aOrbiterG * 5601629670521300241U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7304739457289910555U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6476837815096530043U;
            aOrbiterF = RotL64((aOrbiterF * 16380545138701113267U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 56U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 47U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterG, 10U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8957U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16114U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11407U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 10017U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 44U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aCross, 37U)) + 9133751643283278896U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 8971581804375380408U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 12559650383714566592U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 15753206088872859163U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 58U)) + 7640756270450762350U) + aPhaseDOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7340073357551376125U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5270256573644196046U;
            aOrbiterD = RotL64((aOrbiterD * 13286406906662922841U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3567367996479995928U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11939634537492733738U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5640541900117183639U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 7051817732424527120U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1730487669951837941U;
            aOrbiterA = RotL64((aOrbiterA * 15191634337956285841U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 18009252467909454817U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2361024272031696442U;
            aOrbiterE = RotL64((aOrbiterE * 15215151562500226027U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15902755877642960397U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12243517544704116184U;
            aOrbiterI = RotL64((aOrbiterI * 2576071074148141447U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 10U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22968U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23346U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22377U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((aIndex + 22697U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 4U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 56U)) + 15316464782468770057U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 6642872057476351588U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 660732654689529192U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 7235418086884000655U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 13U)) + 14784518476694580493U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12222433977933449375U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8573001207708329927U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17771120145431297541U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16035256260815013172U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15767726974121910203U;
            aOrbiterK = RotL64((aOrbiterK * 719060452537759331U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17712217935322939971U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13488963456923357159U;
            aOrbiterD = RotL64((aOrbiterD * 16785285630840310405U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10222949131965611079U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1495561412321657209U;
            aOrbiterJ = RotL64((aOrbiterJ * 9706305581868526265U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16156530750584361434U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7773792489045606309U;
            aOrbiterB = RotL64((aOrbiterB * 10730624207715601393U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aScatter, 22U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 56U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 24750U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((aIndex + 30373U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30432U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30826U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 5295352595333316211U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 39U)) + 2341795367042042605U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 10122175780504033663U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 10084612804696198554U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 12U)) + 16470424309851045971U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 656016130975227994U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15313268829659834317U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3553315008401417123U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3795220914993923394U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14044442220988813825U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3270650852546606835U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3804224626734584802U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7980006306010255693U;
            aOrbiterI = RotL64((aOrbiterI * 13958505239726088561U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13746830564584711549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11852212099729274845U;
            aOrbiterK = RotL64((aOrbiterK * 2164880979318247855U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9083223471018084847U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13706723820703853346U;
            aOrbiterH = RotL64((aOrbiterH * 11361854103656219887U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterK, 12U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterA, 21U));
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 4U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + aPhaseDWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4448U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 866U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3250U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 365U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 15188686795415908074U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 50U)) + RotL64(aCarry, 57U)) + 17310049041983079779U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 8246925977992441471U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aCross, 35U)) + 8644260919918112781U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 5U)) + 13401663736874819483U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 29U)) + 7940358935238314973U;
            aOrbiterD = (aWandererC + RotL64(aCross, 57U)) + 13278990328548007839U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11346868298353840706U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2374077904806833579U;
            aOrbiterH = RotL64((aOrbiterH * 1765686942154321425U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6978903378645019166U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11951633297870965212U;
            aOrbiterC = RotL64((aOrbiterC * 12778236598654492185U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17398460995357409673U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1215437945597836770U;
            aOrbiterJ = RotL64((aOrbiterJ * 9322970054123481621U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1878751468043972239U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5343002808239712390U;
            aOrbiterD = RotL64((aOrbiterD * 11878640995447558811U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9884918450053276861U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15894599082080422550U;
            aOrbiterA = RotL64((aOrbiterA * 8359936745539546131U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13917339232771145459U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 18101134009493720683U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15835859435306756387U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3830086372356903769U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15894394599564584010U;
            aOrbiterE = RotL64((aOrbiterE * 9513921913446609263U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterC, 21U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aPhaseEWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 37U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterC, 46U)) + aOrbiterD) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererC, 10U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10166U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15424U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11277U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16034U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aCross, 11U)) + 15904465836916519864U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 17725629806317789307U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 57U)) + 13794170125914914828U) + aPhaseEOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 2149055907476874332U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 19U)) + 5342047776745074649U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 44U)) + RotL64(aCarry, 57U)) + 8268148484060546838U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 29U)) + 10821151364028563719U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4294213820894407378U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10884726101307943090U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1116128870387229159U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16432210042202444824U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15196602644336228055U;
            aOrbiterB = RotL64((aOrbiterB * 12680438355124070237U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14117787670220328165U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 219833877949480215U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10736293047771972173U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3326396981881473962U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14918513066311426279U;
            aOrbiterI = RotL64((aOrbiterI * 14269763278564574663U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11795234681370163206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3068267285352664813U;
            aOrbiterE = RotL64((aOrbiterE * 15746255933920904619U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 245233356957999496U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 709926406353796673U;
            aOrbiterA = RotL64((aOrbiterA * 13627039596842073595U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5378105439430271038U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10114555061122044430U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5351295043424885549U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterK, 42U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 12U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterK, 29U));
            aWandererI = aWandererI + (((RotL64(aIngress, 22U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 58U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22451U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21502U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20246U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 22509U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 58U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aScatter, 5U)) + 252059974543142812U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 57U)) + 11690823093681457368U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 13U)) + 13282189752890971123U) + aPhaseEOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 9507416294305708435U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 24U)) + 14053038174390776539U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 14605253312318725009U) + aPhaseEOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 18138286582677863671U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8530091235978489988U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14381731677571170073U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11675896999665768253U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13316413456378978456U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3910529530149320706U;
            aOrbiterC = RotL64((aOrbiterC * 16000139333493588429U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6302070286831566901U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12324134652758551396U;
            aOrbiterB = RotL64((aOrbiterB * 17136438281540250165U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4773478557638475048U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 4031153435446078944U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3876928995240982769U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3114794895962903899U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3552936509969106796U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16823186892738820299U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5828754613946145627U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17985241114076114558U;
            aOrbiterF = RotL64((aOrbiterF * 1986669631395606833U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11319331046368072261U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6104267020171882160U;
            aOrbiterG = RotL64((aOrbiterG * 12525117969211576177U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27355U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31613U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27098U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 30077U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 52U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 3199575576585871314U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 3U)) + 2533378188975571824U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 6819782112558312658U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 11U)) + 12690060987724798497U;
            aOrbiterB = (aWandererG + RotL64(aCross, 27U)) + 7088375139715629606U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 20U)) + 17785618677423695666U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 1714999280296491277U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17611338506932491624U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6475727359297421201U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15133348244242438069U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2347744591204119530U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2739317903351401068U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15435029315209475631U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8663535261373274338U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8205245127823536479U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13857005110466856439U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8916510616749754516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3944805940148512932U;
            aOrbiterB = RotL64((aOrbiterB * 18082271583211389701U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14094751253118853302U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14094299829196076311U;
            aOrbiterA = RotL64((aOrbiterA * 6370012560657108493U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3940673811518673802U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3015106523254484839U;
            aOrbiterH = RotL64((aOrbiterH * 9655401190755573379U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15404103131982599922U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1828655763233900875U;
            aOrbiterI = RotL64((aOrbiterI * 13024358077740310049U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 51U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 54U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterC, 44U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 153U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 4916U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2628U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3311U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 44U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 1898718075389870739U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 4U)) + 5631794889237247403U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 18219714659484524607U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 15419581386225732921U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 35U)) + 9125575431710198210U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12205871520544965505U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7617534300497343422U;
            aOrbiterG = RotL64((aOrbiterG * 10052675719887595625U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 18017579105368135814U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10693882161946020042U;
            aOrbiterA = RotL64((aOrbiterA * 2326507900303932855U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11669615701700895306U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11045110212889232165U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5965171269273719849U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18019107802806469913U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12315940560472528716U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4505122470351404065U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4899009736070044310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17412253404253730364U;
            aOrbiterF = RotL64((aOrbiterF * 10791901166391946485U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 44U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aScatter, 10U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10362U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14663U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11778U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16150U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 35U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 28U)) + RotL64(aCarry, 53U)) + 2617613537256538553U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 57U)) + 16642868916835132715U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 10860291124337073254U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 6432511273906902472U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 37U)) + 7505375005848241910U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11086616004678821329U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3298830587569881951U;
            aOrbiterF = RotL64((aOrbiterF * 4304047944073454489U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9775143140064220979U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4147601326580823120U;
            aOrbiterK = RotL64((aOrbiterK * 13462244678782260871U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12245920269898100415U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8391940489176734499U;
            aOrbiterG = RotL64((aOrbiterG * 9119606167674098007U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17876893379544668477U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18301882058180370541U;
            aOrbiterJ = RotL64((aOrbiterJ * 16680384667098921309U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6869225862715140102U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15404118372589259800U;
            aOrbiterC = RotL64((aOrbiterC * 5766851935950389915U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 20U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 11U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 21U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 34U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 12U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19300U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16403U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17691U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 18228U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 1364174714924216027U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 27U)) + 13561796874229506613U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 12U)) + 11845572344206238305U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 15762708240326773763U) + aPhaseFOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 1157119665207900473U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6823546624372055260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14465564210523945121U;
            aOrbiterA = RotL64((aOrbiterA * 10957323253786161255U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10667464548080807531U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13445737493224316575U;
            aOrbiterH = RotL64((aOrbiterH * 12137295000900795711U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3009837893785957665U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2886920524111083752U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15308180928967762543U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10886177449328249656U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15067759884678100433U;
            aOrbiterB = RotL64((aOrbiterB * 5724566815989860041U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 18307930462682331536U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8791864377579255801U;
            aOrbiterI = RotL64((aOrbiterI * 9265158882471421767U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterA, 24U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 30U) + RotL64(aOrbiterI, 53U)) + aOrbiterD) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27491U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((aIndex + 25942U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28353U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 26312U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 11U)) + 13714409587461539863U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 14101156723903265839U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 7063754562895369001U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 50U)) + 12320578575245519386U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 11744826789631008424U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8744816505096675597U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10405435520084528645U;
            aOrbiterK = RotL64((aOrbiterK * 13279521344071568023U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1463157688070683543U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12379603577919617703U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14858901470015109311U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1343439118031348146U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16118850268070235540U;
            aOrbiterC = RotL64((aOrbiterC * 11184386483735388257U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14116264435819277136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5251698273012432109U;
            aOrbiterH = RotL64((aOrbiterH * 1495818611622063967U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14806408656041403829U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11569345414052398227U;
            aOrbiterG = RotL64((aOrbiterG * 9913158908301414861U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 18U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterI, 46U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 34U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 1325U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7390U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3821U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((aIndex + 7878U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 42U) + RotL64(aPrevious, 21U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aIngress, 4U)) + 9751314027302668907U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 37U)) + 12175450995523107056U) + aPhaseGOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 17519694958730119552U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 9093525527925682263U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + 3713831321786810138U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10108355209191835040U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12956307447311314768U;
            aOrbiterA = RotL64((aOrbiterA * 9198936928658626667U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1904298513945877359U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4658049993308574460U;
            aOrbiterD = RotL64((aOrbiterD * 10482422152074338611U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9826333658248851902U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12058666914724365134U;
            aOrbiterI = RotL64((aOrbiterI * 964233873188373939U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2516574707110528099U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13335308331049750235U;
            aOrbiterK = RotL64((aOrbiterK * 5880227828760598587U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8230749255538495304U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16536559486797811486U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7097036838156464969U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aIngress, 12U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 56U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + aPhaseGWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 8261U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8679U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10944U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10090U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 34U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 11274974230580265396U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 54U)) + RotL64(aCarry, 5U)) + 16658438747342741547U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 16612986966106053844U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 13U)) + 9329502236843231290U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 5U)) + 14088261356708344656U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13692608802007789581U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6824473946645682398U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13619437545775237601U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2072915876348570040U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7420507753044460759U;
            aOrbiterE = RotL64((aOrbiterE * 13239288539564571257U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4677557318688502593U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15081678577055628459U;
            aOrbiterJ = RotL64((aOrbiterJ * 16659305295251177155U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7026792817486507482U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14871665922943969918U;
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6807734532159292872U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17882797335141303280U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + aPhaseGWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 28U)) + aOrbiterG) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 21545U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 23339U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19972U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21439U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererG + RotL64(aIngress, 20U)) + RotL64(aCarry, 39U)) + 8685374557928800912U) + aPhaseGOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 3482312691892161229U;
            aOrbiterD = (aWandererC + RotL64(aCross, 5U)) + 6948130297389161165U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 5506385663788942690U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 47U)) + 17859982009307397161U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9178488809207094043U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1835479501226057169U;
            aOrbiterD = RotL64((aOrbiterD * 5671861318767342087U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5368101733632614939U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9050459666576835422U;
            aOrbiterE = RotL64((aOrbiterE * 10351719549990259551U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9042186993119635078U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17528342580198295025U;
            aOrbiterA = RotL64((aOrbiterA * 14316671546614386775U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6495418332558436882U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8834495762667327342U;
            aOrbiterB = RotL64((aOrbiterB * 10783141541937645995U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4364314196965690905U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6357485231062120459U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 289429584586504995U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterB, 44U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + aPhaseGWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 31633U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25191U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25998U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 26996U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 16519040829220310189U) + aPhaseGOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 6888002778416941825U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 4U)) + RotL64(aCarry, 27U)) + 1310832187746534025U) + aPhaseGOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 5890888009051281674U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 57U)) + 5143864838362464857U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15591534069452660003U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1466867671765325096U;
            aOrbiterK = RotL64((aOrbiterK * 1277202105237572301U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13931443680107902488U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15400747367673245552U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7011651369456453127U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2836975369734495759U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2370720358274970117U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4615571902817575375U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3470677184188006133U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7175584278499266723U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10067096593682482345U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6095078817776863055U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2176637999243513070U;
            aOrbiterI = RotL64((aOrbiterI * 12215701810843975501U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + aPhaseGWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 38U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7374U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 5929U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5338U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2500U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 50U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 17225673071833726819U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 10301458382103627331U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 30U)) + 3960233050857362414U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 43U)) + 17768665685046605837U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 14471018461213959767U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10730597892721340453U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14863394003122760542U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17731557030589257169U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9948587274816688296U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3573569431435100993U;
            aOrbiterF = RotL64((aOrbiterF * 2303922230056523077U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8153670675740450590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16438856577722561424U;
            aOrbiterA = RotL64((aOrbiterA * 4689247488336908827U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15765587867581925041U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1082039522061775213U;
            aOrbiterB = RotL64((aOrbiterB * 17023740047246402641U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4202521649260798876U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15877659681260461141U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11369910758551088173U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterF, 38U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 10924U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 8794U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11080U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10332U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 2786079456995203065U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 37U)) + 7237256119153857253U) + aPhaseHOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 9310834010563647604U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 17361734905706517877U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 20U)) + 15837111231884647451U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18065431964418026445U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3029123922999952652U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16309219658285890145U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5166926595573507837U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1918425684273807598U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16616641579714896719U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4724551751012661440U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1818014487579644390U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14904092108647864911U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6670090372241084216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8485757110007268693U;
            aOrbiterG = RotL64((aOrbiterG * 11876760095108618363U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4928130251509514742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2528788422725346792U;
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 5U)) + aOrbiterK) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterG, 60U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + aPhaseHWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18303U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22167U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23472U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19468U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 39U)) + (RotL64(aCarry, 54U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 58U)) + 7960325128608297381U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 12773836012104052042U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 3173972621347773016U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 3708401356314308171U;
            aOrbiterA = (aWandererC + RotL64(aCross, 23U)) + 950774285720019449U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4170092315705438265U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17000449130864980747U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7710635557693533263U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8793910540062893860U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 520277969543516469U;
            aOrbiterK = RotL64((aOrbiterK * 4150613128885828229U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12762214857389827271U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2932451184340207695U;
            aOrbiterC = RotL64((aOrbiterC * 7513337346940091655U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11062179998786293839U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7919119215271524178U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9053677007180081359U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1774988449597115155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3799792889466518953U;
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 30U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 44U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 25336U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 27285U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26012U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 25278U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 13U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 4739486756133131180U) + aPhaseHOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 16089707555501328184U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 41U)) + 15310047330238536453U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 7901411596386834955U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 11U)) + 4357555491060982163U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 15667085602825720102U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8520635334382269253U;
            aOrbiterA = RotL64((aOrbiterA * 7348648918661047791U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1772509779231068315U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15336170957886025677U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10996880551392077399U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8628770833489469980U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15469234024247246228U;
            aOrbiterI = RotL64((aOrbiterI * 8905266995119987947U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10796430900884288328U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10660110397012853289U;
            aOrbiterG = RotL64((aOrbiterG * 9140007610912037461U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11202284258711214794U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17509491802893182994U;
            aOrbiterB = RotL64((aOrbiterB * 9329107599972703671U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterI, 34U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 13U);
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
