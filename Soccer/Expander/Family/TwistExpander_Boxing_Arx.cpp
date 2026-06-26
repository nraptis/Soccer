#include "TwistExpander_Boxing_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Boxing_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAA52D910ED81B921ULL + 0x8692100CA4C02F16ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE6AF27A251841BFDULL + 0xE064ECF8032CA94AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8B7FD415FB208275ULL + 0xDDF75FAABBCF8A92ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA9F45D04E43A8A6FULL + 0x9319F1D1D5C92FCAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB2AD4FF57CDAEC37ULL + 0xEA75C95270416380ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAB0571CD9A3973B1ULL + 0x865693B481F3B60DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBCF34E1CA4C78D7BULL + 0xCB1B2073DCB3008CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDD7331EAB5FEFF47ULL + 0x9C6782E7C42C1CC4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x907241448C338147ULL + 0xDEA9AF6655F4F13DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEE84B8B8790B8D2FULL + 0xB4E04BFFEC46CAC4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB2B81F207D8ED46DULL + 0xC541E08C8AE308C5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEB33F0B791CEA813ULL + 0xDE83BD37DC80EA6FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA6CAA9B51EB5C8FBULL + 0x82E2E175722E2EE3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB965D6BBD50A9EDBULL + 0xD8A3FAC735189D38ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBAA08C9555592A99ULL + 0xC159FFC4C717B934ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF202D69C9A5468EBULL + 0xE436BFB3AE950592ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2335U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 297U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3110U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4894U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 37U)) + 6771552164800695068U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 3U)) + 12131763371571322040U;
            aOrbiterG = (aWandererE + RotL64(aCross, 14U)) + 3326182381395522013U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 29U)) + 12288775097697156383U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 41U)) + 5195948373449796741U) + aNonceWordP;
            aOrbiterD = ((((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 14404044002250137144U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aWandererA + RotL64(aScatter, 11U)) + 11142382920035825426U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 2967149520256475485U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 21U)) + 1470907369577818097U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 24U)) + 9231668148004163910U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 13078929163913892386U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9485274692075657877U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12216951187543631673U;
            aOrbiterG = RotL64((aOrbiterG * 6571066246507310805U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6933334652581744234U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17260276102423580920U;
            aOrbiterD = RotL64((aOrbiterD * 7796879893790990605U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 387767848169714392U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8597538259308082638U;
            aOrbiterI = RotL64((aOrbiterI * 4888054690557707241U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7996708724489146033U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15357384191688149939U;
            aOrbiterJ = RotL64((aOrbiterJ * 9827691726832491373U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17739222908739454637U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1614322333281471170U;
            aOrbiterE = RotL64((aOrbiterE * 7063116837752240891U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4531604274893197209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3453280714992341288U;
            aOrbiterK = RotL64((aOrbiterK * 8390029711127907805U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 116623650872661533U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6565636510115095988U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9691897067492501177U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10303258439817808058U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10917642773040237611U;
            aOrbiterC = RotL64((aOrbiterC * 10232856828372963363U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2087058228468680821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3691125545393861889U;
            aOrbiterA = RotL64((aOrbiterA * 1768745056298937903U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9240209357066002219U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7645250700232422804U;
            aOrbiterH = RotL64((aOrbiterH * 6762116797395687607U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9859862257084218280U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6771552164800695068U;
            aOrbiterF = RotL64((aOrbiterF * 11063630807191661109U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 18U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 26U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 13U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterD, 46U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9434U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8666U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 10884U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10236U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 37U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 13U)) + 826930775230515406U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 39U)) + 5137814617363250861U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 14761561947426681616U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 41U)) + 12773023438753662590U) + aNonceWordD;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 24U)) + RotL64(aCarry, 11U)) + 7331345852207096322U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 43U)) + 3899381212671247460U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 35U)) + 10072004147620068599U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 19U)) + 3424585039401897560U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 51U)) + 8246760141625966321U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 37U)) + 3655992860610853290U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 10U)) + RotL64(aCarry, 43U)) + 11154618022505863898U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15629361991059709973U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10842068502278489664U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17223002513104960799U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5571312349016336686U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 589313823745748879U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 1356685926549786027U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13633457935771935260U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12684602052812183096U;
            aOrbiterF = RotL64((aOrbiterF * 4689206269919806711U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5711307583717354204U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7181854170553728211U;
            aOrbiterD = RotL64((aOrbiterD * 9835601115561325911U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1884620014396115821U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1471516373272364262U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5126319375714848029U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 742739371092077733U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8075893317715227838U;
            aOrbiterG = RotL64((aOrbiterG * 11208274111743259795U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8179547722249281263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15305282712174742323U;
            aOrbiterI = RotL64((aOrbiterI * 7951986906055462929U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1430543231751281079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14585341768267283387U;
            aOrbiterB = RotL64((aOrbiterB * 313213844964269133U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8123889986027932297U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2081696191347150910U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4869653441012615053U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10166788886199265936U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15927074835525735601U;
            aOrbiterA = RotL64((aOrbiterA * 6747650218540675523U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6997764816848988590U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 826930775230515406U;
            aOrbiterJ = RotL64((aOrbiterJ * 9943232461538279601U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 46U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterE, 58U));
            aWandererC = aWandererC + (((RotL64(aCross, 42U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 44U) + aOrbiterG) + RotL64(aOrbiterJ, 52U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14094U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13870U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 12717U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 12605U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererF + RotL64(aScatter, 34U)) + 3612110001869385068U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 39U)) + 16340824141280225936U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 15222338965130765231U) + aNonceWordN;
            aOrbiterG = (aWandererI + RotL64(aCross, 23U)) + 6649270508107155041U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 47U)) + 768217258655426384U) + aNonceWordB;
            aOrbiterB = ((aWandererD + RotL64(aCross, 42U)) + RotL64(aCarry, 51U)) + 4481855259658861851U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 3U)) + 18318041934562434016U) + aNonceWordG;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 4212457153804401807U;
            aOrbiterF = (aWandererK + RotL64(aCross, 21U)) + 16143621095636987628U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 27U)) + 2095664232866642086U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 37U)) + 4339527736737366572U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13679353177869884790U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11582168502846418236U;
            aOrbiterD = RotL64((aOrbiterD * 135539430034462861U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10451330452898542191U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12951448817640617841U;
            aOrbiterB = RotL64((aOrbiterB * 4141870904192742091U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15389161934419370747U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4754886272708253014U;
            aOrbiterA = RotL64((aOrbiterA * 16638243718191281597U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11746389873929280688U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12042680172517298768U;
            aOrbiterC = RotL64((aOrbiterC * 3814780289755857543U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2648103752465009244U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 451594673632597973U;
            aOrbiterK = RotL64((aOrbiterK * 8496763663271072425U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5696534794094099710U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14609435045257077395U;
            aOrbiterH = RotL64((aOrbiterH * 14658408563237468407U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11599395126850950133U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12699598504604446664U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14313494063098111823U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9398465148537154745U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12139736860648011256U;
            aOrbiterG = RotL64((aOrbiterG * 15257503229375247987U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5390816291244486383U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2797988892316486895U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 14668138881285892065U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18356290434261054712U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16582824574485822826U;
            aOrbiterF = RotL64((aOrbiterF * 7207935384746719969U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9858803484150150915U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3612110001869385068U;
            aOrbiterI = RotL64((aOrbiterI * 2862887443435821143U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 54U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 4U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 47U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterG, 44U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + aNonceWordP);
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 40U) + RotL64(aOrbiterI, 60U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19312U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18036U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18443U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 18416U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 58U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aIngress, 53U)) + 15813325389431304548U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 27U)) + 2223874171125403602U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 51U)) + 5510483568496824130U;
            aOrbiterB = (aWandererA + RotL64(aCross, 19U)) + 15474152493495661876U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 16846339705130829195U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 1289670576865739669U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aIngress, 37U)) + 18017354919647006944U;
            aOrbiterG = (aWandererC + RotL64(aCross, 3U)) + 8539685539928984921U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 3333721400836704048U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 14U)) + 2261560416623815491U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 35U)) + 4377786131746816567U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18047393176583722719U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8184724021940434631U;
            aOrbiterC = RotL64((aOrbiterC * 9800116157750921119U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10469895939183324807U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14543391765109879223U;
            aOrbiterD = RotL64((aOrbiterD * 4817987697437667225U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5757225781746158178U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3539000495894022869U;
            aOrbiterJ = RotL64((aOrbiterJ * 1032298408884695925U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11288971092707065923U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 2761384065186568294U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 3323838837427471051U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7120580145300417101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6977246291769372866U;
            aOrbiterG = RotL64((aOrbiterG * 15170353875184253779U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17625434527765525937U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3299714663631376190U;
            aOrbiterA = RotL64((aOrbiterA * 6532628892760776767U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10331889953489885250U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8550932256881727932U;
            aOrbiterF = RotL64((aOrbiterF * 13085531621192583719U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11151195711186126257U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2552002192824926483U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9754056316698523849U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8038115194286715268U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 16594489591573505305U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1241387574663818247U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13476964484361081681U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2136330439951908303U;
            aOrbiterK = RotL64((aOrbiterK * 12728359054660550527U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 231990686776499700U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15813325389431304548U;
            aOrbiterB = RotL64((aOrbiterB * 9155088985405261637U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 12U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aScatter, 10U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterA, 34U)) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterE, 56U)) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 39U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22043U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24796U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26551U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22165U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 58U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 12809562813316740345U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 28U)) + 17084212535326321199U) + aNonceWordI;
            aOrbiterB = (aWandererG + RotL64(aCross, 5U)) + 16074921689983846769U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 14027986153007120145U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 3U)) + 7633455951809250227U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 37U)) + 340989348513370174U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 14U)) + 5307820377645020116U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 21U)) + 5605285015771527274U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 43U)) + 5293500434746182790U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 7263156475892261811U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 57U)) + 10672879570907433005U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16659226780900986107U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9774892622769850665U;
            aOrbiterB = RotL64((aOrbiterB * 7487477727543183211U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10728057184108279042U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5032485856947407217U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16651577903809154285U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14642241075374862345U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8386481273395203518U;
            aOrbiterK = RotL64((aOrbiterK * 11649977733867003445U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2874153265304098104U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11519900149177261000U;
            aOrbiterH = RotL64((aOrbiterH * 2010158758971864505U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8885690878540115768U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4482143389870987714U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7105332459437434281U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17469068567801886615U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5121422018622394837U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 14823827133212643467U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3130788210672745618U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6139244627510113216U;
            aOrbiterI = RotL64((aOrbiterI * 2640754184921507389U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10488511756324474710U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1760223670304953696U;
            aOrbiterC = RotL64((aOrbiterC * 4007062295003769311U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2232708414171096783U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17497492434939621063U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 9850565931511937725U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8199114561613022892U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15432482434863050835U;
            aOrbiterF = RotL64((aOrbiterF * 14271143436318169871U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14991531324947777062U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12809562813316740345U;
            aOrbiterG = RotL64((aOrbiterG * 4487021480964944879U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 56U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 24U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD) + aNonceWordL) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 48U)) + aOrbiterE) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30973U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 32243U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32529U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29878U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 58U)) + 6973892330986118220U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 5U)) + 9886813896272094864U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 39U)) + 10996306582517553173U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 37U)) + 8490648283899856223U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 43U)) + 105141713530704655U) + aNonceWordJ;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 3114337422810562588U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 980857684690886131U;
            aOrbiterF = (aWandererG + RotL64(aCross, 29U)) + 6562042345807072665U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 27U)) + 15665371138706353619U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 18113013571374375028U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 60U)) + 17405346422601997299U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5130876096426182506U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1813821672299154629U;
            aOrbiterH = RotL64((aOrbiterH * 15478100342425611875U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15793814882743306728U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13925299440495476399U;
            aOrbiterB = RotL64((aOrbiterB * 12049601510660117401U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9924458846049579438U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7810034662781768090U;
            aOrbiterJ = RotL64((aOrbiterJ * 10310594595026622513U), 23U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 12812586478656872854U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5709576448057435237U;
            aOrbiterI = RotL64((aOrbiterI * 9101555233909853025U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7839807649914541516U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4717944526755429647U;
            aOrbiterF = RotL64((aOrbiterF * 8515229146471335721U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3933911971504256022U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4814079680865379831U;
            aOrbiterC = RotL64((aOrbiterC * 15100740696230557391U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 18352577312212175569U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9670612998448920742U;
            aOrbiterA = RotL64((aOrbiterA * 5743579439303300553U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 72737302703035726U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10032869372369626210U;
            aOrbiterD = RotL64((aOrbiterD * 7449905669249993731U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2669999453643982386U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2016129534922291383U;
            aOrbiterG = RotL64((aOrbiterG * 11730911201750754301U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5108689262300895422U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3753457479225942895U) ^ aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11503304711866175497U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 859776381005289485U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6973892330986118220U;
            aOrbiterK = RotL64((aOrbiterK * 12337041087475258221U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 52U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterB, 18U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 53U)) + aOrbiterC) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 52U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 60U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordF);
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

void TwistExpander_Boxing_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA96533012C6EC8E3ULL + 0xED74EF9E145A7B5FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x87510D7B81CDE5D5ULL + 0xD63F026532AA03AEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEAC05D3642F07CB3ULL + 0xDF2C0C3B3368F61DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB14262C2CFB784DDULL + 0xFE6F21487ABFCD47ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC3024A0918C60F29ULL + 0x9111A0070C5A2EC4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA23F9950BA99DF5FULL + 0xDE078ADE0B85DC60ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC23AA95CD137FFF7ULL + 0xB0EF97EE467F4334ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD3514E16540B5853ULL + 0xC3555159F355E508ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDE842EF95A8AF44FULL + 0xB9D91431F38658D4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9D3C35CD554CD4D3ULL + 0x92331D3C83472E6FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEDC3BAFC91145C33ULL + 0xDE4D8C0EFC7D5924ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE32C6EE5D54BEF29ULL + 0x9F3642FF67F71C75ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD335313EE3ACE4EFULL + 0xC5672EB8AED39C88ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF18909A360D255E9ULL + 0x9CD3372089592E5AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE806F3A645355DBFULL + 0xD56BECAB71270541ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8FC4A1E9C5FFC40BULL + 0xB5284DD6E4AC7D53ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4595U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6612U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1402U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 673U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 18U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 964165145848253292U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 57U)) + 10645976767204934746U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 51U)) + 8241612229349212650U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 14U)) + RotL64(aCarry, 53U)) + 4159196033256913347U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 5U)) + 7194795864620233507U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 27U)) + 7638928444536778384U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 11819105916503968109U;
            aOrbiterE = (aWandererE + RotL64(aCross, 47U)) + 18052213302858186237U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 42U)) + 8663575313970041570U) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16644136720439299786U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16930316530442679864U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2650922074098320859U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16251107616988250593U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7171986193609401665U;
            aOrbiterK = RotL64((aOrbiterK * 3543709971414550087U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 17885046834432626644U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7757069274715713557U;
            aOrbiterE = RotL64((aOrbiterE * 15766885299397923879U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2212805322061155615U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6368539134638838822U;
            aOrbiterF = RotL64((aOrbiterF * 13383744883433594259U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5264326094252925613U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6126345334815012938U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17180934809764905307U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13826731214018407061U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6621261811613643620U;
            aOrbiterJ = RotL64((aOrbiterJ * 2823596473596114171U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5964406317285863781U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2167324450276308078U;
            aOrbiterC = RotL64((aOrbiterC * 1098346374733634905U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16740710162977859724U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8236083581048717923U;
            aOrbiterG = RotL64((aOrbiterG * 4364887787000704039U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13967473987446124012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5136051802217149813U;
            aOrbiterD = RotL64((aOrbiterD * 13997246005108872883U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 26U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterC, 60U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 4U) + aOrbiterK) + RotL64(aOrbiterB, 13U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + RotL64(aOrbiterF, 41U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterF, 56U));
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 38U) + RotL64(aOrbiterK, 37U)) + aOrbiterE) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13279U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8720U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12399U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14665U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 12U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 9023059520606551446U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 24U)) + 662441755115638133U) + aNonceWordP;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 16957253361196144712U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 43U)) + 7840955025765308605U) + aNonceWordE;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 53U)) + 346855809270395799U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 16099139781586668343U;
            aOrbiterI = (aWandererH + RotL64(aCross, 29U)) + 3706457327118322098U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 57U)) + 12166825885547622870U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 48U)) + 7792658665720344200U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7128477606152986326U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11116533962780290084U;
            aOrbiterA = RotL64((aOrbiterA * 11993485572912492297U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10443889548568288532U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4402387036946561017U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 9032964741841833277U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13002706161178447654U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13929727277530310708U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7005639090871200285U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10949073760696935106U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15405923432006783533U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17989565878445202495U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 18096057968822208905U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3032155040484574973U;
            aOrbiterD = RotL64((aOrbiterD * 448597307502544605U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17462076466907467134U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15471015427013701406U;
            aOrbiterK = RotL64((aOrbiterK * 6113474000571976139U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3549031751266594344U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14243218483842508113U;
            aOrbiterG = RotL64((aOrbiterG * 9041601306479302047U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5803147589312920032U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5549470512227427855U;
            aOrbiterF = RotL64((aOrbiterF * 12592362489263862879U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10076661824293832189U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3196799148974716550U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8183276968961467775U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 18U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 30U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aIngress, 30U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21797U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 18899U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23860U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22824U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 23U)) + 5960680319644404115U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 39U)) + 16050752633567034185U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 8447503223226854741U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 34U)) + 14176813813397917591U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 10534915376130006644U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 27U)) + 6866224454375302514U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 47U)) + 16506374165041008396U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 7167814023968794098U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 6U)) + 13870852197416596664U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18064038854848993105U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9869630811507771691U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13723164383800461387U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 863613100452759380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16597969741225436529U;
            aOrbiterI = RotL64((aOrbiterI * 2680793528887208903U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6575347108051310653U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17062262265485019063U;
            aOrbiterB = RotL64((aOrbiterB * 7601045488473620019U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7193399224636409133U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14146747818810433849U;
            aOrbiterD = RotL64((aOrbiterD * 5273185769989530041U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9441449106442431427U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4303295336545399503U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8829695296836242587U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12604760768543193458U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15779327512379787715U;
            aOrbiterE = RotL64((aOrbiterE * 14000905201441272597U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15553000781122708728U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17162740616060079717U;
            aOrbiterG = RotL64((aOrbiterG * 9458662233556750239U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1032374679817715156U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16413393156165548232U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 549659738811935015U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14056855000013992045U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7399202019042538829U;
            aOrbiterH = RotL64((aOrbiterH * 6103508549612077695U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterG, 52U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 10U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 23U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27287U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29892U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25205U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26874U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 12U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aPrevious, 29U)) + 13053031069776604052U;
            aOrbiterF = (aWandererB + RotL64(aCross, 58U)) + 1331396630251085122U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 23U)) + 15879286043343942393U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererA + RotL64(aIngress, 19U)) + 13590365633321406830U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 51U)) + 14569235423040242618U) + aNonceWordJ;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 11397370636618371560U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 3455933494593971847U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 36U)) + RotL64(aCarry, 5U)) + 1307153376443784593U;
            aOrbiterI = (aWandererC + RotL64(aCross, 13U)) + 10688618762584786871U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17746248451153600096U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8512568600755410158U;
            aOrbiterG = RotL64((aOrbiterG * 16648320170768234063U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8950230550112591092U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17790968369472845496U;
            aOrbiterB = RotL64((aOrbiterB * 5104988920132008913U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12583323865381967534U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11243927099685293887U;
            aOrbiterK = RotL64((aOrbiterK * 12867003042486433971U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9690268715525781389U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7466066217365074653U;
            aOrbiterC = RotL64((aOrbiterC * 17565696765505320889U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3673528673209875118U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14079103852360952255U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17449228863409999629U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6747836856132250630U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5027692924422297153U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 2492421273167124437U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11370341866003395776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14013204893442579282U;
            aOrbiterD = RotL64((aOrbiterD * 6602239957997240785U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3436953430697936790U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6399073534839993637U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14186050072610021241U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7054057507823631422U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5752085719673338095U;
            aOrbiterF = RotL64((aOrbiterF * 13252660162476029593U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 14U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterB, 10U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 46U) + aOrbiterC) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterE, 53U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 14U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordD);
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

void TwistExpander_Boxing_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB3C2A0DB5E0DA2E9ULL + 0xA54E2F6C13661348ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF494B4A5275878C1ULL + 0xFA804DB557CF77D8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE8C77CB1E5D7BC29ULL + 0xEBA894F7B7EB8F6EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC4F86236E54BB06BULL + 0xB9D6F7A264DDEA4EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEF04ADF84037BD83ULL + 0xD36046FEBBCC56D6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDA9A16F786F0AEFDULL + 0xE3BBD9B8BA7C5662ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x84F97C17AAB8833FULL + 0xD33CE5AC5E85014DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE161B0EC0027000BULL + 0xC7BCD1AA5056D89DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCD77905206FD6E63ULL + 0xBEB35F7D4DB95E47ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF68BAEDC1553BF0FULL + 0x8AE06C3BEF53D855ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFBA88330ECFBDA61ULL + 0xE90B0E520939155BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC2C0CFF4AC5C4719ULL + 0xD6FA8DA6A1C10EBFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD071850C6D83DD8FULL + 0xF2D197F80B03E8D5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE3CA63D6D9073EA3ULL + 0xCF83B471E4DE4ED3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC626043C2C6036CDULL + 0xBF933867A362E472ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC6A337D7A99E9395ULL + 0xF3652817341D7B7AULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7329U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 2608U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3296U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3440U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aIngress, 28U)) + 11998579547770778580U) + aNonceWordF;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 51U)) + 8409465187298704610U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 3470222286110333500U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 37U)) + 5704486785203069994U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 10334944660253279633U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7626852700722567477U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14631310754943209743U;
            aOrbiterH = RotL64((aOrbiterH * 1958866541508493967U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 807160297237854120U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 5624154783624196107U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 2404066593958052159U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4971444394698940423U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6340057638461027062U;
            aOrbiterJ = RotL64((aOrbiterJ * 12027586111086798629U), 51U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 9003019862787819481U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 13632057463595873033U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 12575202147280216765U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12766104026871797746U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4062118445824915939U;
            aOrbiterE = RotL64((aOrbiterE * 13130770039048080701U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + aNonceWordG);
            aWandererG = aWandererG + (((((RotL64(aIngress, 52U) + aOrbiterK) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 5U)) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11009U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11040U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14055U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15093U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 14499676118633326000U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 39U)) + 17191273593018552288U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 4085176294948097737U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 11112671474158908186U) + aNonceWordF;
            aOrbiterB = (aWandererF + RotL64(aCross, 30U)) + 8745787969012266485U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18074049663777707948U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2543758649719164688U;
            aOrbiterI = RotL64((aOrbiterI * 7153845562786344373U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4659584749412700523U) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 974639159259871273U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17918719351847605523U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9211220687971081987U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8567024626862182714U;
            aOrbiterC = RotL64((aOrbiterC * 7755874089832496393U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5803002132294840900U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11968489432878148467U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4501441062617123165U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9470807228394903442U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1692347973120388469U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17433393164156231575U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 57U)) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 60U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24359U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((aIndex + 19812U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20153U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 24523U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 701291026547470433U) + aNonceWordH;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 17283292650462111643U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 51U)) + 9969124091931303406U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 889176772718046988U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 27U)) + 6054541844643748084U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14703226235143028132U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7977975878522921062U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 9030855800028448469U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16894322614172266274U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12160451749345900570U;
            aOrbiterC = RotL64((aOrbiterC * 18055355572903901749U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10870847008043897470U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8159920947172520247U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4833194641611011805U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2440099120969517932U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2428396147731468007U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 9363073341539598441U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2213226274394673479U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7079731443427765333U;
            aOrbiterI = RotL64((aOrbiterI * 16918930776877030559U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 23U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 53U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 22U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 42U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28661U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 27200U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28489U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 29560U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aScatter, 51U)) + 2915859148137000694U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 4U)) + RotL64(aCarry, 5U)) + 210680583721444425U;
            aOrbiterG = (aWandererF + RotL64(aCross, 39U)) + 6668118118775650387U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 15794200818099010989U) + aNonceWordA;
            aOrbiterF = ((((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 6565076707062828369U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 16323164497808856719U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7965435318816716560U;
            aOrbiterG = RotL64((aOrbiterG * 5984608704943623687U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7390281030573369017U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2269738866911824875U;
            aOrbiterD = RotL64((aOrbiterD * 1198697877998135567U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9664014216039993873U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18284857398028357633U;
            aOrbiterJ = RotL64((aOrbiterJ * 8402008251343393737U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 367667619795303009U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7935945060956274197U;
            aOrbiterA = RotL64((aOrbiterA * 5481786693511955209U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16683666162337789540U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10655658270998102390U;
            aOrbiterF = RotL64((aOrbiterF * 15231596813382239841U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 46U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordE);
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

void TwistExpander_Boxing_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEC7AC340FC3B894BULL + 0xBB4F11C18841906DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFE1578716C0604A1ULL + 0x82A0B40EEA12F8B6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC8EE56B9EE01F773ULL + 0xF735F6AEC7D86A15ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD8EF66596CC195ABULL + 0x814111B95FC07035ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBAEC4D8B68A5A00BULL + 0x855AB02B74BF9675ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEBBA27287544191BULL + 0x9A7EFA3572729F3EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEA38BE5448695711ULL + 0xFF3A2720902D651DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCC479A31F54C5943ULL + 0x962D46E72669D5B0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF2C47FF4B56F5635ULL + 0xADEC3296534489F5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD624C67A6602AB71ULL + 0xDE78DFDBB5877E9BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDF3304F8C05967F3ULL + 0xB5C69711C4348355ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAF5ACBDB87024623ULL + 0xCF603A9FD571CD7BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA421F7B551FE25FFULL + 0x86923CEE4947E32BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE8E147EC677523E3ULL + 0x932A115C26B37C72ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8DCEA1F107C5053DULL + 0xE39FA19435480D29ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x880AD413642C63EDULL + 0x87996696DA030AF9ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4270U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 8128U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7672U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3634U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 18U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 11274974230580265396U) + aNonceWordD;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 14U)) + RotL64(aCarry, 19U)) + 16658438747342741547U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 43U)) + 16612986966106053844U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aWandererK + RotL64(aScatter, 5U)) + 9329502236843231290U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 21U)) + 14088261356708344656U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 37U)) + 13692608802007789581U;
            aOrbiterE = ((((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 6824473946645682398U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2072915876348570040U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7420507753044460759U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13239288539564571257U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4677557318688502593U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15081678577055628459U;
            aOrbiterC = RotL64((aOrbiterC * 16659305295251177155U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7026792817486507482U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 694073180313083145U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6807734532159292872U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17882797335141303280U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9233542707022629190U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1205501586581350876U;
            aOrbiterD = RotL64((aOrbiterD * 2596053290311090589U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10878718669747466677U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8066049063548639241U;
            aOrbiterI = RotL64((aOrbiterI * 3031382633089381605U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 861295180226875235U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9134969787937288583U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 7565008208670843555U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 41U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererD = aWandererD + ((((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 10U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererK, 56U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14586U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 15371U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8693U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 11526U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 35U)) + 10881271196314989997U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 6406461249988567558U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 29U)) + 17255067918280095959U) + aNonceWordF;
            aOrbiterF = (aWandererI + RotL64(aIngress, 47U)) + 16690850682497718411U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 5576201059361086866U) + aNonceWordH;
            aOrbiterE = ((aWandererH + RotL64(aCross, 13U)) + 11991259685693687554U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 23U)) + 14652535244217836909U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1701789037170782122U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 953429054903473833U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 13482379459700651427U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 12064513610469714211U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7993881398822002424U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11572884842788918377U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14421313768013320050U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11112386845630998889U;
            aOrbiterF = RotL64((aOrbiterF * 11771526352030371669U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17069630896535699015U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3308240081138623373U;
            aOrbiterB = RotL64((aOrbiterB * 10449509484417835159U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17615529807112933619U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11782807146851563541U;
            aOrbiterG = RotL64((aOrbiterG * 12992075832343669221U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14401645829607611983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6736397344219993532U;
            aOrbiterE = RotL64((aOrbiterE * 1667287547938175641U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6446974060524700550U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7840991992443308254U;
            aOrbiterJ = RotL64((aOrbiterJ * 6891023544882740107U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aCross, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 21U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 4U)) + aOrbiterE) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23240U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22649U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22445U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18097U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 56U) + RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 12206125048349568300U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 5843520589343188818U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 30U)) + 12195046124287121687U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 47U)) + 16769779119214020640U;
            aOrbiterG = (aWandererK + RotL64(aCross, 13U)) + 5257603646260695833U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 21U)) + 8523523946234886745U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 7316024684200084096U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11996978575084115207U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15491711479085513628U;
            aOrbiterJ = RotL64((aOrbiterJ * 15136690392026011819U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6036648530996821484U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 926323222234121863U;
            aOrbiterK = RotL64((aOrbiterK * 6639661141258803779U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2700323841295743492U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5852273765810284935U;
            aOrbiterF = RotL64((aOrbiterF * 16665696735016345215U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11697397483133538067U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17777142964957007194U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6338967222543284999U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10892176201151170298U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11759700374509499684U;
            aOrbiterG = RotL64((aOrbiterG * 14247697264744736081U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11343756773329590643U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15785048929757652350U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17208103574389502597U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7508839228498497238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13088508510402094665U;
            aOrbiterA = RotL64((aOrbiterA * 15730279447009669103U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 22U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + aNonceWordI);
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 44U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 40U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26380U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 24916U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28902U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30247U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 18255347001097480328U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 58U)) + 13679246790311505735U) + aNonceWordM;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 10565839529765027116U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 41U)) + 14327172566224769901U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 16239024612038195174U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 5U)) + 13800012174212131890U) + aNonceWordL;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 27U)) + 13900288860157577583U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4144386119777112740U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3154558262670631372U;
            aOrbiterK = RotL64((aOrbiterK * 13236911910092437063U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7456728543137614001U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11709519851158935384U;
            aOrbiterG = RotL64((aOrbiterG * 7016689518570071587U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15607438907832240304U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 9276575329661725624U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 8879744070762412745U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6459435969129449226U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6442382118416542275U;
            aOrbiterE = RotL64((aOrbiterE * 2921027306686588233U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12117432107282150865U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6831279293184793243U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2435360641135249073U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9520022957804572889U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8322178689474588679U;
            aOrbiterH = RotL64((aOrbiterH * 1627707191467537115U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4162401591586869316U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8994015844714895961U;
            aOrbiterB = RotL64((aOrbiterB * 15421910378057951895U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 4U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + aNonceWordF);
            aWandererC = aWandererC + ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 6U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordE;
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

void TwistExpander_Boxing_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9703F272663F1EB7ULL + 0xBDD89C9640123EC5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA53C3663CDA18BB7ULL + 0xE00F72FE20D92714ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA8D214ABAF872393ULL + 0xDAE0D38FE0FAE50DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8FE44157E89E9191ULL + 0xE8EEC7CF404C36A1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9AD3E2EF27384A21ULL + 0xABB410B66BFCB702ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE7F92030DE6A1AE5ULL + 0xEB385958364C9B15ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCCA5AC9684341507ULL + 0x9153756A6A79D0F6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFFA953A73A35BF0BULL + 0x993E1351B007B399ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDBAA2AE8BCE1CC53ULL + 0x88F04BF0B817A4ADULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFF4F023B70DB2249ULL + 0xC045EC695C71A402ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC901CC32010EA34DULL + 0xD6C046E8A4A8C29FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9B79E53BBAAA0807ULL + 0x96A293FCC885357AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD73F9A27F28FAF85ULL + 0xA3A695065916B85DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF87CB60CAF82BE03ULL + 0x8D1A33BF16E66FD1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE88513A77B19F09DULL + 0xDFD22CF5E54A3584ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD86E380748F9DC29ULL + 0xFA564D55BB8588A9ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4421U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 641U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1555U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 6193U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 5U)) + 18302975933754610273U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 46U)) + 16736972646771456082U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 17389406266488137442U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 27U)) + 5252511566486165539U) + aNonceWordL;
            aOrbiterG = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 5730715427422747640U) + aNonceWordD;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 21U)) + 6412695646456045825U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 9539701605708994494U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 18355107116412945722U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11735742491750132942U;
            aOrbiterD = RotL64((aOrbiterD * 18129835093627763685U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12363819388562658842U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5861430292304371543U;
            aOrbiterG = RotL64((aOrbiterG * 12989055611235382695U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 15027487084595017708U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7012850020745791926U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15952928839355613939U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11904871669287886120U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11199760114477343208U;
            aOrbiterE = RotL64((aOrbiterE * 7156374911847525867U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3856004502263742700U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3705931243173921893U;
            aOrbiterK = RotL64((aOrbiterK * 10334871178498711485U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12305785390539209389U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 18057980996551978823U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 4850564181113470859U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3229431819292153014U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2994716629242460094U;
            aOrbiterH = RotL64((aOrbiterH * 1029427328395257917U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 40U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 22U) + aOrbiterD) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterF, 56U));
            aWandererC = aWandererC + ((((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11471U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14176U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12615U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15980U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 38U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 3U)) + 3917730204724097072U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 34U)) + 1874642340716212824U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 6900165757434854160U) + aNonceWordM;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 12750946097023807161U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 6563216048479513594U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 57U)) + 14960240191349450795U;
            aOrbiterK = (aWandererA + RotL64(aCross, 19U)) + 16306180275951788289U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6502066618271045547U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6219852857850888738U;
            aOrbiterC = RotL64((aOrbiterC * 10892297250334325283U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2272931312452845850U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3028929882263199463U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11005324285856805069U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6067393030073568112U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10094809900437037258U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18095564940730322769U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5962414178157074575U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15755563045799129417U;
            aOrbiterD = RotL64((aOrbiterD * 3692603590609922031U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6321455513889880590U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1197435601998121700U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 17693996266260557625U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 12496949381666299968U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6357070235648527030U;
            aOrbiterH = RotL64((aOrbiterH * 2931486644220862433U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8423760160877540210U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8090246492554850768U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 2949407491181921633U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterD, 27U)) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterB, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 4U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 24U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22748U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21177U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17544U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17917U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 1888427424966603593U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 53U)) + 5436761445660415091U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aWandererE + RotL64(aIngress, 27U)) + 17322876217962143270U;
            aOrbiterC = (aWandererI + RotL64(aCross, 37U)) + 9728299982740564979U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 301720335271716921U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 8069685428854814396U) + aNonceWordF;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 4U)) + 1973715500949100991U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 87666408799854155U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12195436904339035245U;
            aOrbiterG = RotL64((aOrbiterG * 15427739165893738105U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4578742069143400295U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7828776048774876484U;
            aOrbiterA = RotL64((aOrbiterA * 4047964518501081039U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17203146364542781833U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16913369550858890466U;
            aOrbiterK = RotL64((aOrbiterK * 13534417587921978507U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9632761514552265402U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9106637671877341286U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9073709119482640391U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15423680889126750876U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6087310684583331882U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8964465129744898619U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5420955876411796789U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14166807419730848032U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 442659738632823751U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8118312450347026824U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 4253043584558403086U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5651748455190536467U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 20U)) + aOrbiterA) + aNonceWordL);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 5U)) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterC, 37U)) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28388U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31058U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31386U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25506U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 16424657151168221875U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 13U)) + 17150123681886380361U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 57U)) + 16041993588694572757U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 41U)) + 9871185846434828537U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 21U)) + 11227236398354430757U) + aNonceWordP;
            aOrbiterH = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 5399325217402192631U) + aNonceWordL;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 53U)) + 9248828789282890454U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9041370494203701062U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14944424084524970764U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 10283363059424655079U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5481938174456671041U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14783648629543752715U;
            aOrbiterH = RotL64((aOrbiterH * 7260164783191886395U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12355573914530445723U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9863991559011968318U;
            aOrbiterK = RotL64((aOrbiterK * 8495251211794343179U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16149688605937250965U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 106041828692026825U;
            aOrbiterG = RotL64((aOrbiterG * 12199934305374582599U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8076098639554567792U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11155119311895580013U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1495180896564818647U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6847612160595917702U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16094377920388017367U;
            aOrbiterJ = RotL64((aOrbiterJ * 4875801863643206333U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13584719866672696684U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13446209321646234607U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9945349065094781529U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 54U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aNonceWordO) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 50U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 41U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordO;
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

void TwistExpander_Boxing_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8B670DEBB1188A9FULL + 0x9E881B59D37D16C3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8029B750643BE421ULL + 0xC6FF4B290C4EAFDEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBDEFD5C1C9A5618DULL + 0xA6ECB590CC2378D2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC1A8394D2D7A0171ULL + 0xE9F34005A74AD880ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEA025624050F818BULL + 0x8348E78C3789882FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF2AE79A6DDA7B625ULL + 0xB80F7DFEF506FA0DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9D5696A16244C99BULL + 0xA93758A16586F07CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAC8E5080E8B96451ULL + 0x81FD4157F54492ADULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAE80997ECC362137ULL + 0xC56320466DFAC470ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE26191C52F8DEA45ULL + 0xBF4A8D4D4353C527ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x861F229C3D3DDE7DULL + 0xF71990C04C9CE4C7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE3D1661FCED60FE9ULL + 0xB25341A473EBD0DDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8FE1D415B556F8A1ULL + 0xA2D70A670DAD5C76ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x94F73F374A47EA53ULL + 0xF7087A7B850F433CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA9E8699419407B07ULL + 0xC5B8EE871A5251E1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAE058B17057A9985ULL + 0xE96DAD9445251CA9ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7747U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2462U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1778U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 3678U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 56U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 2177539223979303669U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 22U)) + 3962004686551521471U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aWandererK + RotL64(aCross, 11U)) + 8457602312617147662U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 41U)) + 18011802451816510632U) + aNonceWordN;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 3U)) + 9046101759168876832U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 24U)) + RotL64(aCarry, 11U)) + 11135620637431969597U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 37U)) + 15913029940697999701U) + aNonceWordK;
            aOrbiterI = (aWandererI + RotL64(aCross, 13U)) + 16304193109948135982U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 47U)) + 13208892298820080981U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 57U)) + 4182377898949419225U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 13970137023071326151U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8402396284835248583U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8859190834060657829U;
            aOrbiterB = RotL64((aOrbiterB * 13552418608113716117U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9760005337757990392U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14108277760135744897U;
            aOrbiterF = RotL64((aOrbiterF * 4474681104256093885U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 12226316121949012350U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3456392186754113960U;
            aOrbiterC = RotL64((aOrbiterC * 8704729827929941215U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5004087958637038973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7176881295123125567U;
            aOrbiterD = RotL64((aOrbiterD * 15272157962928021009U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10889800478505074438U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13728832441482547824U;
            aOrbiterJ = RotL64((aOrbiterJ * 17588477761978646139U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17345665880706866772U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 301139993853297566U;
            aOrbiterK = RotL64((aOrbiterK * 5812445396758354505U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2061389844760610160U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13631862266139238355U;
            aOrbiterA = RotL64((aOrbiterA * 143613352104722701U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10767186080827509622U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4893486019456886013U;
            aOrbiterG = RotL64((aOrbiterG * 5194746459545610901U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11264795916303477037U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16013652139405432608U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14924257021089920495U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5209743554932653849U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13160179712987277456U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5003755912040281427U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12440615920191945386U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2177539223979303669U;
            aOrbiterE = RotL64((aOrbiterE * 3565122523239344029U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 6U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 34U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 42U) + aOrbiterK) + RotL64(aOrbiterG, 53U));
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterC, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 40U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aIngress, 26U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 5U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12873U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14303U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11665U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 12805U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 36U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 57U)) + 11700815697312060726U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 46U)) + 11808423452327465441U) + aNonceWordP;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 13U)) + 8670503858631730886U) + aNonceWordL;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 2400061067991988544U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 16163118178366229686U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 43U)) + 3280178595904941068U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 11U)) + 3298683600817047727U;
            aOrbiterI = (aWandererA + RotL64(aCross, 3U)) + 16321624053445183574U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 6730229877611375225U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 34U)) + 10162830636713641322U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 21U)) + 15646771327759599256U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14841751262270544102U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9545541117228834895U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 11529769874752969377U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14676615635857599982U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1231768638470558855U;
            aOrbiterH = RotL64((aOrbiterH * 2716808508509014677U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1945905595345404833U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1406171421638586846U;
            aOrbiterG = RotL64((aOrbiterG * 4577864352425476233U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1970292335806697198U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12309719390375013297U;
            aOrbiterJ = RotL64((aOrbiterJ * 16540660957923687327U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5352135521358954576U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15465675376193501658U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 16385761112921041387U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2842123638916600369U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3544764287036748668U;
            aOrbiterF = RotL64((aOrbiterF * 3360772950777850115U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6038297172906492282U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10249342332287140970U;
            aOrbiterE = RotL64((aOrbiterE * 16701083081566042277U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1662076777040529446U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1949705569959740274U;
            aOrbiterK = RotL64((aOrbiterK * 11340691546658994529U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13934194245417822360U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5720408806425535958U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15237561081637415383U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2209251362417210658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4917447930929521699U;
            aOrbiterC = RotL64((aOrbiterC * 17489570156694692569U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14817115766683623486U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11700815697312060726U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16982411053956669181U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 10U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterI, 4U));
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH + (((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 14U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 10U) + aOrbiterA) + RotL64(aOrbiterF, 53U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterE, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23054U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23760U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17592U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 24270U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 52U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aPrevious, 57U)) + 7948891781097675369U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 11U)) + 13928362874228230226U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 10776180542602258926U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 5735115172149470447U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 6U)) + 5353591822981766987U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 37U)) + 562301708107268570U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 10467810247578364868U;
            aOrbiterE = (aWandererK + RotL64(aCross, 21U)) + 14541630141152308564U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 35U)) + 2350076897065139429U) + aNonceWordK;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 23U)) + 17519109078651162228U;
            aOrbiterA = (aWandererF + RotL64(aCross, 48U)) + 6061035173339902910U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15654836633731000065U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13723521735153718904U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2849680038315532197U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17336102435576647923U;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7671010488872356142U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11485114338165600777U;
            aOrbiterH = RotL64((aOrbiterH * 4162584865462407791U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8759060657343458985U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11009137869375286581U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8741417343929809115U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15792999392743144135U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6180808423175992479U;
            aOrbiterE = RotL64((aOrbiterE * 13681230339693676907U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 361487389591183005U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15292753806514404853U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17478232597253311153U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14929153438443362045U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7904556383593914086U;
            aOrbiterC = RotL64((aOrbiterC * 2484130486635511403U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3793180909904286848U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10391957637467171320U;
            aOrbiterD = RotL64((aOrbiterD * 505484041943467117U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11648765065563798353U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17601185776537566611U;
            aOrbiterK = RotL64((aOrbiterK * 4753179291885740011U), 39U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 2907499704986356444U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17048858067202291241U;
            aOrbiterI = RotL64((aOrbiterI * 2607549567999666889U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4340465159886930775U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7948891781097675369U;
            aOrbiterA = RotL64((aOrbiterA * 12913104720552907335U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 4U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 52U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 60U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterK) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + aNonceWordP);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 14U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterA, 41U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 23U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31597U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30457U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26506U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 26384U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 12U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 17019646486641172469U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 27U)) + 12276141179299971572U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 60U)) + 3617241694029841555U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 21U)) + 6967963401259371737U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 6340709284279891017U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 57U)) + 456065368903896482U) + aNonceWordH;
            aOrbiterH = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 17686765719908116203U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 29U)) + 1322045955429785736U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 47U)) + 5163772703302372887U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 37U)) + 13268431135020363252U;
            aOrbiterF = (aWandererG + RotL64(aCross, 10U)) + 6538789950366849332U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10390344544314544893U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5087084271300584267U;
            aOrbiterA = RotL64((aOrbiterA * 15149302947570776165U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 13423071121590981727U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 18324443012024134729U;
            aOrbiterK = RotL64((aOrbiterK * 15814349432207734533U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4129091815978464507U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17024797553831962245U;
            aOrbiterI = RotL64((aOrbiterI * 3137753479364378175U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6501545108779991661U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11930037791867597447U;
            aOrbiterH = RotL64((aOrbiterH * 4904739567549702851U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4667298703308315851U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6315980380900062127U;
            aOrbiterJ = RotL64((aOrbiterJ * 12080555704907924637U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12732382340390769888U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7792095326183864547U;
            aOrbiterB = RotL64((aOrbiterB * 12645556660611824631U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17428384983571405782U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3193205313177048443U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14488006565106259731U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2813743367131107264U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2742138679703780981U;
            aOrbiterF = RotL64((aOrbiterF * 18356569025783532225U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6270291142961043031U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3490174937775044998U;
            aOrbiterE = RotL64((aOrbiterE * 13879285210885619613U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13182535825771438942U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13047228760732694484U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10365428317468779549U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17926326514553542739U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17019646486641172469U;
            aOrbiterC = RotL64((aOrbiterC * 13978838314848228053U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 10U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterH, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 10U) + aOrbiterG) + RotL64(aOrbiterH, 58U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 53U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 30U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 50U) + aOrbiterF) + RotL64(aOrbiterD, 13U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterE, 5U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 4U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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

void TwistExpander_Boxing_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDE57072E3F8E8DCBULL + 0xF6B4BEEB4F24D039ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF9863B33C0822085ULL + 0x85C3CCBAD682697DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC35CCD8929885FD9ULL + 0xABA5A271BA84B5F3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9ACBA92C70AB11FFULL + 0xDE1C31452A0B8403ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF8F90DD7973D2535ULL + 0xA5816AE183ED151BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC84202F8D3BCA5A3ULL + 0xD0C484619234EB59ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC853A47ADF347709ULL + 0xABF3C5D28E555011ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEFC861B004254187ULL + 0x9E7726FB4E2E98B8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDF2E32877E858A19ULL + 0x83F3FE2F6197B6C6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8F7C3C103DD46B77ULL + 0xBD326FDCA40F6C65ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA40586F56D4AE383ULL + 0xA5E0733F68DAE365ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8C482B6B1712D6DDULL + 0xADDF5794154A75D0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCBF9CC46B6FFE211ULL + 0xE2F56FB19CAA0E73ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x997BF5CC3530534DULL + 0xABF4E6E61543A924ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD7376CDE49D20085ULL + 0x9A48740B4166C651ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF45E3E28DF2FA2CBULL + 0xF83750E367AD4BE5ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 234U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 430U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3420U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 10U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 35U)) + 12980104182836602177U) + aNonceWordB;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 3172622203188863995U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 1170974132219980203U;
            aOrbiterG = (aWandererE + RotL64(aCross, 60U)) + 6035201940965047490U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 23U)) + 18033907118424996722U) + aNonceWordI;
            aOrbiterH = (aWandererD + RotL64(aIngress, 51U)) + 14604813424800580304U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 13720232492851066035U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 13U)) + 3902659710585257448U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 46U)) + 8331560652661619868U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4485014147538689794U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 168202636924512424U;
            aOrbiterA = RotL64((aOrbiterA * 13711020666131492091U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16227825670092707848U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4792781933944671365U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 12636865372722601282U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 18198291399585556632U;
            aOrbiterI = RotL64((aOrbiterI * 18155803890313399795U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3650053185419807206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5897288963905408776U;
            aOrbiterD = RotL64((aOrbiterD * 3706949366974086151U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9922308113622901726U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13352279749091561510U;
            aOrbiterF = RotL64((aOrbiterF * 4025213180483632557U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14969461950939646117U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 10231661776135056651U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 11284575051455238501U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10621934544068320859U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6029116920305246887U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6087523725059376905U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12887482425168671195U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8351351557123783853U;
            aOrbiterB = RotL64((aOrbiterB * 3839381627914762245U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5405938210926464973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 385145802287899406U;
            aOrbiterC = RotL64((aOrbiterC * 8330751480464271445U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 40U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterK, 14U));
            aWandererI = aWandererI + (((RotL64(aCross, 34U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterD, 19U));
            aWandererH = aWandererH + ((RotL64(aCross, 30U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 37U)) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 24U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8784U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 9301U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9938U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 9710U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererK + RotL64(aIngress, 3U)) + 1708250618750199233U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 12009147777553691142U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 46U)) + RotL64(aCarry, 13U)) + 8393982703399156592U) + aNonceWordG;
            aOrbiterH = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 3247327098356831221U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 21U)) + 3403590155376353737U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 13U)) + 18197244558104735044U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 39U)) + 3096253642040701606U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aScatter, 35U)) + 8012692688785412179U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 26U)) + 17531946907545680745U) + aNonceWordN;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17687695944270225817U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16147773866007628769U;
            aOrbiterF = RotL64((aOrbiterF * 16926442582711557877U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 18244641303026196497U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8839160526348897457U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14268021129087663397U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10599266240854068246U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2056723540756216155U;
            aOrbiterD = RotL64((aOrbiterD * 13311591601230386375U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4629354220460621284U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9505955649473204942U;
            aOrbiterC = RotL64((aOrbiterC * 17775391885312236187U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17078153810088721310U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 9470436761716263000U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 5431855497250357229U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3305863413630104742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14377172434239576161U;
            aOrbiterA = RotL64((aOrbiterA * 6880176890091033423U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 415687827894226513U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16975319836893760993U;
            aOrbiterH = RotL64((aOrbiterH * 6597144958013976445U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12707054129431596074U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8974182792497231239U;
            aOrbiterB = RotL64((aOrbiterB * 7874658957269462717U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10826131924322955095U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4168545139712703154U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 10305904857550051705U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 56U)) + aOrbiterB) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterF, 11U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 60U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14662U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14921U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12583U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 11963U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 13U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 60U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererA + RotL64(aCross, 19U)) + 5568146815535263910U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererF + RotL64(aScatter, 57U)) + 7736084960873834666U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 10U)) + 1336413621817562093U) + aNonceWordM;
            aOrbiterE = (aWandererG + RotL64(aIngress, 3U)) + 5218462026934984692U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 7048890985969555935U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 13415955213864702118U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 46U)) + 5657023257021528548U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 14338310943137497116U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 27U)) + 12305161641833950473U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14514226578370459131U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12692904083266024340U;
            aOrbiterA = RotL64((aOrbiterA * 14800805065279908839U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11012959130001327964U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7106471380403489078U;
            aOrbiterI = RotL64((aOrbiterI * 515626559384817223U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3718101961355280891U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13364192077222322664U;
            aOrbiterE = RotL64((aOrbiterE * 1411328915372590283U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6720867800318913440U) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14497243926965866546U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13595058589060114653U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5789056168233262435U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14438482587495779937U;
            aOrbiterG = RotL64((aOrbiterG * 10593535547917767263U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 313917798940179945U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15241845511889502917U;
            aOrbiterD = RotL64((aOrbiterD * 16483477103771326107U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3591957424821693032U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1559050939014453558U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17933346117866604725U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15340590914441451383U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5538037287390050110U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4082576643144951473U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4151270491894969214U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 263593701314144898U;
            aOrbiterJ = RotL64((aOrbiterJ * 10372046955804512457U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 40U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterC, 52U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterJ, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterG, 18U));
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 52U) + aOrbiterK) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21363U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 19474U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17168U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 16605U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aIngress, 35U)) + 3973833383430652211U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 28U)) + 5760227042747169187U) + aNonceWordI;
            aOrbiterA = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 4923009065139227286U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 1477807307009107590U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 57U)) + 5707194514329007301U;
            aOrbiterB = (aWandererE + RotL64(aCross, 20U)) + 5340439728375269724U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 39U)) + 17080457898946572387U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aScatter, 13U)) + 281559150259472813U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 16160633048230910560U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9003989610509592121U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10579322462808454333U;
            aOrbiterA = RotL64((aOrbiterA * 100832431598087235U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15059383289528723069U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10417647757852880956U;
            aOrbiterH = RotL64((aOrbiterH * 1457919230286043137U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14484665027393813330U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12344463053485837974U;
            aOrbiterF = RotL64((aOrbiterF * 5762654194001525041U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5826453246659297805U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12547902286376986223U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2982850000322672789U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9637855144278126174U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2132744427444501938U;
            aOrbiterJ = RotL64((aOrbiterJ * 5911587798564836199U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9248933938130311231U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13274297928717090383U;
            aOrbiterB = RotL64((aOrbiterB * 2901398809555237563U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3690262236918560930U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3626005326410800344U;
            aOrbiterI = RotL64((aOrbiterI * 13030443356669355355U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10801089744186148218U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5446653082176311031U;
            aOrbiterC = RotL64((aOrbiterC * 4594267575901248321U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 3205541585889107366U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4532327942368884436U;
            aOrbiterD = RotL64((aOrbiterD * 16287094987689326229U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 28U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 28U) + aOrbiterB) + RotL64(aOrbiterF, 26U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterI, 47U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterA, 42U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 52U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23589U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26183U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27087U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 21879U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 16451272412693907816U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 18U)) + RotL64(aCarry, 21U)) + 10099485419723255462U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aCross, 5U)) + 17668900099534923192U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererE + RotL64(aIngress, 53U)) + 5497093724143181753U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 39U)) + 10354044773550071706U) + aNonceWordL;
            aOrbiterG = (aWandererJ + RotL64(aCross, 57U)) + 12728258851198019099U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 4144050505314242618U) + aNonceWordP;
            aOrbiterI = (aWandererG + RotL64(aScatter, 29U)) + 14133805325480076530U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 10U)) + 308863673210602899U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11741180130160569753U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12926863156769180448U;
            aOrbiterB = RotL64((aOrbiterB * 9726030996091054939U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 211920854786494259U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13234608842479411078U;
            aOrbiterG = RotL64((aOrbiterG * 2556747209733759467U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9164711974854618892U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6667377062281954219U;
            aOrbiterI = RotL64((aOrbiterI * 2603737166987437649U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4559040002406721850U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1749875480850675109U;
            aOrbiterH = RotL64((aOrbiterH * 15822640067349481089U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9555365165561936366U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18289733999504213574U;
            aOrbiterC = RotL64((aOrbiterC * 14156217554673229429U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8727162691639622461U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 291406782452963706U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8413500075082350243U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8294911802626492257U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15853578397277298548U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13256191781365357747U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11535146194939658681U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2177540476748375661U;
            aOrbiterA = RotL64((aOrbiterA * 15791341922007841029U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2705306323728084136U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17617871830709148043U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 3449981219502809255U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 40U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 6U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 21U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterB, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 44U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30960U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31549U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29938U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 32283U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 36U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 10812151398716051703U;
            aOrbiterA = (aWandererI + RotL64(aCross, 5U)) + 18202551453336003710U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 56U)) + RotL64(aCarry, 39U)) + 9434410809101973752U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 47U)) + 12955829998028534045U) + aNonceWordC;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 12271740641929640181U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 37U)) + 14009351527014534752U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 43U)) + 4316296955679133450U) + aNonceWordG;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 10U)) + 16473324966997442872U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 51U)) + 15735123324965019802U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17656375090484080236U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16066325053456055298U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17912970706985130327U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12908968778503516903U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12761433987676836197U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1023329467480907925U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12737513138040664509U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14535795767570998392U;
            aOrbiterF = RotL64((aOrbiterF * 15560519667062222269U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14370908061811284364U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7001358781208669795U;
            aOrbiterD = RotL64((aOrbiterD * 11641248025734015835U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7298578161120090849U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10498302152357484629U;
            aOrbiterI = RotL64((aOrbiterI * 13144110412179037175U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11447343228638006767U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18284143620422655675U;
            aOrbiterG = RotL64((aOrbiterG * 572862190073605651U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5918253208127360199U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3910541329178205943U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 4550654545328228103U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10357053096941367910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5610891501128498748U;
            aOrbiterE = RotL64((aOrbiterE * 8676370811772047449U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9049881176058575811U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6307599924966452216U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5551444450572055895U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 36U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterK, 14U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 53U)) + aOrbiterD) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterD, 23U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 28U)) + aOrbiterE) + aNonceWordL);
            aWandererG = aWandererG + ((RotL64(aScatter, 52U) + aOrbiterE) + RotL64(aOrbiterD, 39U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Boxing_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9B1A1317E4528023ULL + 0xA1EB13C2F6439C8DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8143F8BFBC0550A7ULL + 0xFAD547474211636FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAA97C8C677B885DFULL + 0xD5852DC226611700ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x80D2EE0E3DA75035ULL + 0x92F86446E470307CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC39F17DD3DAFC88BULL + 0x91E3A0BF58C6E37FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAEEC7084C1AB5A3BULL + 0xEEE652C0EDD1966CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCDC99345B3358349ULL + 0x83A0077B6EDD755CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x842AB27D220612FBULL + 0x9C9F117600D40833ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8D3B82687AC3F7BDULL + 0xD49BD263B66798E2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF8106B690CB38F63ULL + 0x9DF6D7F10361A8DBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x83709F1896A29101ULL + 0xBD33176F10FD6240ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC64D95B728FD1967ULL + 0xCA0166F89E6A1481ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCEF2E8A8F642FE3BULL + 0xF840F4263F600EAAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEC9C6B46C919A097ULL + 0xF3FD9A95EDCA9BEAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE70185A184106691ULL + 0xF3E8A28F9B6760EEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA63B64D614B61F3DULL + 0xBDF7789069CDDF93ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3366U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 763U)) & W_KEY1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1574U)) & W_KEY1], 36U) ^ RotL64(mSource[((aIndex + 2807U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 26U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 19U)) + 5721224134332887360U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 39U)) + 6892749729775049095U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 3U)) + 3884839462099556836U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 4365431706830216193U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 60U)) + 15501528746571578773U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 4505911326320650606U) + aNonceWordE;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 1865129050927879580U) + aPhaseAOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2011737665969640369U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 611672935827062688U;
            aOrbiterI = RotL64((aOrbiterI * 12873671551304596619U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 663547038310431047U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5468932264754299556U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11968657455484578525U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17920294117231191705U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 486058453837528110U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 8851102552244026737U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2789178451938129313U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 420772587981211184U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17402987842294006667U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16196774774442181825U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16264169656793713547U;
            aOrbiterD = RotL64((aOrbiterD * 6900221986041638783U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10207659833859860796U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8593749091183323678U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10696776033512404927U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7224922076047787384U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15366267474865172373U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 10134187073321814217U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 44U)) + aOrbiterC) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 42U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 13U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6468U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8646U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7829U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 8133U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 22U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 47U)) + 15036852811491820366U) + aNonceWordG;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 26U)) + RotL64(aCarry, 29U)) + 305637140752898475U;
            aOrbiterH = ((((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 11948631574496129610U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 5321623592482991426U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 41U)) + 4075270159062690728U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 35U)) + 15111580500356908928U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 57U)) + 7244150695504160363U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5131563519577488862U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5881954992088651371U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2424421828597294607U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12780935808751507998U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12599159643925470226U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 17690046932587062701U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9466589929741834066U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6093158735705189789U;
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17461243886150519249U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15456408913739900718U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16093292401746174671U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11260643903290392780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7870342756041882616U;
            aOrbiterJ = RotL64((aOrbiterJ * 2431528656086173419U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 134484990005888936U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10626896209992890407U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12034131076645285597U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14031164129515132292U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1771835705730244212U;
            aOrbiterC = RotL64((aOrbiterC * 186981668443596623U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 52U)) + aOrbiterE) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 27U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12988U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 15202U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12461U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14200U)) & W_KEY1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 20U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 11U)) + 12029393034357490020U) + aNonceWordF;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 4526754731580694987U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 5U)) + 17060419646421271853U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 27U)) + 4128488893837059683U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 53U)) + 12706894827547160110U) + aPhaseAOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 12506324593645825056U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 12581344490649250025U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14357032418199130132U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15341977701796331249U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6332369248718076031U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7086602307544733241U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 12398300065276832486U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18157408831225635333U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2499745046076601988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7249361592814001829U;
            aOrbiterH = RotL64((aOrbiterH * 14597139848072319685U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3254456186337366437U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3472973415969046680U;
            aOrbiterI = RotL64((aOrbiterI * 14583566953969168353U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7905718972111691591U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15941413652144021522U;
            aOrbiterJ = RotL64((aOrbiterJ * 3473779492962783565U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10583964125960308762U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 13659925272340853715U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 16708294803316630743U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9487054537489454887U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13287757570441887517U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 17351439045329892107U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 51U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 44U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aCross, 54U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21784U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17513U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17258U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 18756U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 10U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aScatter, 30U)) + 8685374557928800912U;
            aOrbiterF = ((((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 3482312691892161229U) + aPhaseAOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 6948130297389161165U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 21U)) + 5506385663788942690U) + aNonceWordI;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 3U)) + 17859982009307397161U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 9178488809207094043U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 41U)) + 1835479501226057169U) + aNonceWordC;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5368101733632614939U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 9050459666576835422U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 10351719549990259551U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9042186993119635078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17528342580198295025U;
            aOrbiterD = RotL64((aOrbiterD * 14316671546614386775U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6495418332558436882U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8834495762667327342U;
            aOrbiterF = RotL64((aOrbiterF * 10783141541937645995U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4364314196965690905U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6357485231062120459U;
            aOrbiterI = RotL64((aOrbiterI * 289429584586504995U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3321488322626415347U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10817330671781848737U;
            aOrbiterC = RotL64((aOrbiterC * 15875919466358823335U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17974092279281611763U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2871472057292789157U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16104199340711015181U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15187929795092006849U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13482063681546475923U;
            aOrbiterJ = RotL64((aOrbiterJ * 14466266308157364963U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 20U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + aNonceWordE);
            aWandererE = aWandererE + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC) + aNonceWordF) + aPhaseAWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24414U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26383U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22175U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22149U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (((aWandererI + RotL64(aCross, 19U)) + 4259993311776766595U) + aPhaseAOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 27U)) + 2857813330021126753U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 43U)) + 1345396841329442896U) + aPhaseAOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 320992148982301024U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 5619109532065293074U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 51U)) + 10380157329426706345U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 5U)) + 12449831150625409695U) + aNonceWordE;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7847096607042268396U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11707184096803214678U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 1959476948106553973U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9893643746186827088U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 333687403830908774U;
            aOrbiterB = RotL64((aOrbiterB * 17911256836121454271U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13837360705077441580U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4367119682175710689U;
            aOrbiterH = RotL64((aOrbiterH * 10295744669174603401U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1193493435041306784U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15062951612027370606U;
            aOrbiterD = RotL64((aOrbiterD * 2509383510565136549U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16000173839235429105U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15294482444605409961U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1031800997944302665U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5720749055549773527U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17248674962996093668U;
            aOrbiterG = RotL64((aOrbiterG * 15730637462755795591U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16956840483882091059U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 9637715107943515594U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8878362378343603463U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 60U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 27U)) + aOrbiterB) + aNonceWordB) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 53U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 40U) + aOrbiterG) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 13U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordH);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30578U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32405U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31312U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 28807U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 10U)) + (RotL64(aIngress, 35U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 35U)) + 2672739400294801233U) + aPhaseAOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 29U)) + 8475624545015101850U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 47U)) + 1252755112289831257U) + aNonceWordG;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 7938039507649183387U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 8167413146948861022U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 53U)) + 17712313989694374353U) + aNonceWordA;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 21U)) + 7637042279892596975U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15770412950033467341U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3951812021898608685U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6623127125223204737U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8656983621098246507U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17943342344730687317U;
            aOrbiterC = RotL64((aOrbiterC * 16495519451034883813U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3087677463651608668U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 16493240011924342788U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 16898479041530771871U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7750923317452683057U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2185924841611106546U;
            aOrbiterA = RotL64((aOrbiterA * 708072658250726381U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14676868738946722416U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6849098251696302393U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2599806275837778069U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17817755047153606419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9900465270314068757U;
            aOrbiterD = RotL64((aOrbiterD * 9267925873983176685U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11380000891112113701U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15930503831156546113U;
            aOrbiterI = RotL64((aOrbiterI * 14450535035065393845U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterB, 56U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordG);
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

void TwistExpander_Boxing_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC8CB06688F0716DDULL + 0xC541F88E3F0C96D9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA2627C451A47FB99ULL + 0x947919F766D459D6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8C693CC5B301D839ULL + 0xFA7C020F97D24AEBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF3D8921B31C397EFULL + 0xA9419E54BE135FDEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDC321AC86C30E9FDULL + 0xF1782F460312661DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8C065F6C700314D7ULL + 0xD33372EF70CD275FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCD79744B2E7B8DDFULL + 0xA32FE36D5E5AE372ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCE564ADDA2B4369FULL + 0x940CA8D2E75AFABFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA99E623C4E2B2A9DULL + 0xC3936AC0B31693C6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x88BDB4358D790B4FULL + 0xB3E0FDF0C2279FFEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEEEC7CE3055BEF25ULL + 0x97FE401209B8F134ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE0F3F8E671C0DC43ULL + 0xE1F2C87DC64C7425ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEFF4545148937487ULL + 0x8A51F046AABDE05FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC312EDC1E1940CF7ULL + 0xD02D627B59FBB24FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD6DE27B79843BBD9ULL + 0xC01980C56F02E279ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8C9EA6A7B3BE446BULL + 0xDEFDB306EF9BC886ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 501U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 5390U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3805U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1316U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 56U)) + RotL64(aCarry, 27U)) + 1393781663398437180U) + aNonceWordA;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 17414594746688585273U) + aPhaseBOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 47U)) + 2823888497053071250U) + aNonceWordP;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 17032631958617884859U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 37U)) + 15222697630461125019U) + aPhaseBOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15737414920751551780U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1357196111055783001U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8225423829221938165U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5315122321649251691U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 7893744655508595974U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 17863000246694319149U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 16721939414324611738U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3444375866323610848U;
            aOrbiterE = RotL64((aOrbiterE * 10874157227815775661U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1825716513674511632U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15582066843912467318U;
            aOrbiterF = RotL64((aOrbiterF * 12765146555943757373U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 15673590949193923915U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13887365046280406413U;
            aOrbiterG = RotL64((aOrbiterG * 3169061375011420121U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterE, 58U)) + aOrbiterA) + aNonceWordH) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 36U) + aOrbiterE) + RotL64(aOrbiterD, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 38U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7218U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 8393U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9996U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8732U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererB + RotL64(aCross, 52U)) + RotL64(aCarry, 21U)) + 3255291173184001106U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 3U)) + 15308468160116255528U) + aPhaseBOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 18186972408589866656U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 4439324265978331914U) + aNonceWordJ;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 37U)) + 13099263173016322486U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7041561081767500660U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6196422612687812971U;
            aOrbiterB = RotL64((aOrbiterB * 13359900204297781063U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 7664260932541281413U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17802347823020441056U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2220679459017369255U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4253107484061190446U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13799496534030645312U;
            aOrbiterG = RotL64((aOrbiterG * 9167675060053848207U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14252892847595951926U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5663527578664291422U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18314294235895182465U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11148755959699137661U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17036900929333594592U;
            aOrbiterE = RotL64((aOrbiterE * 16041243617369003291U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 58U);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 60U)) + aOrbiterG) + aNonceWordN) + aPhaseBWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 42U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterG, 43U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14959U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 16345U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14398U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13373U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 57U)) + 6654158889644956636U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 9045779659363991870U) + aPhaseBOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 3U)) + 3888897662136993491U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 6882016842864459345U;
            aOrbiterK = ((((aWandererE + RotL64(aPrevious, 36U)) + RotL64(aCarry, 3U)) + 15601891715956172291U) + aPhaseBOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5176811598629335350U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12519945150889074325U;
            aOrbiterA = RotL64((aOrbiterA * 8721098129033306427U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4552583214397603278U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 14225482701804864688U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 8526052833180466359U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5485298070606280363U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11237713257388094289U;
            aOrbiterF = RotL64((aOrbiterF * 11032429223099413011U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14340345895626142788U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16275167270553643347U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7308578867128951199U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14041860597556520250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1436068974197066343U;
            aOrbiterK = RotL64((aOrbiterK * 3938460345031496843U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 3U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterF, 12U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18954U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20025U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18852U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 21753U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 37U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 60U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 15652862298542575895U) + aPhaseBOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 57U)) + 16925323928418184554U) + aNonceWordE;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 4413861484961668394U;
            aOrbiterA = ((((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 2215946422098155969U) + aPhaseBOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererD + RotL64(aCross, 26U)) + 14975185533513111110U) + aNonceWordO;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9711613814905834552U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13154957291850149471U;
            aOrbiterD = RotL64((aOrbiterD * 17049677190793844477U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5058313016418534840U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15011423472941211620U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6125316151731105673U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2030053257469580168U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 150530795186791193U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11106050063717096073U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 10878237472104183427U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11724672539469573109U;
            aOrbiterC = RotL64((aOrbiterC * 16158741837357985395U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9589700906445846956U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1367381624958248949U;
            aOrbiterH = RotL64((aOrbiterH * 8459515089081211977U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 28U)) + aOrbiterH) + aNonceWordD) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22627U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 24873U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25723U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25308U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 28U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 5573188770530340913U) + aNonceWordC;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 30U)) + 1431772230889897111U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 4809192776429682319U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 5576603692574369341U) + aNonceWordG;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 3U)) + 2720143226007220386U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17220328778565331629U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9629485808442089423U;
            aOrbiterG = RotL64((aOrbiterG * 18349580416082045015U), 41U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 1136998437010390983U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11893390497814523841U;
            aOrbiterH = RotL64((aOrbiterH * 5329621622743089531U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 1764986431917532370U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1741014798007010376U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13414914086049500731U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12221368453236547044U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 7694538641172350430U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 8439120733670016501U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17472344518811560603U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3308740700728172984U;
            aOrbiterB = RotL64((aOrbiterB * 15290400462887712083U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterH, 38U)) + aNonceWordN);
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + aPhaseBWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27330U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((aIndex + 29060U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30791U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 27907U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 38U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = ((((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 2168513956284366370U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 47U)) + 10290361969974613111U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 38U)) + 15673836275828498050U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 16600540024145812236U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 9428052101528111892U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12763657928312763377U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10751286982008662485U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6169084301655877217U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1708230173038057979U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4011389705422783816U;
            aOrbiterB = RotL64((aOrbiterB * 11692237130784795961U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11704428328093077714U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2055336619674699284U;
            aOrbiterI = RotL64((aOrbiterI * 6374289210096410907U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1870865272102705804U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3574214263751923179U;
            aOrbiterE = RotL64((aOrbiterE * 13132083406834413563U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 984611970726966186U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15207945449947643672U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 9539470161576639981U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 42U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 23U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + aNonceWordA) + aPhaseBWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 60U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Boxing_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB60AD351C321A7CFULL + 0xA526B5478F9890EBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE5C18F2B38DDC987ULL + 0x937D9F06AEDC08B9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD3EA6C48E06E7F75ULL + 0x9FFA3E5AD85E0802ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB4CCFA6C42C8CB2BULL + 0xCBEC84D1BBFB3EB4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB68A85AA9D80F14DULL + 0xA07E9CCCFBCACC8AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB0A51F59437FC4E7ULL + 0xECCEABBF372A0820ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x945EE735EE0090DDULL + 0xC736810DCA563C6AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCF925E2AAA3C00BBULL + 0x9A94EE090A0B6FB6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8EF14784C8A5B7CBULL + 0xB5A7A0398CE18B25ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC5B75F5808A07443ULL + 0x85210C622A84EAC0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAD7F4437201B7A8DULL + 0xD4E79C7663189C5DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB7B4A6260D341325ULL + 0x87B97CD98EA5E34DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEF3005BEDF8CA777ULL + 0x89F97CF251E71BD3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9C0BDE2495EF5FDBULL + 0xAF7B54BA3C3AD08BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF5F012C5EF7EACBBULL + 0xBF2BEDFF19FAE05BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x93E9764C7A2843FBULL + 0xBE71DE518945A85BULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3141U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2429U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8091U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2364U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 36U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 35U)) + 12980104182836602177U;
            aOrbiterI = (aWandererF + RotL64(aCross, 24U)) + 3172622203188863995U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 1170974132219980203U) + aNonceWordK;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 29U)) + 6035201940965047490U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 43U)) + 18033907118424996722U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 20U)) + 14604813424800580304U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 57U)) + 13720232492851066035U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 3902659710585257448U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 8331560652661619868U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4485014147538689794U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 168202636924512424U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13711020666131492091U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16227825670092707848U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4792781933944671365U;
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12636865372722601282U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 18198291399585556632U;
            aOrbiterA = RotL64((aOrbiterA * 18155803890313399795U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3650053185419807206U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5897288963905408776U;
            aOrbiterF = RotL64((aOrbiterF * 3706949366974086151U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9922308113622901726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13352279749091561510U;
            aOrbiterJ = RotL64((aOrbiterJ * 4025213180483632557U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14969461950939646117U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10231661776135056651U;
            aOrbiterK = RotL64((aOrbiterK * 11284575051455238501U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10621934544068320859U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6029116920305246887U;
            aOrbiterD = RotL64((aOrbiterD * 6087523725059376905U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12887482425168671195U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8351351557123783853U;
            aOrbiterI = RotL64((aOrbiterI * 3839381627914762245U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5405938210926464973U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 385145802287899406U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8330751480464271445U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterH, 60U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 53U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 34U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterD, 29U));
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterF) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15583U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 12027U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9135U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((aIndex + 15830U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 43U) + RotL64(aCross, 58U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 47U)) + 15910560457440369082U;
            aOrbiterF = (aWandererK + RotL64(aCross, 19U)) + 17953072986407436888U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 15446940721193538669U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 12U)) + 3020785262774422009U;
            aOrbiterD = (aWandererC + RotL64(aCross, 53U)) + 7001288645424994404U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 41U)) + 13385250665458462689U) + aPhaseCOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 4841895644623005949U) + aNonceWordB;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 13053476783239482065U) + aNonceWordO;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 30U)) + 641996979335975244U) + aPhaseCOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16211238020928688299U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12715448751323279480U;
            aOrbiterB = RotL64((aOrbiterB * 2116880429675303291U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17784406727699995290U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16626339815786580778U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13940754474750138041U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9035070625716345139U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6085848172494001945U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 10405728912339646693U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1177103851507561053U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2281901691017816407U;
            aOrbiterA = RotL64((aOrbiterA * 3142197009403602497U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9040984343694325070U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13334258224023902365U;
            aOrbiterJ = RotL64((aOrbiterJ * 4782523727707164869U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1079824790138592518U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14024082692012948652U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3219489374333737903U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2966776524421278970U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5510281854029308547U;
            aOrbiterI = RotL64((aOrbiterI * 9275402927591867297U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7126632329316720048U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1476827035602733472U;
            aOrbiterE = RotL64((aOrbiterE * 2217671289726794033U), 23U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 6470212302133184965U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4172257438373147415U;
            aOrbiterF = RotL64((aOrbiterF * 4449314239630366533U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 36U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + aNonceWordN);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterG, 58U)) + aNonceWordM) + aPhaseCWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22576U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 21296U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17110U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22595U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 38U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 4970414922752555648U) + aPhaseCOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aWandererE + RotL64(aIngress, 19U)) + 9462756592787669327U;
            aOrbiterF = (aWandererF + RotL64(aCross, 5U)) + 3948790686662213095U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 30U)) + RotL64(aCarry, 27U)) + 14542857212241578311U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 3387479009827029547U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 23U)) + 1411421370057797877U) + aPhaseCOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aScatter, 51U)) + 16894451466895681236U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 10U)) + 12727136462290223542U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 47U)) + 4625389198191960525U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3471881403786164913U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6433115856048534831U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9363233870194144053U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9825592965466157982U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1553125767261293088U;
            aOrbiterG = RotL64((aOrbiterG * 411535191177308781U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9951616357109647617U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11231080382787286889U;
            aOrbiterK = RotL64((aOrbiterK * 14024961994986659187U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13419663264017317947U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4835055642466215566U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 17898065852351759171U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14558747666410946768U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13120938960926874504U;
            aOrbiterJ = RotL64((aOrbiterJ * 5681766019285559739U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11910501376797343986U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15074100100781785300U;
            aOrbiterD = RotL64((aOrbiterD * 228976960937473851U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12415377930578091821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14882039078390681802U;
            aOrbiterI = RotL64((aOrbiterI * 13855446647753150713U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8094338361713756895U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5478280604704108822U;
            aOrbiterE = RotL64((aOrbiterE * 18062931724700600993U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6977017654546871841U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 4131602217285988962U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 11865422227883712419U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 18U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterC, 4U)) + aNonceWordP) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterE);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 21U)) + aNonceWordE) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 48U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 48U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 52U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32637U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 25379U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24789U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 31354U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 18U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 15904465836916519864U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 41U)) + 17725629806317789307U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 13794170125914914828U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 12U)) + 2149055907476874332U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 5U)) + 5342047776745074649U) + aPhaseCOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 8268148484060546838U;
            aOrbiterI = (aWandererC + RotL64(aCross, 37U)) + 10821151364028563719U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 60U)) + 4294213820894407378U) + aNonceWordB;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 19U)) + 10884726101307943090U) + aNonceWordO;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16432210042202444824U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15196602644336228055U;
            aOrbiterC = RotL64((aOrbiterC * 12680438355124070237U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14117787670220328165U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 219833877949480215U;
            aOrbiterA = RotL64((aOrbiterA * 10736293047771972173U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3326396981881473962U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14918513066311426279U;
            aOrbiterI = RotL64((aOrbiterI * 14269763278564574663U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11795234681370163206U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3068267285352664813U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 15746255933920904619U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 245233356957999496U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 709926406353796673U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 13627039596842073595U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5378105439430271038U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 10114555061122044430U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5351295043424885549U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13233010815716769713U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8231291294833548389U;
            aOrbiterJ = RotL64((aOrbiterJ * 10840516135212753869U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7160760224172419829U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14767926435411546785U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1643485739468851073U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4464245330038080103U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15778166658285494712U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13980891936095282989U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 10U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterK, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 14U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererA, 6U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Boxing_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB78B8DFEEBE9F857ULL + 0xADA4739B4D6EB89DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF01DDE5D375D72D1ULL + 0xEC951C9AAEDE7182ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC8D6269DD3FBCB87ULL + 0xDD4583BEC50ED44EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD45B13061F5010E9ULL + 0x9591BCD62B4D66B8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCA6782C10D473853ULL + 0xED18219D362C1119ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF424442AB9F7662BULL + 0x847F646AA569B8ACULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x819516B71EF4A277ULL + 0xD9D4FC9E08B1FE99ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB74827E3FEC75C33ULL + 0x9E906BD83A42B522ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBE9FA22549E8E2CDULL + 0xCC2EE42638C21125ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF3C4A15DFE6293A5ULL + 0xECB316352277E47BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC0293DB837B0C703ULL + 0xBD86F66ECA3670D8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCC753103FC6CC78BULL + 0xEA51A8C6E2BA4E22ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDEB24F7973ED8F6BULL + 0xD0D0F88E2A502458ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF59AF10E904E2373ULL + 0xFBDAD70C9D392C14ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC8E9A4448B167A59ULL + 0xCF6E7907CCE40710ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD6F3049A1FCFE5BDULL + 0xDD6D44C41CB2E5ACULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3157U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2603U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3175U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 2648U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aPrevious, 47U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 18U)) + RotL64(aCarry, 23U)) + 1364174714924216027U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 43U)) + 13561796874229506613U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 57U)) + 11845572344206238305U) + aNonceWordA;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 39U)) + 15762708240326773763U) + aNonceWordL;
            aOrbiterH = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 1157119665207900473U) + aPhaseDOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 41U)) + 6823546624372055260U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 6U)) + RotL64(aCarry, 51U)) + 14465564210523945121U) + aNonceWordH;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 51U)) + 10667464548080807531U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 53U)) + 13445737493224316575U) + aPhaseDOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 37U)) + 3009837893785957665U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 21U)) + 2886920524111083752U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10886177449328249656U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15067759884678100433U;
            aOrbiterF = RotL64((aOrbiterF * 5724566815989860041U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18307930462682331536U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8791864377579255801U;
            aOrbiterD = RotL64((aOrbiterD * 9265158882471421767U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 805797468642992351U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5743305867058244964U;
            aOrbiterG = RotL64((aOrbiterG * 16263000753351131717U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17102025528234481273U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1841579177327486899U;
            aOrbiterC = RotL64((aOrbiterC * 3841603385577825265U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2189493507896508972U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18209567010094914374U;
            aOrbiterI = RotL64((aOrbiterI * 3737080408976852351U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6697069234216868330U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 927471474577415372U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10680760991009199309U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13155854301197725408U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1014625081915435892U;
            aOrbiterB = RotL64((aOrbiterB * 11592754232949990435U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12697209921410914931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11555096613655648647U;
            aOrbiterA = RotL64((aOrbiterA * 4598821388864997089U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9335308231651271690U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3160859883353473444U;
            aOrbiterH = RotL64((aOrbiterH * 4753600703924906409U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 15681189182414315768U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3147692210581710663U;
            aOrbiterJ = RotL64((aOrbiterJ * 6271949093080510861U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5373388632562432117U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1364174714924216027U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4694926665965807945U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 48U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 37U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterE, 39U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterB, 23U)) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterB, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 42U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6736U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7196U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8462U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6820U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 50U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 47U)) + 13924571355038625040U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 58U)) + 16328300979357156658U) + aNonceWordI;
            aOrbiterB = (aWandererA + RotL64(aScatter, 53U)) + 3947771961206012461U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 3U)) + 15428284250569311285U) + aNonceWordC;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 37U)) + 5777369485254032486U;
            aOrbiterK = (aWandererD + RotL64(aCross, 19U)) + 16813320300717644673U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 16689933050200758251U) + aNonceWordD;
            aOrbiterD = (aWandererG + RotL64(aScatter, 21U)) + 1856422419049390708U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 18214498743831925517U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 60U)) + 18278550878494094923U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 797712062039591797U) + aPhaseDOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15854849439012341347U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 996882939768167773U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14936703950807908575U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3005829974130671692U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8793495343509953906U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14065479348374612031U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7710453029930631112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9511995836117707047U;
            aOrbiterH = RotL64((aOrbiterH * 7250766204781428201U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 670902975693341744U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9045820304668279777U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 18373074917532639027U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12417212387607119470U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12816983560669985622U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8406003970221889847U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17245432086377688540U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6806521945548502014U;
            aOrbiterE = RotL64((aOrbiterE * 11335859481858640857U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8947500746292365294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4468060468522895852U;
            aOrbiterA = RotL64((aOrbiterA * 7022481284816599797U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9892975931958803992U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3042599331526937836U;
            aOrbiterK = RotL64((aOrbiterK * 3308512896171443645U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12991568221485810891U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8551331172836260315U;
            aOrbiterD = RotL64((aOrbiterD * 4509997595920847057U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 183547209633334407U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17275712817092769452U;
            aOrbiterJ = RotL64((aOrbiterJ * 15677355290000929085U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12743863879392372723U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13924571355038625040U;
            aOrbiterI = RotL64((aOrbiterI * 11966689345179279407U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 56U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 18U) + RotL64(aOrbiterI, 14U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + aPhaseDWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterF, 39U));
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 60U));
            aWandererB = aWandererB + (((RotL64(aScatter, 38U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13764U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13197U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14563U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 11273U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 3U)) + (RotL64(aIngress, 52U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 7948891781097675369U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 37U)) + 13928362874228230226U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 60U)) + 10776180542602258926U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 5735115172149470447U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 27U)) + 5353591822981766987U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 3U)) + 562301708107268570U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 13U)) + 10467810247578364868U;
            aOrbiterG = (aWandererH + RotL64(aCross, 23U)) + 14541630141152308564U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 53U)) + 2350076897065139429U) + aNonceWordK;
            aOrbiterE = (aWandererG + RotL64(aCross, 56U)) + 17519109078651162228U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 41U)) + 6061035173339902910U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15654836633731000065U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13723521735153718904U;
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2849680038315532197U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17336102435576647923U;
            aOrbiterH = RotL64((aOrbiterH * 10984689101753586739U), 37U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 7671010488872356142U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11485114338165600777U;
            aOrbiterC = RotL64((aOrbiterC * 4162584865462407791U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8759060657343458985U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11009137869375286581U;
            aOrbiterK = RotL64((aOrbiterK * 8741417343929809115U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15792999392743144135U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6180808423175992479U;
            aOrbiterG = RotL64((aOrbiterG * 13681230339693676907U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 361487389591183005U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15292753806514404853U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17478232597253311153U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14929153438443362045U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7904556383593914086U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2484130486635511403U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3793180909904286848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10391957637467171320U;
            aOrbiterJ = RotL64((aOrbiterJ * 505484041943467117U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11648765065563798353U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17601185776537566611U;
            aOrbiterA = RotL64((aOrbiterA * 4753179291885740011U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2907499704986356444U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 17048858067202291241U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 2607549567999666889U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4340465159886930775U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7948891781097675369U;
            aOrbiterB = RotL64((aOrbiterB * 12913104720552907335U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 18U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 36U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 60U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 37U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 50U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 30U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 13U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + aNonceWordB) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 47U)) + aOrbiterB) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + aPhaseDWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21788U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18023U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20347U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 16582U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 51U) + RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 53U)) + 11998579547770778580U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 8409465187298704610U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 11U)) + 3470222286110333500U) + aNonceWordJ;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 29U)) + 5704486785203069994U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 27U)) + 10334944660253279633U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 57U)) + 7626852700722567477U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 41U)) + 14631310754943209743U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 37U)) + 807160297237854120U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 39U)) + 5624154783624196107U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 4971444394698940423U) + aPhaseDOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 48U)) + 6340057638461027062U) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9003019862787819481U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13632057463595873033U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12575202147280216765U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12766104026871797746U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4062118445824915939U;
            aOrbiterI = RotL64((aOrbiterI * 13130770039048080701U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5258212525426469978U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9956946981015983939U;
            aOrbiterB = RotL64((aOrbiterB * 8106382657040497669U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10837606223056473999U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13292864885504191134U;
            aOrbiterH = RotL64((aOrbiterH * 4445739587553669471U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 166087925900318658U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6786842221885441388U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 4411147600413147773U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16888086378070246404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5240855484445974002U;
            aOrbiterF = RotL64((aOrbiterF * 402652898573422271U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6874866669211571608U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 732890824978127460U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 3776365957702257453U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5541380495707308058U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17947326584411475765U;
            aOrbiterK = RotL64((aOrbiterK * 10920952349981652899U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15060679340045767910U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1675974028461383576U;
            aOrbiterG = RotL64((aOrbiterG * 15127962310365242819U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 226889112033170368U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4290719734244011388U;
            aOrbiterJ = RotL64((aOrbiterJ * 6453598182035414143U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7712233480730639084U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11998579547770778580U;
            aOrbiterC = RotL64((aOrbiterC * 11599893373156816375U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 46U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterI, 43U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 22U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 23U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 60U)) + aOrbiterD) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 38U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 34U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 26246U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 26393U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26337U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 25077U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCross, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 13U)) + 6024062041314952357U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 11U)) + 18340757093658015585U) + aNonceWordB;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 11911120493880346751U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 20U)) + 17428074353884654439U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + 12790849760814795936U) + aNonceWordG;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 12633397052172117800U;
            aOrbiterA = (aWandererE + RotL64(aCross, 39U)) + 11946150433665237945U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 16842157900909419285U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 51U)) + 14186235783224155962U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 35U)) + 13284904542579767591U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 18U)) + 11609181965078844357U) + aNonceWordM;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9628562297095374984U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7850281529011259759U;
            aOrbiterC = RotL64((aOrbiterC * 17611485102925470357U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 257458718073794527U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10693404545773519306U;
            aOrbiterE = RotL64((aOrbiterE * 14821443722828498323U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3430519236533871460U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6183054506953198055U;
            aOrbiterB = RotL64((aOrbiterB * 6121082743789970911U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2905610989884221654U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4472163910775333862U;
            aOrbiterG = RotL64((aOrbiterG * 7770678426310856745U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16870142883133769663U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 1403692060594816451U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 9740854430251597879U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16904169913507057108U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4773518591580333357U;
            aOrbiterK = RotL64((aOrbiterK * 5306070307776061267U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6528141733853494275U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11254806909313951442U;
            aOrbiterA = RotL64((aOrbiterA * 6316669786405548827U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6857506858448143407U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2855763534355983644U;
            aOrbiterH = RotL64((aOrbiterH * 16881334940165182415U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12328391751024624740U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16475072086109949522U;
            aOrbiterD = RotL64((aOrbiterD * 15218626930666825883U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15505670341076785424U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6972128419331939330U;
            aOrbiterJ = RotL64((aOrbiterJ * 12206069109180246067U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7151546362283646210U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6024062041314952357U;
            aOrbiterI = RotL64((aOrbiterI * 10243806128059850493U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 38U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterF, 21U));
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 54U)) + aOrbiterB) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 43U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 13U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 4U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + aNonceWordP) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29080U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32675U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28275U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 32759U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 10U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 6068543441070417854U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 39U)) + 2995980468193441856U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 57U)) + 18020277482171594003U) + aNonceWordA;
            aOrbiterK = (aWandererH + RotL64(aCross, 41U)) + 4293807434721230702U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 5U)) + 7980599111583893156U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 8593141111851052016U) + aPhaseDOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 35U)) + 5903487523900084325U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 43U)) + 15112035513447930209U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 18U)) + 9854037263057006439U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 16759760289688823193U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 21U)) + 12622628933030601390U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1264668857268123425U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16302812053619101593U;
            aOrbiterA = RotL64((aOrbiterA * 18291400055836111547U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16087995784896123610U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7970269262800468363U;
            aOrbiterD = RotL64((aOrbiterD * 14924752223305807461U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5331477046030959632U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16534913204255550893U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1013433634373673565U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11042821902537871209U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8069677512345031660U;
            aOrbiterJ = RotL64((aOrbiterJ * 13622218526054132397U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5737130058129936372U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1076627182956662997U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14342191224014199929U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13911061091801078190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15397603151098990373U;
            aOrbiterI = RotL64((aOrbiterI * 1802890451633592245U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15137326716738637972U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11248737008959896786U;
            aOrbiterC = RotL64((aOrbiterC * 90789374131547005U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1847847987633923657U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10560748778679145431U;
            aOrbiterG = RotL64((aOrbiterG * 2919333327817231099U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2703726238610290251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12950671360471467310U;
            aOrbiterB = RotL64((aOrbiterB * 7490327691501537047U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10331504168520449467U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1541527607705280906U;
            aOrbiterF = RotL64((aOrbiterF * 14197400812600186171U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9135056476214341809U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6068543441070417854U;
            aOrbiterK = RotL64((aOrbiterK * 14102524444094948875U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 10U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterI, 34U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 26U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterB, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 52U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordF);
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

void TwistExpander_Boxing_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC635577558293051ULL + 0x86AA4247714EE2B8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC1B5036D7816AEB5ULL + 0xE17F7747C2710B13ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC35CB3BF3161DF21ULL + 0xD605718F6933A9C9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD21335088069C713ULL + 0x9A5E20A7752D863DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA9CEAB02A825CCB9ULL + 0xE3FD4F8AC2D227CDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF2875B7AD3322ACDULL + 0xF386A655CACE166DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x87027F24BCEAF985ULL + 0xB0FD1439E54D243FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC44BA6D731707565ULL + 0xE34F456C7EF0F7FEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB61E8B232BC78B39ULL + 0xD7AA2268DD4833BFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA20CE52D1DC1CF73ULL + 0x9D8BE77E59EC7B90ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x966F806DB8B98B77ULL + 0x974F0B958FDB641FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEE88BE9524848073ULL + 0xE00E19C0D2EC78CBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF3848B8F4E16FDA1ULL + 0xED9655E4DA730E07ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBF7F98618F5392DFULL + 0x9F6D864D03F64AE9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA4472CE37EF2D079ULL + 0xA0FE2AEF0453AD72ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9320280E2850B577ULL + 0xD04CE744E634391AULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3483U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 4307U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3138U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 20U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 35U)) + 3561491146322798260U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 21U)) + 7075025056181885339U) + aNonceWordB;
            aOrbiterG = (aWandererE + RotL64(aCross, 50U)) + 9230910887904171613U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 4119781172609908917U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 43U)) + 17155609083870983149U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 5U)) + 2423018561430181695U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 37U)) + 12957280305617615744U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 27U)) + 2461704174772065813U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 46U)) + 7907123257849391997U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 7257868138318960007U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 16425903703085702285U) + aNonceWordE;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2990822664594079467U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5654819006718953817U;
            aOrbiterG = RotL64((aOrbiterG * 4465096036756887801U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12183676471235678779U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15026286960542123922U;
            aOrbiterF = RotL64((aOrbiterF * 17199049329995315279U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12169080607071830522U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2906296852254787499U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6754514406846040163U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3029858695410344584U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14406410317495954566U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 9663780721657983421U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11048818178401163861U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13622063920319445043U;
            aOrbiterB = RotL64((aOrbiterB * 2516025554421589857U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2642646089141233277U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12761571777929273548U;
            aOrbiterK = RotL64((aOrbiterK * 5518252696078700127U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7753802695131502382U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8510425459525030222U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 12412361423636026483U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13522645164493316722U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1437430302489702713U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14019316635365783545U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14745189473423751499U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16968328257002103715U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 17915588590593471981U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5001838243344386314U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13506188720092630563U;
            aOrbiterE = RotL64((aOrbiterE * 7010027510838271877U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16902624500530747723U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3561491146322798260U;
            aOrbiterI = RotL64((aOrbiterI * 95761172090277669U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordO) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 28U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterF, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 36U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 40U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10620U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10617U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7760U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 10618U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 10U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 2571116506511057880U) + aNonceWordO;
            aOrbiterG = (aWandererB + RotL64(aIngress, 38U)) + 13112435411509707292U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 10403251762787357256U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 27U)) + 8461951095541400405U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 21U)) + 9890793478557463815U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 5U)) + 3030229465991783707U) + aNonceWordD;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 7273848154043719247U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 3U)) + 10681774862516028276U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 34U)) + 7105082755586853104U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 43U)) + 6588579345319551129U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 41U)) + 14616333550242386092U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15439666290229654921U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3360304356760164799U;
            aOrbiterA = RotL64((aOrbiterA * 5164191920584106237U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14438730801970761889U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14515616787452085729U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2041601927968559821U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4167853822635132419U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8950982233003320239U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 887144270884244907U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12391327853728029953U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7100871010552394421U;
            aOrbiterE = RotL64((aOrbiterE * 16552349374101955967U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 15381697462381887944U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6801677551341079401U;
            aOrbiterC = RotL64((aOrbiterC * 13325954438427340703U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 947011315719204867U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6356920162398333481U;
            aOrbiterB = RotL64((aOrbiterB * 5566721941682667419U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8910262020598577378U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8778455415977526457U;
            aOrbiterI = RotL64((aOrbiterI * 4092470497616637283U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5585696961453127223U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9670655481681494412U;
            aOrbiterJ = RotL64((aOrbiterJ * 7863197168965036383U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10713004007087085729U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4036355047492922339U;
            aOrbiterF = RotL64((aOrbiterF * 6923922258047667173U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14580156873863533497U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7049502932205025182U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8665428649262370727U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12707521269341941677U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2571116506511057880U;
            aOrbiterH = RotL64((aOrbiterH * 2388236789245943699U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterI, 54U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 38U) + aOrbiterF) + RotL64(aOrbiterJ, 41U));
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 29U));
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 37U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 51U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + aPhaseEWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 58U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + aPhaseEWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13992U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11193U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12529U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((aIndex + 12593U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 36U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 3248574644570178787U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 47U)) + 4506961512959200024U) + aNonceWordH;
            aOrbiterK = (aWandererK + RotL64(aCross, 29U)) + 8423739774540738590U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 39U)) + 6593975869641735337U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 27U)) + 16441716090557369103U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 54U)) + RotL64(aCarry, 29U)) + 7936601450453207914U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 13333752583560167065U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 5U)) + 8013703284795432973U) + aPhaseEOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 13U)) + 2349852779887439236U) + aNonceWordE;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 19U)) + 5318539364763284138U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aCross, 22U)) + 11450957608502944376U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9058992558327552687U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 632095686920230926U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12460364388358520799U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14734218428913777098U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16344357661370784442U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15049472842002138369U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2981145363531184308U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14176472085175714494U;
            aOrbiterD = RotL64((aOrbiterD * 2584623327412130939U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11198457590069700889U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 952584436750426828U;
            aOrbiterI = RotL64((aOrbiterI * 1165713888651280355U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4311591763498985972U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16194341833989936369U;
            aOrbiterB = RotL64((aOrbiterB * 9997934560195932575U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7560794022401107431U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10683789740265711603U;
            aOrbiterE = RotL64((aOrbiterE * 15637823045351977883U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11614366395125937178U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10750771385100564416U;
            aOrbiterJ = RotL64((aOrbiterJ * 4987921274272444283U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2934697034132204529U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4646873794658020363U;
            aOrbiterH = RotL64((aOrbiterH * 10555456865641580175U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7913681837683568905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17603563535330106340U;
            aOrbiterG = RotL64((aOrbiterG * 17882943067522319671U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15375641415139193079U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17059712718085411887U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 13722089235751208215U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14022558453716067200U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3248574644570178787U;
            aOrbiterF = RotL64((aOrbiterF * 15249135451439374621U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 53U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 21U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 10U)) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterI, 40U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17765U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19574U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17112U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19053U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 24U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 9446153639709651566U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 47U)) + 10550762260670758167U;
            aOrbiterE = (aWandererE + RotL64(aCross, 34U)) + 7062634922142578383U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 9178499097812764515U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 41U)) + 6887103379773525538U) + aNonceWordC;
            aOrbiterH = ((aWandererB + RotL64(aCross, 5U)) + 6239750312052010257U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 37U)) + 17645022614523287959U) + aNonceWordB;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 30U)) + 3639618183259408272U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 27U)) + 3131737117548745095U;
            aOrbiterD = (aWandererG + RotL64(aCross, 3U)) + 7253994382396406554U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 15217993711938379561U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12594152227603630033U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 11250170200489647869U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 546800378327864723U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12936942656624279424U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10990736056052106149U;
            aOrbiterG = RotL64((aOrbiterG * 7123916809953459187U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12787293075893090465U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17154990205620778151U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10031369940028159521U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1270827262969060301U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17337623431665013136U;
            aOrbiterB = RotL64((aOrbiterB * 1517262088236356107U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 830330490987911853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6828309232554560547U;
            aOrbiterK = RotL64((aOrbiterK * 9742464176986145819U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11470087853413986203U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10470148870747884420U;
            aOrbiterA = RotL64((aOrbiterA * 6766079738799967443U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18315536891901859637U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12264670822285914271U;
            aOrbiterD = RotL64((aOrbiterD * 5841574505408674119U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10931842095884524879U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11134871340959676257U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 11714837622285605745U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 11484168476761306078U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5964766416973454097U;
            aOrbiterJ = RotL64((aOrbiterJ * 14721123403032510803U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10646362765367117994U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8994267196877016381U;
            aOrbiterI = RotL64((aOrbiterI * 17386417559346134797U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16797547458402042464U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9446153639709651566U;
            aOrbiterC = RotL64((aOrbiterC * 567585472220695323U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 58U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 50U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 13U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 26U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterA, 23U)) + aNonceWordL) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 28U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24506U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 24400U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22315U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 25911U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 44U)) ^ (RotL64(aIngress, 13U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (((aWandererB + RotL64(aScatter, 57U)) + 7960325128608297381U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 23U)) + 12773836012104052042U;
            aOrbiterB = (aWandererD + RotL64(aCross, 52U)) + 3173972621347773016U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 3708401356314308171U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 39U)) + 950774285720019449U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 4170092315705438265U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 17000449130864980747U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 11U)) + 8793910540062893860U;
            aOrbiterI = (aWandererC + RotL64(aCross, 3U)) + 520277969543516469U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 29U)) + 12762214857389827271U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 42U)) + 2932451184340207695U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11062179998786293839U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7919119215271524178U;
            aOrbiterB = RotL64((aOrbiterB * 9053677007180081359U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1774988449597115155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3799792889466518953U;
            aOrbiterJ = RotL64((aOrbiterJ * 17512791286490623455U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1815062051307896589U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15260373951371654483U;
            aOrbiterK = RotL64((aOrbiterK * 2208604434669491625U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12867546628945676853U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7772820973895846946U;
            aOrbiterC = RotL64((aOrbiterC * 7581704643538761985U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14213957831821966834U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16561105721170419454U;
            aOrbiterD = RotL64((aOrbiterD * 2540533987337175367U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16556502948339949526U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9706742922075498974U;
            aOrbiterG = RotL64((aOrbiterG * 8527361328901355457U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13455756934917486016U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 9107769876332723454U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1722386100852683783U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 15793099079168487016U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7968278803691283365U;
            aOrbiterI = RotL64((aOrbiterI * 11644765391940099387U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15068302421261745111U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11373111908765197862U;
            aOrbiterF = RotL64((aOrbiterF * 17756438368103196771U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6362100123286229887U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 528778333872160609U;
            aOrbiterH = RotL64((aOrbiterH * 17377710146983314215U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6116442644744391285U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7960325128608297381U;
            aOrbiterA = RotL64((aOrbiterA * 17826511435509927061U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE + (((RotL64(aIngress, 10U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 34U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + ((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 19U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB + (((((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 30U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordE) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31482U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 32427U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28062U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27431U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 7270044678408187242U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aWandererF + RotL64(aScatter, 3U)) + 10192278965379756766U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 10U)) + RotL64(aCarry, 41U)) + 17568666746676060748U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 23U)) + 14312927531124963037U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 9825825726152087706U;
            aOrbiterB = (aWandererK + RotL64(aCross, 19U)) + 9696778570255265896U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 29U)) + 17657841352013417228U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 47U)) + 16207815085909628439U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 5U)) + 1752979206374514227U) + aNonceWordJ;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 41U)) + 10456310689643905854U) + aNonceWordE;
            aOrbiterK = (aWandererC + RotL64(aScatter, 56U)) + 16127830548663742550U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2940917376003930842U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7353596864777649953U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7499468723171042005U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12725092740446150705U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5791296650856037010U;
            aOrbiterD = RotL64((aOrbiterD * 760379251950502133U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1200130368046206150U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16689604428598558547U;
            aOrbiterB = RotL64((aOrbiterB * 13815324235939996623U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14359561591103730856U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3975025843599045263U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 5025047888533298617U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14017901732955607601U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10431526786489555196U;
            aOrbiterH = RotL64((aOrbiterH * 10181915874476132407U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7320527073559849223U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15333411223710709907U;
            aOrbiterC = RotL64((aOrbiterC * 3488684905528068775U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14302474063321663801U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2104154521019935187U;
            aOrbiterG = RotL64((aOrbiterG * 12944382959742278055U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5167600586916325228U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4566823109447208716U;
            aOrbiterK = RotL64((aOrbiterK * 9997799807454267443U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12475580453805083495U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15461491763911887974U;
            aOrbiterJ = RotL64((aOrbiterJ * 13548865386159287481U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11000532703581114393U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7815822789941347770U;
            aOrbiterI = RotL64((aOrbiterI * 1476638214324946775U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2166336159928211562U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 7270044678408187242U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 10648564933168714815U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 38U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 30U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 24U)) + aOrbiterI) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterH, 19U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 26U) + aOrbiterG) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererB, 52U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordA);
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

void TwistExpander_Boxing_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x97BDE77D729CE163ULL + 0xD41F9A02816651C3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC7191FEB9978315FULL + 0xD73B1CAB61CA5738ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x858587D3E3045797ULL + 0x8B34496752B08D14ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAC8D415CEF91D1C7ULL + 0xC2EA4B30BFAB30D3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEE08DED966678CC1ULL + 0xC31FC02A52F732B1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9EDC348C1143BCC5ULL + 0xFDD84264FF8D459EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBDF85D5ABB0A7A91ULL + 0x9595C30D477A4E12ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC3640C9A8D030339ULL + 0x8CADFADB2902F088ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB4F848B9D36EA0F3ULL + 0xE1990CB60F7BE136ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC542E286F05DA405ULL + 0xB11E9F67D997A9DFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9C61542F9BC0E13FULL + 0xC3A1D562042948B9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFD3DC94E37981C25ULL + 0x988115C8EA799068ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD0692FBF73502A09ULL + 0xBE44D5545C59652FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAACF510A76F887DDULL + 0xE2BB74C704382568ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB31BEFBEFE3D710DULL + 0xB84347F41E2CB5BEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB35BA629C709B071ULL + 0xB36EB820E69CDE39ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2865U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4365U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1454U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 649U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 20U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 39U)) + 8506388683755208267U) + aNonceWordH;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 47U)) + 2179323259055019735U) + aPhaseFOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 37U)) + 3345902531140983016U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 6U)) + RotL64(aCarry, 43U)) + 17456139311481306584U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 14587864088462311164U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 53U)) + 13178947246650647057U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 43U)) + 12866578138946916962U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 58U)) + 13098524333655118173U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 19U)) + 15451329483787541982U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 21U)) + 9494299579678389385U) + aNonceWordM;
            aOrbiterF = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 15581954810375490643U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4487042505730624892U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2774455928791636186U;
            aOrbiterI = RotL64((aOrbiterI * 15847933919136777451U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12435319582397755819U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10077180055177766823U;
            aOrbiterK = RotL64((aOrbiterK * 3924363471701748703U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10391963896910956455U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6149237416725301794U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 10115917698918612823U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15673402771629639978U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14729117178956592426U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9070464269215820531U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14492001279368870240U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6278248084483259952U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16731228350971263873U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 15727518866499740411U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8652631010810965473U;
            aOrbiterG = RotL64((aOrbiterG * 9508484121620912715U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13660890300188313775U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14699253534935936300U;
            aOrbiterF = RotL64((aOrbiterF * 3978135617259934869U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1621689916308271346U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5651399428852950385U;
            aOrbiterD = RotL64((aOrbiterD * 12220143634120124133U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9833573729127477238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11171647423058940388U;
            aOrbiterJ = RotL64((aOrbiterJ * 9692915620701425697U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10346908196429120039U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11972183669378621435U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12364429258926549335U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11063215816236490488U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8506388683755208267U;
            aOrbiterE = RotL64((aOrbiterE * 11514304191652750181U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterF, 39U));
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 12U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 41U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 50U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 37U)) + aOrbiterG) + aNonceWordD);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + aNonceWordP) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10824U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 8158U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10407U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5807U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 51U)) + 4259993311776766595U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 29U)) + 2857813330021126753U) + aNonceWordD;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 18U)) + 1345396841329442896U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 21U)) + 320992148982301024U) + aNonceWordH;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 5619109532065293074U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 10380157329426706345U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 11U)) + 12449831150625409695U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 43U)) + 7847096607042268396U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aWandererG + RotL64(aScatter, 23U)) + 11707184096803214678U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 38U)) + RotL64(aCarry, 5U)) + 9893643746186827088U;
            aOrbiterD = (aWandererC + RotL64(aCross, 13U)) + 333687403830908774U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13837360705077441580U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4367119682175710689U;
            aOrbiterJ = RotL64((aOrbiterJ * 10295744669174603401U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1193493435041306784U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15062951612027370606U;
            aOrbiterC = RotL64((aOrbiterC * 2509383510565136549U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16000173839235429105U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15294482444605409961U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 1031800997944302665U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5720749055549773527U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17248674962996093668U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15730637462755795591U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16956840483882091059U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9637715107943515594U;
            aOrbiterB = RotL64((aOrbiterB * 8878362378343603463U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7147495779349862274U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7508890985889484275U;
            aOrbiterK = RotL64((aOrbiterK * 17728368447504622035U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4407738164617959366U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17027017782352660454U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 417183060881259295U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3174658601748235285U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9779053567370714831U;
            aOrbiterA = RotL64((aOrbiterA * 6383245776181968033U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16256981360027888091U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12778335633397105924U;
            aOrbiterG = RotL64((aOrbiterG * 10821225965811763659U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13985909343937844583U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14307218309393008729U;
            aOrbiterF = RotL64((aOrbiterF * 12053366452617039877U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15549857305890093491U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4259993311776766595U;
            aOrbiterD = RotL64((aOrbiterD * 13703695714360435719U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 24U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterK) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12721U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16103U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11719U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16352U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 30U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aScatter, 41U)) + 12692813903177772178U;
            aOrbiterA = (aWandererF + RotL64(aCross, 50U)) + 7112496446691277899U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 35U)) + 2112247138290568813U) + aNonceWordJ;
            aOrbiterK = (aWandererG + RotL64(aIngress, 19U)) + 3699421080882855947U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 53U)) + 13761832028354380922U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 11U)) + 9243822514887600214U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 4U)) + 6863833516853046129U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 8863897995943098018U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 13U)) + 13346785686701467520U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 15309543066305531619U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 17515530938817919111U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 760493237816424254U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7282586354117620860U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 2327153408185290635U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4129706068526969105U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7020175432730888755U;
            aOrbiterG = RotL64((aOrbiterG * 10095158356907592239U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9102258982216515596U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10822031305361453690U;
            aOrbiterA = RotL64((aOrbiterA * 2036205056490578491U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12571477440964330246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8436347026653095199U;
            aOrbiterH = RotL64((aOrbiterH * 17930734781213681573U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14214789872073941940U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12915911919403385001U;
            aOrbiterE = RotL64((aOrbiterE * 13161681603528031511U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15443240166233851298U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7311369180113240915U;
            aOrbiterB = RotL64((aOrbiterB * 13339195007946889423U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12976516224995960015U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7823308381434556721U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 502385172763861451U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4829417661664149137U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16306394751966719700U;
            aOrbiterK = RotL64((aOrbiterK * 5294376579588592157U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16769868341852572677U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7107433163189177642U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5279050651595743649U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11896784111967113871U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 389626690429371003U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 10665914532159182181U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8226849597052979358U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12692813903177772178U;
            aOrbiterI = RotL64((aOrbiterI * 17909062471564422847U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterG, 53U)) + aNonceWordG) + aPhaseFWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterB, 18U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 43U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 34U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 50U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17797U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((aIndex + 19548U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18754U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19273U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 11U)) + 4068921616130916949U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 12077715273915151726U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 37U)) + 16047546802670596833U) + aNonceWordP;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 5U)) + 9690277462716999763U) + aNonceWordH;
            aOrbiterA = (aWandererC + RotL64(aCross, 23U)) + 14484814700447992628U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 30U)) + RotL64(aCarry, 35U)) + 17089267243053958210U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 9138746214446211147U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 51U)) + 10181001536979097045U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 19U)) + 6657458969093373191U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 13U)) + 7515983477876590988U) + aNonceWordC;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 60U)) + 3039935555863947600U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16209389224740851136U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 725253312098083182U;
            aOrbiterJ = RotL64((aOrbiterJ * 17535989492095522597U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13307041115748941383U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7159572004825238263U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4855009895002398449U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12027236743251643820U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8717826175991286553U;
            aOrbiterE = RotL64((aOrbiterE * 1175614802543098451U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4769096034227659937U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11201226563992939616U;
            aOrbiterK = RotL64((aOrbiterK * 15595355978388159931U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17295978531215563256U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11850923890626719833U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3854851059897397075U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14139441565288097706U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 988684899382304485U;
            aOrbiterC = RotL64((aOrbiterC * 11929090869999700891U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6159251276942253175U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4849529993914550651U;
            aOrbiterB = RotL64((aOrbiterB * 18240712676783671317U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6679745455842119497U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15838404437552215214U;
            aOrbiterD = RotL64((aOrbiterD * 17357853511591350887U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15853153471104458948U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12542164757451566994U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12163611303899312043U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14304233464055838869U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4037999346933039765U;
            aOrbiterG = RotL64((aOrbiterG * 564236202758328407U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3582312827630995454U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4068921616130916949U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 1527829107415867363U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 36U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterC, 53U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterB, 36U));
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterH) + aNonceWordJ);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterK, 48U)) + aNonceWordL) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22756U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 22243U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24979U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26917U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 60U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 29U)) + 17936518874386450467U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 54U)) + 13722737841589910344U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 13U)) + 11774969167948715796U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 3U)) + 3640101505680493777U) + aNonceWordK;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 1369495382725650822U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 21U)) + 11827310354654653345U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 41U)) + 186037671377175394U) + aNonceWordH;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 11428829344234627340U;
            aOrbiterC = (aWandererB + RotL64(aCross, 39U)) + 2275016369870029068U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 48U)) + RotL64(aCarry, 51U)) + 15471646673734798328U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 19U)) + 12172082573115640145U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6626736341348283154U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12220614992483863623U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8137086205714097487U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13157102324253760215U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4143587482368093601U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5060677690991506895U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11007575246013796426U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11721585930088637162U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15009627907125738519U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5720789204450196217U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3094696226821431648U;
            aOrbiterI = RotL64((aOrbiterI * 4412033981712165541U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14675830108100986773U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9444071495289719645U;
            aOrbiterH = RotL64((aOrbiterH * 10983136361953366557U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5106753847015199956U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7585421898593510010U;
            aOrbiterG = RotL64((aOrbiterG * 140996914192351011U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11746948407655524690U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16336323220286344483U;
            aOrbiterK = RotL64((aOrbiterK * 6590417628835864497U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8030445186765781136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 276034088015165891U;
            aOrbiterC = RotL64((aOrbiterC * 7626025612710225099U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8116955322602209153U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5704503350608834450U;
            aOrbiterB = RotL64((aOrbiterB * 7049558959583832449U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8063875087087055875U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1111816778196345760U;
            aOrbiterA = RotL64((aOrbiterA * 13820440198677609571U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7702895879089714461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17936518874386450467U;
            aOrbiterE = RotL64((aOrbiterE * 12767279443267850009U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH + ((RotL64(aIngress, 54U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 54U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 41U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 37U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterD, 34U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28659U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((aIndex + 30459U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29771U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 28570U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 52U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 6U)) + 13854738573712660276U) + aNonceWordE;
            aOrbiterA = (aWandererI + RotL64(aCross, 39U)) + 16835460633412286294U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 13U)) + 6785859293758091931U) + aNonceWordD;
            aOrbiterB = (aWandererA + RotL64(aIngress, 43U)) + 126317283127992659U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 7568963536291415413U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 12294016745653004819U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 60U)) + 18269588932920281147U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 51U)) + 5872406424994751026U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 21U)) + 7764434758831474129U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 37U)) + 4804168969415573371U) + aNonceWordO;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 959601763507651280U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9257644462479293048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14332699366894494579U;
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10487012596470786004U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 612729229562321440U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11380387280507726003U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7845523921295625315U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12742115479740024747U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15578543510683986421U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10294667720904610944U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14369711143154904567U;
            aOrbiterF = RotL64((aOrbiterF * 13753005602288309379U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10918344717497681894U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18136794828308636957U;
            aOrbiterG = RotL64((aOrbiterG * 17899418637978002409U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14378638206724886404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7077588188450008059U;
            aOrbiterK = RotL64((aOrbiterK * 485375960462924335U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8941870012851971932U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15242087859620352399U;
            aOrbiterE = RotL64((aOrbiterE * 4963002810455992839U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10395280254030875387U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6826595516076975980U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6198886240333178001U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10407910809564430664U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6368255889263255730U;
            aOrbiterD = RotL64((aOrbiterD * 3809496492809859731U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6365669830464231626U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 596785214258266904U;
            aOrbiterA = RotL64((aOrbiterA * 6338109335634389561U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4807438574488830717U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13854738573712660276U;
            aOrbiterB = RotL64((aOrbiterB * 6954368463489446551U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 36U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterB, 56U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterC, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 13U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            aWandererE = aWandererE + (((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 42U));
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 37U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordM);
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

void TwistExpander_Boxing_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF977966BEB2A1671ULL + 0xCE0F4D32F4E488F5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD56D1C003995E835ULL + 0xAF17770F23868FB3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCE9B0046482A3E0FULL + 0xCBF2465A04AD77F2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD278CF9FFD05A8B3ULL + 0xE28E8C02F34F8420ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDB75001353C40AD5ULL + 0xD09196B84044CD37ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8BB0DEC66FB3FED9ULL + 0xF5737FA8C20FDE5CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBB85EF0D7070CA95ULL + 0xDFF86099AFBD0562ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB35650DDAD7CA28BULL + 0xE5000CBCF510AE84ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD4DE994B4182DF41ULL + 0xF1CC5C44453D8524ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE1AB5C91709BB1CBULL + 0xFDCAB8D5E236DF32ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB0C9149D6C79B5C3ULL + 0xB747EBB7D090A94FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCFD23B74BD441E11ULL + 0xEF8EEB54EC4FD122ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA6FE37BBEACAF947ULL + 0xACB0260A6D68BEEEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC31C4504663A1967ULL + 0xE3A2852B72FE0E3FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE736F580CC43998DULL + 0xAA1051EAC8C64359ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCAD4CD9E4AC486DDULL + 0xC1C107940273F428ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1019U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 3071U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 421U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2961U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 10U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 13854738573712660276U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 30U)) + 16835460633412286294U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 13U)) + 6785859293758091931U) + aPhaseFOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 41U)) + 126317283127992659U;
            aOrbiterE = (aWandererC + RotL64(aCross, 47U)) + 7568963536291415413U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 3U)) + 12294016745653004819U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 43U)) + 18269588932920281147U) + aNonceWordM;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 54U)) + RotL64(aCarry, 41U)) + 5872406424994751026U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 7764434758831474129U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 11U)) + 4804168969415573371U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 37U)) + 959601763507651280U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9257644462479293048U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 14332699366894494579U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8829304078930625541U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10487012596470786004U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 612729229562321440U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11380387280507726003U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7845523921295625315U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12742115479740024747U;
            aOrbiterA = RotL64((aOrbiterA * 15578543510683986421U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10294667720904610944U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14369711143154904567U;
            aOrbiterH = RotL64((aOrbiterH * 13753005602288309379U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10918344717497681894U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 18136794828308636957U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17899418637978002409U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14378638206724886404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7077588188450008059U;
            aOrbiterK = RotL64((aOrbiterK * 485375960462924335U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8941870012851971932U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15242087859620352399U;
            aOrbiterB = RotL64((aOrbiterB * 4963002810455992839U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10395280254030875387U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6826595516076975980U;
            aOrbiterF = RotL64((aOrbiterF * 6198886240333178001U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10407910809564430664U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6368255889263255730U;
            aOrbiterE = RotL64((aOrbiterE * 3809496492809859731U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6365669830464231626U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 596785214258266904U;
            aOrbiterI = RotL64((aOrbiterI * 6338109335634389561U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4807438574488830717U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13854738573712660276U;
            aOrbiterJ = RotL64((aOrbiterJ * 6954368463489446551U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 28U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterB, 38U)) + aNonceWordB) + aPhaseFWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 26U) + RotL64(aOrbiterH, 27U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + aPhaseFWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 20U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 20U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7535U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((aIndex + 7247U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7902U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6222U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 16160838483846078448U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 56U)) + 15404960896190227946U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 39U)) + 16904160594024977199U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 17790460246821031802U) + aNonceWordE;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 16395168254086971959U;
            aOrbiterE = (aWandererH + RotL64(aCross, 34U)) + 7484373204039901786U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 37U)) + 18026814691322913510U) + aNonceWordM;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 19U)) + 15244817793136966450U) + aNonceWordJ;
            aOrbiterD = (aWandererI + RotL64(aScatter, 43U)) + 5795491730356335666U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 3U)) + 3163873518027801504U) + aPhaseFOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 29U)) + 2690791759507349172U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17898067251167087906U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8028010015006604239U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5601629670521300241U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7304739457289910555U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6476837815096530043U;
            aOrbiterG = RotL64((aOrbiterG * 16380545138701113267U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14242499233467960602U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17305645693017634630U;
            aOrbiterK = RotL64((aOrbiterK * 14442976693206929569U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9772864059444171908U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7897200728282156408U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 816306719390807411U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4890999319172950996U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8165132649356094963U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17297706071263690189U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9342923520083533265U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7213639583505088067U;
            aOrbiterF = RotL64((aOrbiterF * 1349251979649428909U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4079475132684197272U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3350998022472827283U;
            aOrbiterJ = RotL64((aOrbiterJ * 948841791460066265U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2479140576609216238U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7703147534931674972U;
            aOrbiterE = RotL64((aOrbiterE * 11419116495223970801U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9050277787914448469U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13295888852307317371U;
            aOrbiterI = RotL64((aOrbiterI * 3027097172772140975U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15380254190549884741U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17653690414528791774U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15923958179714368315U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6825072759468337036U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16160838483846078448U;
            aOrbiterB = RotL64((aOrbiterB * 11690325563580492415U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 21U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 14U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aIngress, 38U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + aNonceWordC) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 47U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterE, 50U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14157U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11227U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16012U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((aIndex + 15003U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aScatter, 35U)) + 18191288703716505885U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 9824014524910417136U) + aPhaseFOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 21U)) + 11953012029254917548U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 53U)) + 6297568011027199089U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 26U)) + 2576999400457367975U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 13176139160575558254U;
            aOrbiterD = (aWandererK + RotL64(aCross, 39U)) + 9978408174563621810U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 13U)) + 16765834875061607142U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 16534507305459121344U) + aNonceWordF;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 50U)) + 3114710944346151807U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 23U)) + 10240517868726718592U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10721450637990777883U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16689590768796583952U;
            aOrbiterE = RotL64((aOrbiterE * 3046344179729901637U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2427422768928450209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13495584061816457831U;
            aOrbiterK = RotL64((aOrbiterK * 6670984773768885119U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7058636403765106682U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9897341853944713767U;
            aOrbiterB = RotL64((aOrbiterB * 14286816859999869231U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17749559755733386064U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12515645083926326659U;
            aOrbiterC = RotL64((aOrbiterC * 6582878478865838245U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2625692458813609962U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10596240255026143019U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11605800195771080135U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12374290338067865540U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1507386663796330249U;
            aOrbiterA = RotL64((aOrbiterA * 1210241080424446087U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9288099549484146726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15159312464747000702U;
            aOrbiterG = RotL64((aOrbiterG * 500055502081347757U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14998608679505446229U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17625038109437732009U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 14785862243019841689U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10543192232885637211U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 10330547522729618042U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 7635903835474874057U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5753298214283941201U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15943436872588208065U;
            aOrbiterI = RotL64((aOrbiterI * 17704547766822075741U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5757218926946874970U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 18191288703716505885U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2644970408001409575U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 6U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 27U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 30U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterF, 21U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterH, 46U));
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterB, 41U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21608U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16978U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20685U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19250U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aPrevious, 57U)) + 16651241552253078315U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 35U)) + 4558144676982478003U) + aNonceWordA;
            aOrbiterI = (aWandererC + RotL64(aCross, 14U)) + 8814884320080367550U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 16011579668555672117U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 43U)) + 4738918668759862438U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + 12526083125540985108U) + aNonceWordF;
            aOrbiterH = ((aWandererI + RotL64(aCross, 39U)) + 8048723561746000552U) + aNonceWordE;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 5U)) + 1082218464034639039U) + aPhaseFOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 8432043246965946816U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 37U)) + 9982080524048636852U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 46U)) + RotL64(aCarry, 53U)) + 6720069955755215919U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1019035028070247757U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7360619079463870467U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6623074813047915863U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10893918488381348474U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1390297670907738019U;
            aOrbiterA = RotL64((aOrbiterA * 11909657437658597735U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12512200589031203480U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14741471280748399540U;
            aOrbiterD = RotL64((aOrbiterD * 3012135242889901095U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8543897248359826770U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8545972622733791272U;
            aOrbiterH = RotL64((aOrbiterH * 11793879362775346821U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7049384618581928664U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14730773807906925408U;
            aOrbiterG = RotL64((aOrbiterG * 10711566871536755073U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11480717275652449986U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1135397594974536859U;
            aOrbiterB = RotL64((aOrbiterB * 6347492892938856497U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6897207625849516702U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10920630712550287148U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 4140705091806993359U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1094056478999931332U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6784487144549717207U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6295177724167067891U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2224992798329560875U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11486442570446223696U;
            aOrbiterC = RotL64((aOrbiterC * 5680065455032616591U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14681556190496625711U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1809388635055225841U;
            aOrbiterE = RotL64((aOrbiterE * 3449474313001177557U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4480846057441948619U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16651241552253078315U;
            aOrbiterK = RotL64((aOrbiterK * 10628778876898064085U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 28U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 50U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterC) + aNonceWordB);
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterI, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + aNonceWordG);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterF, 22U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23343U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 21973U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24712U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25229U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 60U)) + (RotL64(aCross, 13U) + RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 4384716820085860551U) + aNonceWordK;
            aOrbiterC = (aWandererI + RotL64(aCross, 37U)) + 9715780315942116888U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 58U)) + 15963520052789178632U) + aNonceWordN;
            aOrbiterA = (aWandererH + RotL64(aIngress, 35U)) + 14346700690686392938U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 47U)) + 6005518012489966643U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 27U)) + 2506732930310252119U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 16782163084851775826U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 13U)) + 823673076571076303U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 54U)) + 1634084509064077736U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 1288134975466877686U;
            aOrbiterB = (aWandererD + RotL64(aCross, 5U)) + 2998220403162908444U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 220430672180734911U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10223923547068528867U;
            aOrbiterJ = RotL64((aOrbiterJ * 12577370238343872139U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11696469696177647608U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6545430420379636963U;
            aOrbiterE = RotL64((aOrbiterE * 8387163146257553773U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 79691451831797107U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8971444023498649419U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5624403902454498793U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9468064161002030997U;
            aOrbiterI = RotL64((aOrbiterI * 8243560528100864595U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4619361544913629805U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12682446273369750704U;
            aOrbiterD = RotL64((aOrbiterD * 10879074713156075641U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8728730962617599223U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9099675924074253030U;
            aOrbiterA = RotL64((aOrbiterA * 5525644236954497523U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3298303921318288541U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5953276499411658358U;
            aOrbiterH = RotL64((aOrbiterH * 10565471305001292693U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6725769507592688539U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 1057277456510215817U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8269412198279297075U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11317925732206917722U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17814749417006079067U;
            aOrbiterB = RotL64((aOrbiterB * 4369209051015735925U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9258362135343403308U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4873837345446960113U;
            aOrbiterC = RotL64((aOrbiterC * 14223381466269503273U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7863380865835889675U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4384716820085860551U;
            aOrbiterF = RotL64((aOrbiterF * 2003891033298374621U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 44U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterB, 41U)) + aNonceWordC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 48U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordB) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterE, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 44U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31577U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31698U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29947U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 30629U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aCross, 5U)) + 15904465836916519864U) + aNonceWordK;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 21U)) + 17725629806317789307U) + aNonceWordF;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 46U)) + RotL64(aCarry, 5U)) + 13794170125914914828U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 2149055907476874332U;
            aOrbiterD = (aWandererE + RotL64(aCross, 57U)) + 5342047776745074649U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 19U)) + 8268148484060546838U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 53U)) + 10821151364028563719U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 23U)) + 4294213820894407378U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 13U)) + 10884726101307943090U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 28U)) + RotL64(aCarry, 57U)) + 16432210042202444824U) + aNonceWordM;
            aOrbiterE = (aWandererH + RotL64(aCross, 43U)) + 15196602644336228055U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14117787670220328165U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 219833877949480215U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10736293047771972173U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3326396981881473962U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14918513066311426279U;
            aOrbiterD = RotL64((aOrbiterD * 14269763278564574663U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11795234681370163206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3068267285352664813U;
            aOrbiterH = RotL64((aOrbiterH * 15746255933920904619U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 245233356957999496U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 709926406353796673U;
            aOrbiterK = RotL64((aOrbiterK * 13627039596842073595U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5378105439430271038U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10114555061122044430U;
            aOrbiterG = RotL64((aOrbiterG * 5351295043424885549U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13233010815716769713U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8231291294833548389U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 10840516135212753869U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7160760224172419829U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14767926435411546785U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1643485739468851073U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4464245330038080103U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15778166658285494712U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13980891936095282989U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2426340576450960905U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6030631392508241438U;
            aOrbiterI = RotL64((aOrbiterI * 13921288910299408423U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15990180955119402476U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8707879851984546959U;
            aOrbiterB = RotL64((aOrbiterB * 13794027045755532979U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11665969506971636052U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15904465836916519864U;
            aOrbiterA = RotL64((aOrbiterA * 17042355185093585101U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 12U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 46U) + aOrbiterG) + RotL64(aOrbiterJ, 28U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 19U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterK, 53U));
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 44U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_Boxing_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4048U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadA[((aIndex + 5179U)) & W_KEY1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5576U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5366U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 37U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 35U)) + 18144572925667544139U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 42U)) + 5659758077574059728U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 51U)) + 6343330616999166392U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 23U)) + 17754639838410839447U) + aPhaseCOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 9451843819849581729U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 7957854457197462212U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 12U)) + 1461994799722205010U;
            aOrbiterH = (aWandererG + RotL64(aCross, 57U)) + 18002214276252170177U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 14689869073147027164U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3978104368003440293U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8512135845221335386U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10506667163729414667U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1477533446382953439U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2166717790929947990U;
            aOrbiterD = RotL64((aOrbiterD * 6538884492418324461U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8082437060686606995U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4363687722464700362U;
            aOrbiterH = RotL64((aOrbiterH * 7199165810993478887U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15782763348014924206U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8572509150015960728U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3340528604891897779U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12248271773316742521U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9602078627638561949U;
            aOrbiterJ = RotL64((aOrbiterJ * 1860631869877427405U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17244849374768558859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1030743048280579012U;
            aOrbiterA = RotL64((aOrbiterA * 10858949914285817051U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17722342363541914280U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15667504059789880034U;
            aOrbiterF = RotL64((aOrbiterF * 15872269872168533709U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12645332941998550794U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9938135244509986497U;
            aOrbiterI = RotL64((aOrbiterI * 16548185968987392957U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4024609904162105979U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6732064218696157303U;
            aOrbiterB = RotL64((aOrbiterB * 3815409766145891393U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 34U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 46U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 37U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 50U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 4U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 54U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13666U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9451U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11435U)) & W_KEY1], 36U) ^ RotL64(aKeyRowReadB[((aIndex + 10874U)) & W_KEY1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 36U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 41U)) + 17225673071833726819U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 47U)) + 10301458382103627331U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 57U)) + 3960233050857362414U) + aPhaseCOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 53U)) + 17768665685046605837U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 14471018461213959767U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 38U)) + 10730597892721340453U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 19U)) + 14863394003122760542U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 43U)) + 9948587274816688296U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 3573569431435100993U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8153670675740450590U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16438856577722561424U;
            aOrbiterK = RotL64((aOrbiterK * 4689247488336908827U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15765587867581925041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1082039522061775213U;
            aOrbiterJ = RotL64((aOrbiterJ * 17023740047246402641U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4202521649260798876U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15877659681260461141U;
            aOrbiterB = RotL64((aOrbiterB * 11369910758551088173U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2551560426129646123U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3005102326163906320U;
            aOrbiterC = RotL64((aOrbiterC * 4241583192662435107U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1675501058857208089U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12774812270956702043U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5488437008504905105U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1044886020922563597U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4857445127457225171U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13223560654459705259U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11548725551787560962U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2434677823189765161U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4283026044563670969U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9606875320524736294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13732615866277657704U;
            aOrbiterA = RotL64((aOrbiterA * 3905528919281629775U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13921743663803299567U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13350829301153929899U;
            aOrbiterF = RotL64((aOrbiterF * 11858642286713079795U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 30U) + aOrbiterI) + RotL64(aOrbiterK, 14U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 39U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 24U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + aPhaseCWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 28U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23104U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18856U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20072U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20023U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 18U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 28U)) + RotL64(aCarry, 53U)) + 15316464782468770057U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 43U)) + 6642872057476351588U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 35U)) + 660732654689529192U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 7235418086884000655U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 14784518476694580493U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 39U)) + 12222433977933449375U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 13U)) + 8573001207708329927U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 24U)) + 16035256260815013172U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 53U)) + 15767726974121910203U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17712217935322939971U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13488963456923357159U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16785285630840310405U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10222949131965611079U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1495561412321657209U;
            aOrbiterH = RotL64((aOrbiterH * 9706305581868526265U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16156530750584361434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7773792489045606309U;
            aOrbiterE = RotL64((aOrbiterE * 10730624207715601393U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11544578291333360613U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3665587867634242865U;
            aOrbiterI = RotL64((aOrbiterI * 4840528190844842595U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15248434984650998090U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15487979645426567581U;
            aOrbiterF = RotL64((aOrbiterF * 10868107809356766183U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6972347795052712690U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16074994810010431338U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1262655238856775853U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16851139687900415292U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14630026837021552812U;
            aOrbiterJ = RotL64((aOrbiterJ * 9577900853521254603U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14236330619137368169U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17778707026111136216U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16239561893843454747U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9390961969105999083U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1174881758316573228U;
            aOrbiterD = RotL64((aOrbiterD * 6602061268277529311U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 14U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterC, 29U));
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterH, 10U)) + aOrbiterD) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 53U));
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29879U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28953U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29740U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26150U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererI + RotL64(aScatter, 53U)) + 4384716820085860551U;
            aOrbiterK = (aWandererC + RotL64(aCross, 30U)) + 9715780315942116888U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 15963520052789178632U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 41U)) + 14346700690686392938U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 19U)) + 6005518012489966643U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 35U)) + 2506732930310252119U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 11U)) + 16782163084851775826U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 823673076571076303U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 23U)) + 1634084509064077736U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1288134975466877686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2998220403162908444U;
            aOrbiterF = RotL64((aOrbiterF * 4321412662318298283U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 220430672180734911U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10223923547068528867U;
            aOrbiterD = RotL64((aOrbiterD * 12577370238343872139U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11696469696177647608U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6545430420379636963U;
            aOrbiterE = RotL64((aOrbiterE * 8387163146257553773U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 79691451831797107U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8971444023498649419U;
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5624403902454498793U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9468064161002030997U;
            aOrbiterI = RotL64((aOrbiterI * 8243560528100864595U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4619361544913629805U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12682446273369750704U;
            aOrbiterH = RotL64((aOrbiterH * 10879074713156075641U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8728730962617599223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9099675924074253030U;
            aOrbiterJ = RotL64((aOrbiterJ * 5525644236954497523U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3298303921318288541U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5953276499411658358U;
            aOrbiterC = RotL64((aOrbiterC * 10565471305001292693U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6725769507592688539U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1057277456510215817U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8269412198279297075U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 28U) + RotL64(aOrbiterK, 4U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 27U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterH, 52U)) + aPhaseCWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Boxing_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6784U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 7821U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4106U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7490U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 8866844335448071821U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 48U)) + RotL64(aCarry, 5U)) + 15159698739856430085U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 9582805772989594633U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 57U)) + 1438538239931588373U) + aPhaseDOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 5U)) + 10862044156620436139U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13682173320058164615U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8351013291045977592U;
            aOrbiterD = RotL64((aOrbiterD * 5722336275651615473U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15777857431516633916U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16178966745333885377U;
            aOrbiterG = RotL64((aOrbiterG * 7545129923202147703U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9031889187993001617U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6308472367425865347U;
            aOrbiterE = RotL64((aOrbiterE * 17118710301967158153U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 642109145903321046U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9186268569255318035U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10714674348507516749U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6091345356803675860U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13218507921880873749U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15415157927185637717U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 36U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterA, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14385U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16267U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12848U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9997U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 42U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aCross, 41U)) + 5697928251815176134U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 337587740689259575U) + aPhaseDOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 4927686903263973950U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 3742409032569801033U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 56U)) + 1608092659172197650U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15848744267145717509U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15300174177963339253U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5771922862677667319U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14162868453323648628U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12020167069983729869U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2071080217680099017U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16259538291658723956U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8516686212464112245U;
            aOrbiterB = RotL64((aOrbiterB * 4731296903548893627U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3722184575520553132U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5663609293306386784U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14364218128780764749U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15265344442454471986U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3050323350098829515U;
            aOrbiterJ = RotL64((aOrbiterJ * 5890624677162388135U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 50U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 21U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 30U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20632U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 20658U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19986U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20001U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 58U)) ^ (RotL64(aPrevious, 29U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 7632760812370906911U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 6007174525479723089U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 3362829642521821048U) + aPhaseDOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 20U)) + 18009548556107978286U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 11U)) + 17880909432272697327U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15961567935420752568U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10136559064656837921U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14473810261421912849U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17622019364405410277U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6927494824421416306U;
            aOrbiterG = RotL64((aOrbiterG * 2686290883767829973U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7125170407794874847U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12342273503071032250U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 867417849555857179U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14997696377476124836U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14874498694181230698U;
            aOrbiterD = RotL64((aOrbiterD * 4026127545746010937U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2549397729130885686U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4217995818662767955U;
            aOrbiterA = RotL64((aOrbiterA * 5525525344485251063U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 48U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + aPhaseDWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 18U) + aOrbiterH) + RotL64(aOrbiterG, 54U)) + aPhaseDWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28540U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29631U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32237U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29837U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 16200278595895089008U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + 1029614154810465897U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 7129562468705441295U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 14388903902433951274U) + aPhaseDOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 10U)) + 1013568949315967455U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3128823373497815651U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14525694606889470589U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12053226114431679195U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14443983602196782887U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12244220415328641190U;
            aOrbiterD = RotL64((aOrbiterD * 15052949098014803181U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10477159225338766614U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2842870123078131566U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11522265477555954071U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8621138818955849917U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5038396344400303181U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14636756322207385447U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2768613802894372496U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2027754864051410015U;
            aOrbiterJ = RotL64((aOrbiterJ * 2461322540050569287U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 39U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterA, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterB, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Boxing_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7126U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7380U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2003U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5812U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 15813325389431304548U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 46U)) + RotL64(aCarry, 57U)) + 2223874171125403602U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 3U)) + 5510483568496824130U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 15474152493495661876U;
            aOrbiterK = (aWandererA + RotL64(aCross, 13U)) + 16846339705130829195U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 27U)) + 1289670576865739669U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 37U)) + 18017354919647006944U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8539685539928984921U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3333721400836704048U;
            aOrbiterH = RotL64((aOrbiterH * 3745286323481400085U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2261560416623815491U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4377786131746816567U;
            aOrbiterK = RotL64((aOrbiterK * 9164777834392621157U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18047393176583722719U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8184724021940434631U;
            aOrbiterG = RotL64((aOrbiterG * 9800116157750921119U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10469895939183324807U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14543391765109879223U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4817987697437667225U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5757225781746158178U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3539000495894022869U;
            aOrbiterA = RotL64((aOrbiterA * 1032298408884695925U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11288971092707065923U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2761384065186568294U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3323838837427471051U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7120580145300417101U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6977246291769372866U;
            aOrbiterE = RotL64((aOrbiterE * 15170353875184253779U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 11U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 48U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 29U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10074U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneD[((aIndex + 14634U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10525U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15485U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 5131645209694953015U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 12070391048835379854U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 12U)) + 2604295836242338724U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 14042039029284001596U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 53U)) + 8914654543854559327U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 27U)) + 2185619407969359869U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 21U)) + 5187406295103352574U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8022832481290871217U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8783061916740573472U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3309891377744201773U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10711028365596196301U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13387065038269133571U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12444578026365205255U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11187001318931801582U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14191473173276034019U;
            aOrbiterB = RotL64((aOrbiterB * 2491253922434756431U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16207761776716426435U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9677408414452078760U;
            aOrbiterG = RotL64((aOrbiterG * 5487303383095129949U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17812460332794370649U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7736423148554132028U;
            aOrbiterK = RotL64((aOrbiterK * 15588733747232852555U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17293203944059014763U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13487243633338010243U;
            aOrbiterC = RotL64((aOrbiterC * 9468688858740539095U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15979293016815060755U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17645215484691359547U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1449450767288733995U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 28U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 4U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 50U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23210U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 24184U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20890U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24034U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 15726877954695761686U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 35U)) + 14187652171881943587U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 50U)) + RotL64(aCarry, 35U)) + 8420423151313882782U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 57U)) + 14942322692433259283U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 7272331475919796255U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 29U)) + 154504365041805840U) + aPhaseEOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 23U)) + 17475491222554948786U) + aPhaseEOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5759181483165339605U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5993060214499322845U;
            aOrbiterH = RotL64((aOrbiterH * 10799489831896153301U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10901786237875941844U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17135786595614068473U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15923538730142047043U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5208202073886811165U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6821452921018900631U;
            aOrbiterC = RotL64((aOrbiterC * 13119330055184115669U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13348064837402206969U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8967943922403445136U;
            aOrbiterK = RotL64((aOrbiterK * 300168481725373093U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8130283784171430891U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6351113882502502876U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15960622823993072903U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6894708729226455769U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12065058511247133944U;
            aOrbiterF = RotL64((aOrbiterF * 5432601727436935831U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17138279326229372741U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12987698199066890628U;
            aOrbiterD = RotL64((aOrbiterD * 12665716655177320977U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 30U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 47U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererK = aWandererK + (((RotL64(aScatter, 12U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterF, 18U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27938U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29703U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28238U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27215U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 10U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aIngress, 18U)) + 12122689833405846292U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 9640400270962766788U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 9141937998266739071U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 11U)) + 12899395770434090537U;
            aOrbiterB = (aWandererB + RotL64(aCross, 5U)) + 13457918115408031842U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 15134784483576000943U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 29U)) + 12540961268790055438U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6306886773092764230U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13573343491337243121U;
            aOrbiterJ = RotL64((aOrbiterJ * 15893457012357368707U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8545588657348974413U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10891410570357275120U;
            aOrbiterD = RotL64((aOrbiterD * 5399310978367842841U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2877137119767060151U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9178097682386595144U;
            aOrbiterH = RotL64((aOrbiterH * 3524486002084427513U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15528007881855616978U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11368419529245281435U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12433207037378339309U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5932738914934356645U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5551842263864055419U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16093776759971522681U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3824433359595690603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17184628855571662441U;
            aOrbiterE = RotL64((aOrbiterE * 691208053136187317U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8724462245014132623U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7481349499528092352U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8212182934509617583U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 51U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterD, 4U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 14U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Boxing_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1646U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 7799U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6472U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 381U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 3105313968748067810U) + aPhaseFOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 9977249451119627064U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 17941392803495349366U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 27U)) + 4279533326705471133U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 46U)) + 13983828966811580039U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3983490984234810378U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 308786542215259956U;
            aOrbiterF = RotL64((aOrbiterF * 4366245356597769425U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8443607695364427037U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14939626441464340668U;
            aOrbiterG = RotL64((aOrbiterG * 16793255020331774983U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9350693577306121110U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1717071159396961752U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11062480662625054525U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15911765265202100610U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14898546272333182767U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2674900543810733067U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3560903518513465868U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5367062725726860234U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8521908836601319553U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterD, 38U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10587U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 14208U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14368U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 10935U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 10U)) + RotL64(aCarry, 29U)) + 12809562813316740345U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 51U)) + 17084212535326321199U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 16074921689983846769U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 14027986153007120145U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 35U)) + 7633455951809250227U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 340989348513370174U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5307820377645020116U;
            aOrbiterK = RotL64((aOrbiterK * 8402492604131262157U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5605285015771527274U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5293500434746182790U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17674669610895537063U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7263156475892261811U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10672879570907433005U;
            aOrbiterH = RotL64((aOrbiterH * 2506338667179450741U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16659226780900986107U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9774892622769850665U;
            aOrbiterE = RotL64((aOrbiterE * 7487477727543183211U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10728057184108279042U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5032485856947407217U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16651577903809154285U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 12U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterH, 10U)) + aPhaseFWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18565U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 23089U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18853U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24255U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 41U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 34U)) + 9630214189402543339U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 4072576573737526819U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 15994787452709618869U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 6403240137132259482U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 5U)) + 10229266900170507720U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5025294577989748989U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16696461238217956883U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15993828976234917577U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9878318855341719119U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16086635438116177346U;
            aOrbiterC = RotL64((aOrbiterC * 5585682357395705671U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12295437783084203730U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7681150419912842402U;
            aOrbiterF = RotL64((aOrbiterF * 7289497379725191451U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2639104034287637448U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12298170009332243573U;
            aOrbiterE = RotL64((aOrbiterE * 9397919591171238575U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3485932317267669626U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16569551670038752475U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8139802826402217631U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterE, 14U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27191U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26268U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25942U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26755U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 2558105147674438050U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 15856662514774702561U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 47U)) + 13346869226246584582U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 38U)) + RotL64(aCarry, 21U)) + 7632111846116243973U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 21U)) + 2102101361626976279U) + aPhaseFOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5605968705067851563U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6842483186584326681U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11344798544990575365U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5559797213819425064U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12422313931331576759U;
            aOrbiterJ = RotL64((aOrbiterJ * 7399849122565913401U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2751024420047872601U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11031320239359798610U;
            aOrbiterD = RotL64((aOrbiterD * 8607639453141148025U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14366375309473793217U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11971479429768505316U;
            aOrbiterH = RotL64((aOrbiterH * 10063001532313098203U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3947595951884469542U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17882767922372770896U;
            aOrbiterE = RotL64((aOrbiterE * 3361906348965810211U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 56U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Boxing_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 2536U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1863U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1496U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneD[((aIndex + 810U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 28U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 13350544654542863236U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 22U)) + 12364346790125404372U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 9738750172849512764U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 3781373837635491421U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 37U)) + 16635020317512702337U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5383653921676231276U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10181959815492056493U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14784636206508715141U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10005510924273927017U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9524687662265740565U;
            aOrbiterD = RotL64((aOrbiterD * 13687380438646756931U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4259138552009771014U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8973051213213726023U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12625091476068190979U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17602611840127337490U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8218984546932905269U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17504305273683304231U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18102186122213487888U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2629927500298092976U;
            aOrbiterF = RotL64((aOrbiterF * 6983280164448292723U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 40U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterA, 54U));
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13298U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((aIndex + 9208U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9166U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 15797U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 18319689184146942855U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 19U)) + 8041304130090501019U) + aPhaseGOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 27U)) + 11347064191990897738U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 15242243470024447468U) + aPhaseGOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 36U)) + RotL64(aCarry, 21U)) + 10619749107163611105U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14795614276221947128U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1578095288886372393U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9953192041564147241U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13593906305770501684U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8919815528334599172U;
            aOrbiterJ = RotL64((aOrbiterJ * 2033810402808238127U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17425548324720065145U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11125018338392347335U;
            aOrbiterB = RotL64((aOrbiterB * 4377887040461528587U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3779189180734244399U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10958224663276134041U;
            aOrbiterD = RotL64((aOrbiterD * 6206963519509783781U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4317305352561612995U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4891139433808505355U;
            aOrbiterA = RotL64((aOrbiterA * 11507024985663120317U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 56U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 16863U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 24061U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18909U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20562U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 1557680213571812384U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 11U)) + 7387349725778021121U;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 37U)) + 15379264067601586976U) + aPhaseGOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 19U)) + 3730195724576043708U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 9637070085323827066U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1170865717363676184U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2750833653175252030U;
            aOrbiterD = RotL64((aOrbiterD * 1937822982381882775U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15118992811225568305U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4974092922102988451U;
            aOrbiterA = RotL64((aOrbiterA * 10575977398702460975U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10625719096296719514U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 855167122475471865U;
            aOrbiterH = RotL64((aOrbiterH * 7441090331293158773U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11322911068958340262U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4334591909425429835U;
            aOrbiterB = RotL64((aOrbiterB * 10059025861172038183U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14263701737208936392U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 678723206735649084U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10823239851733632227U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 38U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 13U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterB) + aPhaseGWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterH, 44U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 32040U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 26644U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29830U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 29451U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 16519040829220310189U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 6U)) + 6888002778416941825U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 1310832187746534025U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 5890888009051281674U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 47U)) + 5143864838362464857U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15591534069452660003U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1466867671765325096U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1277202105237572301U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13931443680107902488U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15400747367673245552U;
            aOrbiterK = RotL64((aOrbiterK * 7011651369456453127U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2836975369734495759U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2370720358274970117U;
            aOrbiterI = RotL64((aOrbiterI * 4615571902817575375U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3470677184188006133U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7175584278499266723U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10067096593682482345U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6095078817776863055U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2176637999243513070U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12215701810843975501U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aPhaseGWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 14U) + RotL64(aOrbiterA, 42U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterI, 27U)) + aPhaseGWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Boxing_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 544U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((aIndex + 7102U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1509U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 654U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 36U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 57U)) + 2101601659597850213U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 13U)) + 2759794072560720121U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 9443562552411269339U) + aPhaseHOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 10801360546699857975U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 37U)) + 8020716394829332019U) + aPhaseHOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1021894212367773801U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13346855534622490176U;
            aOrbiterA = RotL64((aOrbiterA * 12668950387932320985U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16359309548462953836U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12642446944680783519U;
            aOrbiterE = RotL64((aOrbiterE * 12197935153255283321U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8197424982767553380U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14346334610901859094U;
            aOrbiterG = RotL64((aOrbiterG * 16982899923227935679U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14171304260534233539U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 334531601308283605U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5012968232749075075U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10707856298471572695U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 18364775750091914766U;
            aOrbiterH = RotL64((aOrbiterH * 15735143943129143265U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterG, 37U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 26U)) + aOrbiterA) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14576U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 15279U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15462U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 14832U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 7960325128608297381U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 38U)) + 12773836012104052042U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 3173972621347773016U) + aPhaseHOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 3708401356314308171U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 11U)) + 950774285720019449U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4170092315705438265U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17000449130864980747U;
            aOrbiterH = RotL64((aOrbiterH * 7710635557693533263U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8793910540062893860U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 520277969543516469U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4150613128885828229U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12762214857389827271U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2932451184340207695U;
            aOrbiterK = RotL64((aOrbiterK * 7513337346940091655U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11062179998786293839U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7919119215271524178U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9053677007180081359U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1774988449597115155U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3799792889466518953U;
            aOrbiterD = RotL64((aOrbiterD * 17512791286490623455U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 46U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 10U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + aPhaseHWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 60U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 53U)) + aOrbiterD) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 19450U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23220U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17292U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20462U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 38U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 16183871922837164759U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 7002058258090219055U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 48U)) + 5650868611888303705U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 11899839660943876690U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 35U)) + 15349649504488111111U) + aPhaseHOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14060149569086744970U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12920917574225030112U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6552626684290469367U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2831994965175330135U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18312543585028439192U;
            aOrbiterE = RotL64((aOrbiterE * 11618182708195744321U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11657562205118394239U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10850792819281246052U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10663100544207879337U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17810371216216125323U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7963413941144223128U;
            aOrbiterD = RotL64((aOrbiterD * 534217972450595401U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5498715358793875584U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9256727548911651373U;
            aOrbiterC = RotL64((aOrbiterC * 10498848323914000989U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 44U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 58U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 31539U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32424U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26180U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 25302U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 11450949896247900941U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 6U)) + RotL64(aCarry, 29U)) + 3905542253538116335U) + aPhaseHOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 9529740545977785305U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 41U)) + 1856876631533143492U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 57U)) + 84253466320181686U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12577480918745432444U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5625703170397704029U;
            aOrbiterF = RotL64((aOrbiterF * 13583960724598036659U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 694608607323629282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3993981243536262204U;
            aOrbiterH = RotL64((aOrbiterH * 2502835860198146381U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4119215953484892051U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8785040118556157146U;
            aOrbiterC = RotL64((aOrbiterC * 17113521266125471625U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16234403619456882890U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10398727475672860610U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5086871400049644715U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18327987141759096769U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2645964788056875452U;
            aOrbiterK = RotL64((aOrbiterK * 8778681366114628045U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 37U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 12U) + aOrbiterF) + RotL64(aOrbiterI, 20U)) + aPhaseHWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
