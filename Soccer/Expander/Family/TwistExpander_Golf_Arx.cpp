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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD2ECC4B8AC242267ULL + 0xBC9E64F51C3DF80DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDCC1128950563F6DULL + 0xB38074BFD5CF6FAFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x940B5892CFD55479ULL + 0xA14D246916E3004CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFEF48F16B50BA963ULL + 0xDC3BE6A49ACD77CCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF1067D213D0DADA1ULL + 0xACC5E19CC2F58B9CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC08D0FFFFEA26DF9ULL + 0xC27EB98884FAE08BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD76CC4834AEF559FULL + 0xF8D1B5F64B412231ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF1C30327D7EF7CFFULL + 0xAE1B56333CCA38ADULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8064AA2859E01B67ULL + 0xEA04B312535F0F1BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDAA244B4D810CCC1ULL + 0xE14A373ABF5CDC73ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8494AFA6AD26F80FULL + 0x9FEA2874B99FCA00ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAE3B67D8F9CA2AFFULL + 0xC18EF110FC357A58ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDF1DDCD52CBED1CFULL + 0xD60561EA64E4F80DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA25E85ED6BF121E7ULL + 0x8DE202931184045CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9398F00D1572BAEDULL + 0xE218AF8F9EE89229ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA4124A8BBA30FA1FULL + 0xBA34800A94D84B65ULL);
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
            aIngress = RotL64(mSource[((aIndex + 4819U)) & S_BLOCK1], 6U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1319U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4879U)) & S_BLOCK1], 46U) ^ RotL64(mSource[((aIndex + 1088U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 47U)) + 3339283916456813609U) + aNonceWordM;
            aOrbiterG = (aWandererJ + RotL64(aCross, 21U)) + 11339086426180649584U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 16819191669329316585U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 10U)) + 8361916937762630725U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 27U)) + 18031328374429899857U) + aNonceWordP;
            aOrbiterF = (aWandererI + RotL64(aCross, 37U)) + 18261756894092897276U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 4250319792907645666U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 24U)) + RotL64(aCarry, 35U)) + 1492411503643460886U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 5U)) + 17369549067879344180U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 35U)) + 7301713524358676722U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 41U)) + 2985193736033012535U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14086975808140927408U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10390516547834639800U;
            aOrbiterK = RotL64((aOrbiterK * 11441293212275890819U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18205555540941493267U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16967799565443938873U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9209505304067579944U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3522631966146762306U;
            aOrbiterD = RotL64((aOrbiterD * 3441982898533162599U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8811497120829041188U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14707301680850257294U;
            aOrbiterB = RotL64((aOrbiterB * 11383709499376464085U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10080595991787801029U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6822892187784299166U;
            aOrbiterG = RotL64((aOrbiterG * 7417016898027778287U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1981637172055758689U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16463077485583119324U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 2876782050665869121U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8383837717361569465U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3529607472855930041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8850940802020173766U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 7821450253655655943U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7469160295100147267U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16973986572163482061U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15660743778376905023U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12371372942863279718U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12098525148034303633U;
            aOrbiterC = RotL64((aOrbiterC * 11234127652230231751U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5138683482859889480U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3339283916456813609U;
            aOrbiterJ = RotL64((aOrbiterJ * 10975353228235695455U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 40U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 42U) + aOrbiterE) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterA, 20U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterH, 37U));
            aWandererH = aWandererH + (((((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 13U)) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 58U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterB, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererD, 18U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 8014U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 7929U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7822U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 10069U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 35U)) + (RotL64(aIngress, 4U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 12U)) + 11521331427196538632U) + aNonceWordA;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 19U)) + 16653824187682957632U) + aNonceWordI;
            aOrbiterH = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 11654676587350088289U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 8010313317412193584U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aPrevious, 3U)) + 1108775560502907471U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 39U)) + 243952321439823521U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 57U)) + 2324945800401240403U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 41U)) + 9257554497543369657U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 16701314607244592540U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 14U)) + 3900445848034341782U;
            aOrbiterC = (aWandererH + RotL64(aCross, 21U)) + 7652316487347103658U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14980368605272070578U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2001165460948764796U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 8110980921827107649U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1911044015666991050U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11366207111147818339U;
            aOrbiterF = RotL64((aOrbiterF * 17234439040652553865U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16469329744002456607U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8062793687044950815U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5856142259851144369U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15364721421972807872U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8979915611483540231U;
            aOrbiterE = RotL64((aOrbiterE * 10899377466171153383U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7654234623563110457U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1526832460342135008U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 12766083052650723051U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1596625448797520938U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15723912914858523080U;
            aOrbiterC = RotL64((aOrbiterC * 6003857787643420337U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7664226719746532168U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13767298788411473401U;
            aOrbiterD = RotL64((aOrbiterD * 15663266144965532019U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8371251860069346385U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10143279934304029980U;
            aOrbiterK = RotL64((aOrbiterK * 12764966547132248131U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10034920090729616747U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14450253491131954914U;
            aOrbiterA = RotL64((aOrbiterA * 15877567779079226909U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9450697155749555210U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14051719612902917300U;
            aOrbiterJ = RotL64((aOrbiterJ * 7659810299163085295U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 659383614060726993U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11521331427196538632U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 1068009283450923005U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + aNonceWordM);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterG, 13U)) + aOrbiterB) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 52U)) + aOrbiterE) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterH, 41U));
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 37U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 15293U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 15558U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14689U)) & S_BLOCK1], 37U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 11592U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 39U)) + 966899917801652720U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 27U)) + 10996327672320748649U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 14U)) + RotL64(aCarry, 35U)) + 4188171566846621107U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 43U)) + 5886209243097387959U) + aNonceWordK;
            aOrbiterI = (aWandererI + RotL64(aCross, 41U)) + 14940428957136728111U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 3U)) + 179187285531914832U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 37U)) + 6685351948936817752U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 48U)) + 1894506461704029700U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 4182760368636977082U) + aNonceWordC;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 12523318028514940790U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 29U)) + 5059306166973366892U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5890872367917643851U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17747338389865221534U;
            aOrbiterB = RotL64((aOrbiterB * 5306740664798049267U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13906227834259884100U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7152105382899756368U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6772157117358310485U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17868101884759619240U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11758843266314148347U;
            aOrbiterC = RotL64((aOrbiterC * 5919135169337501485U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13950566197090324859U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17278105609930477854U;
            aOrbiterK = RotL64((aOrbiterK * 11431842718945107359U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9556785965646738355U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 841298436857932987U;
            aOrbiterH = RotL64((aOrbiterH * 15077843186688841797U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1951515285492133830U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15775839819330588437U;
            aOrbiterG = RotL64((aOrbiterG * 7902654031401620995U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5585458468816495436U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17258586689032223623U;
            aOrbiterA = RotL64((aOrbiterA * 1652050227399194271U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5254132659445988836U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15440741734777060925U;
            aOrbiterD = RotL64((aOrbiterD * 17445581079035134067U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16770361602586485631U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 14902616717976301965U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 7757713071544143453U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9521517757370835715U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 18241677917767801049U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 16977396965907931057U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14307634663160859644U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 966899917801652720U;
            aOrbiterF = RotL64((aOrbiterF * 17012361848398765251U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 12U)) + aOrbiterA) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aIngress, 24U) + RotL64(aOrbiterC, 21U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 10U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 36U) + aOrbiterK) + RotL64(aOrbiterI, 41U));
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 51U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18751U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((aIndex + 20981U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18179U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 19839U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19750U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 48U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (aWandererI + RotL64(aScatter, 48U)) + 9107326720193244489U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 10868585484401664145U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 41U)) + 13637736741437846622U) + aNonceWordD;
            aOrbiterK = ((((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 6130725216183918844U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 21U)) + 2063834478521338187U) + aNonceWordA;
            aOrbiterH = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 8564870627911949158U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 54U)) + 6524015751064086390U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 23U)) + 9874937766875388236U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 14723718409522680894U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 13U)) + 13767059954741528279U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 11U)) + 6387608251033722169U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5391425980008431000U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11524218415655093779U;
            aOrbiterC = RotL64((aOrbiterC * 12508457981779189389U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 155510463350385905U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10554591788433641311U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 5412084824127934293U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8662160162966241542U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5092555636369853727U;
            aOrbiterJ = RotL64((aOrbiterJ * 433807340167635499U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7163345798448796101U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 695089002178413267U;
            aOrbiterH = RotL64((aOrbiterH * 17302689458565434475U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5409173939213468972U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15349690077393827541U;
            aOrbiterF = RotL64((aOrbiterF * 10984681254001609841U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12376011890751302027U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7809614158898158383U;
            aOrbiterK = RotL64((aOrbiterK * 13845113198736843629U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13031938699536449576U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3983178190194056516U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1341678482929213405U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5567935037909671790U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17137042627663349797U;
            aOrbiterI = RotL64((aOrbiterI * 13535586899620672373U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8726085717433137208U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13154097637429217548U;
            aOrbiterG = RotL64((aOrbiterG * 5523758597936082363U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4030516340575723215U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 7121696965917254968U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 13569584361980228493U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12079991626282752674U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9107326720193244489U;
            aOrbiterB = RotL64((aOrbiterB * 7225937408665051799U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterK, 60U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterD, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterI, 22U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterI, 27U));
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22043U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 22575U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(pSnow[((aIndex + 22835U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((aIndex + 25689U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24668U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22880U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 13U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 15045917390223766480U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 51U)) + 10763054007033668758U) + aNonceWordF;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 34U)) + RotL64(aCarry, 3U)) + 13190170142593666607U;
            aOrbiterE = (aWandererC + RotL64(aCross, 47U)) + 9657025731441167065U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 41U)) + 11433367178975954211U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 17904920143996810366U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 53U)) + 3244383020512113283U) + aNonceWordN;
            aOrbiterB = (aWandererD + RotL64(aScatter, 19U)) + 6538815775171139091U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 13U)) + 7195368312757976343U) + aNonceWordO;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 21U)) + 18134430713910279374U) + aNonceWordB;
            aOrbiterI = (aWandererA + RotL64(aScatter, 28U)) + 6571776588427107976U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11830778129647517758U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9793702760907767365U;
            aOrbiterA = RotL64((aOrbiterA * 4096246227968677179U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2287235876793192036U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8951959188326141794U;
            aOrbiterK = RotL64((aOrbiterK * 9968356718110753845U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7583061790273240157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3571364625022806085U;
            aOrbiterG = RotL64((aOrbiterG * 6238360922735480669U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13869345563551689212U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 277480328952975002U;
            aOrbiterH = RotL64((aOrbiterH * 1057564597096163085U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4983735092494677578U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 9490022869381030928U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 12926352917961703123U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7928039573014765566U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6504190875809407084U;
            aOrbiterF = RotL64((aOrbiterF * 14648214826494826711U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2787985600176307413U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16308785053443116826U;
            aOrbiterI = RotL64((aOrbiterI * 17867565986311256691U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12788128335006767824U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1187040019537798339U;
            aOrbiterJ = RotL64((aOrbiterJ * 10834905007658184183U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 10771230162770496645U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6542421559654716320U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16829492790597069373U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 702458690970201679U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2806140783487813070U;
            aOrbiterD = RotL64((aOrbiterD * 7415398198842270381U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 950611302199732036U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15045917390223766480U;
            aOrbiterB = RotL64((aOrbiterB * 9358017420417979347U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 52U)) + RotL64(aCarry, 51U)) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterD, 35U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 39U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 36U) + aOrbiterI) + RotL64(aOrbiterG, 57U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 14U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28491U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 29938U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 28272U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30555U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31536U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 30884U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28197U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (aWandererF + RotL64(aCross, 39U)) + 10336802574069791273U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 46U)) + 169025388197058936U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 5U)) + 6541354188379168846U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 53U)) + 16223920526599306104U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 43U)) + 12756613707692514808U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 5082475548176484035U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aIngress, 21U)) + 4907435526952698526U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 14236627073831834337U) + aNonceWordP;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 11502511046130497584U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 27U)) + 3679044835550219497U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 58U)) + 11254838916686736746U) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10582608424233200966U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterJ = RotL64((aOrbiterJ * 7363770199734997411U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4628253464169957835U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17664454668473204465U;
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3798386391743884889U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1379331161819246587U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13086160171095077295U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9816600392407327227U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16781971616348376878U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 12503867584828289879U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4807797577690520554U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterD = RotL64((aOrbiterD * 9453302540675483005U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7909676419643119585U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 256053568910383007U;
            aOrbiterA = RotL64((aOrbiterA * 11965085163352053161U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16179914439220412472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3968867762761955845U;
            aOrbiterG = RotL64((aOrbiterG * 7473632378251893139U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7474832923901283742U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4736994731050735779U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9839654409121414047U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 596484364660389193U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13822222274464306169U;
            aOrbiterC = RotL64((aOrbiterC * 1723502278319885511U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16307920280681985443U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3505106171801702915U;
            aOrbiterB = RotL64((aOrbiterB * 8479675421552861243U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4987142580981135150U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10336802574069791273U;
            aOrbiterF = RotL64((aOrbiterF * 2670706512498539705U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 26U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 14U)) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 60U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 37U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF4632C06DF89D745ULL + 0x891914A8341B9BA3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x89B61FF0A602DCADULL + 0x90E78BF4A4E1718AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9F7618C46E96EA19ULL + 0xA39097CDD8EB7F64ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8FC4339B45190C69ULL + 0xE206BD35E3894A4DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDF9E0E61A7561583ULL + 0xFE56C511BA020B9EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9DFB2CEE8809EB7BULL + 0x8A6F2B8228C71450ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDF149F40D4C72787ULL + 0xCFD8E26E6BD85D54ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9862618BB2135B49ULL + 0xA7CF63FA787463EDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD358C8B88A29498DULL + 0xEA9F0E9B26190888ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x967D4208E31A0453ULL + 0xDA9389B051AC94A2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9AFB389B116002A9ULL + 0x912FE0D5479E4C9FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBA86B3E1575C1B71ULL + 0xDD3F19D6CF22D247ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD16F1E87435D2711ULL + 0xB0E7D5FC45673500ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8C67125A9F236FF1ULL + 0x85E18EEC093AF593ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFBED629B84AE1BE5ULL + 0xE64EDB44AC5608FBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCFE01707F8DF1DA5ULL + 0xE33E072350234E29ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 3505U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2094U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1241U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 2746U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 41U)) + (RotL64(aCross, 26U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (((aWandererD + RotL64(aScatter, 37U)) + 2558105147674438050U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 21U)) + 15856662514774702561U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 41U)) + 13346869226246584582U;
            aOrbiterH = ((((aWandererJ + RotL64(aCross, 6U)) + RotL64(aCarry, 23U)) + 7632111846116243973U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 2102101361626976279U) + aNonceWordH;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 11U)) + 5605968705067851563U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 53U)) + 6842483186584326681U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 30U)) + RotL64(aCarry, 41U)) + 5559797213819425064U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 47U)) + 12422313931331576759U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2751024420047872601U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11031320239359798610U;
            aOrbiterE = RotL64((aOrbiterE * 8607639453141148025U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14366375309473793217U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11971479429768505316U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10063001532313098203U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3947595951884469542U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17882767922372770896U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 3361906348965810211U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 513871456983509223U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 5951677013597794294U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 8508629569649935293U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 437626309049021931U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 466674061172005705U;
            aOrbiterF = RotL64((aOrbiterF * 1310502572084891157U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12362602809233133718U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10525852878882195702U;
            aOrbiterA = RotL64((aOrbiterA * 17755022180514914325U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17927000184308583095U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 566723721423470052U;
            aOrbiterH = RotL64((aOrbiterH * 17710534355278632573U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9504585484034413577U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4614306037721859929U;
            aOrbiterJ = RotL64((aOrbiterJ * 170807293799483539U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1463218357720031588U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4036696102163560633U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15389914226155130065U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 6U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterD, 58U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterF, 4U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10009U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 10289U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9542U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6427U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 6161U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 26U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = (aWandererG + RotL64(aCross, 20U)) + 12615321415808640429U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 35U)) + 15712784676459931207U) + aNonceWordB;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 11013335427004930046U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 8298733856304768806U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 39U)) + 6207732959150824216U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 10U)) + 9769864876127544038U;
            aOrbiterH = ((((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 10782181918651152563U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererK + RotL64(aCross, 51U)) + 5790454015845620939U) + aNonceWordE;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 43U)) + 15606578025386733803U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5522352539991175304U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5993355818572869649U;
            aOrbiterG = RotL64((aOrbiterG * 15221467311057431139U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10864534396947622047U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12090053126235913528U;
            aOrbiterC = RotL64((aOrbiterC * 7250801471645972261U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14191181677234981396U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2258570108233924592U;
            aOrbiterH = RotL64((aOrbiterH * 8307541155393855209U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8448114811381534603U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2702389315763499817U;
            aOrbiterA = RotL64((aOrbiterA * 6710443836432274393U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17202184076718780200U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 150549910056015002U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 195034681254956335U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4910512055808124967U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4783477997418403079U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 861977492146512865U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13842899106208709771U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7930112618036681468U;
            aOrbiterJ = RotL64((aOrbiterJ * 8609551859830858419U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8790107242863198659U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6882768826643279144U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 13745521454063360763U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12136498871759890015U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8120456314755584336U;
            aOrbiterD = RotL64((aOrbiterD * 1830725195528043575U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 12U)) + aOrbiterB) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterA, 28U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 14782U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 15187U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13150U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13357U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16173U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 11U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 53U)) + 9774364261626083532U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aCross, 29U)) + 18059001521926116420U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 34U)) + RotL64(aCarry, 27U)) + 10615626210406381148U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 10536484278007898620U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 47U)) + 13320663045139972700U) + aNonceWordM;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 5U)) + 17127001787268166583U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 21U)) + 16742574590844166551U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 8347719720758228053U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 10U)) + 13502468705946051986U) + aNonceWordI;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3512687886188904904U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 495660316165795934U;
            aOrbiterG = RotL64((aOrbiterG * 6724596801190194913U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5092722552034477356U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15641128019608284015U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3621036395703527059U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15421873776811085458U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17978775513204574125U;
            aOrbiterK = RotL64((aOrbiterK * 18359600395119440183U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16617179197537669849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1931805387534012528U;
            aOrbiterD = RotL64((aOrbiterD * 3400139345857733775U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9544923119559308431U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12930999400470173353U;
            aOrbiterA = RotL64((aOrbiterA * 16791006919271490005U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 13673733276226249890U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2032263473309124738U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 3088728329261360607U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14868502349358414206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10116495537187552321U;
            aOrbiterC = RotL64((aOrbiterC * 1380512121796709469U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5341113995358179244U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8415417980279705731U;
            aOrbiterF = RotL64((aOrbiterF * 8521501372683793821U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2462819265072352463U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7657062767608441931U;
            aOrbiterH = RotL64((aOrbiterH * 15554638801273540163U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 54U) + aOrbiterD) + RotL64(aOrbiterJ, 23U));
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 60U)) + aOrbiterH) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 11U)) + aOrbiterF);
            aWandererF = aWandererF + (((((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 3U)) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterK, 4U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21733U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 16394U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19863U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19240U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 20954U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (aWandererG + RotL64(aIngress, 5U)) + 17081642665820489793U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 56U)) + 14468854040067229623U) + aNonceWordC;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 51U)) + 2249450222593057429U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 14964389079511378664U) + aNonceWordL;
            aOrbiterK = ((((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 17003491054252360650U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 37U)) + 12710882240582032588U) + aNonceWordP;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 9887078182156755359U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 18U)) + 7665284531810584704U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 23U)) + 7304284015511876717U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5517927023543751734U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 17704756310857362759U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 15826832172923213591U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11347400363019508578U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11696395232760991243U;
            aOrbiterI = RotL64((aOrbiterI * 9725231749679442003U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10875780291242873583U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7808740614343437672U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8889516201913716283U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3145390996141902032U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16080636485642732615U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 7445756373012217305U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3929263288176983844U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18210228766683996806U;
            aOrbiterC = RotL64((aOrbiterC * 13178080076505449091U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13948962323541421431U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3037683309790156893U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13406672352222636739U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17827265198532699474U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7270895262023504864U;
            aOrbiterA = RotL64((aOrbiterA * 13467417362477308167U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6431243064980879185U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6680205390976259885U;
            aOrbiterF = RotL64((aOrbiterF * 10421386694108590789U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15910655919164357152U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8046213498216027383U;
            aOrbiterJ = RotL64((aOrbiterJ * 18061867495824063553U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 30U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterI, 56U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterA, 27U)) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 54U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterE, 46U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 22337U)) & S_BLOCK1], 6U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25146U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25426U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 22493U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (aWandererG + RotL64(aCross, 23U)) + 17668251151213543491U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 35U)) + 16101602509895104517U) + aNonceWordF;
            aOrbiterG = (aWandererA + RotL64(aIngress, 54U)) + 9083915270773304935U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 27U)) + 12810720730318214811U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 18113428002071925621U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 43U)) + 1582208899354109878U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 60U)) + 4180688104819188154U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 8954598189262820611U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 15360094153175355879U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8383954114668216260U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15626783326234049197U;
            aOrbiterG = RotL64((aOrbiterG * 15058420415480073793U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10609978564404958066U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17656516608997517984U;
            aOrbiterA = RotL64((aOrbiterA * 4590620354119899777U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 760077259110786536U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3597338735888033063U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 6548831472863517621U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4431777844935985157U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10710423172154671296U;
            aOrbiterB = RotL64((aOrbiterB * 16267496318491473315U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10240882795242085185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7826053487019825891U;
            aOrbiterC = RotL64((aOrbiterC * 15053729937684375907U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9418883403715727353U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11507423614799075545U;
            aOrbiterE = RotL64((aOrbiterE * 16189463984557044693U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11545217316421066655U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 617921402135485341U;
            aOrbiterI = RotL64((aOrbiterI * 8182920764965471653U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14456933220749921009U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7990243583564535387U;
            aOrbiterD = RotL64((aOrbiterD * 5994900368027985469U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14023633125757654751U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11319146808574958827U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 13676159969338309307U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 58U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterA, 4U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 39U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterB, 12U));
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterD) + aNonceWordE);
            aWandererB = aWandererB + ((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 31879U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29580U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32344U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 28202U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 36U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 13U)) + 18144572925667544139U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 5659758077574059728U) + aNonceWordH;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 46U)) + 6343330616999166392U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 19U)) + 17754639838410839447U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aWandererH + RotL64(aCross, 53U)) + 9451843819849581729U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 27U)) + 7957854457197462212U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 1461994799722205010U) + aNonceWordM;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 18002214276252170177U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aIngress, 4U)) + 14689869073147027164U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3978104368003440293U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8512135845221335386U;
            aOrbiterI = RotL64((aOrbiterI * 10506667163729414667U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1477533446382953439U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2166717790929947990U;
            aOrbiterE = RotL64((aOrbiterE * 6538884492418324461U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8082437060686606995U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4363687722464700362U;
            aOrbiterH = RotL64((aOrbiterH * 7199165810993478887U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15782763348014924206U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8572509150015960728U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3340528604891897779U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12248271773316742521U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9602078627638561949U;
            aOrbiterD = RotL64((aOrbiterD * 1860631869877427405U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 17244849374768558859U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1030743048280579012U;
            aOrbiterG = RotL64((aOrbiterG * 10858949914285817051U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 17722342363541914280U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15667504059789880034U;
            aOrbiterC = RotL64((aOrbiterC * 15872269872168533709U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12645332941998550794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9938135244509986497U;
            aOrbiterB = RotL64((aOrbiterB * 16548185968987392957U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4024609904162105979U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6732064218696157303U;
            aOrbiterF = RotL64((aOrbiterF * 3815409766145891393U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 44U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aNonceWordG);
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 48U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterB, 23U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 12U)) + aOrbiterF) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB3D5F5997F30F3DFULL + 0xEC7BAF06ED507354ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA57F01A342D25EADULL + 0xECB6A84EFA1B47A8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8F80DBF7E9888BF7ULL + 0xABDD26266C61E490ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCA8DED95EE100A5BULL + 0xCD78AF6067EA6102ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA9B0B813CEEE7BC3ULL + 0xC5D19FC4954F7BFAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAA40E229E8586EE9ULL + 0xB64C279007DA82D3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF73ED4423280655BULL + 0xAA9FF99337A3C036ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF4A6383AE1E2A247ULL + 0xA7D98B99542FAEF8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA73320D90AD860F7ULL + 0x890F6AFAE76CA570ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9917702DBED4BF49ULL + 0xE2A8D69498CCA517ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFCC6F911B67BE58FULL + 0xACA36D000F5473CBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB2E329F9515903B3ULL + 0xFD4E68D8516B160AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x877F9B7C78B8C293ULL + 0xB654F8D35F8F99FCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x98136893B2ABC14DULL + 0xE8E043E1451BDBCAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF4ADA3F01B3F2667ULL + 0xCA6680441DF99675ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF7F5044225EADE81ULL + 0xEA81249DB90034CBULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8017U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 5355U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 54U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7336U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2520U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3431U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 18191288703716505885U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 9824014524910417136U;
            aOrbiterC = ((((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 11953012029254917548U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 29U)) + 6297568011027199089U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 50U)) + 2576999400457367975U) + aNonceWordA;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13176139160575558254U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9978408174563621810U;
            aOrbiterC = RotL64((aOrbiterC * 1399052522159751531U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16765834875061607142U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16534507305459121344U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8943988574248229067U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 3114710944346151807U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10240517868726718592U;
            aOrbiterF = RotL64((aOrbiterF * 4645691562915606463U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10721450637990777883U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 16689590768796583952U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 3046344179729901637U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2427422768928450209U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13495584061816457831U;
            aOrbiterB = RotL64((aOrbiterB * 6670984773768885119U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + aNonceWordH);
            aWandererD = aWandererD + (((((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterH, 4U)) + RotL64(aCarry, 51U)) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14041U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 8764U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11178U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9943U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11570U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8508U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11373U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + 14249093584376402677U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 5U)) + 8756965951816492264U) + aNonceWordJ;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 41U)) + 11221139480258176330U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 17218894445564194851U) + aNonceWordO;
            aOrbiterH = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 8064642692524949490U) + aNonceWordP;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5822093203710704646U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3217799620158102238U;
            aOrbiterF = RotL64((aOrbiterF * 2806328682494910635U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2613757677892120843U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 13647481499551657237U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5517563514031899891U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3545714196663685016U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9735422670576621521U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 7276207208162697249U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3911046580637583767U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9315984027042049203U;
            aOrbiterK = RotL64((aOrbiterK * 12568550776487242469U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8926367674641729058U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 11035347490524961446U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 10948288997163592463U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + aNonceWordN) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterH, 44U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 44U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24537U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 22643U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20097U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21109U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20955U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21403U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23290U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (aWandererG + RotL64(aIngress, 22U)) + 13204735390996728477U;
            aOrbiterB = ((((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 851171359595647173U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 16745304202825290723U) + aNonceWordC;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 562392736584913979U) + aNonceWordG;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 3U)) + 3244267012529053918U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17282536111067869133U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14851130066471729068U;
            aOrbiterF = RotL64((aOrbiterF * 6308165353504550619U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5256130407952363129U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2904742485828362001U;
            aOrbiterC = RotL64((aOrbiterC * 12941135856735075457U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3723346325449225387U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5344621093694027341U;
            aOrbiterI = RotL64((aOrbiterI * 9044881458629673499U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12919263300833603026U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17989801264160996071U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15468293047311883751U), 41U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 5022175042377172157U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 16684822380107847758U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 2834049270263837537U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 60U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 28U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26135U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 30056U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 29822U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27576U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29112U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30654U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31150U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 9654059367478508868U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 4U)) + 6473006635864677427U) + aNonceWordM;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 6944184481315853243U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 4061496421939102306U) + aNonceWordK;
            aOrbiterF = (aWandererI + RotL64(aCross, 41U)) + 15791809275719085463U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14050798802646323055U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12072905924741758266U;
            aOrbiterK = RotL64((aOrbiterK * 4757104346636738119U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17639076509231343896U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12195388285571234715U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4317060502521195769U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4325404419499496529U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5910567888204238382U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11503787177122206937U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13092940059929942699U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13381962590820308761U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6345904465930943295U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15622862439323440527U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14027151901132249793U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2273573821630510087U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 36U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 58U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x91E107E811CAB823ULL + 0xB5BC202FE360C6D2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8F3D5B964752CF19ULL + 0xBD85E568527248E4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB6CD18DF5FF5D717ULL + 0xE48F08727E0B448EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC4F35C3198F38FA1ULL + 0xE73436D49B1796FCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB50D2D01885BF909ULL + 0x9B587BB6D7E86F81ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8417F1A92E1F832FULL + 0xD4615557D448D751ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8A0C20C88EA003B3ULL + 0x87708C2FABD7A39AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA91F01E3ECFF6CF5ULL + 0xE3D0EAAB7753B570ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE5CF5AD1B27CF6DFULL + 0x8DC74566168E6486ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC3ACADD3A633E5DBULL + 0xAC7E64406F09A1FEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF4682AE07C22042DULL + 0xADEAA342D266CEEEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xACA0735F09C9D73BULL + 0xABAC2B6CB2B7438FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAC1EC0DD8A1861F3ULL + 0xFE93C4FEB5C88BF3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBEDB5AAA484E9143ULL + 0xA1504BEAB9C7C288ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x855732898700834BULL + 0x96B14F348937F07AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFA5EBB97E043D7EDULL + 0x99F5BD311BA6044FULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 553U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 5646U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7610U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2435U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4500U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1099U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 26U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 12131317914288566437U) + aNonceWordL;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 51U)) + 5672805657999385496U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 43U)) + 3581710244233124197U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 34U)) + 15251296040538489436U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 57U)) + 11295008604679904153U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 2230897493419504490U) + aNonceWordP;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 7109600123297458999U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 13119156643107683803U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14755160867807355250U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10007087518844899239U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 16829363373287496832U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 16981122946707720883U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5394974422201576627U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8806000776958603317U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16810923047720876014U;
            aOrbiterG = RotL64((aOrbiterG * 17872735050219539145U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8129657889554436328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8653100378491974463U;
            aOrbiterI = RotL64((aOrbiterI * 11395283153912468661U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17048985838727432415U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10892675550889823573U;
            aOrbiterA = RotL64((aOrbiterA * 976298937314081913U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15960158965421254346U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12290011578634850001U;
            aOrbiterH = RotL64((aOrbiterH * 9280475585104357745U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16265047040311479093U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10312956912303656248U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 3012584393253845131U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterG, 22U)) + aNonceWordB) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 10U) + RotL64(aOrbiterD, 37U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aNonceWordM);
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterE, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9817U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 11077U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11197U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 12168U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8380U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14518U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12664U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 56U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 3248574644570178787U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 41U)) + 4506961512959200024U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 27U)) + 8423739774540738590U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 6593975869641735337U) + aNonceWordM;
            aOrbiterI = (((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 23U)) + 16441716090557369103U) + aNonceWordI;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 5U)) + 7936601450453207914U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 13U)) + 13333752583560167065U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8013703284795432973U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2349852779887439236U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 2422888500648100783U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5318539364763284138U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 11450957608502944376U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 1957880366707810635U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9058992558327552687U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 632095686920230926U;
            aOrbiterH = RotL64((aOrbiterH * 12460364388358520799U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14734218428913777098U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16344357661370784442U;
            aOrbiterJ = RotL64((aOrbiterJ * 15049472842002138369U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2981145363531184308U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14176472085175714494U;
            aOrbiterE = RotL64((aOrbiterE * 2584623327412130939U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11198457590069700889U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 952584436750426828U;
            aOrbiterA = RotL64((aOrbiterA * 1165713888651280355U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4311591763498985972U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16194341833989936369U;
            aOrbiterG = RotL64((aOrbiterG * 9997934560195932575U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 20U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 4U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16541U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 22145U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 20746U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16792U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21609U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22650U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 17544U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 37U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererK + RotL64(aPrevious, 51U)) + 13481227414590594621U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 43U)) + 17425964381118918026U;
            aOrbiterA = ((((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 4792004356135956581U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 29U)) + 11926849936000639098U) + aNonceWordC;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 60U)) + 990697329347742142U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 37U)) + 9307721505373076588U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 17605732738841908719U) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13110764518634187439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17970109897810645911U;
            aOrbiterA = RotL64((aOrbiterA * 10395095143998920213U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10273133817644703654U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11239046688920468137U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5197802934333553327U), 39U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 8355821483275763145U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15522151127786049345U;
            aOrbiterJ = RotL64((aOrbiterJ * 4844278537850520413U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5381663179722418112U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 9551368011768104906U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 14202470972121732997U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16264476585232221270U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7721417776432288282U;
            aOrbiterE = RotL64((aOrbiterE * 10267770327791051869U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 339418090653475277U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3247926250495935511U;
            aOrbiterF = RotL64((aOrbiterF * 16824669543765729097U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3390560045236418590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3894024951542543635U;
            aOrbiterH = RotL64((aOrbiterH * 10599637790900418767U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 58U)) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 11U)) + aOrbiterB) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 57U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32717U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 27416U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 31183U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 25253U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26321U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30461U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30656U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 56U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 21U)) + 8101351470141807662U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 37U)) + 6965474099521076705U) + aNonceWordH;
            aOrbiterI = ((aWandererK + RotL64(aCross, 14U)) + RotL64(aCarry, 57U)) + 6803828268885684784U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 27U)) + 13454235922950972488U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 5U)) + 11678091885751244777U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 5307134544628507141U) + aNonceWordN;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 4873703518950429353U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8542156221858586039U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 3993726182905296513U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 11331376012938127609U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12113047622035464386U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1944244448665721151U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7010050836758762003U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12914188029425467576U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2486762763475327024U;
            aOrbiterB = RotL64((aOrbiterB * 12319769994433811617U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14580191602982245481U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12093414832400135066U;
            aOrbiterF = RotL64((aOrbiterF * 12720286833215690663U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13623906997320021065U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9977356009806428696U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2005536391712733499U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3694954095397810851U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11453812627797091638U;
            aOrbiterA = RotL64((aOrbiterA * 13730420725113907161U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 542311345544726351U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3024285045990499484U;
            aOrbiterC = RotL64((aOrbiterC * 5153745952148205645U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 43U)) + aOrbiterB) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + aNonceWordI);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 42U) + aOrbiterK) + RotL64(aOrbiterC, 12U)) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD90646FF64A778D5ULL + 0xFF7695661A23F70FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE704121DFE85EE03ULL + 0xB1F226365DE0AA72ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD5DF173B791012A7ULL + 0xA279888B8DAD6E6DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCC95BBE50B2DFBFBULL + 0xE5457F7174B491FBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xED2E91A7AC64265BULL + 0xD3BDA441101385DCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x85501449D038742FULL + 0x8F3B088B91D2B06EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB71E6079DE4AA6B5ULL + 0xFD6572477B6DD657ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAED2D5190A33773BULL + 0xB59587E9C52FD61EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC4A62A2CB6AFD599ULL + 0xD404C1702B6CD276ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB43AD07C8918A221ULL + 0x96BAFBC0E8CDA6C4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD79993DB44F8DB2BULL + 0x94EFA87F831CDC4EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBE526BE5897A1149ULL + 0x8A6364710BA5FE93ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC407BB933772996BULL + 0xAA1B1B4DA7573031ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9CCF2C625DC65351ULL + 0x99B16D9A042CD04AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x91A6B575EA92038DULL + 0x8E56AB9501E4E133ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA69F1436884449CBULL + 0xB9C87F32E56F4F1AULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2105U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 2115U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1810U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4444U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((aIndex + 5459U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 15813325389431304548U) + aNonceWordO;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 21U)) + 2223874171125403602U) + aNonceWordG;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 10U)) + RotL64(aCarry, 51U)) + 5510483568496824130U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 15474152493495661876U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 51U)) + 16846339705130829195U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 35U)) + 1289670576865739669U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 29U)) + 18017354919647006944U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8539685539928984921U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3333721400836704048U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3745286323481400085U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2261560416623815491U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4377786131746816567U;
            aOrbiterE = RotL64((aOrbiterE * 9164777834392621157U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18047393176583722719U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8184724021940434631U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 9800116157750921119U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10469895939183324807U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14543391765109879223U;
            aOrbiterC = RotL64((aOrbiterC * 4817987697437667225U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5757225781746158178U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3539000495894022869U;
            aOrbiterJ = RotL64((aOrbiterJ * 1032298408884695925U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11288971092707065923U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2761384065186568294U;
            aOrbiterA = RotL64((aOrbiterA * 3323838837427471051U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7120580145300417101U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 6977246291769372866U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 15170353875184253779U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aCross, 10U) + RotL64(aOrbiterA, 5U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 47U)) + aOrbiterF) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 14U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 5539U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 7664U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6756U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8699U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10275U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 7018U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 47U)) + 11274974230580265396U) + aNonceWordA;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 41U)) + 16658438747342741547U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 29U)) + 16612986966106053844U) + aNonceWordO;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 9329502236843231290U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 14088261356708344656U) + aNonceWordP;
            aOrbiterA = ((aWandererD + RotL64(aCross, 19U)) + 13692608802007789581U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 4U)) + RotL64(aCarry, 39U)) + 6824473946645682398U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2072915876348570040U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7420507753044460759U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 13239288539564571257U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4677557318688502593U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15081678577055628459U;
            aOrbiterF = RotL64((aOrbiterF * 16659305295251177155U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7026792817486507482U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14871665922943969918U;
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6807734532159292872U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17882797335141303280U;
            aOrbiterB = RotL64((aOrbiterB * 15439872930381050291U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9233542707022629190U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1205501586581350876U;
            aOrbiterC = RotL64((aOrbiterC * 2596053290311090589U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10878718669747466677U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8066049063548639241U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3031382633089381605U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 861295180226875235U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9134969787937288583U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 23U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterA, 42U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 53U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 28U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15212U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 14523U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12617U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12454U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((aIndex + 16259U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 26U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 8866844335448071821U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 15159698739856430085U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 13U)) + 9582805772989594633U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 1438538239931588373U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 37U)) + 10862044156620436139U) + aNonceWordI;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 60U)) + 13682173320058164615U) + aNonceWordK;
            aOrbiterF = (((aWandererF + RotL64(aCross, 3U)) + 8351013291045977592U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15777857431516633916U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16178966745333885377U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 7545129923202147703U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9031889187993001617U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 6308472367425865347U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 17118710301967158153U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 642109145903321046U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9186268569255318035U;
            aOrbiterD = RotL64((aOrbiterD * 10714674348507516749U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6091345356803675860U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13218507921880873749U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15415157927185637717U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4266652275234474616U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4391422098164506195U;
            aOrbiterH = RotL64((aOrbiterH * 17634679403195085867U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5160682323243635577U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10351728852161347404U;
            aOrbiterC = RotL64((aOrbiterC * 11105410036471745951U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3950932176454814023U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9536466386833427441U;
            aOrbiterF = RotL64((aOrbiterF * 18064984243491293435U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererA = aWandererA + ((RotL64(aCross, 12U) + RotL64(aOrbiterI, 21U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterC, 12U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 41U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18850U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 21422U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 20197U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21146U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 21259U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 6973892330986118220U) + aNonceWordL;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 39U)) + 9886813896272094864U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 29U)) + 10996306582517553173U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 3U)) + 8490648283899856223U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 105141713530704655U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 10U)) + 3114337422810562588U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 980857684690886131U) + aNonceWordM;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6562042345807072665U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15665371138706353619U;
            aOrbiterJ = RotL64((aOrbiterJ * 8086237578564620623U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18113013571374375028U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17405346422601997299U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11162604605443005253U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5130876096426182506U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1813821672299154629U;
            aOrbiterI = RotL64((aOrbiterI * 15478100342425611875U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15793814882743306728U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13925299440495476399U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 12049601510660117401U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9924458846049579438U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7810034662781768090U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10310594595026622513U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12812586478656872854U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5709576448057435237U;
            aOrbiterK = RotL64((aOrbiterK * 9101555233909853025U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7839807649914541516U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4717944526755429647U;
            aOrbiterE = RotL64((aOrbiterE * 8515229146471335721U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterH, 4U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 51U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 35U));
            aWandererH = aWandererH + (((((RotL64(aCross, 21U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 26431U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneB[((aIndex + 23500U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21977U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 23698U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U)) + (RotL64(aIngress, 6U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 35U)) + 5480870806135400132U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 47U)) + 8034874599430768743U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 3U)) + 4006919843736863767U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 2988069748674633718U) + aNonceWordE;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 58U)) + 12347295651973135786U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 14152683894431568192U) + aNonceWordN;
            aOrbiterB = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 15765143815254196598U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 10473067082331244233U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1089466925383677249U;
            aOrbiterF = RotL64((aOrbiterF * 17334888609179149753U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13215039929873682230U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3957997712247961479U;
            aOrbiterK = RotL64((aOrbiterK * 7631186240013784703U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10023907397941685546U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14593012591254614353U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17111300092082154687U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13353797968154036726U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9259966668512102858U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8326732574268308221U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10757861831070349321U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10530223113483866178U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 11269177745265396583U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7554320926405521865U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6978052067277966996U;
            aOrbiterD = RotL64((aOrbiterD * 18020134738536217801U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1053695861967171420U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15980734683539854451U;
            aOrbiterH = RotL64((aOrbiterH * 3208466640010555357U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 30U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterA, 47U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 39U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + aNonceWordG) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 28386U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 27993U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28620U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29424U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 43U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (aWandererB + RotL64(aIngress, 51U)) + 16802219662864902427U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 14332033461409490629U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 8781794298640286845U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aWandererD + RotL64(aCross, 34U)) + 8459933908074937264U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 1883580287986004426U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 57U)) + 17500258188004626118U) + aNonceWordH;
            aOrbiterI = (aWandererI + RotL64(aCross, 27U)) + 7934811305150872870U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6380363892361098905U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12623079132626676910U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12406671746344127399U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10455208121949202703U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8805532707916767629U;
            aOrbiterG = RotL64((aOrbiterG * 666082374369701881U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9161544391400377699U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3501434325829663268U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 7933545151293799637U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 651783304096081996U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 441505031509930622U;
            aOrbiterJ = RotL64((aOrbiterJ * 8045355432310956143U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1771159983581326424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15227946417377695989U;
            aOrbiterB = RotL64((aOrbiterB * 1563141188972797601U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4153717524193279095U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4404521756523902829U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1410342912973206203U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6231945075461813285U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3864780227164426690U;
            aOrbiterI = RotL64((aOrbiterI * 18031353247480673617U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 28U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterI, 21U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 50U)) + aOrbiterG);
            aWandererG = aWandererG + (((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 53U)) + aNonceWordP) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE3C0061CFEE73059ULL + 0x9B5D6353A1DB0D0FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB4B306E660FB57BFULL + 0x871ED84E902FCF39ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC8D1E9D3128C59C1ULL + 0xF632FFCC9B783F4FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x873B3D1099E3812DULL + 0xBF6BD6513758D36BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD0569933F6A5DDFBULL + 0x82AA23A1D984493EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9BADFF27A1B49CEDULL + 0xD70D20B139E1D4BEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE48286A830CA1E6BULL + 0xA0F58E2C53B971CFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9C82928711D38257ULL + 0x82836AC73BCDD148ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA5B17B075ED95535ULL + 0xC2429DC667CE352BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA99DEC4885122F75ULL + 0xF63D5415A1CF0CB9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF6D82A1529982D69ULL + 0x96336EE1BA32F45CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEE3056292A519BCBULL + 0xCCE02F1E3E403604ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB54DE307B53BFCE1ULL + 0xE4AC047A628CF911ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEC23E7ABCB8DC22DULL + 0x9DFFC6C2548AD2B3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF02BF7E00435353DULL + 0xB13D7D2C5A91A691ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC856B3B80CA8FE23ULL + 0xA778C73D8B2CF2C7ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 847U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 6826U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4067U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4607U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3244U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1916U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 54U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 37U)) + 4068921616130916949U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 60U)) + 12077715273915151726U) + aNonceWordP;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 16047546802670596833U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 11U)) + 9690277462716999763U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 19U)) + 14484814700447992628U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 17089267243053958210U) + aNonceWordF;
            aOrbiterH = (aWandererF + RotL64(aScatter, 39U)) + 9138746214446211147U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 13U)) + 10181001536979097045U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 46U)) + 6657458969093373191U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 7515983477876590988U) + aNonceWordJ;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 43U)) + 3039935555863947600U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16209389224740851136U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 725253312098083182U;
            aOrbiterJ = RotL64((aOrbiterJ * 17535989492095522597U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13307041115748941383U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7159572004825238263U;
            aOrbiterA = RotL64((aOrbiterA * 4855009895002398449U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12027236743251643820U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8717826175991286553U;
            aOrbiterH = RotL64((aOrbiterH * 1175614802543098451U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4769096034227659937U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11201226563992939616U;
            aOrbiterF = RotL64((aOrbiterF * 15595355978388159931U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17295978531215563256U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11850923890626719833U;
            aOrbiterG = RotL64((aOrbiterG * 3854851059897397075U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14139441565288097706U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 988684899382304485U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11929090869999700891U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6159251276942253175U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 4849529993914550651U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 18240712676783671317U), 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 6679745455842119497U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15838404437552215214U;
            aOrbiterK = RotL64((aOrbiterK * 17357853511591350887U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15853153471104458948U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12542164757451566994U;
            aOrbiterE = RotL64((aOrbiterE * 12163611303899312043U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14304233464055838869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4037999346933039765U;
            aOrbiterI = RotL64((aOrbiterI * 564236202758328407U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3582312827630995454U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4068921616130916949U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 1527829107415867363U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterC, 10U)) + aOrbiterD) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 13U)) + aNonceWordB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterJ, 28U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11419U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 13428U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11647U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9992U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9387U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10616U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15372U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 18U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 5U)) + 9220392006207660113U) + aNonceWordF;
            aOrbiterH = (aWandererC + RotL64(aScatter, 37U)) + 11305018553489132882U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 21U)) + 5860373868073513684U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 53U)) + 12319586170883987589U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 43U)) + 14072333614354649021U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 3U)) + 9332158529453194608U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 40U)) + 3860569321145958686U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 57U)) + 8119005668901240093U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 37U)) + 13918259792880333239U) + aNonceWordO;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 35U)) + 6938856216758228704U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 3960905839118710604U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6043879193734253929U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15691425268831319195U;
            aOrbiterI = RotL64((aOrbiterI * 7189195135654636271U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14912209933584715274U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16180183395910618923U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 3942858974766467849U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4966642362507707776U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6962226782462822861U;
            aOrbiterG = RotL64((aOrbiterG * 3647802407741095419U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12409120845092026295U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2302946450253872465U;
            aOrbiterD = RotL64((aOrbiterD * 7099576330777297911U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16118304388937163838U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15968419034359049422U;
            aOrbiterC = RotL64((aOrbiterC * 11736207775827080165U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17098982091525008231U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10298979200690822062U;
            aOrbiterA = RotL64((aOrbiterA * 12620028874653521945U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 552826643694256437U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11786560990790695378U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11190309640069208311U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13730399230389329793U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17614226859252305432U;
            aOrbiterB = RotL64((aOrbiterB * 2640019643570222977U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1062738267846296283U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13959480457644980835U;
            aOrbiterJ = RotL64((aOrbiterJ * 1194145909157002977U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4635071137794189167U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13374502212707796180U;
            aOrbiterH = RotL64((aOrbiterH * 129680788767298945U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 11479902881487238033U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9220392006207660113U;
            aOrbiterE = RotL64((aOrbiterE * 1437457810224888809U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 26U)) + aOrbiterF) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterD, 23U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterE, 56U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 46U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20674U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 20550U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 23536U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 18219U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17136U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19442U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 21098U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCarry, 21U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 9654059367478508868U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 6U)) + 6473006635864677427U) + aNonceWordG;
            aOrbiterE = (aWandererH + RotL64(aCross, 41U)) + 6944184481315853243U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 4061496421939102306U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 15791809275719085463U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 57U)) + 14050798802646323055U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 39U)) + 12072905924741758266U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 27U)) + 17639076509231343896U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 24U)) + 12195388285571234715U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 11U)) + 4325404419499496529U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 37U)) + 5910567888204238382U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13092940059929942699U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13381962590820308761U;
            aOrbiterE = RotL64((aOrbiterE * 6345904465930943295U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15622862439323440527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14027151901132249793U;
            aOrbiterC = RotL64((aOrbiterC * 2273573821630510087U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4584410023907605157U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15763755180625487157U;
            aOrbiterF = RotL64((aOrbiterF * 6755736130607297639U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17023059745666559199U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5298529579288492971U;
            aOrbiterH = RotL64((aOrbiterH * 2483562793328357721U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2870152867331654736U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12017191100173748848U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9958191466506480519U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15899529176182436062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16482713846343388735U;
            aOrbiterI = RotL64((aOrbiterI * 719465695044265601U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 12943393531812774449U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9881108254540483225U;
            aOrbiterK = RotL64((aOrbiterK * 8011108108007885059U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3532054586199716750U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7142230313294797435U;
            aOrbiterG = RotL64((aOrbiterG * 14154176174768868421U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 733958394016131587U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2060800099014517137U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 12988885554457108631U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2278498033811574812U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15342071118593803929U;
            aOrbiterB = RotL64((aOrbiterB * 7842196613533603835U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12987212219357101955U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9654059367478508868U;
            aOrbiterA = RotL64((aOrbiterA * 11796100167917742307U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 37U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + RotL64(aOrbiterG, 24U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterD, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 11U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterC, 43U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterK, 56U)) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 40U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25210U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 26841U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25910U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 28801U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27865U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25191U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 27238U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 38U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 2571116506511057880U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 3U)) + 13112435411509707292U) + aNonceWordD;
            aOrbiterF = (aWandererI + RotL64(aScatter, 53U)) + 10403251762787357256U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 47U)) + 8461951095541400405U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 12U)) + RotL64(aCarry, 21U)) + 9890793478557463815U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 57U)) + 3030229465991783707U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 51U)) + 7273848154043719247U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 39U)) + 10681774862516028276U) + aNonceWordN;
            aOrbiterA = (aWandererK + RotL64(aIngress, 35U)) + 7105082755586853104U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 26U)) + 6588579345319551129U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 14616333550242386092U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15439666290229654921U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3360304356760164799U;
            aOrbiterF = RotL64((aOrbiterF * 5164191920584106237U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14438730801970761889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14515616787452085729U;
            aOrbiterB = RotL64((aOrbiterB * 2041601927968559821U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4167853822635132419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8950982233003320239U;
            aOrbiterG = RotL64((aOrbiterG * 887144270884244907U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12391327853728029953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7100871010552394421U;
            aOrbiterC = RotL64((aOrbiterC * 16552349374101955967U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 15381697462381887944U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6801677551341079401U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13325954438427340703U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 947011315719204867U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6356920162398333481U;
            aOrbiterJ = RotL64((aOrbiterJ * 5566721941682667419U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 8910262020598577378U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8778455415977526457U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 4092470497616637283U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5585696961453127223U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9670655481681494412U;
            aOrbiterE = RotL64((aOrbiterE * 7863197168965036383U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10713004007087085729U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4036355047492922339U;
            aOrbiterH = RotL64((aOrbiterH * 6923922258047667173U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14580156873863533497U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7049502932205025182U;
            aOrbiterD = RotL64((aOrbiterD * 8665428649262370727U), 51U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 12707521269341941677U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2571116506511057880U;
            aOrbiterK = RotL64((aOrbiterK * 2388236789245943699U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 54U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 21U)) + aOrbiterC) + aNonceWordM);
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterA, 41U));
            aWandererH = aWandererH + ((RotL64(aIngress, 4U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAA53E7E5108897FBULL + 0xE498EAC1A56099F0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD76F7E54F9A8058BULL + 0xA22E213648E76DB2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF8D73E2B06C7F03DULL + 0xD6A69882B9D5F5F6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBD166E4B3697B057ULL + 0xD100A85CB3F91264ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE4244F38560B5259ULL + 0xB2498982FC70BF02ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8E80F89D8D503A5FULL + 0x9D0EA0F8373C57BFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCADF84C0C6C4B62FULL + 0x93C43DC4C871ABCDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBA547AE96A59A22FULL + 0xA79052D5350DEAE0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEC4998209780977BULL + 0xA129DBEC9663B4BEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD7523ECE40B07DF9ULL + 0xEA721273BBC1253CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD934BFFB3B17FCDFULL + 0xD82F57078914DC61ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA5F505FD1FE215BFULL + 0xCBE2D2E2AE043F3FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA8EBB5C8E1EDF499ULL + 0xC02D413AA816B672ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA2EFAC3953488FADULL + 0x854BAAA99B15C67DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE160E25F1A0F75C5ULL + 0xB65E13231D86E79CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB1318F1228B36947ULL + 0x9770384218C9B0DDULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2473U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 4677U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5872U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6542U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2454U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5262U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 37U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 18255347001097480328U;
            aOrbiterA = (aWandererF + RotL64(aCross, 34U)) + 13679246790311505735U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 57U)) + 10565839529765027116U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 14327172566224769901U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 53U)) + 16239024612038195174U) + aNonceWordP;
            aOrbiterF = (aWandererK + RotL64(aIngress, 3U)) + 13800012174212131890U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 26U)) + 13900288860157577583U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 4144386119777112740U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 11U)) + 3154558262670631372U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7456728543137614001U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11709519851158935384U;
            aOrbiterK = RotL64((aOrbiterK * 7016689518570071587U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15607438907832240304U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9276575329661725624U;
            aOrbiterH = RotL64((aOrbiterH * 8879744070762412745U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6459435969129449226U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6442382118416542275U;
            aOrbiterG = RotL64((aOrbiterG * 2921027306686588233U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12117432107282150865U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6831279293184793243U;
            aOrbiterI = RotL64((aOrbiterI * 2435360641135249073U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9520022957804572889U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8322178689474588679U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 1627707191467537115U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4162401591586869316U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8994015844714895961U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 15421910378057951895U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10038095909727959633U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17756404450592957616U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14255952184627347295U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3379089265413427719U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11341713098678108441U;
            aOrbiterJ = RotL64((aOrbiterJ * 2500587373161411961U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4030296130743454165U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6332387792111212064U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16490982218150897861U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 38U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + aNonceWordI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterK, 60U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + aNonceWordM);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterF, 12U)) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11148U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 10976U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12177U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((aIndex + 13467U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16018U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14370U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9390U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCarry, 13U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (aWandererG + RotL64(aIngress, 58U)) + 14823268998003220191U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 15295237288788213847U) + aNonceWordE;
            aOrbiterJ = (aWandererD + RotL64(aCross, 19U)) + 16434853402001133899U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 7555911304407871631U) + aNonceWordC;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 27U)) + 14977248264994834620U) + aNonceWordK;
            aOrbiterA = (aWandererF + RotL64(aIngress, 23U)) + 9707764144919392380U;
            aOrbiterK = ((((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 1277304385464681529U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aWandererA + RotL64(aScatter, 10U)) + 3089786220465849395U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 3U)) + 3700503853358695085U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3240054112993517371U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16897532076915366859U;
            aOrbiterJ = RotL64((aOrbiterJ * 4120874717534309035U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 18167359289798364307U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8870819278575769863U;
            aOrbiterE = RotL64((aOrbiterE * 9334066154398059075U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15363069206212330251U) + aNonceWordO;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 14858164441499725158U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 14931933411393847915U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5357144808788707522U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2910681277417754860U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13170868582159347059U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9824408699018165151U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 368370224788793300U;
            aOrbiterI = RotL64((aOrbiterI * 14358982366258729959U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7095398304588825115U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11418879758164313554U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 5983520332639771791U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2171599720681913272U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17593730219647495033U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12926053208918563087U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17755947635188715523U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14565740605227022106U;
            aOrbiterG = RotL64((aOrbiterG * 15866418354612945335U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14538017880915584414U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6174566474851449123U;
            aOrbiterD = RotL64((aOrbiterD * 179569008593475683U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 46U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterA, 30U)) + aNonceWordN);
            aWandererI = aWandererI + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordH) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterE, 57U));
            aWandererK = aWandererK + (((RotL64(aCross, 6U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + aNonceWordL);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aCross, 58U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 46U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19495U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 22249U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 18200U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17939U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17667U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16876U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17325U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 11U)) + (RotL64(aIngress, 58U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 29U)) + 13583136155674166402U;
            aOrbiterC = ((((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 12830472187484919497U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 34U)) + 18081197909484522509U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 23U)) + 8680634051297891550U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 13939998767458656823U;
            aOrbiterI = (aWandererI + RotL64(aCross, 19U)) + 1795730579103692594U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 11U)) + 17369751719734069999U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 51U)) + 224769585901248068U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 46U)) + RotL64(aCarry, 21U)) + 4133547085925268180U) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7022512056309567391U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10319484359046945495U;
            aOrbiterG = RotL64((aOrbiterG * 3400140531307001933U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10483878349412282069U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6481381149199985736U;
            aOrbiterC = RotL64((aOrbiterC * 9701719367082506253U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13721077228796934509U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9704818014314175007U;
            aOrbiterH = RotL64((aOrbiterH * 760445624027740287U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6253040047758584339U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16890211690273641226U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5622534399866057841U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6216227831265032436U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2023609047004658739U;
            aOrbiterB = RotL64((aOrbiterB * 3252332895698310147U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9201669637050388263U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5106927540934338576U;
            aOrbiterJ = RotL64((aOrbiterJ * 6368134569042291431U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10080368957861445998U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10784789383436485808U;
            aOrbiterF = RotL64((aOrbiterF * 3794918350254445939U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15426339824951793026U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17637144549368340331U;
            aOrbiterI = RotL64((aOrbiterI * 10971293914614704441U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9941300382181962134U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8118046374121322097U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 8481945819050983127U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 46U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 10U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aNonceWordP);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 37U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 12U) + aOrbiterD) + RotL64(aOrbiterG, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28479U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 24686U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 31843U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31143U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25126U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30797U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 29596U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 4U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = (aWandererG + RotL64(aPrevious, 41U)) + 12136097566601676613U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 29U)) + 7969431322248040056U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 10530676021510553889U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 8740777303075445264U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 27U)) + 13249434169895564739U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 34U)) + 15529577005925628472U) + aNonceWordK;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 47U)) + 344627093687331562U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 3U)) + 8824277416519988893U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 19U)) + 5636276438449709875U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2079413361031851552U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7807998179168655561U;
            aOrbiterD = RotL64((aOrbiterD * 961456853699784753U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13589392896232029112U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10733011474804473996U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 361749145931578805U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15934162328347805968U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7573511217796245232U;
            aOrbiterA = RotL64((aOrbiterA * 10694563909931636155U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 4828475187337891975U) + aNonceWordI;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 13284974329890393113U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 10831075817642374287U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 13173869918669643112U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15841507674783398167U;
            aOrbiterC = RotL64((aOrbiterC * 15632933198136963277U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 14168272451055700516U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11134471485501999898U;
            aOrbiterJ = RotL64((aOrbiterJ * 8019507184494591705U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2611858916687822610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17863271539727513641U;
            aOrbiterH = RotL64((aOrbiterH * 4987884722174985677U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8874401993454249066U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5131480593493950665U;
            aOrbiterK = RotL64((aOrbiterK * 8585874663602346121U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9366563022381918996U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7890729519928340296U;
            aOrbiterE = RotL64((aOrbiterE * 11428572374057899517U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 30U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + aNonceWordE);
            aWandererD = aWandererD + ((((RotL64(aIngress, 56U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 42U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + (((RotL64(aIngress, 10U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterH, 4U));
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 52U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF7543B10286CB5A9ULL + 0x92111E26413D5D00ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBCABEACB2D7CFAC1ULL + 0x806EDF76E336E62DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE692BC0C730BCD01ULL + 0x982CAD689C1A2F5BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCF7CB1248B070227ULL + 0x8A0E90A4C95826ADULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9011C4140CF555FBULL + 0xFA0A37043CF17D61ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE1104CE035363DF7ULL + 0xC757E801B3EEF33AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAA578A98848D4435ULL + 0xF980E0BB48C4ED49ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD2519619051E88FBULL + 0x871198DDDBD59BB2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA00DE970DEDE1AA1ULL + 0xB7B494CA23EEBA6DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF14F70F91278F51FULL + 0xA9F762B3627F8A5BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF3C27322CD0DCB41ULL + 0xE41237B039577890ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDE72EF48857B6F75ULL + 0x9520446422525B9CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDF81E57BD171D6FFULL + 0xBCA1C547538C242BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9BC079C939BD724BULL + 0xE1B9DF8876806DE8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE7FD326D47ECD003ULL + 0xD5998B6820EE8C9DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x864EF10D39B0E25DULL + 0xC7CA74A852D78BD5ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1250U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 5822U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7278U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 275U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 61U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6713U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 14U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 29U)) + 13204735390996728477U) + aNonceWordM;
            aOrbiterA = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 851171359595647173U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 16745304202825290723U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 10U)) + 562392736584913979U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 57U)) + 3244267012529053918U) + aNonceWordI;
            aOrbiterH = (aWandererB + RotL64(aIngress, 41U)) + 17282536111067869133U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 14851130066471729068U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5256130407952363129U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 2904742485828362001U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 12941135856735075457U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3723346325449225387U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5344621093694027341U;
            aOrbiterG = RotL64((aOrbiterG * 9044881458629673499U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12919263300833603026U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17989801264160996071U;
            aOrbiterD = RotL64((aOrbiterD * 15468293047311883751U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5022175042377172157U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16684822380107847758U;
            aOrbiterA = RotL64((aOrbiterA * 2834049270263837537U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2740326510600876682U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13981423865219318820U;
            aOrbiterH = RotL64((aOrbiterH * 14593082145080056441U), 51U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 231945878229848395U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14139797734944312580U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6492256080432266407U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16704102101387552373U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8506734780526852552U;
            aOrbiterF = RotL64((aOrbiterF * 4684566118627414659U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 56U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterK, 51U)) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterD, 12U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11769U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((aIndex + 10206U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 11780U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 13440U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13694U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9064U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12804U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 12U)) + 5573188770530340913U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 1431772230889897111U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 5U)) + 4809192776429682319U) + aNonceWordP;
            aOrbiterF = ((aWandererC + RotL64(aCross, 29U)) + 5576603692574369341U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 2720143226007220386U) + aNonceWordE;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 35U)) + 17220328778565331629U) + aNonceWordK;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 9629485808442089423U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1136998437010390983U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11893390497814523841U;
            aOrbiterK = RotL64((aOrbiterK * 5329621622743089531U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1764986431917532370U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1741014798007010376U;
            aOrbiterB = RotL64((aOrbiterB * 13414914086049500731U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12221368453236547044U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7694538641172350430U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8439120733670016501U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17472344518811560603U) + aNonceWordC;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 3308740700728172984U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 15290400462887712083U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9535358833412446771U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 11192312491731312451U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 17405609148475445743U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14850451970047190039U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11932493299452443256U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7964808728820467795U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5972619895614731870U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17174497535809891690U;
            aOrbiterC = RotL64((aOrbiterC * 15471084511364572533U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 28U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 23U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterH, 56U)) + aOrbiterI) + aNonceWordG);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 34U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23529U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 20581U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 18860U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 18277U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19368U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17290U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 17886U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererH + RotL64(aCross, 18U)) + 5480870806135400132U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 29U)) + 8034874599430768743U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 35U)) + 4006919843736863767U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 2988069748674633718U) + aNonceWordF;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 12347295651973135786U) + aNonceWordM;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 14152683894431568192U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 11U)) + 15765143815254196598U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10473067082331244233U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1089466925383677249U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 17334888609179149753U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13215039929873682230U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3957997712247961479U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7631186240013784703U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10023907397941685546U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14593012591254614353U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 17111300092082154687U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13353797968154036726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9259966668512102858U;
            aOrbiterJ = RotL64((aOrbiterJ * 8326732574268308221U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10757861831070349321U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10530223113483866178U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11269177745265396583U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7554320926405521865U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6978052067277966996U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 18020134738536217801U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1053695861967171420U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15980734683539854451U;
            aOrbiterD = RotL64((aOrbiterD * 3208466640010555357U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 46U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterG, 50U)) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 11U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29871U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 25159U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26748U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 27484U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26831U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25044U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 30292U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = ((aWandererF + RotL64(aScatter, 13U)) + 2617613537256538553U) + aNonceWordF;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 34U)) + 16642868916835132715U) + aNonceWordE;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 10860291124337073254U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 51U)) + 6432511273906902472U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 7505375005848241910U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 11086616004678821329U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 57U)) + 3298830587569881951U) + aNonceWordC;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 9775143140064220979U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4147601326580823120U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 13462244678782260871U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 12245920269898100415U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8391940489176734499U;
            aOrbiterK = RotL64((aOrbiterK * 9119606167674098007U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17876893379544668477U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18301882058180370541U;
            aOrbiterG = RotL64((aOrbiterG * 16680384667098921309U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6869225862715140102U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15404118372589259800U;
            aOrbiterF = RotL64((aOrbiterF * 5766851935950389915U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17757381020518233814U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17677969146092374455U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3469432916562405063U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15783378556632870114U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5792858258663697864U;
            aOrbiterH = RotL64((aOrbiterH * 12008981883482080427U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11737803388202260296U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16001927091970715330U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3062030309852922061U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 60U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterE, 37U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 60U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 43U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9BE7E0348B9C6F91ULL + 0xFB2CD16EFB06222AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8D23515E4CB357B5ULL + 0xD362775B13810B20ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE37E871C5345CDC7ULL + 0xE1D0C2DDFEDE2919ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9BB909C705DA96A5ULL + 0xE21B7E173F09481DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAEC63AC022C60BEBULL + 0x83ECBB6A45E3CA48ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC869AE3154EDCE45ULL + 0xC89F9A44ED453686ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF79C1CBD5CA94E09ULL + 0xC2E6E41336C8D097ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA028BC9911400603ULL + 0xFEE76F45F955D947ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x83D2A6F505AF67FDULL + 0xCC46D29F9079C0FBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB784C67B25E47027ULL + 0x8D6E29FDA7F3E490ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAB38FB6C2E69ED95ULL + 0x86834DB43D0822C7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE5FC6AFAFAE6CB8DULL + 0xC1F7D6185AFD62F4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE45ECDD7F67C404DULL + 0xFB7F450DB3B2092BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAB4ECE72B6787F59ULL + 0xA908074A9C1B2301ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDFE62B2152985EFDULL + 0x9BA3D4CE18478F5AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAA4CF14BD8678A5DULL + 0xCC5F0187A40E23E7ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2540U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 834U)) & W_KEY1], 38U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2581U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2283U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 27U)) + 13481227414590594621U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 17425964381118918026U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 4792004356135956581U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 11926849936000639098U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 39U)) + 990697329347742142U) + aNonceWordL;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 20U)) + RotL64(aCarry, 3U)) + 9307721505373076588U) + aNonceWordC;
            aOrbiterG = (aWandererK + RotL64(aScatter, 47U)) + 17605732738841908719U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13110764518634187439U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17970109897810645911U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10395095143998920213U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10273133817644703654U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11239046688920468137U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5197802934333553327U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8355821483275763145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15522151127786049345U;
            aOrbiterA = RotL64((aOrbiterA * 4844278537850520413U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5381663179722418112U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9551368011768104906U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 14202470972121732997U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16264476585232221270U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7721417776432288282U;
            aOrbiterF = RotL64((aOrbiterF * 10267770327791051869U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 339418090653475277U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3247926250495935511U;
            aOrbiterH = RotL64((aOrbiterH * 16824669543765729097U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3390560045236418590U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3894024951542543635U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10599637790900418767U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 11U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aCross, 30U) + RotL64(aOrbiterF, 58U)) + aOrbiterH) + aNonceWordJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 2886U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 4396U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5335U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3066U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 964165145848253292U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 48U)) + 10645976767204934746U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 5U)) + 8241612229349212650U) + aNonceWordK;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 29U)) + 4159196033256913347U) + aNonceWordB;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 21U)) + 7194795864620233507U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 7638928444536778384U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 11819105916503968109U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18052213302858186237U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8663575313970041570U;
            aOrbiterF = RotL64((aOrbiterF * 14131073322476609161U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16644136720439299786U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16930316530442679864U;
            aOrbiterH = RotL64((aOrbiterH * 2650922074098320859U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16251107616988250593U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7171986193609401665U;
            aOrbiterK = RotL64((aOrbiterK * 3543709971414550087U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17885046834432626644U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7757069274715713557U;
            aOrbiterC = RotL64((aOrbiterC * 15766885299397923879U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2212805322061155615U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 6368539134638838822U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 13383744883433594259U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5264326094252925613U) + aNonceWordC;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 6126345334815012938U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 17180934809764905307U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13826731214018407061U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6621261811613643620U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2823596473596114171U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterH, 5U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterA, 35U)) + aNonceWordJ);
            aWandererG = aWandererG + ((((RotL64(aScatter, 52U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7460U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 7660U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7414U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6504U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5786U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 42U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (((aWandererG + RotL64(aIngress, 30U)) + RotL64(aCarry, 53U)) + 18144572925667544139U) + aNonceWordN;
            aOrbiterE = ((((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 5659758077574059728U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 6343330616999166392U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 47U)) + 17754639838410839447U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 3U)) + 9451843819849581729U) + aPhaseEOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 23U)) + 7957854457197462212U;
            aOrbiterB = (aWandererH + RotL64(aCross, 11U)) + 1461994799722205010U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18002214276252170177U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14689869073147027164U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 12242482963989582191U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3978104368003440293U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8512135845221335386U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10506667163729414667U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1477533446382953439U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2166717790929947990U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6538884492418324461U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8082437060686606995U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4363687722464700362U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7199165810993478887U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15782763348014924206U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8572509150015960728U;
            aOrbiterF = RotL64((aOrbiterF * 3340528604891897779U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12248271773316742521U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9602078627638561949U;
            aOrbiterB = RotL64((aOrbiterB * 1860631869877427405U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17244849374768558859U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1030743048280579012U;
            aOrbiterE = RotL64((aOrbiterE * 10858949914285817051U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 44U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 29U)) + aNonceWordB) + aPhaseEWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 51U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8901U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 10877U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(mSource[((aIndex + 9310U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9723U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9928U)) & W_KEY1], 19U) ^ RotL64(aFireLaneB[((aIndex + 9360U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 43U)) + (RotL64(aIngress, 29U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (((aWandererC + RotL64(aScatter, 11U)) + 10805654776556844351U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 29U)) + 582794182442795335U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 2858343650974681068U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 53U)) + 8189584049022064284U;
            aOrbiterB = (aWandererK + RotL64(aCross, 21U)) + 1565100751996962893U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 51U)) + 8062028016947611891U) + aNonceWordI;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 8280504280578451745U) + aNonceWordO;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11326869194491655350U) + aNonceWordL;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 1671695656567777163U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 7511554500524257921U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2349843105293943452U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13015545152052004254U;
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16703354404749291869U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8713231044374305801U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 9242480982197688625U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11118401674497783533U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14857556493734710364U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 3452566050389715195U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12953419670951660965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12666121730825089017U;
            aOrbiterI = RotL64((aOrbiterI * 14049925256934142519U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11075249639473053423U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9374217688244187867U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5261156325627117877U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17608340953291367867U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13159437499327086340U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4882100944453534805U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterC, 6U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 43U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12442U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 13219U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 10978U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 12455U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13575U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12686U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12945U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 40U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = ((((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 5721224134332887360U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 6892749729775049095U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 3884839462099556836U) + aNonceWordH;
            aOrbiterK = (aWandererD + RotL64(aIngress, 19U)) + 4365431706830216193U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 35U)) + 15501528746571578773U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 4U)) + 4505911326320650606U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 51U)) + 1865129050927879580U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2011737665969640369U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 611672935827062688U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 12873671551304596619U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 663547038310431047U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5468932264754299556U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 11968657455484578525U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17920294117231191705U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 486058453837528110U;
            aOrbiterK = RotL64((aOrbiterK * 8851102552244026737U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2789178451938129313U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 420772587981211184U;
            aOrbiterH = RotL64((aOrbiterH * 17402987842294006667U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16196774774442181825U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16264169656793713547U;
            aOrbiterB = RotL64((aOrbiterB * 6900221986041638783U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10207659833859860796U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8593749091183323678U;
            aOrbiterF = RotL64((aOrbiterF * 10696776033512404927U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 7224922076047787384U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15366267474865172373U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10134187073321814217U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 38U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + aNonceWordG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterB, 51U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 50U) + aOrbiterH) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 15108U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14061U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16040U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16158U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14580U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13779U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14446U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 14U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 16160838483846078448U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 47U)) + 15404960896190227946U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 34U)) + 16904160594024977199U) + aNonceWordC;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 17790460246821031802U) + aNonceWordD;
            aOrbiterD = (aWandererI + RotL64(aCross, 41U)) + 16395168254086971959U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 23U)) + 7484373204039901786U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 18026814691322913510U) + aPhaseFOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 15244817793136966450U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5795491730356335666U;
            aOrbiterG = RotL64((aOrbiterG * 13253529465289332171U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 3163873518027801504U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 2690791759507349172U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 16677948635136515083U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17898067251167087906U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8028010015006604239U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 5601629670521300241U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7304739457289910555U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 6476837815096530043U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 16380545138701113267U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14242499233467960602U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17305645693017634630U;
            aOrbiterI = RotL64((aOrbiterI * 14442976693206929569U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9772864059444171908U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7897200728282156408U;
            aOrbiterJ = RotL64((aOrbiterJ * 816306719390807411U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4890999319172950996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8165132649356094963U;
            aOrbiterC = RotL64((aOrbiterC * 17297706071263690189U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterI, 58U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 43U)) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 27U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16793U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 16821U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(mSource[((aIndex + 16942U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneA[((aIndex + 17441U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18997U)) & W_KEY1], 43U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18948U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 16512U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 18U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (((aWandererD + RotL64(aCross, 21U)) + 9751314027302668907U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 4U)) + 12175450995523107056U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 57U)) + 17519694958730119552U) + aNonceWordJ;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 35U)) + 9093525527925682263U) + aNonceWordP;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 3713831321786810138U) + aPhaseGOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 10108355209191835040U) + aNonceWordE;
            aOrbiterB = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 12956307447311314768U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1904298513945877359U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4658049993308574460U;
            aOrbiterH = RotL64((aOrbiterH * 10482422152074338611U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9826333658248851902U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12058666914724365134U;
            aOrbiterJ = RotL64((aOrbiterJ * 964233873188373939U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2516574707110528099U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13335308331049750235U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5880227828760598587U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8230749255538495304U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16536559486797811486U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7097036838156464969U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12387639130570188998U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8459259798142872020U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8001346480955847013U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16083784052002800300U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1957284290736468379U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 5046501301740813065U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7349538179311335863U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16395170077006105258U;
            aOrbiterE = RotL64((aOrbiterE * 4230485452156662763U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterK, 54U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + aNonceWordO) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20454U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((aIndex + 21679U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19129U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20800U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19273U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21298U)) & W_KEY1], 48U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20832U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21390U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 12690502671561165478U) + aNonceWordE;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 57U)) + 17519943923428102801U) + aPhaseGOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 37U)) + 10705515807975331385U;
            aOrbiterC = ((((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 16586447272278538179U) + aPhaseGOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererI + RotL64(aCross, 21U)) + 8006560996840971798U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 28U)) + RotL64(aCarry, 19U)) + 12928600185788857701U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 13U)) + 14240723153798267172U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8636219177994872072U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7586790235186467512U;
            aOrbiterF = RotL64((aOrbiterF * 15052686382507614169U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1103807034179512424U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7547526530239498693U;
            aOrbiterI = RotL64((aOrbiterI * 3360295583636013509U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8380239679344786397U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5690809173787433519U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5354724308093372953U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8390902801141804609U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3507306189192059486U;
            aOrbiterB = RotL64((aOrbiterB * 18336280496510253103U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6190745292098482871U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8065418693975056902U;
            aOrbiterC = RotL64((aOrbiterC * 6414621418430102589U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12111755051718111803U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7605877769709909297U;
            aOrbiterE = RotL64((aOrbiterE * 17525248694315944599U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5969794501112646237U) + aNonceWordF;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 5127559299360591476U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 4521563633438853069U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + RotL64(aOrbiterC, 12U)) + aOrbiterE) + aNonceWordP) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterF, 27U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aIngress, 38U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 43U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23321U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 23701U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22811U)) & W_KEY1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21850U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23132U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24572U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24174U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneD[((aIndex + 22326U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 19U)) + 18180797995100240808U) + aNonceWordJ;
            aOrbiterH = (aWandererC + RotL64(aScatter, 44U)) + 6585906608223552885U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 53U)) + 14088708930575939855U) + aNonceWordM;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 35U)) + 468974153311516044U) + aNonceWordO;
            aOrbiterI = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 12481951025619894110U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 17227987923860711763U) + aPhaseGOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 4373962756657477139U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2077576476565420951U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17435011300234663764U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 8910133867294004711U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 4118039398293246896U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13724716599855216683U;
            aOrbiterB = RotL64((aOrbiterB * 17556333902751079677U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12391461204689596339U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9900605191533799627U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13553565332531046301U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 972946858824366125U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17247681919694541215U;
            aOrbiterD = RotL64((aOrbiterD * 2974639094630445643U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15442851427306771601U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7303586227288294037U;
            aOrbiterH = RotL64((aOrbiterH * 15406402525021428799U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12650358753454105119U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1483710933373510492U;
            aOrbiterI = RotL64((aOrbiterI * 6531763256577221891U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18065810162229740788U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11311677121338794007U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15116367961682119467U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterD, 21U)) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 28U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 37U)) + aNonceWordN) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26065U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 25212U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 24782U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26385U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25502U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27103U)) & S_BLOCK1], 38U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26865U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26854U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (aWandererA + RotL64(aPrevious, 57U)) + 3917730204724097072U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 1874642340716212824U) + aNonceWordG;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 51U)) + 6900165757434854160U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 12750946097023807161U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 21U)) + 6563216048479513594U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 12U)) + RotL64(aCarry, 39U)) + 14960240191349450795U) + aNonceWordI;
            aOrbiterH = ((aWandererF + RotL64(aCross, 5U)) + 16306180275951788289U) + aNonceWordM;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6502066618271045547U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6219852857850888738U;
            aOrbiterJ = RotL64((aOrbiterJ * 10892297250334325283U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 2272931312452845850U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3028929882263199463U;
            aOrbiterA = RotL64((aOrbiterA * 11005324285856805069U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6067393030073568112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10094809900437037258U;
            aOrbiterB = RotL64((aOrbiterB * 18095564940730322769U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 5962414178157074575U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15755563045799129417U;
            aOrbiterD = RotL64((aOrbiterD * 3692603590609922031U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6321455513889880590U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1197435601998121700U;
            aOrbiterC = RotL64((aOrbiterC * 17693996266260557625U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12496949381666299968U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6357070235648527030U;
            aOrbiterI = RotL64((aOrbiterI * 2931486644220862433U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8423760160877540210U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8090246492554850768U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2949407491181921633U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 51U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 11U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterD, 37U)) + aPhaseHWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterC, 22U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29224U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((aIndex + 28278U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29855U)) & W_KEY1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 28098U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29579U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27400U)) & S_BLOCK1], 60U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29952U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28230U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererC + RotL64(aIngress, 21U)) + 11700815697312060726U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 11U)) + 11808423452327465441U) + aNonceWordE;
            aOrbiterG = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 8670503858631730886U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 41U)) + 2400061067991988544U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 5U)) + 16163118178366229686U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 3280178595904941068U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 48U)) + RotL64(aCarry, 51U)) + 3298683600817047727U) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16321624053445183574U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6730229877611375225U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 2022290495153519279U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 10162830636713641322U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15646771327759599256U;
            aOrbiterC = RotL64((aOrbiterC * 15333053762177144775U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14841751262270544102U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9545541117228834895U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11529769874752969377U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14676615635857599982U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1231768638470558855U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 2716808508509014677U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1945905595345404833U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1406171421638586846U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 4577864352425476233U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1970292335806697198U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12309719390375013297U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16540660957923687327U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5352135521358954576U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15465675376193501658U;
            aOrbiterD = RotL64((aOrbiterD * 16385761112921041387U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordI) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterC, 58U));
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 37U)) + aOrbiterG) + aNonceWordH);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + aNonceWordP) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32707U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadA[((aIndex + 30850U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30860U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30940U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30940U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30083U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 51U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (((aWandererG + RotL64(aScatter, 53U)) + 11998579547770778580U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 8409465187298704610U) + aNonceWordM;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 38U)) + 3470222286110333500U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 5704486785203069994U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 27U)) + 10334944660253279633U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 7626852700722567477U) + aNonceWordI;
            aOrbiterB = (aWandererK + RotL64(aIngress, 3U)) + 14631310754943209743U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 807160297237854120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5624154783624196107U;
            aOrbiterJ = RotL64((aOrbiterJ * 2404066593958052159U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4971444394698940423U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6340057638461027062U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12027586111086798629U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9003019862787819481U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13632057463595873033U;
            aOrbiterI = RotL64((aOrbiterI * 12575202147280216765U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12766104026871797746U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4062118445824915939U;
            aOrbiterG = RotL64((aOrbiterG * 13130770039048080701U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5258212525426469978U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 9956946981015983939U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 8106382657040497669U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10837606223056473999U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13292864885504191134U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 4445739587553669471U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 166087925900318658U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6786842221885441388U;
            aOrbiterB = RotL64((aOrbiterB * 4411147600413147773U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 19U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterG) + aNonceWordF) + aPhaseHWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aIngress, 4U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 13U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 54U)) + aOrbiterE) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x959B34070249B851ULL + 0xD6FD8928855ACE6DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC6FB189C45B1070DULL + 0xBFA992359325A31BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA62D435299417627ULL + 0xA691DECE023350CFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC0D43DC67F09FED3ULL + 0x8E6DD676E39148BBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x947CD07911ADD1DDULL + 0xA859CB429BF7417EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC8A3879CEE25B2FBULL + 0x9DDD5CB413F8290EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC31D7A417BA40C3DULL + 0xC3AD6E1819672848ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC6DA237B4A0C8BA5ULL + 0xB054D2A9AE9D8278ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF2301B3571542FBDULL + 0x9930AEE5FD019710ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEC0D11E8F3B2E897ULL + 0x91325A76328261DCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD584CFC874C5BAADULL + 0xF316E1BD6218A6C8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE9EC10B81F88101FULL + 0xEC7CD8DC1D678C98ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA257D596EA6E7955ULL + 0xA8F2D49214282626ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD96F2C8A7AB42A1DULL + 0xE6E8A100E11808B4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF0B48CEB04C35259ULL + 0xA233C1F39901BB18ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFE1FE6E02FBA4F13ULL + 0xAE8949AA66DD350CULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 724U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 2062U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4147U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3442U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3632U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1774U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 22U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (((aWandererK + RotL64(aIngress, 4U)) + RotL64(aCarry, 19U)) + 17470880031634374199U) + aNonceWordH;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 757565846006937746U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 43U)) + 9419282475801345674U) + aPhaseAOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 2014248014107898196U) + aNonceWordG;
            aOrbiterB = (((aWandererE + RotL64(aCross, 19U)) + 15113928519446490441U) + aPhaseAOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7346126964886259935U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5594123113093162359U;
            aOrbiterG = RotL64((aOrbiterG * 18043634828891483403U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 5659237263369402005U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11565709683423969703U;
            aOrbiterB = RotL64((aOrbiterB * 16731289017588574671U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 16782863743534856287U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13499100900072115907U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5567729598873214433U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11414447651044205242U) + aNonceWordA;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 7545993795121430538U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 10758488381206257261U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11778229237616454988U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2544793391976514665U;
            aOrbiterC = RotL64((aOrbiterC * 4021060413798523299U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 60U)) + aOrbiterG) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + aNonceWordM) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 29U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 12U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10104U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 5462U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 5913U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7136U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6750U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9399U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10352U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 20U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 3973833383430652211U) + aNonceWordL;
            aOrbiterK = (((aWandererH + RotL64(aCross, 58U)) + 5760227042747169187U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 4923009065139227286U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 1477807307009107590U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 13U)) + 5707194514329007301U) + aNonceWordO;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5340439728375269724U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17080457898946572387U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17719588880215414933U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 281559150259472813U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16160633048230910560U;
            aOrbiterF = RotL64((aOrbiterF * 16883442583309073785U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9003989610509592121U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 10579322462808454333U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 100832431598087235U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15059383289528723069U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10417647757852880956U;
            aOrbiterE = RotL64((aOrbiterE * 1457919230286043137U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 14484665027393813330U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12344463053485837974U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5762654194001525041U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordB) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterK, 30U)) + aNonceWordE);
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            aWandererA = aWandererA + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14905U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 14483U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12347U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13689U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12862U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 4U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 16200278595895089008U) + aNonceWordO;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 1029614154810465897U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aCross, 19U)) + 7129562468705441295U) + aPhaseAOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 14388903902433951274U) + aNonceWordL;
            aOrbiterG = ((aWandererH + RotL64(aCross, 60U)) + 1013568949315967455U) + aNonceWordC;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3128823373497815651U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14525694606889470589U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12053226114431679195U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14443983602196782887U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12244220415328641190U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 15052949098014803181U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10477159225338766614U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2842870123078131566U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 11522265477555954071U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8621138818955849917U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5038396344400303181U;
            aOrbiterJ = RotL64((aOrbiterJ * 14636756322207385447U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2768613802894372496U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2027754864051410015U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 2461322540050569287U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterE, 48U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + aNonceWordG) + aPhaseAWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16638U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((aIndex + 20927U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 19008U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20900U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17278U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 42U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 26U)) + RotL64(aCarry, 57U)) + 13350544654542863236U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 12364346790125404372U) + aNonceWordC;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 9738750172849512764U) + aPhaseAOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aCross, 5U)) + 3781373837635491421U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 13U)) + 16635020317512702337U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5383653921676231276U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 10181959815492056493U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 14784636206508715141U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10005510924273927017U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9524687662265740565U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13687380438646756931U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4259138552009771014U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8973051213213726023U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12625091476068190979U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17602611840127337490U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8218984546932905269U;
            aOrbiterC = RotL64((aOrbiterC * 17504305273683304231U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 18102186122213487888U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2629927500298092976U;
            aOrbiterI = RotL64((aOrbiterI * 6983280164448292723U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 44U)) + aOrbiterI) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aCross, 14U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + aNonceWordI) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22036U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneB[((aIndex + 23818U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25386U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26482U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25512U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 41U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((((aWandererF + RotL64(aIngress, 54U)) + RotL64(aCarry, 19U)) + 12669015908335980355U) + aPhaseAOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 5438715179868613192U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 13U)) + 13172104448184536460U) + aNonceWordD;
            aOrbiterJ = (aWandererA + RotL64(aCross, 21U)) + 13421421503244744803U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 13327113302994856582U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 4671768205922454413U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 5355759962838579929U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 15080379163499722187U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6691720614265406851U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7063906424700911378U;
            aOrbiterF = RotL64((aOrbiterF * 17091734375516280675U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17328616394166672263U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1542940602574207068U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8981679306319627975U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7203866278803132454U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 993485696233139264U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11609009908810366447U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 15659679028507488331U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 18321361454094675842U;
            aOrbiterI = RotL64((aOrbiterI * 3966860765622641843U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 12U)) + RotL64(aCarry, 13U)) + aNonceWordG) + aPhaseAWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + aNonceWordF);
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aNonceWordK) + aPhaseAWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 52U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 27U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27360U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 29517U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 30990U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28167U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32309U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 27U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererF + RotL64(aIngress, 52U)) + 4622023259121087483U) + aNonceWordN;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 10253505250223501352U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 17133877904420462669U) + aNonceWordI;
            aOrbiterB = (((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 6162827793741796700U) + aNonceWordF;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 23U)) + 9610986424765907615U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11210747154264753754U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 16554205219580654546U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12754735039924859911U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10352576357413766388U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3651845783283479752U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1011289824180799641U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 18145542190463500476U) + aNonceWordD;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 5415609566767162857U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 6474184559323816389U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2033734872464201570U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3507213117125813345U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 5453058336688881113U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8716253393049851856U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 695984869565941856U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8377921610764044735U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 38U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + aNonceWordE) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCC6E77B504FCD123ULL + 0xE6788F897434CAFCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCDB314F0A482BFA9ULL + 0xF942FA55F8759BD1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAFE26A95D2F9F829ULL + 0xF6E5F758F628B82CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF029361A164B76B9ULL + 0xADC8C8359CA61115ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA8ECCDA63EADD985ULL + 0xCFA37546844D6D7CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8248CE329074FAD1ULL + 0xDC4C236539152080ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEC2060B018396811ULL + 0xF29A2433613EA7A6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8C28988C856175F7ULL + 0xF8D4FB4033E0B999ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x92005A91F2E3CB9DULL + 0x9C212DF191DD58AAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9D6DB7699E1CF0EBULL + 0xEBDB10C03F86145BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAE64444F6860E90BULL + 0x8D95017AA0C248D8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x937F5448977236A9ULL + 0xFEFF21CAB62C4BBBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8C7E0F34E3CB886BULL + 0x99BC6B252803B1CCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB67B6D317B1368B9ULL + 0x9473054B7526ACA4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9A06C1174C2F126BULL + 0xF35A70B675B3FCC1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC3D4551CE16E9F31ULL + 0xB4164D12640B462EULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7815U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 606U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4069U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8095U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 571U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 34U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 4U)) ^ (RotL64(aIngress, 47U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (aWandererH + RotL64(aIngress, 34U)) + 5906639480605353429U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 23U)) + 5293518570213287605U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 27U)) + 15383185501428521377U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 5U)) + 15364072512743978902U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aWandererA + RotL64(aScatter, 51U)) + 4525473357144014271U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 19U)) + 10400911938125603074U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 16417506293824627550U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 56U)) + RotL64(aCarry, 41U)) + 2419329331753341815U) + aNonceWordI;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 14929222427923332069U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16771573504983922586U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1863466450051787622U;
            aOrbiterJ = RotL64((aOrbiterJ * 2585626547126027053U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12895350137096692415U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3700979086526298327U;
            aOrbiterE = RotL64((aOrbiterE * 10279730254867618193U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1977099106211282426U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6144698304096915742U;
            aOrbiterC = RotL64((aOrbiterC * 5039822990560519609U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3858895556659724975U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1283646340363435327U;
            aOrbiterF = RotL64((aOrbiterF * 11622421841377018069U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6240532051889108891U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 757364889381634634U;
            aOrbiterH = RotL64((aOrbiterH * 943852137901972945U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5272945693977418174U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6850528198786172283U;
            aOrbiterD = RotL64((aOrbiterD * 1966383079897679953U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14431587733859573714U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16124590257870999553U;
            aOrbiterK = RotL64((aOrbiterK * 7755796211433191143U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 14912695018110241411U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11098623474413346520U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15167688959990872051U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3484847683376368686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2295388097292719800U;
            aOrbiterI = RotL64((aOrbiterI * 1240808318176106909U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 26U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 42U) + RotL64(aOrbiterA, 19U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 48U)) + aOrbiterF) + aNonceWordD) + aPhaseBWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 23U)) + aOrbiterH) + aNonceWordG);
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterI, 3U)) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 28U)) + aOrbiterE) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8344U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 14702U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9044U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((aIndex + 15217U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15514U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9941U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 13636U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 54U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 13880995121909552664U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 42U)) + 14534942818069300546U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 17745973100886007133U) + aPhaseBOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 2249805580771946872U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 47U)) + 4460116116396439410U) + aNonceWordA;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 23U)) + 3378683994078106878U) + aNonceWordO;
            aOrbiterF = (aWandererA + RotL64(aCross, 60U)) + 3992996501048809123U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 5U)) + 12057768808864451929U) + aPhaseBOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 51U)) + 4115362079047921130U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15297384955502206698U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17623548383481905636U;
            aOrbiterE = RotL64((aOrbiterE * 7487278217901483685U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3559213898000162417U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12311605719074507335U;
            aOrbiterI = RotL64((aOrbiterI * 3982199462062847697U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14807313864347885885U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11222085523291581822U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12580941911587215653U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 916681229436292462U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2441350114032314686U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 7336079498999018067U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7361470539894653271U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12153585147213579808U;
            aOrbiterA = RotL64((aOrbiterA * 3040327545467672961U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13566300726101613579U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14875254144748509128U;
            aOrbiterG = RotL64((aOrbiterG * 13699179902908972403U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9268158535644002904U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14144295981814993491U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 12739937231684038161U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 13861225650900541642U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12620513474052058164U;
            aOrbiterB = RotL64((aOrbiterB * 18141974182442267181U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14163773386433257965U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5725700029399455855U;
            aOrbiterH = RotL64((aOrbiterH * 10446930901088908809U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterA) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterI, 4U)) + aOrbiterC) + aPhaseBWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aCross, 34U) + aOrbiterE) + RotL64(aOrbiterI, 58U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24415U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 18555U)) & S_BLOCK1], 22U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21873U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18007U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20413U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21625U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23103U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 28U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 43U)) + 9080426856729228705U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 48U)) + 7851218321653539276U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 7023344692919298036U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 9772846154227440734U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 3U)) + 12008298632429608431U) + aPhaseBOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 12U)) + RotL64(aCarry, 23U)) + 12201090455849562875U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 53U)) + 9498721803411445471U) + aPhaseBOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererB + RotL64(aCross, 23U)) + 351203764023093632U) + aNonceWordJ;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 29U)) + 4966360430644539250U) + aNonceWordB;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9194167899071345693U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4922477697284269116U;
            aOrbiterI = RotL64((aOrbiterI * 8444814161720407881U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15742625291642356429U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7528703106518431730U;
            aOrbiterJ = RotL64((aOrbiterJ * 11530049278751507567U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 15279053574704935317U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2425839793660355555U;
            aOrbiterH = RotL64((aOrbiterH * 11486964816849830667U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13209849392400008898U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9041500097716231309U;
            aOrbiterA = RotL64((aOrbiterA * 340661035700748739U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 7885423750878814599U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1992993999902904603U;
            aOrbiterC = RotL64((aOrbiterC * 1478629826632201617U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6120758615019314102U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8529621625846992066U;
            aOrbiterD = RotL64((aOrbiterD * 8485991471612862467U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9125182130757385320U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15691232622970220043U;
            aOrbiterE = RotL64((aOrbiterE * 16517916951054758147U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11413090085435424697U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11563151001080914939U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16828196274450408201U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1778975369262558069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3232132443557192010U;
            aOrbiterB = RotL64((aOrbiterB * 17132823737792200981U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 30U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterH, 24U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + aNonceWordN) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 57U)) + aNonceWordD) + aPhaseBWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 19U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 4U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32507U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 25290U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27477U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 27231U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28358U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30069U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28703U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 6U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 19U)) + 3255291173184001106U) + aNonceWordJ;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 51U)) + 15308468160116255528U) + aPhaseBOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 10U)) + 18186972408589866656U) + aNonceWordM;
            aOrbiterK = (aWandererE + RotL64(aIngress, 41U)) + 4439324265978331914U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 23U)) + 13099263173016322486U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 7041561081767500660U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 6196422612687812971U;
            aOrbiterB = (aWandererD + RotL64(aCross, 29U)) + 7664260932541281413U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 58U)) + RotL64(aCarry, 29U)) + 17802347823020441056U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4253107484061190446U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13799496534030645312U;
            aOrbiterG = RotL64((aOrbiterG * 9167675060053848207U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14252892847595951926U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5663527578664291422U;
            aOrbiterI = RotL64((aOrbiterI * 18314294235895182465U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11148755959699137661U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17036900929333594592U;
            aOrbiterH = RotL64((aOrbiterH * 16041243617369003291U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2403828181385259549U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17813580350434928194U;
            aOrbiterB = RotL64((aOrbiterB * 13666780980793857831U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5623611126885414523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7293224381174846969U;
            aOrbiterA = RotL64((aOrbiterA * 7032561584670788117U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10602620906929686163U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 18015916257203385982U;
            aOrbiterK = RotL64((aOrbiterK * 10684090189688871993U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13592915735376305773U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13995866908043417505U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3802175869395887331U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8200465989447697618U) + aNonceWordP;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 9866671660800629464U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 2138851839905326265U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11557528777230608777U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 131060617338185060U;
            aOrbiterJ = RotL64((aOrbiterJ * 11068705423012265209U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 14U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterG, 60U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 42U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + aNonceWordN) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 46U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + aNonceWordG) + aPhaseBWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF8C950CCA0E118A3ULL + 0xB083D91CCE17BDF5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA3B473CF0994EE0BULL + 0x85D11C82C5418D2AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFF0018CF552C66E9ULL + 0xFA41B324A6DBB110ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA4D13564A9329C49ULL + 0xE7DA16BEFACECD9FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF3FF3C9BAC33832DULL + 0x9D07D6844DB61769ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB94B6E89E68A8981ULL + 0x9CA3BEB777EF28DBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA632CFFE7FC3F1CBULL + 0xC1EEB4C83B7FC757ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF53BC833B9C90DDBULL + 0xA17D086CC2A49252ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x90926EFC85AB8D03ULL + 0xCA26D0BC173B281DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x86E880BFE09EEC6FULL + 0x9F6A8BAFB2469654ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD2E63B89B6ABD60BULL + 0x8546558C2AED48EBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC8DB7BD2F9C49C6BULL + 0xF79F52D870AEED80ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEF6846592B34F75BULL + 0xD77EC4210F13A7BCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE275F40AB3792577ULL + 0xECCE383BFC75B1B6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF0630BA9A3804701ULL + 0xFC0F605B751CA7A4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA4565E265A4946BDULL + 0xFD61C60B10DAB23BULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4583U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 4682U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4347U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1940U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3570U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1389U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 50U)) + 6973892330986118220U) + aNonceWordE;
            aOrbiterG = ((aWandererI + RotL64(aCross, 19U)) + 9886813896272094864U) + aNonceWordH;
            aOrbiterA = (aWandererB + RotL64(aScatter, 13U)) + 10996306582517553173U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 8490648283899856223U) + aNonceWordO;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 105141713530704655U) + aPhaseDOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 3114337422810562588U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 27U)) + 980857684690886131U) + aNonceWordC;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 6562042345807072665U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15665371138706353619U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 8086237578564620623U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 18113013571374375028U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17405346422601997299U;
            aOrbiterE = RotL64((aOrbiterE * 11162604605443005253U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5130876096426182506U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1813821672299154629U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15478100342425611875U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15793814882743306728U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13925299440495476399U;
            aOrbiterH = RotL64((aOrbiterH * 12049601510660117401U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9924458846049579438U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7810034662781768090U;
            aOrbiterJ = RotL64((aOrbiterJ * 10310594595026622513U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12812586478656872854U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5709576448057435237U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 9101555233909853025U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7839807649914541516U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4717944526755429647U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8515229146471335721U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 60U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterE, 57U)) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 48U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5983U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 7529U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8558U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneC[((aIndex + 6577U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8594U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10268U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8975U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 17668251151213543491U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 5U)) + 16101602509895104517U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererI + RotL64(aIngress, 19U)) + 9083915270773304935U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 13U)) + 12810720730318214811U) + aNonceWordL;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 18113428002071925621U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 50U)) + RotL64(aCarry, 39U)) + 1582208899354109878U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 41U)) + 4180688104819188154U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8954598189262820611U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15360094153175355879U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8177798855402983685U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8383954114668216260U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15626783326234049197U;
            aOrbiterA = RotL64((aOrbiterA * 15058420415480073793U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10609978564404958066U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17656516608997517984U;
            aOrbiterK = RotL64((aOrbiterK * 4590620354119899777U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 760077259110786536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3597338735888033063U;
            aOrbiterE = RotL64((aOrbiterE * 6548831472863517621U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4431777844935985157U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10710423172154671296U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16267496318491473315U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10240882795242085185U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7826053487019825891U;
            aOrbiterB = RotL64((aOrbiterB * 15053729937684375907U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9418883403715727353U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11507423614799075545U;
            aOrbiterJ = RotL64((aOrbiterJ * 16189463984557044693U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 37U)) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterK, 51U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterB, 30U)) + aNonceWordG) + aPhaseDWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 4U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11419U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 12058U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12873U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11201U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 13315U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = ((((aWandererF + RotL64(aScatter, 28U)) + RotL64(aCarry, 37U)) + 4739486756133131180U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 16089707555501328184U) + aPhaseDOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 15310047330238536453U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 21U)) + 7901411596386834955U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 35U)) + 4357555491060982163U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 3U)) + 15667085602825720102U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 41U)) + 8520635334382269253U) + aNonceWordI;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1772509779231068315U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15336170957886025677U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 10996880551392077399U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8628770833489469980U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15469234024247246228U;
            aOrbiterG = RotL64((aOrbiterG * 8905266995119987947U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10796430900884288328U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10660110397012853289U;
            aOrbiterF = RotL64((aOrbiterF * 9140007610912037461U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11202284258711214794U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17509491802893182994U;
            aOrbiterH = RotL64((aOrbiterH * 9329107599972703671U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16212572740740103554U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2190030203761579226U;
            aOrbiterE = RotL64((aOrbiterE * 3101886685668871045U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 12014337082293041909U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3733531010807001506U;
            aOrbiterC = RotL64((aOrbiterC * 5797362244066062299U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7100994963061975529U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17837541162838600258U;
            aOrbiterD = RotL64((aOrbiterD * 8745987361678166553U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 36U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 3U)) + aNonceWordG) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 60U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 29U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18274U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 20223U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21787U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17806U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20006U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 34U)) + 9751314027302668907U) + aPhaseDOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 51U)) + 12175450995523107056U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 17519694958730119552U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 27U)) + 9093525527925682263U) + aNonceWordI;
            aOrbiterI = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 3713831321786810138U) + aNonceWordJ;
            aOrbiterC = ((((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 10108355209191835040U) + aPhaseDOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 41U)) + 12956307447311314768U) + aNonceWordC;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1904298513945877359U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4658049993308574460U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10482422152074338611U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9826333658248851902U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 12058666914724365134U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 964233873188373939U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2516574707110528099U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13335308331049750235U;
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8230749255538495304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16536559486797811486U;
            aOrbiterF = RotL64((aOrbiterF * 7097036838156464969U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12387639130570188998U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8459259798142872020U;
            aOrbiterI = RotL64((aOrbiterI * 8001346480955847013U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16083784052002800300U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1957284290736468379U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 5046501301740813065U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7349538179311335863U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16395170077006105258U;
            aOrbiterC = RotL64((aOrbiterC * 4230485452156662763U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 41U)) + aNonceWordE) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterG, 57U));
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterI, 42U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22524U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 23822U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24306U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23296U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 24582U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 30U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 3684295017013759987U) + aNonceWordN;
            aOrbiterA = ((aWandererA + RotL64(aCross, 4U)) + 6740408842457292881U) + aNonceWordF;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 4563975890702399441U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 43U)) + 797804144825287940U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 29U)) + 2763779540450101303U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 13211846164102089685U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 13U)) + 15214578447281401982U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13745208628754232427U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17358621225969190747U;
            aOrbiterH = RotL64((aOrbiterH * 5325024317338823061U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 779739369960480023U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4370963533701407813U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3123135216876641039U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6061333005507739975U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3589705340762734456U;
            aOrbiterJ = RotL64((aOrbiterJ * 16499293983611196967U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10607697666369230567U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9356757995305239271U;
            aOrbiterB = RotL64((aOrbiterB * 10945513661439954731U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10093033335903048138U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11037328061699834100U;
            aOrbiterF = RotL64((aOrbiterF * 11189760551792389605U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 558431161176115540U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17795680919453449358U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3910117359996283803U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6096779391116214109U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17594243286880690775U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 12655610181937429915U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 47U)) + aOrbiterF) + aNonceWordK) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 53U)) + aOrbiterB) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterH, 6U));
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 28967U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneA[((aIndex + 27341U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 31570U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28360U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 29977U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 48U)) + RotL64(aCarry, 57U)) + 13481227414590594621U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 35U)) + 17425964381118918026U) + aNonceWordE;
            aOrbiterH = ((aWandererB + RotL64(aCross, 11U)) + 4792004356135956581U) + aNonceWordG;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 11926849936000639098U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 3U)) + 990697329347742142U) + aPhaseDOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 9307721505373076588U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + 17605732738841908719U) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13110764518634187439U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17970109897810645911U;
            aOrbiterH = RotL64((aOrbiterH * 10395095143998920213U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10273133817644703654U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11239046688920468137U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5197802934333553327U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8355821483275763145U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15522151127786049345U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 4844278537850520413U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5381663179722418112U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9551368011768104906U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 14202470972121732997U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16264476585232221270U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7721417776432288282U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10267770327791051869U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 339418090653475277U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3247926250495935511U;
            aOrbiterE = RotL64((aOrbiterE * 16824669543765729097U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3390560045236418590U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3894024951542543635U;
            aOrbiterG = RotL64((aOrbiterG * 10599637790900418767U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 42U)) + aOrbiterG) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 11U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + aPhaseDWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 14U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + aNonceWordB);
            aWandererB = aWandererB + (((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 37U)) + aNonceWordK) + aPhaseDWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB6FA3BDBF53B8EA5ULL + 0xA4DF841105E9D6ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9EF558CD918826D1ULL + 0x9704F445AEC23C5EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF83B9249C72D4F65ULL + 0xFCC5559E8BB8224DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC82B65375B11F55BULL + 0x956FA2692AE7E061ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD1592AD20F89FCF5ULL + 0xB27B674FC69D982AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAD23094ADB62EC1DULL + 0xF4CFD17C904D8EF2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF63472A196BD81ADULL + 0xE6F4F919A15FB8B0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF0B35014E9EF7A87ULL + 0xD456176A0B855E7FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE234C03009AA5A4BULL + 0xD5BC9C9CC6677A47ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8B5D4F76C1682BE5ULL + 0xDDB4B5140EA4001BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCD89E7AB987C7B09ULL + 0xB207DD500B2FCA61ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x969984324C87C9C5ULL + 0xF67081881896EDF2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE384462AA2BF96CFULL + 0xD5810CACD7CF218FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB5F5F9E57B396863ULL + 0xD3E77227F83D113CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x80C58751620F7083ULL + 0xB77DB3ABECFEFCB6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8F2861BC971F3A7DULL + 0xBF8DF8523A84E86BULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4053U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneB[((aIndex + 5248U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 687U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2811U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4488U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4299U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 5U)) + 12262991801139086177U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 41U)) + 7963038771924890197U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 54U)) + 15540520327933568896U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 37U)) + 8745565892055020722U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 27U)) + 16619329199683755286U) + aNonceWordH;
            aOrbiterI = (aWandererA + RotL64(aScatter, 13U)) + 10865705026433867260U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 2743368697984518059U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 5556006271515473135U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 56U)) + 5355833281353498588U) + aNonceWordK;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 8313616108963479829U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 19U)) + 16657121016801866434U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16532226425013000833U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5800465874932467232U;
            aOrbiterC = RotL64((aOrbiterC * 5966395771690704577U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17882948163883121328U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15029375310296563175U;
            aOrbiterA = RotL64((aOrbiterA * 17021415832288477713U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10170682648007918739U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11829089574189398773U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15755874363488568849U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1746524867389196322U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10217423427886742775U;
            aOrbiterE = RotL64((aOrbiterE * 9166162099575333519U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1338457710729082656U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1319981417675542556U;
            aOrbiterF = RotL64((aOrbiterF * 9518448254565489715U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3985281993069194761U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7281264481139915593U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 13498446162967276739U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17394503335338855566U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1430703546991948227U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 1623206122475721175U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 472559435062214929U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8065899137826178995U;
            aOrbiterK = RotL64((aOrbiterK * 13287499768933229539U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3377996409668333322U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10456089146891981998U;
            aOrbiterD = RotL64((aOrbiterD * 12037044781049717633U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5246784368779537905U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 8518987022368391332U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 4046763804695058779U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7791883487780325967U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12262991801139086177U;
            aOrbiterJ = RotL64((aOrbiterJ * 3409890579914160747U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 41U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 43U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 10U) + aOrbiterA) + RotL64(aOrbiterF, 34U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterG, 11U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 39U)) + aOrbiterA) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 22U) + aOrbiterJ) + RotL64(aOrbiterB, 29U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 54U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6795U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneC[((aIndex + 5788U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7159U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6308U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9936U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8686U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10883U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 18U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (((aWandererE + RotL64(aScatter, 19U)) + 3561491146322798260U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 35U)) + 7075025056181885339U;
            aOrbiterA = (aWandererI + RotL64(aCross, 21U)) + 9230910887904171613U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 4119781172609908917U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 39U)) + 17155609083870983149U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 44U)) + 2423018561430181695U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 41U)) + 12957280305617615744U) + aNonceWordF;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 11U)) + 2461704174772065813U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 7907123257849391997U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 7257868138318960007U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 4U)) + 16425903703085702285U) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2990822664594079467U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5654819006718953817U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 4465096036756887801U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12183676471235678779U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15026286960542123922U;
            aOrbiterK = RotL64((aOrbiterK * 17199049329995315279U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12169080607071830522U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2906296852254787499U;
            aOrbiterE = RotL64((aOrbiterE * 6754514406846040163U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3029858695410344584U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14406410317495954566U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 9663780721657983421U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11048818178401163861U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13622063920319445043U;
            aOrbiterH = RotL64((aOrbiterH * 2516025554421589857U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2642646089141233277U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12761571777929273548U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5518252696078700127U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7753802695131502382U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8510425459525030222U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 12412361423636026483U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13522645164493316722U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1437430302489702713U;
            aOrbiterC = RotL64((aOrbiterC * 14019316635365783545U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14745189473423751499U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16968328257002103715U;
            aOrbiterD = RotL64((aOrbiterD * 17915588590593471981U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5001838243344386314U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13506188720092630563U;
            aOrbiterI = RotL64((aOrbiterI * 7010027510838271877U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16902624500530747723U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3561491146322798260U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 95761172090277669U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 48U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 48U)) + aOrbiterF) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 41U)) + aOrbiterK) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 37U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterK, 24U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + aNonceWordB) + aPhaseEWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13953U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((aIndex + 15319U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11933U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15174U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11903U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 48U) + RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 24U)) + 4752759164691497960U) + aPhaseEOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 43U)) + 12088872623537639782U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 5U)) + 3734943577379734227U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 29U)) + 8854778183012444234U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 14U)) + 16948373492893967275U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 7962415690046184385U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 1872682375669714454U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 7776801806943853566U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 21U)) + 16665439117257230732U) + aNonceWordG;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 53U)) + 11088186766134265676U) + aNonceWordB;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 11U)) + 10850237991780969350U) + aNonceWordD;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6464817712131305812U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 244557182884209844U;
            aOrbiterB = RotL64((aOrbiterB * 2394270354887582889U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13261563971157415841U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2323811103717827362U;
            aOrbiterC = RotL64((aOrbiterC * 11483723582415081925U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12338803568475493422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2811342930111104982U;
            aOrbiterK = RotL64((aOrbiterK * 5020981755203607757U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5554497011738996057U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12712169745460598698U;
            aOrbiterE = RotL64((aOrbiterE * 1985586486150377769U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17415058661427002973U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9430421222715343818U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10321140659099470811U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3926618548181233180U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6172453297026957838U;
            aOrbiterH = RotL64((aOrbiterH * 1161551082037835233U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8633288765997226004U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17270881130844274342U;
            aOrbiterJ = RotL64((aOrbiterJ * 8888559940161770791U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12232950994807835262U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15352600312956742750U;
            aOrbiterA = RotL64((aOrbiterA * 6140396356904933003U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5614120002595447983U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1920822446545182835U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 17049182594382482085U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 625576652179261739U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2362773059031414585U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17049048587829564949U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16749690978107177915U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4752759164691497960U;
            aOrbiterI = RotL64((aOrbiterI * 8442185754037031199U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 53U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 27U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + aNonceWordE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterE, 4U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 21U)) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 13U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aScatter, 20U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 50U)) + aOrbiterB) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18744U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 17654U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 16983U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17382U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19449U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCarry, 54U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 11U)) + 8685374557928800912U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 30U)) + 3482312691892161229U) + aNonceWordC;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 39U)) + 6948130297389161165U) + aNonceWordP;
            aOrbiterD = ((aWandererB + RotL64(aCross, 27U)) + 5506385663788942690U) + aNonceWordG;
            aOrbiterG = (aWandererK + RotL64(aScatter, 43U)) + 17859982009307397161U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 9178488809207094043U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 1835479501226057169U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 57U)) + 5368101733632614939U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 3U)) + 9050459666576835422U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 23U)) + 9042186993119635078U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 14U)) + RotL64(aCarry, 47U)) + 17528342580198295025U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6495418332558436882U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8834495762667327342U;
            aOrbiterB = RotL64((aOrbiterB * 10783141541937645995U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4364314196965690905U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6357485231062120459U;
            aOrbiterF = RotL64((aOrbiterF * 289429584586504995U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3321488322626415347U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10817330671781848737U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 15875919466358823335U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17974092279281611763U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2871472057292789157U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 16104199340711015181U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15187929795092006849U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13482063681546475923U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14466266308157364963U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6232152545071397380U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17488906002621373262U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4719340606442742577U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12444819880507588549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13808941689757772497U;
            aOrbiterD = RotL64((aOrbiterD * 6541360905282412317U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8049361354387692374U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7137831335606542401U;
            aOrbiterH = RotL64((aOrbiterH * 11022231291507235007U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7230759462019420058U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3923744511976096944U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 9953869624243563101U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15967667946023263856U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8677583624693910669U;
            aOrbiterG = RotL64((aOrbiterG * 10737731876339973717U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1604347321263511013U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8685374557928800912U;
            aOrbiterA = RotL64((aOrbiterA * 14103365695918844461U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 18U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 14U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ) + aNonceWordI) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterE, 23U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 26U) + RotL64(aOrbiterI, 10U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 36U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23136U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 25111U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 24616U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23167U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((aIndex + 23082U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 54U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 10915618884692072446U) + aNonceWordK;
            aOrbiterI = (aWandererD + RotL64(aScatter, 19U)) + 12634922308499254909U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 39U)) + 6533934734564499389U) + aNonceWordN;
            aOrbiterC = (aWandererC + RotL64(aCross, 46U)) + 6744203303756105181U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 27U)) + 13086782386652045658U) + aNonceWordA;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 5U)) + 5693840533331397822U) + aPhaseEOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 1803663542535024611U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 43U)) + 3597219300593287708U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 1429753448204448904U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 41U)) + 17229017825587322715U) + aNonceWordO;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 34U)) + 1137574712801062932U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2401991077004083378U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1332473247826139292U;
            aOrbiterA = RotL64((aOrbiterA * 15029831858261506447U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11730946340796899885U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15319163439700390962U;
            aOrbiterE = RotL64((aOrbiterE * 1349242001887975499U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4744141870145159917U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6067132201862688684U;
            aOrbiterB = RotL64((aOrbiterB * 6046100687757836027U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14991509179286371800U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4342608825699398682U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 10240526103933275875U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3727521409410742075U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3302027219498304367U;
            aOrbiterI = RotL64((aOrbiterI * 12153634588200479559U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6039539483340398858U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2902581519976937051U;
            aOrbiterD = RotL64((aOrbiterD * 2057584328877854239U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12332784713738947242U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13761272577223712786U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14930145045480030821U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2947946397617043735U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11107014023853644521U;
            aOrbiterJ = RotL64((aOrbiterJ * 15030903626191481831U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6212403196992771516U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16107261731677426470U;
            aOrbiterK = RotL64((aOrbiterK * 13764822942405295129U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8414111492161335472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3625937496991123221U;
            aOrbiterG = RotL64((aOrbiterG * 1736741235159600739U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5466667339391480293U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10915618884692072446U;
            aOrbiterF = RotL64((aOrbiterF * 14719282928172086707U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 40U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 6U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + aNonceWordI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 24U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 13U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29817U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 31656U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28121U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32131U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27698U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aIngress, 10U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 53U)) + 2786079456995203065U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 10U)) + 7237256119153857253U) + aNonceWordM;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 9310834010563647604U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 5U)) + 17361734905706517877U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 15837111231884647451U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 18065431964418026445U) + aNonceWordN;
            aOrbiterA = (aWandererF + RotL64(aIngress, 37U)) + 3029123922999952652U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 21U)) + 5166926595573507837U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 23U)) + 1918425684273807598U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 51U)) + 4724551751012661440U) + aPhaseEOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 34U)) + 1818014487579644390U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 6670090372241084216U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8485757110007268693U;
            aOrbiterH = RotL64((aOrbiterH * 11876760095108618363U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4928130251509514742U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2528788422725346792U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 1855982047967756661U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2860387120895147503U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12927802338151379368U;
            aOrbiterF = RotL64((aOrbiterF * 8876144125458603029U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18029699867733207083U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13361836994951253312U;
            aOrbiterE = RotL64((aOrbiterE * 5349767426256597073U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11957294454794128079U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3755417922063414648U;
            aOrbiterG = RotL64((aOrbiterG * 13896364063651241401U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18001157153447913032U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16214145724690286854U;
            aOrbiterD = RotL64((aOrbiterD * 5874139687703360515U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3860958772090975562U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12395621524459640173U;
            aOrbiterK = RotL64((aOrbiterK * 722817135977510161U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3402035664910754484U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2139099117325745602U;
            aOrbiterI = RotL64((aOrbiterI * 14008983756425796029U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7769274487425053026U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6492669707749367728U;
            aOrbiterC = RotL64((aOrbiterC * 5149771861620757839U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14963366447884375043U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11398874662567519691U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8221521452475029835U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7168445485232814860U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2786079456995203065U;
            aOrbiterA = RotL64((aOrbiterA * 14258367164534307955U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 10U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + aOrbiterJ) + RotL64(aOrbiterC, 58U));
            aWandererA = aWandererA + ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 14U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 56U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterE, 51U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9AC68D715A5979EDULL + 0xA3F7926F03F8276AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBB93A2C543EF1CE9ULL + 0xBFC7146C9EC1C68BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA11A563BCA5CDB37ULL + 0xBE338E795E62EA57ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB884F883E66032F3ULL + 0x93B4E55C4EEDC573ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDA10D741121BA4E1ULL + 0xFA2E6BC184659959ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEDE9745ED5F4A4F7ULL + 0x8F63C5F2447A48BCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x891F6D395501E947ULL + 0xB5B2CE32E03B1843ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9A906FFC282BF5D5ULL + 0x8435E42B50844EB2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBAA6A4BB79AB407BULL + 0xCBE1BC19CDA198E2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x909E59C63EB0C2FFULL + 0x957A1C611EBAE846ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEFFC6E5EBFF28249ULL + 0xAF3DFE3A97E7D60EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB00705F03F8DFE41ULL + 0xB8871212198D7229ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF84621EEF363C0EBULL + 0xD7B800D7EA4557EBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x895DD43E45CCA6DBULL + 0xDD59B6BF469BE6D7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x86AA7ADFC6EF0A7FULL + 0x9183FC61C88E3B8AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF78F6E9331F4DC2BULL + 0xC494910CAE769274ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5319U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 106U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3325U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4384U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2367U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2842U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 56U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 53U)) + 13442819395490639310U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 35U)) + 8187292523194120936U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 11469697159823131388U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 47U)) + 13414083692375929653U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 29U)) + 11404010733687907517U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 10U)) + 6783212827186218247U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 8561131439340372614U) + aNonceWordN;
            aOrbiterB = (aWandererC + RotL64(aCross, 43U)) + 6252609642004429113U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 19U)) + 12804867444200448952U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2739648749603690781U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14808861217017399752U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 373911885694012101U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17588866502571268888U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5882260142735642980U;
            aOrbiterE = RotL64((aOrbiterE * 7688252946143263869U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15493099088132862949U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5175647411532429582U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15226544495598541883U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14279707376173642767U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6826363572161275158U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5263708315440161809U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13267185753040999992U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9980987858092888720U;
            aOrbiterA = RotL64((aOrbiterA * 13210290848800728635U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3582972937645514549U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10140409019562890804U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6944490201647678479U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6160444117287330557U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16344602960561293113U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 2319964919335633293U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3497141036108337171U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 91269118352540308U;
            aOrbiterF = RotL64((aOrbiterF * 5160060720189045505U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12739932748793144857U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12820180915064791197U;
            aOrbiterK = RotL64((aOrbiterK * 5843849637411948699U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 3U)) + aNonceWordK) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 34U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 24U) + aOrbiterC) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterK, 12U)) + aNonceWordH) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9825U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 10550U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9617U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7289U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9776U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10347U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8913U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 52U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererC + RotL64(aScatter, 5U)) + 6973892330986118220U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 39U)) + 9886813896272094864U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 34U)) + 10996306582517553173U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 23U)) + 8490648283899856223U) + aNonceWordH;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 105141713530704655U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 43U)) + 3114337422810562588U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 58U)) + RotL64(aCarry, 11U)) + 980857684690886131U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 6562042345807072665U) + aNonceWordB;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 47U)) + 15665371138706353619U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 18113013571374375028U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17405346422601997299U;
            aOrbiterE = RotL64((aOrbiterE * 11162604605443005253U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5130876096426182506U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1813821672299154629U;
            aOrbiterK = RotL64((aOrbiterK * 15478100342425611875U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15793814882743306728U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13925299440495476399U;
            aOrbiterF = RotL64((aOrbiterF * 12049601510660117401U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9924458846049579438U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7810034662781768090U;
            aOrbiterB = RotL64((aOrbiterB * 10310594595026622513U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12812586478656872854U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5709576448057435237U;
            aOrbiterH = RotL64((aOrbiterH * 9101555233909853025U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7839807649914541516U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4717944526755429647U;
            aOrbiterA = RotL64((aOrbiterA * 8515229146471335721U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3933911971504256022U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4814079680865379831U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 15100740696230557391U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18352577312212175569U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9670612998448920742U;
            aOrbiterI = RotL64((aOrbiterI * 5743579439303300553U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 72737302703035726U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10032869372369626210U;
            aOrbiterD = RotL64((aOrbiterD * 7449905669249993731U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererK = aWandererK + (((RotL64(aScatter, 26U) + RotL64(aOrbiterI, 10U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + aNonceWordP) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 29U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 14U)) + aOrbiterH) + aNonceWordI);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 43U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14836U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 13300U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 11639U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11879U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15832U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (aWandererH + RotL64(aCross, 51U)) + 4179952823252098240U;
            aOrbiterF = ((((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 3745613452332101749U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aWandererB + RotL64(aIngress, 19U)) + 2955689793395307176U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 34U)) + 5639060180251322019U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 57U)) + 7901969163853586463U) + aNonceWordB;
            aOrbiterI = (aWandererA + RotL64(aCross, 23U)) + 2242166787816318119U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 47U)) + 5239936443960750064U) + aNonceWordK;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 14U)) + RotL64(aCarry, 39U)) + 13939136954732185558U) + aNonceWordG;
            aOrbiterK = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 17058884136712717463U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18148618660054585941U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7022023484530327814U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 650100011311048589U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7722084537340095637U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11764151879690934182U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 12264384877711365655U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16412785901758144708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9666718667728274824U;
            aOrbiterH = RotL64((aOrbiterH * 10865799822751771795U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4307127540152109364U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2457646804702647606U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6340030928007058595U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3179394870088602208U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 504977947273774249U;
            aOrbiterB = RotL64((aOrbiterB * 16190282058883481551U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16182729401018310837U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7110817020445860609U;
            aOrbiterC = RotL64((aOrbiterC * 13371352088428584087U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12960656706837391973U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7103806893724395904U;
            aOrbiterF = RotL64((aOrbiterF * 14365984439655979791U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1248300178080633527U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7195473175424961337U;
            aOrbiterI = RotL64((aOrbiterI * 4633558992739305045U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13007951568242991449U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10296811247653636372U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16469682651380549395U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 28U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 48U)) + aOrbiterI) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + aNonceWordA) + aPhaseFWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterF, 12U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 23U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20320U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((aIndex + 19586U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 19524U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21679U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17931U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 28U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 9471546960258473684U) + aNonceWordG;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 18050235435948942244U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 46U)) + 3005107102671544641U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 19U)) + 17898396434573801850U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 15071602525497771648U;
            aOrbiterI = (aWandererH + RotL64(aCross, 39U)) + 5780119462702672108U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 13U)) + 13301326224151025687U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 58U)) + 18129323022260575961U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 35U)) + 1199228670638790709U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1839199978088021020U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4999517042246790165U;
            aOrbiterE = RotL64((aOrbiterE * 4585813675677234577U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8788607633376516299U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15143903839930468749U;
            aOrbiterB = RotL64((aOrbiterB * 12735914889325422675U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16674732686428431869U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15908873150953195581U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 18049755517524334107U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11204775359756474667U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2525984309543939465U;
            aOrbiterF = RotL64((aOrbiterF * 3988529812023791571U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4566345170476825512U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14876612901557406267U;
            aOrbiterH = RotL64((aOrbiterH * 9047956948845135339U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 14926290877038883931U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12710203178186614846U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14841163494801662515U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7315094513967387996U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11050116830482816766U;
            aOrbiterA = RotL64((aOrbiterA * 3702999495721152019U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4505368486032503953U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17905748055257551092U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14775870175093453197U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5728886950801376350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17998141690182325170U;
            aOrbiterC = RotL64((aOrbiterC * 16008599930125391379U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 30U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterA, 39U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterF, 10U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 51U)) + aNonceWordF);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + RotL64(aOrbiterG, 58U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            aWandererG = aWandererG + (((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22768U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneB[((aIndex + 26558U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 26105U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27014U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24219U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (((aWandererA + RotL64(aIngress, 14U)) + 6318740973868639425U) + aPhaseFOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 27U)) + 5487840061430920881U) + aNonceWordM;
            aOrbiterC = (aWandererE + RotL64(aCross, 47U)) + 10258706763248072672U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 18356875269730338208U) + aNonceWordF;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 12883160282903147010U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 36U)) + RotL64(aCarry, 57U)) + 1010140474942697730U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 57U)) + 17733939421700898293U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 5U)) + 13693055887924981201U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 21U)) + 14574732452793385269U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10832873941223609012U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8212600587135328040U;
            aOrbiterC = RotL64((aOrbiterC * 5334613996794796145U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5312744319781971178U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6173741211706546923U;
            aOrbiterK = RotL64((aOrbiterK * 12854414066390848249U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3693249147883790810U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18365859989736602556U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 3348463719324104997U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10645056678337549771U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1175668356822251045U;
            aOrbiterI = RotL64((aOrbiterI * 6579675292775345579U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13556844570541823717U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4790355739411849736U;
            aOrbiterD = RotL64((aOrbiterD * 4083544011788850307U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14905575502272644116U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17047244574558476634U;
            aOrbiterE = RotL64((aOrbiterE * 2356386971503880047U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10161614295718414869U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13413914082651612468U;
            aOrbiterJ = RotL64((aOrbiterJ * 16224039093981079491U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6072693130156927774U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4333656233793103787U;
            aOrbiterH = RotL64((aOrbiterH * 9374745547133955709U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17209776289202130250U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11752001118070361543U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4416523594812872339U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 20U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 46U)) + aOrbiterI);
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + aNonceWordI) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterI, 29U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 12U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 24U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterB, 37U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31822U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 31167U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 32497U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30090U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28570U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 28U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 14823268998003220191U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 56U)) + 15295237288788213847U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 16434853402001133899U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aWandererG + RotL64(aCross, 43U)) + 7555911304407871631U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 47U)) + 14977248264994834620U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 21U)) + 9707764144919392380U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 52U)) + 1277304385464681529U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 3089786220465849395U) + aNonceWordM;
            aOrbiterG = (aWandererK + RotL64(aIngress, 5U)) + 3700503853358695085U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3240054112993517371U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16897532076915366859U;
            aOrbiterA = RotL64((aOrbiterA * 4120874717534309035U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18167359289798364307U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8870819278575769863U;
            aOrbiterH = RotL64((aOrbiterH * 9334066154398059075U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15363069206212330251U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14858164441499725158U;
            aOrbiterC = RotL64((aOrbiterC * 14931933411393847915U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5357144808788707522U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 2910681277417754860U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 13170868582159347059U), 13U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 9824408699018165151U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 368370224788793300U;
            aOrbiterK = RotL64((aOrbiterK * 14358982366258729959U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7095398304588825115U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11418879758164313554U;
            aOrbiterG = RotL64((aOrbiterG * 5983520332639771791U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2171599720681913272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17593730219647495033U;
            aOrbiterB = RotL64((aOrbiterB * 12926053208918563087U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17755947635188715523U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14565740605227022106U;
            aOrbiterE = RotL64((aOrbiterE * 15866418354612945335U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14538017880915584414U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6174566474851449123U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 179569008593475683U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + aNonceWordK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 36U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 57U));
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 24U) + aOrbiterK) + RotL64(aOrbiterE, 13U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 11U)) + aNonceWordC) + aPhaseFWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 24U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 22U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8B0789AF47614B9FULL + 0xB9A532EAF01F307AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8E8DC330D90FC8FFULL + 0xDF3A852B3FFC99BEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9E3A5886AEF3F217ULL + 0xE10E95DD905FD18BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC52D1E7AA0FE44B3ULL + 0xC04CB069B9A701F6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC843138E2B75550FULL + 0xDDECCF7BE642E6A0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA9E5879B02BDE02FULL + 0xCE5C84423354F89AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC7AAF95F0904D7FBULL + 0x8FDFE6C04478688AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA739C2337A7D1985ULL + 0xC8C71EE3729F8B43ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF179505C0EA0B965ULL + 0x87766F26D8F4F43BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA2D098F24C15FC29ULL + 0xEDF0527A21E3335EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9F5F44BD03F31B79ULL + 0xCF268CCC783755F9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFFD866A6EE7572B7ULL + 0xBBC25BABE68CCB89ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA5E828FD7115C12BULL + 0xBD198919D8F70E92ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAA92EB2381BAEE67ULL + 0xD4EA35CFCE5E8F13ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDB02487534759D39ULL + 0x9F83FBCB24EA709BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBA7F2988CCA7E201ULL + 0xC999814417D6F8AEULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3920U)) & S_BLOCK1], 14U) ^ RotL64(aSnowLaneB[((aIndex + 3176U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 922U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 258U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 700U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1855U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 42U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (aWandererI + RotL64(aScatter, 51U)) + 9446153639709651566U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 10550762260670758167U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 7062634922142578383U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 60U)) + 9178499097812764515U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 11U)) + 6887103379773525538U) + aNonceWordF;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 41U)) + 6239750312052010257U) + aNonceWordN;
            aOrbiterB = ((((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 17645022614523287959U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3639618183259408272U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3131737117548745095U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6585057380704940395U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7253994382396406554U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15217993711938379561U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17853313384747259923U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12594152227603630033U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11250170200489647869U;
            aOrbiterI = RotL64((aOrbiterI * 546800378327864723U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12936942656624279424U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10990736056052106149U;
            aOrbiterB = RotL64((aOrbiterB * 7123916809953459187U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12787293075893090465U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17154990205620778151U;
            aOrbiterC = RotL64((aOrbiterC * 10031369940028159521U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 1270827262969060301U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17337623431665013136U;
            aOrbiterG = RotL64((aOrbiterG * 1517262088236356107U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 830330490987911853U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6828309232554560547U;
            aOrbiterK = RotL64((aOrbiterK * 9742464176986145819U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 37U)) + aOrbiterB) + aNonceWordE) + aPhaseHWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterI, 52U)) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 22U) + aOrbiterF) + RotL64(aOrbiterE, 43U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8483U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((aIndex + 8345U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 8615U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9902U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8906U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8151U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9311U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 966899917801652720U) + aNonceWordG;
            aOrbiterH = ((aWandererK + RotL64(aCross, 3U)) + 10996327672320748649U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 4188171566846621107U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 41U)) + 5886209243097387959U) + aNonceWordO;
            aOrbiterA = (aWandererF + RotL64(aCross, 10U)) + 14940428957136728111U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 51U)) + 179187285531914832U) + aNonceWordI;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 6685351948936817752U) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1894506461704029700U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 4182760368636977082U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 972988091869133921U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12523318028514940790U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5059306166973366892U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2857409765717296483U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5890872367917643851U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17747338389865221534U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 5306740664798049267U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13906227834259884100U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7152105382899756368U;
            aOrbiterD = RotL64((aOrbiterD * 6772157117358310485U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17868101884759619240U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11758843266314148347U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 5919135169337501485U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13950566197090324859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17278105609930477854U;
            aOrbiterA = RotL64((aOrbiterA * 11431842718945107359U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9556785965646738355U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 841298436857932987U;
            aOrbiterK = RotL64((aOrbiterK * 15077843186688841797U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 58U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + aNonceWordE) + aPhaseHWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13212U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((aIndex + 15924U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11505U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11217U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 16338U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 18U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 2558105147674438050U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 48U)) + RotL64(aCarry, 13U)) + 15856662514774702561U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 27U)) + 13346869226246584582U) + aNonceWordF;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 7632111846116243973U) + aNonceWordC;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 41U)) + 2102101361626976279U) + aNonceWordJ;
            aOrbiterI = ((aWandererI + RotL64(aCross, 3U)) + 5605968705067851563U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aScatter, 21U)) + 6842483186584326681U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5559797213819425064U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12422313931331576759U;
            aOrbiterJ = RotL64((aOrbiterJ * 7399849122565913401U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2751024420047872601U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11031320239359798610U;
            aOrbiterB = RotL64((aOrbiterB * 8607639453141148025U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14366375309473793217U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11971479429768505316U;
            aOrbiterI = RotL64((aOrbiterI * 10063001532313098203U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3947595951884469542U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17882767922372770896U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3361906348965810211U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 513871456983509223U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5951677013597794294U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8508629569649935293U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 437626309049021931U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 466674061172005705U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 1310502572084891157U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 12362602809233133718U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10525852878882195702U;
            aOrbiterH = RotL64((aOrbiterH * 17755022180514914325U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 41U)) + aNonceWordK) + aPhaseHWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 19U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterG, 26U)) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 39U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aNonceWordP) + aPhaseHWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21375U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 17839U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20077U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19827U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneD[((aIndex + 20656U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 5U)) + 6163290588946759209U) + aPhaseHOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 20U)) + 7342672468560105447U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 29U)) + 11574563167017282321U;
            aOrbiterJ = ((((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 2254820206194758964U) + aPhaseHOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aWandererK + RotL64(aIngress, 35U)) + 1469783447473099498U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 14174828900676165088U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 16277954291890598132U) + aNonceWordP;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14845750668693136766U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 150099699692047766U;
            aOrbiterB = RotL64((aOrbiterB * 7644895634421086357U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1200784917165131703U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 9469982764806754302U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 17851969334511301943U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10956702761701710182U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7915506894975487807U;
            aOrbiterJ = RotL64((aOrbiterJ * 8874108311712727983U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17335794183733623213U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 557028996286989506U;
            aOrbiterF = RotL64((aOrbiterF * 3993359298602424281U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1597385667771002414U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4376417959915162639U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 4626236858205178149U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 549770198518993876U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 756554555648070919U;
            aOrbiterG = RotL64((aOrbiterG * 16272320259614325355U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7298557532533152193U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 3336802611342112013U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14679103452120080499U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 20U)) + aOrbiterI) + aPhaseHWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 24U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 35U)) + aNonceWordB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22206U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 25713U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 25851U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26526U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((aIndex + 25734U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 38U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 701291026547470433U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 10U)) + 17283292650462111643U) + aNonceWordO;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 35U)) + 9969124091931303406U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 3U)) + 889176772718046988U) + aNonceWordD;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 57U)) + 6054541844643748084U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 14703226235143028132U) + aNonceWordE;
            aOrbiterG = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 7977975878522921062U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16894322614172266274U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12160451749345900570U;
            aOrbiterF = RotL64((aOrbiterF * 18055355572903901749U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10870847008043897470U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8159920947172520247U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 4833194641611011805U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2440099120969517932U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2428396147731468007U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9363073341539598441U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2213226274394673479U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7079731443427765333U;
            aOrbiterH = RotL64((aOrbiterH * 16918930776877030559U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 958896789550478970U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10788682955708075458U;
            aOrbiterG = RotL64((aOrbiterG * 913321215613559729U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2003386579317564870U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8419686358774204999U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6547052526438697621U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6989167615157578904U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17636634003643824148U;
            aOrbiterC = RotL64((aOrbiterC * 11038576417283732937U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 46U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aNonceWordH) + aPhaseHWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterA, 52U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 14U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27474U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 31589U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31519U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31913U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneB[((aIndex + 31749U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 58U) + RotL64(aIngress, 11U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 8604208734152026945U) + aPhaseHOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 35U)) + 1374329953253889829U) + aNonceWordE;
            aOrbiterH = (aWandererD + RotL64(aIngress, 44U)) + 5779278910548228339U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 23U)) + 17670451230882805140U) + aPhaseHOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 8193848740764866860U) + aNonceWordB;
            aOrbiterA = (aWandererI + RotL64(aIngress, 5U)) + 15801168428145650104U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 2584718176087499066U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14950366247822737997U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9779293225265670135U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 11625969538497982117U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8688968319288372383U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13665723186950342601U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 292035540396910837U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9395428688359973510U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2152719218018108418U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 15271961483518392671U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1350324137411377992U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 8729317951386057921U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 6008790836417785083U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6317310451893678411U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10175620379041384281U;
            aOrbiterC = RotL64((aOrbiterC * 14079679617394330781U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1203082119358827708U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 523869107818193101U;
            aOrbiterB = RotL64((aOrbiterB * 4629501113595689157U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4028324959540432983U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15447631947468213912U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6037306615787729185U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 28U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 35U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 4U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterI, 37U)) + aPhaseHWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 932U)) & W_KEY1], 60U) ^ RotL64(aKeyRowReadB[((aIndex + 783U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2606U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1792U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 26U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 35U)) + 9654059367478508868U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 53U)) + 6473006635864677427U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 18U)) + RotL64(aCarry, 53U)) + 6944184481315853243U;
            aOrbiterG = (aWandererE + RotL64(aCross, 57U)) + 4061496421939102306U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 13U)) + 15791809275719085463U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 14050798802646323055U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 12072905924741758266U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 23U)) + 17639076509231343896U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 4U)) + 12195388285571234715U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4325404419499496529U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5910567888204238382U;
            aOrbiterI = RotL64((aOrbiterI * 11503787177122206937U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13092940059929942699U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13381962590820308761U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6345904465930943295U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15622862439323440527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14027151901132249793U;
            aOrbiterG = RotL64((aOrbiterG * 2273573821630510087U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4584410023907605157U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15763755180625487157U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6755736130607297639U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17023059745666559199U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5298529579288492971U;
            aOrbiterE = RotL64((aOrbiterE * 2483562793328357721U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2870152867331654736U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12017191100173748848U;
            aOrbiterB = RotL64((aOrbiterB * 9958191466506480519U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15899529176182436062U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16482713846343388735U;
            aOrbiterA = RotL64((aOrbiterA * 719465695044265601U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12943393531812774449U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9881108254540483225U;
            aOrbiterK = RotL64((aOrbiterK * 8011108108007885059U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3532054586199716750U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7142230313294797435U;
            aOrbiterC = RotL64((aOrbiterC * 14154176174768868421U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 34U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterB, 34U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 34U) + aOrbiterB) + RotL64(aOrbiterF, 23U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 58U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4353U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4467U)) & W_KEY1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2971U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 3467U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aScatter, 47U)) + 16124889768301047791U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 11912338587186717280U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 24U)) + 8594012868813114354U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 41U)) + 18281043566156682815U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 16853106130200942302U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 2611212958619673086U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 28U)) + 18039472325066855180U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 53U)) + 14495785571345122046U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 57U)) + 4556063793412832418U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14896419970271244358U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 880028529183500036U;
            aOrbiterH = RotL64((aOrbiterH * 14228281807461251361U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2379557167489415783U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11854373946064529806U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 150755294320438887U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1487252775956449964U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12777924204511625545U;
            aOrbiterI = RotL64((aOrbiterI * 1366019527386994789U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15998631485222477969U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8864212892296191613U;
            aOrbiterC = RotL64((aOrbiterC * 579242788050369815U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17069347835763226743U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7443008171694679791U;
            aOrbiterE = RotL64((aOrbiterE * 748894368884566607U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17334256152350782002U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8986626119086556393U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2258172145924120235U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8528180968228358674U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12702290928064582589U;
            aOrbiterA = RotL64((aOrbiterA * 15673603224146737631U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7742438100860023610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3729687240959702198U;
            aOrbiterD = RotL64((aOrbiterD * 3756794766163746783U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 426129097367382096U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16782175452274911213U;
            aOrbiterJ = RotL64((aOrbiterJ * 1041477289638333659U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 26U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 60U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterE, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7605U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 6153U)) & W_KEY1], 36U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6271U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6863U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6067U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCross, 51U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 1457104756581596530U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 5U)) + 6127240317844622874U) + aPhaseAOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 56U)) + 16492290056044189421U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 10963676850938416468U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 11U)) + 4872917367399752405U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 39U)) + 15218882377875616148U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 30U)) + 5934166612122118251U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 35U)) + 14215280930872003003U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 11428034799044600979U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5453003654321728726U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14273775120265649389U;
            aOrbiterF = RotL64((aOrbiterF * 5139018128323795309U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 328723770018440271U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13032190719588211088U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13363368478932798315U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2386881543033598494U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1649501123340887116U;
            aOrbiterD = RotL64((aOrbiterD * 11148976582360499033U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16462401546754210583U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1510579201823042227U;
            aOrbiterI = RotL64((aOrbiterI * 16287912400104043275U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6889066000014251983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11324594596597724357U;
            aOrbiterE = RotL64((aOrbiterE * 15344987814648586023U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12237796033168436537U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17306069670330000343U;
            aOrbiterH = RotL64((aOrbiterH * 3167451351403385259U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14197284538008811658U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4754134852883071927U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3484427259538998699U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17201907781639753736U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8318419319239859855U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10320390501983802091U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16012488623961565780U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15583721012865354925U;
            aOrbiterC = RotL64((aOrbiterC * 10656414363201743961U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 54U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 46U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 10U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9331U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadB[((aIndex + 9750U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 8853U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneA[((aIndex + 8212U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10893U)) & W_KEY1], 21U) ^ RotL64(aFireLaneB[((aIndex + 9243U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 53U)) + 6654158889644956636U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 35U)) + 9045779659363991870U) + aPhaseBOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 46U)) + 3888897662136993491U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 41U)) + 6882016842864459345U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 15601891715956172291U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 23U)) + 5176811598629335350U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 12519945150889074325U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 4552583214397603278U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 28U)) + 14225482701804864688U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5485298070606280363U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11237713257388094289U;
            aOrbiterJ = RotL64((aOrbiterJ * 11032429223099413011U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14340345895626142788U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16275167270553643347U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7308578867128951199U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14041860597556520250U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1436068974197066343U;
            aOrbiterD = RotL64((aOrbiterD * 3938460345031496843U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11483155566419547004U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4608508534724289325U;
            aOrbiterK = RotL64((aOrbiterK * 13461385011638899485U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2389196334288832895U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4062682330273866602U;
            aOrbiterA = RotL64((aOrbiterA * 8787682133271101901U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5655656046585592034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7977947821249746880U;
            aOrbiterC = RotL64((aOrbiterC * 10082104644185964787U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11653718118543974168U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 5456429682072377614U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12504180638665296649U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12457179652004203574U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 445821754230182952U;
            aOrbiterF = RotL64((aOrbiterF * 16043092621697786393U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12429505513284703263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12480745784412363537U;
            aOrbiterI = RotL64((aOrbiterI * 643617210585287593U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 52U) + aOrbiterF) + RotL64(aOrbiterG, 28U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 53U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 14U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 48U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12638U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 12807U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13128U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 11236U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12722U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12512U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneC[((aIndex + 13598U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 47U)) + 14499676118633326000U) + aPhaseBOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 19U)) + 17191273593018552288U) + aPhaseBOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 30U)) + RotL64(aCarry, 39U)) + 4085176294948097737U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 13U)) + 11112671474158908186U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 37U)) + 8745787969012266485U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 18074049663777707948U;
            aOrbiterG = (aWandererA + RotL64(aCross, 24U)) + 2543758649719164688U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 4659584749412700523U;
            aOrbiterI = (aWandererC + RotL64(aCross, 43U)) + 974639159259871273U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9211220687971081987U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8567024626862182714U;
            aOrbiterA = RotL64((aOrbiterA * 7755874089832496393U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5803002132294840900U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11968489432878148467U;
            aOrbiterH = RotL64((aOrbiterH * 4501441062617123165U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9470807228394903442U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1692347973120388469U;
            aOrbiterJ = RotL64((aOrbiterJ * 17433393164156231575U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16510815732690193145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 755159406833096510U;
            aOrbiterG = RotL64((aOrbiterG * 14091736464659561165U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1518824876475937620U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 701225390867330446U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12264618860580199927U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8425976693733003889U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7182176375442410367U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8860605703761731859U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4546566785167467924U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2593340999038753749U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10152461487764567563U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9756331608356622299U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5511625814747641978U;
            aOrbiterB = RotL64((aOrbiterB * 4806076157539829529U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8694400787420160733U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12648969491371382682U;
            aOrbiterI = RotL64((aOrbiterI * 5346585704222643759U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 20U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 14U));
            aWandererA = aWandererA + (((RotL64(aCross, 30U) + RotL64(aOrbiterA, 39U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + aPhaseBWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterH, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterF, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 10U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 47U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 15671U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13724U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15464U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15567U)) & W_KEY1], 57U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15812U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15848U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14058U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 34U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 10812151398716051703U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 18202551453336003710U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 35U)) + 9434410809101973752U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 60U)) + 12955829998028534045U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 5U)) + 12271740641929640181U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 39U)) + 14009351527014534752U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 53U)) + 4316296955679133450U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 22U)) + RotL64(aCarry, 35U)) + 16473324966997442872U;
            aOrbiterA = (aWandererE + RotL64(aCross, 43U)) + 15735123324965019802U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17656375090484080236U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16066325053456055298U;
            aOrbiterD = RotL64((aOrbiterD * 17912970706985130327U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12908968778503516903U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12761433987676836197U;
            aOrbiterG = RotL64((aOrbiterG * 1023329467480907925U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12737513138040664509U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14535795767570998392U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15560519667062222269U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 14370908061811284364U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7001358781208669795U;
            aOrbiterI = RotL64((aOrbiterI * 11641248025734015835U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7298578161120090849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10498302152357484629U;
            aOrbiterK = RotL64((aOrbiterK * 13144110412179037175U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11447343228638006767U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 18284143620422655675U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 572862190073605651U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5918253208127360199U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3910541329178205943U;
            aOrbiterF = RotL64((aOrbiterF * 4550654545328228103U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10357053096941367910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5610891501128498748U;
            aOrbiterE = RotL64((aOrbiterE * 8676370811772047449U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9049881176058575811U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6307599924966452216U;
            aOrbiterB = RotL64((aOrbiterB * 5551444450572055895U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterD, 56U)) + aPhaseBWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererD = aWandererD + ((RotL64(aIngress, 38U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterI, 21U));
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 26U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17768U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 16509U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 16560U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 18662U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17132U)) & W_KEY1], 37U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18348U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 18236U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 54U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererK + RotL64(aPrevious, 39U)) + 12206125048349568300U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 12U)) + RotL64(aCarry, 27U)) + 5843520589343188818U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 19U)) + 12195046124287121687U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 16769779119214020640U) + aPhaseCOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 5257603646260695833U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 60U)) + 8523523946234886745U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 23U)) + 7316024684200084096U;
            aOrbiterI = (aWandererC + RotL64(aCross, 5U)) + 11996978575084115207U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 35U)) + 15491711479085513628U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6036648530996821484U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 926323222234121863U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6639661141258803779U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2700323841295743492U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5852273765810284935U;
            aOrbiterA = RotL64((aOrbiterA * 16665696735016345215U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11697397483133538067U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17777142964957007194U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6338967222543284999U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10892176201151170298U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11759700374509499684U;
            aOrbiterI = RotL64((aOrbiterI * 14247697264744736081U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11343756773329590643U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15785048929757652350U;
            aOrbiterC = RotL64((aOrbiterC * 17208103574389502597U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7508839228498497238U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13088508510402094665U;
            aOrbiterE = RotL64((aOrbiterE * 15730279447009669103U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 16259236641717377699U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11228995722951003980U;
            aOrbiterK = RotL64((aOrbiterK * 4870092259515181323U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13775851561528617086U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3023564646900497080U;
            aOrbiterH = RotL64((aOrbiterH * 9936548213275464131U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 154952467284609583U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14239675888632174461U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1370550680736926425U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 52U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 34U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + aPhaseCWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 54U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterA, 19U));
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterC, 56U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20218U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((aIndex + 20520U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20398U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20166U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19533U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21261U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19638U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19821U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 47U)) + 13296600294247799698U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 34U)) + 5818503518080877515U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 27U)) + 6735784238734173597U;
            aOrbiterA = (aWandererG + RotL64(aCross, 53U)) + 7368398209488856201U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 961734029066455638U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 11U)) + 797011946660892011U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 19U)) + 12841876018396622350U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 16213253970483895623U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 40U)) + RotL64(aCarry, 13U)) + 15186950557113470375U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5117930310827477341U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12265429373166094162U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1522823535151532249U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13920531346698601568U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14695405206998211456U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13950964363414164279U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7851960904825938443U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9501511171732550190U;
            aOrbiterI = RotL64((aOrbiterI * 5614164120361489613U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5663365182245722077U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9607860124321315555U;
            aOrbiterB = RotL64((aOrbiterB * 3461820361914280601U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18171052650586819280U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3442698321538580861U;
            aOrbiterK = RotL64((aOrbiterK * 6317525514963824829U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1491052813469258970U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3956599824067616133U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2928600779267623085U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10963841237346073453U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2303020125591252534U;
            aOrbiterH = RotL64((aOrbiterH * 9969099842343321981U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14503856057958162356U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11147548150090597694U;
            aOrbiterA = RotL64((aOrbiterA * 11856382308792700441U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9191681438318311481U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13556072770381999852U;
            aOrbiterG = RotL64((aOrbiterG * 18316231099054203683U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 4U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 34U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 12U)) + aOrbiterI) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 43U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterG, 29U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterB, 24U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22458U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 22584U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22783U)) & W_KEY1], 44U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22933U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23910U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23100U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22155U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 23383U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 3973833383430652211U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 36U)) + RotL64(aCarry, 37U)) + 5760227042747169187U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 13U)) + 4923009065139227286U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 23U)) + 1477807307009107590U) + aPhaseCOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 5707194514329007301U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 19U)) + 5340439728375269724U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 42U)) + 17080457898946572387U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 47U)) + 281559150259472813U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 5U)) + 16160633048230910560U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9003989610509592121U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10579322462808454333U;
            aOrbiterC = RotL64((aOrbiterC * 100832431598087235U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15059383289528723069U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10417647757852880956U;
            aOrbiterJ = RotL64((aOrbiterJ * 1457919230286043137U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14484665027393813330U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12344463053485837974U;
            aOrbiterK = RotL64((aOrbiterK * 5762654194001525041U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5826453246659297805U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12547902286376986223U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2982850000322672789U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9637855144278126174U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2132744427444501938U;
            aOrbiterG = RotL64((aOrbiterG * 5911587798564836199U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9248933938130311231U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13274297928717090383U;
            aOrbiterI = RotL64((aOrbiterI * 2901398809555237563U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3690262236918560930U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3626005326410800344U;
            aOrbiterD = RotL64((aOrbiterD * 13030443356669355355U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10801089744186148218U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5446653082176311031U;
            aOrbiterF = RotL64((aOrbiterF * 4594267575901248321U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3205541585889107366U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4532327942368884436U;
            aOrbiterE = RotL64((aOrbiterE * 16287094987689326229U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 26U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 36U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterK, 53U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterB, 41U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterI, 30U));
            aWandererE = aWandererE + ((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 19U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 23U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25108U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadA[((aIndex + 26188U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25093U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24875U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25307U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25647U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27273U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25018U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererE + RotL64(aScatter, 51U)) + 16200278595895089008U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 46U)) + 1029614154810465897U) + aPhaseDOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 7129562468705441295U) + aPhaseDOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aCross, 13U)) + 14388903902433951274U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 1013568949315967455U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 3128823373497815651U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 29U)) + 14525694606889470589U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 5U)) + 14443983602196782887U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 18U)) + 12244220415328641190U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10477159225338766614U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2842870123078131566U;
            aOrbiterH = RotL64((aOrbiterH * 11522265477555954071U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8621138818955849917U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5038396344400303181U;
            aOrbiterG = RotL64((aOrbiterG * 14636756322207385447U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2768613802894372496U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2027754864051410015U;
            aOrbiterB = RotL64((aOrbiterB * 2461322540050569287U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2848088309172056399U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15017458513904884651U;
            aOrbiterI = RotL64((aOrbiterI * 9926904679902843055U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9079797279596336139U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15424866642305110811U;
            aOrbiterJ = RotL64((aOrbiterJ * 12912331089970158845U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13751764050290602740U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7694557131324740282U;
            aOrbiterF = RotL64((aOrbiterF * 14980807690491467023U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3508673897305667669U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3600868397311393233U;
            aOrbiterA = RotL64((aOrbiterA * 5165032044164139165U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1222655844979128996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2257342337168905875U;
            aOrbiterK = RotL64((aOrbiterK * 6198995971182272119U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6290990717563682725U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15308494772443447109U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1925593111157842325U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 28U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 60U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 39U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + aPhaseDWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 46U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 54U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27871U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 28915U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27528U)) & W_KEY1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27407U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27650U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27491U)) & S_BLOCK1], 42U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28736U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28132U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aIngress, 27U)) + 1708250618750199233U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 42U)) + RotL64(aCarry, 51U)) + 12009147777553691142U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 11U)) + 8393982703399156592U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 47U)) + 3247327098356831221U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 35U)) + 3403590155376353737U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 19U)) + 18197244558104735044U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 53U)) + 3096253642040701606U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 3U)) + 8012692688785412179U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 17531946907545680745U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17687695944270225817U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16147773866007628769U;
            aOrbiterE = RotL64((aOrbiterE * 16926442582711557877U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18244641303026196497U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8839160526348897457U;
            aOrbiterC = RotL64((aOrbiterC * 14268021129087663397U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10599266240854068246U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2056723540756216155U;
            aOrbiterH = RotL64((aOrbiterH * 13311591601230386375U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4629354220460621284U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9505955649473204942U;
            aOrbiterB = RotL64((aOrbiterB * 17775391885312236187U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17078153810088721310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9470436761716263000U;
            aOrbiterG = RotL64((aOrbiterG * 5431855497250357229U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3305863413630104742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14377172434239576161U;
            aOrbiterI = RotL64((aOrbiterI * 6880176890091033423U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 415687827894226513U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16975319836893760993U;
            aOrbiterF = RotL64((aOrbiterF * 6597144958013976445U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12707054129431596074U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8974182792497231239U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7874658957269462717U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10826131924322955095U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4168545139712703154U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10305904857550051705U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 48U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterC, 52U));
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterC, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 34U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererG, 24U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30967U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30895U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30827U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30638U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30266U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32295U)) & W_KEY1], 18U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCarry, 27U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 3U)) + 7896237440058555694U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 13U)) + 11870529476037558635U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 9158983227801569448U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 57U)) + 4710172270996950329U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 23U)) + 14634482800356647630U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 37U)) + 8822207952170610891U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 43U)) + 13755891414028982553U;
            aOrbiterI = (aWandererI + RotL64(aCross, 50U)) + 4555293067488040719U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 2816805148093762081U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2122631477965135190U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4592922416380416071U;
            aOrbiterH = RotL64((aOrbiterH * 11644507904538573165U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7102471666524164715U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17274623547879474204U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5443572270546181789U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 938587316977094680U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18258015823797023523U;
            aOrbiterI = RotL64((aOrbiterI * 6068819567674605919U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5809987756043471595U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5083075160112581620U;
            aOrbiterG = RotL64((aOrbiterG * 3313957222154937503U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5960021727750946496U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5967477320950630150U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 330964768256424655U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6578428711689296132U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5601728218197771276U;
            aOrbiterB = RotL64((aOrbiterB * 9552559022315971847U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7923809409017855241U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16479366540906497019U;
            aOrbiterC = RotL64((aOrbiterC * 7118578387798460919U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17000467091738009736U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6801634573655508028U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10584635770060137089U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 123668445682719574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14462802805503986316U;
            aOrbiterJ = RotL64((aOrbiterJ * 12398236364304875941U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 18U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterE, 20U));
            aWandererB = aWandererB + ((RotL64(aIngress, 34U) + RotL64(aOrbiterB, 53U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 60U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 48U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4719U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 6037U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4258U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2068U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6557U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2454U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 60U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 57U)) + 1393781663398437180U) + aPhaseEOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 41U)) + 17414594746688585273U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 2823888497053071250U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 47U)) + 17032631958617884859U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 39U)) + 15222697630461125019U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 15737414920751551780U;
            aOrbiterG = (aWandererF + RotL64(aCross, 21U)) + 1357196111055783001U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5315122321649251691U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7893744655508595974U;
            aOrbiterB = RotL64((aOrbiterB * 17863000246694319149U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16721939414324611738U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3444375866323610848U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10874157227815775661U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1825716513674511632U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15582066843912467318U;
            aOrbiterJ = RotL64((aOrbiterJ * 12765146555943757373U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15673590949193923915U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13887365046280406413U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3169061375011420121U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12730414371734709356U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4819112390640821927U;
            aOrbiterG = RotL64((aOrbiterG * 8782547948627685451U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3089925954422937464U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7180179304678622530U;
            aOrbiterI = RotL64((aOrbiterI * 16118051565147747413U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17030269962085008657U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6675917351883004046U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14134335325316949687U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 36U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterI, 60U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12537U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 12029U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11402U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10443U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16172U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15469U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12454U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 18087125778766689269U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 13710545066503235196U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 30U)) + RotL64(aCarry, 29U)) + 1701939704736254645U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 8064093611384019909U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 21U)) + 16623332751533885431U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 3U)) + 15590129153794910109U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 41U)) + 7413312683079107383U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4186064478651458810U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5501191643940735954U;
            aOrbiterC = RotL64((aOrbiterC * 14254804649177125269U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11064645242200570835U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13825922087298055833U;
            aOrbiterF = RotL64((aOrbiterF * 7529317892716108867U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5944980709887369970U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8181136916070569646U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 395183021205661827U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15442336949157292482U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11580554435240641337U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6654637892858767739U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11240018128174598322U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2027565596050777471U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18048186560314431815U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16425887196883725233U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16828683527588834095U;
            aOrbiterA = RotL64((aOrbiterA * 17746289103235902485U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9923829146479008804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6669171007279929454U;
            aOrbiterD = RotL64((aOrbiterD * 681823450939955099U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 26U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterB, 21U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterB, 60U));
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22240U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 22061U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 16894U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 17595U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23936U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24159U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20842U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 13U)) + (RotL64(aIngress, 28U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 13U)) + 13442819395490639310U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 8187292523194120936U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 11469697159823131388U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 23U)) + 13414083692375929653U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 44U)) + 11404010733687907517U) + aPhaseEOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 6783212827186218247U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 29U)) + 8561131439340372614U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6252609642004429113U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12804867444200448952U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3114688959081972615U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2739648749603690781U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14808861217017399752U;
            aOrbiterI = RotL64((aOrbiterI * 373911885694012101U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17588866502571268888U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5882260142735642980U;
            aOrbiterC = RotL64((aOrbiterC * 7688252946143263869U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15493099088132862949U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5175647411532429582U;
            aOrbiterB = RotL64((aOrbiterB * 15226544495598541883U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14279707376173642767U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6826363572161275158U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5263708315440161809U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13267185753040999992U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9980987858092888720U;
            aOrbiterF = RotL64((aOrbiterF * 13210290848800728635U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3582972937645514549U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10140409019562890804U;
            aOrbiterE = RotL64((aOrbiterE * 6944490201647678479U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 58U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 27U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 51U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 21U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + aPhaseEWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31125U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 26698U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 30867U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25782U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29826U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28962U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27772U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 41U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 6361545377408870615U) + aPhaseEOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 14U)) + 2967245486744774933U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 5U)) + 3836634268482850139U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 7691642115360086297U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 16479280384178279281U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 29U)) + 2901468732552539249U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 47U)) + 2600353867755647475U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5666596904781510956U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16108791609267427553U;
            aOrbiterK = RotL64((aOrbiterK * 8904649663479834199U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8389926875737312112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1689501721163024426U;
            aOrbiterG = RotL64((aOrbiterG * 6517194895779049139U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11721701506949917719U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3963842745030140473U;
            aOrbiterF = RotL64((aOrbiterF * 6692473494944919373U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8510538243472109368U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18281865214102080387U;
            aOrbiterJ = RotL64((aOrbiterJ * 1351546966368884609U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 2259725140963665123U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11652011949557979650U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11260100762113295037U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1116085424226174473U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4725260319270802912U;
            aOrbiterH = RotL64((aOrbiterH * 4697109059565450269U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7348945429843437036U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1249234309180653260U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3136745255820405881U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterE, 4U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 42U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2522U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 7918U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3787U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3248U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1978U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1796U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 21U)) + (RotL64(aCarry, 40U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 28U)) + 1042610313571524121U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 3505725321008825582U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 37U)) + 12584654563843782991U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 5U)) + 6645399144515770935U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 3608978423753715584U) + aPhaseFOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 39U)) + 8089198857670370983U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 19U)) + 15207251813516399879U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 60U)) + 9579268660105824516U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 16055044469473802812U;
            aOrbiterC = (aWandererG + RotL64(aCross, 11U)) + 583811872609805949U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 13U)) + 7027491967970873942U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 18256061823189677508U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12708429127816136937U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12593886633108075321U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12169216645156306078U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12694325407567795065U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3711789483877261899U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16109994660203297503U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4234704064165718913U;
            aOrbiterB = RotL64((aOrbiterB * 730085881474787681U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14119541943554602878U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8777769004811352951U;
            aOrbiterI = RotL64((aOrbiterI * 2556957257736134223U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15642663488392549609U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11594468530833278624U;
            aOrbiterG = RotL64((aOrbiterG * 6639306656361601143U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7365350535791499871U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5965170981970155956U;
            aOrbiterE = RotL64((aOrbiterE * 1898702752753066851U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9115232101451815522U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9433983580038990072U;
            aOrbiterA = RotL64((aOrbiterA * 1951249217843992179U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8810565477444156140U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12081286530401844859U;
            aOrbiterF = RotL64((aOrbiterF * 1991383259486140229U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7498045374283306625U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13095973566401200720U;
            aOrbiterK = RotL64((aOrbiterK * 2657451581036351987U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18205793828042507364U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3339020890428651569U;
            aOrbiterC = RotL64((aOrbiterC * 10195916881103252701U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16957913958369950483U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1042610313571524121U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11206619213970727629U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 40U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aCross, 54U) + RotL64(aOrbiterD, 41U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterA, 54U));
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 38U) + RotL64(aOrbiterG, 12U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 4U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 50U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13881U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 10400U)) & S_BLOCK1], 42U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 15004U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 10386U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11416U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13592U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9213U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 58U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererI + RotL64(aPrevious, 3U)) + 11210042748013785976U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 4584747303233477454U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 8878765929792969517U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 19U)) + 2172232330280041122U;
            aOrbiterB = (aWandererH + RotL64(aCross, 36U)) + 8378937026022264016U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 57U)) + 8683007464695824208U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 5U)) + 9564352997357118134U) + aPhaseFOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 11713878436769887528U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 13U)) + 8052917623074021077U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 11U)) + 7720597162792145185U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 50U)) + 2602847785328475621U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17813669222300509724U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8724263063156573013U;
            aOrbiterG = RotL64((aOrbiterG * 3632927017737834359U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6882429835961613492U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13213313479525717359U;
            aOrbiterB = RotL64((aOrbiterB * 2411431247725974895U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2401526093648669573U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3616448566579979749U;
            aOrbiterI = RotL64((aOrbiterI * 13323155103752121393U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18268262471839710401U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5116424918948694752U;
            aOrbiterH = RotL64((aOrbiterH * 7641143782996332069U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11405305689555640431U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12427591396711015574U;
            aOrbiterJ = RotL64((aOrbiterJ * 8112834135715541223U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16960781161508084626U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12382604781005282628U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17196168631120103115U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10054839091354729292U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4167641616532985407U;
            aOrbiterA = RotL64((aOrbiterA * 919291747187787625U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14383737233143309039U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16258779988369405932U;
            aOrbiterK = RotL64((aOrbiterK * 8348773195366160215U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4777263172049970723U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12498046021142146499U;
            aOrbiterD = RotL64((aOrbiterD * 5941015011162130901U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7435001955334177144U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4100235545173125433U;
            aOrbiterE = RotL64((aOrbiterE * 5046572784117638909U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1981704568071298614U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11210042748013785976U;
            aOrbiterF = RotL64((aOrbiterF * 17889749044418386565U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 50U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterF, 60U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 47U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterA, 18U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19257U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((aIndex + 22810U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20100U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 19380U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20995U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16516U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22487U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 2225397913940961213U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 50U)) + 8342544893601343643U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 23U)) + 162922186381417187U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 53U)) + 11660218373710972210U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 5U)) + 14909034764605802354U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 16776955237009701511U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 57U)) + 5834487809188925253U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 1498492772767040320U;
            aOrbiterB = (aWandererG + RotL64(aCross, 29U)) + 4161765458781579617U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 26U)) + 10511923076962447765U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 47U)) + 8575954471692620021U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6536325446331340573U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1790628986900286346U;
            aOrbiterF = RotL64((aOrbiterF * 5262997114200816715U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2623814807619278590U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11676970995834706612U;
            aOrbiterI = RotL64((aOrbiterI * 10057461115132434901U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13836786354224256591U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6293096163612129260U;
            aOrbiterJ = RotL64((aOrbiterJ * 8977954126326217153U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4271144764978661248U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15938494256992560202U;
            aOrbiterE = RotL64((aOrbiterE * 10004841288382726739U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11038155227307702976U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12408749795071243930U;
            aOrbiterK = RotL64((aOrbiterK * 5527720475032868855U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1673665849053496882U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12866353361497103629U;
            aOrbiterD = RotL64((aOrbiterD * 6041125499398924871U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10673935802381580966U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8946776538955520352U;
            aOrbiterB = RotL64((aOrbiterB * 12293084177712710021U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16294935203370452805U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4697759331563852212U;
            aOrbiterC = RotL64((aOrbiterC * 14407806317275373043U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17633118874112283386U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 89602424202721105U;
            aOrbiterG = RotL64((aOrbiterG * 1010654844008668685U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4019154066191316616U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15029609435149173243U;
            aOrbiterH = RotL64((aOrbiterH * 3522168783248806167U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11765990698273078458U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2225397913940961213U;
            aOrbiterA = RotL64((aOrbiterA * 8471538922288466221U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterG, 24U));
            aWandererE = aWandererE + ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 39U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 42U) + aOrbiterE) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 26U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterG, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32631U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 32457U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27746U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 26483U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32524U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26474U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 26005U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 43U)) + 12046647397183218524U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 37U)) + 2760779375026461991U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 21U)) + 13735454443176855650U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 29U)) + 4370377000586647724U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 51U)) + 14566322384189969094U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 39U)) + 5056565959818422786U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aScatter, 13U)) + 8795403810686579209U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 9625947666256011567U;
            aOrbiterF = (aWandererI + RotL64(aCross, 57U)) + 1703669290934254701U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 34U)) + 6664070663184147951U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 2104148316797553431U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1197910004222596145U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9922977170060903197U;
            aOrbiterJ = RotL64((aOrbiterJ * 13047828062605568603U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2048376210852567829U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12568990647075931409U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9860242601194210927U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15026894775772902751U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3439447160137900629U;
            aOrbiterK = RotL64((aOrbiterK * 1813754963043785165U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6532671388552829796U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17261098369835997661U;
            aOrbiterD = RotL64((aOrbiterD * 568292591215203521U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3171300991007459947U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5935563269327662024U;
            aOrbiterI = RotL64((aOrbiterI * 11271790283157765003U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14290941734320455612U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12371794745736518824U;
            aOrbiterH = RotL64((aOrbiterH * 12208762336145168647U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8782840145467637373U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4067525421190366741U;
            aOrbiterG = RotL64((aOrbiterG * 6671002797916227485U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11854812920571789853U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17564890418553131451U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16657184504366731805U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6250004085193517531U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2362659992682660827U;
            aOrbiterC = RotL64((aOrbiterC * 4365619310373869859U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4597159873252831182U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13197238269207675773U;
            aOrbiterF = RotL64((aOrbiterF * 379653377172816575U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8552479493772820372U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12046647397183218524U;
            aOrbiterA = RotL64((aOrbiterA * 17918033655125400323U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 56U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterI, 21U));
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 12U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 48U) + aOrbiterA) + RotL64(aOrbiterF, 41U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 50U) + aOrbiterF) + RotL64(aOrbiterB, 18U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 268U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 202U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7087U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1063U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1184U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 769U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 51U)) ^ (RotL64(aCross, 10U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 3U)) + 13687218104610230596U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 6841550124960692709U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 17418968668458764131U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 36U)) + RotL64(aCarry, 11U)) + 8303537912696948204U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 23U)) + 12376614417285936537U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14215749063579232654U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4111736931433665347U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8841288213954433049U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11250375934571631522U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5367367837773331275U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7262723007545807179U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15514089192382674434U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1475991716685034960U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17720681295551650891U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5531622777788629748U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8363822215908303335U;
            aOrbiterE = RotL64((aOrbiterE * 17850203366840994883U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3741256932685720414U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11634667238062155772U;
            aOrbiterK = RotL64((aOrbiterK * 15925089729784547403U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 30U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 50U)) + aOrbiterC) + aPhaseGWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 37U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + aPhaseGWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8627U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 8824U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 15109U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16081U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11048U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 14059U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 44U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 2558105147674438050U) + aPhaseGOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 27U)) + 15856662514774702561U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 13346869226246584582U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 53U)) + 7632111846116243973U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 35U)) + 2102101361626976279U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5605968705067851563U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6842483186584326681U;
            aOrbiterJ = RotL64((aOrbiterJ * 11344798544990575365U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5559797213819425064U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12422313931331576759U;
            aOrbiterK = RotL64((aOrbiterK * 7399849122565913401U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2751024420047872601U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11031320239359798610U;
            aOrbiterG = RotL64((aOrbiterG * 8607639453141148025U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14366375309473793217U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11971479429768505316U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10063001532313098203U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3947595951884469542U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17882767922372770896U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3361906348965810211U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterK, 58U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + aPhaseGWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23599U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 22192U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22187U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18553U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19698U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18452U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 52U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererI + RotL64(aScatter, 58U)) + 5721224134332887360U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 6892749729775049095U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 3884839462099556836U) + aPhaseGOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 4365431706830216193U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 5U)) + 15501528746571578773U) + aPhaseGOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4505911326320650606U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1865129050927879580U;
            aOrbiterH = RotL64((aOrbiterH * 9198152644404068721U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2011737665969640369U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 611672935827062688U;
            aOrbiterJ = RotL64((aOrbiterJ * 12873671551304596619U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 663547038310431047U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5468932264754299556U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11968657455484578525U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17920294117231191705U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 486058453837528110U;
            aOrbiterB = RotL64((aOrbiterB * 8851102552244026737U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2789178451938129313U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 420772587981211184U;
            aOrbiterI = RotL64((aOrbiterI * 17402987842294006667U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 6U) + aOrbiterH) + RotL64(aOrbiterA, 5U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 44U));
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterB, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27783U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 32735U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29386U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26341U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32167U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 30232U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aCross, 35U)) + 4476099022490972343U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 16836423700375760429U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 46U)) + RotL64(aCarry, 13U)) + 8850577488928703557U) + aPhaseGOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 7091631824560042743U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 3U)) + 12560498899956759494U) + aPhaseGOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7797973377112012161U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6173820673874805794U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15741300047917486527U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10805025132310245348U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7139216143268029968U;
            aOrbiterA = RotL64((aOrbiterA * 8349754682635765573U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8241544862261635722U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4735527016563596150U;
            aOrbiterB = RotL64((aOrbiterB * 6621354217673598381U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5166171126690294033U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11117641762075368393U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4980156869201219393U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6312932356458415421U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1304139291184508668U;
            aOrbiterC = RotL64((aOrbiterC * 90744653170922319U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 5U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterK, 28U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7663U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 222U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 469U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1062U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7050U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 1009U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 6U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 7825479804710770560U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 5298124167101358123U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 57U)) + 17774541024369233726U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 23U)) + 7679371833537454082U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 3U)) + 5385914900748772224U) + aPhaseHOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3879781930908486531U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 659110346638873236U;
            aOrbiterE = RotL64((aOrbiterE * 17439162088869824407U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10749021728538539749U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3631252455767429457U;
            aOrbiterH = RotL64((aOrbiterH * 8552825360915119613U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2271978810960685021U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5963558780692551176U;
            aOrbiterF = RotL64((aOrbiterF * 4772055335210781149U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 974909966119198104U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9296998242911152296U;
            aOrbiterK = RotL64((aOrbiterK * 2613629915877957661U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2245318466901521959U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13391076374843288568U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18094558036982107419U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 4U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterE, 39U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterH, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8208U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 12702U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9952U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12941U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15771U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9115U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 30U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 9751314027302668907U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 5U)) + 12175450995523107056U) + aPhaseHOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 19U)) + 17519694958730119552U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 21U)) + 9093525527925682263U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 3713831321786810138U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10108355209191835040U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12956307447311314768U;
            aOrbiterH = RotL64((aOrbiterH * 9198936928658626667U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1904298513945877359U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4658049993308574460U;
            aOrbiterC = RotL64((aOrbiterC * 10482422152074338611U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9826333658248851902U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12058666914724365134U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 964233873188373939U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2516574707110528099U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13335308331049750235U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8230749255538495304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16536559486797811486U;
            aOrbiterK = RotL64((aOrbiterK * 7097036838156464969U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 54U) + RotL64(aOrbiterA, 13U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterC, 4U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + aPhaseHWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22228U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 18095U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 18188U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19313U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16693U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 23321U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 21U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererC + RotL64(aIngress, 5U)) + 12046647397183218524U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 2760779375026461991U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 13735454443176855650U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 4370377000586647724U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 44U)) + 14566322384189969094U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5056565959818422786U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8795403810686579209U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11205867337479457471U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9625947666256011567U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1703669290934254701U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5763881345676123583U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6664070663184147951U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2104148316797553431U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12887842067180975983U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1197910004222596145U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9922977170060903197U;
            aOrbiterG = RotL64((aOrbiterG * 13047828062605568603U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2048376210852567829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12568990647075931409U;
            aOrbiterC = RotL64((aOrbiterC * 9860242601194210927U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterC, 18U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 56U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30487U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 31874U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25465U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27870U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32434U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 32483U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 52U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 54U)) + RotL64(aCarry, 39U)) + 7651355040951791298U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 13988210277931659312U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 29U)) + 9846849412579537783U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 12746719939495876158U) + aPhaseHOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 21U)) + 11498066185182895284U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11101058955193080232U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15513734459555672046U;
            aOrbiterC = RotL64((aOrbiterC * 6974281215677538561U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15711108675349394643U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4771231759949468556U;
            aOrbiterI = RotL64((aOrbiterI * 9806191054594333615U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11449258010811305256U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17036938391509986723U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7411466953205347639U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6999245666776654250U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2106819066263369528U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13005885810757743129U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12716183358903477216U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16752724547046059889U;
            aOrbiterD = RotL64((aOrbiterD * 11475905692393034141U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterC, 24U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
