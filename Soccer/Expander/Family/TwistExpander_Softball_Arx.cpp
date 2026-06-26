#include "TwistExpander_Softball_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Softball_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x91091905AACA1343ULL + 0x9DB6E7062C8CA962ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8E7F29DA921CFC77ULL + 0xB493E4B8234F40E7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAC63A5FB38E08E53ULL + 0x8A8A53BB0B8F2902ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x908973991DAA2535ULL + 0x9D45BD4F349CB2FEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA20E9092183F29DBULL + 0x9CD3EE6DACB34846ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF95E3BD0D5E1CDEFULL + 0x9E414F0226A53FF6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9433B19AE46E7D91ULL + 0x8809E6CDA6C35CBAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC00780AE4B81B619ULL + 0x9D6CA7C4B07EE0E3ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordG, 12U)) ^ RotL64(aNonceWordE, 43U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 448U)) & S_BLOCK1], 53U) ^ RotL64(mSnow[((aIndex + 1115U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 4622U)) & S_BLOCK1], 38U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 2560U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aIngress, 24U)) + 4970414922752555648U;
            aOrbiterI = (aWandererB + RotL64(aCross, 43U)) + 9462756592787669327U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 39U)) + 3948790686662213095U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 14542857212241578311U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 21U)) + 3387479009827029547U) + RotL64(aNonceWordE, 21U);
            aOrbiterD = (aWandererG + RotL64(aPrevious, 13U)) + 1411421370057797877U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 47U)) + 16894451466895681236U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 12727136462290223542U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 58U)) + RotL64(aCarry, 37U)) + 4625389198191960525U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 35U)) + 3471881403786164913U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 53U)) + 6433115856048534831U) + RotL64(aNonceWordD, 45U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9825592965466157982U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1553125767261293088U;
            aOrbiterG = RotL64((aOrbiterG * 411535191177308781U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9951616357109647617U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11231080382787286889U;
            aOrbiterD = RotL64((aOrbiterD * 14024961994986659187U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13419663264017317947U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4835055642466215566U;
            aOrbiterB = RotL64((aOrbiterB * 17898065852351759171U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14558747666410946768U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13120938960926874504U;
            aOrbiterK = RotL64((aOrbiterK * 5681766019285559739U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11910501376797343986U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15074100100781785300U) ^ RotL64(aNonceWordC, 60U);
            aOrbiterA = RotL64((aOrbiterA * 228976960937473851U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12415377930578091821U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14882039078390681802U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13855446647753150713U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8094338361713756895U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5478280604704108822U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18062931724700600993U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6977017654546871841U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4131602217285988962U;
            aOrbiterI = RotL64((aOrbiterI * 11865422227883712419U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9619228479582032318U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13506679497441415586U;
            aOrbiterH = RotL64((aOrbiterH * 5789932662418992799U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10180259475831448124U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4721628773773094283U) ^ RotL64(aNonceWordF, 59U);
            aOrbiterC = RotL64((aOrbiterC * 10834196399754443771U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7898137727558813688U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4970414922752555648U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6651835668618579479U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterC, 10U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + RotL64(aNonceWordH, 55U));
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 23U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + RotL64(aNonceWordB, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterA, 21U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 39U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterD, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 51U) ^ RotL64(aNonceWordB, 3U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5756U)) & S_BLOCK1], 23U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 6426U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordG, 58U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7322U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 9909U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 41U)) + 6069475454765660321U) + RotL64(aNonceWordD, 19U);
            aOrbiterE = (aWandererH + RotL64(aScatter, 3U)) + 11483704742497268068U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 11055697447388986418U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 37U)) + 10897095046039997004U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 54U)) + 4731637118230457840U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 13855839187084986751U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 11U)) + 5328208115460188239U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 43U)) + 12479538544291412985U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 56U)) + 10740165998792608231U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 47U)) + 6492798157284955373U) + RotL64(aNonceWordA, 25U);
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 13056825957483891921U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2068184064919194657U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5656302738780746294U) ^ RotL64(aNonceWordC, 61U);
            aOrbiterB = RotL64((aOrbiterB * 16493021179127646345U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11193756120230763294U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 17306750816837208999U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7949360041241439741U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12952818800389361804U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15380412293642628312U;
            aOrbiterH = RotL64((aOrbiterH * 2914662289178925547U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7706090204767242996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14598802276412649570U;
            aOrbiterA = RotL64((aOrbiterA * 4821408736292041399U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17819762117328075515U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6481384240915075101U;
            aOrbiterF = RotL64((aOrbiterF * 4836701121865783029U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 754936290510338717U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15510875946573720154U;
            aOrbiterC = RotL64((aOrbiterC * 2994718968852184303U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9245381722813944586U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2629847912019726214U;
            aOrbiterD = RotL64((aOrbiterD * 6718795794951106961U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3909987749797113773U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9277056074757335265U;
            aOrbiterJ = RotL64((aOrbiterJ * 11580847505996697115U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12577180954515966707U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9144513680789115458U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8880777678193004979U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1544232962956974411U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 2658275904714859636U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ RotL64(aNonceWordB, 39U);
            aOrbiterK = RotL64((aOrbiterK * 1926083316365175327U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5733515391293514025U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6069475454765660321U;
            aOrbiterG = RotL64((aOrbiterG * 9627476106108146391U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 6U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + RotL64(aNonceWordE, 8U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 38U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 23U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 41U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 10U));
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + RotL64(aNonceWordF, 7U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 20U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordB, 23U)) ^ RotL64(aNonceWordG, 47U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 15223U)) & S_BLOCK1], 57U) ^ RotL64(mSnow[((aIndex + 14335U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 39U) ^ RotL64(aNonceWordC, 56U)) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10935U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 12858U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 35U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 5U)) + 77518479758428414U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 13U)) + 4832061802166300011U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 35U)) + 11695291171006574112U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 23U)) + 7467412817843260094U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 51U)) + 17801484124471154757U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordH, 47U);
            aOrbiterK = (aWandererI + RotL64(aCross, 21U)) + 5555455638503958639U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 26U)) + 5669470540733721606U) + RotL64(aNonceWordB, 7U);
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 3042388456327784163U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 2236734925228156691U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 47U)) + 14459720401528685450U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 18U)) + RotL64(aCarry, 21U)) + 4814967631216658856U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16950679344449075945U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6262238639302011050U;
            aOrbiterD = RotL64((aOrbiterD * 9942659897425088183U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3522256359074996724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12524717897707074242U;
            aOrbiterK = RotL64((aOrbiterK * 6787771338063891989U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13891759914865623828U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11910250571469028666U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12311343917878428995U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 2240189915640314069U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordF, 21U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5365912986308810837U;
            aOrbiterE = RotL64((aOrbiterE * 15133972552032469957U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9323732721344489753U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 13087326560957916553U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14659491687401151733U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16398238057564892809U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11517870519285159224U;
            aOrbiterB = RotL64((aOrbiterB * 1501848878469712681U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7758285512254776734U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17475149091906684720U) ^ RotL64(aNonceWordC, 41U);
            aOrbiterA = RotL64((aOrbiterA * 6015816725428299273U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2051631493975035243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11684740065349595315U;
            aOrbiterI = RotL64((aOrbiterI * 10918975496337269197U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10575473798991451167U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8267005776169272822U;
            aOrbiterF = RotL64((aOrbiterF * 13166868678285963961U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6249698995716039231U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13808085811784323978U;
            aOrbiterG = RotL64((aOrbiterG * 3897731011582061983U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2739364646624876985U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 77518479758428414U;
            aOrbiterJ = RotL64((aOrbiterJ * 6977724811175035551U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 40U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 43U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 22U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + RotL64(aNonceWordA, 6U));
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 26U)) + aOrbiterE) + RotL64(aNonceWordG, 29U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordC, 21U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 18218U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21180U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 60U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20780U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 21212U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererC + RotL64(aScatter, 51U)) + 9855743441035905047U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 8426286937143990276U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 11U)) + 7146752367170267002U) + RotL64(aNonceWordG, 44U);
            aOrbiterK = (aWandererD + RotL64(aPrevious, 3U)) + 12947210066678101726U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 21U)) + 15902163559925328965U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 18U)) + RotL64(aCarry, 5U)) + 8506649889346449469U;
            aOrbiterC = ((((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 8226286036430263052U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordD, 61U);
            aOrbiterE = (aWandererH + RotL64(aScatter, 43U)) + 2703047093452420216U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 41U)) + 6769351326360139560U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 23U)) + 9857025533281333281U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 26U)) + 238297452132277585U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7203572312072908931U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12497027346166575632U;
            aOrbiterJ = RotL64((aOrbiterJ * 1703586436725662307U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 473851890609048879U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1664484956453886047U;
            aOrbiterA = RotL64((aOrbiterA * 8566500756326590209U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4635095143004754116U) + RotL64(aNonceWordA, 21U);
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17695676150967345793U;
            aOrbiterF = RotL64((aOrbiterF * 5780416541584439301U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15628965269863402796U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9190117464399730235U;
            aOrbiterC = RotL64((aOrbiterC * 5586437438425999715U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17835918238346011086U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4398005402429282682U;
            aOrbiterE = RotL64((aOrbiterE * 14828737209913317463U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10902589938246551273U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15124274429081385923U;
            aOrbiterB = RotL64((aOrbiterB * 13524180348258805367U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8747233520702236018U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5445611443463112371U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10294109295823410447U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16296005217836151910U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6468336224317602364U;
            aOrbiterD = RotL64((aOrbiterD * 7369779919748367133U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3827976387089403774U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7773383658122100111U;
            aOrbiterH = RotL64((aOrbiterH * 9784711300597525161U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 18273794621528918389U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8401424792700263455U;
            aOrbiterG = RotL64((aOrbiterG * 13003420427441089595U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11402828934846813949U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9855743441035905047U) ^ RotL64(aNonceWordE, 19U);
            aOrbiterK = RotL64((aOrbiterK * 7339549576423555273U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 36U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterB, 22U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 51U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aNonceWordF, 45U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordB, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 20U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 53U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordF, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 26565U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24643U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordA, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24972U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 24068U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 56U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 54U)) + 8367680518550579791U) + RotL64(aNonceWordF, 41U);
            aOrbiterH = (aWandererG + RotL64(aPrevious, 5U)) + 11491674725611181241U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 11U)) + 16673861720782164214U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 23U)) + 9786610124108350855U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 41U)) + 5745080601557577637U) + RotL64(aNonceWordG, 36U);
            aOrbiterK = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 1959402215131684684U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 37U)) + 6121650036079196522U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 27U)) + 12016309761037342392U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 14U)) + RotL64(aCarry, 23U)) + 5986936646177049603U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 1000367700904043468U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 19U)) + 17425288243569101032U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4856917474950325209U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16312111093223166419U;
            aOrbiterG = RotL64((aOrbiterG * 11046477664487805241U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 456110002032422270U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11393724374787795662U) ^ RotL64(aNonceWordD, 39U);
            aOrbiterK = RotL64((aOrbiterK * 1176984359123668389U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8378176867715697176U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8086186452345234815U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8450438271765985235U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8470349167474173245U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2528229938740192694U;
            aOrbiterC = RotL64((aOrbiterC * 8717790851266520943U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13247168811545753141U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8745293957516815264U;
            aOrbiterI = RotL64((aOrbiterI * 14270617180621072619U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6165915500564961987U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12015407798844173213U;
            aOrbiterD = RotL64((aOrbiterD * 3913451986559154153U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 545006684939922156U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16366753936267185001U;
            aOrbiterF = RotL64((aOrbiterF * 6495185976430013201U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3097605623436091728U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15950167830259022926U;
            aOrbiterE = RotL64((aOrbiterE * 4415538963984293323U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8356327899232213426U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10183421678251169945U;
            aOrbiterB = RotL64((aOrbiterB * 9474380650337109299U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16327340177970834683U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7086901180933495535U;
            aOrbiterH = RotL64((aOrbiterH * 1276521829484494857U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13421211370092080006U) + RotL64(aNonceWordH, 45U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8367680518550579791U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12256662446176946163U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 36U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + RotL64(aNonceWordB, 5U)) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 21U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterA, 56U));
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 54U)) + RotL64(aNonceWordE, 19U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aCross, 48U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordC, 39U)) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 31431U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 29799U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordE, 29U)) ^ RotL64(aNonceWordH, 40U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30451U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32586U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 11U)) + 14686411261024919129U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 35U)) + 7514582233957632005U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 6U)) + RotL64(aCarry, 29U)) + 6520710480103365552U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 39U)) + 1983621978676188036U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordG, 40U);
            aOrbiterF = (aWandererG + RotL64(aPrevious, 43U)) + 9003524602590749672U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 6428568234045228995U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 8656552687136446989U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 3U)) + 16916248288415922490U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 24U)) + 9740237548002535784U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 19U)) + 907561000814618339U) + RotL64(aNonceWordD, 53U);
            aOrbiterI = (aWandererD + RotL64(aIngress, 51U)) + 4751108900841197631U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 167774899400732287U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11907484918310854962U;
            aOrbiterK = RotL64((aOrbiterK * 7213139491146402985U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14910318613649863924U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14882888155751455276U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11394136445442060201U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16175942562693781908U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11022373758481651102U;
            aOrbiterH = RotL64((aOrbiterH * 6836331461393816027U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12548405399045031548U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10850926364556828443U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16231561687709867431U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13391684887911141790U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14648937281264822988U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6533299316940026059U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8298658887198526821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13822977698661348891U;
            aOrbiterC = RotL64((aOrbiterC * 17769262972278410937U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7505646847564645719U) + RotL64(aNonceWordF, 29U);
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3238749538197209166U;
            aOrbiterG = RotL64((aOrbiterG * 15394286542600778567U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15853506915123709257U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8426329899401071248U;
            aOrbiterI = RotL64((aOrbiterI * 1330397096577715113U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14848635392815613098U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3549927798350175044U;
            aOrbiterE = RotL64((aOrbiterE * 1899044682313056949U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1798973117197750802U) + RotL64(aNonceWordC, 13U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13056711228618953977U;
            aOrbiterD = RotL64((aOrbiterD * 9102877396419306689U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1395893547965799281U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14686411261024919129U;
            aOrbiterJ = RotL64((aOrbiterJ * 17075377081365066067U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterB, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterE, 30U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterA, 26U)) + RotL64(aNonceWordH, 11U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + RotL64(aNonceWordB, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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

void TwistExpander_Softball_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA4EFDDA0EE1D6371ULL + 0x88BD8CF8A51463E3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB1D5517663DE0C19ULL + 0x81FAD736A5BC4E0BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9DED3454FBE6B509ULL + 0xD6DE917140DDE0A4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEFF59279BDD9B223ULL + 0x99E26E6B46CEA5BEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC439138A39DBCEB5ULL + 0xDC69FFCCC991A27BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCA44A29A9AC9D963ULL + 0xEEFCA854697DDB32ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCFDA7034A0B3A839ULL + 0xA3795D0812EB6073ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9535A126B0E12103ULL + 0xACE88B3326E96A3EULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordH, 43U)) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 460U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 112U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2759U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2714U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 5088525177670191619U) + RotL64(aNonceWordG, 8U);
            aOrbiterF = (aWandererE + RotL64(aCross, 6U)) + 9966456257813932112U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 35U)) + 7707646574027146307U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 11U)) + 75480203757681173U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 53U)) + 384659134071835163U;
            aOrbiterD = ((((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 3158769775373307778U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordE, 21U);
            aOrbiterA = ((aWandererA + RotL64(aScatter, 46U)) + RotL64(aCarry, 29U)) + 17360830943513941272U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 19U)) + 5317278822721604586U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 39U)) + 1371427105215954781U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3162710551223553423U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5332921933853550756U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11709546145149357887U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10572462410297815854U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10234389605554817892U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterD = RotL64((aOrbiterD * 2130374833440291193U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13421365517991380605U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10186643614984034083U;
            aOrbiterJ = RotL64((aOrbiterJ * 8554471709467808453U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4742438973260817120U) + RotL64(aNonceWordA, 45U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6081590345899008846U;
            aOrbiterI = RotL64((aOrbiterI * 7069396301823124931U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15360092808493795340U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12186413069553132646U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3815981440611914267U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16756221656224451552U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12232880965861373143U;
            aOrbiterG = RotL64((aOrbiterG * 14196910735715726471U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10090954323470840557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15615770271463853537U;
            aOrbiterA = RotL64((aOrbiterA * 13544181592829027283U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 556029032505658411U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13311879111583579039U;
            aOrbiterF = RotL64((aOrbiterF * 3924744868168749003U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8646360871497847336U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2064833941982069154U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10016546852137913163U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 10U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + RotL64(aNonceWordF, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 60U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 21U));
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordB, 57U));
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterA, 48U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11013U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13873U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 50U) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14208U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16124U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 10U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 41U)) + 13053031069776604052U) + RotL64(aNonceWordB, 23U);
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 23U)) + 1331396630251085122U) + RotL64(aNonceWordE, 57U);
            aOrbiterE = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 15879286043343942393U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 21U)) + 13590365633321406830U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 5U)) + 14569235423040242618U;
            aOrbiterF = (aWandererG + RotL64(aCross, 57U)) + 11397370636618371560U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 3455933494593971847U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 19U)) + 1307153376443784593U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 46U)) + 10688618762584786871U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17746248451153600096U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8512568600755410158U;
            aOrbiterE = RotL64((aOrbiterE * 16648320170768234063U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8950230550112591092U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17790968369472845496U;
            aOrbiterG = RotL64((aOrbiterG * 5104988920132008913U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12583323865381967534U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11243927099685293887U;
            aOrbiterB = RotL64((aOrbiterB * 12867003042486433971U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9690268715525781389U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 7466066217365074653U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordF, 51U);
            aOrbiterD = RotL64((aOrbiterD * 17565696765505320889U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 3673528673209875118U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordD, 9U);
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14079103852360952255U;
            aOrbiterH = RotL64((aOrbiterH * 17449228863409999629U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6747836856132250630U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5027692924422297153U;
            aOrbiterJ = RotL64((aOrbiterJ * 2492421273167124437U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11370341866003395776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14013204893442579282U;
            aOrbiterI = RotL64((aOrbiterI * 6602239957997240785U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3436953430697936790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6399073534839993637U;
            aOrbiterF = RotL64((aOrbiterF * 14186050072610021241U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7054057507823631422U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5752085719673338095U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13252660162476029593U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterF, 20U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordH, 25U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 12U) + aOrbiterF) + RotL64(aOrbiterE, 51U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + RotL64(aNonceWordA, 52U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 6U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 6U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 44U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordF, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19449U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 22665U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordC, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21857U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((aIndex + 23348U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 19U)) ^ (RotL64(aCarry, 4U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aIngress, 30U)) + 9888431329297626900U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 41U)) + 2937735167534624403U;
            aOrbiterI = (aWandererF + RotL64(aCross, 47U)) + 17626022970343789617U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 3U)) + 5665660859333693743U) + RotL64(aNonceWordE, 27U);
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 23U)) + 1060537034632076669U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aCross, 36U)) + RotL64(aCarry, 5U)) + 743777763907175800U) + RotL64(aNonceWordH, 40U);
            aOrbiterD = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 5744905970181808845U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 3545351394494002180U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 53U)) + 4877547088414106007U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11669378338379598445U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2961072441706158212U) ^ RotL64(aNonceWordG, 59U);
            aOrbiterI = RotL64((aOrbiterI * 2677988507090705371U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13984945589234919765U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1433097875470903205U;
            aOrbiterK = RotL64((aOrbiterK * 451996840039906781U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 716415411025451152U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8542286150858297810U;
            aOrbiterJ = RotL64((aOrbiterJ * 9139015340823332449U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12932391786479661299U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14005503313299177013U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 802663466907819743U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9382792812676318046U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5138554251079724724U;
            aOrbiterF = RotL64((aOrbiterF * 6386016499265056247U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8522380066269546172U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11825536408101906458U;
            aOrbiterC = RotL64((aOrbiterC * 17042837108792016849U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15504062350899452495U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1219010998820336744U;
            aOrbiterD = RotL64((aOrbiterD * 10650635772711590803U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6442717843380349632U) + RotL64(aNonceWordD, 35U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1047843426279085117U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4074561571072878005U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10611039527108679173U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5092816736177358221U;
            aOrbiterE = RotL64((aOrbiterE * 14342779343820140833U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 26U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 42U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 15U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 30U)) + aOrbiterB) + RotL64(aNonceWordA, 47U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 30U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordE, 10U)) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26021U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 31696U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28409U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 27215U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 6U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 3561491146322798260U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 23U)) + 7075025056181885339U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 51U)) + 9230910887904171613U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 4119781172609908917U) + RotL64(aNonceWordG, 57U);
            aOrbiterE = (aWandererA + RotL64(aCross, 12U)) + 17155609083870983149U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 43U)) + 2423018561430181695U) + RotL64(aNonceWordB, 26U);
            aOrbiterD = ((aWandererC + RotL64(aScatter, 19U)) + 12957280305617615744U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 2461704174772065813U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 34U)) + 7907123257849391997U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7257868138318960007U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16425903703085702285U;
            aOrbiterC = RotL64((aOrbiterC * 7996935869077231999U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2990822664594079467U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5654819006718953817U;
            aOrbiterE = RotL64((aOrbiterE * 4465096036756887801U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12183676471235678779U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 15026286960542123922U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17199049329995315279U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12169080607071830522U) + RotL64(aNonceWordA, 21U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2906296852254787499U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6754514406846040163U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3029858695410344584U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14406410317495954566U;
            aOrbiterI = RotL64((aOrbiterI * 9663780721657983421U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11048818178401163861U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13622063920319445043U;
            aOrbiterF = RotL64((aOrbiterF * 2516025554421589857U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2642646089141233277U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12761571777929273548U;
            aOrbiterK = RotL64((aOrbiterK * 5518252696078700127U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7753802695131502382U) + RotL64(aNonceWordC, 51U);
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8510425459525030222U;
            aOrbiterB = RotL64((aOrbiterB * 12412361423636026483U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13522645164493316722U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1437430302489702713U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14019316635365783545U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterE, 58U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 22U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + RotL64(aCarry, 47U)) + RotL64(aNonceWordE, 37U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + RotL64(aNonceWordD, 13U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
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

void TwistExpander_Softball_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAC8870780BF951DDULL + 0xB0883C8D38F51E97ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9E1AF4D4E3DA41E5ULL + 0xC2F69207B599A83EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x81DD2AE6BF6F49A5ULL + 0xFB338B8732C05F64ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x807B23AA060C4879ULL + 0xBC4C303CBB76F8E0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEFD505CA7F37F513ULL + 0xCB84774D47009AF7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAEB0E6A9ACEED143ULL + 0xA894DA736EAB4B8FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE3C28FAC5376DC13ULL + 0xDBE6DDB0528A1939ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD1903F9BCB91307DULL + 0xD79309C2ED5ABE11ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 44U) ^ RotL64(aNonceWordA, 23U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 635U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 955U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordG, 46U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4492U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3614U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 27U)) + 4179952823252098240U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 3745613452332101749U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aCross, 52U)) + RotL64(aCarry, 53U)) + 2955689793395307176U) + RotL64(aNonceWordB, 57U);
            aOrbiterD = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 5639060180251322019U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 41U)) + 7901969163853586463U) + RotL64(aNonceWordD, 40U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 2242166787816318119U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5239936443960750064U;
            aOrbiterJ = RotL64((aOrbiterJ * 2752853245379816327U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13939136954732185558U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17058884136712717463U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7222348891215482977U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18148618660054585941U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7022023484530327814U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 650100011311048589U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7722084537340095637U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11764151879690934182U) ^ RotL64(aNonceWordH, 3U);
            aOrbiterE = RotL64((aOrbiterE * 12264384877711365655U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16412785901758144708U) + RotL64(aNonceWordE, 39U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9666718667728274824U;
            aOrbiterI = RotL64((aOrbiterI * 10865799822751771795U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + RotL64(aNonceWordF, 25U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 24U)) + aOrbiterJ);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 39U)) + aOrbiterA) + RotL64(aCarry, 35U)) + RotL64(aNonceWordA, 17U)) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordC, 23U)) ^ RotL64(aNonceWordB, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15715U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((aIndex + 8912U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordH, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10565U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 8415U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 43U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 30U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 53U)) + 4634399531433127141U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 16961792729406903200U) + RotL64(aNonceWordF, 59U);
            aOrbiterB = ((((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 4105280732301137738U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordA, 43U);
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 15692013501147331191U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 4U)) + 1252216715968780587U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7958289043012473752U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6611577301818896615U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2757493607265637973U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8506226754305949140U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3648813120449403353U;
            aOrbiterI = RotL64((aOrbiterI * 9521367946879238849U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5195245426245535735U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 542948051600803051U;
            aOrbiterJ = RotL64((aOrbiterJ * 4631106308856448475U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11974253551208964789U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10596463592332655367U) ^ RotL64(aNonceWordG, 29U);
            aOrbiterG = RotL64((aOrbiterG * 10941161258815714641U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12015129484061440159U) + RotL64(aNonceWordE, 9U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8254944355710109060U;
            aOrbiterF = RotL64((aOrbiterF * 3233697992479357615U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 4U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + RotL64(aNonceWordC, 14U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 54U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + RotL64(aNonceWordD, 47U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordA, 35U)) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22976U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20098U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19786U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23225U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 28U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 9107326720193244489U) + RotL64(aNonceWordH, 51U);
            aOrbiterJ = (aWandererA + RotL64(aScatter, 57U)) + 10868585484401664145U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 13637736741437846622U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 24U)) + 6130725216183918844U) + RotL64(aNonceWordD, 37U);
            aOrbiterE = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 2063834478521338187U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8564870627911949158U) + RotL64(aNonceWordB, 49U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6524015751064086390U;
            aOrbiterD = RotL64((aOrbiterD * 12055267995727104463U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9874937766875388236U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14723718409522680894U;
            aOrbiterJ = RotL64((aOrbiterJ * 17379140128833323431U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13767059954741528279U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6387608251033722169U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6601902195707980693U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5391425980008431000U) + RotL64(aNonceWordF, 38U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11524218415655093779U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12508457981779189389U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 155510463350385905U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10554591788433641311U;
            aOrbiterE = RotL64((aOrbiterE * 5412084824127934293U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterC, 29U)) + aOrbiterE);
            aWandererD = aWandererD + (((((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + RotL64(aCarry, 43U)) + RotL64(aNonceWordE, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 58U)) + RotL64(aNonceWordC, 31U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27963U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((aIndex + 28214U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24581U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 28050U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 52U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 13U)) + 12669015908335980355U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 5438715179868613192U;
            aOrbiterC = ((((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 13172104448184536460U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordF, 35U);
            aOrbiterB = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 13421421503244744803U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 4U)) + 13327113302994856582U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordB, 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4671768205922454413U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5355759962838579929U;
            aOrbiterC = RotL64((aOrbiterC * 15080379163499722187U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6691720614265406851U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7063906424700911378U;
            aOrbiterJ = RotL64((aOrbiterJ * 17091734375516280675U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17328616394166672263U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1542940602574207068U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8981679306319627975U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7203866278803132454U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 993485696233139264U;
            aOrbiterD = RotL64((aOrbiterD * 11609009908810366447U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 15659679028507488331U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordC, 10U);
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 18321361454094675842U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) ^ RotL64(aNonceWordD, 41U);
            aOrbiterH = RotL64((aOrbiterH * 3966860765622641843U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 44U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterC, 48U));
            aWandererC = aWandererC + (((((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordH, 5U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + RotL64(aNonceWordG, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Softball_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB2F8C5B65E62445DULL + 0x876F8D1757580D3BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9E34299E31640CB3ULL + 0x96BA701B5D4E16FAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBCED0682407CCF81ULL + 0x8A1CCEBE140E9B6CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF7E250FBD310891BULL + 0xAA474FD5C6DD12CBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE636A21B52EBEA27ULL + 0xDB5143A26AD6E869ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB745E470DCFC7337ULL + 0xEA27F26785D0240EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC7CF8A2959EE845FULL + 0xCD7A50664F6D66C7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xACDD2AA965C9CA69ULL + 0x9D22E5316ADB7A62ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2624U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 7362U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordD, 42U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7731U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5594U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 6342299552323486695U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 28U);
            aOrbiterE = (aWandererI + RotL64(aIngress, 43U)) + 12692748514781367538U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 37U)) + 8202639945493229155U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 27U)) + 4439975701793231639U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 16774235182859553759U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 8764155413335405667U) + RotL64(aNonceWordE, 55U);
            aOrbiterF = (aWandererB + RotL64(aIngress, 60U)) + 7167848811974967685U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16768278912125334220U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9090838954826296201U;
            aOrbiterD = RotL64((aOrbiterD * 5459329624017272077U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7644075729758006298U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17326182797908071215U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2408330168749256075U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16158809721888137555U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8029938783858263694U;
            aOrbiterC = RotL64((aOrbiterC * 12628072435324195483U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8716553521415553404U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7012599977009208840U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8775355876188948851U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13250558696578541499U) + RotL64(aNonceWordF, 35U);
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13705957059101025396U;
            aOrbiterB = RotL64((aOrbiterB * 16889495686487056367U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2796775206291902461U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13741676263512390669U) ^ RotL64(aNonceWordC, 41U);
            aOrbiterG = RotL64((aOrbiterG * 10455782033465595947U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1691908360612389252U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4114939415206031540U;
            aOrbiterE = RotL64((aOrbiterE * 2797401802892718297U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + RotL64(aNonceWordG, 9U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterC, 58U)) + RotL64(aNonceWordH, 15U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 41U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordD, 38U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13175U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12034U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordC, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8620U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 9625U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 54U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 21U)) + 17264605017518259932U) + RotL64(aNonceWordC, 57U);
            aOrbiterD = ((aWandererE + RotL64(aIngress, 27U)) + 15209184354580778643U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 46U)) + 3299527965014731384U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 16293096431816127821U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 11031983436878828337U) + RotL64(aNonceWordE, 19U);
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 9188018632448236358U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 57U)) + 13420816400363406556U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2485063384097917101U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3089135816938128264U) ^ RotL64(aNonceWordA, 16U);
            aOrbiterI = RotL64((aOrbiterI * 8813152992957361153U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10730544971770435788U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10431767565618874806U;
            aOrbiterK = RotL64((aOrbiterK * 4723078464590561545U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14883796491656899074U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13465877783538483706U;
            aOrbiterH = RotL64((aOrbiterH * 14311686051108108503U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 13322163435314643713U) + RotL64(aNonceWordH, 27U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12337846092069506365U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4950101626975919939U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2596253994220103666U;
            aOrbiterG = RotL64((aOrbiterG * 7181706961838582889U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17961706029559914243U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10321902557977495175U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16189559888625084711U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18146616411403012772U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8414050129421955787U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14879448948196182863U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterC, 41U));
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aNonceWordB, 55U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 60U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + RotL64(aNonceWordF, 23U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 14U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 34U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20692U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19447U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordB, 30U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20849U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 20671U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 51U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 48U)) + 18319689184146942855U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 41U)) + 8041304130090501019U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 11347064191990897738U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 15242243470024447468U) + RotL64(aNonceWordF, 60U);
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 10619749107163611105U) + RotL64(aNonceWordH, 3U);
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 13U)) + 14795614276221947128U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 19U)) + 1578095288886372393U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13593906305770501684U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8919815528334599172U;
            aOrbiterH = RotL64((aOrbiterH * 2033810402808238127U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17425548324720065145U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11125018338392347335U) ^ RotL64(aNonceWordA, 17U);
            aOrbiterG = RotL64((aOrbiterG * 4377887040461528587U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3779189180734244399U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10958224663276134041U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6206963519509783781U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4317305352561612995U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4891139433808505355U) ^ RotL64(aNonceWordC, 57U);
            aOrbiterB = RotL64((aOrbiterB * 11507024985663120317U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5166074784835930965U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10080890270621589202U;
            aOrbiterJ = RotL64((aOrbiterJ * 13170894418184288695U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4501071771615514619U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6486573807774431753U;
            aOrbiterI = RotL64((aOrbiterI * 324029625116648669U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15714881857668975753U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3506619392820235900U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5707033870161224499U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordB, 15U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 37U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + RotL64(aNonceWordE, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 60U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 41U) ^ RotL64(aNonceWordD, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30492U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 24628U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordG, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25210U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28921U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 22U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 37U)) + 6771552164800695068U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 12131763371571322040U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 3326182381395522013U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 12288775097697156383U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordF, 54U);
            aOrbiterG = (aWandererE + RotL64(aIngress, 56U)) + 5195948373449796741U;
            aOrbiterA = (aWandererC + RotL64(aCross, 47U)) + 14404044002250137144U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 13U)) + 11142382920035825426U) + RotL64(aNonceWordB, 49U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 2967149520256475485U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 45U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1470907369577818097U;
            aOrbiterF = RotL64((aOrbiterF * 9398653295177725883U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9231668148004163910U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13078929163913892386U;
            aOrbiterA = RotL64((aOrbiterA * 7509829068700523627U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9485274692075657877U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12216951187543631673U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6571066246507310805U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6933334652581744234U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17260276102423580920U) ^ RotL64(aNonceWordE, 21U);
            aOrbiterG = RotL64((aOrbiterG * 7796879893790990605U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 387767848169714392U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8597538259308082638U;
            aOrbiterC = RotL64((aOrbiterC * 4888054690557707241U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7996708724489146033U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15357384191688149939U;
            aOrbiterI = RotL64((aOrbiterI * 9827691726832491373U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17739222908739454637U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1614322333281471170U;
            aOrbiterE = RotL64((aOrbiterE * 7063116837752240891U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 60U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 43U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 53U)) + aOrbiterC);
            aWandererC = aWandererC + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aCarry, 53U)) + RotL64(aNonceWordH, 9U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 22U) + RotL64(aOrbiterG, 11U)) + aOrbiterK) + RotL64(aNonceWordA, 15U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Softball_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDF3DA7EB098A5799ULL + 0xF40B68A2C4471F35ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE2B5BB99EBEA9199ULL + 0xDA135750A9C3319FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC99557647272825FULL + 0xC89C676F2ADC2A8BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB65DE7E85F6BB42DULL + 0x8B4AB68433D5128FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA89D33A767254E79ULL + 0x993D3932D9502677ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x819F50142DEAF80DULL + 0xE8C5F54189C7685EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAA60C48699A68B03ULL + 0x8809C7D61BE49382ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9E0BEA5E29343D39ULL + 0xA8C5440E5F1D4941ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 50U) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 7247U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7338U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordE, 27U)) ^ RotL64(aNonceWordF, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7631U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1712U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 52U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aIngress, 12U)) + 3448371607470865612U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 3743742913651580573U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 57U)) + 13069491287948807280U;
            aOrbiterE = (aWandererA + RotL64(aCross, 37U)) + 16872779275586545632U;
            aOrbiterJ = ((((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 17945792656755062795U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordE, 21U);
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 43U)) + 18199747196793731853U;
            aOrbiterD = ((((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 15953311878379809513U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordA, 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 941268763494588338U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10090221530365796809U;
            aOrbiterB = RotL64((aOrbiterB * 14035236086292997613U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8335698093307607001U) + RotL64(aNonceWordG, 12U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6147498804734306100U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6904444049941211327U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5980246079567570090U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4152167624425912978U;
            aOrbiterH = RotL64((aOrbiterH * 10019421651535123573U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14990418790239735916U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3418668387496597219U;
            aOrbiterD = RotL64((aOrbiterD * 12814077238529863119U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4206650904177199425U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3905470780938996069U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16030122739273137005U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9968672788233080924U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 602258075661864866U) ^ RotL64(aNonceWordC, 5U);
            aOrbiterE = RotL64((aOrbiterE * 2615726693066300065U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17751667243048041383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2414054413585296027U;
            aOrbiterC = RotL64((aOrbiterC * 1049512574773201893U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 14U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 20U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + RotL64(aNonceWordH, 59U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + RotL64(aNonceWordB, 15U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordG, 29U)) ^ RotL64(aNonceWordD, 58U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14366U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 13395U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 41U) ^ RotL64(aNonceWordA, 20U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10079U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16348U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 5U)) + 18087125778766689269U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 13710545066503235196U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordE, 23U);
            aOrbiterG = (aWandererK + RotL64(aIngress, 37U)) + 1701939704736254645U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 8064093611384019909U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 22U)) + RotL64(aCarry, 23U)) + 16623332751533885431U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 43U)) + 15590129153794910109U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 57U)) + 7413312683079107383U) + RotL64(aNonceWordD, 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4186064478651458810U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5501191643940735954U;
            aOrbiterG = RotL64((aOrbiterG * 14254804649177125269U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11064645242200570835U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13825922087298055833U;
            aOrbiterC = RotL64((aOrbiterC * 7529317892716108867U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5944980709887369970U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8181136916070569646U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 395183021205661827U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15442336949157292482U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11580554435240641337U) ^ RotL64(aNonceWordB, 41U);
            aOrbiterI = RotL64((aOrbiterI * 6654637892858767739U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11240018128174598322U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 2027565596050777471U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) ^ RotL64(aNonceWordH, 6U);
            aOrbiterF = RotL64((aOrbiterF * 18048186560314431815U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16425887196883725233U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16828683527588834095U;
            aOrbiterH = RotL64((aOrbiterH * 17746289103235902485U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9923829146479008804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6669171007279929454U;
            aOrbiterA = RotL64((aOrbiterA * 681823450939955099U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 10U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererH = aWandererH + (((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordG, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 37U)) + aOrbiterD) + RotL64(aNonceWordF, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 4U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22934U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 17518U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordE, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20760U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 20725U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 44U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 29U)) + 7896237440058555694U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 3U)) + 11870529476037558635U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 9158983227801569448U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 51U)) + 4710172270996950329U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 39U)) + 14634482800356647630U) + RotL64(aNonceWordB, 57U);
            aOrbiterC = ((((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 8822207952170610891U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordD, 40U);
            aOrbiterE = ((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 27U)) + 13755891414028982553U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4555293067488040719U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2816805148093762081U;
            aOrbiterG = RotL64((aOrbiterG * 16838149138341713943U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2122631477965135190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4592922416380416071U;
            aOrbiterI = RotL64((aOrbiterI * 11644507904538573165U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7102471666524164715U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17274623547879474204U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5443572270546181789U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 938587316977094680U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 18258015823797023523U;
            aOrbiterJ = RotL64((aOrbiterJ * 6068819567674605919U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5809987756043471595U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 5083075160112581620U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3313957222154937503U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5960021727750946496U) + RotL64(aNonceWordH, 21U);
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5967477320950630150U;
            aOrbiterC = RotL64((aOrbiterC * 330964768256424655U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 6578428711689296132U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordA, 5U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5601728218197771276U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9552559022315971847U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 6U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterI, 5U));
            aWandererA = aWandererA + (((((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + RotL64(aCarry, 27U)) + RotL64(aNonceWordC, 35U)) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + RotL64(aNonceWordG, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterB, 60U)) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 52U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordA, 42U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26367U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 26412U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordG, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31240U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 26774U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 23U)) + 15910560457440369082U) + RotL64(aNonceWordB, 27U);
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 29U)) + 17953072986407436888U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 47U)) + 15446940721193538669U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 3020785262774422009U) + RotL64(aNonceWordE, 3U);
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 7001288645424994404U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 6U)) + RotL64(aCarry, 57U)) + 13385250665458462689U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 13U)) + 4841895644623005949U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13053476783239482065U) + RotL64(aNonceWordH, 45U);
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 641996979335975244U;
            aOrbiterH = RotL64((aOrbiterH * 3697673197256549833U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16211238020928688299U) + RotL64(aNonceWordC, 23U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12715448751323279480U;
            aOrbiterK = RotL64((aOrbiterK * 2116880429675303291U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17784406727699995290U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16626339815786580778U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13940754474750138041U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9035070625716345139U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6085848172494001945U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10405728912339646693U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1177103851507561053U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2281901691017816407U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3142197009403602497U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9040984343694325070U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13334258224023902365U;
            aOrbiterI = RotL64((aOrbiterI * 4782523727707164869U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1079824790138592518U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14024082692012948652U;
            aOrbiterA = RotL64((aOrbiterA * 3219489374333737903U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + RotL64(aNonceWordD, 36U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 3U)) + RotL64(aNonceWordA, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterA, 60U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 53U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Softball_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF773B27247DD0D29ULL + 0xCC6D37BF16BCFE8FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF26D51D20522E2CDULL + 0xFA8F95F74B570D1EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC9AD25BD331C3A8FULL + 0xD2ABFBCC1255B616ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC176B89097A9F837ULL + 0x96933408F22DF33AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE59C37511D6A354DULL + 0x8C6FAF6C90C1F016ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE1A23C9643965BFFULL + 0x81EFFE018AC09EAEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD0EBCD603E66078DULL + 0xD19AE64DEDA38552ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFFEC7620FCCA0023ULL + 0xC670A09E1CB3778EULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordE, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1417U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 506U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordH, 37U)) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3164U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7638U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 54U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 1042610313571524121U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 3505725321008825582U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 29U)) + 12584654563843782991U) + RotL64(aNonceWordA, 15U);
            aOrbiterG = (aWandererJ + RotL64(aCross, 14U)) + 6645399144515770935U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 35U)) + 3608978423753715584U;
            aOrbiterK = (aWandererI + RotL64(aCross, 53U)) + 8089198857670370983U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 23U)) + 15207251813516399879U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 51U)) + 9579268660105824516U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 37U)) + 16055044469473802812U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 48U)) + 583811872609805949U) + RotL64(aNonceWordD, 54U);
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 7027491967970873942U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 18256061823189677508U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordB, 61U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12708429127816136937U;
            aOrbiterJ = RotL64((aOrbiterJ * 12593886633108075321U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12169216645156306078U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12694325407567795065U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3711789483877261899U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16109994660203297503U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4234704064165718913U;
            aOrbiterF = RotL64((aOrbiterF * 730085881474787681U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14119541943554602878U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8777769004811352951U;
            aOrbiterG = RotL64((aOrbiterG * 2556957257736134223U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15642663488392549609U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11594468530833278624U;
            aOrbiterA = RotL64((aOrbiterA * 6639306656361601143U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7365350535791499871U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5965170981970155956U;
            aOrbiterD = RotL64((aOrbiterD * 1898702752753066851U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9115232101451815522U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9433983580038990072U;
            aOrbiterB = RotL64((aOrbiterB * 1951249217843992179U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8810565477444156140U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12081286530401844859U;
            aOrbiterE = RotL64((aOrbiterE * 1991383259486140229U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7498045374283306625U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 13095973566401200720U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) ^ RotL64(aNonceWordH, 47U);
            aOrbiterI = RotL64((aOrbiterI * 2657451581036351987U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18205793828042507364U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3339020890428651569U;
            aOrbiterH = RotL64((aOrbiterH * 10195916881103252701U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16957913958369950483U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1042610313571524121U;
            aOrbiterC = RotL64((aOrbiterC * 11206619213970727629U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 10U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI + ((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterB, 37U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + RotL64(aNonceWordF, 43U));
            aWandererG = aWandererG + ((RotL64(aIngress, 46U) + RotL64(aOrbiterK, 46U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + RotL64(aNonceWordG, 29U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10946U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 10975U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordB, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15811U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 15579U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 21U)) + 13499155707765393469U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 3740324981823726185U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 47U)) + 5470765363949735652U;
            aOrbiterG = (aWandererD + RotL64(aCross, 23U)) + 3446436171274452326U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 1778929412631211933U;
            aOrbiterD = (aWandererB + RotL64(aCross, 30U)) + 14666308799855220954U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 53U)) + 4548410236791175055U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 39U)) + 5829739767694190372U) + RotL64(aNonceWordE, 9U);
            aOrbiterA = ((aWandererE + RotL64(aCross, 5U)) + 14319231414903675748U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 58U)) + 1513851750246111405U) + RotL64(aNonceWordC, 43U);
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 1685620217748986019U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16284162182006054402U) + RotL64(aNonceWordD, 23U);
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6271539598462003309U;
            aOrbiterH = RotL64((aOrbiterH * 13923286694131331137U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12669312437565969473U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11894755313393001665U;
            aOrbiterJ = RotL64((aOrbiterJ * 12556759675372354075U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6315983824634946566U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17106616474222892782U;
            aOrbiterE = RotL64((aOrbiterE * 167205520766791073U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13350266700180455548U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4608846311203767162U;
            aOrbiterK = RotL64((aOrbiterK * 2504857468837437365U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14195866746143604365U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7917977448256795054U;
            aOrbiterA = RotL64((aOrbiterA * 5927771378657284557U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10707336923305131629U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17122696159336995392U) ^ RotL64(aNonceWordF, 3U);
            aOrbiterC = RotL64((aOrbiterC * 13953518568670659191U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5182322763573586116U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6503754948502556246U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14749002194140663519U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14907832047832987341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6258064448676621346U;
            aOrbiterD = RotL64((aOrbiterD * 4407960312705621487U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1180234574888070795U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 801686887651085881U;
            aOrbiterI = RotL64((aOrbiterI * 433981853631548041U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11810494591997709554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9343740505955858127U;
            aOrbiterF = RotL64((aOrbiterF * 8733378485648720323U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12816829575386720695U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13499155707765393469U;
            aOrbiterB = RotL64((aOrbiterB * 9937924703928730369U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 34U);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 42U));
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 47U));
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aNonceWordG, 61U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aIngress, 40U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aCarry, 29U)) + RotL64(aNonceWordA, 16U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 26U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 36U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererF, 6U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 22U) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21316U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21394U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordG, 3U)) ^ RotL64(aNonceWordC, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16710U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22958U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 35U)) + 17225673071833726819U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 10301458382103627331U) + RotL64(aNonceWordA, 47U);
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 3960233050857362414U) + RotL64(aNonceWordF, 19U);
            aOrbiterK = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 17768665685046605837U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 54U)) + 14471018461213959767U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 47U)) + 10730597892721340453U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 57U)) + 14863394003122760542U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 29U)) + 9948587274816688296U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 27U)) + 3573569431435100993U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 60U)) + 8153670675740450590U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 41U)) + 16438856577722561424U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15765587867581925041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1082039522061775213U;
            aOrbiterH = RotL64((aOrbiterH * 17023740047246402641U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4202521649260798876U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15877659681260461141U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11369910758551088173U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2551560426129646123U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3005102326163906320U;
            aOrbiterE = RotL64((aOrbiterE * 4241583192662435107U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1675501058857208089U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12774812270956702043U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5488437008504905105U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1044886020922563597U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4857445127457225171U;
            aOrbiterB = RotL64((aOrbiterB * 13223560654459705259U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11548725551787560962U) + RotL64(aNonceWordB, 51U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2434677823189765161U;
            aOrbiterD = RotL64((aOrbiterD * 4283026044563670969U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9606875320524736294U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13732615866277657704U;
            aOrbiterJ = RotL64((aOrbiterJ * 3905528919281629775U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13921743663803299567U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13350829301153929899U;
            aOrbiterK = RotL64((aOrbiterK * 11858642286713079795U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9473349030551400156U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7446792050826434742U;
            aOrbiterA = RotL64((aOrbiterA * 6619682184124713031U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 17970527747978977453U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2326714817603921480U;
            aOrbiterC = RotL64((aOrbiterC * 14581676978186226887U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7875511075130474136U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17225673071833726819U) ^ RotL64(aNonceWordG, 40U);
            aOrbiterI = RotL64((aOrbiterI * 1196024136909896027U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 20U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + RotL64(aNonceWordC, 15U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 48U) + aOrbiterI) + RotL64(aOrbiterG, 46U)) + RotL64(aNonceWordE, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterD, 56U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterK, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordD, 39U)) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 24702U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 27419U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordB, 60U)) ^ RotL64(aNonceWordG, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31870U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24819U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCross, 27U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 29U)) + 6654158889644956636U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 57U)) + 9045779659363991870U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 19U)) + 3888897662136993491U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 34U)) + 6882016842864459345U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 27U)) + 15601891715956172291U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 5176811598629335350U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 51U)) + 12519945150889074325U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 4552583214397603278U) + RotL64(aNonceWordC, 37U);
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 14225482701804864688U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 12U)) + 5485298070606280363U) + RotL64(aNonceWordG, 53U);
            aOrbiterI = ((aWandererD + RotL64(aCross, 39U)) + 11237713257388094289U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14340345895626142788U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 16275167270553643347U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ RotL64(aNonceWordA, 25U);
            aOrbiterJ = RotL64((aOrbiterJ * 7308578867128951199U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14041860597556520250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1436068974197066343U;
            aOrbiterF = RotL64((aOrbiterF * 3938460345031496843U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11483155566419547004U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4608508534724289325U;
            aOrbiterG = RotL64((aOrbiterG * 13461385011638899485U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2389196334288832895U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4062682330273866602U;
            aOrbiterC = RotL64((aOrbiterC * 8787682133271101901U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5655656046585592034U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7977947821249746880U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10082104644185964787U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11653718118543974168U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5456429682072377614U;
            aOrbiterE = RotL64((aOrbiterE * 12504180638665296649U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12457179652004203574U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 445821754230182952U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16043092621697786393U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12429505513284703263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12480745784412363537U;
            aOrbiterI = RotL64((aOrbiterI * 643617210585287593U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6952219750393303609U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13965647644550998416U;
            aOrbiterK = RotL64((aOrbiterK * 5395755018020115073U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5602193483992512507U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9593414134773695959U;
            aOrbiterA = RotL64((aOrbiterA * 2186313187456153775U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16469843418561148995U) + RotL64(aNonceWordD, 18U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6654158889644956636U;
            aOrbiterD = RotL64((aOrbiterD * 17490973872858383001U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterI, 14U)) + RotL64(aNonceWordH, 45U)) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 22U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aNonceWordF, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 43U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 11U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 26U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 41U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 50U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 40U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Softball_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB0413A238DACA539ULL + 0xB772C01121BD9356ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB20F099902459B05ULL + 0xB9A0FA15619C3D32ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD650622FBE59A1BFULL + 0xE4DF64D797307AD8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAD819B889CC31185ULL + 0xDD479E75BF98B510ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFDDAF8A5F7A29C09ULL + 0xA7C825CC46F0DE3CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE108AEAE47B08C79ULL + 0x9BDF26F3F3882450ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8A6B1C11A28F909DULL + 0xCA11B2D8887CE730ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEBE851A34F71139DULL + 0xF87A452A42673FC5ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordC, 43U)) ^ RotL64(aNonceWordD, 4U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3243U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 5091U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordB, 23U)) ^ RotL64(aNonceWordH, 52U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3483U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 414U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 36U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 43U)) + 785861751704720606U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 13U)) + 15968088718435606299U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 51U)) + 1393976526590347151U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 34U)) + RotL64(aCarry, 27U)) + 17240750947292745884U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 21U)) + 4921576136163183137U) + RotL64(aNonceWordF, 29U);
            aOrbiterH = ((aWandererI + RotL64(aScatter, 29U)) + 3334047873553153032U) + RotL64(aNonceWordD, 19U);
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 15086509978458408698U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 892391205397581998U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 2965686403183767521U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14632215393655706170U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15740589515342377322U) ^ RotL64(aNonceWordG, 50U);
            aOrbiterI = RotL64((aOrbiterI * 15677716942904794913U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11131164813943086445U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6988080581278900960U;
            aOrbiterH = RotL64((aOrbiterH * 6412189142344044255U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16021254613117657178U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6183615599897921154U;
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12533992547026652747U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3104325358982904219U) ^ RotL64(aNonceWordC, 45U);
            aOrbiterF = RotL64((aOrbiterF * 14977348108778147265U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3878525937957474644U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2120435259884368445U;
            aOrbiterD = RotL64((aOrbiterD * 15964718652193073177U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14928658302694194856U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9121310461310309348U;
            aOrbiterJ = RotL64((aOrbiterJ * 17304439784647477491U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3715693239100476493U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7336577492932262490U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11074754160002665253U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2312452827448455675U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 4322756069651934618U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6908893297397073539U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4962079617577705818U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5072727464750706525U;
            aOrbiterK = RotL64((aOrbiterK * 4947670001221089155U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 26U) + aOrbiterH) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 51U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 26U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererA = aWandererA + ((((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterI, 21U)) + RotL64(aNonceWordH, 25U)) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + RotL64(aNonceWordA, 61U));
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 22U) ^ RotL64(aNonceWordB, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10911U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 8735U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordG, 12U)) ^ RotL64(aNonceWordD, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6560U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 6807U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 22U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aScatter, 14U)) + 9751314027302668907U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 41U)) + 12175450995523107056U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 47U)) + 17519694958730119552U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 35U)) + 9093525527925682263U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 3713831321786810138U) + RotL64(aNonceWordF, 7U);
            aOrbiterK = ((aWandererE + RotL64(aIngress, 10U)) + RotL64(aCarry, 35U)) + 10108355209191835040U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 23U)) + 12956307447311314768U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 1904298513945877359U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 57U)) + 4658049993308574460U) + RotL64(aNonceWordB, 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9826333658248851902U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12058666914724365134U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 964233873188373939U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2516574707110528099U) + RotL64(aNonceWordH, 21U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13335308331049750235U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5880227828760598587U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8230749255538495304U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16536559486797811486U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7097036838156464969U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12387639130570188998U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8459259798142872020U;
            aOrbiterE = RotL64((aOrbiterE * 8001346480955847013U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16083784052002800300U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1957284290736468379U;
            aOrbiterG = RotL64((aOrbiterG * 5046501301740813065U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7349538179311335863U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16395170077006105258U;
            aOrbiterJ = RotL64((aOrbiterJ * 4230485452156662763U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3317652065873784068U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5517155804799120700U;
            aOrbiterH = RotL64((aOrbiterH * 9789270651974719183U), 5U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 5568525912112200094U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordE, 51U);
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9334250662962319598U;
            aOrbiterK = RotL64((aOrbiterK * 5034887614541768961U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5641394627075994165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13524971148931512745U;
            aOrbiterA = RotL64((aOrbiterA * 3699457147759854357U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 46U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + RotL64(aNonceWordC, 25U));
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 24U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + RotL64(aNonceWordA, 54U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 11U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterH, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordH, 38U)) ^ RotL64(aNonceWordF, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13493U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15175U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16205U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16327U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 51U)) + (RotL64(aCross, 22U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 5U)) + 2168513956284366370U) + RotL64(aNonceWordC, 47U);
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 11U)) + 10290361969974613111U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 56U)) + 15673836275828498050U;
            aOrbiterA = (aWandererC + RotL64(aCross, 39U)) + 16600540024145812236U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 23U)) + 9428052101528111892U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 12763657928312763377U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 10751286982008662485U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 46U)) + RotL64(aCarry, 3U)) + 1708230173038057979U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 51U)) + 4011389705422783816U) + RotL64(aNonceWordF, 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11704428328093077714U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2055336619674699284U;
            aOrbiterD = RotL64((aOrbiterD * 6374289210096410907U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1870865272102705804U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3574214263751923179U;
            aOrbiterB = RotL64((aOrbiterB * 13132083406834413563U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 984611970726966186U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15207945449947643672U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9539470161576639981U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4181398506373973169U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15222345431506025949U;
            aOrbiterJ = RotL64((aOrbiterJ * 6925143692628659467U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15023513452326240962U) + RotL64(aNonceWordB, 13U);
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14965669361708810699U;
            aOrbiterF = RotL64((aOrbiterF * 587008860996713147U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7985755518735406360U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 225592097619240187U;
            aOrbiterG = RotL64((aOrbiterG * 2313509354133400439U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3659537916566939383U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17043668033610689611U;
            aOrbiterK = RotL64((aOrbiterK * 10797634709118100773U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10217321522161675848U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8013663869536146842U;
            aOrbiterH = RotL64((aOrbiterH * 2293233079384777175U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13762445330867496042U) + RotL64(aNonceWordG, 36U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2692400019659269106U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 167704184292219399U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 10U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 56U) + aOrbiterB) + RotL64(aOrbiterI, 60U));
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ) + RotL64(aNonceWordD, 45U));
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterK, 34U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 6U) + aOrbiterH) + RotL64(aOrbiterF, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 39U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordE, 7U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordG, 60U)) ^ RotL64(aNonceWordF, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18510U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 19589U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 20U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16537U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 17438U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 20U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 27U)) + 2783898056762489197U) + RotL64(aNonceWordB, 16U);
            aOrbiterC = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 7177192902873343053U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 41U)) + 12254703232691980774U) + RotL64(aNonceWordE, 19U);
            aOrbiterK = ((aWandererG + RotL64(aScatter, 57U)) + 15446547245691219559U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 48U)) + RotL64(aCarry, 5U)) + 888475203006174856U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 53U)) + 3649183529366307877U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 35U)) + 4642631047518805167U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 19U)) + 6108329730724782250U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 47U)) + 8334054653023816636U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 5891895375031474350U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordH, 43U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3176720746238477862U;
            aOrbiterJ = RotL64((aOrbiterJ * 1869961473768307911U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6111038696865301675U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11914998302228682704U;
            aOrbiterG = RotL64((aOrbiterG * 11738924766359642853U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17005063057791320948U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 18333780598768130670U;
            aOrbiterA = RotL64((aOrbiterA * 5416759844884107303U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2056115016443263153U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10245512728872962677U;
            aOrbiterI = RotL64((aOrbiterI * 707106795383284903U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4810366069422162351U) + RotL64(aNonceWordC, 59U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3051442983125942469U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13558537578054436423U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9285068547223654308U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13067251130180968842U;
            aOrbiterF = RotL64((aOrbiterF * 7000687697769766605U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3203670242792002165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1770881716916463461U;
            aOrbiterH = RotL64((aOrbiterH * 13870229847371882171U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16286823712870537410U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13067191141829694202U;
            aOrbiterB = RotL64((aOrbiterB * 15629974528467350445U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3414576315085336932U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8979691827341555245U;
            aOrbiterC = RotL64((aOrbiterC * 15971594804040295757U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 18U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 22U)) + aOrbiterH) + RotL64(aNonceWordA, 49U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterC, 18U)) + RotL64(aNonceWordF, 17U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            aWandererC = aWandererC + ((RotL64(aCross, 38U) + aOrbiterJ) + RotL64(aOrbiterF, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 41U) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21973U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23040U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordH, 5U)) ^ RotL64(aNonceWordC, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26388U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 26216U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 36U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 41U)) + 13350544654542863236U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 29U)) + 12364346790125404372U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 9738750172849512764U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 3781373837635491421U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 51U)) + 16635020317512702337U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 23U)) + 5383653921676231276U) + RotL64(aNonceWordD, 17U);
            aOrbiterE = ((aWandererD + RotL64(aCross, 60U)) + 10181959815492056493U) + RotL64(aNonceWordF, 9U);
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 5U)) + 10005510924273927017U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 11U)) + 9524687662265740565U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4259138552009771014U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8973051213213726023U;
            aOrbiterG = RotL64((aOrbiterG * 12625091476068190979U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17602611840127337490U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8218984546932905269U;
            aOrbiterJ = RotL64((aOrbiterJ * 17504305273683304231U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18102186122213487888U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2629927500298092976U;
            aOrbiterH = RotL64((aOrbiterH * 6983280164448292723U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2491581597835795234U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9506602492971620955U;
            aOrbiterI = RotL64((aOrbiterI * 9559829640915637163U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13422942713680612924U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15037354693234876601U;
            aOrbiterC = RotL64((aOrbiterC * 12692376075738621447U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12896066842192894694U) + RotL64(aNonceWordH, 59U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2202952306291905855U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6779368532763429997U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12160313482450599313U) + RotL64(aNonceWordA, 41U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10812986281270407756U;
            aOrbiterE = RotL64((aOrbiterE * 7786608700746771809U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12474638293190144525U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5882870951276225224U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15532427302173572457U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3782896138051179209U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10965680631059882311U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14060923998307082385U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 28U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterI, 34U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 52U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordE, 61U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 58U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 14U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 34U) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27350U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29760U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordD, 34U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32651U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32493U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 40U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 27U)) + 6733949564325516029U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 18U)) + RotL64(aCarry, 11U)) + 7304098437143918796U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 57U)) + 3923949518391777800U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 14243591003388927124U) + RotL64(aNonceWordG, 48U);
            aOrbiterA = ((aWandererI + RotL64(aScatter, 37U)) + 18329498724605410406U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 23U)) + 13118172167747037249U) + RotL64(aNonceWordA, 47U);
            aOrbiterD = ((aWandererE + RotL64(aCross, 10U)) + RotL64(aCarry, 53U)) + 5272025143849174212U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 41U)) + 16075917179214318424U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 51U)) + 15263590648674658399U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13730046728289525921U) + RotL64(aNonceWordH, 29U);
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7703141464499623408U;
            aOrbiterB = RotL64((aOrbiterB * 5886009900621521987U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1382279753822135359U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2973369221699098292U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7440242040663550631U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11578274119583013219U) + RotL64(aNonceWordF, 19U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3419411247737896674U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17814942652262802991U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2582783513078999303U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3959762790273529677U;
            aOrbiterI = RotL64((aOrbiterI * 383974377372162751U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 465795011576934604U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17880826624185821135U;
            aOrbiterF = RotL64((aOrbiterF * 4445949147592860913U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10819659185349413173U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17298208553586835030U;
            aOrbiterJ = RotL64((aOrbiterJ * 1965860510614222093U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12585880006661489402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16650193903267408586U;
            aOrbiterH = RotL64((aOrbiterH * 5781132589396936615U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 885882046325991589U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 869560078374809974U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13440973563438747181U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11871305571797951851U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12137095015607196226U;
            aOrbiterE = RotL64((aOrbiterE * 7618152256560808581U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 52U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + RotL64(aNonceWordD, 41U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 48U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterK) + RotL64(aNonceWordC, 17U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 38U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Softball_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFD866787C8541029ULL + 0xE288755E56A863CBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD74508948CF38FADULL + 0x96C77617B124946EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9D12E6670FA072CDULL + 0xAADC754AC5F47501ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCA1C0ABF8CACEADDULL + 0x8DCAA0EB2819736DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEC2B91B2B904DB25ULL + 0xE8B59F71DA56C84EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD598CD99FE4F707DULL + 0xF7C846EB46C3142DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD0F74EFEC0394E01ULL + 0xA6D6C42B3AAA7030ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF6EB6EC6955040B3ULL + 0xDD9E99F84F78FE91ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 39U) ^ RotL64(aNonceWordG, 60U)) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4520U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1856U)) & W_KEY1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordD, 23U)) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3667U)) & W_KEY1], 54U) ^ RotL64(mSource[((aIndex + 1055U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (((aWandererA + RotL64(aIngress, 50U)) + 8975885703279267062U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordH, 43U);
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 8664844915562660637U;
            aOrbiterK = (aWandererE + RotL64(aCross, 57U)) + 12281774799736296726U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 13U)) + 15347461352311329726U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 12967500561828907834U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 43U)) + 5002833859280402726U) + aPhaseAOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordB, 60U);
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 11908257536954668983U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17017174811949227162U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16851323125613931180U) ^ RotL64(aNonceWordE, 37U);
            aOrbiterK = RotL64((aOrbiterK * 12446990992858763577U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13469326957728686706U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5228638551056105241U) ^ RotL64(aNonceWordF, 55U);
            aOrbiterD = RotL64((aOrbiterD * 13369947664646167255U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11945166198089308564U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16268645041872996022U;
            aOrbiterF = RotL64((aOrbiterF * 5391448793718370911U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14781204627695095701U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5365325354838101092U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8017284997946310807U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 563147416025715953U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14660867395395625851U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4769458126865307103U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3168989056355712105U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16179131669773665579U;
            aOrbiterE = RotL64((aOrbiterE * 5641461617066671723U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4160220074225527179U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8597134686962559111U;
            aOrbiterB = RotL64((aOrbiterB * 639572585431474015U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + aPhaseAWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + RotL64(aNonceWordG, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterE, 58U));
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 5U)) + aOrbiterD) + RotL64(aNonceWordC, 31U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 39U) ^ RotL64(aNonceWordE, 6U)) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5618U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 5647U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 36U) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8775U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7999U)) & W_KEY1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 6024062041314952357U) + aPhaseAOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordB, 11U);
            aOrbiterB = (aWandererK + RotL64(aPrevious, 51U)) + 18340757093658015585U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 27U)) + 11911120493880346751U;
            aOrbiterG = (aWandererB + RotL64(aCross, 5U)) + 17428074353884654439U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 12790849760814795936U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 20U)) + RotL64(aCarry, 57U)) + 12633397052172117800U) + aPhaseAOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 11U)) + 11946150433665237945U) + RotL64(aNonceWordF, 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16842157900909419285U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 14186235783224155962U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) ^ RotL64(aNonceWordG, 25U);
            aOrbiterC = RotL64((aOrbiterC * 10521157787073684417U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13284904542579767591U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11609181965078844357U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5455780554452453513U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9628562297095374984U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7850281529011259759U;
            aOrbiterG = RotL64((aOrbiterG * 17611485102925470357U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 257458718073794527U) + RotL64(aNonceWordC, 55U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10693404545773519306U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14821443722828498323U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3430519236533871460U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6183054506953198055U;
            aOrbiterI = RotL64((aOrbiterI * 6121082743789970911U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2905610989884221654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4472163910775333862U;
            aOrbiterH = RotL64((aOrbiterH * 7770678426310856745U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16870142883133769663U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1403692060594816451U;
            aOrbiterA = RotL64((aOrbiterA * 9740854430251597879U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterI, 37U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 29U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 51U)) + aOrbiterI) + RotL64(aCarry, 53U)) + RotL64(aNonceWordH, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterA) + RotL64(aNonceWordA, 58U));
            aWandererG = aWandererG + (((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + aPhaseAWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterH, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 28U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 14U) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15667U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12005U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15986U)) & W_KEY1], 26U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12458U)) & W_KEY1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 12U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 3U)) + 14214886793361825363U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 11U)) + 17267959031078766320U) + RotL64(aNonceWordF, 57U);
            aOrbiterI = (aWandererC + RotL64(aScatter, 21U)) + 16436067429484887644U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 29U)) + 9885951769332633820U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 36U)) + RotL64(aCarry, 47U)) + 12971711341813893304U;
            aOrbiterC = ((((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 199970353398450154U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordE, 55U);
            aOrbiterH = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 1237341696444162094U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7991128854417613360U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14809029847149045833U) ^ RotL64(aNonceWordC, 58U);
            aOrbiterI = RotL64((aOrbiterI * 5940857360838299105U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2559509556915775947U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14336829730147834160U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15103242520064900873U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8853631886733610440U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13346159398673246914U;
            aOrbiterG = RotL64((aOrbiterG * 13660497151446983393U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12121095718571872976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16239781125815589804U;
            aOrbiterF = RotL64((aOrbiterF * 5157009090454962231U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9051377033794324106U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13805815136723461780U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 571129481747181357U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14849157800322754413U) + RotL64(aNonceWordG, 35U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 18116651528452542634U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3638480428016835537U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4105057226952948599U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5911714320560994391U;
            aOrbiterH = RotL64((aOrbiterH * 1796514171654961389U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterH, 22U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 50U) + RotL64(aOrbiterF, 40U)) + aOrbiterE) + RotL64(aNonceWordH, 3U)) + aPhaseAWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + RotL64(aCarry, 57U)) + RotL64(aNonceWordA, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordA, 46U)) ^ RotL64(aNonceWordG, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20935U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 20429U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordC, 12U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19142U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 19442U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 22U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 35U)) + 16922357079016918108U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 23U)) + 11771749797137599131U) + RotL64(aNonceWordH, 35U);
            aOrbiterK = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 4635668433708036077U) + aPhaseAOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 15827952719230577008U;
            aOrbiterB = ((((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 1495675306110023086U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordE, 18U);
            aOrbiterI = (aWandererC + RotL64(aPrevious, 57U)) + 7294835466949728365U;
            aOrbiterG = (aWandererG + RotL64(aCross, 44U)) + 179122461212041978U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 545981421632236251U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15338259639814630535U;
            aOrbiterK = RotL64((aOrbiterK * 14895421566334357871U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12924313840290895215U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17846785921286020610U;
            aOrbiterI = RotL64((aOrbiterI * 18309347016029917133U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 5721472794107057875U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordF, 21U);
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16359630793856870319U;
            aOrbiterA = RotL64((aOrbiterA * 14186771515526698907U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10614102110239037308U) + RotL64(aNonceWordB, 15U);
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16421992251278236531U;
            aOrbiterB = RotL64((aOrbiterB * 2561232904676068089U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8668149834861244963U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12699331834360948734U;
            aOrbiterH = RotL64((aOrbiterH * 2249360824172616357U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4470693178142950471U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 526000656022724741U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16688501462334673493U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6880246132270094141U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7126466778855297013U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5692237926830293205U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterA, 60U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + RotL64(aCarry, 19U)) + RotL64(aNonceWordG, 7U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterK, 43U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 27U)) + aOrbiterK) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + RotL64(aNonceWordD, 49U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26120U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21884U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordH, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27103U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26156U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 18U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 13296600294247799698U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 39U)) + 5818503518080877515U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 57U)) + 6735784238734173597U) + RotL64(aNonceWordC, 47U);
            aOrbiterD = (aWandererK + RotL64(aCross, 21U)) + 7368398209488856201U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 961734029066455638U;
            aOrbiterA = ((((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 797011946660892011U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordA, 13U);
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 50U)) + 12841876018396622350U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16213253970483895623U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15186950557113470375U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4647470430467908107U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 5117930310827477341U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordE, 24U);
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12265429373166094162U;
            aOrbiterK = RotL64((aOrbiterK * 1522823535151532249U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13920531346698601568U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14695405206998211456U;
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7851960904825938443U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9501511171732550190U;
            aOrbiterB = RotL64((aOrbiterB * 5614164120361489613U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5663365182245722077U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9607860124321315555U;
            aOrbiterG = RotL64((aOrbiterG * 3461820361914280601U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 18171052650586819280U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordG, 9U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3442698321538580861U;
            aOrbiterA = RotL64((aOrbiterA * 6317525514963824829U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1491052813469258970U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3956599824067616133U;
            aOrbiterC = RotL64((aOrbiterC * 2928600779267623085U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterH, 28U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterG, 21U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordB, 17U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 50U) + aOrbiterG) + RotL64(aOrbiterA, 48U)) + RotL64(aNonceWordD, 15U)) + aPhaseAWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterD) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordE, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29874U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 28651U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 54U) ^ RotL64(aNonceWordB, 5U)) ^ RotL64(aNonceWordH, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31431U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27998U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 44U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 41U)) + 4634399531433127141U) + aPhaseAOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 16961792729406903200U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 4105280732301137738U) + RotL64(aNonceWordC, 5U);
            aOrbiterE = (aWandererH + RotL64(aCross, 34U)) + 15692013501147331191U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 11U)) + 1252216715968780587U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 51U)) + 7958289043012473752U) + RotL64(aNonceWordD, 27U);
            aOrbiterH = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 6611577301818896615U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8506226754305949140U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3648813120449403353U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9521367946879238849U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5195245426245535735U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 542948051600803051U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4631106308856448475U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11974253551208964789U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10596463592332655367U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10941161258815714641U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12015129484061440159U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8254944355710109060U) ^ RotL64(aNonceWordB, 45U);
            aOrbiterH = RotL64((aOrbiterH * 3233697992479357615U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2754858806943915419U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5007802002906662779U;
            aOrbiterF = RotL64((aOrbiterF * 15613733948331639723U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6262190752136523216U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10528977986487821428U;
            aOrbiterE = RotL64((aOrbiterE * 1184258264034585525U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 8511097226098211854U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12091864735686692582U) ^ RotL64(aNonceWordF, 41U);
            aOrbiterD = RotL64((aOrbiterD * 6128140528141411237U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 42U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + RotL64(aNonceWordG, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 12U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterH) + RotL64(aNonceWordA, 40U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterD, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Softball_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEC6A676EC126287FULL + 0xFC9D4DEE16BCA438ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEB9BDC09407EFCBDULL + 0xA3277DE6DD119778ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEFF68063CB932757ULL + 0xF6FA3AB1DC367843ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEDAA1A7BD5A52BEFULL + 0xFD4FE48D605CF5A2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBAB22E33BB126CB5ULL + 0xD26D37986E8787DBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8F9F9DA2DFAD97EDULL + 0x8C4E6FE0CA3CC0F3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE3A7C4C85B68F71DULL + 0xE2E62A71AA303981ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x880480BC38BAFE1BULL + 0xBC4EA1B3732860D2ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 54U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordD, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 225U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2285U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordA, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1986U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4536U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 42U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 13278949403988203974U;
            aOrbiterA = ((((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 9213599924054673756U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordF, 52U);
            aOrbiterJ = (aWandererA + RotL64(aScatter, 47U)) + 1255746482932381798U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 11575321997144516122U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 6U)) + 15881587525529432437U) + aPhaseBOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordA, 45U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9846195809864862707U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12319815691858217670U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14271546305640811091U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16322617427294439587U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16332130810525887437U;
            aOrbiterH = RotL64((aOrbiterH * 7588076439690559343U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4920951156015336794U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16767126455124552329U;
            aOrbiterG = RotL64((aOrbiterG * 4440352337076842603U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12553595911087945223U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1437522202135436142U) ^ RotL64(aNonceWordC, 9U);
            aOrbiterA = RotL64((aOrbiterA * 2001992794165550905U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12313100454852227143U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 2761983020631055729U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ RotL64(aNonceWordB, 55U);
            aOrbiterE = RotL64((aOrbiterE * 3874839760378039509U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordG, 43U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 43U)) + aOrbiterH) + RotL64(aNonceWordH, 27U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 12U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 24U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 58U) ^ RotL64(aNonceWordG, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9521U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 6091U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordH, 34U)) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7569U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10290U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 10U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 4773124477323378268U) + aPhaseBOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordF, 25U);
            aOrbiterC = ((aWandererA + RotL64(aIngress, 52U)) + RotL64(aCarry, 23U)) + 16848723289435796005U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 27U)) + 13846642134917107058U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 6472057872482789939U) + RotL64(aNonceWordA, 51U);
            aOrbiterD = ((aWandererC + RotL64(aScatter, 39U)) + 2747019500690707226U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9003965289739733880U) + RotL64(aNonceWordE, 27U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3013390651936257377U;
            aOrbiterF = RotL64((aOrbiterF * 11081353600889943167U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3331004709895625067U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15355010435553517129U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8322759117004876831U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7709870658004280052U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13568728443963926564U;
            aOrbiterH = RotL64((aOrbiterH * 6736090830113688981U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 12409548853419307131U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordD, 59U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 969183352023661537U;
            aOrbiterC = RotL64((aOrbiterC * 5549220554838837145U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15370309834426476775U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3896803894396631184U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11018830202891911603U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 14U);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + RotL64(aCarry, 37U)) + RotL64(aNonceWordC, 10U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + RotL64(aOrbiterA, 60U)) + aOrbiterF) + RotL64(aCarry, 11U)) + RotL64(aNonceWordB, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 37U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 14U) ^ RotL64(aNonceWordB, 57U)) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11969U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11284U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordE, 3U)) ^ RotL64(aNonceWordA, 30U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15621U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11928U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 53U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 37U)) + 11274974230580265396U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 16658438747342741547U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 16612986966106053844U) + aPhaseBOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 25U);
            aOrbiterD = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 9329502236843231290U) + RotL64(aNonceWordF, 43U);
            aOrbiterC = (aWandererG + RotL64(aCross, 19U)) + 14088261356708344656U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13692608802007789581U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6824473946645682398U;
            aOrbiterB = RotL64((aOrbiterB * 13619437545775237601U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2072915876348570040U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 7420507753044460759U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordB, 23U);
            aOrbiterI = RotL64((aOrbiterI * 13239288539564571257U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4677557318688502593U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15081678577055628459U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16659305295251177155U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7026792817486507482U) + RotL64(aNonceWordE, 26U);
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14871665922943969918U;
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6807734532159292872U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17882797335141303280U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + RotL64(aNonceWordH, 11U));
            aWandererF = aWandererF + (((((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordC, 15U)) + aPhaseBWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 56U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererG, 44U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordA, 19U)) ^ RotL64(aNonceWordE, 34U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20924U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20073U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordF, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19268U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16650U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 1042610313571524121U) + RotL64(aNonceWordE, 61U);
            aOrbiterA = (((aWandererF + RotL64(aScatter, 58U)) + 3505725321008825582U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordF, 49U);
            aOrbiterB = (aWandererC + RotL64(aCross, 19U)) + 12584654563843782991U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 6645399144515770935U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 3608978423753715584U) + aPhaseBOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8089198857670370983U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15207251813516399879U) ^ RotL64(aNonceWordH, 7U);
            aOrbiterB = RotL64((aOrbiterB * 7596841660069752069U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9579268660105824516U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16055044469473802812U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2269649280637188723U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 583811872609805949U) + RotL64(aNonceWordD, 25U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7027491967970873942U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12686754713465826139U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 18256061823189677508U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12708429127816136937U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12593886633108075321U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12169216645156306078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12694325407567795065U;
            aOrbiterD = RotL64((aOrbiterD * 3711789483877261899U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + RotL64(aNonceWordG, 58U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterG, 43U)) + aOrbiterF) + RotL64(aCarry, 19U)) + RotL64(aNonceWordB, 21U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterA, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 60U) ^ RotL64(aNonceWordC, 5U)) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22669U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 25104U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordF, 4U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27220U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 24264U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 13687218104610230596U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 12U)) + RotL64(aCarry, 27U)) + 6841550124960692709U) + RotL64(aNonceWordA, 43U);
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 43U)) + 17418968668458764131U) + aPhaseBOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aScatter, 3U)) + 8303537912696948204U) + aPhaseBOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordC, 29U);
            aOrbiterH = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 12376614417285936537U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14215749063579232654U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 4111736931433665347U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ RotL64(aNonceWordH, 37U);
            aOrbiterJ = RotL64((aOrbiterJ * 8841288213954433049U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11250375934571631522U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5367367837773331275U;
            aOrbiterH = RotL64((aOrbiterH * 7262723007545807179U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15514089192382674434U) + RotL64(aNonceWordE, 61U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1475991716685034960U;
            aOrbiterA = RotL64((aOrbiterA * 17720681295551650891U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5531622777788629748U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8363822215908303335U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17850203366840994883U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3741256932685720414U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11634667238062155772U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15925089729784547403U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE) + RotL64(aNonceWordG, 4U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordD, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 4U)) + aOrbiterG) + aPhaseBWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordB, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28849U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30259U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordC, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28650U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30338U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 13U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 51U)) + 9080426856729228705U) + aPhaseBOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordE, 50U);
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 5U)) + 7851218321653539276U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 37U)) + 7023344692919298036U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 9772846154227440734U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 26U)) + RotL64(aCarry, 19U)) + 12008298632429608431U) + RotL64(aNonceWordA, 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12201090455849562875U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9498721803411445471U) ^ RotL64(aNonceWordC, 49U);
            aOrbiterI = RotL64((aOrbiterI * 6511810500788451775U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 351203764023093632U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4966360430644539250U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10138518378274592739U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9194167899071345693U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 4922477697284269116U) ^ RotL64(aNonceWordG, 3U);
            aOrbiterB = RotL64((aOrbiterB * 8444814161720407881U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15742625291642356429U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7528703106518431730U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11530049278751507567U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15279053574704935317U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2425839793660355555U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11486964816849830667U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + RotL64(aNonceWordD, 25U));
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterB, 54U)) + RotL64(aNonceWordH, 39U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 27U)) + aOrbiterD) + aPhaseBWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Softball_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCBCA107B7EFBD301ULL + 0xFCAFA43D7425998EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFE30825BA5FF95B5ULL + 0xFA099373CFD27717ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD782CFCBB3F82479ULL + 0xF988980EE63D6093ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC6A32D6C7E409BA7ULL + 0xA8AB8B132A1E1C31ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8B66A5B054941E9DULL + 0xB4AD2139CF785361ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCAEDDB42FB33A50DULL + 0xBF33B64251882496ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC1B54630BBF385D5ULL + 0x8614400B7BA476B5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAB68A8C3A1E86139ULL + 0x8A49D7064CB5F8F4ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordC, 42U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5933U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3173U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 41U) ^ RotL64(aNonceWordH, 28U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3276U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 7912U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aScatter, 58U)) + 3248574644570178787U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 4506961512959200024U) + RotL64(aNonceWordE, 45U);
            aOrbiterE = (aWandererG + RotL64(aIngress, 47U)) + 8423739774540738590U;
            aOrbiterK = (aWandererK + RotL64(aCross, 51U)) + 6593975869641735337U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 43U)) + 16441716090557369103U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordF, 17U);
            aOrbiterH = (aWandererD + RotL64(aCross, 5U)) + 7936601450453207914U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 13333752583560167065U) + aPhaseCOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 8013703284795432973U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 18U)) + 2349852779887439236U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5318539364763284138U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11450957608502944376U;
            aOrbiterE = RotL64((aOrbiterE * 1957880366707810635U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9058992558327552687U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 632095686920230926U) ^ RotL64(aNonceWordB, 23U);
            aOrbiterH = RotL64((aOrbiterH * 12460364388358520799U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 14734218428913777098U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16344357661370784442U;
            aOrbiterG = RotL64((aOrbiterG * 15049472842002138369U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2981145363531184308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14176472085175714494U;
            aOrbiterF = RotL64((aOrbiterF * 2584623327412130939U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11198457590069700889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 952584436750426828U;
            aOrbiterB = RotL64((aOrbiterB * 1165713888651280355U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4311591763498985972U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16194341833989936369U) ^ RotL64(aNonceWordD, 10U);
            aOrbiterK = RotL64((aOrbiterK * 9997934560195932575U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7560794022401107431U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10683789740265711603U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15637823045351977883U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11614366395125937178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10750771385100564416U;
            aOrbiterD = RotL64((aOrbiterD * 4987921274272444283U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2934697034132204529U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4646873794658020363U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10555456865641580175U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 52U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 19U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aPhaseCWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 18U) + aOrbiterF) + RotL64(aOrbiterB, 44U));
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 53U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI + (((((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordG, 31U)) + aPhaseCWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + RotL64(aNonceWordA, 7U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterE, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 56U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordH, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13330U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 12356U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8253U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 16247U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aPrevious, 47U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 57U)) + 15904465836916519864U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 35U)) + 17725629806317789307U) + aPhaseCOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 22U)) + RotL64(aCarry, 57U)) + 13794170125914914828U) + RotL64(aNonceWordD, 34U);
            aOrbiterB = (aWandererC + RotL64(aCross, 5U)) + 2149055907476874332U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 53U)) + 5342047776745074649U) + RotL64(aNonceWordA, 11U);
            aOrbiterD = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 8268148484060546838U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 48U)) + 10821151364028563719U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 4294213820894407378U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 27U)) + 10884726101307943090U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16432210042202444824U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 15196602644336228055U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) ^ RotL64(aNonceWordE, 37U);
            aOrbiterG = RotL64((aOrbiterG * 12680438355124070237U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14117787670220328165U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 219833877949480215U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordG, 9U);
            aOrbiterH = RotL64((aOrbiterH * 10736293047771972173U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3326396981881473962U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14918513066311426279U;
            aOrbiterF = RotL64((aOrbiterF * 14269763278564574663U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11795234681370163206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3068267285352664813U;
            aOrbiterC = RotL64((aOrbiterC * 15746255933920904619U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 245233356957999496U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 709926406353796673U;
            aOrbiterI = RotL64((aOrbiterI * 13627039596842073595U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5378105439430271038U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10114555061122044430U;
            aOrbiterE = RotL64((aOrbiterE * 5351295043424885549U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13233010815716769713U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8231291294833548389U;
            aOrbiterB = RotL64((aOrbiterB * 10840516135212753869U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7160760224172419829U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14767926435411546785U;
            aOrbiterD = RotL64((aOrbiterD * 1643485739468851073U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4464245330038080103U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15778166658285494712U;
            aOrbiterA = RotL64((aOrbiterA * 13980891936095282989U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 24U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterF, 46U)) + RotL64(aNonceWordB, 45U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterE, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterG, 19U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + aPhaseCWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 53U)) + aOrbiterC) + RotL64(aCarry, 19U)) + RotL64(aNonceWordC, 61U)) + aPhaseCWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 28U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordD, 41U)) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19056U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19933U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 4U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordB, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21437U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24557U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 20U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 60U)) + 6361545377408870615U) + aPhaseCOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 37U)) + 2967245486744774933U) + RotL64(aNonceWordA, 25U);
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 3836634268482850139U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 23U)) + 7691642115360086297U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 13U)) + 16479280384178279281U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 56U)) + 2901468732552539249U) + aPhaseCOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 2600353867755647475U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 5666596904781510956U) + RotL64(aNonceWordE, 53U);
            aOrbiterI = (aWandererC + RotL64(aScatter, 47U)) + 16108791609267427553U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8389926875737312112U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1689501721163024426U;
            aOrbiterC = RotL64((aOrbiterC * 6517194895779049139U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11721701506949917719U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3963842745030140473U;
            aOrbiterG = RotL64((aOrbiterG * 6692473494944919373U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8510538243472109368U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 18281865214102080387U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1351546966368884609U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2259725140963665123U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11652011949557979650U) ^ RotL64(aNonceWordD, 18U);
            aOrbiterK = RotL64((aOrbiterK * 11260100762113295037U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1116085424226174473U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4725260319270802912U;
            aOrbiterB = RotL64((aOrbiterB * 4697109059565450269U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7348945429843437036U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1249234309180653260U) ^ RotL64(aNonceWordC, 55U);
            aOrbiterF = RotL64((aOrbiterF * 3136745255820405881U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12463505532573389603U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2304125977906510386U;
            aOrbiterA = RotL64((aOrbiterA * 9960816714791454421U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2178037443783425551U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11712110130079307683U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9797864956200779505U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10703510612147312252U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18155460326242413483U;
            aOrbiterI = RotL64((aOrbiterI * 6903953708987478723U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + RotL64(aNonceWordF, 57U)) + aPhaseCWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 12U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterG, 36U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordH, 9U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterB, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27561U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29909U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordD, 30U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24714U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 32759U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 826930775230515406U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 41U)) + 5137814617363250861U) + RotL64(aNonceWordE, 27U);
            aOrbiterF = ((aWandererA + RotL64(aScatter, 30U)) + 14761561947426681616U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 12773023438753662590U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 53U)) + 7331345852207096322U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 47U)) + 3899381212671247460U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 23U)) + 10072004147620068599U) + RotL64(aNonceWordF, 29U);
            aOrbiterI = (aWandererJ + RotL64(aScatter, 5U)) + 3424585039401897560U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 51U)) + 8246760141625966321U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3655992860610853290U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11154618022505863898U;
            aOrbiterF = RotL64((aOrbiterF * 4791494171286145231U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15629361991059709973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10842068502278489664U;
            aOrbiterC = RotL64((aOrbiterC * 17223002513104960799U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5571312349016336686U) + RotL64(aNonceWordH, 12U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 589313823745748879U;
            aOrbiterE = RotL64((aOrbiterE * 1356685926549786027U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13633457935771935260U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12684602052812183096U;
            aOrbiterJ = RotL64((aOrbiterJ * 4689206269919806711U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5711307583717354204U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7181854170553728211U;
            aOrbiterH = RotL64((aOrbiterH * 9835601115561325911U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1884620014396115821U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1471516373272364262U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5126319375714848029U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 742739371092077733U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8075893317715227838U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11208274111743259795U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8179547722249281263U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15305282712174742323U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7951986906055462929U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1430543231751281079U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 14585341768267283387U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) ^ RotL64(aNonceWordD, 57U);
            aOrbiterG = RotL64((aOrbiterG * 313213844964269133U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 44U) + aOrbiterI) + RotL64(aOrbiterF, 4U));
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aCross, 23U) + RotL64(aOrbiterD, 21U)) + aOrbiterE) + RotL64(aCarry, 13U)) + RotL64(aNonceWordC, 45U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 50U)) + aOrbiterD) + RotL64(aNonceWordG, 13U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterA, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + aPhaseCWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Softball_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA205B72A0888185BULL + 0x9A76A654F5CAC705ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDC0B8A999DE71767ULL + 0xE46C935BED0B3F67ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC9B086B4A667FCDDULL + 0xD267704D1176EC1EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE7F5BF92616349D7ULL + 0x8706FDDC1D99E4A2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB04A5401EFAFE989ULL + 0x911358FD286710ABULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9F898571779D1359ULL + 0x8FF5ADA8ACD21285ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x95BE3EFE0AF112E3ULL + 0xE832825329F768D6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x987F6A5B46B6CE93ULL + 0xEC5A19A17CE8EC89ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2345U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2849U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordC, 28U)) ^ RotL64(aNonceWordF, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2260U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 2067U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 13U)) + 14249093584376402677U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 46U)) + RotL64(aCarry, 47U)) + 8756965951816492264U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 43U)) + 11221139480258176330U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 51U)) + 17218894445564194851U) + RotL64(aNonceWordE, 39U);
            aOrbiterA = (aWandererC + RotL64(aScatter, 57U)) + 8064642692524949490U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 5822093203710704646U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 37U)) + 3217799620158102238U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 6U)) + RotL64(aCarry, 37U)) + 2613757677892120843U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 53U)) + 13647481499551657237U) + RotL64(aNonceWordH, 21U);
            aOrbiterH = (aWandererI + RotL64(aPrevious, 21U)) + 3545714196663685016U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 41U)) + 9735422670576621521U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 3911046580637583767U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordB, 43U);
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9315984027042049203U;
            aOrbiterG = RotL64((aOrbiterG * 12568550776487242469U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8926367674641729058U) + RotL64(aNonceWordC, 3U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11035347490524961446U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10948288997163592463U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10748158733051120339U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2467801787989056455U;
            aOrbiterE = RotL64((aOrbiterE * 12621934274702358977U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9244415080474351390U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8517784887959492079U;
            aOrbiterC = RotL64((aOrbiterC * 17022899813765884147U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8409307332803038455U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11043806021873232950U;
            aOrbiterK = RotL64((aOrbiterK * 8294888329708842989U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17512395828450251457U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16849067939795823992U;
            aOrbiterJ = RotL64((aOrbiterJ * 9361991804481514337U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17541946638063238056U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11430501673960586718U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15074409630605450091U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 78307505705383302U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4834528975263832983U;
            aOrbiterI = RotL64((aOrbiterI * 17245673681686752861U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9647985402149698269U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6610247710757518931U;
            aOrbiterA = RotL64((aOrbiterA * 8672486173272686859U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2706696306041774372U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9519896513600816252U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7468605169665549731U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14647351223431646222U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14249093584376402677U;
            aOrbiterH = RotL64((aOrbiterH * 8296105266618697281U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 42U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 21U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 37U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 58U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + RotL64(aNonceWordD, 38U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + RotL64(aNonceWordA, 15U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordH, 21U)) ^ RotL64(aNonceWordC, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7494U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10230U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 30U) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10369U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6750U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 21U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 11U)) + 10404808878585437255U) + aPhaseDOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 10587858736301591439U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 44U)) + 1430530909801644435U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 9090938022430118902U;
            aOrbiterB = (aWandererG + RotL64(aCross, 3U)) + 12936604311751121235U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 13U)) + 1000583006020232032U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 12352532088997042232U) + RotL64(aNonceWordH, 61U);
            aOrbiterH = (aWandererD + RotL64(aIngress, 21U)) + 16723410947058502564U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 36U)) + 16614089235313154270U) + RotL64(aNonceWordG, 20U);
            aOrbiterD = ((aWandererA + RotL64(aCross, 29U)) + 4245553025593349277U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 51U)) + 3353146318549477494U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5935727336135635196U) + RotL64(aNonceWordA, 25U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10312187090293319667U;
            aOrbiterF = RotL64((aOrbiterF * 1395964500396711899U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12192843181244744484U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2542570124502586365U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17222847847573534963U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3315472769469002444U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17512858811783071174U;
            aOrbiterB = RotL64((aOrbiterB * 9070400454074283765U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16633218007427888082U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2502077714838858460U;
            aOrbiterG = RotL64((aOrbiterG * 970762420815997725U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14792910273226469214U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15739513291150783151U;
            aOrbiterJ = RotL64((aOrbiterJ * 11896279674116906915U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2192903544350345992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 844428341223009295U;
            aOrbiterC = RotL64((aOrbiterC * 4768368713974002539U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2998511458298901402U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7790789639864783373U;
            aOrbiterA = RotL64((aOrbiterA * 9173097618440495497U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4540735375055164995U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13700342877362633034U) ^ RotL64(aNonceWordD, 3U);
            aOrbiterK = RotL64((aOrbiterK * 14730797752841670505U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16966725424259324323U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5945539295893015935U;
            aOrbiterH = RotL64((aOrbiterH * 12226268057062268981U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12560355243513521281U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2104086086480258265U;
            aOrbiterD = RotL64((aOrbiterD * 17989755118752755577U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4476697099257280568U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10404808878585437255U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6245415417832089357U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterD) + RotL64(aNonceWordE, 21U));
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 30U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aNonceWordF, 37U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 38U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererC, 36U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordF, 52U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13073U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 13383U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordB, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15210U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15882U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 6U)) + RotL64(aCarry, 19U)) + 6318740973868639425U;
            aOrbiterA = (aWandererK + RotL64(aCross, 41U)) + 5487840061430920881U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 10258706763248072672U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 57U)) + 18356875269730338208U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 3U)) + 12883160282903147010U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 10U)) + 1010140474942697730U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 17733939421700898293U) + aPhaseDOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 35U)) + 13693055887924981201U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 23U)) + 14574732452793385269U) + RotL64(aNonceWordF, 13U);
            aOrbiterK = ((aWandererI + RotL64(aCross, 53U)) + 10832873941223609012U) + RotL64(aNonceWordH, 23U);
            aOrbiterF = (aWandererD + RotL64(aIngress, 39U)) + 8212600587135328040U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5312744319781971178U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6173741211706546923U) ^ RotL64(aNonceWordC, 25U);
            aOrbiterJ = RotL64((aOrbiterJ * 12854414066390848249U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3693249147883790810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18365859989736602556U;
            aOrbiterB = RotL64((aOrbiterB * 3348463719324104997U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10645056678337549771U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1175668356822251045U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6579675292775345579U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13556844570541823717U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4790355739411849736U;
            aOrbiterH = RotL64((aOrbiterH * 4083544011788850307U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14905575502272644116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17047244574558476634U;
            aOrbiterE = RotL64((aOrbiterE * 2356386971503880047U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10161614295718414869U) + RotL64(aNonceWordE, 39U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13413914082651612468U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16224039093981079491U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6072693130156927774U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4333656233793103787U;
            aOrbiterG = RotL64((aOrbiterG * 9374745547133955709U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17209776289202130250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11752001118070361543U;
            aOrbiterI = RotL64((aOrbiterI * 4416523594812872339U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15367365111105608277U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8650687767097460704U;
            aOrbiterC = RotL64((aOrbiterC * 11430451559660578667U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18074648514448405693U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10857586858462237581U;
            aOrbiterD = RotL64((aOrbiterD * 3722891011080095849U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17219932344278345591U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6318740973868639425U;
            aOrbiterF = RotL64((aOrbiterF * 8846295038878812229U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 42U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 27U)) + RotL64(aNonceWordD, 28U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 26U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + RotL64(aNonceWordA, 55U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterB) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 50U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 38U) ^ RotL64(aNonceWordC, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21508U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18194U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19913U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17736U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 11U) + RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 26U)) + 4259993311776766595U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 2857813330021126753U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 35U)) + 1345396841329442896U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 43U)) + 320992148982301024U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 11U)) + 5619109532065293074U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 10380157329426706345U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 41U)) + 12449831150625409695U;
            aOrbiterE = (aWandererB + RotL64(aCross, 19U)) + 7847096607042268396U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 51U)) + 11707184096803214678U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((((aWandererJ + RotL64(aCross, 14U)) + RotL64(aCarry, 3U)) + 9893643746186827088U) + aPhaseDOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordC, 3U);
            aOrbiterF = ((aWandererG + RotL64(aIngress, 29U)) + 333687403830908774U) + RotL64(aNonceWordH, 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13837360705077441580U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4367119682175710689U;
            aOrbiterK = RotL64((aOrbiterK * 10295744669174603401U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1193493435041306784U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15062951612027370606U) ^ RotL64(aNonceWordE, 9U);
            aOrbiterD = RotL64((aOrbiterD * 2509383510565136549U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16000173839235429105U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15294482444605409961U;
            aOrbiterI = RotL64((aOrbiterI * 1031800997944302665U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5720749055549773527U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17248674962996093668U;
            aOrbiterC = RotL64((aOrbiterC * 15730637462755795591U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16956840483882091059U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9637715107943515594U;
            aOrbiterE = RotL64((aOrbiterE * 8878362378343603463U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7147495779349862274U) + RotL64(aNonceWordA, 43U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7508890985889484275U;
            aOrbiterH = RotL64((aOrbiterH * 17728368447504622035U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4407738164617959366U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17027017782352660454U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 417183060881259295U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3174658601748235285U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9779053567370714831U;
            aOrbiterF = RotL64((aOrbiterF * 6383245776181968033U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16256981360027888091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12778335633397105924U;
            aOrbiterG = RotL64((aOrbiterG * 10821225965811763659U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13985909343937844583U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14307218309393008729U;
            aOrbiterB = RotL64((aOrbiterB * 12053366452617039877U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15549857305890093491U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4259993311776766595U;
            aOrbiterJ = RotL64((aOrbiterJ * 13703695714360435719U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 50U) + aOrbiterB) + RotL64(aOrbiterG, 57U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + RotL64(aNonceWordD, 10U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + RotL64(aNonceWordG, 39U)) + aPhaseDWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 30U) + RotL64(aOrbiterE, 26U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 36U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + aPhaseDWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordG, 60U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 26594U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27015U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23224U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 27294U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 11U)) + 18319689184146942855U) + RotL64(aNonceWordF, 38U);
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 22U)) + 8041304130090501019U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 51U)) + 11347064191990897738U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 3U)) + 15242243470024447468U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 43U)) + 10619749107163611105U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 35U)) + 14795614276221947128U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 13U)) + 1578095288886372393U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 39U)) + 13593906305770501684U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 8919815528334599172U) + RotL64(aNonceWordG, 45U);
            aOrbiterK = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 17425548324720065145U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 24U)) + RotL64(aCarry, 27U)) + 11125018338392347335U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 3779189180734244399U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordD, 3U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10958224663276134041U;
            aOrbiterH = RotL64((aOrbiterH * 6206963519509783781U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4317305352561612995U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4891139433808505355U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11507024985663120317U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5166074784835930965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10080890270621589202U;
            aOrbiterI = RotL64((aOrbiterI * 13170894418184288695U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4501071771615514619U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6486573807774431753U;
            aOrbiterK = RotL64((aOrbiterK * 324029625116648669U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15714881857668975753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3506619392820235900U;
            aOrbiterA = RotL64((aOrbiterA * 5707033870161224499U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5295711072762443783U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11192836530396570648U;
            aOrbiterE = RotL64((aOrbiterE * 4361810118382207039U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7993389678399774574U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12551394763541226695U) ^ RotL64(aNonceWordH, 7U);
            aOrbiterF = RotL64((aOrbiterF * 11903486656172026403U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11553674370322129668U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 4459881583199320245U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2805857426321555685U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3053507713574219459U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15458441755058850309U;
            aOrbiterB = RotL64((aOrbiterB * 7296609957819165877U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17429750026356459756U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17114614857181230304U;
            aOrbiterC = RotL64((aOrbiterC * 10541235280918902739U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8958993884028672039U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18319689184146942855U;
            aOrbiterG = RotL64((aOrbiterG * 5430881344386342703U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 52U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterB, 26U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aNonceWordB, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterD, 23U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 54U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + RotL64(aNonceWordE, 43U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 40U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 44U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordE, 35U)) ^ RotL64(aNonceWordA, 46U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28436U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 31066U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordC, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29605U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 28463U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 10U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 9774364261626083532U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 35U)) + 18059001521926116420U) + RotL64(aNonceWordC, 47U);
            aOrbiterK = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 10615626210406381148U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 22U)) + 10536484278007898620U) + RotL64(aNonceWordD, 13U);
            aOrbiterH = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 13320663045139972700U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 47U)) + 17127001787268166583U) + aPhaseDOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 53U)) + 16742574590844166551U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 6U)) + 8347719720758228053U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 37U)) + 13502468705946051986U) + aPhaseDOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 11U)) + 3512687886188904904U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 57U)) + 495660316165795934U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5092722552034477356U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15641128019608284015U;
            aOrbiterK = RotL64((aOrbiterK * 3621036395703527059U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15421873776811085458U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17978775513204574125U;
            aOrbiterH = RotL64((aOrbiterH * 18359600395119440183U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16617179197537669849U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1931805387534012528U;
            aOrbiterI = RotL64((aOrbiterI * 3400139345857733775U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9544923119559308431U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12930999400470173353U;
            aOrbiterE = RotL64((aOrbiterE * 16791006919271490005U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13673733276226249890U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2032263473309124738U;
            aOrbiterD = RotL64((aOrbiterD * 3088728329261360607U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14868502349358414206U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10116495537187552321U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1380512121796709469U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5341113995358179244U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8415417980279705731U;
            aOrbiterB = RotL64((aOrbiterB * 8521501372683793821U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2462819265072352463U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7657062767608441931U;
            aOrbiterA = RotL64((aOrbiterA * 15554638801273540163U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8153420530633265789U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10990681417675210534U) ^ RotL64(aNonceWordB, 28U);
            aOrbiterJ = RotL64((aOrbiterJ * 1928509513380702895U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 17035995983178569271U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordG, 17U);
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2806563871848226777U;
            aOrbiterC = RotL64((aOrbiterC * 4137935663733587867U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6570698907081812011U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9774364261626083532U;
            aOrbiterF = RotL64((aOrbiterF * 1766375419340392741U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + RotL64(aNonceWordE, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterH, 3U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 60U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ) + RotL64(aNonceWordF, 27U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + aPhaseDWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterE, 39U));
            aWandererG = aWandererG + ((RotL64(aCross, 44U) + RotL64(aOrbiterC, 6U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 35U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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

void TwistExpander_Softball_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x89CC0C3D76137041ULL + 0xFE259E6DB8258B17ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBFAF101B0A118F4DULL + 0xDBDF9644B0461980ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x987173386A52D2CBULL + 0xB5A26932908D2B54ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA0A1EEA93DC57D67ULL + 0xC32F73A6A995DB68ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x87F53BDFF5C1AF6BULL + 0x8A505BDF2E864E24ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF4E3AC1024E63E4BULL + 0x8B65588187CB1FDDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBC8577F0F78AE959ULL + 0x9D494046BE393D20ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA1BE21A1953F692FULL + 0xE13BEB2AD6FD14D0ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordD, 58U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4080U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 499U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordC, 57U)) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 729U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 1652U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 3U)) + 3199575576585871314U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 23U)) + 2533378188975571824U;
            aOrbiterF = (aWandererD + RotL64(aCross, 27U)) + 6819782112558312658U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 47U)) + 12690060987724798497U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 34U)) + 7088375139715629606U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 41U)) + 17785618677423695666U) + RotL64(aNonceWordG, 55U);
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 51U)) + 1714999280296491277U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 17611338506932491624U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 6475727359297421201U) + RotL64(aNonceWordF, 13U);
            aOrbiterD = (aWandererA + RotL64(aCross, 20U)) + 2347744591204119530U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 2739317903351401068U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8663535261373274338U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 8205245127823536479U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13857005110466856439U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8916510616749754516U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3944805940148512932U;
            aOrbiterK = RotL64((aOrbiterK * 18082271583211389701U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14094751253118853302U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14094299829196076311U;
            aOrbiterG = RotL64((aOrbiterG * 6370012560657108493U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3940673811518673802U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3015106523254484839U;
            aOrbiterC = RotL64((aOrbiterC * 9655401190755573379U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15404103131982599922U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1828655763233900875U;
            aOrbiterJ = RotL64((aOrbiterJ * 13024358077740310049U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1236981890899916502U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18208975564570342697U;
            aOrbiterE = RotL64((aOrbiterE * 4577109989465876801U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17882273895471449661U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 16196010765612713713U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1]) ^ RotL64(aNonceWordA, 22U);
            aOrbiterA = RotL64((aOrbiterA * 15624856645134182005U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14639250100311162559U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9139027997336903273U;
            aOrbiterB = RotL64((aOrbiterB * 1853126389565574293U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16848571995585465845U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15901000078517800358U;
            aOrbiterH = RotL64((aOrbiterH * 11617866400577762383U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9405166641274108606U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6776079798531281127U;
            aOrbiterI = RotL64((aOrbiterI * 6914644957401512339U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 15056085197286596847U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordD, 19U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3199575576585871314U;
            aOrbiterD = RotL64((aOrbiterD * 15940936753708416817U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 20U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 50U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 56U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterH, 11U)) + RotL64(aNonceWordB, 49U)) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 14U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 26U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + RotL64(aNonceWordC, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererD, 50U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordC, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6610U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10582U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordF, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9971U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9426U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 38U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 23U)) + 3650233661228036955U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 47U)) + 11607036400067735729U;
            aOrbiterC = (aWandererF + RotL64(aCross, 53U)) + 3899614406903883035U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 51U)) + 8159156925629965143U) + aPhaseEOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 7148903913967261270U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 57U)) + 9161665622287517848U;
            aOrbiterD = (aWandererI + RotL64(aCross, 14U)) + 2981535013474059469U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 5U)) + 15812469008200319549U;
            aOrbiterG = (aWandererC + RotL64(aCross, 11U)) + 14687469489893270300U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 6025209349511417063U) + RotL64(aNonceWordA, 31U);
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 34U)) + RotL64(aCarry, 51U)) + 12964750392311112676U) + RotL64(aNonceWordH, 49U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6572355895765394340U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3542300121890027981U;
            aOrbiterC = RotL64((aOrbiterC * 11201491178181273935U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6477175684045398359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1081388388827929314U;
            aOrbiterE = RotL64((aOrbiterE * 8752188637514143529U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13754328481584620771U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3684673342659575917U;
            aOrbiterH = RotL64((aOrbiterH * 6139923312873039143U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6542045150319909445U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5352102692424060388U;
            aOrbiterD = RotL64((aOrbiterD * 7385758355501860261U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9110100774657340354U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2813273684436269057U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10468759062594022273U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5860425751137403755U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1598622981888978548U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 651816500461718345U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14710305692377606725U) + RotL64(aNonceWordB, 20U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16280545617802383463U;
            aOrbiterA = RotL64((aOrbiterA * 12541767206978802063U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6849565243667718750U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12152381961996750050U;
            aOrbiterJ = RotL64((aOrbiterJ * 11185935780063403807U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1318947876257794796U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5447559252769140391U;
            aOrbiterI = RotL64((aOrbiterI * 13683733413554766327U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2766869582494246454U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15757729967222729304U;
            aOrbiterB = RotL64((aOrbiterB * 1858683399257513171U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 13063432816787882618U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3650233661228036955U) ^ RotL64(aNonceWordC, 45U);
            aOrbiterF = RotL64((aOrbiterF * 16230564672533821641U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 28U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 29U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 22U)) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 3U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 39U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 19U)) + aOrbiterA) + RotL64(aNonceWordE, 7U));
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 37U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + RotL64(aNonceWordD, 53U));
            aWandererG = aWandererG + ((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 54U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 51U) ^ RotL64(aNonceWordD, 40U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13586U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13681U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 46U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordB, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12216U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13079U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCross, 51U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 7825479804710770560U;
            aOrbiterC = (aWandererG + RotL64(aCross, 44U)) + 5298124167101358123U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 53U)) + 17774541024369233726U) + RotL64(aNonceWordE, 29U);
            aOrbiterF = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 7679371833537454082U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 11U)) + 5385914900748772224U) + RotL64(aNonceWordA, 3U);
            aOrbiterD = (aWandererE + RotL64(aScatter, 35U)) + 3879781930908486531U;
            aOrbiterG = (aWandererC + RotL64(aCross, 13U)) + 659110346638873236U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 4U)) + 10749021728538539749U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 29U)) + 3631252455767429457U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 2271978810960685021U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 41U)) + 5963558780692551176U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 974909966119198104U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9296998242911152296U;
            aOrbiterB = RotL64((aOrbiterB * 2613629915877957661U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2245318466901521959U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13391076374843288568U;
            aOrbiterD = RotL64((aOrbiterD * 18094558036982107419U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6184487746594236737U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1563385912137291418U) ^ RotL64(aNonceWordC, 9U);
            aOrbiterC = RotL64((aOrbiterC * 4805455299959232321U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1744840092006498629U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2100927276837188416U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3541788262067077997U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9998911862807246338U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12239948725635220096U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7098620484129489129U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3307447094994950246U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 12746613971448298932U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9463975886346934681U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11577488293733790649U) + RotL64(aNonceWordH, 40U);
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 191108997585598809U;
            aOrbiterK = RotL64((aOrbiterK * 9574978681405356871U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18096145693841273722U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10026281133603934071U;
            aOrbiterF = RotL64((aOrbiterF * 17261343107314203471U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2346682418062064668U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2996178204018644206U;
            aOrbiterG = RotL64((aOrbiterG * 2552965800703390909U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15085425896818988223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1589593231782852588U;
            aOrbiterH = RotL64((aOrbiterH * 1535556765195388675U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17170695588248383518U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7825479804710770560U;
            aOrbiterJ = RotL64((aOrbiterJ * 7434218282170150533U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 6U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + aPhaseEWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 18U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 10U)) + RotL64(aNonceWordF, 25U));
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterB, 29U));
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG) + RotL64(aNonceWordG, 61U));
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 41U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 14U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20739U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17808U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17759U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19319U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 39U)) + 4476099022490972343U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 10U)) + 16836423700375760429U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 29U)) + 8850577488928703557U;
            aOrbiterI = (aWandererE + RotL64(aCross, 37U)) + 7091631824560042743U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 13U)) + 12560498899956759494U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 57U)) + 7797973377112012161U) + aPhaseEOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordB, 49U);
            aOrbiterE = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 6173820673874805794U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 10805025132310245348U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 27U)) + 7139216143268029968U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 8241544862261635722U) + RotL64(aNonceWordF, 26U);
            aOrbiterG = (aWandererA + RotL64(aIngress, 48U)) + 4735527016563596150U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5166171126690294033U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11117641762075368393U) ^ RotL64(aNonceWordC, 13U);
            aOrbiterC = RotL64((aOrbiterC * 4980156869201219393U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6312932356458415421U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1304139291184508668U;
            aOrbiterB = RotL64((aOrbiterB * 90744653170922319U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10085025354842771067U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16745854428789531080U;
            aOrbiterJ = RotL64((aOrbiterJ * 1945983905747274355U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2497187958708890337U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16069701876646548995U;
            aOrbiterE = RotL64((aOrbiterE * 16606039730973709495U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17242004368025978091U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 12334315722243232121U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16528598396696346719U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8007042082518126895U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5665686359038811484U;
            aOrbiterD = RotL64((aOrbiterD * 11289316305875751813U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3913477186958600592U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16918984318564170343U;
            aOrbiterF = RotL64((aOrbiterF * 5128293326494417281U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10227611546502931418U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7187623463085447228U;
            aOrbiterG = RotL64((aOrbiterG * 8479839369622163181U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16655159122037336519U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9844145011519243346U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16512883184116277583U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8660130685326542506U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16192687259641294851U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2882649237163668499U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15208432734447317310U) + RotL64(aNonceWordE, 9U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4476099022490972343U;
            aOrbiterI = RotL64((aOrbiterI * 7447168142776253041U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 60U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordA, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + RotL64(aNonceWordG, 59U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterA, 51U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterH, 46U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordA, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26556U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26067U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordE, 35U)) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23895U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 26369U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 43U)) + 9133751643283278896U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 5U)) + 8971581804375380408U) + RotL64(aNonceWordF, 25U);
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 11U)) + 12559650383714566592U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 54U)) + RotL64(aCarry, 51U)) + 15753206088872859163U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 7640756270450762350U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 47U)) + 7340073357551376125U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 29U)) + 5270256573644196046U;
            aOrbiterI = (aWandererH + RotL64(aCross, 37U)) + 3567367996479995928U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 39U)) + 11939634537492733738U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 7051817732424527120U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 14U)) + 1730487669951837941U) + RotL64(aNonceWordA, 59U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 18009252467909454817U) + RotL64(aNonceWordC, 53U);
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2361024272031696442U;
            aOrbiterC = RotL64((aOrbiterC * 15215151562500226027U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15902755877642960397U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12243517544704116184U;
            aOrbiterD = RotL64((aOrbiterD * 2576071074148141447U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16846181962302186187U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 636121425116506681U;
            aOrbiterI = RotL64((aOrbiterI * 17075030673338779993U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6887385655828217318U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3705834550934775862U;
            aOrbiterF = RotL64((aOrbiterF * 11275428284929594435U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11165142437077969438U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6426659930331618269U;
            aOrbiterJ = RotL64((aOrbiterJ * 17170640810530893705U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12629082390899315789U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4277510580069574724U;
            aOrbiterA = RotL64((aOrbiterA * 9829125163412708305U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13814834144170469978U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3698381854100295826U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5126359230872258015U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11623170635983579937U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7247413650388803796U) ^ RotL64(aNonceWordB, 13U);
            aOrbiterE = RotL64((aOrbiterE * 3403219499465560059U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3129755194359521145U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4081016725582134919U;
            aOrbiterG = RotL64((aOrbiterG * 11564414998539605389U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15878346077922215753U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2974440187796944059U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 783253926537018373U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3922344163443096356U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9133751643283278896U;
            aOrbiterK = RotL64((aOrbiterK * 16887991698415418429U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 14U);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterA, 14U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 29U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 11U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterK, 3U)) + RotL64(aNonceWordH, 29U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 12U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 48U)) + aOrbiterC) + RotL64(aNonceWordG, 20U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordD, 23U)) ^ RotL64(aNonceWordF, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31484U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32232U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 14U) ^ RotL64(aNonceWordB, 37U)) ^ RotL64(aNonceWordH, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28163U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 30257U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 29U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aScatter, 41U)) + 12692813903177772178U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 39U)) + 7112496446691277899U;
            aOrbiterB = (aWandererA + RotL64(aCross, 47U)) + 2112247138290568813U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 12U)) + 3699421080882855947U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 13761832028354380922U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 9243822514887600214U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 5U)) + 6863833516853046129U) + RotL64(aNonceWordF, 47U);
            aOrbiterI = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 8863897995943098018U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 60U)) + 13346785686701467520U) + aPhaseEOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 21U)) + 15309543066305531619U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 51U)) + 17515530938817919111U) + RotL64(aNonceWordH, 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 760493237816424254U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7282586354117620860U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2327153408185290635U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4129706068526969105U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7020175432730888755U;
            aOrbiterK = RotL64((aOrbiterK * 10095158356907592239U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9102258982216515596U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10822031305361453690U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2036205056490578491U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12571477440964330246U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8436347026653095199U) ^ RotL64(aNonceWordG, 46U);
            aOrbiterC = RotL64((aOrbiterC * 17930734781213681573U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14214789872073941940U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12915911919403385001U;
            aOrbiterI = RotL64((aOrbiterI * 13161681603528031511U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15443240166233851298U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7311369180113240915U;
            aOrbiterJ = RotL64((aOrbiterJ * 13339195007946889423U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12976516224995960015U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7823308381434556721U;
            aOrbiterF = RotL64((aOrbiterF * 502385172763861451U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4829417661664149137U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16306394751966719700U;
            aOrbiterG = RotL64((aOrbiterG * 5294376579588592157U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16769868341852572677U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7107433163189177642U;
            aOrbiterA = RotL64((aOrbiterA * 5279050651595743649U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11896784111967113871U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 389626690429371003U;
            aOrbiterE = RotL64((aOrbiterE * 10665914532159182181U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8226849597052979358U) + RotL64(aNonceWordE, 11U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12692813903177772178U;
            aOrbiterD = RotL64((aOrbiterD * 17909062471564422847U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 14U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 46U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + RotL64(aNonceWordB, 27U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aCross, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 23U)) + RotL64(aNonceWordA, 61U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aCross, 50U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 26U));
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererK, 54U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Softball_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x80523D4075204575ULL + 0xBDABEB6B6073A97AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEE8255D276599F01ULL + 0xA9BDF613DA91DD71ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9153BF32EFDD550FULL + 0xB7B08ABEA1B9A7B8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAEDC8F89502EF69DULL + 0xB46EFF3886A80F15ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDDE46001A1232B3FULL + 0xDC53393AC93EB0E9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBA7EA19E0EAED4CDULL + 0xD3676AB3612AFF7FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC7A7CD9F084EFFEDULL + 0xAACE4FF6E3D7BD3FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8739FBF9AE490BDBULL + 0x9B0A786F3C526BAAULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 50U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2389U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 3739U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4414U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 3253U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 12122689833405846292U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 9640400270962766788U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 9141937998266739071U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 43U)) + 12899395770434090537U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 37U)) + 13457918115408031842U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 60U)) + 15134784483576000943U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 51U)) + 12540961268790055438U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 39U)) + 6306886773092764230U) + RotL64(aNonceWordC, 49U);
            aOrbiterH = ((aWandererA + RotL64(aScatter, 19U)) + 13573343491337243121U) + RotL64(aNonceWordD, 17U);
            aOrbiterB = (aWandererC + RotL64(aIngress, 10U)) + 8545588657348974413U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 53U)) + 10891410570357275120U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2877137119767060151U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9178097682386595144U;
            aOrbiterE = RotL64((aOrbiterE * 3524486002084427513U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15528007881855616978U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11368419529245281435U;
            aOrbiterF = RotL64((aOrbiterF * 12433207037378339309U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5932738914934356645U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5551842263864055419U;
            aOrbiterA = RotL64((aOrbiterA * 16093776759971522681U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3824433359595690603U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17184628855571662441U;
            aOrbiterC = RotL64((aOrbiterC * 691208053136187317U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8724462245014132623U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7481349499528092352U;
            aOrbiterJ = RotL64((aOrbiterJ * 8212182934509617583U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6908362960248294718U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5354057969992655314U;
            aOrbiterH = RotL64((aOrbiterH * 16586084885820679343U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 11138301629323903147U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordE, 23U);
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14164180536320940750U;
            aOrbiterK = RotL64((aOrbiterK * 9099767681053390287U), 39U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 709942920176922902U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordH, 47U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17128241237359414945U;
            aOrbiterI = RotL64((aOrbiterI * 14063385518459963529U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6760410778228957309U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15333948259759012363U;
            aOrbiterD = RotL64((aOrbiterD * 3685416414008280787U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6929136132517755104U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13833415487953533365U;
            aOrbiterG = RotL64((aOrbiterG * 14860437994758579635U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16143046377679975216U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12122689833405846292U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 227699085983424155U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterG, 24U)) + RotL64(aNonceWordA, 40U));
            aWandererF = aWandererF + (((RotL64(aCross, 22U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 39U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 3U)) + aOrbiterC) + RotL64(aNonceWordG, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterG, 5U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterF, 28U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 44U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordB, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8234U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((aIndex + 6318U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordD, 41U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7293U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 9218U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 26U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 51U)) + 9080426856729228705U) + RotL64(aNonceWordA, 45U);
            aOrbiterH = (((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 11U)) + 7851218321653539276U) + RotL64(aNonceWordC, 28U);
            aOrbiterF = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 7023344692919298036U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 39U)) + 9772846154227440734U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 21U)) + 12008298632429608431U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 12201090455849562875U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 47U)) + 9498721803411445471U) + aPhaseFOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aScatter, 60U)) + 351203764023093632U;
            aOrbiterD = (aWandererK + RotL64(aCross, 19U)) + 4966360430644539250U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 37U)) + 9194167899071345693U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 41U)) + 4922477697284269116U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15742625291642356429U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7528703106518431730U;
            aOrbiterF = RotL64((aOrbiterF * 11530049278751507567U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15279053574704935317U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2425839793660355555U;
            aOrbiterH = RotL64((aOrbiterH * 11486964816849830667U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13209849392400008898U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9041500097716231309U;
            aOrbiterK = RotL64((aOrbiterK * 340661035700748739U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7885423750878814599U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1992993999902904603U;
            aOrbiterI = RotL64((aOrbiterI * 1478629826632201617U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6120758615019314102U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8529621625846992066U;
            aOrbiterD = RotL64((aOrbiterD * 8485991471612862467U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9125182130757385320U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15691232622970220043U) ^ RotL64(aNonceWordD, 5U);
            aOrbiterJ = RotL64((aOrbiterJ * 16517916951054758147U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11413090085435424697U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11563151001080914939U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16828196274450408201U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1778975369262558069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3232132443557192010U;
            aOrbiterB = RotL64((aOrbiterB * 17132823737792200981U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 277456309842614908U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10470076566806421600U;
            aOrbiterG = RotL64((aOrbiterG * 7526503789282158285U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12466953663713418197U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15871548472936716844U;
            aOrbiterA = RotL64((aOrbiterA * 11788139245249205765U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12322317028530419228U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 9080426856729228705U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ RotL64(aNonceWordH, 57U);
            aOrbiterE = RotL64((aOrbiterE * 4204042134412769955U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 51U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterK) + RotL64(aNonceWordG, 37U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterI, 42U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterC, 23U));
            aWandererK = aWandererK + ((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterD, 13U));
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 6U)) + aOrbiterD) + RotL64(aNonceWordE, 9U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + ((RotL64(aCross, 48U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordE, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16035U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14521U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordF, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15591U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14625U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 22U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aCross, 19U)) + 16183871922837164759U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 51U)) + 7002058258090219055U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 48U)) + RotL64(aCarry, 39U)) + 5650868611888303705U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 27U)) + 11899839660943876690U) + RotL64(aNonceWordA, 59U);
            aOrbiterJ = (aWandererG + RotL64(aIngress, 43U)) + 15349649504488111111U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 3U)) + 14060149569086744970U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 13U)) + 12920917574225030112U) + RotL64(aNonceWordB, 28U);
            aOrbiterF = (((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 2831994965175330135U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 18312543585028439192U;
            aOrbiterB = (aWandererF + RotL64(aCross, 29U)) + 11657562205118394239U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 60U)) + 10850792819281246052U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17810371216216125323U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7963413941144223128U;
            aOrbiterD = RotL64((aOrbiterD * 534217972450595401U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5498715358793875584U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9256727548911651373U;
            aOrbiterI = RotL64((aOrbiterI * 10498848323914000989U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17246360111302191699U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 18309978718113983369U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18267472694666221077U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3100998994319502921U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8129301860291235970U;
            aOrbiterJ = RotL64((aOrbiterJ * 17847033539279176187U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1889641029473279114U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16538494307002917945U;
            aOrbiterF = RotL64((aOrbiterF * 8081488217920885783U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5432230549146849322U) + RotL64(aNonceWordG, 45U);
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2634437941396090817U;
            aOrbiterB = RotL64((aOrbiterB * 7612999214758935211U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16940172599174185058U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13151669140593952203U;
            aOrbiterK = RotL64((aOrbiterK * 16225319638131723487U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3995064294869931681U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 913081077665768816U;
            aOrbiterG = RotL64((aOrbiterG * 9299514648768060453U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2469001696075411481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2167390955194185443U;
            aOrbiterH = RotL64((aOrbiterH * 11805065572289005223U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1574066406534010796U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 8736976961589874013U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ RotL64(aNonceWordD, 23U);
            aOrbiterC = RotL64((aOrbiterC * 5980070607180321955U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4233621443153132083U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16183871922837164759U;
            aOrbiterA = RotL64((aOrbiterA * 4030569514959370895U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterB, 24U)) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 36U)) + aOrbiterH) + RotL64(aNonceWordE, 43U));
            aWandererB = aWandererB + ((RotL64(aScatter, 52U) + aOrbiterH) + RotL64(aOrbiterE, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + RotL64(aNonceWordH, 51U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 50U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordB, 53U)) ^ RotL64(aNonceWordF, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18956U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 17687U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordE, 4U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19065U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20523U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 18U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aPrevious, 29U)) + 8685374557928800912U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 3U)) + 3482312691892161229U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 36U)) + RotL64(aCarry, 37U)) + 6948130297389161165U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 39U)) + 5506385663788942690U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 17859982009307397161U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 9178488809207094043U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 58U)) + 1835479501226057169U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 43U)) + 5368101733632614939U) + RotL64(aNonceWordB, 53U);
            aOrbiterK = (aWandererK + RotL64(aCross, 13U)) + 9050459666576835422U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 21U)) + 9042186993119635078U) + aPhaseFOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 53U)) + 17528342580198295025U) + RotL64(aNonceWordD, 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6495418332558436882U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8834495762667327342U;
            aOrbiterB = RotL64((aOrbiterB * 10783141541937645995U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4364314196965690905U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6357485231062120459U;
            aOrbiterC = RotL64((aOrbiterC * 289429584586504995U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3321488322626415347U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10817330671781848737U) ^ RotL64(aNonceWordC, 35U);
            aOrbiterE = RotL64((aOrbiterE * 15875919466358823335U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17974092279281611763U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2871472057292789157U;
            aOrbiterG = RotL64((aOrbiterG * 16104199340711015181U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15187929795092006849U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13482063681546475923U;
            aOrbiterH = RotL64((aOrbiterH * 14466266308157364963U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6232152545071397380U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17488906002621373262U) ^ RotL64(aNonceWordH, 58U);
            aOrbiterK = RotL64((aOrbiterK * 4719340606442742577U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12444819880507588549U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13808941689757772497U;
            aOrbiterF = RotL64((aOrbiterF * 6541360905282412317U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8049361354387692374U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7137831335606542401U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11022231291507235007U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7230759462019420058U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3923744511976096944U;
            aOrbiterA = RotL64((aOrbiterA * 9953869624243563101U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15967667946023263856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8677583624693910669U;
            aOrbiterJ = RotL64((aOrbiterJ * 10737731876339973717U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1604347321263511013U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8685374557928800912U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14103365695918844461U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterD, 6U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterK, 41U)) + aPhaseFWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterE, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 19U));
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 21U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + RotL64(aNonceWordE, 13U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordF, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 10U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordE, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22703U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 24630U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 58U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22410U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22123U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 11039986441331892533U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 23U)) + 6256024955965426119U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 9857443189988995666U;
            aOrbiterH = (aWandererA + RotL64(aCross, 35U)) + 11900944813380998208U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 19U)) + 8422577734978875541U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 3U)) + 3100835100713928724U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 5U)) + 11871553509810206993U) + aPhaseFOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordD, 13U);
            aOrbiterF = (aWandererH + RotL64(aPrevious, 57U)) + 17614749493763417027U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 3638372131856199916U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 52U)) + 6582275259281025770U) + RotL64(aNonceWordB, 21U);
            aOrbiterK = (aWandererF + RotL64(aPrevious, 29U)) + 17016882418498941958U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1747214688658984715U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9356088987044015278U;
            aOrbiterB = RotL64((aOrbiterB * 16221733545319753695U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4056238112133473456U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16013150119949532998U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12913648646318115315U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16076621211111834889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9940824359571581765U;
            aOrbiterF = RotL64((aOrbiterF * 11624767861336495331U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15624084004784515753U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7630989544834680335U;
            aOrbiterE = RotL64((aOrbiterE * 12261063237156822067U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18003586430673313786U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1654118743290334161U;
            aOrbiterJ = RotL64((aOrbiterJ * 1153250137357176071U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3254189676528343910U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15629083361573065165U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17024833368570949107U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10056859810555674806U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15976683222786846254U;
            aOrbiterI = RotL64((aOrbiterI * 2801754232182942635U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11872378594829637933U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7633773773528713489U;
            aOrbiterC = RotL64((aOrbiterC * 8218288492011593353U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16305188578382203720U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13293036594949754170U;
            aOrbiterK = RotL64((aOrbiterK * 1300645662609848183U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15185013801659166674U) + RotL64(aNonceWordG, 17U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11562899709899198100U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9115495024409604629U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1525205566739385260U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11039986441331892533U) ^ RotL64(aNonceWordF, 36U);
            aOrbiterD = RotL64((aOrbiterD * 9802284050237622047U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 36U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterD, 10U));
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterH, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterB, 28U)) + RotL64(aNonceWordE, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 53U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 3U)) + RotL64(aNonceWordC, 15U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordE, 20U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29770U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32647U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31673U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32183U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 36U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aPrevious, 35U)) + 14008824488073394623U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 41U)) + 13317978415866411468U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 21U)) + 13209180141897453900U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 29U)) + 11870521586865233578U;
            aOrbiterD = (aWandererF + RotL64(aCross, 46U)) + 8052156380448047385U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 12158131176743680605U) + RotL64(aNonceWordH, 7U);
            aOrbiterH = (aWandererA + RotL64(aScatter, 27U)) + 14674467487607719347U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 39U)) + 18055496790566231147U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 48U)) + RotL64(aCarry, 47U)) + 3838105585041578784U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 57U)) + 2839568255183054418U) + RotL64(aNonceWordF, 25U);
            aOrbiterA = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 11933612922864258179U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6289849094151630580U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2640344350528492271U;
            aOrbiterB = RotL64((aOrbiterB * 16197726750829369365U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16306175266267657791U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3339898380394883600U;
            aOrbiterD = RotL64((aOrbiterD * 7105436590182982373U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15017076663742800002U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8973064296077602496U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9309462227233615761U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17580319233338139859U) + RotL64(aNonceWordD, 57U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14063208878807603874U;
            aOrbiterH = RotL64((aOrbiterH * 16601475239075164585U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13326130855721009942U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12843186026737544416U;
            aOrbiterI = RotL64((aOrbiterI * 4975848122837321619U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14102887715772847499U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14495942314329085733U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4236795312917583565U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11564857125101669667U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17435970784822000464U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1472691848852381173U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16561390130356833062U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9952805588514363872U;
            aOrbiterA = RotL64((aOrbiterA * 3720874990001086597U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8246822023509690545U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 305480212301772662U;
            aOrbiterF = RotL64((aOrbiterF * 4295787267516476485U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11729872285756639125U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9669174142543613799U) ^ RotL64(aNonceWordC, 24U);
            aOrbiterJ = RotL64((aOrbiterJ * 9443240779947114779U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7653344907616923293U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14008824488073394623U;
            aOrbiterE = RotL64((aOrbiterE * 8362849599309360823U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterF, 46U)) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + RotL64(aCarry, 41U)) + RotL64(aNonceWordG, 45U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterK, 11U));
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + RotL64(aNonceWordA, 59U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterE, 41U));
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterI, 39U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 34U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Softball_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFEA25505E167596BULL + 0xC1DED0F9BC30F80EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9AD02F6B5742A6E3ULL + 0x88A32E084DF240DDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF5EC3D30772505ADULL + 0xF42B77901F3B56E4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x89E370DEFB84AFDFULL + 0x93DE12040E9AFA1BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF65594022AD4952DULL + 0xA0511FA51C9DBF59ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAEF1547CFB8A630BULL + 0xAE150B8FD47E5A18ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA7343A00F90CBE4FULL + 0xADAF2E7530E1A7B5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBFA2A071C8A1DD7BULL + 0xDDD050BF1B56A29BULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordE, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1515U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 3712U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordB, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1818U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 3835U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 20U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 11410829607777684449U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 13U)) + 7502698839700975347U) + RotL64(aNonceWordA, 19U);
            aOrbiterB = (aWandererJ + RotL64(aIngress, 21U)) + 13267685058252106173U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 19U)) + 238242706996630625U;
            aOrbiterE = (aWandererD + RotL64(aCross, 50U)) + 8184695499511454281U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 23U)) + 12767823220461985403U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 12293198423143850330U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 11149495229952495939U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 52U)) + 7556992689338382800U) + aPhaseFOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 47U)) + 3431338808774134649U) + RotL64(aNonceWordC, 23U);
            aOrbiterF = ((aWandererK + RotL64(aIngress, 41U)) + 16863099140844995099U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17872458049880677604U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16760153457252546974U;
            aOrbiterB = RotL64((aOrbiterB * 11225037229069712805U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3115544493537438408U) + RotL64(aNonceWordB, 21U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4359882942759752958U;
            aOrbiterI = RotL64((aOrbiterI * 561477566995575801U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13387113067202396536U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12955690074544490161U;
            aOrbiterC = RotL64((aOrbiterC * 12449941770827974511U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15614054443728226807U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1939441328066616114U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4484917074808974359U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4599016263007782537U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9962305629016158048U;
            aOrbiterJ = RotL64((aOrbiterJ * 1496184427500037279U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8428467674122750557U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3938884087806393439U;
            aOrbiterA = RotL64((aOrbiterA * 12810531094050481761U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6018636830758044658U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1510372000641305416U;
            aOrbiterF = RotL64((aOrbiterF * 9002834928626918247U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17592782466215337843U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8119921507606870360U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1299795061644535485U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8753237702359236964U) + RotL64(aNonceWordG, 22U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12389957327067768090U;
            aOrbiterE = RotL64((aOrbiterE * 4586786761936601607U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17791633199762408683U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11606494383812053915U;
            aOrbiterH = RotL64((aOrbiterH * 13041480602055778521U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4418614662439151979U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11410829607777684449U;
            aOrbiterK = RotL64((aOrbiterK * 3342270212301058781U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterK, 48U));
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 50U) + aOrbiterI) + RotL64(aOrbiterE, 14U)) + RotL64(aNonceWordH, 49U));
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 4U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 12U) ^ RotL64(aNonceWordD, 37U)) ^ RotL64(aNonceWordE, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8198U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7812U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordH, 58U)) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9714U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 7436U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 60U)) + 6342299552323486695U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 13U)) + 12692748514781367538U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 27U);
            aOrbiterI = (aWandererB + RotL64(aScatter, 47U)) + 8202639945493229155U;
            aOrbiterC = (aWandererH + RotL64(aCross, 37U)) + 4439975701793231639U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 16774235182859553759U) + RotL64(aNonceWordG, 57U);
            aOrbiterD = (aWandererI + RotL64(aPrevious, 44U)) + 8764155413335405667U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 5U)) + 7167848811974967685U;
            aOrbiterH = (aWandererC + RotL64(aCross, 29U)) + 16768278912125334220U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 53U)) + 9090838954826296201U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 7644075729758006298U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 17326182797908071215U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16158809721888137555U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8029938783858263694U;
            aOrbiterI = RotL64((aOrbiterI * 12628072435324195483U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8716553521415553404U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7012599977009208840U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8775355876188948851U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13250558696578541499U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13705957059101025396U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16889495686487056367U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2796775206291902461U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13741676263512390669U;
            aOrbiterF = RotL64((aOrbiterF * 10455782033465595947U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1691908360612389252U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4114939415206031540U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2797401802892718297U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2374911514440738727U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12377616933668803091U;
            aOrbiterJ = RotL64((aOrbiterJ * 2505164835116651215U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 681094033415259645U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13841322124900463362U;
            aOrbiterC = RotL64((aOrbiterC * 4210414203856902329U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18082983557580381338U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15731122225678626778U;
            aOrbiterD = RotL64((aOrbiterD * 7785999919955613789U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2084336993254383330U) + RotL64(aNonceWordH, 4U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3600882019682875370U;
            aOrbiterH = RotL64((aOrbiterH * 2977569829649654329U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11436602278656592334U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5775886971784627864U;
            aOrbiterB = RotL64((aOrbiterB * 6765942246225582787U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17120308925134658794U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 6342299552323486695U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ RotL64(aNonceWordD, 21U);
            aOrbiterA = RotL64((aOrbiterA * 5788669985396507227U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 50U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 42U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterH) + RotL64(aNonceWordA, 45U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + RotL64(aNonceWordF, 43U));
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 21U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterB, 38U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 38U) ^ RotL64(aNonceWordE, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11898U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 11051U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15937U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 16335U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 52U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 35U)) + 5576732410244514238U) + RotL64(aNonceWordG, 61U);
            aOrbiterK = (aWandererG + RotL64(aScatter, 24U)) + 2833808925935929629U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 51U)) + 3670188682914544792U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 43U)) + 15759072378887814995U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 13934007231137439994U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 11022225696007690512U) + aPhaseFOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + 16989177104453635790U) + RotL64(aNonceWordE, 35U);
            aOrbiterD = (aWandererC + RotL64(aIngress, 11U)) + 9256930045263527091U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + 17788596104417068290U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 17044369456673337625U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 58U)) + 1310908395523250343U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12067065689034065422U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15130844248737512262U;
            aOrbiterE = RotL64((aOrbiterE * 9409499577465934107U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14532689204495587494U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8198147292120244178U) ^ RotL64(aNonceWordH, 52U);
            aOrbiterJ = RotL64((aOrbiterJ * 1418356389507740991U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5485494458627163347U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10830008207150307611U;
            aOrbiterK = RotL64((aOrbiterK * 6526039534042499457U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17770065502486618029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6397859353395335459U;
            aOrbiterI = RotL64((aOrbiterI * 14286997752368893825U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5128700697381508319U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7103394110057060499U;
            aOrbiterD = RotL64((aOrbiterD * 5053680689949149633U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16024401282261796979U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12818445221897253410U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11450004517784155405U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13386978409145916350U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16740821954556699503U;
            aOrbiterB = RotL64((aOrbiterB * 5376430209628515105U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 313978038530994953U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1355733685461795345U;
            aOrbiterH = RotL64((aOrbiterH * 15955927322082619735U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12590581077253956064U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2298195367575496005U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17512801361187006363U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 11847450675712272468U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordB, 55U);
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5914296379577670282U;
            aOrbiterA = RotL64((aOrbiterA * 14574813500616811367U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16901317262621287065U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5576732410244514238U;
            aOrbiterC = RotL64((aOrbiterC * 4514943876091531567U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 46U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 4U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterA, 21U)) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterB, 6U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + RotL64(aNonceWordF, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterF, 23U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 30U) + aOrbiterK) + RotL64(aOrbiterI, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 19U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterK, 60U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 26U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordA, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21043U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20155U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordC, 6U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21838U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16904U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 54U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 5173905450211892891U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 19U)) + 3555542451908039957U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 14U)) + 11559884700283861559U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 1352524329968738673U) + RotL64(aNonceWordB, 24U);
            aOrbiterE = (aWandererK + RotL64(aIngress, 5U)) + 8914206450420616349U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 51U)) + 2251523378498463946U) + RotL64(aNonceWordD, 47U);
            aOrbiterA = (aWandererA + RotL64(aPrevious, 23U)) + 9541575923299247038U;
            aOrbiterH = (aWandererB + RotL64(aCross, 43U)) + 1239854507907214595U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 54U)) + 17698101462598498934U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 12305566971683256060U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 3U)) + 13804545036303215569U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10239749097704329264U) + RotL64(aNonceWordF, 57U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4212214906286320308U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3661436621615751071U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12192418916967430783U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4475514289326450361U;
            aOrbiterE = RotL64((aOrbiterE * 17497164630368757887U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17376102613298827459U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18129393209955439341U;
            aOrbiterI = RotL64((aOrbiterI * 6404089025014118979U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4014763724300253568U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17325007199676828814U;
            aOrbiterA = RotL64((aOrbiterA * 1420888274815627083U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15480474849292388685U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14357924730184375449U;
            aOrbiterH = RotL64((aOrbiterH * 16723492259068034209U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4335731868597970070U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8296023680394303015U;
            aOrbiterG = RotL64((aOrbiterG * 14027415401430120543U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2807312426993262800U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15510369660839648501U;
            aOrbiterD = RotL64((aOrbiterD * 18207954408298333959U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12597844696606519907U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7231012798553551535U;
            aOrbiterK = RotL64((aOrbiterK * 2841306785994479299U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 849663631945232360U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4002310581470781194U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2148877014350721479U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16067735571435654555U) + RotL64(aNonceWordE, 5U);
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4607980694199923842U;
            aOrbiterB = RotL64((aOrbiterB * 10401780756830017477U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5346879191913449715U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 5173905450211892891U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15360571827429301833U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterD, 53U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 39U)) + aOrbiterA) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterB, 10U)) + RotL64(aNonceWordA, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterK, 41U));
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + aPhaseFWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterI, 57U));
            aWandererE = aWandererE + ((((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordG, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterK, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25641U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 27121U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27124U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((aIndex + 26149U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 43U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 30U)) + 3684295017013759987U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 35U)) + 6740408842457292881U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 47U)) + 4563975890702399441U;
            aOrbiterG = (aWandererD + RotL64(aCross, 43U)) + 797804144825287940U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 51U)) + 2763779540450101303U) + aPhaseFOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 22U)) + 13211846164102089685U) + RotL64(aNonceWordB, 6U);
            aOrbiterD = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 15214578447281401982U;
            aOrbiterA = (aWandererG + RotL64(aCross, 5U)) + 13745208628754232427U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 53U)) + 17358621225969190747U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 779739369960480023U) + RotL64(aNonceWordE, 39U);
            aOrbiterH = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 4370963533701407813U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6061333005507739975U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3589705340762734456U;
            aOrbiterI = RotL64((aOrbiterI * 16499293983611196967U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10607697666369230567U) + RotL64(aNonceWordD, 7U);
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9356757995305239271U;
            aOrbiterK = RotL64((aOrbiterK * 10945513661439954731U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10093033335903048138U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11037328061699834100U;
            aOrbiterA = RotL64((aOrbiterA * 11189760551792389605U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 558431161176115540U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17795680919453449358U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3910117359996283803U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6096779391116214109U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17594243286880690775U;
            aOrbiterC = RotL64((aOrbiterC * 12655610181937429915U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 15414704802398002423U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 18040588240488602196U) ^ RotL64(aNonceWordH, 15U);
            aOrbiterG = RotL64((aOrbiterG * 16344249573086571225U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14636298592697156931U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9677305688594936561U;
            aOrbiterD = RotL64((aOrbiterD * 8354776999961642997U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16408025751875050713U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10018342878801454965U;
            aOrbiterE = RotL64((aOrbiterE * 10349132962708124117U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1841090936357114866U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16142637455878447020U;
            aOrbiterH = RotL64((aOrbiterH * 10565394571714418033U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4089676582910615502U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8749600984499831109U;
            aOrbiterB = RotL64((aOrbiterB * 3421055105090316521U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11408932421005107097U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3684295017013759987U;
            aOrbiterF = RotL64((aOrbiterF * 7037953759624065417U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH + ((((RotL64(aCross, 60U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 46U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterH, 43U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + RotL64(aNonceWordG, 37U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterA, 39U)) + RotL64(aNonceWordC, 49U)) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 44U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 34U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32318U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30471U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordG, 53U)) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28073U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31712U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 13880995121909552664U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 21U)) + 14534942818069300546U) + RotL64(aNonceWordE, 5U);
            aOrbiterF = (aWandererJ + RotL64(aIngress, 53U)) + 17745973100886007133U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 3U)) + 2249805580771946872U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 4460116116396439410U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 18U)) + 3378683994078106878U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 47U)) + 3992996501048809123U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 41U)) + 12057768808864451929U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 35U)) + 4115362079047921130U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 15297384955502206698U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 23U)) + 17623548383481905636U) + RotL64(aNonceWordG, 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3559213898000162417U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12311605719074507335U;
            aOrbiterF = RotL64((aOrbiterF * 3982199462062847697U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14807313864347885885U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11222085523291581822U;
            aOrbiterA = RotL64((aOrbiterA * 12580941911587215653U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 916681229436292462U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2441350114032314686U;
            aOrbiterC = RotL64((aOrbiterC * 7336079498999018067U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7361470539894653271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12153585147213579808U;
            aOrbiterH = RotL64((aOrbiterH * 3040327545467672961U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13566300726101613579U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14875254144748509128U;
            aOrbiterB = RotL64((aOrbiterB * 13699179902908972403U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9268158535644002904U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14144295981814993491U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12739937231684038161U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13861225650900541642U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12620513474052058164U) ^ RotL64(aNonceWordH, 7U);
            aOrbiterK = RotL64((aOrbiterK * 18141974182442267181U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14163773386433257965U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5725700029399455855U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10446930901088908809U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16644838246877860102U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6611825438224873117U;
            aOrbiterD = RotL64((aOrbiterD * 5336239588054125897U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9408958265247071226U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16980073477599191801U) ^ RotL64(aNonceWordF, 24U);
            aOrbiterJ = RotL64((aOrbiterJ * 7985839560318985205U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6513029242607881518U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13880995121909552664U;
            aOrbiterG = RotL64((aOrbiterG * 17463079726765044639U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 12U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 41U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 26U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterD, 37U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aNonceWordC, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 30U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + RotL64(aCarry, 3U)) + RotL64(aNonceWordA, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 54U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Softball_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4869U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3835U)) & W_KEY1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6801U)) & W_KEY1], 52U) ^ RotL64(mSource[((aIndex + 202U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 35U)) + 3199575576585871314U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 54U)) + 2533378188975571824U;
            aOrbiterI = (aWandererD + RotL64(aCross, 3U)) + 6819782112558312658U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 41U)) + 12690060987724798497U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 47U)) + 7088375139715629606U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 17785618677423695666U;
            aOrbiterC = (aWandererI + RotL64(aCross, 23U)) + 1714999280296491277U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 17611338506932491624U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 6475727359297421201U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2347744591204119530U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2739317903351401068U;
            aOrbiterI = RotL64((aOrbiterI * 15435029315209475631U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8663535261373274338U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8205245127823536479U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13857005110466856439U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8916510616749754516U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3944805940148512932U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18082271583211389701U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14094751253118853302U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14094299829196076311U;
            aOrbiterJ = RotL64((aOrbiterJ * 6370012560657108493U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3940673811518673802U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3015106523254484839U;
            aOrbiterF = RotL64((aOrbiterF * 9655401190755573379U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15404103131982599922U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1828655763233900875U;
            aOrbiterA = RotL64((aOrbiterA * 13024358077740310049U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1236981890899916502U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18208975564570342697U;
            aOrbiterC = RotL64((aOrbiterC * 4577109989465876801U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17882273895471449661U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16196010765612713713U;
            aOrbiterG = RotL64((aOrbiterG * 15624856645134182005U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14639250100311162559U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9139027997336903273U;
            aOrbiterD = RotL64((aOrbiterD * 1853126389565574293U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 50U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 37U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterG, 46U)) + aPhaseCWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16359U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((aIndex + 16314U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12480U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 15014U)) & W_KEY1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererF + RotL64(aScatter, 53U)) + 898812731947995389U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 57U)) + 8677347622525527167U) + aPhaseCOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 44U)) + RotL64(aCarry, 41U)) + 770321564027567654U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 11020474858081526395U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 17289793580414993470U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 13U)) + 10111912559295118444U) + aPhaseCOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 5U)) + 8083622125544542011U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 39U)) + 7149858558922988240U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 48U)) + 5919683821379905699U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6860902846079238714U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15083517836867542075U;
            aOrbiterF = RotL64((aOrbiterF * 4686657139237578325U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14852868368708376381U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9860233289028878323U;
            aOrbiterG = RotL64((aOrbiterG * 13418143547952204667U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 772406119079116272U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7971141501337627589U;
            aOrbiterA = RotL64((aOrbiterA * 10168120622976358617U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 8478568022896691911U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4027604850785607101U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4826627523578901467U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17199331557841535430U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7515957656979776361U;
            aOrbiterK = RotL64((aOrbiterK * 5468950152869656599U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17138249294921502391U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16236812863923234668U;
            aOrbiterC = RotL64((aOrbiterC * 2925542836624164807U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16941524155859123682U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11240343728857342866U;
            aOrbiterE = RotL64((aOrbiterE * 7281012444214294659U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15163914964139858328U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6673576554415729652U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1558880328574736975U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5399050402101642989U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11806006719060024615U;
            aOrbiterB = RotL64((aOrbiterB * 15782156615926092159U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 36U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 58U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterD, 42U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 34U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16505U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20088U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16471U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[((aIndex + 19278U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 24U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aScatter, 37U)) + 4179952823252098240U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 10U)) + RotL64(aCarry, 57U)) + 3745613452332101749U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 2955689793395307176U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 5639060180251322019U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 5U)) + 7901969163853586463U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 23U)) + 2242166787816318119U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 27U)) + 5239936443960750064U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 57U)) + 13939136954732185558U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 46U)) + 17058884136712717463U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18148618660054585941U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7022023484530327814U;
            aOrbiterC = RotL64((aOrbiterC * 650100011311048589U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7722084537340095637U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11764151879690934182U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12264384877711365655U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16412785901758144708U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9666718667728274824U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10865799822751771795U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4307127540152109364U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2457646804702647606U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6340030928007058595U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3179394870088602208U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 504977947273774249U;
            aOrbiterE = RotL64((aOrbiterE * 16190282058883481551U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16182729401018310837U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7110817020445860609U;
            aOrbiterF = RotL64((aOrbiterF * 13371352088428584087U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12960656706837391973U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7103806893724395904U;
            aOrbiterH = RotL64((aOrbiterH * 14365984439655979791U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1248300178080633527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7195473175424961337U;
            aOrbiterG = RotL64((aOrbiterG * 4633558992739305045U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13007951568242991449U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10296811247653636372U;
            aOrbiterK = RotL64((aOrbiterK * 16469682651380549395U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterH, 27U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 10U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterB, 6U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 6U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31695U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30577U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30041U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((aIndex + 25588U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 14U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aIngress, 47U)) + 11410829607777684449U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 7502698839700975347U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 54U)) + RotL64(aCarry, 27U)) + 13267685058252106173U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 27U)) + 238242706996630625U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 11U)) + 8184695499511454281U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 12767823220461985403U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 60U)) + 12293198423143850330U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 19U)) + 11149495229952495939U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 23U)) + 7556992689338382800U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3431338808774134649U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16863099140844995099U;
            aOrbiterG = RotL64((aOrbiterG * 752376661101787919U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17872458049880677604U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 16760153457252546974U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11225037229069712805U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3115544493537438408U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4359882942759752958U;
            aOrbiterB = RotL64((aOrbiterB * 561477566995575801U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13387113067202396536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12955690074544490161U;
            aOrbiterH = RotL64((aOrbiterH * 12449941770827974511U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15614054443728226807U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1939441328066616114U;
            aOrbiterA = RotL64((aOrbiterA * 4484917074808974359U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4599016263007782537U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9962305629016158048U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1496184427500037279U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8428467674122750557U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3938884087806393439U;
            aOrbiterK = RotL64((aOrbiterK * 12810531094050481761U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6018636830758044658U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1510372000641305416U;
            aOrbiterF = RotL64((aOrbiterF * 9002834928626918247U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17592782466215337843U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8119921507606870360U;
            aOrbiterE = RotL64((aOrbiterE * 1299795061644535485U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 6U) + aOrbiterE) + RotL64(aOrbiterF, 60U));
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 24U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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

void TwistExpander_Softball_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1783U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 3243U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1847U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 663U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererH + RotL64(aScatter, 21U)) + 10336802574069791273U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 169025388197058936U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 6541354188379168846U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aCross, 42U)) + RotL64(aCarry, 29U)) + 16223920526599306104U) + aPhaseDOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 5U)) + 12756613707692514808U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5082475548176484035U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4907435526952698526U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1379692095754989215U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14236627073831834337U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11502511046130497584U;
            aOrbiterD = RotL64((aOrbiterD * 3460330807286625917U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3679044835550219497U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11254838916686736746U;
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10582608424233200966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4628253464169957835U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17664454668473204465U;
            aOrbiterC = RotL64((aOrbiterC * 4234720298731378527U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 42U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9799U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10232U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10320U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13481U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 29U)) + 4970414922752555648U;
            aOrbiterF = (aWandererD + RotL64(aCross, 13U)) + 9462756592787669327U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 5U)) + 3948790686662213095U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 14542857212241578311U) + aPhaseDOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 3387479009827029547U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1411421370057797877U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16894451466895681236U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13825974818858676215U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12727136462290223542U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4625389198191960525U;
            aOrbiterJ = RotL64((aOrbiterJ * 5726474430977810191U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3471881403786164913U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6433115856048534831U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9363233870194144053U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9825592965466157982U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1553125767261293088U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 411535191177308781U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9951616357109647617U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11231080382787286889U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14024961994986659187U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterE, 53U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20994U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 21183U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16456U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 24455U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 57U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 5697928251815176134U) + aPhaseDOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 337587740689259575U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 53U)) + 4927686903263973950U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 3742409032569801033U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 38U)) + 1608092659172197650U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15848744267145717509U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15300174177963339253U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5771922862677667319U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14162868453323648628U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12020167069983729869U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2071080217680099017U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16259538291658723956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8516686212464112245U;
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3722184575520553132U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5663609293306386784U;
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15265344442454471986U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3050323350098829515U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5890624677162388135U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 52U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 39U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 11U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31625U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 31997U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25971U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27859U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 22U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 41U)) + 10805654776556844351U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 582794182442795335U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 3U)) + 2858343650974681068U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 8189584049022064284U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aIngress, 14U)) + RotL64(aCarry, 43U)) + 1565100751996962893U) + aPhaseDOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8062028016947611891U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8280504280578451745U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5212851648135050483U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11326869194491655350U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1671695656567777163U;
            aOrbiterJ = RotL64((aOrbiterJ * 7511554500524257921U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2349843105293943452U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13015545152052004254U;
            aOrbiterG = RotL64((aOrbiterG * 1316662811685429983U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16703354404749291869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8713231044374305801U;
            aOrbiterA = RotL64((aOrbiterA * 9242480982197688625U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11118401674497783533U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14857556493734710364U;
            aOrbiterF = RotL64((aOrbiterF * 3452566050389715195U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 48U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 22U) + aOrbiterG) + RotL64(aOrbiterA, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Softball_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4708U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 5384U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1379U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((aIndex + 7406U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 41U)) + 8506388683755208267U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 27U)) + 2179323259055019735U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 3345902531140983016U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aScatter, 57U)) + 17456139311481306584U;
            aOrbiterE = (aWandererE + RotL64(aCross, 35U)) + 14587864088462311164U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 13178947246650647057U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 50U)) + RotL64(aCarry, 53U)) + 12866578138946916962U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13098524333655118173U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15451329483787541982U;
            aOrbiterC = RotL64((aOrbiterC * 13580376920467431451U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9494299579678389385U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15581954810375490643U;
            aOrbiterE = RotL64((aOrbiterE * 13670002280188424825U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4487042505730624892U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2774455928791636186U;
            aOrbiterG = RotL64((aOrbiterG * 15847933919136777451U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12435319582397755819U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10077180055177766823U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3924363471701748703U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10391963896910956455U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6149237416725301794U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10115917698918612823U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15673402771629639978U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14729117178956592426U;
            aOrbiterD = RotL64((aOrbiterD * 9070464269215820531U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14492001279368870240U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6278248084483259952U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16731228350971263873U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 18U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterF, 4U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15745U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14301U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11646U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15121U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 38U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererG + RotL64(aIngress, 21U)) + 2974056819475622600U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 7345051759236356098U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 12738468816846628882U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 11U)) + 7694520596043297922U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 3U)) + 5530753590015084774U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 44U)) + RotL64(aCarry, 21U)) + 3776309161718383105U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 29U)) + 784780304358106404U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8999942326995036509U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5194986506064092779U;
            aOrbiterG = RotL64((aOrbiterG * 15070787038006135963U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7920040007459652762U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11311997270710107937U;
            aOrbiterA = RotL64((aOrbiterA * 6227571709361790209U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5365231114813547251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8630110234623825263U;
            aOrbiterB = RotL64((aOrbiterB * 2735881715888325759U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2358235238039571072U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 18059414891616491807U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17150786106857185467U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14526050556461782864U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6937282036603272474U;
            aOrbiterD = RotL64((aOrbiterD * 14954512365270028029U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10105832250694931310U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3884223553012098137U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16340956813003906195U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10385284339549648087U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1257633893341505930U;
            aOrbiterJ = RotL64((aOrbiterJ * 2669950791270500977U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 28U) + aOrbiterD) + RotL64(aOrbiterF, 37U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterF, 52U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + aPhaseEWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18293U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 21412U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18055U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17799U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 52U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 2558105147674438050U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 19U)) + 15856662514774702561U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 13346869226246584582U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 7632111846116243973U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 43U)) + 2102101361626976279U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 27U)) + 5605968705067851563U;
            aOrbiterB = (aWandererK + RotL64(aCross, 37U)) + 6842483186584326681U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5559797213819425064U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12422313931331576759U;
            aOrbiterE = RotL64((aOrbiterE * 7399849122565913401U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2751024420047872601U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11031320239359798610U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8607639453141148025U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14366375309473793217U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11971479429768505316U;
            aOrbiterJ = RotL64((aOrbiterJ * 10063001532313098203U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3947595951884469542U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17882767922372770896U;
            aOrbiterG = RotL64((aOrbiterG * 3361906348965810211U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 513871456983509223U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5951677013597794294U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8508629569649935293U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 437626309049021931U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 466674061172005705U;
            aOrbiterI = RotL64((aOrbiterI * 1310502572084891157U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12362602809233133718U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10525852878882195702U;
            aOrbiterB = RotL64((aOrbiterB * 17755022180514914325U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterB, 58U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterE, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererF, 54U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26699U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 26888U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32750U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29693U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 15045917390223766480U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 10763054007033668758U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 5U)) + 13190170142593666607U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 19U)) + 9657025731441167065U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 50U)) + 11433367178975954211U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 17904920143996810366U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 35U)) + 3244383020512113283U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6538815775171139091U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7195368312757976343U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10515679176134176565U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 18134430713910279374U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6571776588427107976U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11916502085252589161U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11830778129647517758U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9793702760907767365U;
            aOrbiterC = RotL64((aOrbiterC * 4096246227968677179U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2287235876793192036U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8951959188326141794U;
            aOrbiterH = RotL64((aOrbiterH * 9968356718110753845U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7583061790273240157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3571364625022806085U;
            aOrbiterJ = RotL64((aOrbiterJ * 6238360922735480669U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13869345563551689212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 277480328952975002U;
            aOrbiterA = RotL64((aOrbiterA * 1057564597096163085U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4983735092494677578U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9490022869381030928U;
            aOrbiterF = RotL64((aOrbiterF * 12926352917961703123U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 5U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 28U));
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + aPhaseEWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Softball_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6573U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6652U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 427U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4242U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 42U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 11998579547770778580U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 8409465187298704610U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 11U)) + 3470222286110333500U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 22U)) + RotL64(aCarry, 35U)) + 5704486785203069994U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 3U)) + 10334944660253279633U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7626852700722567477U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14631310754943209743U;
            aOrbiterD = RotL64((aOrbiterD * 1958866541508493967U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 807160297237854120U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5624154783624196107U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2404066593958052159U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4971444394698940423U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6340057638461027062U;
            aOrbiterA = RotL64((aOrbiterA * 12027586111086798629U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9003019862787819481U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13632057463595873033U;
            aOrbiterF = RotL64((aOrbiterF * 12575202147280216765U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12766104026871797746U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4062118445824915939U;
            aOrbiterE = RotL64((aOrbiterE * 13130770039048080701U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 58U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12157U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9246U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14404U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 15872U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 4739486756133131180U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 42U)) + 16089707555501328184U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 15310047330238536453U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 7901411596386834955U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 21U)) + 4357555491060982163U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15667085602825720102U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8520635334382269253U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7348648918661047791U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1772509779231068315U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15336170957886025677U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10996880551392077399U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8628770833489469980U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15469234024247246228U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8905266995119987947U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10796430900884288328U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10660110397012853289U;
            aOrbiterF = RotL64((aOrbiterF * 9140007610912037461U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11202284258711214794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17509491802893182994U;
            aOrbiterK = RotL64((aOrbiterK * 9329107599972703671U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 20U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 4U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 29U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterH, 56U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19360U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18529U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16396U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21992U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 36U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 8020711767807230555U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 53U)) + 15368693777246341570U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 10U)) + RotL64(aCarry, 3U)) + 5117523734225562401U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 13155269151097507808U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 29U)) + 9879303753623578272U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1165799257173794826U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 930641942062732091U;
            aOrbiterA = RotL64((aOrbiterA * 17151944851548731159U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11330571332221123153U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2862963158282518899U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13782195862525974199U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6019186399361476659U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1924419843785161958U;
            aOrbiterC = RotL64((aOrbiterC * 9485557122500346869U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12618629043591380461U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9334176504266512405U;
            aOrbiterK = RotL64((aOrbiterK * 18239109235362925739U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16829692481030013551U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5604784396927022709U;
            aOrbiterH = RotL64((aOrbiterH * 2833893610883508353U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterK, 50U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 29U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterH, 41U));
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31796U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 26982U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31901U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 25908U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 18U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 8506388683755208267U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 23U)) + 2179323259055019735U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 3U)) + 3345902531140983016U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 17456139311481306584U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aCross, 56U)) + RotL64(aCarry, 57U)) + 14587864088462311164U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13178947246650647057U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12866578138946916962U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 121991325166969319U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13098524333655118173U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15451329483787541982U;
            aOrbiterD = RotL64((aOrbiterD * 13580376920467431451U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9494299579678389385U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15581954810375490643U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13670002280188424825U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4487042505730624892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2774455928791636186U;
            aOrbiterB = RotL64((aOrbiterB * 15847933919136777451U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12435319582397755819U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10077180055177766823U;
            aOrbiterE = RotL64((aOrbiterE * 3924363471701748703U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 24U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterE, 3U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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

void TwistExpander_Softball_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 2923U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1399U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1041U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4168U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aPrevious, 35U)) + 17081642665820489793U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 14468854040067229623U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 2249450222593057429U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 14964389079511378664U) + aPhaseGOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aCross, 58U)) + 17003491054252360650U) + aPhaseGOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12710882240582032588U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9887078182156755359U;
            aOrbiterG = RotL64((aOrbiterG * 8205865025853482573U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7665284531810584704U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7304284015511876717U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6193179739025093929U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5517927023543751734U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17704756310857362759U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15826832172923213591U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11347400363019508578U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11696395232760991243U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9725231749679442003U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10875780291242873583U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7808740614343437672U;
            aOrbiterB = RotL64((aOrbiterB * 8889516201913716283U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 35U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterA, 21U));
            aWandererC = aWandererC + (((RotL64(aScatter, 20U) + RotL64(aOrbiterF, 44U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + aPhaseGWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 46U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16184U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14839U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10811U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16202U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 20U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 3U)) + 9041099828460168106U) + aPhaseGOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 51U)) + 12883711604096848454U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 40U)) + RotL64(aCarry, 43U)) + 17420968786226443079U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 3448213891716125104U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 11866455977445336560U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4119356835384495905U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2186212599698637068U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6756888950976735707U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6506144898969301620U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12556800923644051626U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15961043406612913121U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4075551535185182945U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17877694808492008749U;
            aOrbiterG = RotL64((aOrbiterG * 901315308379887473U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5553428900598223316U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14362304852277160675U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11415103199856419303U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9174200302876075831U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16110739511917638547U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7004356839428657949U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 36U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterH, 38U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 23930U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23770U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18086U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22573U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 57U)) + 9888431329297626900U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 3U)) + 2937735167534624403U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 17626022970343789617U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 5665660859333693743U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 20U)) + RotL64(aCarry, 27U)) + 1060537034632076669U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 743777763907175800U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5744905970181808845U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17426701505806885785U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3545351394494002180U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4877547088414106007U;
            aOrbiterJ = RotL64((aOrbiterJ * 5416792889338547109U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11669378338379598445U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2961072441706158212U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2677988507090705371U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13984945589234919765U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1433097875470903205U;
            aOrbiterE = RotL64((aOrbiterE * 451996840039906781U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 716415411025451152U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8542286150858297810U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9139015340823332449U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterF, 13U)) + aPhaseGWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 50U));
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 40U) + aOrbiterE) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 26825U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28068U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29111U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 28965U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 3199575576585871314U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 2533378188975571824U) + aPhaseGOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 6819782112558312658U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 4U)) + 12690060987724798497U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 13U)) + 7088375139715629606U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17785618677423695666U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1714999280296491277U;
            aOrbiterJ = RotL64((aOrbiterJ * 7675674437417383741U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17611338506932491624U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6475727359297421201U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15133348244242438069U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2347744591204119530U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2739317903351401068U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15435029315209475631U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8663535261373274338U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8205245127823536479U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13857005110466856439U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8916510616749754516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3944805940148512932U;
            aOrbiterA = RotL64((aOrbiterA * 18082271583211389701U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 56U)) + aPhaseGWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
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

void TwistExpander_Softball_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7727U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 10U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4584U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5427U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 36U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererI + RotL64(aScatter, 21U)) + 12583180859826261500U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 29U)) + 9067093488553721468U) + aPhaseHOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aCross, 40U)) + RotL64(aCarry, 47U)) + 12173106198862881754U) + aPhaseHOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 11333491014394592654U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 3511883526940919554U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7416810692106273044U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8341174972619784110U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17722163445765437279U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2220852854836962979U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8090781422229383825U;
            aOrbiterC = RotL64((aOrbiterC * 578293950675644397U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2338801236599102223U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12484514711848308104U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10364216764253366067U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13684861340589131816U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12796636819991873058U;
            aOrbiterF = RotL64((aOrbiterF * 5533508014234835669U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7634198650894837690U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10240326122201201762U;
            aOrbiterG = RotL64((aOrbiterG * 8758703497719125901U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 4U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 56U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + aPhaseHWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12298U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11078U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10417U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 9683U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 42U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 8506388683755208267U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 47U)) + 2179323259055019735U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 4U)) + RotL64(aCarry, 57U)) + 3345902531140983016U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 17456139311481306584U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 39U)) + 14587864088462311164U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13178947246650647057U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12866578138946916962U;
            aOrbiterH = RotL64((aOrbiterH * 121991325166969319U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13098524333655118173U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 15451329483787541982U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13580376920467431451U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9494299579678389385U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15581954810375490643U;
            aOrbiterD = RotL64((aOrbiterD * 13670002280188424825U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 4487042505730624892U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2774455928791636186U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15847933919136777451U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12435319582397755819U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10077180055177766823U;
            aOrbiterK = RotL64((aOrbiterK * 3924363471701748703U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 26U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 56U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18738U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 23030U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18298U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 20771U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 3U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 12U)) + RotL64(aCarry, 39U)) + 6771552164800695068U;
            aOrbiterH = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 12131763371571322040U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 37U)) + 3326182381395522013U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 12288775097697156383U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 21U)) + 5195948373449796741U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14404044002250137144U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11142382920035825426U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8134413822789107595U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2967149520256475485U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1470907369577818097U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9398653295177725883U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9231668148004163910U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13078929163913892386U;
            aOrbiterC = RotL64((aOrbiterC * 7509829068700523627U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9485274692075657877U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12216951187543631673U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6571066246507310805U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6933334652581744234U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17260276102423580920U;
            aOrbiterD = RotL64((aOrbiterD * 7796879893790990605U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 56U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 52U) + RotL64(aOrbiterA, 47U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + aPhaseHWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterA, 56U)) + aPhaseHWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 25164U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 25189U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29486U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29933U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 6U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aIngress, 41U)) + 11480359716598965890U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 15431182525482873419U) + aPhaseHOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 11360504974812776707U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 12U)) + 9292576416573382769U) + aPhaseHOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 1549257414531028975U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5347769463033129317U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17019199177478377234U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4336112198640602307U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16558106007323125094U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3976182233825939422U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4392162052317572289U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2889047161195954395U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2241831345026962605U;
            aOrbiterG = RotL64((aOrbiterG * 5757458560979927857U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12850802412140579294U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13541744735436450160U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 906089290000537439U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2085863085516538212U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2969034221711544086U;
            aOrbiterF = RotL64((aOrbiterF * 7768528124408400403U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 4U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + aPhaseHWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterE, 50U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
