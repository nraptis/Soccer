#include "TwistExpander_Lacrosse_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Lacrosse_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEA6F3687373CE643ULL + 0xCB3210795ECD46C9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF41C258A05022A3FULL + 0xCE1E9880D0019498ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x83011927CA08219FULL + 0xC61D5E83BDB06647ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE38B137A3A676BE5ULL + 0x98A46C5A500CEAE6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD1C255B3CB5B5193ULL + 0xFE44FD538D1E595EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA29C9F67CEF08131ULL + 0xA85E221E9A374C55ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBB644E00C169AC1BULL + 0xCCEC6B941607A193ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD7381BD1B5A315EBULL + 0x8E6EA3BE7FFC3C73ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordC, 41U)) ^ RotL64(aNonceWordB, 22U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2306U)) & S_BLOCK1], 3U) ^ RotL64(mSnow[((aIndex + 80U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordF, 23U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2166U)) & S_BLOCK1], 41U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 2523U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 42U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 11U)) + 11410829607777684449U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordG, 9U);
            aOrbiterI = (aWandererD + RotL64(aScatter, 37U)) + 7502698839700975347U;
            aOrbiterJ = ((((aWandererE + RotL64(aIngress, 44U)) + RotL64(aCarry, 21U)) + 13267685058252106173U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordH, 54U);
            aOrbiterB = (aWandererF + RotL64(aCross, 35U)) + 238242706996630625U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 13U)) + 8184695499511454281U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 12767823220461985403U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 18U)) + RotL64(aCarry, 5U)) + 12293198423143850330U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 5U)) + 11149495229952495939U;
            aOrbiterF = (aWandererB + RotL64(aCross, 53U)) + 7556992689338382800U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 57U)) + 3431338808774134649U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 39U)) + 16863099140844995099U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17872458049880677604U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16760153457252546974U;
            aOrbiterJ = RotL64((aOrbiterJ * 11225037229069712805U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3115544493537438408U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4359882942759752958U;
            aOrbiterE = RotL64((aOrbiterE * 561477566995575801U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13387113067202396536U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12955690074544490161U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12449941770827974511U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15614054443728226807U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1939441328066616114U;
            aOrbiterB = RotL64((aOrbiterB * 4484917074808974359U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4599016263007782537U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9962305629016158048U;
            aOrbiterA = RotL64((aOrbiterA * 1496184427500037279U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8428467674122750557U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3938884087806393439U) ^ RotL64(aNonceWordE, 17U);
            aOrbiterF = RotL64((aOrbiterF * 12810531094050481761U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6018636830758044658U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1510372000641305416U;
            aOrbiterK = RotL64((aOrbiterK * 9002834928626918247U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17592782466215337843U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8119921507606870360U;
            aOrbiterI = RotL64((aOrbiterI * 1299795061644535485U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8753237702359236964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12389957327067768090U;
            aOrbiterH = RotL64((aOrbiterH * 4586786761936601607U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17791633199762408683U) + RotL64(aNonceWordB, 35U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11606494383812053915U;
            aOrbiterD = RotL64((aOrbiterD * 13041480602055778521U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4418614662439151979U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11410829607777684449U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3342270212301058781U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 20U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordD, 5U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + RotL64(aNonceWordA, 3U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 5U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterI, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordG, 26U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7555U)) & S_BLOCK1], 47U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 7685U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 50U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8214U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 8788U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 57U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererB + RotL64(aIngress, 6U)) + 10881271196314989997U;
            aOrbiterI = (aWandererG + RotL64(aCross, 29U)) + 6406461249988567558U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 53U)) + 17255067918280095959U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 27U)) + 16690850682497718411U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 23U)) + 5576201059361086866U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 34U)) + RotL64(aCarry, 19U)) + 11991259685693687554U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 14652535244217836909U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 1701789037170782122U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 37U)) + 953429054903473833U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordG, 5U);
            aOrbiterD = ((((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 12064513610469714211U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordA, 47U);
            aOrbiterE = (aWandererA + RotL64(aCross, 39U)) + 7993881398822002424U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14421313768013320050U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11112386845630998889U;
            aOrbiterG = RotL64((aOrbiterG * 11771526352030371669U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17069630896535699015U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3308240081138623373U;
            aOrbiterI = RotL64((aOrbiterI * 10449509484417835159U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17615529807112933619U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11782807146851563541U;
            aOrbiterJ = RotL64((aOrbiterJ * 12992075832343669221U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14401645829607611983U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6736397344219993532U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1667287547938175641U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6446974060524700550U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7840991992443308254U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6891023544882740107U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10362169906019794305U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4503700997923168911U;
            aOrbiterK = RotL64((aOrbiterK * 15066164494038852559U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13492041134973259041U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14337899277551397976U;
            aOrbiterH = RotL64((aOrbiterH * 5966740718899290915U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13693100781608180748U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16177545026405910052U;
            aOrbiterB = RotL64((aOrbiterB * 6019231448444020563U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9641191118119415680U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 735491776764667034U;
            aOrbiterF = RotL64((aOrbiterF * 11305930862759869997U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 2225714710491247284U) + RotL64(aNonceWordD, 21U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16906789796765378455U;
            aOrbiterD = RotL64((aOrbiterD * 4341667316266234469U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9451961177946601088U) + RotL64(aNonceWordH, 51U);
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10881271196314989997U;
            aOrbiterE = RotL64((aOrbiterE * 10929686721061541543U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterH, 39U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 36U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aNonceWordF, 37U));
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 41U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterC) + RotL64(aNonceWordB, 24U));
            aWandererG = aWandererG + ((RotL64(aIngress, 54U) + RotL64(aOrbiterE, 58U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 26U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 15667U)) & S_BLOCK1], 26U) ^ RotL64(mSnow[((aIndex + 11353U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 6U) ^ RotL64(aNonceWordB, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16374U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 14267U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aScatter, 23U)) + 1952750591494698524U) + RotL64(aNonceWordH, 57U);
            aOrbiterE = (((aWandererH + RotL64(aIngress, 48U)) + RotL64(aCarry, 19U)) + 4488270851303332830U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 2738763375328927635U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 6728843649480454340U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 41U)) + 10490717875258865358U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 3U)) + 1429288737812910205U;
            aOrbiterG = (aWandererI + RotL64(aCross, 11U)) + 2761375016998907636U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 28U)) + 1088988605204499835U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 43U)) + 6829840407300289709U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 21U)) + 9267240337867690471U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 57U)) + 8120113021183975703U) + RotL64(aNonceWordC, 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1340980511302566784U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11874452169979878835U;
            aOrbiterJ = RotL64((aOrbiterJ * 8638486178860092537U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1872314794140971426U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6013952618696225751U;
            aOrbiterF = RotL64((aOrbiterF * 7994863587373565715U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3644011378086236002U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8501867691997891731U;
            aOrbiterE = RotL64((aOrbiterE * 7115282675461711509U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2493546555198066143U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5179240189571799179U;
            aOrbiterA = RotL64((aOrbiterA * 1267579130962756135U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11273348247858394197U) + RotL64(aNonceWordA, 3U);
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4577476419423118925U;
            aOrbiterH = RotL64((aOrbiterH * 8427261005061162673U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6201955123046621919U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3930651302557530185U;
            aOrbiterB = RotL64((aOrbiterB * 1563512534463027965U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7571426325227856019U) + RotL64(aNonceWordF, 25U);
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11098508505512361002U;
            aOrbiterK = RotL64((aOrbiterK * 9229352429618815089U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6154830144380484305U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4282054616147137364U;
            aOrbiterI = RotL64((aOrbiterI * 14984813139796280171U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14818120999774989697U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12174471855744785761U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3061488029278974095U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3117297607579915182U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2979217539186455309U;
            aOrbiterC = RotL64((aOrbiterC * 12235308335184626143U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 824986728082249286U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1952750591494698524U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10162288961171400541U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterA, 52U));
            aWandererD = aWandererD + (((((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + RotL64(aCarry, 47U)) + RotL64(aNonceWordG, 52U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + RotL64(aNonceWordE, 45U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 54U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordE, 27U)) ^ RotL64(aNonceWordH, 39U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 18731U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 21338U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordC, 60U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17628U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21452U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 18U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 13U)) + 9751314027302668907U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 27U)) + 12175450995523107056U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 44U)) + 17519694958730119552U;
            aOrbiterG = (aWandererD + RotL64(aCross, 53U)) + 9093525527925682263U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 3713831321786810138U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 10108355209191835040U) + RotL64(aNonceWordH, 41U);
            aOrbiterH = (aWandererF + RotL64(aCross, 24U)) + 12956307447311314768U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 37U)) + 1904298513945877359U) + RotL64(aNonceWordC, 3U);
            aOrbiterK = (aWandererB + RotL64(aPrevious, 11U)) + 4658049993308574460U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 9826333658248851902U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 47U)) + 12058666914724365134U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2516574707110528099U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13335308331049750235U;
            aOrbiterD = RotL64((aOrbiterD * 5880227828760598587U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 8230749255538495304U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordD, 23U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16536559486797811486U;
            aOrbiterA = RotL64((aOrbiterA * 7097036838156464969U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12387639130570188998U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8459259798142872020U;
            aOrbiterC = RotL64((aOrbiterC * 8001346480955847013U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16083784052002800300U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1957284290736468379U;
            aOrbiterH = RotL64((aOrbiterH * 5046501301740813065U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7349538179311335863U) + RotL64(aNonceWordG, 53U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16395170077006105258U;
            aOrbiterB = RotL64((aOrbiterB * 4230485452156662763U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3317652065873784068U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5517155804799120700U;
            aOrbiterK = RotL64((aOrbiterK * 9789270651974719183U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5568525912112200094U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9334250662962319598U;
            aOrbiterF = RotL64((aOrbiterF * 5034887614541768961U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5641394627075994165U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13524971148931512745U;
            aOrbiterI = RotL64((aOrbiterI * 3699457147759854357U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15124425790244392471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7896294947517723306U;
            aOrbiterE = RotL64((aOrbiterE * 7526632360108129915U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15241686066829586263U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12099799118961857495U;
            aOrbiterJ = RotL64((aOrbiterJ * 10456171163074630861U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17529688916595727188U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9751314027302668907U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 521888849578281715U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 23U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterB, 51U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + RotL64(aNonceWordB, 47U));
            aWandererE = aWandererE + (((RotL64(aIngress, 54U) + RotL64(aOrbiterD, 35U)) + aOrbiterA) + RotL64(aNonceWordF, 52U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererH = aWandererH + ((((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterA, 6U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordH, 41U)) ^ RotL64(aNonceWordA, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 25645U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 25828U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordD, 46U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24660U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26027U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 22U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 22U)) + 12131317914288566437U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 5672805657999385496U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 3581710244233124197U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 11U)) + 15251296040538489436U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 41U)) + 11295008604679904153U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 43U)) + 2230897493419504490U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 27U)) + 7109600123297458999U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 35U)) + 13119156643107683803U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 5U)) + 14755160867807355250U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 46U)) + 16829363373287496832U) + RotL64(aNonceWordG, 3U);
            aOrbiterF = ((((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 16981122946707720883U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 49U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8806000776958603317U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16810923047720876014U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17872735050219539145U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8129657889554436328U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8653100378491974463U;
            aOrbiterC = RotL64((aOrbiterC * 11395283153912468661U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17048985838727432415U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10892675550889823573U;
            aOrbiterA = RotL64((aOrbiterA * 976298937314081913U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15960158965421254346U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12290011578634850001U;
            aOrbiterK = RotL64((aOrbiterK * 9280475585104357745U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16265047040311479093U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10312956912303656248U) ^ RotL64(aNonceWordE, 13U);
            aOrbiterE = RotL64((aOrbiterE * 3012584393253845131U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16706890352221352779U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10630955894218491929U;
            aOrbiterH = RotL64((aOrbiterH * 12675937483456206355U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4009352551041162434U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 3043810773683888556U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ RotL64(aNonceWordH, 39U);
            aOrbiterJ = RotL64((aOrbiterJ * 4328135390387997315U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1398071019814944785U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16689766557488135301U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8403881916549404871U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15934647144489136524U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13521276033614992223U;
            aOrbiterF = RotL64((aOrbiterF * 18003640895553609933U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4281211055727414100U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11848150507497406421U;
            aOrbiterD = RotL64((aOrbiterD * 1107789990317433481U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12022829841608199449U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12131317914288566437U;
            aOrbiterB = RotL64((aOrbiterB * 13275753083882829973U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 34U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterG, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 57U));
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 26U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + RotL64(aNonceWordF, 45U));
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 38U)) + RotL64(aNonceWordA, 54U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 20U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordC, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 27405U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27467U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 6U) ^ RotL64(aNonceWordF, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31392U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30598U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 14U)) + 18302975933754610273U) + RotL64(aNonceWordA, 48U);
            aOrbiterC = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 16736972646771456082U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 17389406266488137442U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 11U)) + 5252511566486165539U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 19U)) + 5730715427422747640U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 37U)) + 6412695646456045825U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 39U)) + 9539701605708994494U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 18355107116412945722U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 24U)) + 11735742491750132942U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 27U)) + 12363819388562658842U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 21U)) + 5861430292304371543U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordF, 15U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15027487084595017708U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7012850020745791926U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15952928839355613939U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11904871669287886120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11199760114477343208U;
            aOrbiterJ = RotL64((aOrbiterJ * 7156374911847525867U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3856004502263742700U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3705931243173921893U;
            aOrbiterE = RotL64((aOrbiterE * 10334871178498711485U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12305785390539209389U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 18057980996551978823U;
            aOrbiterD = RotL64((aOrbiterD * 4850564181113470859U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3229431819292153014U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2994716629242460094U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1029427328395257917U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9796307843453735512U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2957260393651252432U;
            aOrbiterI = RotL64((aOrbiterI * 7261055869794739609U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4060469664218866340U) + RotL64(aNonceWordD, 3U);
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17462081697889685330U;
            aOrbiterF = RotL64((aOrbiterF * 7712009170974461225U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13638660073917821172U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15202349592659062565U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4514326257446024301U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12071949111168967041U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11930843273199806728U;
            aOrbiterB = RotL64((aOrbiterB * 16229663295689525137U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11294220104731500296U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 440743185210586759U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14810195235168807229U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8514240764798061804U) + RotL64(aNonceWordG, 27U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 18302975933754610273U;
            aOrbiterK = RotL64((aOrbiterK * 1972439346780950873U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 10U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 26U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 53U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + RotL64(aNonceWordH, 45U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 34U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterI, 19U)) + RotL64(aNonceWordE, 43U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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

void TwistExpander_Lacrosse_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF3369954DF64DB09ULL + 0xF768BA7B7725658FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF86C79ACE8B54B45ULL + 0xD1A1BB1890B80F6FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD4B2B715CC70817FULL + 0xD48D165DA383A77BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBA2B97B6EAC4F395ULL + 0xC5F8E546ABD61A76ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x947B8494F04A168DULL + 0xC4BE290E14D13C36ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8EAC8014159AE3D1ULL + 0x999AB7926E7A245DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD2434E12C73DC243ULL + 0x8814408FFD9D42E0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8243C545240A97DBULL + 0x849DC4A1FF868B16ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 47U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordE, 24U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4238U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4058U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordG, 53U)) ^ RotL64(aNonceWordC, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1874U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1302U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 40U)) + 4476099022490972343U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 16836423700375760429U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 51U)) + 8850577488928703557U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 57U)) + 7091631824560042743U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 12560498899956759494U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 13U)) + 7797973377112012161U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 23U)) + 6173820673874805794U) + RotL64(aNonceWordH, 37U);
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 10805025132310245348U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 36U)) + 7139216143268029968U) + RotL64(aNonceWordG, 16U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8241544862261635722U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4735527016563596150U;
            aOrbiterG = RotL64((aOrbiterG * 6621354217673598381U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5166171126690294033U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11117641762075368393U;
            aOrbiterH = RotL64((aOrbiterH * 4980156869201219393U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6312932356458415421U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1304139291184508668U;
            aOrbiterJ = RotL64((aOrbiterJ * 90744653170922319U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10085025354842771067U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16745854428789531080U;
            aOrbiterC = RotL64((aOrbiterC * 1945983905747274355U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2497187958708890337U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 16069701876646548995U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ RotL64(aNonceWordE, 57U);
            aOrbiterD = RotL64((aOrbiterD * 16606039730973709495U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17242004368025978091U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12334315722243232121U;
            aOrbiterI = RotL64((aOrbiterI * 16528598396696346719U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8007042082518126895U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5665686359038811484U;
            aOrbiterF = RotL64((aOrbiterF * 11289316305875751813U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3913477186958600592U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16918984318564170343U) ^ RotL64(aNonceWordA, 61U);
            aOrbiterK = RotL64((aOrbiterK * 5128293326494417281U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10227611546502931418U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7187623463085447228U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8479839369622163181U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 40U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + RotL64(aNonceWordC, 7U));
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterH, 24U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterG, 43U));
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aNonceWordF, 17U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterH, 6U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordH, 58U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9729U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 11610U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12287U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15630U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 22U)) + (RotL64(aCross, 37U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 16183871922837164759U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 7002058258090219055U) + RotL64(aNonceWordE, 17U);
            aOrbiterG = ((aWandererA + RotL64(aCross, 12U)) + RotL64(aCarry, 47U)) + 5650868611888303705U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 41U)) + 11899839660943876690U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 3U)) + 15349649504488111111U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 47U)) + 14060149569086744970U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 51U)) + 12920917574225030112U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 27U)) + 2831994965175330135U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 60U)) + 18312543585028439192U) + RotL64(aNonceWordD, 31U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11657562205118394239U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10850792819281246052U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10663100544207879337U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 17810371216216125323U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7963413941144223128U;
            aOrbiterB = RotL64((aOrbiterB * 534217972450595401U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5498715358793875584U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9256727548911651373U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10498848323914000989U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17246360111302191699U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 18309978718113983369U) ^ RotL64(aNonceWordG, 48U);
            aOrbiterC = RotL64((aOrbiterC * 18267472694666221077U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3100998994319502921U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8129301860291235970U;
            aOrbiterK = RotL64((aOrbiterK * 17847033539279176187U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1889641029473279114U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16538494307002917945U;
            aOrbiterF = RotL64((aOrbiterF * 8081488217920885783U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5432230549146849322U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2634437941396090817U;
            aOrbiterD = RotL64((aOrbiterD * 7612999214758935211U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16940172599174185058U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13151669140593952203U) ^ RotL64(aNonceWordH, 39U);
            aOrbiterH = RotL64((aOrbiterH * 16225319638131723487U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3995064294869931681U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 913081077665768816U;
            aOrbiterA = RotL64((aOrbiterA * 9299514648768060453U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 42U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 40U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + RotL64(aCarry, 3U)) + RotL64(aNonceWordC, 9U)) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterH, 3U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 52U)) + aOrbiterC) + RotL64(aNonceWordF, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 18U) + aOrbiterK) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 50U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20366U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 17721U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordH, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19145U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17017U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 34U)) + RotL64(aCarry, 11U)) + 6654158889644956636U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 9045779659363991870U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 11U)) + 3888897662136993491U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 57U)) + 6882016842864459345U) + RotL64(aNonceWordH, 15U);
            aOrbiterH = ((aWandererA + RotL64(aScatter, 23U)) + 15601891715956172291U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 3U)) + 5176811598629335350U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 44U)) + RotL64(aCarry, 53U)) + 12519945150889074325U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 19U)) + 4552583214397603278U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 39U)) + 14225482701804864688U) + RotL64(aNonceWordB, 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5485298070606280363U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11237713257388094289U;
            aOrbiterC = RotL64((aOrbiterC * 11032429223099413011U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14340345895626142788U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16275167270553643347U;
            aOrbiterA = RotL64((aOrbiterA * 7308578867128951199U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 14041860597556520250U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordD, 21U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1436068974197066343U;
            aOrbiterJ = RotL64((aOrbiterJ * 3938460345031496843U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11483155566419547004U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4608508534724289325U;
            aOrbiterF = RotL64((aOrbiterF * 13461385011638899485U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2389196334288832895U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4062682330273866602U;
            aOrbiterH = RotL64((aOrbiterH * 8787682133271101901U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5655656046585592034U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7977947821249746880U;
            aOrbiterK = RotL64((aOrbiterK * 10082104644185964787U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11653718118543974168U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 5456429682072377614U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ RotL64(aNonceWordG, 44U);
            aOrbiterB = RotL64((aOrbiterB * 12504180638665296649U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12457179652004203574U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 445821754230182952U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16043092621697786393U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12429505513284703263U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12480745784412363537U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 643617210585287593U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterE, 60U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 50U) + aOrbiterA) + RotL64(aOrbiterE, 51U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterK, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 36U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + RotL64(aNonceWordA, 3U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 56U)) + aOrbiterI) + RotL64(aNonceWordF, 25U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 34U) ^ RotL64(aNonceWordA, 47U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30311U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27756U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordB, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25130U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 31964U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 60U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aScatter, 24U)) + 13714409587461539863U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 14101156723903265839U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 43U)) + 7063754562895369001U) + RotL64(aNonceWordF, 17U);
            aOrbiterK = ((aWandererD + RotL64(aIngress, 47U)) + 12320578575245519386U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 39U)) + 11744826789631008424U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 51U)) + 8744816505096675597U) + RotL64(aNonceWordG, 9U);
            aOrbiterE = (aWandererA + RotL64(aScatter, 29U)) + 10405435520084528645U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 10U)) + RotL64(aCarry, 39U)) + 1463157688070683543U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 12379603577919617703U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1343439118031348146U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16118850268070235540U;
            aOrbiterG = RotL64((aOrbiterG * 11184386483735388257U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14116264435819277136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5251698273012432109U;
            aOrbiterC = RotL64((aOrbiterC * 1495818611622063967U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 14806408656041403829U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordD, 37U);
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11569345414052398227U;
            aOrbiterE = RotL64((aOrbiterE * 9913158908301414861U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17063874769147888574U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9927420478679581917U;
            aOrbiterA = RotL64((aOrbiterA * 9042782809534196563U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2550285599827162167U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17801534123304996448U;
            aOrbiterK = RotL64((aOrbiterK * 2160836889363614721U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6456685241021762041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17064208177372969289U;
            aOrbiterF = RotL64((aOrbiterF * 13726627607233302493U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18279938244131982650U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8211002229712129419U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12931373380977640645U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12795832560781931767U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 286378504074349650U;
            aOrbiterI = RotL64((aOrbiterI * 85453101173293509U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 5835304250436889513U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordA, 28U);
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12704972686724379659U;
            aOrbiterH = RotL64((aOrbiterH * 1198789639656336053U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 18U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 60U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 46U) + aOrbiterI) + RotL64(aOrbiterC, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aNonceWordH, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 39U)) + aOrbiterE) + RotL64(aNonceWordC, 23U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterG, 6U));
            aWandererD = aWandererD + (((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 26U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Lacrosse_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB40B84EDCDDE1EBBULL + 0xFDAD24490971533BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF28AFDE0A8808999ULL + 0xCD9A63CBC1826C98ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC932BB2ED09C5019ULL + 0x87C6B52A46CA53F8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE0E9BC22987B3081ULL + 0xE35A8A94CD8839ABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF21A4EEA8AE4BFCDULL + 0x8DA8B17CBCA79021ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x82B1BDA63988373FULL + 0xB255317866605497ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBC21A0364C5EDB13ULL + 0xC61BA354F5B21B49ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA2DB87C68851203DULL + 0xAC3E115CBBC53A76ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordB, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4080U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 5800U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 23U) ^ RotL64(aNonceWordA, 4U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1381U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 7535U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 4U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 8793908991006073956U) + RotL64(aNonceWordB, 49U);
            aOrbiterD = (((aWandererJ + RotL64(aCross, 34U)) + RotL64(aCarry, 57U)) + 2932916283348441943U) + RotL64(aNonceWordH, 36U);
            aOrbiterC = ((aWandererB + RotL64(aScatter, 21U)) + 11069042087940968262U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 3U)) + 14369628676782894441U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 8602903272780978282U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3827036107178568820U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8905245209036772489U;
            aOrbiterC = RotL64((aOrbiterC * 5744017326197157667U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13331387530760017893U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9880107580289737823U) ^ RotL64(aNonceWordF, 37U);
            aOrbiterI = RotL64((aOrbiterI * 10302652857542703753U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10199619040626900278U) + RotL64(aNonceWordG, 55U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2466307560891374281U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6295342978834217571U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13973403407981259448U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2851460278409385243U;
            aOrbiterD = RotL64((aOrbiterD * 11226902976321781743U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10365453393815690776U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2382382358987358791U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 481563628980705781U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterH, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 34U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordC, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aNonceWordD, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordH, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12571U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9566U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 58U) ^ RotL64(aNonceWordF, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16234U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 12380U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 28U) + RotL64(aCarry, 13U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 13U)) + 9774364261626083532U;
            aOrbiterI = ((((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 18059001521926116420U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordG, 34U);
            aOrbiterB = ((((aWandererA + RotL64(aIngress, 4U)) + RotL64(aCarry, 11U)) + 10615626210406381148U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordC, 43U);
            aOrbiterD = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 10536484278007898620U;
            aOrbiterF = (aWandererB + RotL64(aCross, 51U)) + 13320663045139972700U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17127001787268166583U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16742574590844166551U;
            aOrbiterB = RotL64((aOrbiterB * 17828964140627204983U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8347719720758228053U) + RotL64(aNonceWordD, 13U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13502468705946051986U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13822952083584784695U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3512687886188904904U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 495660316165795934U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6724596801190194913U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5092722552034477356U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15641128019608284015U) ^ RotL64(aNonceWordF, 31U);
            aOrbiterI = RotL64((aOrbiterI * 3621036395703527059U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15421873776811085458U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17978775513204574125U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18359600395119440183U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordB, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 24U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + RotL64(aNonceWordE, 59U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordG, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19684U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 17533U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 51U) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21505U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 18653U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 20U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 38U)) + 77518479758428414U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 4832061802166300011U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 11695291171006574112U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 7467412817843260094U) + RotL64(aNonceWordC, 59U);
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 57U)) + 17801484124471154757U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordF, 30U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5555455638503958639U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5669470540733721606U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17219613748084498879U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3042388456327784163U) + RotL64(aNonceWordB, 29U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2236734925228156691U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10076582424701705531U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14459720401528685450U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4814967631216658856U;
            aOrbiterJ = RotL64((aOrbiterJ * 18288097536171386643U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16950679344449075945U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 6262238639302011050U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ RotL64(aNonceWordH, 17U);
            aOrbiterF = RotL64((aOrbiterF * 9942659897425088183U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3522256359074996724U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12524717897707074242U;
            aOrbiterD = RotL64((aOrbiterD * 6787771338063891989U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 52U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordA, 39U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 56U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 27U)) + aOrbiterF) + RotL64(aNonceWordD, 61U));
            aWandererG = aWandererG + (((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 51U) ^ RotL64(aNonceWordH, 21U)) ^ RotL64(aNonceWordG, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26267U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 28137U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 51U) ^ RotL64(aNonceWordE, 26U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26154U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24963U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 3339283916456813609U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 11339086426180649584U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 16819191669329316585U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordA, 59U);
            aOrbiterI = (aWandererJ + RotL64(aScatter, 57U)) + 8361916937762630725U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 28U)) + 18031328374429899857U) + RotL64(aNonceWordH, 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18261756894092897276U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4250319792907645666U) ^ RotL64(aNonceWordG, 17U);
            aOrbiterD = RotL64((aOrbiterD * 7053489184750217963U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1492411503643460886U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17369549067879344180U) ^ RotL64(aNonceWordB, 12U);
            aOrbiterH = RotL64((aOrbiterH * 2947354306696216579U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7301713524358676722U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2985193736033012535U;
            aOrbiterI = RotL64((aOrbiterI * 7473297294949338265U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14086975808140927408U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10390516547834639800U;
            aOrbiterE = RotL64((aOrbiterE * 11441293212275890819U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18205555540941493267U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16967799565443938873U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3009081009044782443U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 4U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordD, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordC, 31U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 46U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererI, 24U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Lacrosse_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC108BD76F02BE351ULL + 0xF55C426C0435BCC7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x86B8397D05232167ULL + 0xD81446D448E9CAE9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE874A2AD62161B17ULL + 0xD48A0F1323F88368ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xACB95C12037508A1ULL + 0xD096676249B489B2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAA73B5548C3E83BDULL + 0xBD9F6465C2878867ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF6F219B1B0AADF93ULL + 0xA04A20FDF97CD02BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x84E492EB4FEF23A7ULL + 0xFCE202AA7EAC1C16ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA2B383768B924A03ULL + 0xBAFDD2DC36C88E10ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordC, 52U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5482U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 1878U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 6U) ^ RotL64(aNonceWordE, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 520U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6902U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 1042610313571524121U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 57U)) + 3505725321008825582U) + RotL64(aNonceWordE, 37U);
            aOrbiterD = (((aWandererH + RotL64(aIngress, 20U)) + RotL64(aCarry, 37U)) + 12584654563843782991U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 35U)) + 6645399144515770935U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 11U)) + 3608978423753715584U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 5U)) + 8089198857670370983U;
            aOrbiterK = ((((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 15207251813516399879U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordG, 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9579268660105824516U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16055044469473802812U;
            aOrbiterD = RotL64((aOrbiterD * 2269649280637188723U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 583811872609805949U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7027491967970873942U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12686754713465826139U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 18256061823189677508U) + RotL64(aNonceWordD, 35U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12708429127816136937U;
            aOrbiterH = RotL64((aOrbiterH * 12593886633108075321U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12169216645156306078U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12694325407567795065U;
            aOrbiterK = RotL64((aOrbiterK * 3711789483877261899U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16109994660203297503U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4234704064165718913U;
            aOrbiterI = RotL64((aOrbiterI * 730085881474787681U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14119541943554602878U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8777769004811352951U) ^ RotL64(aNonceWordB, 43U);
            aOrbiterE = RotL64((aOrbiterE * 2556957257736134223U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15642663488392549609U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11594468530833278624U;
            aOrbiterA = RotL64((aOrbiterA * 6639306656361601143U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + RotL64(aNonceWordF, 56U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterD, 44U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterD, 27U));
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordH, 17U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordE, 42U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11456U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8938U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 48U) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8944U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 13553U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 4U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 8604208734152026945U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordH, 25U);
            aOrbiterI = (aWandererH + RotL64(aIngress, 21U)) + 1374329953253889829U;
            aOrbiterB = (aWandererF + RotL64(aCross, 35U)) + 5779278910548228339U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 17670451230882805140U;
            aOrbiterH = (aWandererE + RotL64(aCross, 11U)) + 8193848740764866860U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 5U)) + 15801168428145650104U) + RotL64(aNonceWordD, 13U);
            aOrbiterC = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 2584718176087499066U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14950366247822737997U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9779293225265670135U;
            aOrbiterB = RotL64((aOrbiterB * 11625969538497982117U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8688968319288372383U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13665723186950342601U) ^ RotL64(aNonceWordE, 54U);
            aOrbiterD = RotL64((aOrbiterD * 292035540396910837U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9395428688359973510U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2152719218018108418U;
            aOrbiterE = RotL64((aOrbiterE * 15271961483518392671U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1350324137411377992U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8729317951386057921U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6008790836417785083U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6317310451893678411U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10175620379041384281U;
            aOrbiterH = RotL64((aOrbiterH * 14079679617394330781U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 1203082119358827708U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordG, 53U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 523869107818193101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4629501113595689157U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4028324959540432983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15447631947468213912U;
            aOrbiterC = RotL64((aOrbiterC * 6037306615787729185U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + RotL64(aCarry, 51U)) + RotL64(aNonceWordB, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterB, 6U)) + RotL64(aNonceWordA, 9U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 53U));
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordB, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18439U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 17725U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 60U) ^ RotL64(aNonceWordC, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24067U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 18573U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 53U)) + 15188686795415908074U) + RotL64(aNonceWordD, 25U);
            aOrbiterF = (aWandererG + RotL64(aPrevious, 60U)) + 17310049041983079779U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 8246925977992441471U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 8644260919918112781U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 27U)) + 13401663736874819483U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 3U)) + 7940358935238314973U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 13278990328548007839U) + RotL64(aNonceWordB, 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11346868298353840706U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2374077904806833579U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1765686942154321425U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6978903378645019166U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11951633297870965212U;
            aOrbiterF = RotL64((aOrbiterF * 12778236598654492185U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17398460995357409673U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 1215437945597836770U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9322970054123481621U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1878751468043972239U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5343002808239712390U) ^ RotL64(aNonceWordC, 48U);
            aOrbiterB = RotL64((aOrbiterB * 11878640995447558811U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9884918450053276861U) + RotL64(aNonceWordA, 27U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15894599082080422550U;
            aOrbiterD = RotL64((aOrbiterD * 8359936745539546131U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13917339232771145459U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 18101134009493720683U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15835859435306756387U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3830086372356903769U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15894394599564584010U;
            aOrbiterJ = RotL64((aOrbiterJ * 9513921913446609263U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterA, 41U)) + aOrbiterF) + RotL64(aNonceWordH, 17U));
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterF, 53U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterB, 34U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordF, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordE, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28393U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 26878U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordH, 26U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32440U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25589U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 13U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aPrevious, 29U)) + 6916817163240024692U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 14554930751292077817U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 39U)) + 1098305064484336101U;
            aOrbiterB = (aWandererC + RotL64(aCross, 13U)) + 12192821172420471527U;
            aOrbiterH = ((((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 2435134991707318845U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 13U);
            aOrbiterC = (aWandererD + RotL64(aCross, 6U)) + 1896745368738512624U;
            aOrbiterI = ((((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 1114996424222923873U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordD, 49U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9839135798371512656U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8037967239603177043U;
            aOrbiterG = RotL64((aOrbiterG * 7848951103759663025U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15185468738487237432U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4912098316394854543U;
            aOrbiterC = RotL64((aOrbiterC * 3072785550384399929U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13142688607850380888U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 4507379759608945839U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) ^ RotL64(aNonceWordH, 51U);
            aOrbiterJ = RotL64((aOrbiterJ * 2989332387754215967U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7299006009652289342U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5390655277207053627U) ^ RotL64(aNonceWordA, 47U);
            aOrbiterH = RotL64((aOrbiterH * 10973744708856143715U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6744737023577785725U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15539737698867067285U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4686092035261336911U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13329866734681377952U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13284937458969166257U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3965985432462699445U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8695002088915702168U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3858059421620839286U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9559783727301092937U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + RotL64(aNonceWordC, 25U));
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + RotL64(aNonceWordE, 28U)) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterB, 20U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA43D5DC872FEC8B1ULL + 0xF8520D56FC90A929ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9C27CEE548E8274DULL + 0x98AE838E187A8E4BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEF7A5DFB0F3A0B27ULL + 0xC66D090955069F99ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA54CB7DB59784313ULL + 0x983E2D1D7E76B77AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAA7B15DEFE471E1DULL + 0xB4099C47099B2603ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC7057455ED5EC193ULL + 0xFBD6DBA9AD015784ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC2968FA55A3EB827ULL + 0x820D981D32405A64ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC65674A27E86B4C9ULL + 0xB1A92335ACC7F66BULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordB, 37U)) ^ RotL64(aNonceWordC, 60U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 7675U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5329U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 40U) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5043U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 1824U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 40U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aScatter, 57U)) + 8506388683755208267U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 4U)) + RotL64(aCarry, 29U)) + 2179323259055019735U) + RotL64(aNonceWordE, 57U);
            aOrbiterF = (aWandererF + RotL64(aCross, 37U)) + 3345902531140983016U;
            aOrbiterJ = ((((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 17456139311481306584U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordB, 13U);
            aOrbiterG = ((aWandererG + RotL64(aIngress, 11U)) + 14587864088462311164U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 13178947246650647057U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 43U)) + 12866578138946916962U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13098524333655118173U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15451329483787541982U;
            aOrbiterF = RotL64((aOrbiterF * 13580376920467431451U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 9494299579678389385U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordA, 41U);
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15581954810375490643U;
            aOrbiterG = RotL64((aOrbiterG * 13670002280188424825U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4487042505730624892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2774455928791636186U;
            aOrbiterD = RotL64((aOrbiterD * 15847933919136777451U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12435319582397755819U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10077180055177766823U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3924363471701748703U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10391963896910956455U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6149237416725301794U;
            aOrbiterB = RotL64((aOrbiterB * 10115917698918612823U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15673402771629639978U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14729117178956592426U;
            aOrbiterJ = RotL64((aOrbiterJ * 9070464269215820531U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14492001279368870240U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6278248084483259952U) ^ RotL64(aNonceWordD, 23U);
            aOrbiterK = RotL64((aOrbiterK * 16731228350971263873U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererJ = aWandererJ + (((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 12U)) + aOrbiterK) + RotL64(aCarry, 41U)) + RotL64(aNonceWordG, 4U)) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + RotL64(aNonceWordF, 61U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordB, 60U)) ^ RotL64(aNonceWordF, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12638U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15587U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 30U) ^ RotL64(aNonceWordC, 19U)) ^ RotL64(aNonceWordD, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13409U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 13043U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 44U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 24U)) + 10404808878585437255U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 10587858736301591439U) + RotL64(aNonceWordA, 59U);
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 1430530909801644435U;
            aOrbiterF = (aWandererH + RotL64(aCross, 51U)) + 9090938022430118902U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 35U)) + 12936604311751121235U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 1000583006020232032U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 11U)) + 12352532088997042232U) + RotL64(aNonceWordE, 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16723410947058502564U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16614089235313154270U;
            aOrbiterJ = RotL64((aOrbiterJ * 11530998303573027827U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4245553025593349277U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3353146318549477494U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14246377408238318091U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5935727336135635196U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10312187090293319667U;
            aOrbiterF = RotL64((aOrbiterF * 1395964500396711899U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12192843181244744484U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2542570124502586365U;
            aOrbiterD = RotL64((aOrbiterD * 17222847847573534963U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3315472769469002444U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17512858811783071174U;
            aOrbiterE = RotL64((aOrbiterE * 9070400454074283765U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16633218007427888082U) + RotL64(aNonceWordH, 41U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2502077714838858460U;
            aOrbiterK = RotL64((aOrbiterK * 970762420815997725U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 14792910273226469214U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordF, 14U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15739513291150783151U;
            aOrbiterH = RotL64((aOrbiterH * 11896279674116906915U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterG, 21U)) + RotL64(aNonceWordB, 15U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 51U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordG, 7U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 28U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererD, 4U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordA, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22590U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 24261U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordB, 57U)) ^ RotL64(aNonceWordF, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21943U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((aIndex + 18908U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 56U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aScatter, 3U)) + 9107326720193244489U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordD, 13U);
            aOrbiterJ = ((aWandererD + RotL64(aCross, 54U)) + 10868585484401664145U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 27U)) + 13637736741437846622U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 6130725216183918844U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 2063834478521338187U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 8564870627911949158U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 13U)) + 6524015751064086390U) + RotL64(aNonceWordE, 55U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9874937766875388236U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14723718409522680894U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17379140128833323431U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 13767059954741528279U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordA, 18U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6387608251033722169U;
            aOrbiterJ = RotL64((aOrbiterJ * 6601902195707980693U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5391425980008431000U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11524218415655093779U;
            aOrbiterB = RotL64((aOrbiterB * 12508457981779189389U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 155510463350385905U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10554591788433641311U;
            aOrbiterI = RotL64((aOrbiterI * 5412084824127934293U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8662160162966241542U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5092555636369853727U;
            aOrbiterF = RotL64((aOrbiterF * 433807340167635499U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 7163345798448796101U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordC, 9U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 695089002178413267U;
            aOrbiterD = RotL64((aOrbiterD * 17302689458565434475U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5409173939213468972U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15349690077393827541U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10984681254001609841U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 54U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ) + RotL64(aNonceWordB, 51U)) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterH, 34U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + RotL64(aNonceWordG, 23U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 13U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 50U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordG, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30080U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25799U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 47U) ^ RotL64(aNonceWordH, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25418U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 32487U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 22U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 48U)) + 5576732410244514238U) + RotL64(aNonceWordA, 25U);
            aOrbiterH = (aWandererG + RotL64(aPrevious, 29U)) + 2833808925935929629U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 13U)) + 3670188682914544792U) + RotL64(aNonceWordG, 19U);
            aOrbiterC = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 15759072378887814995U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 13934007231137439994U;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 11022225696007690512U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 37U)) + 16989177104453635790U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9256930045263527091U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17788596104417068290U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 675554110563253305U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17044369456673337625U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1310908395523250343U;
            aOrbiterJ = RotL64((aOrbiterJ * 16305084373037705921U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12067065689034065422U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15130844248737512262U;
            aOrbiterH = RotL64((aOrbiterH * 9409499577465934107U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14532689204495587494U) + RotL64(aNonceWordC, 53U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8198147292120244178U) ^ RotL64(aNonceWordB, 21U);
            aOrbiterK = RotL64((aOrbiterK * 1418356389507740991U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5485494458627163347U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10830008207150307611U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6526039534042499457U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17770065502486618029U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6397859353395335459U;
            aOrbiterC = RotL64((aOrbiterC * 14286997752368893825U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5128700697381508319U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7103394110057060499U;
            aOrbiterB = RotL64((aOrbiterB * 5053680689949149633U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + RotL64(aNonceWordD, 12U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + RotL64(aNonceWordE, 43U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 48U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD + (((RotL64(aIngress, 20U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE050B8106145BA57ULL + 0xA52F7AF0838257D7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB3D4D8268C2DE895ULL + 0x899C94C02856E1B4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x965290D08DE91AEDULL + 0xF864552C5D30B620ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x847C8E40835D4323ULL + 0x9AF918173E77F310ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x911985380862E979ULL + 0xCE654724D2F39D3FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA57A1859A2BB6DDDULL + 0xE1219862BFAF66A0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE65566EC3D89D37DULL + 0xB83B91FFF3049CB6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD01E2C2A7DF54B4DULL + 0xB5DE3B69EEE66FF1ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordG, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1382U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1694U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7103U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 1522U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 52U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aPrevious, 58U)) + 5568146815535263910U;
            aOrbiterD = (aWandererD + RotL64(aCross, 23U)) + 7736084960873834666U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 35U)) + 1336413621817562093U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 39U)) + 5218462026934984692U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 27U)) + 7048890985969555935U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 13415955213864702118U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 51U)) + 5657023257021528548U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 14338310943137497116U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 12305161641833950473U) + RotL64(aNonceWordF, 15U);
            aOrbiterI = ((aWandererH + RotL64(aCross, 48U)) + 14514226578370459131U) + RotL64(aNonceWordB, 17U);
            aOrbiterC = ((aWandererE + RotL64(aScatter, 43U)) + 12692904083266024340U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11012959130001327964U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7106471380403489078U;
            aOrbiterA = RotL64((aOrbiterA * 515626559384817223U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3718101961355280891U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13364192077222322664U;
            aOrbiterG = RotL64((aOrbiterG * 1411328915372590283U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6720867800318913440U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14497243926965866546U;
            aOrbiterK = RotL64((aOrbiterK * 13595058589060114653U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5789056168233262435U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14438482587495779937U;
            aOrbiterH = RotL64((aOrbiterH * 10593535547917767263U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 313917798940179945U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15241845511889502917U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16483477103771326107U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3591957424821693032U) + RotL64(aNonceWordC, 38U);
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1559050939014453558U;
            aOrbiterF = RotL64((aOrbiterF * 17933346117866604725U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15340590914441451383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5538037287390050110U;
            aOrbiterC = RotL64((aOrbiterC * 4082576643144951473U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4151270491894969214U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 263593701314144898U) ^ RotL64(aNonceWordD, 29U);
            aOrbiterD = RotL64((aOrbiterD * 10372046955804512457U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9025145270653080646U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6867950904094870056U;
            aOrbiterE = RotL64((aOrbiterE * 9975247022340627751U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3183454301841252109U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3054904157641290615U;
            aOrbiterJ = RotL64((aOrbiterJ * 4092317552439599475U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1768555574434776135U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5568146815535263910U;
            aOrbiterI = RotL64((aOrbiterI * 12466957001078663927U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 24U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 39U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 44U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterB, 53U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterC, 50U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterB) + RotL64(aNonceWordE, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterC) + RotL64(aNonceWordG, 41U));
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12130U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 8906U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordF, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9590U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10788U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 37U)) + 9751314027302668907U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 3U)) + 12175450995523107056U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 18U)) + 17519694958730119552U) + RotL64(aNonceWordC, 25U);
            aOrbiterD = (aWandererF + RotL64(aIngress, 21U)) + 9093525527925682263U;
            aOrbiterC = (aWandererH + RotL64(aCross, 39U)) + 3713831321786810138U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 10108355209191835040U) + RotL64(aNonceWordH, 60U);
            aOrbiterI = (aWandererG + RotL64(aScatter, 41U)) + 12956307447311314768U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 1904298513945877359U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 23U)) + 4658049993308574460U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 47U)) + 9826333658248851902U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 56U)) + RotL64(aCarry, 39U)) + 12058666914724365134U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2516574707110528099U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13335308331049750235U;
            aOrbiterE = RotL64((aOrbiterE * 5880227828760598587U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8230749255538495304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16536559486797811486U;
            aOrbiterA = RotL64((aOrbiterA * 7097036838156464969U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12387639130570188998U) + RotL64(aNonceWordD, 19U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8459259798142872020U;
            aOrbiterC = RotL64((aOrbiterC * 8001346480955847013U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16083784052002800300U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1957284290736468379U;
            aOrbiterI = RotL64((aOrbiterI * 5046501301740813065U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 7349538179311335863U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16395170077006105258U;
            aOrbiterB = RotL64((aOrbiterB * 4230485452156662763U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3317652065873784068U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5517155804799120700U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9789270651974719183U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5568525912112200094U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9334250662962319598U;
            aOrbiterD = RotL64((aOrbiterD * 5034887614541768961U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5641394627075994165U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 13524971148931512745U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3699457147759854357U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15124425790244392471U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7896294947517723306U;
            aOrbiterJ = RotL64((aOrbiterJ * 7526632360108129915U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15241686066829586263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12099799118961857495U;
            aOrbiterH = RotL64((aOrbiterH * 10456171163074630861U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17529688916595727188U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 9751314027302668907U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordA, 57U);
            aOrbiterG = RotL64((aOrbiterG * 521888849578281715U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 39U)) + aOrbiterG) + RotL64(aNonceWordG, 21U));
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterE, 52U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterD, 23U));
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterG, 54U));
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterI, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + RotL64(aNonceWordB, 31U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordA, 10U)) ^ RotL64(aNonceWordD, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23654U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19181U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordC, 41U)) ^ RotL64(aNonceWordH, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22175U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23236U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 12U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 5510690816044082200U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 23U)) + 15967820875033940530U) + RotL64(aNonceWordB, 47U);
            aOrbiterF = (aWandererH + RotL64(aCross, 29U)) + 539348720848176221U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 51U)) + 15779318183635560817U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordE, 9U);
            aOrbiterI = ((aWandererA + RotL64(aCross, 19U)) + 14511058534424187469U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 57U)) + 5811130556873428391U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 53U)) + 1085928476499444025U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 3U)) + 6973335316600768130U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 13U)) + 10747243745475009744U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 38U)) + 1072260008981349754U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 2018772405352495753U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1092091597048996547U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15103140149542167197U;
            aOrbiterF = RotL64((aOrbiterF * 621856991658027989U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13194619321108681542U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16749188603268621850U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9575408950550922039U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7427959503086895166U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9895804051379551393U;
            aOrbiterG = RotL64((aOrbiterG * 2701997336201570715U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4526020800679774259U) + RotL64(aNonceWordG, 55U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4484850928870048176U) ^ RotL64(aNonceWordA, 59U);
            aOrbiterI = RotL64((aOrbiterI * 17556987520625677313U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1837404844299040155U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15213208978489570694U;
            aOrbiterA = RotL64((aOrbiterA * 7062740584650274133U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9615231781751396800U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15872192167825648096U;
            aOrbiterK = RotL64((aOrbiterK * 2900526493682580729U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12530672039655918903U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10617836782870315804U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9716778004909794973U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 550750725406860977U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3498554352021622907U;
            aOrbiterC = RotL64((aOrbiterC * 9846933294851238495U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4059346317776216057U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14161853870874499023U;
            aOrbiterB = RotL64((aOrbiterB * 8601560894939097781U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4088411647683253905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9321241420172776158U;
            aOrbiterJ = RotL64((aOrbiterJ * 4167888281125330225U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8527337525861632945U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5510690816044082200U;
            aOrbiterH = RotL64((aOrbiterH * 12464836001483233379U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 38U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 58U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterE, 54U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD + (((RotL64(aCross, 40U) + RotL64(aOrbiterE, 3U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + RotL64(aNonceWordF, 49U));
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 5U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterI, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 24U)) + aOrbiterB) + RotL64(aNonceWordD, 4U));
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 41U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterK, 39U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererB, 22U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordH, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26946U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 30067U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordG, 44U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31131U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27620U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 52U)) + RotL64(aCarry, 37U)) + 6654158889644956636U;
            aOrbiterB = ((((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 9045779659363991870U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordD, 23U);
            aOrbiterJ = ((aWandererI + RotL64(aCross, 13U)) + 3888897662136993491U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 5U)) + 6882016842864459345U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 24U)) + 15601891715956172291U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 21U)) + 5176811598629335350U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 37U)) + 12519945150889074325U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 4552583214397603278U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 47U)) + 14225482701804864688U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 43U)) + 5485298070606280363U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 39U)) + 11237713257388094289U) + RotL64(aNonceWordG, 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14340345895626142788U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16275167270553643347U;
            aOrbiterJ = RotL64((aOrbiterJ * 7308578867128951199U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14041860597556520250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1436068974197066343U;
            aOrbiterI = RotL64((aOrbiterI * 3938460345031496843U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11483155566419547004U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4608508534724289325U;
            aOrbiterH = RotL64((aOrbiterH * 13461385011638899485U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2389196334288832895U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4062682330273866602U;
            aOrbiterD = RotL64((aOrbiterD * 8787682133271101901U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5655656046585592034U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7977947821249746880U;
            aOrbiterG = RotL64((aOrbiterG * 10082104644185964787U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11653718118543974168U) + RotL64(aNonceWordE, 5U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5456429682072377614U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12504180638665296649U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12457179652004203574U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 445821754230182952U;
            aOrbiterC = RotL64((aOrbiterC * 16043092621697786393U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12429505513284703263U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12480745784412363537U;
            aOrbiterE = RotL64((aOrbiterE * 643617210585287593U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6952219750393303609U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13965647644550998416U;
            aOrbiterF = RotL64((aOrbiterF * 5395755018020115073U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5602193483992512507U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9593414134773695959U;
            aOrbiterB = RotL64((aOrbiterB * 2186313187456153775U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16469843418561148995U) + RotL64(aNonceWordC, 41U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6654158889644956636U;
            aOrbiterA = RotL64((aOrbiterA * 17490973872858383001U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterA, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aNonceWordH, 52U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 6U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterI, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterI, 37U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + RotL64(aOrbiterC, 20U)) + aOrbiterB) + RotL64(aCarry, 37U)) + RotL64(aNonceWordF, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterC, 43U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC50D520AC93317F7ULL + 0x85287330D6E91B42ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBA663D55A5BBACB1ULL + 0xF405DAD4120A683FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFDB504D6AD4B21F3ULL + 0xCC50DACE06AA5892ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAF46C88AF70BC603ULL + 0xFC3272C933241F73ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA8C0F875CFCC6337ULL + 0xDAEC2538AFCEEE8CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9466C060FD9925D7ULL + 0xF125F5903693758CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE76225DFC43E3DF5ULL + 0xC5D19AB6F27D65B6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x881370E703A8FD95ULL + 0xA729E593DEC2A5CEULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordD, 41U)) ^ RotL64(aNonceWordA, 50U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1115U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 628U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordH, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2369U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 4114U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 14U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 39U)) + 7948891781097675369U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 30U)) + RotL64(aCarry, 5U)) + 13928362874228230226U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 51U)) + 10776180542602258926U) + RotL64(aNonceWordE, 16U);
            aOrbiterE = (aWandererI + RotL64(aIngress, 23U)) + 5735115172149470447U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 3U)) + 5353591822981766987U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 57U)) + 562301708107268570U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 12U)) + 10467810247578364868U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 19U)) + 14541630141152308564U;
            aOrbiterF = ((((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 2350076897065139429U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordD, 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17519109078651162228U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6061035173339902910U;
            aOrbiterC = RotL64((aOrbiterC * 10021905773432907835U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15654836633731000065U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 13723521735153718904U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14459516479283070563U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2849680038315532197U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17336102435576647923U;
            aOrbiterK = RotL64((aOrbiterK * 10984689101753586739U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7671010488872356142U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11485114338165600777U;
            aOrbiterF = RotL64((aOrbiterF * 4162584865462407791U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8759060657343458985U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11009137869375286581U;
            aOrbiterG = RotL64((aOrbiterG * 8741417343929809115U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15792999392743144135U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 6180808423175992479U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) ^ RotL64(aNonceWordG, 59U);
            aOrbiterE = RotL64((aOrbiterE * 13681230339693676907U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 361487389591183005U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15292753806514404853U;
            aOrbiterB = RotL64((aOrbiterB * 17478232597253311153U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14929153438443362045U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7904556383593914086U;
            aOrbiterI = RotL64((aOrbiterI * 2484130486635511403U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3793180909904286848U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10391957637467171320U) ^ RotL64(aNonceWordC, 3U);
            aOrbiterJ = RotL64((aOrbiterJ * 505484041943467117U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 36U) + RotL64(aOrbiterJ, 18U)) + aOrbiterI) + RotL64(aNonceWordB, 23U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterI, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 43U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 10U) + aOrbiterE) + RotL64(aOrbiterC, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterK, 60U)) + RotL64(aNonceWordF, 41U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 38U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 22U) ^ RotL64(aNonceWordF, 3U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8607U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6307U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 12U) ^ RotL64(aNonceWordH, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8529U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6092U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 3621877681473089725U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 24U)) + 4451752751536414717U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 29U)) + 11371625415377772117U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 47U)) + 6046792758881150619U) + RotL64(aNonceWordE, 7U);
            aOrbiterE = ((aWandererI + RotL64(aIngress, 37U)) + 8213166120394461682U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 4343156661140422645U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 11105271483234947905U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 19U)) + 348904609985341372U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 53U)) + 12924652822526858767U) + RotL64(aNonceWordA, 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7461211697358520287U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16551553555297890558U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16432952324635746293U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11908056404140782995U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9147367258259948715U;
            aOrbiterE = RotL64((aOrbiterE * 10777628928376261667U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8876461054692728610U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10546855952702525404U;
            aOrbiterC = RotL64((aOrbiterC * 10071104785895309677U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4748636139110443794U) + RotL64(aNonceWordB, 43U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 783046909529525098U) ^ RotL64(aNonceWordC, 19U);
            aOrbiterJ = RotL64((aOrbiterJ * 8969157702460927215U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16683965945838696665U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12385412690177109575U;
            aOrbiterA = RotL64((aOrbiterA * 10795062772707143187U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8210546822184469023U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13146493623236979963U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13199947810161148155U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13857628148804187115U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7241297989337473475U;
            aOrbiterB = RotL64((aOrbiterB * 16223448508809614229U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 773904571213804946U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7660676598236419707U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14467390638468925567U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16822672435156055469U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6514707119190640433U;
            aOrbiterG = RotL64((aOrbiterG * 7097496727567460535U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 44U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + RotL64(aNonceWordD, 44U));
            aWandererG = aWandererG + ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 21U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterC, 26U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + RotL64(aNonceWordF, 41U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordD, 52U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12941U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11359U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15518U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14878U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aIngress, 4U)) + RotL64(aCarry, 47U)) + 5173905450211892891U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 3555542451908039957U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 11559884700283861559U) + RotL64(aNonceWordE, 29U);
            aOrbiterK = (aWandererK + RotL64(aCross, 43U)) + 1352524329968738673U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 23U)) + 8914206450420616349U) + RotL64(aNonceWordG, 9U);
            aOrbiterG = ((aWandererE + RotL64(aScatter, 51U)) + 2251523378498463946U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 30U)) + 9541575923299247038U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 13U)) + 1239854507907214595U;
            aOrbiterC = (aWandererA + RotL64(aCross, 57U)) + 17698101462598498934U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12305566971683256060U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13804545036303215569U;
            aOrbiterJ = RotL64((aOrbiterJ * 10359543704152744971U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10239749097704329264U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4212214906286320308U;
            aOrbiterA = RotL64((aOrbiterA * 3661436621615751071U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 12192418916967430783U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4475514289326450361U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17497164630368757887U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17376102613298827459U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 18129393209955439341U;
            aOrbiterF = RotL64((aOrbiterF * 6404089025014118979U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4014763724300253568U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17325007199676828814U;
            aOrbiterI = RotL64((aOrbiterI * 1420888274815627083U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15480474849292388685U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14357924730184375449U;
            aOrbiterG = RotL64((aOrbiterG * 16723492259068034209U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4335731868597970070U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8296023680394303015U) ^ RotL64(aNonceWordC, 17U);
            aOrbiterD = RotL64((aOrbiterD * 14027415401430120543U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2807312426993262800U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15510369660839648501U) ^ RotL64(aNonceWordA, 37U);
            aOrbiterE = RotL64((aOrbiterE * 18207954408298333959U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12597844696606519907U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7231012798553551535U;
            aOrbiterC = RotL64((aOrbiterC * 2841306785994479299U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 48U)) + aOrbiterD) + RotL64(aNonceWordB, 54U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterJ, 58U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterI, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aNonceWordD, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordG, 23U)) ^ RotL64(aNonceWordD, 36U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18125U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21795U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordA, 20U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16845U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21284U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 36U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 15549114274303128055U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 60U)) + 16466750056388063241U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 41U)) + 12209449840836787142U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aIngress, 53U)) + 14551496099734294336U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 21U)) + 6266576428679808622U) + RotL64(aNonceWordA, 9U);
            aOrbiterC = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 16892841575635668152U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 7375966221423362125U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 34U)) + 11926105302821753530U) + RotL64(aNonceWordB, 24U);
            aOrbiterJ = (aWandererF + RotL64(aScatter, 27U)) + 16219253791550461124U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7299056065319248160U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15234001484933728439U;
            aOrbiterB = RotL64((aOrbiterB * 8182244796017018911U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6615802589932632120U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5481176858895819247U) ^ RotL64(aNonceWordE, 3U);
            aOrbiterK = RotL64((aOrbiterK * 3604590158551984877U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17220507586542139380U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14137921473739415340U;
            aOrbiterA = RotL64((aOrbiterA * 10634645686035907603U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16981960446540932787U) + RotL64(aNonceWordH, 57U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10897565927079518588U;
            aOrbiterF = RotL64((aOrbiterF * 418843936329303571U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2746889569299593263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4894117146736361379U;
            aOrbiterH = RotL64((aOrbiterH * 2656750612042673191U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18294823016957137777U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 86828501068883383U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11432686669235402365U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6322053762209547826U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6754524552483363820U;
            aOrbiterE = RotL64((aOrbiterE * 1746163087826694641U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7306452650619361017U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12717201204443785828U;
            aOrbiterJ = RotL64((aOrbiterJ * 6121251603905574991U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10422327053543898585U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14786413282036348183U;
            aOrbiterD = RotL64((aOrbiterD * 8713024293107068275U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 38U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterC, 12U));
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordC, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 24U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + RotL64(aNonceWordG, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 48U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordA, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24160U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 25493U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordD, 51U)) ^ RotL64(aNonceWordG, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21857U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23343U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 12U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aScatter, 11U)) + 9080426856729228705U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 7851218321653539276U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 4U)) + RotL64(aCarry, 39U)) + 7023344692919298036U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 51U)) + 9772846154227440734U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 57U)) + 12008298632429608431U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 37U)) + 12201090455849562875U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 9498721803411445471U) + RotL64(aNonceWordE, 37U);
            aOrbiterG = (aWandererE + RotL64(aPrevious, 29U)) + 351203764023093632U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 46U)) + 4966360430644539250U) + RotL64(aNonceWordD, 7U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9194167899071345693U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4922477697284269116U;
            aOrbiterK = RotL64((aOrbiterK * 8444814161720407881U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15742625291642356429U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7528703106518431730U;
            aOrbiterF = RotL64((aOrbiterF * 11530049278751507567U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15279053574704935317U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2425839793660355555U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11486964816849830667U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 13209849392400008898U) + RotL64(aNonceWordF, 22U);
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9041500097716231309U;
            aOrbiterB = RotL64((aOrbiterB * 340661035700748739U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7885423750878814599U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1992993999902904603U;
            aOrbiterA = RotL64((aOrbiterA * 1478629826632201617U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6120758615019314102U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 8529621625846992066U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) ^ RotL64(aNonceWordG, 23U);
            aOrbiterC = RotL64((aOrbiterC * 8485991471612862467U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9125182130757385320U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15691232622970220043U;
            aOrbiterI = RotL64((aOrbiterI * 16517916951054758147U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11413090085435424697U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11563151001080914939U;
            aOrbiterJ = RotL64((aOrbiterJ * 16828196274450408201U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1778975369262558069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3232132443557192010U;
            aOrbiterD = RotL64((aOrbiterD * 17132823737792200981U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 14U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 26U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterA, 37U));
            aWandererH = aWandererH + (((RotL64(aIngress, 30U) + RotL64(aOrbiterC, 53U)) + aOrbiterA) + RotL64(aNonceWordC, 21U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 5U)) + RotL64(aNonceWordB, 49U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 58U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 42U) + aOrbiterG) + RotL64(aOrbiterD, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordC, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32381U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32111U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 44U) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29634U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28090U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 57U)) + 9471546960258473684U) + RotL64(aNonceWordC, 23U);
            aOrbiterI = (((aWandererI + RotL64(aIngress, 4U)) + RotL64(aCarry, 3U)) + 18050235435948942244U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 29U)) + 3005107102671544641U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 17898396434573801850U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 35U)) + 15071602525497771648U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 5780119462702672108U) + RotL64(aNonceWordD, 43U);
            aOrbiterE = (aWandererB + RotL64(aPrevious, 10U)) + 13301326224151025687U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 47U)) + 18129323022260575961U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 19U)) + 1199228670638790709U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1839199978088021020U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4999517042246790165U) ^ RotL64(aNonceWordE, 45U);
            aOrbiterK = RotL64((aOrbiterK * 4585813675677234577U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8788607633376516299U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15143903839930468749U;
            aOrbiterC = RotL64((aOrbiterC * 12735914889325422675U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16674732686428431869U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15908873150953195581U;
            aOrbiterE = RotL64((aOrbiterE * 18049755517524334107U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11204775359756474667U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2525984309543939465U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3988529812023791571U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4566345170476825512U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14876612901557406267U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9047956948845135339U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14926290877038883931U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12710203178186614846U) ^ RotL64(aNonceWordA, 10U);
            aOrbiterJ = RotL64((aOrbiterJ * 14841163494801662515U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7315094513967387996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11050116830482816766U;
            aOrbiterB = RotL64((aOrbiterB * 3702999495721152019U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4505368486032503953U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17905748055257551092U;
            aOrbiterF = RotL64((aOrbiterF * 14775870175093453197U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5728886950801376350U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17998141690182325170U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16008599930125391379U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterI, 38U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 6U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aNonceWordG, 55U));
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterE, 18U)) + RotL64(aNonceWordH, 9U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 43U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterC, 13U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 34U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Lacrosse_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD9DC9BD47B171B29ULL + 0xCB10767CB5142439ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA55A04C320E135BFULL + 0xC6B4364101C02FA6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE0743A34752BB73DULL + 0xB2B6FE4ADB5AC1B6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x98EC43ED1221F3ABULL + 0xDEC7067946FFE2C1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDCE3869618908059ULL + 0xE1BC5CA90576C495ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA0CFB8753722977FULL + 0x8421335D23E5F7D9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8C4166BEB7075E5DULL + 0xF6F61DEF68A07FA1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF272DC9D0D9FAC07ULL + 0xA3F78EB15C85069DULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordC, 37U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2431U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4452U)) & W_KEY1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3864U)) & W_KEY1], 29U) ^ RotL64(mSource[((aIndex + 2671U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 24U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 13U)) + 6467297102954816305U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 7921154109831114952U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 43U)) + 5701131763215638919U) + RotL64(aNonceWordB, 51U);
            aOrbiterG = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 10022999076719002684U) + aPhaseAOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 51U)) + 4367135243038982316U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 6U)) + RotL64(aCarry, 23U)) + 14445846824810383592U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 27U)) + 7683697954545773253U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordA, 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17517006750428030899U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2052484792684025476U;
            aOrbiterA = RotL64((aOrbiterA * 12463117571122469643U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6279463052085808926U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 679280153651813684U;
            aOrbiterE = RotL64((aOrbiterE * 3047031560593583881U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2939516520188460569U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1960616434964712325U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15145998415466343039U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12273819390719947361U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5685033154709449397U;
            aOrbiterC = RotL64((aOrbiterC * 9845666295874714959U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9314494172199500653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15757631834636427621U;
            aOrbiterF = RotL64((aOrbiterF * 15483543888965744529U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 10878078046389399574U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordD, 31U);
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 3583495913766365232U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ RotL64(aNonceWordG, 25U);
            aOrbiterG = RotL64((aOrbiterG * 2913540984990155225U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 7385544065754622301U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16839599460207922881U;
            aOrbiterB = RotL64((aOrbiterB * 240651605910592561U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + aPhaseAWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + RotL64(aNonceWordF, 15U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aPhaseAWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterE, 60U)) + RotL64(aNonceWordH, 16U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordC, 20U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8815U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9145U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordE, 19U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6802U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 5853U)) & W_KEY1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 42U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 21U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aIngress, 43U)) + 6342299552323486695U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 35U)) + 12692748514781367538U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 8202639945493229155U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordC, 41U);
            aOrbiterF = (aWandererA + RotL64(aScatter, 51U)) + 4439975701793231639U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 16774235182859553759U) + RotL64(aNonceWordF, 35U);
            aOrbiterD = ((aWandererI + RotL64(aScatter, 14U)) + RotL64(aCarry, 5U)) + 8764155413335405667U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 21U)) + 7167848811974967685U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16768278912125334220U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9090838954826296201U;
            aOrbiterB = RotL64((aOrbiterB * 5459329624017272077U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7644075729758006298U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17326182797908071215U;
            aOrbiterI = RotL64((aOrbiterI * 2408330168749256075U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16158809721888137555U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8029938783858263694U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12628072435324195483U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8716553521415553404U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7012599977009208840U;
            aOrbiterA = RotL64((aOrbiterA * 8775355876188948851U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13250558696578541499U) + RotL64(aNonceWordE, 13U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13705957059101025396U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16889495686487056367U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2796775206291902461U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13741676263512390669U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10455782033465595947U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1691908360612389252U) + RotL64(aNonceWordB, 27U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4114939415206031540U;
            aOrbiterH = RotL64((aOrbiterH * 2797401802892718297U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterI, 53U));
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 28U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterD, 5U)) + RotL64(aNonceWordA, 19U)) + aPhaseAWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordH, 46U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordA, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15743U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12457U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordH, 10U)) ^ RotL64(aNonceWordF, 39U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15946U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14987U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (((aWandererC + RotL64(aScatter, 21U)) + 15045917390223766480U) + aPhaseAOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordE, 17U);
            aOrbiterB = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 10763054007033668758U) + RotL64(aNonceWordC, 51U);
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 13190170142593666607U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 12U)) + RotL64(aCarry, 39U)) + 9657025731441167065U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aIngress, 47U)) + 11433367178975954211U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 27U)) + 17904920143996810366U;
            aOrbiterC = (aWandererH + RotL64(aCross, 5U)) + 3244383020512113283U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6538815775171139091U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7195368312757976343U;
            aOrbiterJ = RotL64((aOrbiterJ * 10515679176134176565U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 18134430713910279374U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordF, 61U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6571776588427107976U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11916502085252589161U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11830778129647517758U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9793702760907767365U;
            aOrbiterF = RotL64((aOrbiterF * 4096246227968677179U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2287235876793192036U) + RotL64(aNonceWordG, 53U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8951959188326141794U;
            aOrbiterE = RotL64((aOrbiterE * 9968356718110753845U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7583061790273240157U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3571364625022806085U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6238360922735480669U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13869345563551689212U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 277480328952975002U;
            aOrbiterI = RotL64((aOrbiterI * 1057564597096163085U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4983735092494677578U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9490022869381030928U;
            aOrbiterC = RotL64((aOrbiterC * 12926352917961703123U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 56U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + RotL64(aNonceWordD, 12U));
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterE, 21U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + RotL64(aNonceWordH, 37U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordG, 56U)) ^ RotL64(aNonceWordF, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21436U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 19249U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordB, 5U)) ^ RotL64(aNonceWordE, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16648U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 17550U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 50U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 35U)) + 3199575576585871314U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 19U)) + 2533378188975571824U;
            aOrbiterC = ((((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 6819782112558312658U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 53U);
            aOrbiterD = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 12690060987724798497U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 35U)) + 7088375139715629606U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 29U)) + 17785618677423695666U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 41U)) + 1714999280296491277U) + aPhaseAOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordE, 24U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17611338506932491624U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6475727359297421201U;
            aOrbiterC = RotL64((aOrbiterC * 15133348244242438069U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2347744591204119530U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2739317903351401068U;
            aOrbiterK = RotL64((aOrbiterK * 15435029315209475631U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 8663535261373274338U) + RotL64(aNonceWordG, 23U);
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8205245127823536479U;
            aOrbiterI = RotL64((aOrbiterI * 13857005110466856439U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8916510616749754516U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3944805940148512932U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18082271583211389701U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14094751253118853302U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14094299829196076311U;
            aOrbiterE = RotL64((aOrbiterE * 6370012560657108493U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3940673811518673802U) + RotL64(aNonceWordF, 37U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3015106523254484839U;
            aOrbiterD = RotL64((aOrbiterD * 9655401190755573379U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15404103131982599922U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1828655763233900875U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13024358077740310049U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 6U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 42U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + RotL64(aNonceWordA, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 23U)) + aOrbiterK) + aPhaseAWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 13U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + RotL64(aNonceWordH, 13U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 41U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordF, 13U)) ^ RotL64(aNonceWordB, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23328U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 23328U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordA, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21858U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25274U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 10U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererI + RotL64(aIngress, 5U)) + 5568146815535263910U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordB, 3U);
            aOrbiterK = ((aWandererG + RotL64(aScatter, 36U)) + 7736084960873834666U) + RotL64(aNonceWordC, 43U);
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 27U)) + 1336413621817562093U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 5218462026934984692U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 7048890985969555935U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 13415955213864702118U) + aPhaseAOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 43U)) + 5657023257021528548U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14338310943137497116U) + RotL64(aNonceWordD, 22U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12305161641833950473U) ^ RotL64(aNonceWordE, 11U);
            aOrbiterJ = RotL64((aOrbiterJ * 11949964304435964395U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14514226578370459131U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12692904083266024340U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14800805065279908839U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11012959130001327964U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7106471380403489078U;
            aOrbiterA = RotL64((aOrbiterA * 515626559384817223U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3718101961355280891U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13364192077222322664U;
            aOrbiterK = RotL64((aOrbiterK * 1411328915372590283U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6720867800318913440U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14497243926965866546U;
            aOrbiterI = RotL64((aOrbiterI * 13595058589060114653U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5789056168233262435U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14438482587495779937U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10593535547917767263U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 313917798940179945U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15241845511889502917U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16483477103771326107U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + aPhaseAWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterG, 60U));
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + RotL64(aNonceWordF, 41U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 23U)) + aOrbiterK) + RotL64(aNonceWordH, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordF, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32254U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31300U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordH, 50U)) ^ RotL64(aNonceWordC, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27458U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 29881U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 21U)) + (RotL64(aCarry, 36U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aCross, 11U)) + 5721224134332887360U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 47U)) + 6892749729775049095U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 4U)) + 3884839462099556836U) + aPhaseAOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 4365431706830216193U) + aPhaseAOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordB, 11U);
            aOrbiterG = (aWandererD + RotL64(aCross, 41U)) + 15501528746571578773U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 4505911326320650606U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 1865129050927879580U) + RotL64(aNonceWordH, 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2011737665969640369U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 611672935827062688U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12873671551304596619U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 663547038310431047U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5468932264754299556U;
            aOrbiterG = RotL64((aOrbiterG * 11968657455484578525U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17920294117231191705U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 486058453837528110U;
            aOrbiterD = RotL64((aOrbiterD * 8851102552244026737U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2789178451938129313U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 420772587981211184U;
            aOrbiterJ = RotL64((aOrbiterJ * 17402987842294006667U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16196774774442181825U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16264169656793713547U;
            aOrbiterE = RotL64((aOrbiterE * 6900221986041638783U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 10207659833859860796U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordC, 61U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8593749091183323678U) ^ RotL64(aNonceWordD, 39U);
            aOrbiterC = RotL64((aOrbiterC * 10696776033512404927U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7224922076047787384U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15366267474865172373U;
            aOrbiterH = RotL64((aOrbiterH * 10134187073321814217U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 20U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 20U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + RotL64(aNonceWordG, 59U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 41U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordE, 40U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Lacrosse_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9627DBE56951C3B7ULL + 0xF13C6CE711B70948ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8C2E83FD58B8A587ULL + 0x9EACDF1630F20B86ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBC8AA0C57D03A301ULL + 0xDCA149D0FBE4811DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBF65989EA7046D89ULL + 0xDB67878AC02C677FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF8BF1E9185528D53ULL + 0xD7BA92B584D3CB70ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF962C4A6C320BEDDULL + 0xCC6880BCF64E66A0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB6209E6A29A0BDB1ULL + 0xA762C0546957C9FDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x90C45313894523E3ULL + 0xF3FA5F2DD3811086ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 36U) ^ RotL64(aNonceWordG, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5066U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2356U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 41U) ^ RotL64(aNonceWordE, 30U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5251U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1557U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 57U)) + 6733949564325516029U;
            aOrbiterA = ((((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 7304098437143918796U) + aPhaseBOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordB, 48U);
            aOrbiterI = (((aWandererB + RotL64(aCross, 42U)) + RotL64(aCarry, 39U)) + 3923949518391777800U) + RotL64(aNonceWordH, 53U);
            aOrbiterE = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 14243591003388927124U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 27U)) + 18329498724605410406U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13118172167747037249U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5272025143849174212U;
            aOrbiterI = RotL64((aOrbiterI * 9935990954321437743U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 16075917179214318424U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordF, 9U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15263590648674658399U;
            aOrbiterD = RotL64((aOrbiterD * 9918239923411740337U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13730046728289525921U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7703141464499623408U;
            aOrbiterE = RotL64((aOrbiterE * 5886009900621521987U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1382279753822135359U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2973369221699098292U;
            aOrbiterA = RotL64((aOrbiterA * 7440242040663550631U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11578274119583013219U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3419411247737896674U) ^ RotL64(aNonceWordG, 13U);
            aOrbiterK = RotL64((aOrbiterK * 17814942652262802991U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 20U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + RotL64(aNonceWordC, 41U));
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + RotL64(aCarry, 13U)) + RotL64(aNonceWordA, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 10U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 58U) ^ RotL64(aNonceWordA, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10088U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10685U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordC, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7619U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9371U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 56U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aScatter, 58U)) + 5041131702736607991U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 3U)) + 9295010428212681446U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 6235875895358766017U;
            aOrbiterD = ((((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 2622227802531866918U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordD, 39U);
            aOrbiterE = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 3888894734834524972U) + RotL64(aNonceWordG, 17U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 241682012014701753U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15758000422451568079U;
            aOrbiterJ = RotL64((aOrbiterJ * 14719166949665416221U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2061944548396976912U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8177144990755754531U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12702392689484397947U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 554978075608818497U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 250408260560714933U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1295379390497107727U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8700027645880997552U) + RotL64(aNonceWordE, 47U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10026130047465480902U;
            aOrbiterF = RotL64((aOrbiterF * 12417270861933696623U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9785843014096326696U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9998582683258411251U) ^ RotL64(aNonceWordF, 21U);
            aOrbiterD = RotL64((aOrbiterD * 7197956237569462269U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 46U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 21U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterI, 44U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + RotL64(aNonceWordB, 10U)) + aPhaseBWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordH, 59U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordE, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13397U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 15187U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11880U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11809U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 60U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 13687218104610230596U) + RotL64(aNonceWordH, 51U);
            aOrbiterH = ((((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 6841550124960692709U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordG, 11U);
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 17418968668458764131U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 54U)) + 8303537912696948204U) + aPhaseBOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 23U)) + 12376614417285936537U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14215749063579232654U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4111736931433665347U;
            aOrbiterI = RotL64((aOrbiterI * 8841288213954433049U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11250375934571631522U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5367367837773331275U) ^ RotL64(aNonceWordA, 25U);
            aOrbiterH = RotL64((aOrbiterH * 7262723007545807179U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15514089192382674434U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1475991716685034960U;
            aOrbiterG = RotL64((aOrbiterG * 17720681295551650891U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5531622777788629748U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8363822215908303335U;
            aOrbiterA = RotL64((aOrbiterA * 17850203366840994883U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3741256932685720414U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 11634667238062155772U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordE, 22U);
            aOrbiterD = RotL64((aOrbiterD * 15925089729784547403U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 10U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + RotL64(aCarry, 11U)) + RotL64(aNonceWordC, 19U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 18U)) + aOrbiterG) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 37U)) + aOrbiterG) + RotL64(aCarry, 39U)) + RotL64(aNonceWordD, 15U)) + aPhaseBWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordA, 35U)) ^ RotL64(aNonceWordG, 12U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21393U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19752U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordE, 60U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19138U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 21142U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 11U) + RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 8975885703279267062U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 56U)) + RotL64(aCarry, 27U)) + 8664844915562660637U) + aPhaseBOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 27U)) + 12281774799736296726U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 19U)) + 15347461352311329726U) + RotL64(aNonceWordB, 55U);
            aOrbiterE = ((((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 12967500561828907834U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5002833859280402726U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11908257536954668983U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4384790916151202785U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17017174811949227162U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16851323125613931180U;
            aOrbiterC = RotL64((aOrbiterC * 12446990992858763577U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13469326957728686706U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5228638551056105241U;
            aOrbiterH = RotL64((aOrbiterH * 13369947664646167255U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11945166198089308564U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 16268645041872996022U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordC, 25U);
            aOrbiterD = RotL64((aOrbiterD * 5391448793718370911U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14781204627695095701U) + RotL64(aNonceWordF, 43U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5365325354838101092U;
            aOrbiterE = RotL64((aOrbiterE * 8017284997946310807U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 12U)) + aOrbiterH) + RotL64(aCarry, 19U)) + RotL64(aNonceWordG, 52U)) + aPhaseBWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + RotL64(aNonceWordD, 39U));
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordD, 53U)) ^ RotL64(aNonceWordG, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25551U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((aIndex + 23463U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordA, 22U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24847U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 22585U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 13296600294247799698U) + aPhaseBOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 27U)) + 5818503518080877515U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 6735784238734173597U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 7368398209488856201U) + RotL64(aNonceWordC, 51U);
            aOrbiterK = ((aWandererF + RotL64(aCross, 4U)) + 961734029066455638U) + RotL64(aNonceWordA, 59U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 797011946660892011U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12841876018396622350U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14056540056414153277U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16213253970483895623U) + RotL64(aNonceWordB, 3U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15186950557113470375U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4647470430467908107U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5117930310827477341U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12265429373166094162U;
            aOrbiterB = RotL64((aOrbiterB * 1522823535151532249U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13920531346698601568U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14695405206998211456U;
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 7851960904825938443U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordH, 15U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 9501511171732550190U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5614164120361489613U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 37U)) + aOrbiterD) + RotL64(aCarry, 13U)) + RotL64(aNonceWordG, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 12U)) + aOrbiterD) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 39U)) + RotL64(aNonceWordE, 60U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28437U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 29423U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28949U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30753U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 4U)) + (RotL64(aPrevious, 51U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 7960325128608297381U) + RotL64(aNonceWordH, 57U);
            aOrbiterE = ((aWandererC + RotL64(aCross, 43U)) + 12773836012104052042U) + RotL64(aNonceWordF, 4U);
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 3173972621347773016U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aIngress, 14U)) + 3708401356314308171U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 950774285720019449U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4170092315705438265U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17000449130864980747U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7710635557693533263U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8793910540062893860U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 520277969543516469U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4150613128885828229U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12762214857389827271U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2932451184340207695U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7513337346940091655U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11062179998786293839U) + RotL64(aNonceWordB, 13U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7919119215271524178U) ^ RotL64(aNonceWordA, 59U);
            aOrbiterC = RotL64((aOrbiterC * 9053677007180081359U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1774988449597115155U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3799792889466518953U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17512791286490623455U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + RotL64(aNonceWordG, 41U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterH, 18U));
            aWandererD = aWandererD + (((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + RotL64(aCarry, 35U)) + RotL64(aNonceWordE, 17U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Lacrosse_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8F5D31066CFE46D5ULL + 0xC2462E38427BEF3DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDA33DBCD4F99F533ULL + 0xE7CF379F8958656DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9BDE5A04CF505A3BULL + 0xE6B2704508C1F4C9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x995EFF1D78ECF143ULL + 0xE919E277E4A3BE11ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xED87796253C68BB9ULL + 0xE8F46A6882850F6FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x882CA7A15878E2FDULL + 0xEB212D21C3FBB5BCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9A91FD97DC1966BFULL + 0xC6A56CF0AE5265A6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF3EF1E8D828A4441ULL + 0xD2C01959A1D71072ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordC, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6904U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 7545U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6156U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5016U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 60U)) ^ (RotL64(aCross, 47U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 24U)) + 12046647397183218524U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 11U)) + 2760779375026461991U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 29U)) + 13735454443176855650U) + aPhaseCOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aIngress, 3U)) + 4370377000586647724U) + aPhaseCOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordH, 17U);
            aOrbiterK = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 14566322384189969094U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 57U)) + 5056565959818422786U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 18U)) + RotL64(aCarry, 29U)) + 8795403810686579209U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 37U)) + 9625947666256011567U) + RotL64(aNonceWordB, 51U);
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 1703669290934254701U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6664070663184147951U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2104148316797553431U;
            aOrbiterD = RotL64((aOrbiterD * 12887842067180975983U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1197910004222596145U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9922977170060903197U) ^ RotL64(aNonceWordD, 21U);
            aOrbiterC = RotL64((aOrbiterC * 13047828062605568603U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2048376210852567829U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 12568990647075931409U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordG, 59U);
            aOrbiterF = RotL64((aOrbiterF * 9860242601194210927U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15026894775772902751U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3439447160137900629U;
            aOrbiterI = RotL64((aOrbiterI * 1813754963043785165U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6532671388552829796U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17261098369835997661U;
            aOrbiterE = RotL64((aOrbiterE * 568292591215203521U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3171300991007459947U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5935563269327662024U;
            aOrbiterH = RotL64((aOrbiterH * 11271790283157765003U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14290941734320455612U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12371794745736518824U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12208762336145168647U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8782840145467637373U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4067525421190366741U;
            aOrbiterG = RotL64((aOrbiterG * 6671002797916227485U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11854812920571789853U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17564890418553131451U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16657184504366731805U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 26U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + RotL64(aNonceWordF, 26U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 24U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + RotL64(aNonceWordE, 11U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 40U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordA, 30U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13426U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 14861U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 54U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordG, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14822U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 10938U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aPrevious, 27U)) + 12632404972795375757U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 5U)) + 5351879979055988456U;
            aOrbiterA = (aWandererB + RotL64(aCross, 43U)) + 3597737727467443413U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 2830846754917852318U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 18U)) + RotL64(aCarry, 3U)) + 17311925960294518018U) + RotL64(aNonceWordA, 11U);
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 2083584640523695383U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 53U)) + 15049343611387010158U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 23U)) + 6443050378205811147U) + aPhaseCOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aScatter, 34U)) + 6021965178697344070U) + aPhaseCOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordH, 54U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5080289878758029976U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 576927745306972983U;
            aOrbiterA = RotL64((aOrbiterA * 16008958833683246115U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4728489691382690859U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6184355840165758855U;
            aOrbiterK = RotL64((aOrbiterK * 1515043910404156423U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11220539885798595450U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11091438724966718214U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8225347114759391961U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17184210490020062419U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2150997767099116408U;
            aOrbiterF = RotL64((aOrbiterF * 8058553821648892499U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7021953562676903717U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17159676348343312834U;
            aOrbiterH = RotL64((aOrbiterH * 13877284519668483549U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10367891770525239784U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11922478487264201233U;
            aOrbiterG = RotL64((aOrbiterG * 9195137452661956029U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17815162358981720634U) + RotL64(aNonceWordC, 35U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9582631251085100284U;
            aOrbiterJ = RotL64((aOrbiterJ * 11838992994130850483U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 872593750259572264U) + RotL64(aNonceWordD, 7U);
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17832330100262167302U;
            aOrbiterE = RotL64((aOrbiterE * 1114416841510028467U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16601139856969287418U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14931287111691324985U;
            aOrbiterD = RotL64((aOrbiterD * 16757174577841001179U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + RotL64(aCarry, 13U)) + RotL64(aNonceWordF, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 22U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterG, 43U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 34U) + RotL64(aOrbiterA, 37U)) + aOrbiterF) + RotL64(aNonceWordE, 21U)) + aPhaseCWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 4U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordF, 6U)) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18098U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21156U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22549U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 16832U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aIngress, 29U)) + 9220392006207660113U) + RotL64(aNonceWordG, 47U);
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 23U)) + 11305018553489132882U) + RotL64(aNonceWordE, 41U);
            aOrbiterB = (aWandererC + RotL64(aScatter, 58U)) + 5860373868073513684U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 12319586170883987589U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 14072333614354649021U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 11U)) + 9332158529453194608U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 39U)) + 3860569321145958686U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 53U)) + 8119005668901240093U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 4U)) + RotL64(aCarry, 57U)) + 13918259792880333239U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6938856216758228704U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3960905839118710604U;
            aOrbiterB = RotL64((aOrbiterB * 16203746868670689793U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6043879193734253929U) + RotL64(aNonceWordA, 53U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15691425268831319195U) ^ RotL64(aNonceWordD, 19U);
            aOrbiterD = RotL64((aOrbiterD * 7189195135654636271U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14912209933584715274U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16180183395910618923U;
            aOrbiterC = RotL64((aOrbiterC * 3942858974766467849U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4966642362507707776U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6962226782462822861U;
            aOrbiterF = RotL64((aOrbiterF * 3647802407741095419U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12409120845092026295U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2302946450253872465U;
            aOrbiterG = RotL64((aOrbiterG * 7099576330777297911U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16118304388937163838U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15968419034359049422U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11736207775827080165U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17098982091525008231U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10298979200690822062U;
            aOrbiterH = RotL64((aOrbiterH * 12620028874653521945U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 552826643694256437U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11786560990790695378U;
            aOrbiterJ = RotL64((aOrbiterJ * 11190309640069208311U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13730399230389329793U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17614226859252305432U;
            aOrbiterE = RotL64((aOrbiterE * 2640019643570222977U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 46U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 41U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 18U));
            aWandererG = aWandererG + ((RotL64(aScatter, 34U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + RotL64(aNonceWordH, 59U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 58U)) + aOrbiterB) + RotL64(aNonceWordF, 40U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29160U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 29799U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordF, 30U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31211U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30399U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 252059974543142812U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 35U)) + 11690823093681457368U;
            aOrbiterB = ((((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 13282189752890971123U) + aPhaseCOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordD, 17U);
            aOrbiterI = (aWandererK + RotL64(aScatter, 6U)) + 9507416294305708435U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 19U)) + 14053038174390776539U) + RotL64(aNonceWordF, 9U);
            aOrbiterE = ((aWandererA + RotL64(aScatter, 51U)) + 14605253312318725009U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 47U)) + 18138286582677863671U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 56U)) + 8530091235978489988U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 14381731677571170073U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13316413456378978456U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3910529530149320706U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16000139333493588429U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6302070286831566901U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12324134652758551396U;
            aOrbiterJ = RotL64((aOrbiterJ * 17136438281540250165U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4773478557638475048U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4031153435446078944U;
            aOrbiterD = RotL64((aOrbiterD * 3876928995240982769U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3114794895962903899U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3552936509969106796U;
            aOrbiterG = RotL64((aOrbiterG * 16823186892738820299U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5828754613946145627U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 17985241114076114558U) ^ RotL64(aNonceWordG, 57U);
            aOrbiterI = RotL64((aOrbiterI * 1986669631395606833U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11319331046368072261U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6104267020171882160U;
            aOrbiterE = RotL64((aOrbiterE * 12525117969211576177U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7662668379725735125U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6583034411403600735U;
            aOrbiterF = RotL64((aOrbiterF * 262095656452193889U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5569865728026310280U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4176065898330374039U) ^ RotL64(aNonceWordE, 50U);
            aOrbiterC = RotL64((aOrbiterC * 11305749530796963967U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13677146592276526676U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2734371113158117596U;
            aOrbiterH = RotL64((aOrbiterH * 13146444882662731975U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 34U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterF, 39U));
            aWandererH = aWandererH + (((RotL64(aScatter, 58U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + RotL64(aNonceWordA, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 54U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aPhaseCWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterI, 48U)) + RotL64(aNonceWordH, 35U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Lacrosse_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA77CBEE479735B93ULL + 0xBB4AF9C41C7C770DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9BA0E6D1EFF62F6FULL + 0x998CBE2BB51B32ADULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD60C8E20786DC711ULL + 0x93ED7A3C1F06DAD7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBC41BE836EFC761FULL + 0xD69ECDF54FC13C83ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDD2D086418A65E41ULL + 0xD178374D7E21FF03ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8A1D72F613970FD3ULL + 0x9848656C307BA488ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x845C4655626A1E79ULL + 0xFC03073A6601B2B1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF28A0B58E6E0D0E5ULL + 0xE2CF7370575CB757ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordF, 54U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2746U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 5028U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordE, 56U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1429U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 3526U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 60U)) + 14249093584376402677U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 11U)) + 8756965951816492264U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 23U)) + 11221139480258176330U) + RotL64(aNonceWordA, 7U);
            aOrbiterG = (aWandererI + RotL64(aIngress, 5U)) + 17218894445564194851U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 27U)) + 8064642692524949490U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 21U)) + 5822093203710704646U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 29U)) + 3217799620158102238U) + aPhaseDOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 2613757677892120843U;
            aOrbiterI = (aWandererK + RotL64(aCross, 43U)) + 13647481499551657237U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 3545714196663685016U) + RotL64(aNonceWordH, 57U);
            aOrbiterB = ((aWandererD + RotL64(aScatter, 48U)) + RotL64(aCarry, 29U)) + 9735422670576621521U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3911046580637583767U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9315984027042049203U;
            aOrbiterH = RotL64((aOrbiterH * 12568550776487242469U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8926367674641729058U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11035347490524961446U;
            aOrbiterA = RotL64((aOrbiterA * 10948288997163592463U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10748158733051120339U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2467801787989056455U) ^ RotL64(aNonceWordD, 50U);
            aOrbiterC = RotL64((aOrbiterC * 12621934274702358977U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9244415080474351390U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8517784887959492079U;
            aOrbiterG = RotL64((aOrbiterG * 17022899813765884147U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8409307332803038455U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11043806021873232950U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8294888329708842989U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 17512395828450251457U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16849067939795823992U;
            aOrbiterI = RotL64((aOrbiterI * 9361991804481514337U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17541946638063238056U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11430501673960586718U;
            aOrbiterB = RotL64((aOrbiterB * 15074409630605450091U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 78307505705383302U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4834528975263832983U;
            aOrbiterE = RotL64((aOrbiterE * 17245673681686752861U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9647985402149698269U) + RotL64(aNonceWordE, 17U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6610247710757518931U;
            aOrbiterJ = RotL64((aOrbiterJ * 8672486173272686859U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2706696306041774372U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9519896513600816252U;
            aOrbiterK = RotL64((aOrbiterK * 7468605169665549731U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14647351223431646222U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14249093584376402677U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8296105266618697281U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterA, 5U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 46U) + RotL64(aOrbiterG, 19U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + RotL64(aNonceWordC, 53U));
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 44U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 13U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 44U) + aOrbiterI) + RotL64(aOrbiterC, 47U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + RotL64(aNonceWordB, 29U));
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 42U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 41U) ^ RotL64(aNonceWordF, 60U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7333U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 8229U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordB, 38U)) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7894U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 7015U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 47U)) + (RotL64(aCross, 19U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aScatter, 19U)) + 12046647397183218524U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 2760779375026461991U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 13735454443176855650U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 34U)) + RotL64(aCarry, 53U)) + 4370377000586647724U) + RotL64(aNonceWordC, 15U);
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 29U)) + 14566322384189969094U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 37U)) + 5056565959818422786U;
            aOrbiterA = (aWandererI + RotL64(aCross, 27U)) + 8795403810686579209U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 6U)) + 9625947666256011567U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 41U)) + 1703669290934254701U) + RotL64(aNonceWordE, 25U);
            aOrbiterK = (aWandererF + RotL64(aPrevious, 3U)) + 6664070663184147951U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 43U)) + 2104148316797553431U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1197910004222596145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9922977170060903197U;
            aOrbiterD = RotL64((aOrbiterD * 13047828062605568603U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2048376210852567829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12568990647075931409U;
            aOrbiterJ = RotL64((aOrbiterJ * 9860242601194210927U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15026894775772902751U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3439447160137900629U;
            aOrbiterC = RotL64((aOrbiterC * 1813754963043785165U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6532671388552829796U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17261098369835997661U) ^ RotL64(aNonceWordD, 51U);
            aOrbiterA = RotL64((aOrbiterA * 568292591215203521U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3171300991007459947U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5935563269327662024U;
            aOrbiterF = RotL64((aOrbiterF * 11271790283157765003U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14290941734320455612U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12371794745736518824U;
            aOrbiterB = RotL64((aOrbiterB * 12208762336145168647U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8782840145467637373U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4067525421190366741U;
            aOrbiterG = RotL64((aOrbiterG * 6671002797916227485U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11854812920571789853U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17564890418553131451U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16657184504366731805U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6250004085193517531U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2362659992682660827U;
            aOrbiterI = RotL64((aOrbiterI * 4365619310373869859U), 21U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 4597159873252831182U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordA, 21U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13197238269207675773U;
            aOrbiterK = RotL64((aOrbiterK * 379653377172816575U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8552479493772820372U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12046647397183218524U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17918033655125400323U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 4U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 28U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 58U)) + aOrbiterC) + RotL64(aNonceWordG, 31U));
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 11U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 28U)) + aPhaseDWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aNonceWordF, 56U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterG, 51U));
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + aPhaseDWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 44U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordB, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11107U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 14853U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordH, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11711U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 13863U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 56U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (((aWandererH + RotL64(aCross, 18U)) + RotL64(aCarry, 37U)) + 8975885703279267062U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aIngress, 39U)) + 8664844915562660637U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 43U)) + 12281774799736296726U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 15347461352311329726U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 11U)) + 12967500561828907834U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 23U)) + 5002833859280402726U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 35U)) + 11908257536954668983U) + RotL64(aNonceWordF, 37U);
            aOrbiterF = (aWandererA + RotL64(aIngress, 3U)) + 17017174811949227162U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 53U)) + 16851323125613931180U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 13469326957728686706U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 14U)) + 5228638551056105241U) + RotL64(aNonceWordH, 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11945166198089308564U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16268645041872996022U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5391448793718370911U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14781204627695095701U) + RotL64(aNonceWordG, 47U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5365325354838101092U;
            aOrbiterK = RotL64((aOrbiterK * 8017284997946310807U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 563147416025715953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14660867395395625851U;
            aOrbiterC = RotL64((aOrbiterC * 4769458126865307103U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3168989056355712105U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16179131669773665579U;
            aOrbiterJ = RotL64((aOrbiterJ * 5641461617066671723U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4160220074225527179U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8597134686962559111U;
            aOrbiterF = RotL64((aOrbiterF * 639572585431474015U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16811551552456811661U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5827323970423386301U) ^ RotL64(aNonceWordE, 11U);
            aOrbiterG = RotL64((aOrbiterG * 9328247349730652021U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15583234353262170227U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2950816254621717748U;
            aOrbiterI = RotL64((aOrbiterI * 1102417597476170143U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4426165025104306337U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11871220132164971152U;
            aOrbiterH = RotL64((aOrbiterH * 2366168050042802207U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3832424136113939717U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17673885217916768611U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10887063696370811871U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3479289844909914390U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9498461576098567546U;
            aOrbiterE = RotL64((aOrbiterE * 8734492074299676555U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10645314291190544864U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8975885703279267062U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16584086014947250551U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 14U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterE, 3U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterI, 18U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterB, 47U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 23U)) + aOrbiterB) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + RotL64(aNonceWordB, 4U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterF, 53U));
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterF, 27U)) + RotL64(aNonceWordC, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 18559U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 20578U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 20U) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19549U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21289U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 47U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aIngress, 11U)) + 6024062041314952357U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 18340757093658015585U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 35U)) + 11911120493880346751U) + RotL64(aNonceWordG, 5U);
            aOrbiterI = ((aWandererC + RotL64(aCross, 47U)) + 17428074353884654439U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((((aWandererK + RotL64(aIngress, 6U)) + RotL64(aCarry, 27U)) + 12790849760814795936U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordB, 7U);
            aOrbiterE = (aWandererD + RotL64(aScatter, 43U)) + 12633397052172117800U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 41U)) + 11946150433665237945U;
            aOrbiterD = (aWandererH + RotL64(aCross, 57U)) + 16842157900909419285U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 27U)) + 14186235783224155962U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 39U)) + 13284904542579767591U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 53U)) + 11609181965078844357U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9628562297095374984U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7850281529011259759U;
            aOrbiterF = RotL64((aOrbiterF * 17611485102925470357U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 257458718073794527U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10693404545773519306U;
            aOrbiterJ = RotL64((aOrbiterJ * 14821443722828498323U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3430519236533871460U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6183054506953198055U;
            aOrbiterE = RotL64((aOrbiterE * 6121082743789970911U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2905610989884221654U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4472163910775333862U) ^ RotL64(aNonceWordD, 42U);
            aOrbiterA = RotL64((aOrbiterA * 7770678426310856745U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16870142883133769663U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1403692060594816451U;
            aOrbiterD = RotL64((aOrbiterD * 9740854430251597879U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16904169913507057108U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4773518591580333357U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5306070307776061267U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6528141733853494275U) + RotL64(aNonceWordH, 49U);
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11254806909313951442U;
            aOrbiterG = RotL64((aOrbiterG * 6316669786405548827U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6857506858448143407U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2855763534355983644U;
            aOrbiterH = RotL64((aOrbiterH * 16881334940165182415U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12328391751024624740U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16475072086109949522U;
            aOrbiterB = RotL64((aOrbiterB * 15218626930666825883U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15505670341076785424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6972128419331939330U;
            aOrbiterK = RotL64((aOrbiterK * 12206069109180246067U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7151546362283646210U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6024062041314952357U;
            aOrbiterI = RotL64((aOrbiterI * 10243806128059850493U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + RotL64(aNonceWordE, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterG, 35U));
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 57U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterC, 48U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 37U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + RotL64(aNonceWordA, 59U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 24U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererH, 42U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 54U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordA, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23453U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22699U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordB, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24527U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 21981U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 16200278595895089008U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 29U)) + 1029614154810465897U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 47U)) + 7129562468705441295U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 21U)) + 14388903902433951274U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 5U)) + 1013568949315967455U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 3128823373497815651U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 3U)) + 14525694606889470589U) + aPhaseDOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 14443983602196782887U) + aPhaseDOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 53U)) + 12244220415328641190U) + RotL64(aNonceWordB, 57U);
            aOrbiterI = (aWandererD + RotL64(aScatter, 36U)) + 10477159225338766614U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 27U)) + 2842870123078131566U) + RotL64(aNonceWordF, 55U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8621138818955849917U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5038396344400303181U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14636756322207385447U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2768613802894372496U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2027754864051410015U;
            aOrbiterD = RotL64((aOrbiterD * 2461322540050569287U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2848088309172056399U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15017458513904884651U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9926904679902843055U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9079797279596336139U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15424866642305110811U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12912331089970158845U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13751764050290602740U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7694557131324740282U;
            aOrbiterF = RotL64((aOrbiterF * 14980807690491467023U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3508673897305667669U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3600868397311393233U;
            aOrbiterH = RotL64((aOrbiterH * 5165032044164139165U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1222655844979128996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2257342337168905875U;
            aOrbiterG = RotL64((aOrbiterG * 6198995971182272119U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6290990717563682725U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 15308494772443447109U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordH, 11U);
            aOrbiterE = RotL64((aOrbiterE * 1925593111157842325U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4065385272074155855U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17216369169581934516U;
            aOrbiterA = RotL64((aOrbiterA * 16172589962950781777U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15683161334290612079U) + RotL64(aNonceWordG, 37U);
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4197626901960576264U;
            aOrbiterK = RotL64((aOrbiterK * 2822547214684481747U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4400047838649306704U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16200278595895089008U;
            aOrbiterJ = RotL64((aOrbiterJ * 6603195071605635697U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterC, 10U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterE, 51U));
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + RotL64(aNonceWordC, 30U));
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA + ((RotL64(aCross, 50U) + RotL64(aOrbiterH, 39U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 54U)) + RotL64(aNonceWordE, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 41U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 48U) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28293U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 27377U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordE, 38U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31777U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31402U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aScatter, 41U)) + 4752759164691497960U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 19U)) + 12088872623537639782U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 48U)) + RotL64(aCarry, 43U)) + 3734943577379734227U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 3U)) + 8854778183012444234U) + RotL64(aNonceWordB, 28U);
            aOrbiterI = (aWandererF + RotL64(aCross, 21U)) + 16948373492893967275U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 7962415690046184385U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 37U)) + 1872682375669714454U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 7776801806943853566U;
            aOrbiterA = (aWandererC + RotL64(aCross, 60U)) + 16665439117257230732U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 35U)) + 11088186766134265676U) + aPhaseDOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 47U);
            aOrbiterF = (aWandererK + RotL64(aScatter, 39U)) + 10850237991780969350U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6464817712131305812U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 244557182884209844U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2394270354887582889U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13261563971157415841U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2323811103717827362U;
            aOrbiterI = RotL64((aOrbiterI * 11483723582415081925U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12338803568475493422U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2811342930111104982U;
            aOrbiterG = RotL64((aOrbiterG * 5020981755203607757U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5554497011738996057U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12712169745460598698U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1985586486150377769U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17415058661427002973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9430421222715343818U;
            aOrbiterC = RotL64((aOrbiterC * 10321140659099470811U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3926618548181233180U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6172453297026957838U;
            aOrbiterA = RotL64((aOrbiterA * 1161551082037835233U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8633288765997226004U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17270881130844274342U;
            aOrbiterE = RotL64((aOrbiterE * 8888559940161770791U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12232950994807835262U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15352600312956742750U;
            aOrbiterF = RotL64((aOrbiterF * 6140396356904933003U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5614120002595447983U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1920822446545182835U;
            aOrbiterB = RotL64((aOrbiterB * 17049182594382482085U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 625576652179261739U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2362773059031414585U) ^ RotL64(aNonceWordH, 43U);
            aOrbiterJ = RotL64((aOrbiterJ * 17049048587829564949U), 37U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 16749690978107177915U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordF, 41U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4752759164691497960U;
            aOrbiterD = RotL64((aOrbiterD * 8442185754037031199U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aScatter, 40U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordG, 5U)) + aPhaseDWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 47U)) + aOrbiterG) + RotL64(aNonceWordE, 9U));
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 60U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterH, 39U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterB, 37U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 27U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 52U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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

void TwistExpander_Lacrosse_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB318A1CC8B71CC43ULL + 0x8D8A3338ADD527F3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8C5180A6F1A8E07DULL + 0xB123BD29527843E0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD68E2BDC81D2E4D1ULL + 0x85B7AA06EA26E071ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE3D1736B5C90C97BULL + 0xFDA9E47831DDC587ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBDE80CEBB1C40FAFULL + 0xC1B36CD2CA63BE88ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC726563C3AA1F0A7ULL + 0xD99DFA697C410BB9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFC6CF25EC707FBA1ULL + 0xB2DEDE431CD565E5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCAAE1033813CB28DULL + 0x95BD8E126C2EB0E0ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordG, 44U)) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5271U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 4156U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 634U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3545U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 51U)) + 12311607308490066301U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 29U)) + 13100864684740679846U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 13U)) + 13697304189274329704U) + RotL64(aNonceWordE, 10U);
            aOrbiterB = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 9047976902871216732U) + RotL64(aNonceWordG, 15U);
            aOrbiterD = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 2147897579538537888U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 2072444829390996142U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 57U)) + 2129307836981020908U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 39U)) + 10663145333751112064U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 19U)) + 15019844390503785459U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 10U)) + 5460865577557928142U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 47U)) + 15806522559993224197U) + aPhaseEOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6361113778657833389U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8306013884615042570U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8234258702656728667U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4038420580499706912U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11908091484457158973U;
            aOrbiterE = RotL64((aOrbiterE * 3964111175645156719U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11133912466611921250U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2469227904206936928U;
            aOrbiterC = RotL64((aOrbiterC * 2704438771198001599U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13234017916788297295U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9061117693840451988U;
            aOrbiterB = RotL64((aOrbiterB * 3637440416741459419U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12013423690843812324U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14371779015144617412U;
            aOrbiterK = RotL64((aOrbiterK * 3359568073302062667U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10044883414565441442U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14334898081890462218U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4878939077928220019U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13788962593988366125U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8377887372059713516U) ^ RotL64(aNonceWordF, 51U);
            aOrbiterJ = RotL64((aOrbiterJ * 1925913354197206851U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4584439257847749371U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13335592911357756498U;
            aOrbiterG = RotL64((aOrbiterG * 6515028218115896375U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11166747459333977215U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2368465601636093120U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1929974840976648333U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4538402006569031063U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3397601475441212067U) ^ RotL64(aNonceWordD, 59U);
            aOrbiterH = RotL64((aOrbiterH * 12043369327112500565U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4804403185062062524U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12311607308490066301U;
            aOrbiterI = RotL64((aOrbiterI * 10281231071618984185U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 54U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 14U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + RotL64(aNonceWordH, 55U));
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererE = aWandererE + ((RotL64(aScatter, 56U) + aOrbiterF) + RotL64(aOrbiterB, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterH) + RotL64(aCarry, 27U)) + RotL64(aNonceWordA, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 44U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterD, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordA, 52U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9911U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8273U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordF, 30U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8087U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 8144U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 4U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aScatter, 29U)) + 16451272412693907816U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 41U)) + 10099485419723255462U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 17668900099534923192U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 18U)) + 5497093724143181753U;
            aOrbiterK = (aWandererD + RotL64(aCross, 53U)) + 10354044773550071706U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 47U)) + 12728258851198019099U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 4144050505314242618U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 35U)) + 14133805325480076530U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 308863673210602899U) + RotL64(aNonceWordD, 43U);
            aOrbiterI = (aWandererK + RotL64(aPrevious, 37U)) + 11741180130160569753U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 6U)) + 12926863156769180448U) + RotL64(aNonceWordF, 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 211920854786494259U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13234608842479411078U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2556747209733759467U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9164711974854618892U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6667377062281954219U) ^ RotL64(aNonceWordH, 61U);
            aOrbiterA = RotL64((aOrbiterA * 2603737166987437649U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4559040002406721850U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1749875480850675109U;
            aOrbiterK = RotL64((aOrbiterK * 15822640067349481089U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9555365165561936366U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18289733999504213574U;
            aOrbiterD = RotL64((aOrbiterD * 14156217554673229429U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8727162691639622461U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 291406782452963706U) ^ RotL64(aNonceWordB, 40U);
            aOrbiterF = RotL64((aOrbiterF * 8413500075082350243U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8294911802626492257U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15853578397277298548U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13256191781365357747U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11535146194939658681U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2177540476748375661U;
            aOrbiterJ = RotL64((aOrbiterJ * 15791341922007841029U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2705306323728084136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17617871830709148043U;
            aOrbiterB = RotL64((aOrbiterB * 3449981219502809255U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3699834746313613206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17952609181629473245U;
            aOrbiterC = RotL64((aOrbiterC * 6103160209028988839U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8016694658897707674U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6971251395823324489U;
            aOrbiterI = RotL64((aOrbiterI * 13483776115929040277U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17467528888050817915U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16451272412693907816U;
            aOrbiterE = RotL64((aOrbiterE * 13689734638238895071U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            aWandererD = aWandererD + ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 24U)) + aOrbiterA);
            aWandererE = aWandererE + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 21U)) + aOrbiterI) + RotL64(aCarry, 5U)) + RotL64(aNonceWordE, 41U)) + aPhaseEWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 34U)) + aOrbiterF) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 39U)) + RotL64(aNonceWordG, 55U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordE, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11427U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15664U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordG, 12U)) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15591U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15589U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 6U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 39U)) + 12222235191147985484U) + RotL64(aNonceWordA, 27U);
            aOrbiterK = (aWandererB + RotL64(aCross, 57U)) + 16367317014523328414U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 12U)) + 3511378091284703789U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 15247492830966725949U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 35U)) + 7745995913390407897U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 41U)) + 6463593307540108810U) + RotL64(aNonceWordB, 9U);
            aOrbiterJ = (aWandererE + RotL64(aCross, 43U)) + 1101669311005268630U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 48U)) + RotL64(aCarry, 11U)) + 12988052764067518580U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 17717179747434679772U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aPrevious, 37U)) + 11662190906682400416U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 3U)) + 6563014073547628748U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13099094932059419219U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16342730862261868847U;
            aOrbiterI = RotL64((aOrbiterI * 10988124108686164829U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16855346813127524624U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6570063128502306944U;
            aOrbiterH = RotL64((aOrbiterH * 4571570049463124831U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11328352033809240501U) + RotL64(aNonceWordG, 7U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11640986648833160901U;
            aOrbiterK = RotL64((aOrbiterK * 2895830492089678919U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 2675226158571501666U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordH, 61U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17700531248266458165U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2231403813970188657U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7729597396731910874U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15172374484412053756U;
            aOrbiterF = RotL64((aOrbiterF * 149009041406406517U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9178769489257842683U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9020154972097834926U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8910504667566521429U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1317403761217790562U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17151528554929201571U;
            aOrbiterG = RotL64((aOrbiterG * 3735945655450625203U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11621882033959669977U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10289504450815075623U;
            aOrbiterD = RotL64((aOrbiterD * 13365982786836243195U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16178772981106335703U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16896130772325866910U;
            aOrbiterJ = RotL64((aOrbiterJ * 6993524735412868965U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9573223644675562575U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17552463713786507189U;
            aOrbiterA = RotL64((aOrbiterA * 16103431656424881779U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4801852246698369631U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12222235191147985484U;
            aOrbiterC = RotL64((aOrbiterC * 2835204872125428065U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 6U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 44U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + RotL64(aNonceWordC, 23U)) + aPhaseEWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + RotL64(aNonceWordE, 42U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordC, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17036U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16558U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19500U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((aIndex + 21627U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 22U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aCross, 51U)) + 13583136155674166402U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 43U)) + 12830472187484919497U) + RotL64(aNonceWordF, 13U);
            aOrbiterD = ((aWandererA + RotL64(aScatter, 34U)) + RotL64(aCarry, 29U)) + 18081197909484522509U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 8680634051297891550U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 11U)) + 13939998767458656823U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 21U)) + 1795730579103692594U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 57U)) + 17369751719734069999U;
            aOrbiterG = ((((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 224769585901248068U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordH, 47U);
            aOrbiterB = (aWandererK + RotL64(aIngress, 18U)) + 4133547085925268180U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 47U)) + 7022512056309567391U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 53U)) + 10319484359046945495U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10483878349412282069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6481381149199985736U;
            aOrbiterD = RotL64((aOrbiterD * 9701719367082506253U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13721077228796934509U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9704818014314175007U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 760445624027740287U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6253040047758584339U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16890211690273641226U;
            aOrbiterF = RotL64((aOrbiterF * 5622534399866057841U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6216227831265032436U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2023609047004658739U;
            aOrbiterI = RotL64((aOrbiterI * 3252332895698310147U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9201669637050388263U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5106927540934338576U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6368134569042291431U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10080368957861445998U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10784789383436485808U;
            aOrbiterB = RotL64((aOrbiterB * 3794918350254445939U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15426339824951793026U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17637144549368340331U) ^ RotL64(aNonceWordB, 21U);
            aOrbiterA = RotL64((aOrbiterA * 10971293914614704441U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9941300382181962134U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8118046374121322097U;
            aOrbiterK = RotL64((aOrbiterK * 8481945819050983127U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5138086185042567633U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7279942739248982986U;
            aOrbiterC = RotL64((aOrbiterC * 12911998308338410917U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12135610639038562853U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12945353426409788798U) ^ RotL64(aNonceWordG, 35U);
            aOrbiterH = RotL64((aOrbiterH * 7434977715954413699U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7534876598022096222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13583136155674166402U;
            aOrbiterJ = RotL64((aOrbiterJ * 8194058098043157015U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 39U)) + aOrbiterF) + RotL64(aNonceWordA, 15U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 30U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterK, 60U));
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 26U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + RotL64(aNonceWordD, 60U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 24U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 44U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23912U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23197U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordD, 44U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26906U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 25183U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aScatter, 27U)) + 9914837590440975587U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 21U)) + 6706125076401958051U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 57U)) + 16570817772679258409U) + RotL64(aNonceWordA, 9U);
            aOrbiterH = (((aWandererC + RotL64(aIngress, 37U)) + 6843705658115186948U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordH, 10U);
            aOrbiterG = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 16099930446791572351U;
            aOrbiterA = (aWandererK + RotL64(aCross, 43U)) + 5420550009556030459U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 5729549069420177477U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 41U)) + 15590601126188675834U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 11U)) + 13044027390998620029U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 11068338135659636772U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 6U)) + 6584988841809544332U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8516813219883915404U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10647314042912492785U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15559481057047148785U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 201691689889605304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15512161798401184003U;
            aOrbiterA = RotL64((aOrbiterA * 11473219183982564709U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3883760518944464145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterF = RotL64((aOrbiterF * 17194438894492581181U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12019138626550801486U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13030350224959652248U;
            aOrbiterI = RotL64((aOrbiterI * 11724200983306280107U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2643807255422544248U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4127143302485631794U;
            aOrbiterD = RotL64((aOrbiterD * 5441038881111578487U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14602951930809633069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4555737199162278494U;
            aOrbiterH = RotL64((aOrbiterH * 12415825635220991865U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6343143902997169834U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10404783711336491985U) ^ RotL64(aNonceWordE, 43U);
            aOrbiterB = RotL64((aOrbiterB * 6235474458879439079U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7406959231434835393U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6684368109277850196U;
            aOrbiterE = RotL64((aOrbiterE * 8760360417572331159U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4835889355927954728U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7917682889852676712U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9045350756570117327U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10268055422944417055U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5563744562922937643U;
            aOrbiterJ = RotL64((aOrbiterJ * 12442484191329795173U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17244672945880141679U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9914837590440975587U) ^ RotL64(aNonceWordB, 25U);
            aOrbiterG = RotL64((aOrbiterG * 12269340309792850489U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + RotL64(aNonceWordF, 53U));
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 36U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 50U) + RotL64(aOrbiterF, 38U)) + aOrbiterI) + RotL64(aNonceWordC, 45U)) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererG, 26U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 24U) ^ RotL64(aNonceWordF, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31054U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28126U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 40U) ^ RotL64(aNonceWordC, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29503U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 32248U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 12426357877879529292U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 11U)) + 12604900366173639176U) + aPhaseEOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordF, 12U);
            aOrbiterK = ((aWandererK + RotL64(aCross, 47U)) + 13511119007338929401U) + aPhaseEOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 9878720081166788060U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 56U)) + 15463195409806395076U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 27U)) + 6407922778852833423U;
            aOrbiterG = (aWandererI + RotL64(aCross, 43U)) + 7690427254160734016U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 41U)) + 18030974031722143619U;
            aOrbiterB = (aWandererE + RotL64(aCross, 34U)) + 17983938038322737041U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 16605512170117753884U) + RotL64(aNonceWordG, 55U);
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 51U)) + 681802273302348322U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15550312921312083819U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 17824154101711884508U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7358612830654795357U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1939207786756735430U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3132864634777826569U;
            aOrbiterI = RotL64((aOrbiterI * 13606281919426730325U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12822929773923954849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16576106045887115660U;
            aOrbiterA = RotL64((aOrbiterA * 16370914370769903051U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2398825881649235260U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13700821892926092479U;
            aOrbiterG = RotL64((aOrbiterG * 10830623703416956043U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2439833784883391606U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15870638514107637833U;
            aOrbiterF = RotL64((aOrbiterF * 3797380922767479287U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9165457123134229670U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8736642509192659417U;
            aOrbiterB = RotL64((aOrbiterB * 16219277537523484065U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9232719746484835693U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7826680628853322541U;
            aOrbiterD = RotL64((aOrbiterD * 12578050118133526187U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14323652326982518782U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2254524512851399313U;
            aOrbiterJ = RotL64((aOrbiterJ * 4119339547645451149U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14459632243829356472U) + RotL64(aNonceWordA, 59U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8591197056749497716U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13053836520694721881U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17220196418897000411U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7186579019945992185U;
            aOrbiterE = RotL64((aOrbiterE * 12406048515179065691U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7554005180895698880U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12426357877879529292U) ^ RotL64(aNonceWordD, 13U);
            aOrbiterC = RotL64((aOrbiterC * 5090046967147694465U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 24U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterE, 3U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 48U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterA, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 40U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + RotL64(aNonceWordE, 9U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 18U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterD) + RotL64(aNonceWordH, 25U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_Lacrosse_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBC35F20EE80DA3DBULL + 0xE369703A8AA3AD44ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8A005CCE23999ACDULL + 0x9705A466FC1FBEFCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xECC97B8B2EECDE7DULL + 0xD8F5D7BF1D17CF01ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9F0B927F1900E07FULL + 0xA1A26DFA1FA3B88DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF613D14DB7513661ULL + 0xCB22E7998CB7875DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA166BF4F9344C565ULL + 0x80FC1041E84E61AEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x931C1B01AAC117DFULL + 0x9160C73509A1412DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFF486B8D4DB98B4FULL + 0xADAE289213A016E2ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordD, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1268U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3339U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 41U) ^ RotL64(aNonceWordF, 11U)) ^ RotL64(aNonceWordE, 20U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5041U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 5125U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 48U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aPrevious, 43U)) + 13481227414590594621U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 51U)) + 17425964381118918026U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 4792004356135956581U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 11926849936000639098U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 29U)) + 990697329347742142U;
            aOrbiterJ = ((((aWandererC + RotL64(aScatter, 56U)) + RotL64(aCarry, 19U)) + 9307721505373076588U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordC, 25U);
            aOrbiterE = (aWandererA + RotL64(aCross, 53U)) + 17605732738841908719U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 19U)) + 13110764518634187439U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 39U)) + 17970109897810645911U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 6U)) + 10273133817644703654U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 21U)) + 11239046688920468137U) + RotL64(aNonceWordA, 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8355821483275763145U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15522151127786049345U;
            aOrbiterK = RotL64((aOrbiterK * 4844278537850520413U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5381663179722418112U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9551368011768104906U;
            aOrbiterJ = RotL64((aOrbiterJ * 14202470972121732997U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16264476585232221270U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7721417776432288282U;
            aOrbiterI = RotL64((aOrbiterI * 10267770327791051869U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 339418090653475277U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3247926250495935511U;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3390560045236418590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3894024951542543635U;
            aOrbiterE = RotL64((aOrbiterE * 10599637790900418767U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3878539166189668154U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5617705593218220843U;
            aOrbiterF = RotL64((aOrbiterF * 82771190372750823U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12320861089148474544U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14943790251625519550U;
            aOrbiterG = RotL64((aOrbiterG * 13758322022902008313U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18119213517612562775U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1413193144229486646U;
            aOrbiterA = RotL64((aOrbiterA * 14562375280658115687U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14810150213456844196U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8468712395797520201U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterC = RotL64((aOrbiterC * 8167911669632436949U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13501570100536254566U) + RotL64(aNonceWordB, 6U);
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15409772061478100850U;
            aOrbiterB = RotL64((aOrbiterB * 955182899606655851U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8621805947309982779U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13481227414590594621U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9591362493722704105U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterB, 35U));
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 60U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + RotL64(aNonceWordG, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterI, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordF, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 53U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordE, 22U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9707U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 7176U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordC, 18U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7179U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6725U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 40U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aScatter, 18U)) + 5697928251815176134U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 13U)) + 337587740689259575U) + RotL64(aNonceWordH, 47U);
            aOrbiterH = ((aWandererD + RotL64(aIngress, 23U)) + 4927686903263973950U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 37U)) + 3742409032569801033U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 43U)) + 1608092659172197650U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 29U)) + 15848744267145717509U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 15300174177963339253U) + RotL64(aNonceWordF, 48U);
            aOrbiterD = (aWandererJ + RotL64(aCross, 21U)) + 14162868453323648628U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 53U)) + 12020167069983729869U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 16259538291658723956U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 51U)) + 8516686212464112245U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3722184575520553132U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5663609293306386784U;
            aOrbiterH = RotL64((aOrbiterH * 14364218128780764749U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15265344442454471986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1093356813820599238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15167726103772238440U;
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15170797965325981472U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17826286701992981628U;
            aOrbiterI = RotL64((aOrbiterI * 11186808881726573677U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14710892030473425181U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 397194787697553904U;
            aOrbiterF = RotL64((aOrbiterF * 14368930300818752833U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1273724124862533034U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13018397560392545616U;
            aOrbiterK = RotL64((aOrbiterK * 4644812473262395329U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9638716186445643730U) + RotL64(aNonceWordB, 21U);
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7255587739807843785U;
            aOrbiterC = RotL64((aOrbiterC * 6055682981584011189U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9272350563697399628U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1040729335295009339U;
            aOrbiterE = RotL64((aOrbiterE * 17825687660830291443U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12128124729613601747U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2285238815562202219U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15398840993074390573U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6339113298619163493U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5911895708485037040U;
            aOrbiterB = RotL64((aOrbiterB * 3271006139923200439U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7601399508218901328U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 5697928251815176134U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) ^ RotL64(aNonceWordG, 55U);
            aOrbiterJ = RotL64((aOrbiterJ * 8184257916861355735U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + RotL64(aNonceWordC, 59U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererB = aWandererB + ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 6U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 41U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 24U)) + aOrbiterH) + RotL64(aNonceWordA, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordD, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14472U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 13863U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordC, 47U)) ^ RotL64(aNonceWordH, 4U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12326U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13674U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 26U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 19U)) + 16124889768301047791U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 27U)) + 11912338587186717280U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 47U)) + 8594012868813114354U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 23U)) + 18281043566156682815U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 29U)) + 16853106130200942302U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 57U)) + 2611212958619673086U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 21U)) + 18039472325066855180U) + RotL64(aNonceWordB, 41U);
            aOrbiterK = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 14495785571345122046U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 4556063793412832418U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 50U)) + 14896419970271244358U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 5U)) + 880028529183500036U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordD, 7U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2379557167489415783U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11854373946064529806U;
            aOrbiterJ = RotL64((aOrbiterJ * 150755294320438887U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1487252775956449964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12777924204511625545U;
            aOrbiterB = RotL64((aOrbiterB * 1366019527386994789U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15998631485222477969U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8864212892296191613U) ^ RotL64(aNonceWordE, 11U);
            aOrbiterE = RotL64((aOrbiterE * 579242788050369815U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17069347835763226743U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7443008171694679791U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 748894368884566607U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 17334256152350782002U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8986626119086556393U;
            aOrbiterK = RotL64((aOrbiterK * 2258172145924120235U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8528180968228358674U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12702290928064582589U;
            aOrbiterA = RotL64((aOrbiterA * 15673603224146737631U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7742438100860023610U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3729687240959702198U) ^ RotL64(aNonceWordG, 3U);
            aOrbiterH = RotL64((aOrbiterH * 3756794766163746783U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 426129097367382096U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16782175452274911213U;
            aOrbiterD = RotL64((aOrbiterD * 1041477289638333659U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5942016166948841079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5260815086125551703U;
            aOrbiterC = RotL64((aOrbiterC * 1603799103692438147U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11732742583346900772U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17182924380693084401U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14858685629471497071U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8539335803784852017U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16124889768301047791U;
            aOrbiterF = RotL64((aOrbiterF * 6607245691919237755U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 42U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 36U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + RotL64(aNonceWordF, 12U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterK, 22U)) + RotL64(aNonceWordC, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 43U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterG, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterA, 10U));
            aWandererK = aWandererK + ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordF, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21341U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 18666U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordA, 60U)) ^ RotL64(aNonceWordH, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21165U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16558U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 27U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aCross, 5U)) + 13296600294247799698U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 46U)) + 5818503518080877515U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 6735784238734173597U) + RotL64(aNonceWordD, 37U);
            aOrbiterC = (aWandererB + RotL64(aPrevious, 11U)) + 7368398209488856201U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 27U)) + 961734029066455638U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 34U)) + 797011946660892011U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 12841876018396622350U) + RotL64(aNonceWordA, 21U);
            aOrbiterG = (aWandererI + RotL64(aIngress, 19U)) + 16213253970483895623U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 13U)) + 15186950557113470375U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 5117930310827477341U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 21U)) + 12265429373166094162U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13920531346698601568U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14695405206998211456U;
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7851960904825938443U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9501511171732550190U) ^ RotL64(aNonceWordF, 15U);
            aOrbiterJ = RotL64((aOrbiterJ * 5614164120361489613U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5663365182245722077U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9607860124321315555U;
            aOrbiterF = RotL64((aOrbiterF * 3461820361914280601U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 18171052650586819280U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3442698321538580861U;
            aOrbiterA = RotL64((aOrbiterA * 6317525514963824829U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1491052813469258970U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3956599824067616133U;
            aOrbiterG = RotL64((aOrbiterG * 2928600779267623085U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10963841237346073453U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2303020125591252534U) ^ RotL64(aNonceWordB, 11U);
            aOrbiterE = RotL64((aOrbiterE * 9969099842343321981U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14503856057958162356U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11147548150090597694U;
            aOrbiterB = RotL64((aOrbiterB * 11856382308792700441U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9191681438318311481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13556072770381999852U;
            aOrbiterH = RotL64((aOrbiterH * 18316231099054203683U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10103207278550444685U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10415809965217261104U;
            aOrbiterK = RotL64((aOrbiterK * 16562732599511350217U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17435033201864058457U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5540494424887364682U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18230910315317249045U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 18020151683897013854U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13296600294247799698U;
            aOrbiterC = RotL64((aOrbiterC * 10000194329456668845U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterB, 22U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterI, 5U)) + RotL64(aNonceWordC, 12U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 41U));
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterE) + RotL64(aNonceWordG, 53U));
            aWandererC = aWandererC + ((RotL64(aCross, 24U) + RotL64(aOrbiterF, 35U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterG, 52U));
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererC, 54U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordC, 30U)) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23952U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 22828U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordD, 14U)) ^ RotL64(aNonceWordE, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23485U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 22063U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 26U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aIngress, 3U)) + 18302975933754610273U) + RotL64(aNonceWordF, 41U);
            aOrbiterF = ((aWandererF + RotL64(aCross, 38U)) + 16736972646771456082U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 17389406266488137442U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 57U)) + 5252511566486165539U) + RotL64(aNonceWordA, 56U);
            aOrbiterH = ((aWandererA + RotL64(aIngress, 27U)) + 5730715427422747640U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 29U)) + 6412695646456045825U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 9539701605708994494U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 40U)) + 18355107116412945722U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 13U)) + 11735742491750132942U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 12363819388562658842U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 5U)) + 5861430292304371543U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15027487084595017708U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7012850020745791926U;
            aOrbiterJ = RotL64((aOrbiterJ * 15952928839355613939U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11904871669287886120U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11199760114477343208U;
            aOrbiterI = RotL64((aOrbiterI * 7156374911847525867U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3856004502263742700U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3705931243173921893U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10334871178498711485U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12305785390539209389U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18057980996551978823U;
            aOrbiterB = RotL64((aOrbiterB * 4850564181113470859U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3229431819292153014U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2994716629242460094U;
            aOrbiterG = RotL64((aOrbiterG * 1029427328395257917U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9796307843453735512U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2957260393651252432U) ^ RotL64(aNonceWordD, 39U);
            aOrbiterA = RotL64((aOrbiterA * 7261055869794739609U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4060469664218866340U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17462081697889685330U;
            aOrbiterC = RotL64((aOrbiterC * 7712009170974461225U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13638660073917821172U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15202349592659062565U;
            aOrbiterE = RotL64((aOrbiterE * 4514326257446024301U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12071949111168967041U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11930843273199806728U;
            aOrbiterK = RotL64((aOrbiterK * 16229663295689525137U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 11294220104731500296U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordE, 7U);
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 440743185210586759U;
            aOrbiterF = RotL64((aOrbiterF * 14810195235168807229U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8514240764798061804U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18302975933754610273U;
            aOrbiterH = RotL64((aOrbiterH * 1972439346780950873U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 10U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 42U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + RotL64(aNonceWordG, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterI, 37U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 54U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererB, 24U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordE, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29181U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 28290U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordD, 29U)) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30171U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 32410U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 29U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aCross, 37U)) + 8988572360732005217U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 54U)) + RotL64(aCarry, 51U)) + 17889613225105985335U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 57U)) + 15563478320513948626U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 13U)) + 3441351228410524816U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 19U)) + 4425592689451435346U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 28U)) + 12733160231627305928U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 35U)) + 3574152157304607854U) + RotL64(aNonceWordB, 3U);
            aOrbiterH = (aWandererF + RotL64(aCross, 5U)) + 15167631896729808783U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 15822667973915417055U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 47U)) + 17181685481076577637U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 9979204751408873468U) + RotL64(aNonceWordA, 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1334240485667164762U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9190066751460137016U;
            aOrbiterE = RotL64((aOrbiterE * 14585141844653660363U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15465215829109246336U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2305208282453624419U;
            aOrbiterJ = RotL64((aOrbiterJ * 10257861974108363283U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16951510027310993926U) + RotL64(aNonceWordF, 57U);
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11117938943423526901U;
            aOrbiterF = RotL64((aOrbiterF * 7805486716716924787U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12461379120662979432U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11719697049048823897U) ^ RotL64(aNonceWordD, 11U);
            aOrbiterG = RotL64((aOrbiterG * 14880996802304818757U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6843357278142933570U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12727898578324702374U;
            aOrbiterH = RotL64((aOrbiterH * 9786435451654365097U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18127999660067652233U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11754709060558683082U;
            aOrbiterB = RotL64((aOrbiterB * 12798744012150745847U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16940151146420516184U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12924950783056761895U;
            aOrbiterD = RotL64((aOrbiterD * 8898170377271926745U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14829713915929878471U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 840466047621042565U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10748511630509529489U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11469637840333471085U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5561780312837795893U;
            aOrbiterI = RotL64((aOrbiterI * 11935079844970978957U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1059834104159730610U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10122108814456766430U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2184693583782179921U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14857099570072635006U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8988572360732005217U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14409836741925393077U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 38U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterG, 48U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 41U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterE, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterC, 28U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + RotL64(aNonceWordH, 55U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + RotL64(aNonceWordC, 10U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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

void TwistExpander_Lacrosse_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCCEEA873D62521CFULL + 0xF98D64A64595BFC3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE70235CFE3ADE177ULL + 0x8114F6028BC0818FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEA263EF1CC98A98FULL + 0xF917B91F0A7F5A5BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEBB8447671B8A869ULL + 0xF830F18F4A0B7C23ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA1624D9682435723ULL + 0xD698E7B52DACBDB3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFC3A185843FC8E35ULL + 0xDA7402F8571695DEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x89C752E901D8EA2DULL + 0xBA84CFD904049486ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDA4CD7E3A1047935ULL + 0xCD61186EE4507FBAULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2549U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((aIndex + 3130U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordE, 40U)) ^ RotL64(aNonceWordF, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2279U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 3153U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 56U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 6U)) + 16200278595895089008U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 29U)) + 1029614154810465897U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 7129562468705441295U) + RotL64(aNonceWordF, 61U);
            aOrbiterA = (aWandererE + RotL64(aCross, 39U)) + 14388903902433951274U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 37U)) + 1013568949315967455U) + RotL64(aNonceWordD, 45U);
            aOrbiterF = (aWandererJ + RotL64(aCross, 27U)) + 3128823373497815651U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 14525694606889470589U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 47U)) + 14443983602196782887U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 12244220415328641190U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 23U)) + 10477159225338766614U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 56U)) + 2842870123078131566U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8621138818955849917U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5038396344400303181U;
            aOrbiterG = RotL64((aOrbiterG * 14636756322207385447U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2768613802894372496U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2027754864051410015U;
            aOrbiterF = RotL64((aOrbiterF * 2461322540050569287U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2848088309172056399U) + RotL64(aNonceWordC, 25U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15017458513904884651U;
            aOrbiterK = RotL64((aOrbiterK * 9926904679902843055U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9079797279596336139U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15424866642305110811U;
            aOrbiterA = RotL64((aOrbiterA * 12912331089970158845U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13751764050290602740U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7694557131324740282U;
            aOrbiterI = RotL64((aOrbiterI * 14980807690491467023U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3508673897305667669U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3600868397311393233U;
            aOrbiterB = RotL64((aOrbiterB * 5165032044164139165U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1222655844979128996U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2257342337168905875U;
            aOrbiterH = RotL64((aOrbiterH * 6198995971182272119U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6290990717563682725U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15308494772443447109U;
            aOrbiterD = RotL64((aOrbiterD * 1925593111157842325U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4065385272074155855U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17216369169581934516U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16172589962950781777U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15683161334290612079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4197626901960576264U;
            aOrbiterE = RotL64((aOrbiterE * 2822547214684481747U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4400047838649306704U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 16200278595895089008U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) ^ RotL64(aNonceWordG, 59U);
            aOrbiterJ = RotL64((aOrbiterJ * 6603195071605635697U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterI, 26U)) + aPhaseFWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterA, 23U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aNonceWordB, 24U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 41U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 30U) + aOrbiterK) + RotL64(aOrbiterJ, 39U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + RotL64(aNonceWordA, 9U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordH, 39U)) ^ RotL64(aNonceWordD, 48U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8372U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 8607U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 12U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8435U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 9571U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 47U)) + (RotL64(aPrevious, 22U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 35U)) + 10812151398716051703U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 37U)) + 18202551453336003710U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 13U)) + 9434410809101973752U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 44U)) + 12955829998028534045U) + RotL64(aNonceWordG, 8U);
            aOrbiterK = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 12271740641929640181U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 14009351527014534752U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 53U)) + 4316296955679133450U) + RotL64(aNonceWordA, 27U);
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 16473324966997442872U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 56U)) + 15735123324965019802U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 39U)) + 17656375090484080236U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 29U)) + 16066325053456055298U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12908968778503516903U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 12761433987676836197U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ RotL64(aNonceWordB, 55U);
            aOrbiterD = RotL64((aOrbiterD * 1023329467480907925U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12737513138040664509U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14535795767570998392U;
            aOrbiterB = RotL64((aOrbiterB * 15560519667062222269U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14370908061811284364U) + RotL64(aNonceWordD, 37U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7001358781208669795U;
            aOrbiterK = RotL64((aOrbiterK * 11641248025734015835U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7298578161120090849U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10498302152357484629U;
            aOrbiterH = RotL64((aOrbiterH * 13144110412179037175U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11447343228638006767U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 18284143620422655675U;
            aOrbiterE = RotL64((aOrbiterE * 572862190073605651U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5918253208127360199U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3910541329178205943U;
            aOrbiterF = RotL64((aOrbiterF * 4550654545328228103U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10357053096941367910U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5610891501128498748U;
            aOrbiterG = RotL64((aOrbiterG * 8676370811772047449U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9049881176058575811U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6307599924966452216U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5551444450572055895U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17109966783467892046U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11563095828344462249U;
            aOrbiterC = RotL64((aOrbiterC * 15463753739272001875U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3739147427725509014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5324449517615050698U;
            aOrbiterJ = RotL64((aOrbiterJ * 5926079615575226853U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5706251076252597592U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10812151398716051703U;
            aOrbiterI = RotL64((aOrbiterI * 5666491216813197045U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 50U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 34U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 26U) + aOrbiterE) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + RotL64(aNonceWordF, 15U)) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 39U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 41U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + RotL64(aNonceWordH, 53U));
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterC, 18U)) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 52U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordH, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11207U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 15570U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordC, 48U)) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15591U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11134U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 37U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 24U)) + RotL64(aCarry, 21U)) + 3236820517816085022U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 21U)) + 741288875914097926U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 11U)) + 8417246926007729580U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 27U)) + 9715717805774537170U) + aPhaseFOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordE, 15U);
            aOrbiterB = (aWandererG + RotL64(aIngress, 3U)) + 14360243844821619482U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 47U)) + 10760908100206775334U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 51U)) + 3434641779946167811U) + aPhaseFOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 30U)) + 7885568822756234567U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 3041563437672051294U;
            aOrbiterK = (aWandererA + RotL64(aCross, 19U)) + 15761355327564963516U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 1158633562785937421U) + RotL64(aNonceWordB, 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9338581575871970653U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9172038894262857354U;
            aOrbiterH = RotL64((aOrbiterH * 3110871165285625807U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14653924713599790081U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3854497592598563309U;
            aOrbiterF = RotL64((aOrbiterF * 11737111068815795303U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16286980180327600557U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5092583772591249756U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13955105624639442903U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4288397994175567333U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15584236478994873104U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1860480595862755379U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5557463939827483792U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2659814275753280856U) ^ RotL64(aNonceWordC, 52U);
            aOrbiterJ = RotL64((aOrbiterJ * 17702430405693184643U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6941807963525063449U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2040598555191211307U;
            aOrbiterK = RotL64((aOrbiterK * 14750544987531722765U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 347572666231116258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 779304821185302523U;
            aOrbiterC = RotL64((aOrbiterC * 14180254150318109855U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10632524582873079742U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9761308771280517212U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterA = RotL64((aOrbiterA * 13926235411726048921U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2097439707055737964U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2813977930321463948U;
            aOrbiterD = RotL64((aOrbiterD * 14983538728730662603U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6080592019313796689U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5396623654821376409U;
            aOrbiterI = RotL64((aOrbiterI * 15478858835919398677U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8460497459575045342U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3236820517816085022U;
            aOrbiterG = RotL64((aOrbiterG * 5530411244458067093U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterD, 19U));
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 37U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + RotL64(aNonceWordA, 43U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterD, 47U)) + aOrbiterF) + RotL64(aNonceWordG, 31U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterG, 24U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 44U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordE, 54U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21675U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 19157U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordH, 5U)) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18107U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19045U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCross, 13U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aIngress, 39U)) + 13442819395490639310U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 8187292523194120936U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 11469697159823131388U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 53U)) + 13414083692375929653U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 24U)) + RotL64(aCarry, 19U)) + 11404010733687907517U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 51U)) + 6783212827186218247U) + RotL64(aNonceWordD, 17U);
            aOrbiterG = (aWandererH + RotL64(aScatter, 41U)) + 8561131439340372614U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 3U)) + 6252609642004429113U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 27U)) + 12804867444200448952U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordH, 21U);
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 22U)) + 2739648749603690781U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 35U)) + 14808861217017399752U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17588866502571268888U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5882260142735642980U;
            aOrbiterE = RotL64((aOrbiterE * 7688252946143263869U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15493099088132862949U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5175647411532429582U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15226544495598541883U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14279707376173642767U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6826363572161275158U;
            aOrbiterD = RotL64((aOrbiterD * 5263708315440161809U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13267185753040999992U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9980987858092888720U;
            aOrbiterG = RotL64((aOrbiterG * 13210290848800728635U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3582972937645514549U) + RotL64(aNonceWordA, 49U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10140409019562890804U;
            aOrbiterB = RotL64((aOrbiterB * 6944490201647678479U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6160444117287330557U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16344602960561293113U;
            aOrbiterH = RotL64((aOrbiterH * 2319964919335633293U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3497141036108337171U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 91269118352540308U;
            aOrbiterC = RotL64((aOrbiterC * 5160060720189045505U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12739932748793144857U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12820180915064791197U;
            aOrbiterK = RotL64((aOrbiterK * 5843849637411948699U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17572075652083359962U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10684041099654982701U;
            aOrbiterI = RotL64((aOrbiterI * 7121293375756263771U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10739534650885677354U) + RotL64(aNonceWordB, 41U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9731206787727954809U;
            aOrbiterJ = RotL64((aOrbiterJ * 3730875775588585547U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9655432616347117764U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13442819395490639310U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3650859301708619119U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 30U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterG, 12U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterK, 19U));
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterI, 37U));
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 60U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + RotL64(aCarry, 13U)) + RotL64(aNonceWordG, 46U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererE = aWandererE + (((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 23U)) + aOrbiterB) + RotL64(aNonceWordF, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordC, 58U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22335U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21853U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordH, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23048U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 26142U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 60U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 1297415699043177788U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 17583786534509260153U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 3U)) + 643197858925708798U;
            aOrbiterI = (aWandererE + RotL64(aCross, 6U)) + 5062653766915694874U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 43U)) + 7034273638367180511U) + RotL64(aNonceWordG, 3U);
            aOrbiterF = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 2026909726972916996U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 35U)) + 2785690475553211646U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 50U)) + 2910341716302991892U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 39U)) + 2834181605200829791U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 57U)) + 13323052600571281928U) + RotL64(aNonceWordA, 52U);
            aOrbiterD = ((aWandererG + RotL64(aIngress, 21U)) + 10434901530315760460U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 247903955625194782U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5196515747387257163U;
            aOrbiterC = RotL64((aOrbiterC * 1799024689023272275U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7196305682377987476U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 14777739876892587484U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1]) ^ RotL64(aNonceWordE, 45U);
            aOrbiterF = RotL64((aOrbiterF * 95220583948241581U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10609060796540136671U) + RotL64(aNonceWordC, 17U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8386027207212484155U;
            aOrbiterA = RotL64((aOrbiterA * 4855610536246556893U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 729659744301903424U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2350564261412606157U;
            aOrbiterE = RotL64((aOrbiterE * 16713856782349084977U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16611987556673864177U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1525195188708550503U;
            aOrbiterH = RotL64((aOrbiterH * 10045858602151004553U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4654808490980989596U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8189569777087686263U;
            aOrbiterI = RotL64((aOrbiterI * 17278657566389299577U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10932857495004451792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1833880112534916813U;
            aOrbiterK = RotL64((aOrbiterK * 8004341577533825681U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13100236350175516423U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2773759534195186313U;
            aOrbiterB = RotL64((aOrbiterB * 3194954066097323161U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13963126688973399221U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 1464529855671190406U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6129954747502059213U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9489842625026216815U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17806120432918490594U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 349307975773661379U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13833297268854563081U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1297415699043177788U;
            aOrbiterJ = RotL64((aOrbiterJ * 4818542043777342249U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 4U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 60U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterD, 21U));
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 11U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + RotL64(aNonceWordH, 39U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 5U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterI, 38U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ) + RotL64(aNonceWordD, 37U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterH, 35U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27680U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28925U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 12U) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32641U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 30516U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (((aWandererK + RotL64(aCross, 34U)) + 13174219512651137892U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 5U);
            aOrbiterB = (aWandererD + RotL64(aScatter, 39U)) + 2715455762789269341U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 29U)) + 1338018183235594313U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 19U)) + 16566866551729552930U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 6U)) + RotL64(aCarry, 19U)) + 6901845297307236726U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 2476078302049201718U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 15531109473927052260U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 21U)) + 4087849380858572351U) + aPhaseFOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 23U)) + 5167830630098599644U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 3U)) + 7275995452428627217U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 43U)) + 14794340370010024117U) + RotL64(aNonceWordH, 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8509217403041662849U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2321522025240806996U) ^ RotL64(aNonceWordF, 61U);
            aOrbiterC = RotL64((aOrbiterC * 113568101672878697U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5676672952755594051U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2304681269233504384U;
            aOrbiterD = RotL64((aOrbiterD * 15731441084605554497U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8383399721062437300U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13181984036942227666U;
            aOrbiterF = RotL64((aOrbiterF * 1648761328771932069U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13602604532551684210U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12725687663616352843U) ^ RotL64(aNonceWordD, 19U);
            aOrbiterA = RotL64((aOrbiterA * 4684699861686199753U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5831790822416009806U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4535048543735457407U;
            aOrbiterE = RotL64((aOrbiterE * 12076777878870257053U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10617608605149381858U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5244225377862618630U;
            aOrbiterH = RotL64((aOrbiterH * 15307177251167023999U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18229989093139888456U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9728120630096192811U;
            aOrbiterJ = RotL64((aOrbiterJ * 16052574428163231023U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1312233443099767304U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8043115602160128619U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9365756845731616963U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4679339316686216023U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 211799535650113758U;
            aOrbiterK = RotL64((aOrbiterK * 1478368466990144107U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13307123762743628190U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7093673238704478497U;
            aOrbiterB = RotL64((aOrbiterB * 13273906568866802561U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16396459072175632290U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13174219512651137892U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7581008806810219369U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 60U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterD, 35U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 19U)) + RotL64(aNonceWordE, 40U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterD, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI + (((RotL64(aCross, 52U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterA, 10U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + RotL64(aNonceWordC, 59U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Lacrosse_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3727U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 6082U)) & W_KEY1], 30U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1339U)) & W_KEY1], 41U) ^ RotL64(mSource[((aIndex + 462U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 11U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererI + RotL64(aScatter, 18U)) + RotL64(aCarry, 23U)) + 3917730204724097072U) + aPhaseCOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 1874642340716212824U;
            aOrbiterB = (aWandererC + RotL64(aCross, 47U)) + 6900165757434854160U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 35U)) + 12750946097023807161U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 27U)) + 6563216048479513594U) + aPhaseCOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 5U)) + 14960240191349450795U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 41U)) + 16306180275951788289U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 6502066618271045547U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 12U)) + 6219852857850888738U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2272931312452845850U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3028929882263199463U;
            aOrbiterB = RotL64((aOrbiterB * 11005324285856805069U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6067393030073568112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10094809900437037258U;
            aOrbiterF = RotL64((aOrbiterF * 18095564940730322769U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5962414178157074575U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15755563045799129417U;
            aOrbiterK = RotL64((aOrbiterK * 3692603590609922031U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6321455513889880590U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1197435601998121700U;
            aOrbiterI = RotL64((aOrbiterI * 17693996266260557625U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12496949381666299968U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6357070235648527030U;
            aOrbiterC = RotL64((aOrbiterC * 2931486644220862433U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8423760160877540210U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8090246492554850768U;
            aOrbiterD = RotL64((aOrbiterD * 2949407491181921633U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11436635942985063755U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17086363141014359856U;
            aOrbiterG = RotL64((aOrbiterG * 10504127577318206801U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10734017887545474935U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 375515325165740779U;
            aOrbiterJ = RotL64((aOrbiterJ * 9980486695448151709U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5217148491945389821U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14696058217023530058U;
            aOrbiterE = RotL64((aOrbiterE * 11026674782236654799U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 58U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 10U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterF, 5U)) + aPhaseCWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 47U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8864U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15668U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12575U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[((aIndex + 10092U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 29U)) + 12222235191147985484U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 16367317014523328414U) + aPhaseCOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 41U)) + 3511378091284703789U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 35U)) + 15247492830966725949U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 54U)) + 7745995913390407897U) + aPhaseCOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 6463593307540108810U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 1101669311005268630U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 3U)) + 12988052764067518580U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 46U)) + 17717179747434679772U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11662190906682400416U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6563014073547628748U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16967910471722117761U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13099094932059419219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16342730862261868847U;
            aOrbiterB = RotL64((aOrbiterB * 10988124108686164829U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16855346813127524624U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6570063128502306944U;
            aOrbiterC = RotL64((aOrbiterC * 4571570049463124831U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11328352033809240501U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11640986648833160901U;
            aOrbiterE = RotL64((aOrbiterE * 2895830492089678919U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2675226158571501666U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17700531248266458165U;
            aOrbiterG = RotL64((aOrbiterG * 2231403813970188657U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7729597396731910874U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15172374484412053756U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 149009041406406517U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9178769489257842683U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9020154972097834926U;
            aOrbiterH = RotL64((aOrbiterH * 8910504667566521429U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1317403761217790562U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17151528554929201571U;
            aOrbiterA = RotL64((aOrbiterA * 3735945655450625203U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11621882033959669977U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10289504450815075623U;
            aOrbiterI = RotL64((aOrbiterI * 13365982786836243195U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 24U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 28U) + aOrbiterG) + RotL64(aOrbiterA, 10U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 4U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + aPhaseCWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18034U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22549U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21163U)) & W_KEY1], 46U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20715U)) & W_KEY1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 42U)) + RotL64(aCarry, 35U)) + 8975885703279267062U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 8664844915562660637U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 23U)) + 12281774799736296726U;
            aOrbiterG = (aWandererH + RotL64(aCross, 11U)) + 15347461352311329726U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 34U)) + 12967500561828907834U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 5002833859280402726U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 47U)) + 11908257536954668983U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 51U)) + 17017174811949227162U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 29U)) + 16851323125613931180U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13469326957728686706U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5228638551056105241U;
            aOrbiterF = RotL64((aOrbiterF * 13369947664646167255U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11945166198089308564U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16268645041872996022U;
            aOrbiterJ = RotL64((aOrbiterJ * 5391448793718370911U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14781204627695095701U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5365325354838101092U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8017284997946310807U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 563147416025715953U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14660867395395625851U;
            aOrbiterI = RotL64((aOrbiterI * 4769458126865307103U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3168989056355712105U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16179131669773665579U;
            aOrbiterK = RotL64((aOrbiterK * 5641461617066671723U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4160220074225527179U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8597134686962559111U;
            aOrbiterD = RotL64((aOrbiterD * 639572585431474015U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16811551552456811661U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5827323970423386301U;
            aOrbiterA = RotL64((aOrbiterA * 9328247349730652021U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15583234353262170227U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2950816254621717748U;
            aOrbiterE = RotL64((aOrbiterE * 1102417597476170143U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4426165025104306337U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11871220132164971152U;
            aOrbiterB = RotL64((aOrbiterB * 2366168050042802207U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterB, 39U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 58U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 13U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29281U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31222U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29567U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31942U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aCross, 41U)) + 3105313968748067810U) + aPhaseCOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 52U)) + 9977249451119627064U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 17941392803495349366U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 37U)) + 4279533326705471133U) + aPhaseCOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 29U)) + 13983828966811580039U;
            aOrbiterA = (aWandererK + RotL64(aCross, 10U)) + 3983490984234810378U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 308786542215259956U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 57U)) + 8443607695364427037U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 14939626441464340668U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9350693577306121110U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1717071159396961752U;
            aOrbiterI = RotL64((aOrbiterI * 11062480662625054525U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15911765265202100610U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14898546272333182767U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2674900543810733067U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3560903518513465868U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5367062725726860234U;
            aOrbiterF = RotL64((aOrbiterF * 8521908836601319553U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15233321480618877327U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9288449812290126074U;
            aOrbiterC = RotL64((aOrbiterC * 6815298520404038519U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5504840529511585676U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6825598386801620046U;
            aOrbiterK = RotL64((aOrbiterK * 11666542445846250077U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6433024450721339470U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 97934156644929458U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8630530773006923215U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3260053604798744515U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16539416623243059076U;
            aOrbiterG = RotL64((aOrbiterG * 12199577351166064503U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9814290051339038920U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13280156404507444041U;
            aOrbiterB = RotL64((aOrbiterB * 15269010043398910061U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11853942590993546833U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13207869904312989977U;
            aOrbiterH = RotL64((aOrbiterH * 15503461937625795969U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 18U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + aPhaseCWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 28U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterF, 23U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 58U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Lacrosse_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4918U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1502U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5834U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6422U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 6069475454765660321U) + aPhaseDOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 13U)) + 11483704742497268068U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 57U)) + 11055697447388986418U) + aPhaseDOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 28U)) + RotL64(aCarry, 53U)) + 10897095046039997004U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 4731637118230457840U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13855839187084986751U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5328208115460188239U;
            aOrbiterK = RotL64((aOrbiterK * 3800417611141123383U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12479538544291412985U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10740165998792608231U;
            aOrbiterH = RotL64((aOrbiterH * 14046827922294477379U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6492798157284955373U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13056825957483891921U;
            aOrbiterE = RotL64((aOrbiterE * 14882112110627751751U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2068184064919194657U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5656302738780746294U;
            aOrbiterB = RotL64((aOrbiterB * 16493021179127646345U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11193756120230763294U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17306750816837208999U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7949360041241439741U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 6U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterF, 39U)) + aOrbiterB) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererG, 58U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16249U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10019U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9889U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12309U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 28U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 12046647397183218524U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 4U)) + RotL64(aCarry, 57U)) + 2760779375026461991U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 13U)) + 13735454443176855650U) + aPhaseDOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 4370377000586647724U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 35U)) + 14566322384189969094U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5056565959818422786U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8795403810686579209U;
            aOrbiterI = RotL64((aOrbiterI * 11205867337479457471U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9625947666256011567U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1703669290934254701U;
            aOrbiterA = RotL64((aOrbiterA * 5763881345676123583U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6664070663184147951U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2104148316797553431U;
            aOrbiterC = RotL64((aOrbiterC * 12887842067180975983U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1197910004222596145U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9922977170060903197U;
            aOrbiterG = RotL64((aOrbiterG * 13047828062605568603U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2048376210852567829U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12568990647075931409U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9860242601194210927U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 37U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 26U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21221U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 17783U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24273U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16836U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 54U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aCross, 3U)) + 17454559218352016650U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 8005709669325164803U) + aPhaseDOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 47U)) + 13393741948412816357U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 3665865624348875553U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 20U)) + RotL64(aCarry, 53U)) + 8334142570031883436U) + aPhaseDOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17226066128706139657U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3319093033121522613U;
            aOrbiterI = RotL64((aOrbiterI * 17961784341097933029U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6657535603401588798U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5469746182326331147U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11315450342347794329U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 17846791786050221418U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15939541003714896288U;
            aOrbiterH = RotL64((aOrbiterH * 1400351482213119809U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12076763190461077406U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3594038213596405284U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10244002692575821495U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8301291631324464622U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8460406137668390582U;
            aOrbiterB = RotL64((aOrbiterB * 9117147929757711595U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 36U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterH, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28121U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 27169U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32163U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((aIndex + 26887U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCross, 24U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 3917730204724097072U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 1874642340716212824U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 52U)) + RotL64(aCarry, 57U)) + 6900165757434854160U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 37U)) + 12750946097023807161U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 11U)) + 6563216048479513594U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14960240191349450795U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16306180275951788289U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12077366095522790283U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6502066618271045547U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6219852857850888738U;
            aOrbiterB = RotL64((aOrbiterB * 10892297250334325283U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2272931312452845850U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3028929882263199463U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11005324285856805069U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6067393030073568112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10094809900437037258U;
            aOrbiterK = RotL64((aOrbiterK * 18095564940730322769U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5962414178157074575U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15755563045799129417U;
            aOrbiterG = RotL64((aOrbiterG * 3692603590609922031U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 24U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK + ((RotL64(aCross, 58U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
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

void TwistExpander_Lacrosse_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5905U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4129U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3651U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((aIndex + 4985U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCarry, 36U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 17081642665820489793U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 14468854040067229623U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 3U)) + 2249450222593057429U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 35U)) + 14964389079511378664U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 27U)) + 17003491054252360650U;
            aOrbiterA = (aWandererB + RotL64(aCross, 53U)) + 12710882240582032588U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 9887078182156755359U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7665284531810584704U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7304284015511876717U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6193179739025093929U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5517927023543751734U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17704756310857362759U;
            aOrbiterB = RotL64((aOrbiterB * 15826832172923213591U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11347400363019508578U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11696395232760991243U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9725231749679442003U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10875780291242873583U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7808740614343437672U;
            aOrbiterH = RotL64((aOrbiterH * 8889516201913716283U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3145390996141902032U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16080636485642732615U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7445756373012217305U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3929263288176983844U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18210228766683996806U;
            aOrbiterG = RotL64((aOrbiterG * 13178080076505449091U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13948962323541421431U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3037683309790156893U;
            aOrbiterJ = RotL64((aOrbiterJ * 13406672352222636739U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 36U)) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC + ((((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12799U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 15137U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15131U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((aIndex + 14084U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 51U)) + 17668251151213543491U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 16101602509895104517U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 19U)) + 9083915270773304935U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 26U)) + 12810720730318214811U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 37U)) + 18113428002071925621U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 1582208899354109878U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 4180688104819188154U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8954598189262820611U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15360094153175355879U;
            aOrbiterH = RotL64((aOrbiterH * 8177798855402983685U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8383954114668216260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15626783326234049197U;
            aOrbiterD = RotL64((aOrbiterD * 15058420415480073793U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10609978564404958066U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17656516608997517984U;
            aOrbiterA = RotL64((aOrbiterA * 4590620354119899777U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 760077259110786536U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3597338735888033063U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6548831472863517621U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4431777844935985157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10710423172154671296U;
            aOrbiterG = RotL64((aOrbiterG * 16267496318491473315U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10240882795242085185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7826053487019825891U;
            aOrbiterI = RotL64((aOrbiterI * 15053729937684375907U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9418883403715727353U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11507423614799075545U;
            aOrbiterC = RotL64((aOrbiterC * 16189463984557044693U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 42U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 28U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 51U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20617U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17774U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24214U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20106U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 37U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 15652862298542575895U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 16925323928418184554U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 35U)) + 4413861484961668394U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 2215946422098155969U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 29U)) + 14975185533513111110U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 58U)) + 9711613814905834552U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 41U)) + 13154957291850149471U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5058313016418534840U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15011423472941211620U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6125316151731105673U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2030053257469580168U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 150530795186791193U;
            aOrbiterK = RotL64((aOrbiterK * 11106050063717096073U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10878237472104183427U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11724672539469573109U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16158741837357985395U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9589700906445846956U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1367381624958248949U;
            aOrbiterE = RotL64((aOrbiterE * 8459515089081211977U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12003215666757518106U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11232479330848006729U;
            aOrbiterG = RotL64((aOrbiterG * 10993290955464593033U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13013910456628561621U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 6092509838924105265U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 805601154718006061U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11999225836250312801U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14421271973875748413U;
            aOrbiterH = RotL64((aOrbiterH * 9529010940887430157U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 44U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterE, 10U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + aPhaseEWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterD, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 22U) + aOrbiterE) + RotL64(aOrbiterK, 21U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 41U)) + aOrbiterH) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25601U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30573U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26637U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 26880U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 12U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 3U)) + 3248574644570178787U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 58U)) + 4506961512959200024U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 8423739774540738590U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 27U)) + 6593975869641735337U) + aPhaseEOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 16441716090557369103U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 7936601450453207914U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 39U)) + 13333752583560167065U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8013703284795432973U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2349852779887439236U;
            aOrbiterG = RotL64((aOrbiterG * 2422888500648100783U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5318539364763284138U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11450957608502944376U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1957880366707810635U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9058992558327552687U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 632095686920230926U;
            aOrbiterK = RotL64((aOrbiterK * 12460364388358520799U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14734218428913777098U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16344357661370784442U;
            aOrbiterE = RotL64((aOrbiterE * 15049472842002138369U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2981145363531184308U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14176472085175714494U;
            aOrbiterI = RotL64((aOrbiterI * 2584623327412130939U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11198457590069700889U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 952584436750426828U;
            aOrbiterH = RotL64((aOrbiterH * 1165713888651280355U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4311591763498985972U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16194341833989936369U;
            aOrbiterF = RotL64((aOrbiterF * 9997934560195932575U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 48U));
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 28U) + aOrbiterH) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Lacrosse_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5055U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 5266U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4481U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 35U)) + 14686411261024919129U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 7514582233957632005U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 14U)) + RotL64(aCarry, 5U)) + 6520710480103365552U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 1983621978676188036U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 3U)) + 9003524602590749672U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6428568234045228995U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8656552687136446989U;
            aOrbiterE = RotL64((aOrbiterE * 16297456077021607301U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16916248288415922490U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9740237548002535784U;
            aOrbiterF = RotL64((aOrbiterF * 7970729853948983849U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 907561000814618339U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4751108900841197631U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4545395964730641957U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 167774899400732287U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11907484918310854962U;
            aOrbiterB = RotL64((aOrbiterB * 7213139491146402985U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14910318613649863924U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14882888155751455276U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11394136445442060201U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterF, 13U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 30U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8881U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16060U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14820U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8488U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 43U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 11U)) + 12426357877879529292U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 47U)) + 12604900366173639176U;
            aOrbiterG = (aWandererK + RotL64(aCross, 39U)) + 13511119007338929401U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 9878720081166788060U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 15463195409806395076U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6407922778852833423U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7690427254160734016U;
            aOrbiterG = RotL64((aOrbiterG * 11841396512731990295U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 18030974031722143619U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17983938038322737041U;
            aOrbiterF = RotL64((aOrbiterF * 12479365337221685413U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16605512170117753884U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 681802273302348322U;
            aOrbiterI = RotL64((aOrbiterI * 14608920184802647123U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15550312921312083819U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17824154101711884508U;
            aOrbiterA = RotL64((aOrbiterA * 7358612830654795357U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1939207786756735430U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3132864634777826569U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13606281919426730325U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterG, 14U));
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18987U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24456U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19305U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19027U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 3621877681473089725U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 38U)) + RotL64(aCarry, 11U)) + 4451752751536414717U) + aPhaseFOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 29U)) + 11371625415377772117U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 13U)) + 6046792758881150619U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 8213166120394461682U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4343156661140422645U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11105271483234947905U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 853531080115819287U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 348904609985341372U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12924652822526858767U;
            aOrbiterI = RotL64((aOrbiterI * 2801892489296408735U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7461211697358520287U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16551553555297890558U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16432952324635746293U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11908056404140782995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9147367258259948715U;
            aOrbiterG = RotL64((aOrbiterG * 10777628928376261667U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8876461054692728610U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10546855952702525404U;
            aOrbiterC = RotL64((aOrbiterC * 10071104785895309677U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 28U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 26U) + RotL64(aOrbiterG, 43U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30647U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32204U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31062U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 24830U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 10U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 58U)) + 18191288703716505885U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 9824014524910417136U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 11U)) + 11953012029254917548U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 6297568011027199089U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 2576999400457367975U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13176139160575558254U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9978408174563621810U;
            aOrbiterI = RotL64((aOrbiterI * 1399052522159751531U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16765834875061607142U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16534507305459121344U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8943988574248229067U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3114710944346151807U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10240517868726718592U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4645691562915606463U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10721450637990777883U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16689590768796583952U;
            aOrbiterJ = RotL64((aOrbiterJ * 3046344179729901637U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2427422768928450209U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13495584061816457831U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6670984773768885119U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 30U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 42U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 22U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Lacrosse_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 1265U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8027U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7506U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 739U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 57U)) + (RotL64(aIngress, 21U) + RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 11410829607777684449U;
            aOrbiterG = (aWandererA + RotL64(aCross, 41U)) + 7502698839700975347U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 13267685058252106173U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 238242706996630625U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aCross, 56U)) + 8184695499511454281U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12767823220461985403U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12293198423143850330U;
            aOrbiterK = RotL64((aOrbiterK * 5073886956792823825U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11149495229952495939U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7556992689338382800U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18232398462716803063U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3431338808774134649U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16863099140844995099U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 752376661101787919U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 17872458049880677604U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16760153457252546974U;
            aOrbiterG = RotL64((aOrbiterG * 11225037229069712805U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3115544493537438408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4359882942759752958U;
            aOrbiterC = RotL64((aOrbiterC * 561477566995575801U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 56U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterD, 19U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12813U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9239U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14156U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((aIndex + 15935U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 38U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 9751314027302668907U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 29U)) + 12175450995523107056U;
            aOrbiterE = (aWandererC + RotL64(aCross, 50U)) + 17519694958730119552U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 9093525527925682263U) + aPhaseGOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 3713831321786810138U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10108355209191835040U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12956307447311314768U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9198936928658626667U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1904298513945877359U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4658049993308574460U;
            aOrbiterJ = RotL64((aOrbiterJ * 10482422152074338611U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9826333658248851902U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12058666914724365134U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 964233873188373939U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2516574707110528099U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13335308331049750235U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5880227828760598587U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8230749255538495304U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16536559486797811486U;
            aOrbiterC = RotL64((aOrbiterC * 7097036838156464969U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 10U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterI, 12U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22074U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20630U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19745U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 20923U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 6U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aCross, 4U)) + 12980104182836602177U) + aPhaseGOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 3172622203188863995U) + aPhaseGOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 21U)) + 1170974132219980203U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 6035201940965047490U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 18033907118424996722U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14604813424800580304U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13720232492851066035U;
            aOrbiterD = RotL64((aOrbiterD * 8927246214721284759U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3902659710585257448U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8331560652661619868U;
            aOrbiterK = RotL64((aOrbiterK * 11418103770615560205U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4485014147538689794U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 168202636924512424U;
            aOrbiterA = RotL64((aOrbiterA * 13711020666131492091U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16227825670092707848U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4792781933944671365U;
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12636865372722601282U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 18198291399585556632U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18155803890313399795U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 10U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 28U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + aPhaseGWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27681U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 25580U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30108U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25479U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 60U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 54U)) + RotL64(aCarry, 51U)) + 2571116506511057880U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 13112435411509707292U) + aPhaseGOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 11U)) + 10403251762787357256U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 8461951095541400405U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 19U)) + 9890793478557463815U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3030229465991783707U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7273848154043719247U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17562254601517935669U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10681774862516028276U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7105082755586853104U;
            aOrbiterG = RotL64((aOrbiterG * 12217705329504230357U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6588579345319551129U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14616333550242386092U;
            aOrbiterB = RotL64((aOrbiterB * 2934574715879306337U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15439666290229654921U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3360304356760164799U;
            aOrbiterI = RotL64((aOrbiterI * 5164191920584106237U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14438730801970761889U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14515616787452085729U;
            aOrbiterC = RotL64((aOrbiterC * 2041601927968559821U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + aPhaseGWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterG, 53U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 30U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE + (((RotL64(aCross, 48U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Lacrosse_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 2637U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2528U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2030U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7255U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 14U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 43U)) + 1866656689936219099U) + aPhaseHOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 2312314528139448289U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 3554037526469185237U) + aPhaseHOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 14U)) + RotL64(aCarry, 23U)) + 405707755060974111U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 35U)) + 1862976326004007697U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12992483065443288263U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3793854946371595197U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1819119223110966487U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4244007978867369382U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10280867500312580308U;
            aOrbiterE = RotL64((aOrbiterE * 13729899124177931289U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 472563452959164242U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12041770406895816553U;
            aOrbiterH = RotL64((aOrbiterH * 17811798500132002631U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6118634015704900486U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13637107920449233307U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17712028184714868053U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16673735670669318830U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8602681273646630496U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6995213887710749241U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterE, 56U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterD, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13960U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 14963U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16151U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13303U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 6U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aPrevious, 57U)) + 7722279280863371124U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 11584220561732385598U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 7834679350105534657U) + aPhaseHOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 11347994382444180879U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 28U)) + 9449903188047063431U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6516243976652795170U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8420815253991184777U;
            aOrbiterG = RotL64((aOrbiterG * 1358649408967265415U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9081386852515170937U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14375955191735286867U;
            aOrbiterC = RotL64((aOrbiterC * 2772840314542262283U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 880757589768436072U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3349856625725164229U;
            aOrbiterD = RotL64((aOrbiterD * 681514212582331781U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7826309957607577207U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8057435761214313635U;
            aOrbiterB = RotL64((aOrbiterB * 4718430712767038607U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9565237500443303103U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15893066735310588501U;
            aOrbiterI = RotL64((aOrbiterI * 8457633439171452397U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 20U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 18U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterC, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 19212U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 17465U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18195U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20902U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 51U)) + 7632760812370906911U) + aPhaseHOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 6007174525479723089U) + aPhaseHOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 3362829642521821048U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 21U)) + 18009548556107978286U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 47U)) + 17880909432272697327U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15961567935420752568U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10136559064656837921U;
            aOrbiterF = RotL64((aOrbiterF * 14473810261421912849U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17622019364405410277U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6927494824421416306U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2686290883767829973U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7125170407794874847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12342273503071032250U;
            aOrbiterC = RotL64((aOrbiterC * 867417849555857179U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14997696377476124836U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14874498694181230698U;
            aOrbiterK = RotL64((aOrbiterK * 4026127545746010937U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2549397729130885686U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4217995818662767955U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5525525344485251063U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 38U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterK, 13U)) + aPhaseHWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 30052U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 25338U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28676U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25092U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 47U)) + (RotL64(aIngress, 60U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 7651355040951791298U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 13988210277931659312U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 14U)) + 9846849412579537783U) + aPhaseHOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 12746719939495876158U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 5U)) + 11498066185182895284U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11101058955193080232U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15513734459555672046U;
            aOrbiterJ = RotL64((aOrbiterJ * 6974281215677538561U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15711108675349394643U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4771231759949468556U;
            aOrbiterA = RotL64((aOrbiterA * 9806191054594333615U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11449258010811305256U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17036938391509986723U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7411466953205347639U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6999245666776654250U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2106819066263369528U;
            aOrbiterH = RotL64((aOrbiterH * 13005885810757743129U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12716183358903477216U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16752724547046059889U;
            aOrbiterK = RotL64((aOrbiterK * 11475905692393034141U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterH, 46U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererC = aWandererC + ((((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
