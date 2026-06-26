#include "TwistExpander_Fencing_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Fencing_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xED1027A6F34CF0ADULL + 0xCAB8F0EBCAA31FFDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC4CBF609C0554905ULL + 0xA06EFEEF9A99A6D4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9DFB14D89B393881ULL + 0xCF1AD0C743647C06ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD25B9DA485E1E05BULL + 0x9BB5D2A989318007ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAC6DBA075AD4E677ULL + 0x8753F0E8EC078B97ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE9A27FEC7B90EC75ULL + 0x84E6204CC124BB5DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9213E2044F1B6D51ULL + 0xB6601069789588A1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8AD1FAB75BA17229ULL + 0x886548F596809D30ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x907F5DEC7A6344BFULL + 0xB2752034C53CF10BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9A9BAA41AD269BDDULL + 0xD8118D5B4B14CC1EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDC1EC70CC585ACF9ULL + 0xE2B928A387DEFE81ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB4C611B70EEFE6C1ULL + 0xCB9046A255B87110ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB8DE0E9B00C9315DULL + 0xF7F73A922EE59A72ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8C9F3992AE219307ULL + 0xDCCADB318E377DD3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFA51E70234FE72A1ULL + 0xB66F4B0F6A8E8D08ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE92908B205C4A7DBULL + 0xF779F837FAF28BFFULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4968U)) & S_BLOCK1], 14U) ^ RotL64(pSnow[((aIndex + 2874U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3076U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1125U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aCross, 35U)) + 252059974543142812U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 23U)) + 11690823093681457368U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 42U)) + 13282189752890971123U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 3U)) + 9507416294305708435U) + aNonceWordF;
            aOrbiterK = ((aWandererD + RotL64(aCross, 39U)) + 14053038174390776539U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 19U)) + 14605253312318725009U) + aNonceWordK;
            aOrbiterH = (aWandererC + RotL64(aScatter, 53U)) + 18138286582677863671U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 8530091235978489988U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 14381731677571170073U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 29U)) + 13316413456378978456U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 3910529530149320706U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6302070286831566901U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12324134652758551396U;
            aOrbiterG = RotL64((aOrbiterG * 17136438281540250165U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4773478557638475048U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4031153435446078944U;
            aOrbiterE = RotL64((aOrbiterE * 3876928995240982769U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3114794895962903899U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3552936509969106796U;
            aOrbiterB = RotL64((aOrbiterB * 16823186892738820299U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5828754613946145627U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 17985241114076114558U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 1986669631395606833U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11319331046368072261U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6104267020171882160U;
            aOrbiterH = RotL64((aOrbiterH * 12525117969211576177U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7662668379725735125U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6583034411403600735U;
            aOrbiterF = RotL64((aOrbiterF * 262095656452193889U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5569865728026310280U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4176065898330374039U;
            aOrbiterI = RotL64((aOrbiterI * 11305749530796963967U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13677146592276526676U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2734371113158117596U;
            aOrbiterJ = RotL64((aOrbiterJ * 13146444882662731975U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14890607377967461739U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3110674898918355049U;
            aOrbiterK = RotL64((aOrbiterK * 9637837600671200315U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15329760212453783067U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 18214263442264013242U;
            aOrbiterC = RotL64((aOrbiterC * 9139354822936682953U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6727267537859989206U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 252059974543142812U;
            aOrbiterA = RotL64((aOrbiterA * 9559128226993261041U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 6U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 19U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterC, 39U));
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterB, 22U)) + aNonceWordD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + aNonceWordE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 6U) + aOrbiterD) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9264U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 10098U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 5936U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 5620U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 29U)) ^ (RotL64(aCross, 42U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 1364174714924216027U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 5U)) + 13561796874229506613U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 11845572344206238305U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 15762708240326773763U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 30U)) + 1157119665207900473U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 27U)) + 6823546624372055260U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 37U)) + 14465564210523945121U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 51U)) + 10667464548080807531U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 43U)) + 13445737493224316575U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 14U)) + 3009837893785957665U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 23U)) + 2886920524111083752U) + aNonceWordK;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10886177449328249656U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15067759884678100433U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 5724566815989860041U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18307930462682331536U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8791864377579255801U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 9265158882471421767U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 805797468642992351U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5743305867058244964U;
            aOrbiterD = RotL64((aOrbiterD * 16263000753351131717U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17102025528234481273U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1841579177327486899U;
            aOrbiterE = RotL64((aOrbiterE * 3841603385577825265U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2189493507896508972U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 18209567010094914374U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3737080408976852351U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6697069234216868330U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 927471474577415372U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10680760991009199309U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13155854301197725408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1014625081915435892U;
            aOrbiterH = RotL64((aOrbiterH * 11592754232949990435U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12697209921410914931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11555096613655648647U;
            aOrbiterK = RotL64((aOrbiterK * 4598821388864997089U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9335308231651271690U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3160859883353473444U;
            aOrbiterA = RotL64((aOrbiterA * 4753600703924906409U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15681189182414315768U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3147692210581710663U;
            aOrbiterG = RotL64((aOrbiterG * 6271949093080510861U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5373388632562432117U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1364174714924216027U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4694926665965807945U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterK, 14U));
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterH, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 56U) + aOrbiterC) + RotL64(aOrbiterG, 46U));
            aWandererJ = aWandererJ + (((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordP) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 41U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordE;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15469U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 12875U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 14946U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((aIndex + 13380U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 19U)) + 14686411261024919129U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 54U)) + 7514582233957632005U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 39U)) + 6520710480103365552U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 21U)) + 1983621978676188036U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 9003524602590749672U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 6428568234045228995U;
            aOrbiterB = (aWandererC + RotL64(aCross, 5U)) + 8656552687136446989U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 50U)) + 16916248288415922490U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 9740237548002535784U) + aNonceWordG;
            aOrbiterC = (aWandererE + RotL64(aScatter, 13U)) + 907561000814618339U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 4751108900841197631U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 167774899400732287U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11907484918310854962U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7213139491146402985U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14910318613649863924U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14882888155751455276U;
            aOrbiterF = RotL64((aOrbiterF * 11394136445442060201U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16175942562693781908U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11022373758481651102U;
            aOrbiterG = RotL64((aOrbiterG * 6836331461393816027U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12548405399045031548U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10850926364556828443U;
            aOrbiterH = RotL64((aOrbiterH * 16231561687709867431U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13391684887911141790U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14648937281264822988U;
            aOrbiterK = RotL64((aOrbiterK * 6533299316940026059U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8298658887198526821U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 13822977698661348891U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 17769262972278410937U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7505646847564645719U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3238749538197209166U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15394286542600778567U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15853506915123709257U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8426329899401071248U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 1330397096577715113U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14848635392815613098U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3549927798350175044U;
            aOrbiterB = RotL64((aOrbiterB * 1899044682313056949U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1798973117197750802U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13056711228618953977U;
            aOrbiterD = RotL64((aOrbiterD * 9102877396419306689U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1395893547965799281U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14686411261024919129U;
            aOrbiterE = RotL64((aOrbiterE * 17075377081365066067U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 21U)) + aOrbiterC) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterI, 37U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 30U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA + ((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16585U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20931U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20018U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 17957U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aIngress, 46U)) + 11274974230580265396U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 41U)) + 16658438747342741547U;
            aOrbiterB = (aWandererE + RotL64(aCross, 23U)) + 16612986966106053844U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 13U)) + 9329502236843231290U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 14088261356708344656U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 19U)) + 13692608802007789581U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 29U)) + 6824473946645682398U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 34U)) + RotL64(aCarry, 47U)) + 2072915876348570040U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 37U)) + 7420507753044460759U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererA + RotL64(aCross, 43U)) + 4677557318688502593U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 15081678577055628459U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7026792817486507482U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14871665922943969918U;
            aOrbiterB = RotL64((aOrbiterB * 694073180313083145U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6807734532159292872U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17882797335141303280U;
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9233542707022629190U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1205501586581350876U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2596053290311090589U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10878718669747466677U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 8066049063548639241U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 3031382633089381605U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 861295180226875235U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9134969787937288583U;
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6726642007159809594U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8061661744643240470U;
            aOrbiterE = RotL64((aOrbiterE * 6703498926835391813U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13541412083111962884U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8617442758729315637U;
            aOrbiterD = RotL64((aOrbiterD * 15471862889276160953U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16884403561131293362U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9490680911678221233U;
            aOrbiterC = RotL64((aOrbiterC * 15988763830018001033U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10486145044311386738U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10200001044821063684U;
            aOrbiterI = RotL64((aOrbiterI * 16149790736141571017U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6997073594007878034U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13585783612009989767U;
            aOrbiterF = RotL64((aOrbiterF * 11425303157774550449U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3847846040256340653U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11274974230580265396U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13970270689108369205U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 39U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 46U)) + aOrbiterE) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 43U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 54U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            aWandererB = aWandererB + ((RotL64(aScatter, 34U) + RotL64(aOrbiterD, 21U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterB, 14U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererC, 14U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22296U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 23466U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26645U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 24341U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aCross, 46U)) + 7825479804710770560U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 5298124167101358123U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 37U)) + 17774541024369233726U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 7679371833537454082U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 5385914900748772224U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 39U)) + 3879781930908486531U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererH + RotL64(aIngress, 48U)) + 659110346638873236U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 11U)) + 10749021728538539749U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 51U)) + 3631252455767429457U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 13U)) + 2271978810960685021U) + aNonceWordC;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 43U)) + 5963558780692551176U) + aNonceWordE;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 974909966119198104U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9296998242911152296U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2613629915877957661U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2245318466901521959U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13391076374843288568U;
            aOrbiterF = RotL64((aOrbiterF * 18094558036982107419U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6184487746594236737U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1563385912137291418U;
            aOrbiterE = RotL64((aOrbiterE * 4805455299959232321U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1744840092006498629U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2100927276837188416U;
            aOrbiterJ = RotL64((aOrbiterJ * 3541788262067077997U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9998911862807246338U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12239948725635220096U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7098620484129489129U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3307447094994950246U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12746613971448298932U;
            aOrbiterK = RotL64((aOrbiterK * 9463975886346934681U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11577488293733790649U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 191108997585598809U;
            aOrbiterB = RotL64((aOrbiterB * 9574978681405356871U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 18096145693841273722U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 10026281133603934071U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 17261343107314203471U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2346682418062064668U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2996178204018644206U;
            aOrbiterH = RotL64((aOrbiterH * 2552965800703390909U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15085425896818988223U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1589593231782852588U;
            aOrbiterD = RotL64((aOrbiterD * 1535556765195388675U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17170695588248383518U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7825479804710770560U;
            aOrbiterG = RotL64((aOrbiterG * 7434218282170150533U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 30U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterB, 60U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterA, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterA, 6U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 40U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererI, 24U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27559U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28190U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30810U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32086U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 13278949403988203974U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 39U)) + 9213599924054673756U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 1255746482932381798U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 11575321997144516122U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 58U)) + 15881587525529432437U) + aNonceWordL;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 3U)) + 9846195809864862707U) + aNonceWordB;
            aOrbiterI = (aWandererF + RotL64(aIngress, 37U)) + 12319815691858217670U;
            aOrbiterF = (aWandererA + RotL64(aCross, 21U)) + 16322617427294439587U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 56U)) + 16332130810525887437U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 41U)) + 4920951156015336794U) + aNonceWordG;
            aOrbiterA = (aWandererC + RotL64(aCross, 29U)) + 16767126455124552329U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12553595911087945223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1437522202135436142U;
            aOrbiterB = RotL64((aOrbiterB * 2001992794165550905U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12313100454852227143U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2761983020631055729U;
            aOrbiterE = RotL64((aOrbiterE * 3874839760378039509U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17635303588421554367U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 788212489507463763U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 17896475584538528059U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5192552894670654434U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6784748488807738811U;
            aOrbiterI = RotL64((aOrbiterI * 8077237651953896479U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16113417046719114943U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1096874945215225916U;
            aOrbiterF = RotL64((aOrbiterF * 17308604412622879833U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 7610274704570171595U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10466070212284342550U;
            aOrbiterH = RotL64((aOrbiterH * 6449728258497920613U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6777845928873855221U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5251515022021984126U;
            aOrbiterJ = RotL64((aOrbiterJ * 9018277343404261611U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13849343158824111498U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7977711210181714021U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4182053966171053577U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6494539818728106982U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11314590450226080781U;
            aOrbiterK = RotL64((aOrbiterK * 12455979257225599157U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 552687702594328012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14961304171192292246U;
            aOrbiterD = RotL64((aOrbiterD * 846375892915484717U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9771874402848476494U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13278949403988203974U;
            aOrbiterC = RotL64((aOrbiterC * 2119203863777871233U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 50U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 52U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 11U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aCross, 42U) + aOrbiterD) + RotL64(aOrbiterF, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterC, 56U)) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 6U) + aOrbiterJ) + RotL64(aOrbiterH, 21U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterE) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordO);
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

void TwistExpander_Fencing_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA547C5B624E85EBBULL + 0x94FB88AF5F5EA930ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC31A43C776A602EBULL + 0xD8824582EBD70423ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC0036149B8C38F3BULL + 0xCDA479B90369693FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCCAAEE16375B9705ULL + 0xE47D0931F13DFE63ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA1AF205625700BF3ULL + 0x8DFA8140042BD4EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA89CAC094E6E82E9ULL + 0xAAD97C23229E27F4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9B7882E6A012064BULL + 0x8919F4F285F163B7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF359B948F36DF4DFULL + 0x9549B3261D763B34ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x80F10EA76FD15F29ULL + 0xB9992ECD014E36FDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x93DE30238CB04EAFULL + 0x892B14B42C852DCBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x96013B2C2E71FB05ULL + 0xC0A1D49B800C60C2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDE29F38E2120AF4FULL + 0xDB72238BDDEC8D81ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFBCFE031F60631BDULL + 0x80E599C2F8A87AA2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBF80BFF65322DD4DULL + 0xDC88810C4F800C57ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDC3510953F4EC979ULL + 0xE43ED2727CC6C93FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC87F337A2CA4F9CBULL + 0xE67D90077A54D6F4ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6831U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((aIndex + 3727U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4804U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6140U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 47U)) + 13714409587461539863U) + aNonceWordC;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 18U)) + 14101156723903265839U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 11U)) + 7063754562895369001U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 12320578575245519386U;
            aOrbiterH = ((((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 11744826789631008424U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aWandererG + RotL64(aCross, 23U)) + 8744816505096675597U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 35U)) + 10405435520084528645U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 1463157688070683543U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 39U)) + 12379603577919617703U) + aNonceWordL;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1343439118031348146U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16118850268070235540U;
            aOrbiterA = RotL64((aOrbiterA * 11184386483735388257U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14116264435819277136U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5251698273012432109U;
            aOrbiterD = RotL64((aOrbiterD * 1495818611622063967U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14806408656041403829U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 11569345414052398227U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 9913158908301414861U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17063874769147888574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9927420478679581917U;
            aOrbiterJ = RotL64((aOrbiterJ * 9042782809534196563U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2550285599827162167U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17801534123304996448U;
            aOrbiterG = RotL64((aOrbiterG * 2160836889363614721U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6456685241021762041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17064208177372969289U;
            aOrbiterF = RotL64((aOrbiterF * 13726627607233302493U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 18279938244131982650U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8211002229712129419U;
            aOrbiterK = RotL64((aOrbiterK * 12931373380977640645U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12795832560781931767U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 286378504074349650U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 85453101173293509U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5835304250436889513U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12704972686724379659U;
            aOrbiterH = RotL64((aOrbiterH * 1198789639656336053U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterB, 28U)) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterG, 51U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterD, 34U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + aNonceWordA) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordN);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15495U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15822U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12609U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 12282U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 30U) ^ RotL64(aCarry, 43U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 5171470532667965920U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 11U)) + 750549462358682403U) + aNonceWordA;
            aOrbiterE = (aWandererD + RotL64(aScatter, 3U)) + 3325689257577120525U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 57U)) + 18031575461559790826U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 42U)) + RotL64(aCarry, 3U)) + 13874739537012288677U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 53U)) + 4250029868785016865U) + aNonceWordL;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 47U)) + 8211158803112611161U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 1083939790236786027U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 34U)) + 3446525462376962464U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 6973817815000417325U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15230876489676945543U;
            aOrbiterE = RotL64((aOrbiterE * 7737039082964537651U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9359727659738755880U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8775170107816327654U;
            aOrbiterB = RotL64((aOrbiterB * 6910680458261008653U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11958941755525038545U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16966819714283167348U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16363457661846050749U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14556087985619763243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17915047508377045221U;
            aOrbiterC = RotL64((aOrbiterC * 6727635453185130109U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8578745677485367222U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7002181668717618866U;
            aOrbiterK = RotL64((aOrbiterK * 12329703532414955235U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3569939503066735457U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2956247934282522184U;
            aOrbiterD = RotL64((aOrbiterD * 9946650822131152531U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4285180013402474041U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5976239869535619811U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3458095419039067465U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2424524955161695463U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6849595426583763537U;
            aOrbiterG = RotL64((aOrbiterG * 12727902040238318101U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11414890686374886716U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5668287266836153445U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8011885266143066285U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 36U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 48U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 56U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterE, 5U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 42U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19665U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17326U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22672U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 20712U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 2915859148137000694U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 37U)) + 210680583721444425U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 57U)) + 6668118118775650387U) + aNonceWordG;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 15794200818099010989U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 24U)) + 6565076707062828369U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 47U)) + 16323164497808856719U) + aNonceWordH;
            aOrbiterD = ((aWandererB + RotL64(aCross, 3U)) + 7965435318816716560U) + aNonceWordD;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 7390281030573369017U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 30U)) + 2269738866911824875U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9664014216039993873U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 18284857398028357633U;
            aOrbiterF = RotL64((aOrbiterF * 8402008251343393737U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 367667619795303009U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7935945060956274197U;
            aOrbiterI = RotL64((aOrbiterI * 5481786693511955209U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16683666162337789540U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10655658270998102390U;
            aOrbiterC = RotL64((aOrbiterC * 15231596813382239841U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8307037916581540297U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3247742749860703524U;
            aOrbiterJ = RotL64((aOrbiterJ * 15052136713218656641U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10446792483683818139U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 16374602929344972364U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 12599903932725787599U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2411334498322777183U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1093701164116833765U;
            aOrbiterH = RotL64((aOrbiterH * 13129220206835381729U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17018480952982840635U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17348395690080029814U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 6212591395713433257U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16111252311283623152U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12776492920397785951U;
            aOrbiterK = RotL64((aOrbiterK * 6136009241593081821U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 12214538600808144816U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10043377462096783363U;
            aOrbiterG = RotL64((aOrbiterG * 14639467375095185877U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 37U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterC, 58U)) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 23U));
            aWandererB = aWandererB + ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 46U) + aOrbiterF) + RotL64(aOrbiterK, 42U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30987U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29230U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25692U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 26277U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 52U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 7651355040951791298U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 48U)) + RotL64(aCarry, 57U)) + 13988210277931659312U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 9846849412579537783U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 3U)) + 12746719939495876158U) + aNonceWordO;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 29U)) + 11498066185182895284U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 13U)) + 11101058955193080232U;
            aOrbiterK = (aWandererK + RotL64(aCross, 23U)) + 15513734459555672046U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 60U)) + 15711108675349394643U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 43U)) + 4771231759949468556U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11449258010811305256U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 17036938391509986723U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 7411466953205347639U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6999245666776654250U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2106819066263369528U;
            aOrbiterC = RotL64((aOrbiterC * 13005885810757743129U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12716183358903477216U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16752724547046059889U;
            aOrbiterK = RotL64((aOrbiterK * 11475905692393034141U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17623077680983093163U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6726003022297274986U;
            aOrbiterF = RotL64((aOrbiterF * 14709385877103232653U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2842410225096524740U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9235178377537910514U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11813751114775673845U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2619888019860844610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6295481948199619613U;
            aOrbiterG = RotL64((aOrbiterG * 15429161806953951205U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9724921158061115570U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4070976180958458679U;
            aOrbiterJ = RotL64((aOrbiterJ * 6080566609081811453U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5864247978960125554U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7771249710071026757U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4787660062590737657U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15006900854988166845U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2755659268987119046U;
            aOrbiterE = RotL64((aOrbiterE * 8043939381186802359U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 38U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 30U)) + aOrbiterA) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterG, 37U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterE, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterF, 56U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordF);
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

void TwistExpander_Fencing_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD70044C90A61918BULL + 0xB9CF93DAFC589319ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCA91E2C89041E9A5ULL + 0xC410AAD724CE0B90ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEFD2ACFDB1B40663ULL + 0xD704BEA6EE26AEDDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB286766A17235499ULL + 0xF4A90DD784B9D0FAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEF6F1A43B334B609ULL + 0x964C0E0F3C1DB525ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD532A98F1AE550B1ULL + 0xBF6DB91BD3C93FF6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x850B9311B76C7DB5ULL + 0xA8D03E4CC76591D4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8EE3B25C06FD093BULL + 0xCC7C4AA693D49076ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA154A415EAA14299ULL + 0xBA8BBB248B482B28ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEC1555CA3A9465EFULL + 0x82B6B799281229D5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD3C7BA8807B1E479ULL + 0xD0C6E559F4DE2FDAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB13830C59AD85947ULL + 0xAD230108DC4E4B41ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCBE0F6E40133A9FDULL + 0xEBBB5E215510793FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC88F29B92D7A43B9ULL + 0xA91A471AC0E88443ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x81E23B65CAA29447ULL + 0x88D2365B3C789958ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x97FB29C0A4D0C461ULL + 0xCEB644C02A745195ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2612U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 950U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3571U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5078U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 52U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 13204735390996728477U) + aNonceWordP;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 27U)) + 851171359595647173U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 36U)) + RotL64(aCarry, 53U)) + 16745304202825290723U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 562392736584913979U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 57U)) + 3244267012529053918U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17282536111067869133U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14851130066471729068U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6308165353504550619U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5256130407952363129U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2904742485828362001U;
            aOrbiterH = RotL64((aOrbiterH * 12941135856735075457U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3723346325449225387U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5344621093694027341U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 9044881458629673499U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12919263300833603026U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17989801264160996071U;
            aOrbiterC = RotL64((aOrbiterC * 15468293047311883751U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5022175042377172157U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16684822380107847758U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2834049270263837537U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            aWandererE = aWandererE + ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 40U) + aOrbiterK) + RotL64(aOrbiterC, 4U)) + aNonceWordN);
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11934U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 13362U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13945U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8628U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 11U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 58U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 14179205183062705133U) + aNonceWordE;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 210032324058740920U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 21U)) + 7387115089142500152U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 17583362781238061430U) + aNonceWordI;
            aOrbiterB = (aWandererB + RotL64(aCross, 38U)) + 4991442849150005943U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2891376254689854555U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10523274382407446239U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 17443994099359920915U), 39U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 3861893764676218667U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3366674459852093746U;
            aOrbiterB = RotL64((aOrbiterB * 14005994095369483813U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5898492634386601145U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7047353571244768721U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2257518291062508467U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14374108805453186316U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8763667021501226510U;
            aOrbiterH = RotL64((aOrbiterH * 7694695426430267863U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 18261523829316379575U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 650477532238860965U;
            aOrbiterC = RotL64((aOrbiterC * 8291758490821819851U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 4U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterB, 28U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 46U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18874U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21743U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18826U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21582U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 50U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 10U)) + RotL64(aCarry, 43U)) + 439898681482066326U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 57U)) + 17362083676671776094U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererH + RotL64(aCross, 47U)) + 6418499837265155024U) + aNonceWordA;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 17262244253027454972U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 2382066162993139503U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14345808395587174135U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7534743166385552851U;
            aOrbiterA = RotL64((aOrbiterA * 9475127126941982125U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16994453324688523966U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7079553728544045092U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 10104892188895367489U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 3562822704508440641U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13990892681975857821U;
            aOrbiterH = RotL64((aOrbiterH * 8352929306654078795U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1796728922368577238U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6605161260520067178U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8147537646591674091U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13994083795942328918U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6144523182899107711U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4153879991344611283U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 5U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterD, 26U));
            aWandererI = aWandererI + ((((RotL64(aCross, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 13U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27639U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 31512U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30095U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 24657U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 34U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 47U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 6243113109470883144U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 3891552123999605832U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 5U)) + 8758797898587019128U) + aNonceWordL;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 1005891374086408851U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 14U)) + 3713426782180050764U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 18358143862391573534U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17504394029693712404U;
            aOrbiterB = RotL64((aOrbiterB * 3391716204095092531U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5312729289027417014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2560873623431186029U;
            aOrbiterJ = RotL64((aOrbiterJ * 16843728573219210173U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16309322822806704211U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10195513918020652600U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14569219741824123715U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2552116263258744287U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7732784879810980089U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 15041929399477790999U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 16499127570665381507U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10890036715535519036U;
            aOrbiterA = RotL64((aOrbiterA * 9065115450010475187U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 24U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterB, 54U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 22U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordF);
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

void TwistExpander_Fencing_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8732CACE2DFCF463ULL + 0xB16AE28C2010B54AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9BB1791F0A3B95E5ULL + 0x9A02D9123802117FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9F4ECE9850412371ULL + 0x9DBFD519973C8C44ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF116CBEB4340CBE1ULL + 0xAA58D2B33D2692C5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD05D295164A8D1EFULL + 0xCD1DAC6C052DDF7AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x83BF76FFD6FF1B69ULL + 0xD6EFA0D90BACF01AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAA68258DA4611E01ULL + 0x8181245888DBF574ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9ABCC94B8269FF97ULL + 0xAD6FF33C564120CDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB6C1D1851E3B3D27ULL + 0xF5FE186411D760A4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8CB96CAFAF41F86DULL + 0xD8FC87717ADE7E09ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x932DBB65659D23DDULL + 0xB60C9B75E4E4631AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB4CDA620904A010BULL + 0xD85C12318DB22FD9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBD84406DD53DCADBULL + 0xB1495B89FC90B85DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF12B072D952A434DULL + 0xC689CD715F1C7F87ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x984D9B1A326C5945ULL + 0xDFC0EC2C67DDF8E9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x82B16319CF91DEC3ULL + 0xD1C1A6EE6F8A5A3DULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7407U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6295U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1690U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6430U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 29U) + RotL64(aIngress, 47U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 1393781663398437180U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 17414594746688585273U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 58U)) + 2823888497053071250U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 17032631958617884859U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 47U)) + 15222697630461125019U;
            aOrbiterI = (aWandererC + RotL64(aCross, 41U)) + 15737414920751551780U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 3U)) + 1357196111055783001U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5315122321649251691U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7893744655508595974U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17863000246694319149U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16721939414324611738U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3444375866323610848U;
            aOrbiterH = RotL64((aOrbiterH * 10874157227815775661U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1825716513674511632U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15582066843912467318U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 12765146555943757373U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15673590949193923915U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13887365046280406413U;
            aOrbiterD = RotL64((aOrbiterD * 3169061375011420121U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12730414371734709356U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4819112390640821927U;
            aOrbiterJ = RotL64((aOrbiterJ * 8782547948627685451U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 3089925954422937464U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7180179304678622530U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16118051565147747413U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17030269962085008657U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6675917351883004046U;
            aOrbiterG = RotL64((aOrbiterG * 14134335325316949687U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterG, 30U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13630U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12886U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8647U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16328U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 4U)) + RotL64(aCarry, 35U)) + 13583136155674166402U) + aNonceWordC;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 37U)) + 12830472187484919497U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aWandererB + RotL64(aCross, 19U)) + 18081197909484522509U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 57U)) + 8680634051297891550U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 13939998767458656823U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 1795730579103692594U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 51U)) + 17369751719734069999U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 224769585901248068U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4133547085925268180U;
            aOrbiterG = RotL64((aOrbiterG * 2611561365156544735U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 7022512056309567391U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10319484359046945495U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3400140531307001933U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10483878349412282069U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6481381149199985736U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13721077228796934509U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9704818014314175007U;
            aOrbiterD = RotL64((aOrbiterD * 760445624027740287U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6253040047758584339U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16890211690273641226U;
            aOrbiterF = RotL64((aOrbiterF * 5622534399866057841U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6216227831265032436U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2023609047004658739U;
            aOrbiterK = RotL64((aOrbiterK * 3252332895698310147U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9201669637050388263U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5106927540934338576U;
            aOrbiterA = RotL64((aOrbiterA * 6368134569042291431U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 18U) + aOrbiterA) + RotL64(aOrbiterH, 27U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 42U)) + aOrbiterF) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22261U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19084U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19064U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16386U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 380024772508948442U) + aNonceWordP;
            aOrbiterF = (aWandererD + RotL64(aIngress, 29U)) + 7649029098162567210U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 22U)) + 5329304598870421851U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 12306118665045151326U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 37U)) + 960751560457324256U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 3244070254386191876U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 43U)) + 15733408571609521746U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17623448932647018544U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8787759896149035829U;
            aOrbiterB = RotL64((aOrbiterB * 7092515868845497573U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14741681792348288162U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8801731213568307302U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12127126999570616489U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9872248187499779222U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15407371518644528235U;
            aOrbiterJ = RotL64((aOrbiterJ * 1245102406469471673U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4242060317152943062U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9942784962409917541U;
            aOrbiterI = RotL64((aOrbiterI * 888649755587764533U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 7296348796484458631U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15061417216070157797U;
            aOrbiterK = RotL64((aOrbiterK * 10349554676953256231U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3233185810644297433U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9241229457641024287U;
            aOrbiterG = RotL64((aOrbiterG * 2728237515724597517U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8464051359381554575U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3307872165699029375U;
            aOrbiterH = RotL64((aOrbiterH * 4859663401033023433U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterG, 43U)) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 44U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterF, 36U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterI, 51U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 47U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29089U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 32638U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27903U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27440U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 21U)) + 13687218104610230596U) + aNonceWordP;
            aOrbiterC = ((((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 6841550124960692709U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 17418968668458764131U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 8303537912696948204U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 51U)) + 12376614417285936537U;
            aOrbiterI = (aWandererH + RotL64(aCross, 57U)) + 14215749063579232654U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 38U)) + 4111736931433665347U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 11250375934571631522U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5367367837773331275U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7262723007545807179U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15514089192382674434U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 1475991716685034960U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 17720681295551650891U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5531622777788629748U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8363822215908303335U;
            aOrbiterC = RotL64((aOrbiterC * 17850203366840994883U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3741256932685720414U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11634667238062155772U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15925089729784547403U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 18180546911210417155U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5123234656838556335U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15362857462853398025U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11215734271189250284U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16863747802158398092U;
            aOrbiterD = RotL64((aOrbiterD * 1828035970246160023U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9859050606636646323U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9331300036643654675U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 2502263410556166281U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 11U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + aNonceWordN) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Fencing_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCE398F32534FACC1ULL + 0x90CE9446C43EC96CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF73BF4D5CCDE6433ULL + 0xD03050DA8FAD8060ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC2BB313A083E86EFULL + 0xBE87DC04861DD355ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA44292C41E6E1F0DULL + 0x909BD11639740888ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD6954F30590ED46DULL + 0xE04B18D607BC5BB7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE32BB69CCAB5DE79ULL + 0x92EA6666F1E9D756ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9AFED4C8975588C5ULL + 0xD011DC03FF37748AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x93710636D0EA450FULL + 0xA7326B4BB6CBC773ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA9F4CB6BB885A1ADULL + 0x90400BC3CAB01AD0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF84176C71F925BE7ULL + 0xD7E9E957B8268259ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEB97605A03082DE9ULL + 0x98D8DA57E4D1D3C3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCB1AF8FAD0F03AADULL + 0xEFBC19ABD48A2DBEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE6D2B79AFDBC3C21ULL + 0xFC53153F19B7F61CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB80B31362C9A3169ULL + 0x814243173BA5E8E0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x86E1FDE8555B4C37ULL + 0xA7CCA1C51E933A64ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9F19F52D694B418BULL + 0xD75E2AADA527EB28ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1279U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 4339U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6467U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5427U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 16651241552253078315U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 43U)) + 4558144676982478003U) + aNonceWordE;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 21U)) + 8814884320080367550U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 57U)) + 16011579668555672117U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aScatter, 50U)) + RotL64(aCarry, 5U)) + 4738918668759862438U) + aNonceWordH;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 12526083125540985108U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 5U)) + 8048723561746000552U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1082218464034639039U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8432043246965946816U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7801965585991025451U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9982080524048636852U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6720069955755215919U;
            aOrbiterB = RotL64((aOrbiterB * 1025046364205332059U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1019035028070247757U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7360619079463870467U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 6623074813047915863U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10893918488381348474U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1390297670907738019U;
            aOrbiterH = RotL64((aOrbiterH * 11909657437658597735U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12512200589031203480U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14741471280748399540U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 3012135242889901095U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 8543897248359826770U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8545972622733791272U;
            aOrbiterF = RotL64((aOrbiterF * 11793879362775346821U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7049384618581928664U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14730773807906925408U;
            aOrbiterK = RotL64((aOrbiterK * 10711566871536755073U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterI, 58U));
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 23U)) + aOrbiterE);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 53U)) + aNonceWordM) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10026U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneD[((aIndex + 11157U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11359U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10832U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 12U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 1393781663398437180U) + aNonceWordE;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 11U)) + 17414594746688585273U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 48U)) + RotL64(aCarry, 41U)) + 2823888497053071250U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 5U)) + 17032631958617884859U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 35U)) + 15222697630461125019U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 15737414920751551780U) + aNonceWordI;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 41U)) + 1357196111055783001U) + aNonceWordO;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5315122321649251691U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7893744655508595974U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17863000246694319149U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16721939414324611738U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3444375866323610848U;
            aOrbiterB = RotL64((aOrbiterB * 10874157227815775661U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1825716513674511632U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 15582066843912467318U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12765146555943757373U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15673590949193923915U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13887365046280406413U;
            aOrbiterG = RotL64((aOrbiterG * 3169061375011420121U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12730414371734709356U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4819112390640821927U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8782547948627685451U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3089925954422937464U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7180179304678622530U;
            aOrbiterI = RotL64((aOrbiterI * 16118051565147747413U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17030269962085008657U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6675917351883004046U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 14134335325316949687U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 12U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterC, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF + ((RotL64(aScatter, 38U) + RotL64(aOrbiterB, 53U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22136U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 16407U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22417U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneC[((aIndex + 18925U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 10U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 479672811032092393U) + aNonceWordG;
            aOrbiterK = (aWandererD + RotL64(aCross, 18U)) + 18061121631394564425U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 14237400452740566065U) + aNonceWordE;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 6723123812257706134U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 35U)) + 4247997188026499248U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 41U)) + 1939107415066134869U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 57U)) + 3912640123546395979U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8295478436553964298U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3218960600711526885U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15443507655470278069U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5874096203353388890U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10294536533673023358U;
            aOrbiterK = RotL64((aOrbiterK * 15561710414949058923U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11268561953904130747U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16693201256788898423U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16291987237693567209U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7550969634681894654U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9501647424602245869U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 11265865222096866605U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8881869255994319423U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16770136406906800016U;
            aOrbiterI = RotL64((aOrbiterI * 1782039587385512923U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16185384746435761363U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13841034186650721627U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 12000155593277035447U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15229062695864608309U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3576122704615303733U;
            aOrbiterH = RotL64((aOrbiterH * 2433987493885779279U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterB) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 27U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 43U)) + aOrbiterB) + aNonceWordK) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30062U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27691U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29133U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 25562U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 40U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aScatter, 3U)) + 12615321415808640429U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 15712784676459931207U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 11013335427004930046U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 19U)) + 8298733856304768806U;
            aOrbiterD = (aWandererG + RotL64(aCross, 11U)) + 6207732959150824216U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 51U)) + 9769864876127544038U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 19U)) + 10782181918651152563U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 5790454015845620939U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15606578025386733803U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 7079287329365566355U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5522352539991175304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5993355818572869649U;
            aOrbiterF = RotL64((aOrbiterF * 15221467311057431139U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10864534396947622047U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12090053126235913528U;
            aOrbiterJ = RotL64((aOrbiterJ * 7250801471645972261U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14191181677234981396U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2258570108233924592U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8307541155393855209U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8448114811381534603U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2702389315763499817U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6710443836432274393U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17202184076718780200U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 150549910056015002U;
            aOrbiterH = RotL64((aOrbiterH * 195034681254956335U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4910512055808124967U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 4783477997418403079U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 861977492146512865U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 26U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 10U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 20U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordI);
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

void TwistExpander_Fencing_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF2AE852210A35B11ULL + 0xB87A303AB71D15C5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8619D96938112321ULL + 0xB54FC1C07EF663A9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8A8FA24397AD7A09ULL + 0xA1288D476470988AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFD6F3C35C00D6B63ULL + 0xE71793262F76D824ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE9D8A8D145B2DEC5ULL + 0xB3D977863F5B46F8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEC8C28CB37AC1AF3ULL + 0xC027ED88659B2F8FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9E2ED891A5C18A4BULL + 0xAA17AA15464CC6F5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAB04E0A5944C68CDULL + 0xD79390B7B06A3DAEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCF5F6C6922E8A5FFULL + 0x88C0B6DA889293AFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE7961BC193902717ULL + 0xAD3B6F45E3F79468ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAE755D708B271D77ULL + 0xC5DEFCA8414ECEECULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD8684856255893C9ULL + 0xB82E12D0F4077039ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB6D01301A73984C1ULL + 0xD0855BB638BBE052ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC8DE14FDDBACFE69ULL + 0x9FBA7255203C94E1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBFB196C2A8E2CCD5ULL + 0xF3D6D3196CF75C80ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD584FA214A5BFBF3ULL + 0xDCFB9D9C737B412FULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 80U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 2935U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5207U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 4638U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 38U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aIngress, 13U)) + 3236820517816085022U;
            aOrbiterA = (aWandererG + RotL64(aCross, 11U)) + 741288875914097926U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 8417246926007729580U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 35U)) + 9715717805774537170U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 5U)) + 14360243844821619482U) + aNonceWordK;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 26U)) + RotL64(aCarry, 27U)) + 10760908100206775334U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 39U)) + 3434641779946167811U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 57U)) + 7885568822756234567U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 23U)) + 3041563437672051294U) + aNonceWordJ;
            aOrbiterC = (aWandererA + RotL64(aCross, 20U)) + 15761355327564963516U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 1158633562785937421U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9338581575871970653U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9172038894262857354U;
            aOrbiterI = RotL64((aOrbiterI * 3110871165285625807U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14653924713599790081U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3854497592598563309U;
            aOrbiterG = RotL64((aOrbiterG * 11737111068815795303U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16286980180327600557U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5092583772591249756U;
            aOrbiterD = RotL64((aOrbiterD * 13955105624639442903U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4288397994175567333U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15584236478994873104U;
            aOrbiterK = RotL64((aOrbiterK * 1860480595862755379U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5557463939827483792U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2659814275753280856U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 17702430405693184643U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6941807963525063449U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 2040598555191211307U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14750544987531722765U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 347572666231116258U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 779304821185302523U;
            aOrbiterE = RotL64((aOrbiterE * 14180254150318109855U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10632524582873079742U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9761308771280517212U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13926235411726048921U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2097439707055737964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2813977930321463948U;
            aOrbiterB = RotL64((aOrbiterB * 14983538728730662603U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6080592019313796689U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5396623654821376409U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15478858835919398677U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8460497459575045342U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3236820517816085022U;
            aOrbiterC = RotL64((aOrbiterC * 5530411244458067093U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterH, 44U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 53U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 41U));
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterK, 50U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterJ, 37U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 42U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15376U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11171U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16245U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10303U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 38U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 16124889768301047791U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 11912338587186717280U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 19U)) + 8594012868813114354U;
            aOrbiterK = (aWandererB + RotL64(aCross, 56U)) + 18281043566156682815U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 5U)) + 16853106130200942302U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 43U)) + 2611212958619673086U) + aNonceWordJ;
            aOrbiterC = (aWandererI + RotL64(aScatter, 23U)) + 18039472325066855180U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 14495785571345122046U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 11U)) + 4556063793412832418U;
            aOrbiterA = (aWandererG + RotL64(aCross, 48U)) + 14896419970271244358U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 37U)) + 880028529183500036U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2379557167489415783U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11854373946064529806U;
            aOrbiterI = RotL64((aOrbiterI * 150755294320438887U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1487252775956449964U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12777924204511625545U;
            aOrbiterJ = RotL64((aOrbiterJ * 1366019527386994789U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15998631485222477969U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8864212892296191613U;
            aOrbiterF = RotL64((aOrbiterF * 579242788050369815U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17069347835763226743U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7443008171694679791U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 748894368884566607U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17334256152350782002U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8986626119086556393U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 2258172145924120235U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8528180968228358674U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12702290928064582589U;
            aOrbiterB = RotL64((aOrbiterB * 15673603224146737631U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7742438100860023610U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3729687240959702198U;
            aOrbiterK = RotL64((aOrbiterK * 3756794766163746783U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 426129097367382096U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16782175452274911213U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1041477289638333659U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5942016166948841079U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5260815086125551703U;
            aOrbiterD = RotL64((aOrbiterD * 1603799103692438147U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11732742583346900772U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17182924380693084401U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14858685629471497071U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8539335803784852017U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16124889768301047791U;
            aOrbiterG = RotL64((aOrbiterG * 6607245691919237755U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 50U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 40U)) + aOrbiterF) + aNonceWordI);
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterG, 11U));
            aWandererH = aWandererH + ((((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 50U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21463U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19134U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18781U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((aIndex + 20527U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 1708250618750199233U) + aNonceWordN;
            aOrbiterG = (aWandererA + RotL64(aCross, 11U)) + 12009147777553691142U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 29U)) + 8393982703399156592U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 58U)) + 3247327098356831221U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 41U)) + 3403590155376353737U) + aNonceWordK;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 18197244558104735044U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 19U)) + 3096253642040701606U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 8012692688785412179U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 36U)) + 17531946907545680745U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aIngress, 13U)) + 17687695944270225817U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 5U)) + 16147773866007628769U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18244641303026196497U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8839160526348897457U;
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10599266240854068246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2056723540756216155U;
            aOrbiterH = RotL64((aOrbiterH * 13311591601230386375U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4629354220460621284U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9505955649473204942U;
            aOrbiterG = RotL64((aOrbiterG * 17775391885312236187U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17078153810088721310U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9470436761716263000U;
            aOrbiterI = RotL64((aOrbiterI * 5431855497250357229U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3305863413630104742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14377172434239576161U;
            aOrbiterE = RotL64((aOrbiterE * 6880176890091033423U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 415687827894226513U) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16975319836893760993U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6597144958013976445U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12707054129431596074U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8974182792497231239U;
            aOrbiterF = RotL64((aOrbiterF * 7874658957269462717U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10826131924322955095U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4168545139712703154U;
            aOrbiterB = RotL64((aOrbiterB * 10305904857550051705U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4539070253658625193U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3737870219498561326U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13130847633918921393U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11563084648810555040U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7410695535361901473U;
            aOrbiterJ = RotL64((aOrbiterJ * 7540855656023807389U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6687453696858775037U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1708250618750199233U;
            aOrbiterK = RotL64((aOrbiterK * 13104250803527718135U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 44U)) + aOrbiterH);
            aWandererB = aWandererB + (((((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aCross, 18U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterF, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32223U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 26938U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30798U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((aIndex + 27790U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 11U)) + 4384716820085860551U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 9715780315942116888U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 60U)) + 15963520052789178632U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 27U)) + 14346700690686392938U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 41U)) + 6005518012489966643U) + aNonceWordH;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 43U)) + 2506732930310252119U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 37U)) + 16782163084851775826U;
            aOrbiterA = (aWandererI + RotL64(aCross, 19U)) + 823673076571076303U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 53U)) + 1634084509064077736U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 23U)) + 1288134975466877686U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 2998220403162908444U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 220430672180734911U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10223923547068528867U;
            aOrbiterC = RotL64((aOrbiterC * 12577370238343872139U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11696469696177647608U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6545430420379636963U;
            aOrbiterK = RotL64((aOrbiterK * 8387163146257553773U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 79691451831797107U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8971444023498649419U;
            aOrbiterB = RotL64((aOrbiterB * 7148919880477390009U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5624403902454498793U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9468064161002030997U;
            aOrbiterE = RotL64((aOrbiterE * 8243560528100864595U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4619361544913629805U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12682446273369750704U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10879074713156075641U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8728730962617599223U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9099675924074253030U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 5525644236954497523U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3298303921318288541U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 5953276499411658358U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 10565471305001292693U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6725769507592688539U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1057277456510215817U;
            aOrbiterH = RotL64((aOrbiterH * 8269412198279297075U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11317925732206917722U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17814749417006079067U;
            aOrbiterG = RotL64((aOrbiterG * 4369209051015735925U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9258362135343403308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4873837345446960113U;
            aOrbiterF = RotL64((aOrbiterF * 14223381466269503273U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7863380865835889675U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4384716820085860551U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2003891033298374621U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + aNonceWordI);
            aWandererA = aWandererA + ((((RotL64(aScatter, 10U) + aOrbiterG) + RotL64(aOrbiterJ, 6U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 37U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterH, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = aCarry ^ aNonceWordI;
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

void TwistExpander_Fencing_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8E8B94D3B57638ADULL + 0xB8F402E69FF175DEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8E30B722D1860A0DULL + 0xE50A832A3238308EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xABD92E4090A0CCEDULL + 0xD34F00999794C97FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE8D9020527DF3185ULL + 0xDF43C8C9E03F367AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBC12FBC76ADB4053ULL + 0xDE28DC5FC0FFA8F9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA7F7CE2B60B9AB6DULL + 0xCDE6D55C3E8457BAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB2C0121EEA052B77ULL + 0xB50B8460533BA02DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8A5C43D3A44E9385ULL + 0xCFAB26C93793D4E2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x881AF892300B7CC1ULL + 0x9684F665385441DAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB226FB34B191F597ULL + 0xC7E9A5D1DD1CEBFEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD57B90E302586FF9ULL + 0xB297667952464DD1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFFBF7AED5C8BDC3DULL + 0x816F4DB4D7803BD8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x964264E5044534A3ULL + 0xBB6152B778EF40D5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBCCA98ED2A82D1BFULL + 0xB4C21AE7813B40F5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDB060C088DAA02DDULL + 0xB0B7064BD39DE5B1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFD5EA7999D825F0BULL + 0xF041409B83C8B2C4ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4544U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4858U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 560U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 353U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aCross, 23U)) + 8866844335448071821U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 47U)) + 15159698739856430085U) + aNonceWordG;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 9582805772989594633U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 1438538239931588373U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 42U)) + 10862044156620436139U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 13682173320058164615U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 35U)) + 8351013291045977592U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 51U)) + 15777857431516633916U) + aNonceWordE;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 18U)) + 16178966745333885377U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9031889187993001617U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6308472367425865347U;
            aOrbiterI = RotL64((aOrbiterI * 17118710301967158153U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 642109145903321046U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9186268569255318035U;
            aOrbiterD = RotL64((aOrbiterD * 10714674348507516749U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6091345356803675860U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13218507921880873749U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15415157927185637717U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4266652275234474616U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4391422098164506195U;
            aOrbiterJ = RotL64((aOrbiterJ * 17634679403195085867U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5160682323243635577U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 10351728852161347404U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11105410036471745951U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3950932176454814023U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9536466386833427441U;
            aOrbiterA = RotL64((aOrbiterA * 18064984243491293435U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9927425919978776529U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6819384090527481081U;
            aOrbiterF = RotL64((aOrbiterF * 18032965969184368561U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1646274931424218507U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16166524473976135097U;
            aOrbiterG = RotL64((aOrbiterG * 11672192658072663849U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11252501968059485262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16847854447987609067U;
            aOrbiterB = RotL64((aOrbiterB * 6326299154627028295U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterJ, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 12U)) + aOrbiterG) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterB, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7560U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 7722U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6956U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 8827U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 27U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 24U)) + 15383045568644941552U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 53U)) + 17452811657750910067U;
            aOrbiterI = ((((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 15660117718455155603U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aWandererG + RotL64(aCross, 19U)) + 10396441207743665753U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 13U)) + 3708971058200841442U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 5U)) + 7000673057768598750U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 9886354469011131596U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 58U)) + 16018065329058043467U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 5024756166109352320U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6587818720728886652U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3652672354944162319U;
            aOrbiterI = RotL64((aOrbiterI * 10807121230791716109U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6307315649915348048U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 16405347331742979258U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 7183142442906743699U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5427299664054601957U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4983381733483185898U;
            aOrbiterC = RotL64((aOrbiterC * 14646556236306407673U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10182995521328377487U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8694282877540593550U;
            aOrbiterH = RotL64((aOrbiterH * 14614602561910403893U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4085927978153269932U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6176195962815240877U;
            aOrbiterD = RotL64((aOrbiterD * 16792916528959579875U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6966742100601433005U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9920952446921247521U;
            aOrbiterB = RotL64((aOrbiterB * 1879821050131820933U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11958734477518336014U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2058335903640404380U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6986170159285417789U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 77366119537297816U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12072894199692855000U;
            aOrbiterJ = RotL64((aOrbiterJ * 9083781120514635987U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11874297832446385377U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13715562531763053196U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12822488258322963187U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 48U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 38U) + aOrbiterC) + RotL64(aOrbiterD, 39U)) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterE, 44U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aCross, 52U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterB, 58U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15187U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16321U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11648U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15710U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 38U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 39U)) + 1297415699043177788U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 17583786534509260153U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 23U)) + 643197858925708798U;
            aOrbiterE = (aWandererI + RotL64(aCross, 60U)) + 5062653766915694874U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 7034273638367180511U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 27U)) + 2026909726972916996U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 2785690475553211646U) + aNonceWordM;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 34U)) + 2910341716302991892U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 43U)) + 2834181605200829791U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13323052600571281928U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10434901530315760460U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2042210188346767033U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 247903955625194782U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5196515747387257163U;
            aOrbiterK = RotL64((aOrbiterK * 1799024689023272275U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7196305682377987476U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14777739876892587484U;
            aOrbiterE = RotL64((aOrbiterE * 95220583948241581U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10609060796540136671U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8386027207212484155U;
            aOrbiterH = RotL64((aOrbiterH * 4855610536246556893U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 729659744301903424U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2350564261412606157U;
            aOrbiterB = RotL64((aOrbiterB * 16713856782349084977U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16611987556673864177U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1525195188708550503U;
            aOrbiterI = RotL64((aOrbiterI * 10045858602151004553U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4654808490980989596U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8189569777087686263U;
            aOrbiterD = RotL64((aOrbiterD * 17278657566389299577U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10932857495004451792U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1833880112534916813U;
            aOrbiterC = RotL64((aOrbiterC * 8004341577533825681U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13100236350175516423U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2773759534195186313U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 3194954066097323161U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 18U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterC, 36U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 48U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 4U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20578U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17399U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20886U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19287U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 47U)) + 1087148170018530502U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 15530846874509311414U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 24U)) + RotL64(aCarry, 19U)) + 16987358651515511212U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 13U)) + 12504143181007924259U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 393322117322732418U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 29U)) + 14325937299241887166U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 35U)) + 9395262907017475742U) + aNonceWordK;
            aOrbiterK = (aWandererB + RotL64(aCross, 56U)) + 13658510441418344769U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 3U)) + 6410754322737005336U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9257290738538818434U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7489828960857692286U;
            aOrbiterD = RotL64((aOrbiterD * 16519674788777989043U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4118778591214588387U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16619215231168796563U;
            aOrbiterB = RotL64((aOrbiterB * 14876884956536265157U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11326283811003573430U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1865401866017614604U;
            aOrbiterC = RotL64((aOrbiterC * 8378326058282460073U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 670150121105733604U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1499331510641068749U;
            aOrbiterI = RotL64((aOrbiterI * 16623742535540383107U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 1116410848560838532U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2696841341036281779U;
            aOrbiterE = RotL64((aOrbiterE * 9598953298074904869U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5487352391229549881U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12008243050943342979U;
            aOrbiterH = RotL64((aOrbiterH * 9087261224804582459U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 552859665927882960U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8426942688524814473U;
            aOrbiterK = RotL64((aOrbiterK * 10916963622695549105U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1613287981244830815U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15592897923468694288U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6600750586743893303U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7629853970631002676U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13778028957247561272U;
            aOrbiterJ = RotL64((aOrbiterJ * 4063798788229605659U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterI, 18U));
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 43U)) + aNonceWordN);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterH, 41U));
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 4U)) + aOrbiterH) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23766U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22901U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23540U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22640U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((((aWandererH + RotL64(aCross, 6U)) + RotL64(aCarry, 5U)) + 4259993311776766595U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 27U)) + 2857813330021126753U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 47U)) + 1345396841329442896U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 39U)) + 320992148982301024U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 5619109532065293074U) + aNonceWordN;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 10380157329426706345U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 35U)) + 12449831150625409695U) + aNonceWordL;
            aOrbiterC = (aWandererF + RotL64(aCross, 18U)) + 7847096607042268396U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 11U)) + 11707184096803214678U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9893643746186827088U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 333687403830908774U;
            aOrbiterK = RotL64((aOrbiterK * 17911256836121454271U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13837360705077441580U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4367119682175710689U;
            aOrbiterI = RotL64((aOrbiterI * 10295744669174603401U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1193493435041306784U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15062951612027370606U;
            aOrbiterC = RotL64((aOrbiterC * 2509383510565136549U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16000173839235429105U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 15294482444605409961U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 1031800997944302665U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5720749055549773527U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17248674962996093668U;
            aOrbiterE = RotL64((aOrbiterE * 15730637462755795591U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16956840483882091059U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9637715107943515594U;
            aOrbiterF = RotL64((aOrbiterF * 8878362378343603463U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7147495779349862274U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7508890985889484275U;
            aOrbiterD = RotL64((aOrbiterD * 17728368447504622035U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4407738164617959366U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17027017782352660454U;
            aOrbiterJ = RotL64((aOrbiterJ * 417183060881259295U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 3174658601748235285U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 9779053567370714831U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6383245776181968033U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 24U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 12U) + aOrbiterE) + RotL64(aOrbiterC, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterI, 22U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterC, 51U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            aWandererB = aWandererB + ((((RotL64(aCross, 28U) + RotL64(aOrbiterD, 30U)) + aOrbiterI) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29112U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31298U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29928U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 31033U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 23U)) ^ (RotL64(aIngress, 38U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aPrevious, 5U)) + 6024062041314952357U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 29U)) + 18340757093658015585U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 34U)) + RotL64(aCarry, 5U)) + 11911120493880346751U) + aNonceWordD;
            aOrbiterE = (aWandererE + RotL64(aIngress, 21U)) + 17428074353884654439U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 12790849760814795936U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 47U)) + 12633397052172117800U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 11946150433665237945U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 53U)) + 16842157900909419285U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 10U)) + 14186235783224155962U) + aNonceWordH;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13284904542579767591U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11609181965078844357U;
            aOrbiterG = RotL64((aOrbiterG * 5455780554452453513U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9628562297095374984U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7850281529011259759U;
            aOrbiterK = RotL64((aOrbiterK * 17611485102925470357U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 257458718073794527U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10693404545773519306U;
            aOrbiterF = RotL64((aOrbiterF * 14821443722828498323U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3430519236533871460U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6183054506953198055U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 6121082743789970911U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2905610989884221654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4472163910775333862U;
            aOrbiterI = RotL64((aOrbiterI * 7770678426310856745U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16870142883133769663U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1403692060594816451U;
            aOrbiterD = RotL64((aOrbiterD * 9740854430251597879U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 16904169913507057108U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4773518591580333357U;
            aOrbiterE = RotL64((aOrbiterE * 5306070307776061267U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6528141733853494275U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11254806909313951442U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6316669786405548827U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6857506858448143407U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2855763534355983644U;
            aOrbiterJ = RotL64((aOrbiterJ * 16881334940165182415U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 10U) + RotL64(aOrbiterD, 60U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 24U)) + aOrbiterE) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordM);
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

void TwistExpander_Fencing_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8162A8D3C6E8C66FULL + 0xB8DCFD63771B4D98ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE7AC43F4BDB6AC39ULL + 0xEC1F15A50CE6561AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFBB4CF07336E4AD3ULL + 0xFF097A95DC663B89ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDE810AB9AABBBB57ULL + 0xCBD3EC39D3B43D6EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD2B34401CDFFCB0BULL + 0xACE8C81C693E6375ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x96CD05C1EC31272BULL + 0xE2B0052ADAA5C2A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC2F00C7FA710303BULL + 0xF2722AFF190332E9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF03930AF4CA5BC39ULL + 0xC7BFD96AB8BE6E1DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF63D8BEC1F85AE43ULL + 0xFBD18F112E003B6AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF678FE79030CE7CFULL + 0xE68F60DF405B000CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9068CD88804FED95ULL + 0xF058B850AFE68716ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA65B7FAE5DC04B5FULL + 0x95419702E9E379BBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x952042DEC2C0B1FBULL + 0xDDA8035814FDE3E8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD2436BCEE83705B3ULL + 0xC30689127CC99791ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB7EC3B568D414489ULL + 0x912397E0E271D9B5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD135B128AF8B9825ULL + 0x897EE70AA6AD42EAULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1000U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4887U)) & W_KEY1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4818U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3968U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 2915859148137000694U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 53U)) + 210680583721444425U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 6668118118775650387U) + aNonceWordK;
            aOrbiterI = (aWandererH + RotL64(aScatter, 19U)) + 15794200818099010989U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 47U)) + 6565076707062828369U) + aPhaseAOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 4U)) + 16323164497808856719U) + aNonceWordL;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 7965435318816716560U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7390281030573369017U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2269738866911824875U;
            aOrbiterF = RotL64((aOrbiterF * 1198697877998135567U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 9664014216039993873U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18284857398028357633U;
            aOrbiterE = RotL64((aOrbiterE * 8402008251343393737U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 367667619795303009U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 7935945060956274197U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 5481786693511955209U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16683666162337789540U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10655658270998102390U;
            aOrbiterG = RotL64((aOrbiterG * 15231596813382239841U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8307037916581540297U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3247742749860703524U;
            aOrbiterJ = RotL64((aOrbiterJ * 15052136713218656641U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10446792483683818139U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 16374602929344972364U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12599903932725787599U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 2411334498322777183U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1093701164116833765U;
            aOrbiterB = RotL64((aOrbiterB * 13129220206835381729U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 28U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterB, 11U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + aNonceWordA);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 48U)) + aOrbiterJ) + aNonceWordM) + aPhaseAWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6852U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 5620U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8424U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7982U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 29U) ^ RotL64(aPrevious, 60U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 7651355040951791298U) + aNonceWordK;
            aOrbiterC = (aWandererF + RotL64(aIngress, 29U)) + 13988210277931659312U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 52U)) + 9846849412579537783U) + aNonceWordN;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 12746719939495876158U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 43U)) + 11498066185182895284U) + aPhaseAOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 5U)) + 11101058955193080232U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 15513734459555672046U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15711108675349394643U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4771231759949468556U;
            aOrbiterJ = RotL64((aOrbiterJ * 9806191054594333615U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11449258010811305256U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17036938391509986723U;
            aOrbiterB = RotL64((aOrbiterB * 7411466953205347639U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6999245666776654250U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2106819066263369528U;
            aOrbiterE = RotL64((aOrbiterE * 13005885810757743129U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12716183358903477216U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16752724547046059889U;
            aOrbiterC = RotL64((aOrbiterC * 11475905692393034141U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 17623077680983093163U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6726003022297274986U;
            aOrbiterK = RotL64((aOrbiterK * 14709385877103232653U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2842410225096524740U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9235178377537910514U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11813751114775673845U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2619888019860844610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6295481948199619613U;
            aOrbiterA = RotL64((aOrbiterA * 15429161806953951205U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 50U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 11U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 58U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + aNonceWordB);
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15384U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 14769U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10995U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13829U)) & W_KEY1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aPrevious, 41U)) + 17225673071833726819U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 21U)) + 10301458382103627331U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 53U)) + 3960233050857362414U) + aNonceWordD;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 6U)) + 17768665685046605837U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 14471018461213959767U) + aNonceWordC;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 10730597892721340453U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 14863394003122760542U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9948587274816688296U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3573569431435100993U;
            aOrbiterK = RotL64((aOrbiterK * 2303922230056523077U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 8153670675740450590U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 16438856577722561424U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 4689247488336908827U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15765587867581925041U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1082039522061775213U;
            aOrbiterA = RotL64((aOrbiterA * 17023740047246402641U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4202521649260798876U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15877659681260461141U;
            aOrbiterB = RotL64((aOrbiterB * 11369910758551088173U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2551560426129646123U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3005102326163906320U;
            aOrbiterJ = RotL64((aOrbiterJ * 4241583192662435107U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1675501058857208089U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12774812270956702043U;
            aOrbiterI = RotL64((aOrbiterI * 5488437008504905105U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1044886020922563597U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4857445127457225171U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13223560654459705259U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 60U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 11U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererD = aWandererD + (((RotL64(aCross, 14U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 43U)) + aOrbiterK) + aNonceWordA) + aPhaseAWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterE, 4U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18248U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 21639U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17252U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 19085U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 1952750591494698524U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 27U)) + 4488270851303332830U) + aPhaseAOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 41U)) + 2738763375328927635U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 53U)) + 6728843649480454340U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 4U)) + 10490717875258865358U) + aNonceWordN;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 1429288737812910205U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 2761375016998907636U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1088988605204499835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6829840407300289709U;
            aOrbiterB = RotL64((aOrbiterB * 13101432880030791787U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9267240337867690471U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8120113021183975703U;
            aOrbiterA = RotL64((aOrbiterA * 14296504593187173107U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1340980511302566784U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11874452169979878835U;
            aOrbiterI = RotL64((aOrbiterI * 8638486178860092537U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1872314794140971426U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6013952618696225751U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 7994863587373565715U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3644011378086236002U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8501867691997891731U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7115282675461711509U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2493546555198066143U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5179240189571799179U;
            aOrbiterJ = RotL64((aOrbiterJ * 1267579130962756135U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11273348247858394197U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4577476419423118925U;
            aOrbiterG = RotL64((aOrbiterG * 8427261005061162673U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 60U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterC, 21U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + aPhaseAWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aNonceWordA);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 46U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25348U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23641U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24131U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26223U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aScatter, 51U)) + 4980738603982643969U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 3U)) + 17660278413018470020U) + aNonceWordK;
            aOrbiterK = (aWandererD + RotL64(aIngress, 57U)) + 17598114429859543466U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 5U)) + 10993929335279994739U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 17967203122976322481U) + aPhaseAOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 35U)) + 1872290205549034384U) + aPhaseAOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 16607778671782810797U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4895226930754394376U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14960359005982301383U;
            aOrbiterK = RotL64((aOrbiterK * 8546231310054433721U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9921642352377700630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 893281964367208693U;
            aOrbiterB = RotL64((aOrbiterB * 2345509157333444217U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8232519988397858732U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4433022122758913407U;
            aOrbiterH = RotL64((aOrbiterH * 834240393225479419U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12689609831247168353U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 404535388957472176U;
            aOrbiterC = RotL64((aOrbiterC * 14534020545479806593U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3349108201964013155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4386449511297371730U;
            aOrbiterJ = RotL64((aOrbiterJ * 9596273264321140229U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14314587717949070586U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10923886625271054985U;
            aOrbiterI = RotL64((aOrbiterI * 7838969002623486809U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17634909585329833520U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2021301459918350372U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 1388242915918642741U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 56U)) + aOrbiterH) + aNonceWordH) + aPhaseAWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 13U));
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + aNonceWordL) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32689U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 31437U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29896U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30651U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 12669015908335980355U) + aPhaseAOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 5438715179868613192U;
            aOrbiterA = (aWandererH + RotL64(aCross, 5U)) + 13172104448184536460U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 28U)) + RotL64(aCarry, 57U)) + 13421421503244744803U) + aNonceWordC;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 21U)) + 13327113302994856582U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 11U)) + 4671768205922454413U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aCross, 35U)) + 5355759962838579929U) + aNonceWordO;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 6691720614265406851U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7063906424700911378U;
            aOrbiterA = RotL64((aOrbiterA * 17091734375516280675U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17328616394166672263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1542940602574207068U;
            aOrbiterI = RotL64((aOrbiterI * 8981679306319627975U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7203866278803132454U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 993485696233139264U;
            aOrbiterB = RotL64((aOrbiterB * 11609009908810366447U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15659679028507488331U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 18321361454094675842U;
            aOrbiterD = RotL64((aOrbiterD * 3966860765622641843U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9633319822696783352U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3496559332232402963U;
            aOrbiterG = RotL64((aOrbiterG * 7772060229838162977U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1918349708324205526U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7701088402761359134U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9649485438465644795U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6006824348814439686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18088375375347012557U;
            aOrbiterH = RotL64((aOrbiterH * 12801082943086128385U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordG) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 6U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 28U)) + aOrbiterF) + aNonceWordM);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aPhaseAWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_Fencing_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB7CB9DC68BD1B611ULL + 0xAA336B7E6E699DD4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB08134DC2A9EA9A9ULL + 0xA2CB30ED46439156ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x87ABDDB9E1DF7859ULL + 0xFAC648FBBB41E80AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFC7BDF8F8877D503ULL + 0x8FF06779D4C20FBDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE66BBE863FD1F6C1ULL + 0xD76F08FE8E1E96B5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAFCF4FC8E8333311ULL + 0xA9500E9E899E4A44ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9BAFE1FB2798F511ULL + 0xF2B12206334962B1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB67CA54BAACC3FB3ULL + 0xE8B1515EB560DABDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEF748D594C707947ULL + 0xE74A57F31D25A9ABULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBF1A838E7AC9C8C5ULL + 0xA85F8EC9C10D7F4DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDB9BC1494116E33DULL + 0xBF72166DBFE0D4F8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBCB220644F290A85ULL + 0xB81E1DFBFB175EC2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xACA3FD117D85FF1BULL + 0xC8CD919F76193A8CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x97FD3BD0DE98D47FULL + 0xA58B43D09E42AC21ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEB62CDF5423E0F51ULL + 0x9706D9C108699A62ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB3D21FCD0F2FC649ULL + 0x8673DCE8F1709827ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5026U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 88U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5169U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 1855U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 1087148170018530502U) + aNonceWordK;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 3U)) + 15530846874509311414U) + aPhaseBOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 16987358651515511212U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 12504143181007924259U) + aPhaseBOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 26U)) + 393322117322732418U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14325937299241887166U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9395262907017475742U;
            aOrbiterD = RotL64((aOrbiterD * 3442643798173589117U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13658510441418344769U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6410754322737005336U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 6932217611373076391U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9257290738538818434U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7489828960857692286U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 16519674788777989043U), 21U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 4118778591214588387U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16619215231168796563U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14876884956536265157U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11326283811003573430U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1865401866017614604U;
            aOrbiterE = RotL64((aOrbiterE * 8378326058282460073U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 18U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 38U) + aOrbiterF) + RotL64(aOrbiterJ, 43U)) + aPhaseBWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 4U)) + aOrbiterF) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9136U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 9333U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9656U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 6522U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 29U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererD + RotL64(aIngress, 48U)) + RotL64(aCarry, 57U)) + 11521331427196538632U) + aPhaseBOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 19U)) + 16653824187682957632U) + aNonceWordO;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 11654676587350088289U) + aNonceWordJ;
            aOrbiterD = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 8010313317412193584U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 29U)) + 1108775560502907471U) + aPhaseBOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 243952321439823521U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2324945800401240403U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9471328582043504473U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9257554497543369657U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16701314607244592540U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8790054741039817107U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3900445848034341782U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7652316487347103658U;
            aOrbiterF = RotL64((aOrbiterF * 11480123491361589799U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14980368605272070578U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2001165460948764796U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8110980921827107649U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1911044015666991050U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11366207111147818339U;
            aOrbiterD = RotL64((aOrbiterD * 17234439040652553865U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererD = aWandererD + (((((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aNonceWordP) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 14U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13042U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 15357U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15180U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 15459U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 54U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 29U)) + 898812731947995389U) + aNonceWordH;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 52U)) + 8677347622525527167U) + aPhaseBOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 770321564027567654U) + aPhaseBOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 11020474858081526395U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 17289793580414993470U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10111912559295118444U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8083622125544542011U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 3610772128071340341U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7149858558922988240U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5919683821379905699U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16705119888884231567U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6860902846079238714U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15083517836867542075U;
            aOrbiterE = RotL64((aOrbiterE * 4686657139237578325U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14852868368708376381U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9860233289028878323U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13418143547952204667U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 772406119079116272U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7971141501337627589U;
            aOrbiterC = RotL64((aOrbiterC * 10168120622976358617U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterG) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 54U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 37U)) + aPhaseBWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21306U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 18172U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16519U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20422U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (((aWandererD + RotL64(aCross, 5U)) + 785861751704720606U) + aPhaseBOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 43U)) + 15968088718435606299U) + aNonceWordO;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 1393976526590347151U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 54U)) + RotL64(aCarry, 19U)) + 17240750947292745884U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 4921576136163183137U) + aNonceWordM;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3334047873553153032U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15086509978458408698U;
            aOrbiterG = RotL64((aOrbiterG * 2162818176367899893U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 892391205397581998U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2965686403183767521U;
            aOrbiterK = RotL64((aOrbiterK * 709160942482770225U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14632215393655706170U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 15740589515342377322U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 15677716942904794913U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11131164813943086445U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6988080581278900960U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6412189142344044255U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 16021254613117657178U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 6183615599897921154U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 9976411093264211033U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterB, 37U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + aNonceWordB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22779U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27268U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24562U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26733U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 5573188770530340913U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 1431772230889897111U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 4809192776429682319U) + aPhaseBOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 5U)) + 5576603692574369341U) + aNonceWordA;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 39U)) + 2720143226007220386U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17220328778565331629U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9629485808442089423U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18349580416082045015U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1136998437010390983U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11893390497814523841U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 5329621622743089531U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1764986431917532370U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1741014798007010376U;
            aOrbiterF = RotL64((aOrbiterF * 13414914086049500731U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12221368453236547044U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7694538641172350430U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8439120733670016501U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17472344518811560603U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3308740700728172984U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15290400462887712083U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + aNonceWordN) + aPhaseBWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterJ, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29614U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 32376U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27511U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29662U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 54U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 5171470532667965920U) + aNonceWordB;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 750549462358682403U) + aNonceWordD;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 57U)) + 3325689257577120525U) + aPhaseBOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 38U)) + RotL64(aCarry, 51U)) + 18031575461559790826U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 29U)) + 13874739537012288677U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4250029868785016865U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8211158803112611161U;
            aOrbiterC = RotL64((aOrbiterC * 9205801383408193959U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1083939790236786027U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3446525462376962464U;
            aOrbiterD = RotL64((aOrbiterD * 13603702473750888213U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6973817815000417325U) + aNonceWordM;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 15230876489676945543U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 7737039082964537651U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9359727659738755880U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8775170107816327654U;
            aOrbiterH = RotL64((aOrbiterH * 6910680458261008653U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11958941755525038545U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16966819714283167348U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 16363457661846050749U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + aNonceWordF);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 19U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterH, 37U)) + aPhaseBWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Fencing_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA71B136803188A1DULL + 0x9206A7640C3B56A4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x86C811BE28176E73ULL + 0xF3E94A2FB5E497C1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDDC6C02221197E07ULL + 0xA5484033B54EBB79ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB62DF689477504B5ULL + 0x817C6A8B05ECCC77ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB01898A62F3E1EB7ULL + 0x9D4D398DBA6CC4CEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC0D5F9FF6C150595ULL + 0xB10AB04FD33CB512ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFD5DD96F057F21CFULL + 0xBC131904AA9FE588ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF110E2DF21BEDFD3ULL + 0x8FBE9A72E4C25F6DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE1E314365ABB677BULL + 0xF82DD70D49687605ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x823BC988D38C986DULL + 0xF966811DE9AAF51BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA7F13A8A688D7E6DULL + 0x9BCF65CACCE88888ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF50C2F4E5B99C41FULL + 0xF44BBEDD7F3A8ED3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD92D99DF1EC5B38DULL + 0xEF329D79666708F0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD22F5E316196BED7ULL + 0xEB235C9576C1828BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC031825F9DCE9927ULL + 0xBED836E4537AA784ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA5F102DE6128EAD5ULL + 0x8CCAFDAB9D114C81ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2734U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2937U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7959U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5488U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 5U)) + 10336802574069791273U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 28U)) + RotL64(aCarry, 35U)) + 169025388197058936U) + aPhaseCOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 23U)) + 6541354188379168846U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 13U)) + 16223920526599306104U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 39U)) + 12756613707692514808U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 43U)) + 5082475548176484035U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 4907435526952698526U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 14236627073831834337U) + aNonceWordP;
            aOrbiterG = (aWandererD + RotL64(aIngress, 52U)) + 11502511046130497584U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3679044835550219497U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11254838916686736746U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8631695922983532915U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10582608424233200966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4628253464169957835U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17664454668473204465U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4234720298731378527U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3798386391743884889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1379331161819246587U;
            aOrbiterG = RotL64((aOrbiterG * 13086160171095077295U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 9816600392407327227U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16781971616348376878U;
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4807797577690520554U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2492057261148595922U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9453302540675483005U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7909676419643119585U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 256053568910383007U;
            aOrbiterA = RotL64((aOrbiterA * 11965085163352053161U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16179914439220412472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3968867762761955845U;
            aOrbiterF = RotL64((aOrbiterF * 7473632378251893139U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7474832923901283742U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4736994731050735779U;
            aOrbiterD = RotL64((aOrbiterD * 9839654409121414047U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 24U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aNonceWordH) + aPhaseCWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterF, 18U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 10U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14580U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12097U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9235U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11627U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 53U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 4U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 21U)) + 8975885703279267062U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 8664844915562660637U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 11U)) + 12281774799736296726U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aCross, 27U)) + 15347461352311329726U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 41U)) + 12967500561828907834U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 35U)) + 5002833859280402726U) + aNonceWordB;
            aOrbiterF = ((aWandererG + RotL64(aCross, 52U)) + RotL64(aCarry, 57U)) + 11908257536954668983U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 3U)) + 17017174811949227162U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 21U)) + 16851323125613931180U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13469326957728686706U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5228638551056105241U;
            aOrbiterI = RotL64((aOrbiterI * 13369947664646167255U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11945166198089308564U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16268645041872996022U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 5391448793718370911U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14781204627695095701U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5365325354838101092U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8017284997946310807U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 563147416025715953U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14660867395395625851U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4769458126865307103U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3168989056355712105U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16179131669773665579U;
            aOrbiterH = RotL64((aOrbiterH * 5641461617066671723U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4160220074225527179U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8597134686962559111U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 639572585431474015U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16811551552456811661U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5827323970423386301U;
            aOrbiterC = RotL64((aOrbiterC * 9328247349730652021U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15583234353262170227U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2950816254621717748U;
            aOrbiterE = RotL64((aOrbiterE * 1102417597476170143U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4426165025104306337U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11871220132164971152U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 2366168050042802207U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 24U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterJ, 22U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterF, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aPhaseCWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterD, 43U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererC = aWandererC + (((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 35U)) + aNonceWordP) + aPhaseCWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterD, 56U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21055U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19173U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16623U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 16717U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 13350544654542863236U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 12364346790125404372U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 18U)) + 9738750172849512764U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 5U)) + 3781373837635491421U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 11U)) + 16635020317512702337U) + aNonceWordI;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 47U)) + 5383653921676231276U) + aPhaseCOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 26U)) + RotL64(aCarry, 37U)) + 10181959815492056493U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 43U)) + 10005510924273927017U) + aPhaseCOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 51U)) + 9524687662265740565U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4259138552009771014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8973051213213726023U;
            aOrbiterC = RotL64((aOrbiterC * 12625091476068190979U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17602611840127337490U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8218984546932905269U;
            aOrbiterF = RotL64((aOrbiterF * 17504305273683304231U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18102186122213487888U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2629927500298092976U;
            aOrbiterJ = RotL64((aOrbiterJ * 6983280164448292723U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2491581597835795234U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9506602492971620955U;
            aOrbiterH = RotL64((aOrbiterH * 9559829640915637163U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13422942713680612924U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15037354693234876601U;
            aOrbiterG = RotL64((aOrbiterG * 12692376075738621447U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12896066842192894694U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2202952306291905855U;
            aOrbiterE = RotL64((aOrbiterE * 6779368532763429997U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12160313482450599313U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10812986281270407756U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7786608700746771809U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12474638293190144525U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5882870951276225224U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15532427302173572457U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3782896138051179209U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10965680631059882311U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14060923998307082385U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 28U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterI, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 28U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 58U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterE, 43U)) + aNonceWordL);
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aNonceWordK);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 48U)) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25878U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27605U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27494U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 31289U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 51U) + RotL64(aIngress, 20U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aCross, 56U)) + RotL64(aCarry, 47U)) + 6318740973868639425U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 5487840061430920881U) + aNonceWordF;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 41U)) + 10258706763248072672U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 18356875269730338208U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 27U)) + 12883160282903147010U) + aPhaseCOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 5U)) + 1010140474942697730U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 51U)) + 17733939421700898293U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 23U)) + 13693055887924981201U) + aNonceWordI;
            aOrbiterC = (aWandererA + RotL64(aScatter, 12U)) + 14574732452793385269U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10832873941223609012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8212600587135328040U;
            aOrbiterD = RotL64((aOrbiterD * 5334613996794796145U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5312744319781971178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6173741211706546923U;
            aOrbiterH = RotL64((aOrbiterH * 12854414066390848249U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3693249147883790810U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 18365859989736602556U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 3348463719324104997U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10645056678337549771U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1175668356822251045U;
            aOrbiterG = RotL64((aOrbiterG * 6579675292775345579U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13556844570541823717U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4790355739411849736U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4083544011788850307U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14905575502272644116U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17047244574558476634U;
            aOrbiterI = RotL64((aOrbiterI * 2356386971503880047U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10161614295718414869U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13413914082651612468U;
            aOrbiterB = RotL64((aOrbiterB * 16224039093981079491U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6072693130156927774U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4333656233793103787U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9374745547133955709U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17209776289202130250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11752001118070361543U;
            aOrbiterF = RotL64((aOrbiterF * 4416523594812872339U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 14U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 18U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 48U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 41U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterC, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 36U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterG, 60U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordC);
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

void TwistExpander_Fencing_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF7AD76211789C0EBULL + 0xCF9C4E81C5283AF1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD23BE2F7510754D5ULL + 0xEFE0D421AACA7CBAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCC74AC8856E678F7ULL + 0x89AEB2365E880B99ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9BAF82254522CF6FULL + 0xB23ABFD35C5A597DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBA8D33C6B606ADFDULL + 0xC21C1820C7517D0CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA8F2FCFD32B7322DULL + 0xD93F2AFC23C2BE9BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAC88CBC3A1436CE9ULL + 0xFBE430C8467DFA3CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBA17608F0E83B7D5ULL + 0x865C33242017649DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBC26DA8297C290ADULL + 0xB8CFD3B80CD92F4CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFEF29DB3F2076A13ULL + 0xD6EDA252C2300794ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9C23AC206BB6402DULL + 0xCCAA1EC342510E5EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE20E40AA5BE5B995ULL + 0xBB5580ACAB489FC5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCC84C7778FD16303ULL + 0x9706256F67862001ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEEB4C668C7208BC1ULL + 0xB8605B425E3246A4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCF916E406B9E6A9FULL + 0x98CDAEA075E4FC2CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB9EE1673B3BBD879ULL + 0xA28088438CFF6295ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3334U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 623U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1055U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4144U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 11998579547770778580U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 8409465187298704610U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 41U)) + 3470222286110333500U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 5704486785203069994U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 10U)) + 10334944660253279633U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 51U)) + 7626852700722567477U) + aNonceWordA;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 43U)) + 14631310754943209743U) + aPhaseDOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 27U)) + 807160297237854120U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 3U)) + 5624154783624196107U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 24U)) + 4971444394698940423U) + aNonceWordJ;
            aOrbiterI = (aWandererD + RotL64(aScatter, 21U)) + 6340057638461027062U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9003019862787819481U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13632057463595873033U;
            aOrbiterK = RotL64((aOrbiterK * 12575202147280216765U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12766104026871797746U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4062118445824915939U;
            aOrbiterJ = RotL64((aOrbiterJ * 13130770039048080701U), 11U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 5258212525426469978U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9956946981015983939U;
            aOrbiterD = RotL64((aOrbiterD * 8106382657040497669U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10837606223056473999U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13292864885504191134U;
            aOrbiterC = RotL64((aOrbiterC * 4445739587553669471U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 166087925900318658U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6786842221885441388U;
            aOrbiterG = RotL64((aOrbiterG * 4411147600413147773U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16888086378070246404U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5240855484445974002U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 402652898573422271U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6874866669211571608U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 732890824978127460U;
            aOrbiterI = RotL64((aOrbiterI * 3776365957702257453U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5541380495707308058U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17947326584411475765U;
            aOrbiterH = RotL64((aOrbiterH * 10920952349981652899U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15060679340045767910U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1675974028461383576U;
            aOrbiterA = RotL64((aOrbiterA * 15127962310365242819U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 226889112033170368U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4290719734244011388U;
            aOrbiterF = RotL64((aOrbiterF * 6453598182035414143U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 7712233480730639084U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11998579547770778580U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11599893373156816375U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterK, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 28U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterI, 14U)) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 50U)) + aOrbiterB) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aIngress, 50U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterF, 39U)) + aNonceWordF) + aPhaseDWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10448U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5596U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8483U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6107U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 4U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 3U)) + 14179205183062705133U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 57U)) + 210032324058740920U) + aNonceWordN;
            aOrbiterA = ((aWandererG + RotL64(aCross, 14U)) + 7387115089142500152U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 47U)) + 17583362781238061430U) + aNonceWordH;
            aOrbiterH = (aWandererB + RotL64(aScatter, 21U)) + 4991442849150005943U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 2891376254689854555U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 10523274382407446239U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 11U)) + 3861893764676218667U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 3366674459852093746U) + aNonceWordG;
            aOrbiterC = (aWandererC + RotL64(aCross, 23U)) + 5898492634386601145U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 60U)) + 7047353571244768721U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14374108805453186316U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8763667021501226510U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7694695426430267863U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 18261523829316379575U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 650477532238860965U;
            aOrbiterD = RotL64((aOrbiterD * 8291758490821819851U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2162326554604894042U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5776546692501825278U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 14911545784585246537U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3501863793638415049U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14853789267425352958U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 10590325397179928739U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15399673014671329743U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12253428583438990426U;
            aOrbiterG = RotL64((aOrbiterG * 12052855472196447849U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13202953937621953839U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7547616636832698398U;
            aOrbiterB = RotL64((aOrbiterB * 9533399972562428073U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15709801946594868318U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12458677982746610971U;
            aOrbiterE = RotL64((aOrbiterE * 6662570874316418993U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6957370791367530127U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10511379961344950861U;
            aOrbiterF = RotL64((aOrbiterF * 15551333099264031337U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16489828646914719181U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6827290294344770680U;
            aOrbiterI = RotL64((aOrbiterI * 6408864925398536651U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3308531598034561099U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10336568208337990458U;
            aOrbiterC = RotL64((aOrbiterC * 5606941634846696657U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14116471880098183908U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14179205183062705133U;
            aOrbiterK = RotL64((aOrbiterK * 8824119255416045191U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterD, 37U));
            aWandererH = aWandererH + (((((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 29U)) + aNonceWordL) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 38U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 4U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aNonceWordF) + aPhaseDWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterA, 41U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterG, 30U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 27U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11850U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 11280U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13552U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16055U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 48U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 51U)) + 11039986441331892533U) + aNonceWordD;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 53U)) + 6256024955965426119U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 19U)) + 9857443189988995666U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 11900944813380998208U) + aNonceWordB;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 11U)) + 8422577734978875541U) + aPhaseDOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aScatter, 27U)) + 3100835100713928724U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 11871553509810206993U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 30U)) + 17614749493763417027U) + aPhaseDOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 47U)) + 3638372131856199916U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 23U)) + 6582275259281025770U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 35U)) + 17016882418498941958U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1747214688658984715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9356088987044015278U;
            aOrbiterC = RotL64((aOrbiterC * 16221733545319753695U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4056238112133473456U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16013150119949532998U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 12913648646318115315U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16076621211111834889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9940824359571581765U;
            aOrbiterE = RotL64((aOrbiterE * 11624767861336495331U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15624084004784515753U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7630989544834680335U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12261063237156822067U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 18003586430673313786U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1654118743290334161U;
            aOrbiterA = RotL64((aOrbiterA * 1153250137357176071U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3254189676528343910U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15629083361573065165U;
            aOrbiterK = RotL64((aOrbiterK * 17024833368570949107U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10056859810555674806U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15976683222786846254U;
            aOrbiterD = RotL64((aOrbiterD * 2801754232182942635U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11872378594829637933U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7633773773528713489U;
            aOrbiterI = RotL64((aOrbiterI * 8218288492011593353U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16305188578382203720U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13293036594949754170U;
            aOrbiterG = RotL64((aOrbiterG * 1300645662609848183U), 53U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 15185013801659166674U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11562899709899198100U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9115495024409604629U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1525205566739385260U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11039986441331892533U;
            aOrbiterJ = RotL64((aOrbiterJ * 9802284050237622047U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 43U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 54U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterD, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterB, 14U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 48U) + aOrbiterH) + RotL64(aOrbiterF, 57U));
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 23U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererA, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 18311U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20635U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18118U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 21449U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 40U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 39U)) + 15036852811491820366U;
            aOrbiterC = (aWandererH + RotL64(aCross, 10U)) + 305637140752898475U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 51U)) + 11948631574496129610U;
            aOrbiterF = ((((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 5321623592482991426U) + aPhaseDOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aWandererD + RotL64(aCross, 23U)) + 4075270159062690728U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 19U)) + 15111580500356908928U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 35U)) + 7244150695504160363U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 47U)) + 5131563519577488862U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 5881954992088651371U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 27U)) + 12780935808751507998U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 37U)) + 12599159643925470226U) + aPhaseDOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9466589929741834066U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6093158735705189789U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7453778295800853653U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17461243886150519249U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15456408913739900718U;
            aOrbiterH = RotL64((aOrbiterH * 16093292401746174671U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11260643903290392780U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7870342756041882616U;
            aOrbiterI = RotL64((aOrbiterI * 2431528656086173419U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 134484990005888936U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10626896209992890407U;
            aOrbiterK = RotL64((aOrbiterK * 12034131076645285597U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14031164129515132292U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1771835705730244212U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 186981668443596623U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16395472745067254664U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 1455944290845294254U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 6757824754363319079U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17866422769075350837U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10226884082632410805U;
            aOrbiterJ = RotL64((aOrbiterJ * 206035536985843815U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14474587247775371703U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8501763445324525303U;
            aOrbiterD = RotL64((aOrbiterD * 5298694643596784007U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 222650368553738561U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3901452368735982094U;
            aOrbiterE = RotL64((aOrbiterE * 18347115513126660483U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3063093906728331146U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9026710562384443411U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8411243802199203035U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11282041925238364080U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15036852811491820366U;
            aOrbiterF = RotL64((aOrbiterF * 18185121326941087841U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 20U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + aPhaseDWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 51U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 43U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterD, 24U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 41U)) + aOrbiterG) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererH, 28U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23832U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 23528U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26032U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25349U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aPrevious, 53U)) + 9080426856729228705U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 4U)) + 7851218321653539276U) + aPhaseDOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 35U)) + 7023344692919298036U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 9772846154227440734U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 29U)) + 12008298632429608431U) + aNonceWordB;
            aOrbiterB = (aWandererK + RotL64(aScatter, 13U)) + 12201090455849562875U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 21U)) + 9498721803411445471U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 11U)) + 351203764023093632U;
            aOrbiterA = (aWandererE + RotL64(aCross, 23U)) + 4966360430644539250U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 9194167899071345693U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 43U)) + 4922477697284269116U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15742625291642356429U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7528703106518431730U;
            aOrbiterK = RotL64((aOrbiterK * 11530049278751507567U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15279053574704935317U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2425839793660355555U;
            aOrbiterB = RotL64((aOrbiterB * 11486964816849830667U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13209849392400008898U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9041500097716231309U;
            aOrbiterE = RotL64((aOrbiterE * 340661035700748739U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7885423750878814599U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1992993999902904603U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 1478629826632201617U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6120758615019314102U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8529621625846992066U;
            aOrbiterF = RotL64((aOrbiterF * 8485991471612862467U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9125182130757385320U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15691232622970220043U;
            aOrbiterI = RotL64((aOrbiterI * 16517916951054758147U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11413090085435424697U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11563151001080914939U;
            aOrbiterD = RotL64((aOrbiterD * 16828196274450408201U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1778975369262558069U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3232132443557192010U;
            aOrbiterA = RotL64((aOrbiterA * 17132823737792200981U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 277456309842614908U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10470076566806421600U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7526503789282158285U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12466953663713418197U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15871548472936716844U;
            aOrbiterG = RotL64((aOrbiterG * 11788139245249205765U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12322317028530419228U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9080426856729228705U;
            aOrbiterC = RotL64((aOrbiterC * 4204042134412769955U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterG) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 35U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterD, 48U)) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterI, 37U));
            aWandererE = aWandererE + ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 23U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 24U) + aOrbiterK) + RotL64(aOrbiterD, 42U)) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30546U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29854U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28248U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((aIndex + 31489U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 4U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 8767379393098711499U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 23U)) + 7168159491580816433U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 5U)) + 9879279829061883406U) + aNonceWordM;
            aOrbiterD = ((((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 10537167136053399303U) + aPhaseDOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aWandererF + RotL64(aIngress, 11U)) + 2839070018069188936U;
            aOrbiterE = (aWandererI + RotL64(aCross, 41U)) + 13844278063968429732U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 58U)) + 11278946626186474646U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 11798425216660557799U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 29U)) + 7618446090703335192U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 35U)) + 695423597006983660U;
            aOrbiterA = (aWandererB + RotL64(aCross, 18U)) + 14344728202803488813U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11656100506575697086U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10384358779985773937U;
            aOrbiterI = RotL64((aOrbiterI * 247494692039140973U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17585001605131977341U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9964478171465522911U;
            aOrbiterK = RotL64((aOrbiterK * 13484044854790175315U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2710943171829692624U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17809072853457153057U;
            aOrbiterE = RotL64((aOrbiterE * 16341884203303271365U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12814092033910687774U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1743186323268668740U;
            aOrbiterF = RotL64((aOrbiterF * 11150822630624332557U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10750472346626754704U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15925901217078035356U;
            aOrbiterB = RotL64((aOrbiterB * 9276504171291801637U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2569102106359362359U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8868261301410769739U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3662495603133918101U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2143691008373582476U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10606616796243205921U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15794414817813485643U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16258070651850746855U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11720192793689633315U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14475623219460678021U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8230871037292355675U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16898650748046368353U;
            aOrbiterC = RotL64((aOrbiterC * 7368697435476300255U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9071122174426904737U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4506737259011736474U;
            aOrbiterJ = RotL64((aOrbiterJ * 11903039808814842447U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4545409671845718259U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8767379393098711499U;
            aOrbiterD = RotL64((aOrbiterD * 1210632171306946669U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 38U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 26U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterD, 41U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterD, 23U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 20U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 58U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterE, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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

void TwistExpander_Fencing_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAACAEF690CAB0E37ULL + 0xBF6725C8A1E64A30ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE698E1E61622BF37ULL + 0x86C687A1ECB807C8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x80A8319D7C9E052FULL + 0xCF914FE733240B3BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC40CBE1A561A197FULL + 0xE6D7DA5BBFBB37E7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8AF6E4576B095545ULL + 0x9468C05CC0E4178CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD1CAB8F1C76209C3ULL + 0xF272F8880D5AF51DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD9A2ADCFBC940F7FULL + 0xE7E6DB57FC0CC462ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB2752F29E6038781ULL + 0xAD2582A910398EF0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA526034699601B81ULL + 0x9574B9997BBD0ED3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFEA1D046715F33C5ULL + 0xB220CD78662D76CCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC0A7AB9557C71D39ULL + 0x852E89BF355728E0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8DA743998E8A23E3ULL + 0xB18F4F63877838FEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC5D8719CAE69E49DULL + 0x80A40626C803C378ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF1E63C29666B9675ULL + 0xCEE558A5950042A5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9FA02897896F6699ULL + 0xED88C2455C519CEDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x98359C1B43563F1BULL + 0x848A8389D628C396ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1764U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 827U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4461U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((aIndex + 4687U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 43U) + RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 43U)) + 9654059367478508868U;
            aOrbiterK = (aWandererA + RotL64(aCross, 47U)) + 6473006635864677427U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 37U)) + 6944184481315853243U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 4061496421939102306U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 23U)) + 15791809275719085463U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 51U)) + 14050798802646323055U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 60U)) + 12072905924741758266U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 17639076509231343896U) + aNonceWordG;
            aOrbiterE = (aWandererB + RotL64(aCross, 21U)) + 12195388285571234715U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 35U)) + 4325404419499496529U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 41U)) + 5910567888204238382U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13092940059929942699U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13381962590820308761U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6345904465930943295U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15622862439323440527U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14027151901132249793U;
            aOrbiterF = RotL64((aOrbiterF * 2273573821630510087U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4584410023907605157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15763755180625487157U;
            aOrbiterJ = RotL64((aOrbiterJ * 6755736130607297639U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17023059745666559199U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5298529579288492971U;
            aOrbiterD = RotL64((aOrbiterD * 2483562793328357721U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2870152867331654736U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12017191100173748848U;
            aOrbiterH = RotL64((aOrbiterH * 9958191466506480519U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15899529176182436062U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16482713846343388735U;
            aOrbiterE = RotL64((aOrbiterE * 719465695044265601U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12943393531812774449U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9881108254540483225U;
            aOrbiterC = RotL64((aOrbiterC * 8011108108007885059U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3532054586199716750U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7142230313294797435U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14154176174768868421U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 733958394016131587U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2060800099014517137U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12988885554457108631U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2278498033811574812U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15342071118593803929U;
            aOrbiterB = RotL64((aOrbiterB * 7842196613533603835U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12987212219357101955U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9654059367478508868U;
            aOrbiterA = RotL64((aOrbiterA * 11796100167917742307U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterD, 41U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 28U)) + aOrbiterC) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterA, 51U));
            aWandererC = aWandererC + ((RotL64(aIngress, 44U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterG, 54U));
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF + ((((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterG, 21U)) + aNonceWordD) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7836U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 9083U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9248U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 9143U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 54U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 12029393034357490020U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 26U)) + 4526754731580694987U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 17060419646421271853U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 4128488893837059683U) + aNonceWordO;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 41U)) + 12706894827547160110U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 22U)) + 12506324593645825056U;
            aOrbiterE = (aWandererE + RotL64(aCross, 5U)) + 12581344490649250025U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 43U)) + 14357032418199130132U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 13U)) + 15341977701796331249U) + aNonceWordC;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 29U)) + 7086602307544733241U) + aPhaseEOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 19U)) + 12398300065276832486U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2499745046076601988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7249361592814001829U;
            aOrbiterG = RotL64((aOrbiterG * 14597139848072319685U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3254456186337366437U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3472973415969046680U;
            aOrbiterB = RotL64((aOrbiterB * 14583566953969168353U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7905718972111691591U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15941413652144021522U;
            aOrbiterJ = RotL64((aOrbiterJ * 3473779492962783565U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10583964125960308762U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13659925272340853715U;
            aOrbiterE = RotL64((aOrbiterE * 16708294803316630743U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9487054537489454887U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13287757570441887517U;
            aOrbiterI = RotL64((aOrbiterI * 17351439045329892107U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15279245465808571942U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12424999114621745879U;
            aOrbiterK = RotL64((aOrbiterK * 2274918760256527137U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13915392738892970475U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13797668053788805126U;
            aOrbiterH = RotL64((aOrbiterH * 13752161103680525317U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14344766585550401077U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13727554194373146727U;
            aOrbiterC = RotL64((aOrbiterC * 17164450431362670223U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1332966642432651232U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 938583742533681467U;
            aOrbiterD = RotL64((aOrbiterD * 13323340043936037549U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5659239372701978244U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8501778564909302938U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 15629932660749672503U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1698500835332753591U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12029393034357490020U;
            aOrbiterA = RotL64((aOrbiterA * 18176507271635640153U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterE, 44U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererA = aWandererA + ((RotL64(aCross, 10U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 24U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12447U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15979U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14343U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15057U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 35U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCross, 18U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aScatter, 46U)) + 6163290588946759209U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 7342672468560105447U;
            aOrbiterF = (aWandererG + RotL64(aCross, 41U)) + 11574563167017282321U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 43U)) + 2254820206194758964U) + aNonceWordJ;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 26U)) + 1469783447473099498U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 14174828900676165088U) + aPhaseEOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 19U)) + 16277954291890598132U) + aNonceWordA;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 3U)) + 14845750668693136766U) + aNonceWordM;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 150099699692047766U;
            aOrbiterH = (aWandererC + RotL64(aCross, 23U)) + 1200784917165131703U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 39U)) + 9469982764806754302U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10956702761701710182U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7915506894975487807U;
            aOrbiterF = RotL64((aOrbiterF * 8874108311712727983U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17335794183733623213U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 557028996286989506U;
            aOrbiterC = RotL64((aOrbiterC * 3993359298602424281U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1597385667771002414U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4376417959915162639U;
            aOrbiterK = RotL64((aOrbiterK * 4626236858205178149U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 549770198518993876U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 756554555648070919U;
            aOrbiterI = RotL64((aOrbiterI * 16272320259614325355U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7298557532533152193U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3336802611342112013U;
            aOrbiterA = RotL64((aOrbiterA * 14679103452120080499U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2314938232094714365U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12215066333571149153U;
            aOrbiterH = RotL64((aOrbiterH * 10747052773052630601U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7762752719356805046U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6519429915769040078U;
            aOrbiterB = RotL64((aOrbiterB * 15548676502167938513U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7556691736109752918U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 13731245903412646404U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 15581965016668635409U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5910925625723735162U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16037704866415841869U;
            aOrbiterE = RotL64((aOrbiterE * 11628217027073824759U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12605882248192797360U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9579778913978981884U;
            aOrbiterD = RotL64((aOrbiterD * 5372577227818787957U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6063171520266734946U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6163290588946759209U;
            aOrbiterJ = RotL64((aOrbiterJ * 291843698316138251U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 40U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterC) + aNonceWordD);
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 13U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterB, 52U)) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 58U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterF, 37U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17987U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 19168U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16951U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18339U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 3U) + RotL64(aCarry, 38U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 18255347001097480328U) + aNonceWordG;
            aOrbiterF = (aWandererB + RotL64(aScatter, 39U)) + 13679246790311505735U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 14U)) + 10565839529765027116U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 5U)) + 14327172566224769901U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 16239024612038195174U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 41U)) + 13800012174212131890U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 47U)) + 13900288860157577583U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 21U)) + 4144386119777112740U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 43U)) + 3154558262670631372U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 23U)) + 7456728543137614001U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 43U)) + 11709519851158935384U) + aNonceWordP;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15607438907832240304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9276575329661725624U;
            aOrbiterE = RotL64((aOrbiterE * 8879744070762412745U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6459435969129449226U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6442382118416542275U;
            aOrbiterC = RotL64((aOrbiterC * 2921027306686588233U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12117432107282150865U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6831279293184793243U;
            aOrbiterA = RotL64((aOrbiterA * 2435360641135249073U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9520022957804572889U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8322178689474588679U;
            aOrbiterD = RotL64((aOrbiterD * 1627707191467537115U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4162401591586869316U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8994015844714895961U;
            aOrbiterB = RotL64((aOrbiterB * 15421910378057951895U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10038095909727959633U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17756404450592957616U;
            aOrbiterG = RotL64((aOrbiterG * 14255952184627347295U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3379089265413427719U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11341713098678108441U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2500587373161411961U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 4030296130743454165U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6332387792111212064U;
            aOrbiterH = RotL64((aOrbiterH * 16490982218150897861U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14893209417387662133U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9265457389326311687U;
            aOrbiterK = RotL64((aOrbiterK * 9778404505547862689U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13496086915199406901U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14576555328710787951U;
            aOrbiterF = RotL64((aOrbiterF * 13155395071667672943U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11482324648071976743U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18255347001097480328U;
            aOrbiterJ = RotL64((aOrbiterJ * 10918514878283385643U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 54U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterF, 30U));
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 24U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22498U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((aIndex + 24849U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23657U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 26054U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 20U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aIngress, 48U)) + 17225673071833726819U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 23U)) + 10301458382103627331U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 35U)) + 3960233050857362414U) + aNonceWordC;
            aOrbiterB = (aWandererF + RotL64(aCross, 5U)) + 17768665685046605837U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 43U)) + 14471018461213959767U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 10730597892721340453U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 14863394003122760542U) + aNonceWordD;
            aOrbiterH = (((aWandererK + RotL64(aCross, 46U)) + RotL64(aCarry, 3U)) + 9948587274816688296U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 41U)) + 3573569431435100993U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 53U)) + 8153670675740450590U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 39U)) + 16438856577722561424U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15765587867581925041U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1082039522061775213U;
            aOrbiterA = RotL64((aOrbiterA * 17023740047246402641U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4202521649260798876U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15877659681260461141U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 11369910758551088173U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2551560426129646123U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3005102326163906320U;
            aOrbiterH = RotL64((aOrbiterH * 4241583192662435107U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1675501058857208089U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12774812270956702043U;
            aOrbiterE = RotL64((aOrbiterE * 5488437008504905105U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1044886020922563597U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4857445127457225171U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 13223560654459705259U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11548725551787560962U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2434677823189765161U;
            aOrbiterB = RotL64((aOrbiterB * 4283026044563670969U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9606875320524736294U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13732615866277657704U;
            aOrbiterG = RotL64((aOrbiterG * 3905528919281629775U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13921743663803299567U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13350829301153929899U;
            aOrbiterK = RotL64((aOrbiterK * 11858642286713079795U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9473349030551400156U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7446792050826434742U;
            aOrbiterJ = RotL64((aOrbiterJ * 6619682184124713031U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17970527747978977453U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2326714817603921480U;
            aOrbiterD = RotL64((aOrbiterD * 14581676978186226887U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7875511075130474136U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17225673071833726819U;
            aOrbiterF = RotL64((aOrbiterF * 1196024136909896027U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterH, 37U)) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 56U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 39U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 30U)) + aOrbiterE) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31951U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28952U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31090U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32638U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 58U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aCross, 53U)) + 13442819395490639310U) + aNonceWordD;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 28U)) + RotL64(aCarry, 23U)) + 8187292523194120936U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 11469697159823131388U) + aPhaseEOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 47U)) + 13414083692375929653U;
            aOrbiterB = (aWandererA + RotL64(aCross, 13U)) + 11404010733687907517U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 39U)) + 6783212827186218247U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 5U)) + 8561131439340372614U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 51U)) + 6252609642004429113U) + aPhaseEOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aScatter, 41U)) + 12804867444200448952U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 2739648749603690781U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 24U)) + 14808861217017399752U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17588866502571268888U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5882260142735642980U;
            aOrbiterE = RotL64((aOrbiterE * 7688252946143263869U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15493099088132862949U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5175647411532429582U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15226544495598541883U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14279707376173642767U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6826363572161275158U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5263708315440161809U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13267185753040999992U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9980987858092888720U;
            aOrbiterC = RotL64((aOrbiterC * 13210290848800728635U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3582972937645514549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10140409019562890804U;
            aOrbiterK = RotL64((aOrbiterK * 6944490201647678479U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6160444117287330557U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16344602960561293113U;
            aOrbiterF = RotL64((aOrbiterF * 2319964919335633293U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3497141036108337171U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 91269118352540308U;
            aOrbiterH = RotL64((aOrbiterH * 5160060720189045505U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12739932748793144857U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12820180915064791197U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5843849637411948699U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17572075652083359962U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10684041099654982701U;
            aOrbiterA = RotL64((aOrbiterA * 7121293375756263771U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10739534650885677354U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9731206787727954809U;
            aOrbiterD = RotL64((aOrbiterD * 3730875775588585547U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9655432616347117764U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13442819395490639310U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3650859301708619119U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 42U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterH, 19U));
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 37U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 13U)) + aNonceWordL) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterF, 44U));
            aWandererC = aWandererC + ((RotL64(aCross, 14U) + RotL64(aOrbiterK, 57U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 6U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordD);
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

void TwistExpander_Fencing_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAE86B51517F4C9C5ULL + 0x869CC24D402277A6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8D45873403046453ULL + 0xBE1267BF2467F258ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFBF43331F4B3D6F3ULL + 0x89DE1550BB490950ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF14DC414AFB8A235ULL + 0x97C4CE65EBCFC937ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC51CE3ED81AD1163ULL + 0xE97A38CF7364E249ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x995F3411A3BDEDA9ULL + 0x95019EB5371316D6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC7F49380A551B141ULL + 0xBF924E596874FA47ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF91A8DF385431257ULL + 0xA3A3B24CC9602FF0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC396A07D25FF7915ULL + 0x8A2F15F5B3C329FAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBCD2B6DD70243035ULL + 0x81D48DE82E6A3892ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEB4EADA2BA442B2BULL + 0x96297C97FBAD801CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEE2E43217B0493E1ULL + 0xD6CE9D29E84FA0E3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x975B229E8182004BULL + 0x8F51B432D155E2B4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC56F8485BEA4F09DULL + 0xEFC9A776D597432CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDA85E1A1BBF07F2FULL + 0xCCEC4D9A7CB1A5EEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD23A9972A8AB5503ULL + 0xCCFA6655598EF7FFULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1372U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 3956U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5388U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 402U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aCross, 50U)) + 13583136155674166402U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 12830472187484919497U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 29U)) + 18081197909484522509U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 5U)) + 8680634051297891550U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 19U)) + 13939998767458656823U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 3U)) + 1795730579103692594U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 23U)) + 17369751719734069999U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 43U)) + 224769585901248068U) + aNonceWordJ;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 40U)) + 4133547085925268180U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 7022512056309567391U;
            aOrbiterE = ((((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 10319484359046945495U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10483878349412282069U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6481381149199985736U;
            aOrbiterH = RotL64((aOrbiterH * 9701719367082506253U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13721077228796934509U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9704818014314175007U;
            aOrbiterB = RotL64((aOrbiterB * 760445624027740287U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6253040047758584339U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16890211690273641226U;
            aOrbiterI = RotL64((aOrbiterI * 5622534399866057841U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6216227831265032436U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2023609047004658739U;
            aOrbiterD = RotL64((aOrbiterD * 3252332895698310147U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9201669637050388263U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5106927540934338576U;
            aOrbiterJ = RotL64((aOrbiterJ * 6368134569042291431U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10080368957861445998U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10784789383436485808U;
            aOrbiterC = RotL64((aOrbiterC * 3794918350254445939U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15426339824951793026U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17637144549368340331U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10971293914614704441U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9941300382181962134U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8118046374121322097U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 8481945819050983127U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5138086185042567633U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7279942739248982986U;
            aOrbiterA = RotL64((aOrbiterA * 12911998308338410917U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12135610639038562853U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12945353426409788798U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 7434977715954413699U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7534876598022096222U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13583136155674166402U;
            aOrbiterG = RotL64((aOrbiterG * 8194058098043157015U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterA, 50U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 37U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 38U) + aOrbiterI) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 39U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterK, 48U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10677U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7931U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6202U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 5574U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 54U)) + (RotL64(aCross, 13U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 58U)) + 17019646486641172469U) + aNonceWordJ;
            aOrbiterE = (aWandererA + RotL64(aIngress, 27U)) + 12276141179299971572U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 3617241694029841555U;
            aOrbiterI = (aWandererE + RotL64(aCross, 5U)) + 6967963401259371737U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + 6340709284279891017U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 37U)) + 456065368903896482U) + aNonceWordF;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 41U)) + 17686765719908116203U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 13U)) + 1322045955429785736U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 5163772703302372887U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 53U)) + 13268431135020363252U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aScatter, 19U)) + 6538789950366849332U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10390344544314544893U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5087084271300584267U;
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13423071121590981727U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 18324443012024134729U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 15814349432207734533U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4129091815978464507U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17024797553831962245U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3137753479364378175U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6501545108779991661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11930037791867597447U;
            aOrbiterK = RotL64((aOrbiterK * 4904739567549702851U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4667298703308315851U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6315980380900062127U;
            aOrbiterC = RotL64((aOrbiterC * 12080555704907924637U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12732382340390769888U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7792095326183864547U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12645556660611824631U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17428384983571405782U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3193205313177048443U;
            aOrbiterI = RotL64((aOrbiterI * 14488006565106259731U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2813743367131107264U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 2742138679703780981U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 18356569025783532225U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6270291142961043031U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3490174937775044998U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 13879285210885619613U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13182535825771438942U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13047228760732694484U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10365428317468779549U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17926326514553542739U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17019646486641172469U;
            aOrbiterG = RotL64((aOrbiterG * 13978838314848228053U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 46U) + aOrbiterI) + RotL64(aOrbiterB, 41U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 56U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterD, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterA, 30U)) + RotL64(aCarry, 3U)) + aNonceWordO) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 44U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 27U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 42U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16213U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12760U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15107U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 13532U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 29U)) + (RotL64(aIngress, 47U) + RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 29U)) + 6069475454765660321U;
            aOrbiterE = (aWandererB + RotL64(aCross, 24U)) + 11483704742497268068U;
            aOrbiterF = ((((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 11055697447388986418U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 39U)) + 10897095046039997004U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 4731637118230457840U) + aNonceWordP;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 5U)) + 13855839187084986751U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 5328208115460188239U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 43U)) + 12479538544291412985U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 11U)) + 10740165998792608231U;
            aOrbiterH = (aWandererG + RotL64(aCross, 46U)) + 6492798157284955373U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 51U)) + 13056825957483891921U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2068184064919194657U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5656302738780746294U;
            aOrbiterF = RotL64((aOrbiterF * 16493021179127646345U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11193756120230763294U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17306750816837208999U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7949360041241439741U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12952818800389361804U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15380412293642628312U;
            aOrbiterE = RotL64((aOrbiterE * 2914662289178925547U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 7706090204767242996U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 14598802276412649570U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4821408736292041399U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17819762117328075515U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6481384240915075101U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 4836701121865783029U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 754936290510338717U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15510875946573720154U;
            aOrbiterH = RotL64((aOrbiterH * 2994718968852184303U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9245381722813944586U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2629847912019726214U;
            aOrbiterC = RotL64((aOrbiterC * 6718795794951106961U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3909987749797113773U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9277056074757335265U;
            aOrbiterG = RotL64((aOrbiterG * 11580847505996697115U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12577180954515966707U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9144513680789115458U;
            aOrbiterK = RotL64((aOrbiterK * 8880777678193004979U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1544232962956974411U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2658275904714859636U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1926083316365175327U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5733515391293514025U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6069475454765660321U;
            aOrbiterB = RotL64((aOrbiterB * 9627476106108146391U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterH, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aScatter, 20U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + aNonceWordK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterC, 6U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 48U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19014U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21145U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21298U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 19794U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererD + RotL64(aPrevious, 11U)) + 12980104182836602177U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 41U)) + 3172622203188863995U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 50U)) + 1170974132219980203U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 35U)) + 6035201940965047490U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 18033907118424996722U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 14604813424800580304U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 13720232492851066035U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 21U)) + 3902659710585257448U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 30U)) + 8331560652661619868U) + aNonceWordC;
            aOrbiterK = (aWandererH + RotL64(aScatter, 39U)) + 4485014147538689794U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 27U)) + 168202636924512424U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16227825670092707848U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4792781933944671365U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12636865372722601282U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18198291399585556632U;
            aOrbiterD = RotL64((aOrbiterD * 18155803890313399795U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3650053185419807206U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5897288963905408776U;
            aOrbiterB = RotL64((aOrbiterB * 3706949366974086151U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9922308113622901726U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13352279749091561510U;
            aOrbiterH = RotL64((aOrbiterH * 4025213180483632557U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14969461950939646117U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10231661776135056651U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11284575051455238501U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10621934544068320859U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6029116920305246887U;
            aOrbiterF = RotL64((aOrbiterF * 6087523725059376905U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12887482425168671195U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8351351557123783853U;
            aOrbiterK = RotL64((aOrbiterK * 3839381627914762245U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5405938210926464973U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 385145802287899406U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8330751480464271445U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7907749190875916461U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5138733192253468642U;
            aOrbiterA = RotL64((aOrbiterA * 17028325976353263843U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14382272868178763187U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14354777100157531233U;
            aOrbiterC = RotL64((aOrbiterC * 7095764230272037767U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4390647647193363824U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12980104182836602177U;
            aOrbiterG = RotL64((aOrbiterG * 11124472075872147333U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterB, 29U));
            aWandererA = aWandererA + ((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterG, 37U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 14U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterI, 57U));
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 48U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 22U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + aNonceWordA) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25819U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22092U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21847U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23585U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 6U)) + RotL64(aCarry, 37U)) + 18180797995100240808U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 6585906608223552885U) + aNonceWordD;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 43U)) + 14088708930575939855U) + aNonceWordF;
            aOrbiterJ = (aWandererB + RotL64(aCross, 21U)) + 468974153311516044U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 47U)) + 12481951025619894110U;
            aOrbiterC = (aWandererF + RotL64(aCross, 11U)) + 17227987923860711763U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 4373962756657477139U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 60U)) + 2077576476565420951U) + aNonceWordP;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 23U)) + 17435011300234663764U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 27U)) + 4118039398293246896U;
            aOrbiterF = (aWandererD + RotL64(aCross, 35U)) + 13724716599855216683U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12391461204689596339U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9900605191533799627U;
            aOrbiterD = RotL64((aOrbiterD * 13553565332531046301U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 972946858824366125U) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17247681919694541215U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2974639094630445643U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15442851427306771601U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7303586227288294037U;
            aOrbiterI = RotL64((aOrbiterI * 15406402525021428799U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12650358753454105119U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1483710933373510492U;
            aOrbiterK = RotL64((aOrbiterK * 6531763256577221891U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18065810162229740788U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11311677121338794007U;
            aOrbiterB = RotL64((aOrbiterB * 15116367961682119467U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2355285311890287611U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1287783821903407734U;
            aOrbiterJ = RotL64((aOrbiterJ * 8054011680932255985U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9282654686791135654U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15488608017745542551U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 7858866274035085123U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13296835576073421802U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7127700236018338741U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11246173563106014149U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1365928843264598789U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7777790578813003657U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10121688100505628161U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2104270617375082523U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13363764449819651164U;
            aOrbiterG = RotL64((aOrbiterG * 2685452132715528975U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2008038686059197988U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18180797995100240808U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8978998151475372047U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 54U));
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 11U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterE, 37U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterI, 43U));
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 30U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 39U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aNonceWordC) + aPhaseFWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aScatter, 42U) + RotL64(aOrbiterD, 21U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 27U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28907U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 30287U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32250U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 27777U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 52U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 57U)) + 13960289014350612206U) + aNonceWordF;
            aOrbiterE = ((((aWandererK + RotL64(aCross, 30U)) + RotL64(aCarry, 41U)) + 3483331015269589730U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 23U)) + 6873299241002444518U) + aNonceWordJ;
            aOrbiterC = (aWandererE + RotL64(aIngress, 41U)) + 3562094007125534229U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 11422367439932782705U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 21U)) + 532453428514259816U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 34U)) + 17810941465810193088U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 53U)) + 11869759058631106331U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 8837581071876177566U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 19U)) + 17185378327053837778U) + aPhaseFOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 11U)) + 7578253375676981500U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17112646434432814442U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 14949096407295697881U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 14770977858283051753U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4259590620758467836U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6534899413644542303U;
            aOrbiterH = RotL64((aOrbiterH * 7987609419215568661U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2637407498893694243U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15819295597921425711U;
            aOrbiterF = RotL64((aOrbiterF * 5202015597375051399U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6373559542002699718U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11694562937392022505U;
            aOrbiterB = RotL64((aOrbiterB * 9311557972331218597U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3308736483775453062U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12749929710650475901U;
            aOrbiterJ = RotL64((aOrbiterJ * 248428400724560945U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1569528215675579656U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1044077933631689572U;
            aOrbiterI = RotL64((aOrbiterI * 6443796233912755143U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8393422728124537471U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2002732612516530754U;
            aOrbiterD = RotL64((aOrbiterD * 13702146823622364279U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13469191942843147943U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7633171368709520560U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9713514012478203047U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4023206337737491091U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15990323932023596968U;
            aOrbiterA = RotL64((aOrbiterA * 4816480271959713463U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 837005729394899591U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9692088757104339973U;
            aOrbiterE = RotL64((aOrbiterE * 17971548293495807419U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18039464962413134616U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13960289014350612206U;
            aOrbiterC = RotL64((aOrbiterC * 931609478642506411U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterA, 56U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 36U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 46U));
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterC, 39U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aNonceWordM) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 37U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 27U)) + aOrbiterA) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aCross, 52U) + RotL64(aOrbiterB, 6U)) + aOrbiterC) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Fencing_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC62E28E1F677B343ULL + 0xDF7FCFD439848061ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBEB00CCB0548FF2DULL + 0xB51E99C9813BC056ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9A784FFB53CD1773ULL + 0xE414531FE970CD43ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAFE8C3A6AD042FE7ULL + 0xFDBD5875B292DB0EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAC8D91939D0C4CC3ULL + 0xB8C8F8B76E267A38ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x97A557A636C860BDULL + 0x8B7BD17717CEA309ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFAADF7A79BCAC56FULL + 0xDD1EE89C1B215DD4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF712DC83895ADC51ULL + 0xA7B965A57AF95229ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF135D0DFE441D223ULL + 0xC943F6983259B3F3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCBB4A7455BFE2865ULL + 0xC5C9671A19ED053DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x918D9A2563907F0DULL + 0xB9BBC81D7F049D52ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFE30F0644DB9A6B7ULL + 0xADC8AC781203090AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA85A9EC402D41A21ULL + 0xE7603B81DE0677B7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDB4956B37B6DD8E3ULL + 0xCBFFDFD1CC4CA49FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9048F17FBB1C745DULL + 0x9791B0560A3145FBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8484F9969A3BB9FFULL + 0xEE0BFDE67BC6F1A3ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4083U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2292U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1825U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 2596U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 28U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aCross, 11U)) + 16651241552253078315U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 53U)) + 4558144676982478003U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 4U)) + RotL64(aCarry, 5U)) + 8814884320080367550U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aIngress, 41U)) + 16011579668555672117U) + aNonceWordA;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 4738918668759862438U) + aNonceWordB;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 12526083125540985108U) + aPhaseFOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 43U)) + 8048723561746000552U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 30U)) + 1082218464034639039U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 37U)) + 8432043246965946816U) + aNonceWordL;
            aOrbiterG = (aWandererH + RotL64(aCross, 47U)) + 9982080524048636852U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 39U)) + 6720069955755215919U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1019035028070247757U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7360619079463870467U;
            aOrbiterD = RotL64((aOrbiterD * 6623074813047915863U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10893918488381348474U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1390297670907738019U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11909657437658597735U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12512200589031203480U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14741471280748399540U;
            aOrbiterK = RotL64((aOrbiterK * 3012135242889901095U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8543897248359826770U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8545972622733791272U;
            aOrbiterH = RotL64((aOrbiterH * 11793879362775346821U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7049384618581928664U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14730773807906925408U;
            aOrbiterA = RotL64((aOrbiterA * 10711566871536755073U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11480717275652449986U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1135397594974536859U;
            aOrbiterE = RotL64((aOrbiterE * 6347492892938856497U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6897207625849516702U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10920630712550287148U;
            aOrbiterF = RotL64((aOrbiterF * 4140705091806993359U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1094056478999931332U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6784487144549717207U;
            aOrbiterI = RotL64((aOrbiterI * 6295177724167067891U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2224992798329560875U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11486442570446223696U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5680065455032616591U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14681556190496625711U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1809388635055225841U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3449474313001177557U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4480846057441948619U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16651241552253078315U;
            aOrbiterG = RotL64((aOrbiterG * 10628778876898064085U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 19U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aIngress, 48U) + aOrbiterC) + RotL64(aOrbiterF, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterF, 48U));
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 27U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterB, 57U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterJ, 44U)) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10778U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9121U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6660U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10743U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 18U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 41U)) + 9471546960258473684U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 18050235435948942244U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 26U)) + 3005107102671544641U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 21U)) + 17898396434573801850U) + aNonceWordJ;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 37U)) + 15071602525497771648U;
            aOrbiterD = (aWandererE + RotL64(aCross, 53U)) + 5780119462702672108U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 13U)) + 13301326224151025687U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 44U)) + 18129323022260575961U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 11U)) + 1199228670638790709U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 1839199978088021020U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 4999517042246790165U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8788607633376516299U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15143903839930468749U;
            aOrbiterF = RotL64((aOrbiterF * 12735914889325422675U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16674732686428431869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15908873150953195581U;
            aOrbiterI = RotL64((aOrbiterI * 18049755517524334107U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11204775359756474667U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2525984309543939465U;
            aOrbiterC = RotL64((aOrbiterC * 3988529812023791571U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4566345170476825512U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14876612901557406267U;
            aOrbiterH = RotL64((aOrbiterH * 9047956948845135339U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14926290877038883931U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12710203178186614846U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14841163494801662515U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7315094513967387996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11050116830482816766U;
            aOrbiterG = RotL64((aOrbiterG * 3702999495721152019U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4505368486032503953U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17905748055257551092U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14775870175093453197U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5728886950801376350U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17998141690182325170U;
            aOrbiterD = RotL64((aOrbiterD * 16008599930125391379U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4325978018819134558U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13526905108565989379U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 14121321495714166291U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10597169665474269506U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7500801022830471869U;
            aOrbiterJ = RotL64((aOrbiterJ * 3702717219742363777U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17063616328548689935U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9471546960258473684U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3029748230803396737U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 20U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 6U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 35U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterB, 50U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 44U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterH, 60U)) + aNonceWordK);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12760U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11754U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13687U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 11352U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 13U) ^ RotL64(aIngress, 28U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 41U)) + 6163290588946759209U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 13U)) + 7342672468560105447U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 4U)) + 11574563167017282321U) + aPhaseFOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 35U)) + 2254820206194758964U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 23U)) + 1469783447473099498U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 14174828900676165088U) + aNonceWordG;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 27U)) + 16277954291890598132U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 14845750668693136766U) + aNonceWordO;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 150099699692047766U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 21U)) + 1200784917165131703U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 10U)) + 9469982764806754302U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10956702761701710182U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7915506894975487807U;
            aOrbiterD = RotL64((aOrbiterD * 8874108311712727983U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17335794183733623213U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 557028996286989506U;
            aOrbiterH = RotL64((aOrbiterH * 3993359298602424281U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1597385667771002414U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4376417959915162639U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4626236858205178149U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 549770198518993876U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 756554555648070919U;
            aOrbiterE = RotL64((aOrbiterE * 16272320259614325355U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7298557532533152193U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3336802611342112013U;
            aOrbiterG = RotL64((aOrbiterG * 14679103452120080499U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2314938232094714365U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12215066333571149153U;
            aOrbiterF = RotL64((aOrbiterF * 10747052773052630601U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7762752719356805046U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6519429915769040078U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15548676502167938513U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7556691736109752918U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13731245903412646404U;
            aOrbiterJ = RotL64((aOrbiterJ * 15581965016668635409U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5910925625723735162U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16037704866415841869U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11628217027073824759U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12605882248192797360U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9579778913978981884U;
            aOrbiterB = RotL64((aOrbiterB * 5372577227818787957U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6063171520266734946U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6163290588946759209U;
            aOrbiterC = RotL64((aOrbiterC * 291843698316138251U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 42U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterH, 53U)) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 13U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 46U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterG, 37U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterI, 51U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterE, 11U));
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 44U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16526U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17357U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18065U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16893U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 14U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aCross, 30U)) + 1210605127156905516U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 41U)) + 11964595428173569519U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 16277319029916258482U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 47U)) + 12369497463101824572U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 43U)) + 6201248574067068202U) + aPhaseFOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 10U)) + 1727477025667206661U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 27U)) + 1404510627789806851U) + aNonceWordE;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 51U)) + 6948213591282018925U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 39U)) + 6688865181284421478U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 3351130769402360855U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 12681032488906270823U) + aNonceWordN;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3591412591193726763U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16153817571210878589U;
            aOrbiterK = RotL64((aOrbiterK * 4165137036092246349U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3808228354421006630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1427373776207504205U;
            aOrbiterB = RotL64((aOrbiterB * 4534374093769595531U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1831554180932501132U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1114853085120949215U;
            aOrbiterJ = RotL64((aOrbiterJ * 4264176108298812905U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2080935638828366835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16104777999646489828U;
            aOrbiterD = RotL64((aOrbiterD * 15205199362011777473U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9782806013673440791U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3721620299829386454U;
            aOrbiterG = RotL64((aOrbiterG * 6286765834910272409U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4013706412064296527U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5751022780695158579U;
            aOrbiterF = RotL64((aOrbiterF * 13766736471646116397U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17684546333240329338U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1106947111128020920U;
            aOrbiterI = RotL64((aOrbiterI * 3158839453318658951U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11564229705849500598U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1585817314460274286U;
            aOrbiterA = RotL64((aOrbiterA * 12687162159791577431U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13549147977354138518U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5148731385622182707U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11016443961557395981U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17048442399822433365U) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13772472534194030098U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13155895389652826889U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9982971300679888388U) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1210605127156905516U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 9183351854400012949U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 14U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 53U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterF, 6U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterI, 43U));
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 44U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23227U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 24857U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26121U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23918U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 47U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aPrevious, 53U)) + 11700815697312060726U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 37U)) + 11808423452327465441U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 35U)) + 8670503858631730886U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 2400061067991988544U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 23U)) + 16163118178366229686U;
            aOrbiterH = (aWandererG + RotL64(aCross, 39U)) + 3280178595904941068U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 14U)) + 3298683600817047727U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 35U)) + 16321624053445183574U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 43U)) + 6730229877611375225U) + aNonceWordA;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 10162830636713641322U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + 15646771327759599256U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14841751262270544102U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9545541117228834895U;
            aOrbiterA = RotL64((aOrbiterA * 11529769874752969377U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14676615635857599982U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1231768638470558855U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 2716808508509014677U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1945905595345404833U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1406171421638586846U;
            aOrbiterG = RotL64((aOrbiterG * 4577864352425476233U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1970292335806697198U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12309719390375013297U;
            aOrbiterK = RotL64((aOrbiterK * 16540660957923687327U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5352135521358954576U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15465675376193501658U;
            aOrbiterF = RotL64((aOrbiterF * 16385761112921041387U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2842123638916600369U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3544764287036748668U;
            aOrbiterB = RotL64((aOrbiterB * 3360772950777850115U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6038297172906492282U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10249342332287140970U;
            aOrbiterJ = RotL64((aOrbiterJ * 16701083081566042277U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1662076777040529446U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1949705569959740274U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 11340691546658994529U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13934194245417822360U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 5720408806425535958U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15237561081637415383U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2209251362417210658U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4917447930929521699U;
            aOrbiterI = RotL64((aOrbiterI * 17489570156694692569U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14817115766683623486U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11700815697312060726U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16982411053956669181U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 48U)) + aOrbiterG);
            aWandererI = aWandererI + (((((RotL64(aCross, 48U) + RotL64(aOrbiterH, 39U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterB, 57U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterK, 23U));
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + aNonceWordB);
            aWandererB = aWandererB + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 11U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterI, 50U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30711U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29205U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31465U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31969U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 48U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 5U)) + 13650869943246163567U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 3435284932011770999U;
            aOrbiterB = (aWandererC + RotL64(aCross, 35U)) + 12388155658186776579U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 48U)) + 2374345913955712039U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 27U)) + 6095094526980292156U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 23U)) + 4965147025852444174U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 39U)) + 3261881216269075298U) + aNonceWordC;
            aOrbiterK = (aWandererI + RotL64(aCross, 13U)) + 4939780217097329222U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 56U)) + 3019862009792676287U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 901910626217143974U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 3647055146712366383U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7731765438957392967U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13409819457393479741U;
            aOrbiterB = RotL64((aOrbiterB * 3345078200262410715U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5415832109107794258U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8876738832313114471U;
            aOrbiterJ = RotL64((aOrbiterJ * 1304277600444504135U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17135570542519390359U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 2373193062766802082U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 4213691513185791519U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16318403285501718552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8456043288604687045U;
            aOrbiterH = RotL64((aOrbiterH * 10556964529144571683U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10572534930284516528U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14616251186735204677U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2048651204265459805U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2837006243817205610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5315917323622194254U;
            aOrbiterI = RotL64((aOrbiterI * 4080522050089666599U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12084676282761185907U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7922080344175593788U;
            aOrbiterG = RotL64((aOrbiterG * 7603522302708937379U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17620847289789547792U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12140386059533463650U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 1443266480620969535U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4006608081473218762U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3152507055132739011U;
            aOrbiterF = RotL64((aOrbiterF * 11929522909695002321U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10845720206369283181U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16572752872386133133U;
            aOrbiterC = RotL64((aOrbiterC * 2891952650448087211U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15544908026178481075U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13650869943246163567U;
            aOrbiterE = RotL64((aOrbiterE * 1275090431127426217U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 37U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 34U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 58U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aCross, 4U) + aOrbiterB) + RotL64(aOrbiterG, 47U)) + aNonceWordK);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 43U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 10U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordN;
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

void TwistExpander_Fencing_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5080U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 6698U)) & W_KEY1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5012U)) & W_KEY1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7067U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 6U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 14179205183062705133U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 210032324058740920U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 7387115089142500152U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 23U)) + 17583362781238061430U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 12U)) + 4991442849150005943U) + aPhaseCOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 5U)) + 2891376254689854555U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 39U)) + 10523274382407446239U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 51U)) + 3861893764676218667U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 60U)) + 3366674459852093746U) + aPhaseCOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5898492634386601145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7047353571244768721U;
            aOrbiterD = RotL64((aOrbiterD * 2257518291062508467U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14374108805453186316U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8763667021501226510U;
            aOrbiterC = RotL64((aOrbiterC * 7694695426430267863U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18261523829316379575U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 650477532238860965U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8291758490821819851U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2162326554604894042U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5776546692501825278U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14911545784585246537U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3501863793638415049U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14853789267425352958U;
            aOrbiterJ = RotL64((aOrbiterJ * 10590325397179928739U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15399673014671329743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12253428583438990426U;
            aOrbiterH = RotL64((aOrbiterH * 12052855472196447849U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13202953937621953839U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7547616636832698398U;
            aOrbiterI = RotL64((aOrbiterI * 9533399972562428073U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15709801946594868318U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12458677982746610971U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6662570874316418993U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6957370791367530127U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10511379961344950861U;
            aOrbiterK = RotL64((aOrbiterK * 15551333099264031337U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 58U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 10U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + aPhaseCWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 30U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 53U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11577U)) & S_BLOCK1], 20U) ^ RotL64(mSource[((aIndex + 12374U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15155U)) & W_KEY1], 26U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 10556U)) & W_KEY1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererE + RotL64(aCross, 41U)) + 5041131702736607991U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 56U)) + 9295010428212681446U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 13U)) + 6235875895358766017U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 23U)) + 2622227802531866918U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 51U)) + 3888894734834524972U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 19U)) + 241682012014701753U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 15758000422451568079U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 34U)) + RotL64(aCarry, 51U)) + 2061944548396976912U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 8177144990755754531U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 554978075608818497U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 250408260560714933U;
            aOrbiterF = RotL64((aOrbiterF * 1295379390497107727U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8700027645880997552U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10026130047465480902U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12417270861933696623U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9785843014096326696U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9998582683258411251U;
            aOrbiterD = RotL64((aOrbiterD * 7197956237569462269U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13817734599383455151U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6647207154174092691U;
            aOrbiterA = RotL64((aOrbiterA * 1578528131687283531U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4957715980509035719U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4994885315786213197U;
            aOrbiterG = RotL64((aOrbiterG * 5676683798126497011U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5072908311783966503U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5535039946192891515U;
            aOrbiterI = RotL64((aOrbiterI * 2989412783482309753U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6594577050344146271U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8750154123258714856U;
            aOrbiterK = RotL64((aOrbiterK * 6942158167127532003U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3514769314840874873U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8626045200273524281U;
            aOrbiterE = RotL64((aOrbiterE * 4315441782689789689U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8524870284841706517U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1841819423572964209U;
            aOrbiterH = RotL64((aOrbiterH * 9802481758007234681U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterF, 36U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA + ((RotL64(aCross, 28U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 42U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17044U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 22530U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 23307U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19952U)) & W_KEY1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 60U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererG + RotL64(aIngress, 57U)) + 12311607308490066301U;
            aOrbiterF = (aWandererE + RotL64(aCross, 30U)) + 13100864684740679846U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 23U)) + 13697304189274329704U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 35U)) + 9047976902871216732U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 2147897579538537888U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 13U)) + 2072444829390996142U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 2129307836981020908U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 10663145333751112064U;
            aOrbiterI = (aWandererA + RotL64(aCross, 46U)) + 15019844390503785459U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5460865577557928142U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15806522559993224197U;
            aOrbiterK = RotL64((aOrbiterK * 8722932687972240099U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6361113778657833389U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8306013884615042570U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8234258702656728667U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4038420580499706912U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11908091484457158973U;
            aOrbiterJ = RotL64((aOrbiterJ * 3964111175645156719U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11133912466611921250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2469227904206936928U;
            aOrbiterF = RotL64((aOrbiterF * 2704438771198001599U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13234017916788297295U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 9061117693840451988U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3637440416741459419U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12013423690843812324U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14371779015144617412U;
            aOrbiterB = RotL64((aOrbiterB * 3359568073302062667U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10044883414565441442U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14334898081890462218U;
            aOrbiterD = RotL64((aOrbiterD * 4878939077928220019U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13788962593988366125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8377887372059713516U;
            aOrbiterA = RotL64((aOrbiterA * 1925913354197206851U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4584439257847749371U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13335592911357756498U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6515028218115896375U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 4U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 35U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 18U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 24U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aScatter, 10U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + aPhaseCWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31768U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((aIndex + 29071U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30047U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((aIndex + 32035U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 37U)) + 2786079456995203065U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 7237256119153857253U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 9310834010563647604U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 47U)) + 17361734905706517877U;
            aOrbiterF = (aWandererE + RotL64(aCross, 19U)) + 15837111231884647451U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 23U)) + 18065431964418026445U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 30U)) + 3029123922999952652U) + aPhaseCOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 5166926595573507837U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 11U)) + 1918425684273807598U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4724551751012661440U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1818014487579644390U;
            aOrbiterG = RotL64((aOrbiterG * 14904092108647864911U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6670090372241084216U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8485757110007268693U;
            aOrbiterF = RotL64((aOrbiterF * 11876760095108618363U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4928130251509514742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2528788422725346792U;
            aOrbiterI = RotL64((aOrbiterI * 1855982047967756661U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2860387120895147503U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12927802338151379368U;
            aOrbiterE = RotL64((aOrbiterE * 8876144125458603029U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18029699867733207083U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13361836994951253312U;
            aOrbiterC = RotL64((aOrbiterC * 5349767426256597073U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11957294454794128079U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3755417922063414648U;
            aOrbiterB = RotL64((aOrbiterB * 13896364063651241401U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18001157153447913032U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16214145724690286854U;
            aOrbiterJ = RotL64((aOrbiterJ * 5874139687703360515U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3860958772090975562U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12395621524459640173U;
            aOrbiterK = RotL64((aOrbiterK * 722817135977510161U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3402035664910754484U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2139099117325745602U;
            aOrbiterD = RotL64((aOrbiterD * 14008983756425796029U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 26U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterK, 60U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterE, 47U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 18U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterF, 5U));
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 26U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Fencing_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3333U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 6568U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2389U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 6368U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 13333509828310369865U) + aPhaseDOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 20U)) + 7645352517103840797U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 5310766306660062655U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 5165635069832352932U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 51U)) + 15684141764734281849U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3327963374225061738U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8625811794878848871U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16327750494894125333U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7598657468430485291U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2881171216276746485U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3331350584102843605U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10237691227222918101U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6419254255884834497U;
            aOrbiterB = RotL64((aOrbiterB * 3816625473642865305U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4238455444646479956U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 14936613353493061492U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3544216916806292273U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15324699725208372627U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9506640480601832011U;
            aOrbiterA = RotL64((aOrbiterA * 12819564111348390227U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 36U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 52U) + RotL64(aOrbiterJ, 56U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aPhaseDWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 22U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14540U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16277U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12504U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 14647U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 28U)) + RotL64(aCarry, 39U)) + 12380376990224645149U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 18296928500297384014U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 3U)) + 3550626816361145100U) + aPhaseDOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 2667792936946706027U;
            aOrbiterF = (aWandererH + RotL64(aCross, 51U)) + 12020969779370926953U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 737340727886903447U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1681797651799760502U;
            aOrbiterJ = RotL64((aOrbiterJ * 11923920414802777451U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2956186342689489064U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1876852870402977177U;
            aOrbiterF = RotL64((aOrbiterF * 8875540081346621757U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6433205819353555071U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9065076854974222998U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5459675878087242021U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3254410578766789992U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2005081975473815576U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9947701153722014085U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15992999234834560419U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3458344156815120948U;
            aOrbiterB = RotL64((aOrbiterB * 1668460113964608051U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 6U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22009U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19668U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23332U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16620U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aPrevious, 24U)) + 7790166497945719700U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 7136208896846119188U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 39U)) + 12123156943355100886U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 5095546037880875199U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 17642705393916765992U) + aPhaseDOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9918479837334416990U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4890009823843176466U;
            aOrbiterI = RotL64((aOrbiterI * 16898633181256061239U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17652590786213674124U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 870002527644696135U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 915408393979165539U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12545429703552643682U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5310272867406182581U;
            aOrbiterF = RotL64((aOrbiterF * 10420003334833925011U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3264719049050179440U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1967241238180278937U;
            aOrbiterA = RotL64((aOrbiterA * 13004319774269457957U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 773883832927040736U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12766817190261232485U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7448864556802318431U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 34U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 46U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + aPhaseDWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterE, 10U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererI, 40U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25406U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27950U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29620U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 27245U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 60U)) ^ (RotL64(aCarry, 13U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 9133751643283278896U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 13U)) + 8971581804375380408U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 21U)) + 12559650383714566592U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 54U)) + RotL64(aCarry, 57U)) + 15753206088872859163U) + aPhaseDOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 39U)) + 7640756270450762350U) + aPhaseDOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7340073357551376125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5270256573644196046U;
            aOrbiterI = RotL64((aOrbiterI * 13286406906662922841U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3567367996479995928U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11939634537492733738U;
            aOrbiterH = RotL64((aOrbiterH * 5640541900117183639U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7051817732424527120U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1730487669951837941U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15191634337956285841U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18009252467909454817U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2361024272031696442U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15215151562500226027U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15902755877642960397U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12243517544704116184U;
            aOrbiterD = RotL64((aOrbiterD * 2576071074148141447U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 44U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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

void TwistExpander_Fencing_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 8163U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2922U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1089U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4344U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 6916817163240024692U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 14554930751292077817U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 12U)) + RotL64(aCarry, 51U)) + 1098305064484336101U) + aPhaseEOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 41U)) + 12192821172420471527U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 53U)) + 2435134991707318845U;
            aOrbiterE = (aWandererG + RotL64(aCross, 35U)) + 1896745368738512624U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 47U)) + 1114996424222923873U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9839135798371512656U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8037967239603177043U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7848951103759663025U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15185468738487237432U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4912098316394854543U;
            aOrbiterH = RotL64((aOrbiterH * 3072785550384399929U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13142688607850380888U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4507379759608945839U;
            aOrbiterE = RotL64((aOrbiterE * 2989332387754215967U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7299006009652289342U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5390655277207053627U;
            aOrbiterC = RotL64((aOrbiterC * 10973744708856143715U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6744737023577785725U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15539737698867067285U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4686092035261336911U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13329866734681377952U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13284937458969166257U;
            aOrbiterJ = RotL64((aOrbiterJ * 3965985432462699445U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8695002088915702168U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3858059421620839286U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9559783727301092937U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterK, 51U));
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 29U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + aPhaseEWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 12U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 42U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8586U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11860U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10071U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 16112U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 35U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aPrevious, 3U)) + 2330952702412094686U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 43U)) + 7820188225935060799U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 9347644591709839145U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 2288624878446846870U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 29U)) + 9358977729492824128U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 1858511275052455039U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 13715478509322292552U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16413396625604260455U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17714322215518432705U;
            aOrbiterK = RotL64((aOrbiterK * 1904184102419934333U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16188315436202861122U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5564445841368207813U;
            aOrbiterI = RotL64((aOrbiterI * 14125834616162835983U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13717068949900594673U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14143659432287313765U;
            aOrbiterG = RotL64((aOrbiterG * 17281441046722262917U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5729546141908425670U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 4297827922736712074U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13631630436759768885U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 829520109395163673U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11547160328525174295U;
            aOrbiterH = RotL64((aOrbiterH * 4759690159673049775U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2907177944512117206U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11100346409065275671U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17927994356809011637U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1344592529249949068U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6470438516791143572U;
            aOrbiterB = RotL64((aOrbiterB * 13339390828725370475U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 4U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21586U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 21920U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16725U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19463U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 380024772508948442U) + aPhaseEOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 43U)) + 7649029098162567210U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 5329304598870421851U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 12306118665045151326U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 29U)) + 960751560457324256U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 50U)) + 3244070254386191876U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 11U)) + 15733408571609521746U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17623448932647018544U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8787759896149035829U;
            aOrbiterE = RotL64((aOrbiterE * 7092515868845497573U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14741681792348288162U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8801731213568307302U;
            aOrbiterJ = RotL64((aOrbiterJ * 12127126999570616489U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9872248187499779222U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15407371518644528235U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1245102406469471673U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4242060317152943062U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9942784962409917541U;
            aOrbiterC = RotL64((aOrbiterC * 888649755587764533U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7296348796484458631U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15061417216070157797U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10349554676953256231U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3233185810644297433U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9241229457641024287U;
            aOrbiterG = RotL64((aOrbiterG * 2728237515724597517U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8464051359381554575U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3307872165699029375U;
            aOrbiterD = RotL64((aOrbiterD * 4859663401033023433U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 26U)) + aOrbiterK) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 51U)) + aOrbiterD) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30838U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((aIndex + 26624U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29707U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31079U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererH + RotL64(aCross, 41U)) + 16160838483846078448U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 35U)) + 15404960896190227946U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 16904160594024977199U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 3U)) + 17790460246821031802U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 48U)) + RotL64(aCarry, 19U)) + 16395168254086971959U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 7484373204039901786U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 27U)) + 18026814691322913510U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15244817793136966450U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5795491730356335666U;
            aOrbiterH = RotL64((aOrbiterH * 13253529465289332171U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3163873518027801504U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2690791759507349172U;
            aOrbiterF = RotL64((aOrbiterF * 16677948635136515083U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17898067251167087906U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8028010015006604239U;
            aOrbiterB = RotL64((aOrbiterB * 5601629670521300241U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7304739457289910555U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6476837815096530043U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16380545138701113267U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14242499233467960602U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17305645693017634630U;
            aOrbiterG = RotL64((aOrbiterG * 14442976693206929569U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9772864059444171908U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7897200728282156408U;
            aOrbiterD = RotL64((aOrbiterD * 816306719390807411U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4890999319172950996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8165132649356094963U;
            aOrbiterA = RotL64((aOrbiterA * 17297706071263690189U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 11U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + (((RotL64(aIngress, 26U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 36U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 38U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Fencing_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3336U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 5534U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4527U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 5524U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 11U)) + 12122689833405846292U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 9640400270962766788U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 9141937998266739071U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 54U)) + RotL64(aCarry, 29U)) + 12899395770434090537U;
            aOrbiterC = (aWandererG + RotL64(aCross, 39U)) + 13457918115408031842U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15134784483576000943U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12540961268790055438U;
            aOrbiterG = RotL64((aOrbiterG * 3295706140418040089U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6306886773092764230U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13573343491337243121U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15893457012357368707U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8545588657348974413U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10891410570357275120U;
            aOrbiterJ = RotL64((aOrbiterJ * 5399310978367842841U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2877137119767060151U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9178097682386595144U;
            aOrbiterD = RotL64((aOrbiterD * 3524486002084427513U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15528007881855616978U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11368419529245281435U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12433207037378339309U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 34U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 24U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11229U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15621U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10733U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 8818U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 16183871922837164759U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 7002058258090219055U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 52U)) + 5650868611888303705U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 11899839660943876690U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 43U)) + 15349649504488111111U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14060149569086744970U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12920917574225030112U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6552626684290469367U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2831994965175330135U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18312543585028439192U;
            aOrbiterD = RotL64((aOrbiterD * 11618182708195744321U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11657562205118394239U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10850792819281246052U;
            aOrbiterG = RotL64((aOrbiterG * 10663100544207879337U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17810371216216125323U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7963413941144223128U;
            aOrbiterC = RotL64((aOrbiterC * 534217972450595401U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5498715358793875584U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9256727548911651373U;
            aOrbiterH = RotL64((aOrbiterH * 10498848323914000989U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 6U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 4U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17003U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17432U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24313U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 24472U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 17912271996338180948U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 44U)) + 13259276608841847058U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 16225936008657276089U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 2243058962151834071U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 11U)) + 10637439274127347861U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15312219216405992627U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2393933972129878613U;
            aOrbiterD = RotL64((aOrbiterD * 13147717214387593761U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 4327069337247976513U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8307656353434167837U;
            aOrbiterF = RotL64((aOrbiterF * 11386588389133096705U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17299145556933889336U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14458100581172798164U;
            aOrbiterK = RotL64((aOrbiterK * 16543734663677070509U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6410095654927998067U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6168964796264687686U;
            aOrbiterC = RotL64((aOrbiterC * 16218071040190475953U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3667999465041020730U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16021552859323602007U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6427266472526362663U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterF, 40U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31811U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((aIndex + 29229U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28068U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26359U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 7825479804710770560U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 39U)) + 5298124167101358123U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 17774541024369233726U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 28U)) + RotL64(aCarry, 57U)) + 7679371833537454082U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 19U)) + 5385914900748772224U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3879781930908486531U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 659110346638873236U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17439162088869824407U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10749021728538539749U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3631252455767429457U;
            aOrbiterK = RotL64((aOrbiterK * 8552825360915119613U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2271978810960685021U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5963558780692551176U;
            aOrbiterD = RotL64((aOrbiterD * 4772055335210781149U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 974909966119198104U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9296998242911152296U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2613629915877957661U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2245318466901521959U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13391076374843288568U;
            aOrbiterH = RotL64((aOrbiterH * 18094558036982107419U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 20U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 46U) + aOrbiterK) + RotL64(aOrbiterH, 48U));
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 21U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Fencing_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6601U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8133U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7036U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2035U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 30U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 5041131702736607991U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 9295010428212681446U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 57U)) + 6235875895358766017U) + aPhaseGOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 43U)) + 2622227802531866918U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 12U)) + RotL64(aCarry, 5U)) + 3888894734834524972U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 241682012014701753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15758000422451568079U;
            aOrbiterA = RotL64((aOrbiterA * 14719166949665416221U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2061944548396976912U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8177144990755754531U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12702392689484397947U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 554978075608818497U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 250408260560714933U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1295379390497107727U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8700027645880997552U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10026130047465480902U;
            aOrbiterG = RotL64((aOrbiterG * 12417270861933696623U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9785843014096326696U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9998582683258411251U;
            aOrbiterC = RotL64((aOrbiterC * 7197956237569462269U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterA, 43U)) + aPhaseGWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterG, 34U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14738U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11893U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11652U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((aIndex + 13010U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 26U)) ^ (RotL64(aIngress, 13U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 3U)) + 16200278595895089008U) + aPhaseGOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 1029614154810465897U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 7129562468705441295U) + aPhaseGOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 30U)) + RotL64(aCarry, 5U)) + 14388903902433951274U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 57U)) + 1013568949315967455U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3128823373497815651U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14525694606889470589U;
            aOrbiterA = RotL64((aOrbiterA * 12053226114431679195U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14443983602196782887U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12244220415328641190U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15052949098014803181U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10477159225338766614U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2842870123078131566U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11522265477555954071U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8621138818955849917U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5038396344400303181U;
            aOrbiterC = RotL64((aOrbiterC * 14636756322207385447U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2768613802894372496U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2027754864051410015U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2461322540050569287U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 26U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterC, 13U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 54U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 19864U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17148U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20370U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23861U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aIngress, 35U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererD + RotL64(aCross, 3U)) + 14157904117287696136U) + aPhaseGOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 36U)) + RotL64(aCarry, 21U)) + 7369512677371640676U) + aPhaseGOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 8411250745902073798U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 5002041814539710275U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 57U)) + 9538041410816283124U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5210700103927513061U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7600709399101287982U;
            aOrbiterF = RotL64((aOrbiterF * 6777896926889560889U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2366369466696580499U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5544575244203019109U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16231219246786333057U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8710073749110329779U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15998211310115361630U;
            aOrbiterB = RotL64((aOrbiterB * 15275657696897688955U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15354357553877376422U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10657523549259276169U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13695239532898311073U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10405750198355464768U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3465819693133515142U;
            aOrbiterG = RotL64((aOrbiterG * 14678343718277562799U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + aPhaseGWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterH, 47U));
            aWandererG = aWandererG + (((RotL64(aIngress, 38U) + RotL64(aOrbiterI, 22U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + aPhaseGWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 29067U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 26245U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28399U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 27598U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 11700815697312060726U) + aPhaseGOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 58U)) + RotL64(aCarry, 51U)) + 11808423452327465441U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 37U)) + 8670503858631730886U) + aPhaseGOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 11U)) + 2400061067991988544U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 16163118178366229686U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3280178595904941068U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3298683600817047727U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9865649058799255343U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16321624053445183574U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6730229877611375225U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2022290495153519279U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10162830636713641322U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15646771327759599256U;
            aOrbiterD = RotL64((aOrbiterD * 15333053762177144775U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14841751262270544102U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9545541117228834895U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11529769874752969377U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14676615635857599982U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1231768638470558855U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2716808508509014677U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA + (((RotL64(aScatter, 36U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterA, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererB, 46U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Fencing_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 3783U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2585U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6368U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 3655U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 26U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 1297415699043177788U) + aPhaseHOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 17583786534509260153U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 35U)) + 643197858925708798U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 5062653766915694874U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 50U)) + 7034273638367180511U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2026909726972916996U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2785690475553211646U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6612792037861160393U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2910341716302991892U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2834181605200829791U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1510617068750957651U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13323052600571281928U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10434901530315760460U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2042210188346767033U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 247903955625194782U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5196515747387257163U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1799024689023272275U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7196305682377987476U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14777739876892587484U;
            aOrbiterA = RotL64((aOrbiterA * 95220583948241581U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterD, 12U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 12U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15645U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 10087U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13702U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12928U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 1898718075389870739U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 5631794889237247403U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 29U)) + 18219714659484524607U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 41U)) + 15419581386225732921U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 5U)) + 9125575431710198210U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12205871520544965505U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7617534300497343422U;
            aOrbiterA = RotL64((aOrbiterA * 10052675719887595625U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18017579105368135814U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10693882161946020042U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2326507900303932855U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11669615701700895306U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11045110212889232165U;
            aOrbiterK = RotL64((aOrbiterK * 5965171269273719849U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18019107802806469913U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12315940560472528716U;
            aOrbiterD = RotL64((aOrbiterD * 4505122470351404065U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 4899009736070044310U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17412253404253730364U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10791901166391946485U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 58U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 12U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 38U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 19956U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22740U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23735U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 23943U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 14U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 966899917801652720U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 19U)) + 10996327672320748649U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 4188171566846621107U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 48U)) + RotL64(aCarry, 23U)) + 5886209243097387959U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 11U)) + 14940428957136728111U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 179187285531914832U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6685351948936817752U;
            aOrbiterI = RotL64((aOrbiterI * 15533370414711696803U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1894506461704029700U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4182760368636977082U;
            aOrbiterA = RotL64((aOrbiterA * 972988091869133921U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12523318028514940790U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5059306166973366892U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2857409765717296483U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5890872367917643851U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17747338389865221534U;
            aOrbiterF = RotL64((aOrbiterF * 5306740664798049267U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13906227834259884100U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7152105382899756368U;
            aOrbiterB = RotL64((aOrbiterB * 6772157117358310485U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + RotL64(aOrbiterI, 4U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterI, 51U));
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterB, 27U));
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 24882U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28097U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27270U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25655U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 48U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererJ + RotL64(aCross, 23U)) + 5088525177670191619U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 9966456257813932112U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 7707646574027146307U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 34U)) + 75480203757681173U) + aPhaseHOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 384659134071835163U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3158769775373307778U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17360830943513941272U;
            aOrbiterA = RotL64((aOrbiterA * 9986023786908098621U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5317278822721604586U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1371427105215954781U;
            aOrbiterD = RotL64((aOrbiterD * 10956603063464438611U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3162710551223553423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5332921933853550756U;
            aOrbiterF = RotL64((aOrbiterF * 11709546145149357887U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10572462410297815854U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10234389605554817892U;
            aOrbiterK = RotL64((aOrbiterK * 2130374833440291193U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13421365517991380605U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 10186643614984034083U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8554471709467808453U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 12U)) + aOrbiterD) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterF, 21U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 53U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + aPhaseHWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
