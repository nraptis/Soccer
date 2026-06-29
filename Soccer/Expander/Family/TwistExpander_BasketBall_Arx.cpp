#include "TwistExpander_BasketBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_BasketBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9B67744C51AC47F9ULL + 0xD1882FDBA91BC019ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF98F05CCFF1DCAEDULL + 0xB50B037E920986D1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8A8520BF4BC65A99ULL + 0xB6E93F19A2908706ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD6AE2AFCAFD2E789ULL + 0xAE1B3228E77160F6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB942B10E0473612BULL + 0xE2F8609490C7DF5EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB0FBB67FCD6CC767ULL + 0xF3DE126568E54CD9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD8AEE27B1FDFD36DULL + 0x8D17F54F9090DBFFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE583AFE45662B185ULL + 0xD80C77E766BD270BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x82EDC18B8567C0FFULL + 0xCAEE673207F27288ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFC7D79CA67609C63ULL + 0xF65913B58E90319FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA148522631CC1B81ULL + 0xBAD4199842F02FB4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC2AC688E40CB2227ULL + 0xB1CCB5118276E578ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBF80DDD00A094E91ULL + 0x9AA728CC8B607AF6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x898F7ADB43723967ULL + 0xB06CEE2485C8129EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8A247876611C060FULL + 0x9A7FCC0CB4C800AFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAFF998589BE0C0F9ULL + 0xE6C6AB91699DED5FULL);
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
            aIngress = RotL64(mSource[((aIndex + 4433U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((aIndex + 1405U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 966U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 54U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 13U)) + 4739486756133131180U) + aNonceWordI;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 16089707555501328184U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 50U)) + RotL64(aCarry, 43U)) + 15310047330238536453U;
            aOrbiterI = (aWandererF + RotL64(aCross, 21U)) + 7901411596386834955U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 43U)) + 4357555491060982163U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 15667085602825720102U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 23U)) + 8520635334382269253U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 27U)) + 1772509779231068315U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 11U)) + 15336170957886025677U) + aNonceWordJ;
            aOrbiterK = (aWandererE + RotL64(aScatter, 18U)) + 8628770833489469980U;
            aOrbiterG = (aWandererK + RotL64(aCross, 47U)) + 15469234024247246228U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10796430900884288328U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10660110397012853289U;
            aOrbiterA = RotL64((aOrbiterA * 9140007610912037461U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11202284258711214794U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17509491802893182994U;
            aOrbiterF = RotL64((aOrbiterF * 9329107599972703671U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16212572740740103554U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2190030203761579226U;
            aOrbiterD = RotL64((aOrbiterD * 3101886685668871045U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12014337082293041909U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3733531010807001506U;
            aOrbiterE = RotL64((aOrbiterE * 5797362244066062299U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7100994963061975529U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17837541162838600258U;
            aOrbiterI = RotL64((aOrbiterI * 8745987361678166553U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3311518938023146951U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7709505172646831553U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 7121143171245765213U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4979968094554018443U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16822214821463034107U;
            aOrbiterK = RotL64((aOrbiterK * 8618262120451291765U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8376124175020587079U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11084586282092424876U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5835632742522563537U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7816368455027681621U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10893292019060642422U;
            aOrbiterC = RotL64((aOrbiterC * 3995821210667317677U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13602875505184178486U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5425735673005681983U;
            aOrbiterJ = RotL64((aOrbiterJ * 12667085597129312079U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 5995385043278810987U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4739486756133131180U;
            aOrbiterH = RotL64((aOrbiterH * 15709273328685013399U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 54U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterG, 42U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 19U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 28U) + RotL64(aOrbiterC, 23U)) + aOrbiterE) + aNonceWordG) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterH, 27U));
            aWandererH = aWandererH + ((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 21U));
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aScatter, 52U) + RotL64(aOrbiterE, 14U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 10514U)) & S_BLOCK1], 52U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 8322U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7043U)) & S_BLOCK1], 24U) ^ RotL64(mSource[((aIndex + 7325U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 58U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (aWandererE + RotL64(aPrevious, 57U)) + 1898718075389870739U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 43U)) + 5631794889237247403U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 18219714659484524607U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aScatter, 37U)) + 15419581386225732921U) + aNonceWordH;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 53U)) + 9125575431710198210U) + aNonceWordN;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 12205871520544965505U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 11U)) + 7617534300497343422U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 23U)) + 18017579105368135814U) + aNonceWordB;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 6U)) + 10693882161946020042U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 39U)) + 11669615701700895306U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 19U)) + 11045110212889232165U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18019107802806469913U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12315940560472528716U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4505122470351404065U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4899009736070044310U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17412253404253730364U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 10791901166391946485U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4826286251927854181U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4523455921321845084U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14534103906736598099U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4132514462154182215U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7164745605985109269U;
            aOrbiterK = RotL64((aOrbiterK * 14107325508977225261U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6297434295807635654U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8813887638672996646U;
            aOrbiterE = RotL64((aOrbiterE * 17495632530773158201U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11086381278955626084U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5660733992573928887U;
            aOrbiterH = RotL64((aOrbiterH * 11248164458720777889U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14851044686208609882U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12707776386060264479U;
            aOrbiterI = RotL64((aOrbiterI * 4470919091467313071U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11508023384209716657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11752973809740920034U;
            aOrbiterA = RotL64((aOrbiterA * 10212754472298834769U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16746821150860017820U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9659421716296641396U;
            aOrbiterD = RotL64((aOrbiterD * 7530071874978553673U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3192309064305104593U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11409078048681398061U;
            aOrbiterF = RotL64((aOrbiterF * 14991409124701807765U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 315359495275427324U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1898718075389870739U;
            aOrbiterB = RotL64((aOrbiterB * 13126661894614781343U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 51U)) + aOrbiterC) + aNonceWordK);
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterE, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterB, 42U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterI, 27U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterD, 44U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterA, 37U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 11389U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 16122U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14885U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((aIndex + 15392U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aIngress, 27U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 4259993311776766595U) + aNonceWordA;
            aOrbiterC = (aWandererE + RotL64(aScatter, 51U)) + 2857813330021126753U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 1345396841329442896U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 320992148982301024U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 56U)) + 5619109532065293074U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 35U)) + 10380157329426706345U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 29U)) + 12449831150625409695U) + aNonceWordM;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 41U)) + 7847096607042268396U) + aNonceWordI;
            aOrbiterF = (aWandererB + RotL64(aCross, 21U)) + 11707184096803214678U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 54U)) + 9893643746186827088U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 3U)) + 333687403830908774U) + aNonceWordJ;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13837360705077441580U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4367119682175710689U;
            aOrbiterD = RotL64((aOrbiterD * 10295744669174603401U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1193493435041306784U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15062951612027370606U;
            aOrbiterH = RotL64((aOrbiterH * 2509383510565136549U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16000173839235429105U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15294482444605409961U;
            aOrbiterI = RotL64((aOrbiterI * 1031800997944302665U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5720749055549773527U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17248674962996093668U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15730637462755795591U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16956840483882091059U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9637715107943515594U;
            aOrbiterE = RotL64((aOrbiterE * 8878362378343603463U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7147495779349862274U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7508890985889484275U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 17728368447504622035U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4407738164617959366U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17027017782352660454U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 417183060881259295U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3174658601748235285U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9779053567370714831U;
            aOrbiterK = RotL64((aOrbiterK * 6383245776181968033U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16256981360027888091U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12778335633397105924U;
            aOrbiterA = RotL64((aOrbiterA * 10821225965811763659U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13985909343937844583U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14307218309393008729U;
            aOrbiterJ = RotL64((aOrbiterJ * 12053366452617039877U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15549857305890093491U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4259993311776766595U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 13703695714360435719U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 40U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 11U)) + aOrbiterC) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 57U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21184U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((aIndex + 18087U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18949U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 18981U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneB[((aIndex + 17159U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (aWandererI + RotL64(aScatter, 23U)) + 5160910997561396461U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 3U)) + 14920764751058512062U) + aNonceWordE;
            aOrbiterD = (aWandererB + RotL64(aCross, 11U)) + 6080952401749660022U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 60U)) + 17667234330526298627U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 760630072638686756U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 3504157162816997476U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 51U)) + 9489022223422585882U) + aNonceWordJ;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 21U)) + 1149898536879968964U) + aNonceWordL;
            aOrbiterK = (aWandererF + RotL64(aIngress, 54U)) + 10492284328940025310U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 13213275606286399312U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 47U)) + 10557118912847180413U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15618980209023994776U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 5268600749854045564U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3849660559223919613U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8011552687609649990U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3148133096349525066U;
            aOrbiterC = RotL64((aOrbiterC * 5245156554959620007U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12032847944237867285U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14999005703490824673U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 6631584955208646049U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5426735969392906710U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3593177531650386729U;
            aOrbiterJ = RotL64((aOrbiterJ * 12997284886192717043U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1701444719333347373U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15928731228196894960U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1919318226904213433U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5960179456039157036U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5716434224061596483U;
            aOrbiterF = RotL64((aOrbiterF * 3731976564761202801U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2136841536293340279U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12969550408652728526U;
            aOrbiterH = RotL64((aOrbiterH * 7612191387451455137U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3641997570461447114U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4677572491523684525U;
            aOrbiterB = RotL64((aOrbiterB * 2730358077882211651U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2741372094325164504U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4998631511811832690U;
            aOrbiterE = RotL64((aOrbiterE * 10619395395977372695U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6260464862798783617U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16489087874167346533U;
            aOrbiterG = RotL64((aOrbiterG * 11278053967185244867U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 7043760915859224327U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5160910997561396461U;
            aOrbiterI = RotL64((aOrbiterI * 15260149870590431675U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 28U) + aOrbiterI) + RotL64(aOrbiterA, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + aNonceWordN);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterI, 58U)) + aOrbiterJ) + aNonceWordB) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterG, 35U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 26U)) + aOrbiterF) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22174U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 24522U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25753U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25331U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25970U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 24279U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 39U)) + 966899917801652720U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 41U)) + 10996327672320748649U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 51U)) + 4188171566846621107U) + aNonceWordN;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 22U)) + 5886209243097387959U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 14940428957136728111U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 3U)) + 179187285531914832U) + aNonceWordB;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 6685351948936817752U) + aNonceWordI;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 57U)) + 1894506461704029700U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 4182760368636977082U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 6U)) + 12523318028514940790U) + aNonceWordE;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 27U)) + 5059306166973366892U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5890872367917643851U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17747338389865221534U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5306740664798049267U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13906227834259884100U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7152105382899756368U;
            aOrbiterE = RotL64((aOrbiterE * 6772157117358310485U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17868101884759619240U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11758843266314148347U;
            aOrbiterA = RotL64((aOrbiterA * 5919135169337501485U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13950566197090324859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17278105609930477854U;
            aOrbiterG = RotL64((aOrbiterG * 11431842718945107359U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9556785965646738355U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 841298436857932987U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15077843186688841797U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1951515285492133830U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15775839819330588437U;
            aOrbiterH = RotL64((aOrbiterH * 7902654031401620995U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5585458468816495436U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17258586689032223623U;
            aOrbiterF = RotL64((aOrbiterF * 1652050227399194271U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5254132659445988836U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15440741734777060925U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17445581079035134067U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16770361602586485631U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14902616717976301965U;
            aOrbiterK = RotL64((aOrbiterK * 7757713071544143453U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 9521517757370835715U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 18241677917767801049U;
            aOrbiterD = RotL64((aOrbiterD * 16977396965907931057U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14307634663160859644U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 966899917801652720U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 17012361848398765251U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 22U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterH, 58U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterH, 4U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterK, 39U)) + aNonceWordA);
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 21U)) + aOrbiterD) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 46U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27731U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 32754U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31911U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32382U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30538U)) & S_BLOCK1], 28U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 31750U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 32119U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 2177539223979303669U) + aNonceWordK;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 46U)) + 3962004686551521471U) + aNonceWordB;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 8457602312617147662U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 5U)) + 18011802451816510632U) + aNonceWordC;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 35U)) + 9046101759168876832U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 21U)) + 11135620637431969597U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 57U)) + 15913029940697999701U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 43U)) + 16304193109948135982U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 19U)) + 13208892298820080981U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 10U)) + 4182377898949419225U) + aNonceWordN;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 13970137023071326151U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8402396284835248583U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8859190834060657829U;
            aOrbiterJ = RotL64((aOrbiterJ * 13552418608113716117U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9760005337757990392U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14108277760135744897U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 4474681104256093885U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12226316121949012350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3456392186754113960U;
            aOrbiterF = RotL64((aOrbiterF * 8704729827929941215U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5004087958637038973U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7176881295123125567U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 15272157962928021009U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10889800478505074438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13728832441482547824U;
            aOrbiterB = RotL64((aOrbiterB * 17588477761978646139U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17345665880706866772U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 301139993853297566U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5812445396758354505U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2061389844760610160U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13631862266139238355U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 143613352104722701U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10767186080827509622U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4893486019456886013U;
            aOrbiterG = RotL64((aOrbiterG * 5194746459545610901U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11264795916303477037U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16013652139405432608U;
            aOrbiterI = RotL64((aOrbiterI * 14924257021089920495U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5209743554932653849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13160179712987277456U;
            aOrbiterE = RotL64((aOrbiterE * 5003755912040281427U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12440615920191945386U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2177539223979303669U;
            aOrbiterD = RotL64((aOrbiterD * 3565122523239344029U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 20U)) + aOrbiterD) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterK, 34U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 42U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_BasketBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA5B7B8FF1917881BULL + 0xFF6031EFA3990E59ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x89A615AC1691EC39ULL + 0xAE8BF0DCE92CC567ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC136DA65D54C405DULL + 0xA971C3A4750A3AC1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEFA1741B77243963ULL + 0xCDFB9283040AB401ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCF73A05622965547ULL + 0xC96A52169150FD63ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA604AD1977E3B5DDULL + 0xBADFB2FF321F700AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBE1C3C3A06ACC251ULL + 0xA8A6C2CA0E7054FAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8F64E0811BF80DDFULL + 0xD66B24B7493FB3A8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF01F7CCE13564161ULL + 0xFBA091B1BF9D1525ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEE4D93CF6F2AFEBBULL + 0x904740F4713D0F2EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBFC13F31E56B49A3ULL + 0xAEFD43E7D9C3387DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA7A89892908BFC3BULL + 0xA5FC7D4A96602F6CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE3EAD3518DE9746DULL + 0x8557AE66AB715B5AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9C28FD78F00F7CD9ULL + 0xC372A8060A51E26AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEB9B4A27A419E2EFULL + 0x9CFA7DDFC478C7CCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC2D76F1F130C2D49ULL + 0xCB87E561D49F288CULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 2760U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2836U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4218U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 2369U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 3U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 30U)) + 4634399531433127141U) + aNonceWordL;
            aOrbiterE = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 16961792729406903200U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 3U)) + 4105280732301137738U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 13U)) + 15692013501147331191U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 53U)) + 1252216715968780587U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 21U)) + 7958289043012473752U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 43U)) + 6611577301818896615U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 8506226754305949140U) + aNonceWordA;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 3648813120449403353U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5195245426245535735U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 542948051600803051U;
            aOrbiterB = RotL64((aOrbiterB * 4631106308856448475U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11974253551208964789U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10596463592332655367U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10941161258815714641U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12015129484061440159U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8254944355710109060U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 3233697992479357615U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2754858806943915419U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5007802002906662779U;
            aOrbiterI = RotL64((aOrbiterI * 15613733948331639723U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6262190752136523216U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10528977986487821428U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1184258264034585525U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8511097226098211854U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12091864735686692582U;
            aOrbiterE = RotL64((aOrbiterE * 6128140528141411237U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4970966265236842566U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10728884018459718341U;
            aOrbiterA = RotL64((aOrbiterA * 18205183219769602827U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13760057185629905360U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6590269178744829056U;
            aOrbiterH = RotL64((aOrbiterH * 14482684769712170123U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 765826377665103262U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9364759196106579706U;
            aOrbiterD = RotL64((aOrbiterD * 10315111163659289329U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 26U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterH, 24U));
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 52U) + aOrbiterH) + RotL64(aOrbiterK, 58U));
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 5616U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 9778U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8159U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8654U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 7151U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 20U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = (((aWandererK + RotL64(aScatter, 4U)) + 18319689184146942855U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 47U)) + 8041304130090501019U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 23U)) + 11347064191990897738U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 43U)) + 15242243470024447468U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 39U)) + 10619749107163611105U) + aNonceWordD;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 18U)) + RotL64(aCarry, 51U)) + 14795614276221947128U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 1578095288886372393U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 13593906305770501684U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 35U)) + 8919815528334599172U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17425548324720065145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11125018338392347335U;
            aOrbiterD = RotL64((aOrbiterD * 4377887040461528587U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3779189180734244399U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10958224663276134041U;
            aOrbiterH = RotL64((aOrbiterH * 6206963519509783781U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4317305352561612995U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4891139433808505355U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11507024985663120317U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5166074784835930965U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10080890270621589202U;
            aOrbiterG = RotL64((aOrbiterG * 13170894418184288695U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4501071771615514619U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6486573807774431753U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 324029625116648669U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15714881857668975753U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3506619392820235900U;
            aOrbiterE = RotL64((aOrbiterE * 5707033870161224499U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5295711072762443783U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11192836530396570648U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 4361810118382207039U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7993389678399774574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12551394763541226695U;
            aOrbiterI = RotL64((aOrbiterI * 11903486656172026403U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11553674370322129668U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4459881583199320245U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 2805857426321555685U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 41U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 6U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 4U)) + aOrbiterE) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 46U)) + aOrbiterD) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11373U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 14842U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 13779U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11806U)) & S_BLOCK1], 18U) ^ RotL64(aFireLaneC[((aIndex + 16331U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 53U)) + 4384716820085860551U;
            aOrbiterC = (aWandererH + RotL64(aCross, 40U)) + 9715780315942116888U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 15963520052789178632U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 21U)) + 14346700690686392938U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 3U)) + 6005518012489966643U) + aNonceWordC;
            aOrbiterG = ((((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 2506732930310252119U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererG + RotL64(aCross, 11U)) + 16782163084851775826U) + aNonceWordO;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 823673076571076303U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 48U)) + 1634084509064077736U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1288134975466877686U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2998220403162908444U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4321412662318298283U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 220430672180734911U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10223923547068528867U;
            aOrbiterF = RotL64((aOrbiterF * 12577370238343872139U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11696469696177647608U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6545430420379636963U;
            aOrbiterI = RotL64((aOrbiterI * 8387163146257553773U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 79691451831797107U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8971444023498649419U;
            aOrbiterK = RotL64((aOrbiterK * 7148919880477390009U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5624403902454498793U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9468064161002030997U;
            aOrbiterA = RotL64((aOrbiterA * 8243560528100864595U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4619361544913629805U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12682446273369750704U;
            aOrbiterJ = RotL64((aOrbiterJ * 10879074713156075641U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8728730962617599223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9099675924074253030U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5525644236954497523U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3298303921318288541U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5953276499411658358U;
            aOrbiterE = RotL64((aOrbiterE * 10565471305001292693U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6725769507592688539U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1057277456510215817U;
            aOrbiterG = RotL64((aOrbiterG * 8269412198279297075U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 20U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 48U)) + aOrbiterC) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            aWandererD = aWandererD + ((RotL64(aIngress, 30U) + RotL64(aOrbiterG, 44U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17105U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 16861U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 17793U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20582U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18540U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 35U)) + 3236820517816085022U) + aNonceWordL;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 50U)) + RotL64(aCarry, 37U)) + 741288875914097926U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 8417246926007729580U) + aNonceWordA;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 39U)) + 9715717805774537170U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 27U)) + 14360243844821619482U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 10760908100206775334U) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 23U)) + 3434641779946167811U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 43U)) + 7885568822756234567U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aWandererF + RotL64(aScatter, 12U)) + 3041563437672051294U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15761355327564963516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1158633562785937421U;
            aOrbiterH = RotL64((aOrbiterH * 15511324886867188235U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9338581575871970653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9172038894262857354U;
            aOrbiterF = RotL64((aOrbiterF * 3110871165285625807U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14653924713599790081U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3854497592598563309U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 11737111068815795303U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16286980180327600557U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5092583772591249756U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 13955105624639442903U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4288397994175567333U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15584236478994873104U;
            aOrbiterJ = RotL64((aOrbiterJ * 1860480595862755379U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5557463939827483792U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2659814275753280856U;
            aOrbiterB = RotL64((aOrbiterB * 17702430405693184643U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6941807963525063449U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2040598555191211307U;
            aOrbiterG = RotL64((aOrbiterG * 14750544987531722765U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 347572666231116258U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 779304821185302523U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14180254150318109855U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10632524582873079742U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9761308771280517212U;
            aOrbiterC = RotL64((aOrbiterC * 13926235411726048921U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterA, 6U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 56U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 24172U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneD[((aIndex + 22321U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25932U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22979U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 23U)) + 2786079456995203065U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 35U)) + 7237256119153857253U) + aNonceWordA;
            aOrbiterG = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 9310834010563647604U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 30U)) + RotL64(aCarry, 37U)) + 17361734905706517877U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 15837111231884647451U) + aNonceWordB;
            aOrbiterA = ((aWandererA + RotL64(aCross, 19U)) + 18065431964418026445U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 51U)) + 3029123922999952652U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 60U)) + 5166926595573507837U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererG + RotL64(aScatter, 43U)) + 1918425684273807598U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4724551751012661440U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1818014487579644390U;
            aOrbiterG = RotL64((aOrbiterG * 14904092108647864911U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6670090372241084216U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8485757110007268693U;
            aOrbiterJ = RotL64((aOrbiterJ * 11876760095108618363U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4928130251509514742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2528788422725346792U;
            aOrbiterA = RotL64((aOrbiterA * 1855982047967756661U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2860387120895147503U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 12927802338151379368U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 8876144125458603029U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18029699867733207083U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 13361836994951253312U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5349767426256597073U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11957294454794128079U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3755417922063414648U;
            aOrbiterK = RotL64((aOrbiterK * 13896364063651241401U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18001157153447913032U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16214145724690286854U;
            aOrbiterI = RotL64((aOrbiterI * 5874139687703360515U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3860958772090975562U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12395621524459640173U;
            aOrbiterF = RotL64((aOrbiterF * 722817135977510161U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3402035664910754484U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2139099117325745602U;
            aOrbiterC = RotL64((aOrbiterC * 14008983756425796029U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + aNonceWordH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterA, 52U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterK, 43U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 20U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 30944U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27820U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27569U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28636U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (aWandererF + RotL64(aCross, 58U)) + 11410829607777684449U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 35U)) + 7502698839700975347U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 11U)) + 13267685058252106173U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 238242706996630625U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 54U)) + 8184695499511454281U) + aNonceWordA;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 12767823220461985403U) + aNonceWordP;
            aOrbiterC = (aWandererG + RotL64(aCross, 27U)) + 12293198423143850330U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 47U)) + 11149495229952495939U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 7556992689338382800U) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3431338808774134649U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16863099140844995099U;
            aOrbiterH = RotL64((aOrbiterH * 752376661101787919U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17872458049880677604U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16760153457252546974U;
            aOrbiterI = RotL64((aOrbiterI * 11225037229069712805U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3115544493537438408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4359882942759752958U;
            aOrbiterA = RotL64((aOrbiterA * 561477566995575801U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13387113067202396536U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12955690074544490161U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 12449941770827974511U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15614054443728226807U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1939441328066616114U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4484917074808974359U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4599016263007782537U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9962305629016158048U;
            aOrbiterJ = RotL64((aOrbiterJ * 1496184427500037279U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8428467674122750557U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3938884087806393439U;
            aOrbiterB = RotL64((aOrbiterB * 12810531094050481761U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6018636830758044658U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1510372000641305416U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9002834928626918247U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17592782466215337843U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8119921507606870360U;
            aOrbiterC = RotL64((aOrbiterC * 1299795061644535485U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 26U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterF, 10U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterH, 19U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 13U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 23U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 50U)) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_BasketBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF633E34050CA3F5DULL + 0xB1286F02ECB779E8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF7AC98660E148D79ULL + 0xBF26BC942855FB1BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE68457CB49153061ULL + 0xFAF6213D31B14307ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x88E7A37F161901B1ULL + 0x8667AA534A088A1CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAA7966D0EB84062DULL + 0xEF7C5CC541463221ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xED51A5F85BBDC107ULL + 0xAE73CFB8985B064DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCD504C79BEA78049ULL + 0xDF10599E3F20C170ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBEC1A2CA7D3CF223ULL + 0xC11E50C974919E13ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFB2EF61F2A6435B3ULL + 0xA3202CEA7156C9F9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCBD06FCD2E771029ULL + 0xCCD8172EC014E1D3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xECCE2E167FD0295FULL + 0xE47BDAFF6D65E77EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE752160D24792E49ULL + 0xE9219D7698119305ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC5E348F58D7738A9ULL + 0xE6A1D3BAECF6D8EBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x85826B465EAEFFFFULL + 0xB46A61E3EC21A728ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x82C4CDA97902CF23ULL + 0xEE80C3022808A1A7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xADB4826C29947FE3ULL + 0xF5CCF8F48EFBA3DBULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7492U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 4158U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5737U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7229U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1424U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6952U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 11U)) + 15920462086654025436U) + aNonceWordB;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 487844076858004017U;
            aOrbiterJ = ((((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 14502883786442630566U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 21U)) + 3787107318658233674U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 56U)) + RotL64(aCarry, 19U)) + 12548777544693755491U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4907309444075181683U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18342396700266492072U;
            aOrbiterJ = RotL64((aOrbiterJ * 14842961036061482089U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13503051997624242670U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17845742460521374571U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1366356786138085155U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 8640887211877858169U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5273913123709097537U;
            aOrbiterI = RotL64((aOrbiterI * 1661149444148461791U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17756844173695563883U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6713055830729302951U;
            aOrbiterG = RotL64((aOrbiterG * 2832836748513174311U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5106468334224035972U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10228769728713526172U;
            aOrbiterH = RotL64((aOrbiterH * 9760310686414358435U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 6U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 56U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12135U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 10433U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13570U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((aIndex + 16250U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9920U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8327U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15626U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 58U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 17225673071833726819U) + aNonceWordJ;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 23U)) + 10301458382103627331U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 58U)) + 3960233050857362414U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 17768665685046605837U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 14471018461213959767U) + aNonceWordA;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 10730597892721340453U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14863394003122760542U;
            aOrbiterI = RotL64((aOrbiterI * 17731557030589257169U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9948587274816688296U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3573569431435100993U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2303922230056523077U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8153670675740450590U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16438856577722561424U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 4689247488336908827U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15765587867581925041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1082039522061775213U;
            aOrbiterH = RotL64((aOrbiterH * 17023740047246402641U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4202521649260798876U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15877659681260461141U;
            aOrbiterD = RotL64((aOrbiterD * 11369910758551088173U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 40U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 50U) + aOrbiterB) + RotL64(aOrbiterI, 11U)) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 22U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24342U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 17619U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 19575U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 21088U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21746U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20832U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 18674U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 15036852811491820366U) + aNonceWordO;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 305637140752898475U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 37U)) + 11948631574496129610U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 5321623592482991426U) + aNonceWordE;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 47U)) + 4075270159062690728U) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15111580500356908928U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7244150695504160363U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2445733898697939969U), 51U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 5131563519577488862U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5881954992088651371U;
            aOrbiterC = RotL64((aOrbiterC * 2424421828597294607U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12780935808751507998U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12599159643925470226U;
            aOrbiterE = RotL64((aOrbiterE * 17690046932587062701U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9466589929741834066U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6093158735705189789U;
            aOrbiterK = RotL64((aOrbiterK * 7453778295800853653U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17461243886150519249U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 15456408913739900718U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 16093292401746174671U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 5U)) + aOrbiterE) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterE, 24U)) + aNonceWordF) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 22U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + aNonceWordL);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 35U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26722U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 27089U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 31750U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27554U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26027U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26284U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28449U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 50U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 13650869943246163567U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 3435284932011770999U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aWandererC + RotL64(aIngress, 46U)) + 12388155658186776579U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 2374345913955712039U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 21U)) + 6095094526980292156U) + aNonceWordP;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4965147025852444174U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3261881216269075298U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4874733445914960785U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4939780217097329222U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3019862009792676287U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 2452316208025448747U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 901910626217143974U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3647055146712366383U;
            aOrbiterC = RotL64((aOrbiterC * 1792602402476450009U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7731765438957392967U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 13409819457393479741U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 3345078200262410715U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 5415832109107794258U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8876738832313114471U;
            aOrbiterB = RotL64((aOrbiterB * 1304277600444504135U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 4U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 54U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 27U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 57U)) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_BasketBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCE4FCF2A005CDAC3ULL + 0xD58F7F4DE1A5938FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB7AF459CB7735DE9ULL + 0x9C53BB30B785A18AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF3AE354EDC8C4813ULL + 0xAE995CC28701AC5EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBA3ACEB4C9B1C899ULL + 0x959A753B56FC8269ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9068C3D5B5F0CB75ULL + 0xF229A39595E28C95ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x968875CCCE73F075ULL + 0xBFC61687462C80F4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA3C1B15107A0F81BULL + 0x8F5B290ED6495723ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCF1929CB7ABA972FULL + 0xB18E0A83E31BB519ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCFF297479D3850A5ULL + 0xC7FF83BC1871DF80ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF57D92B367D814EBULL + 0xA3CA89510F8DE30FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEB08443FA0DC0C4BULL + 0xA4B79480BA608E1EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8B7724E9CBDF658FULL + 0xA69AEAD12C9F876FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC1EAE371D75C0AB5ULL + 0xBCA572A73E3DF602ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x967CA83D3AF86AB1ULL + 0xBE4AE3C860C23F6CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA38C020EC37E4939ULL + 0xB0CFAECCB092C58EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x99A75211F4F634B9ULL + 0xD3F5998906A08036ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7963U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 6498U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2227U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2433U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7855U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2523U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 26U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 9471546960258473684U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 18050235435948942244U) + aNonceWordL;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 3U)) + 3005107102671544641U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 11U)) + 17898396434573801850U) + aNonceWordE;
            aOrbiterH = (aWandererH + RotL64(aScatter, 46U)) + 15071602525497771648U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 19U)) + 5780119462702672108U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 13301326224151025687U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 18129323022260575961U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1199228670638790709U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1780426336211781025U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 1839199978088021020U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4999517042246790165U;
            aOrbiterH = RotL64((aOrbiterH * 4585813675677234577U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8788607633376516299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15143903839930468749U;
            aOrbiterA = RotL64((aOrbiterA * 12735914889325422675U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16674732686428431869U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15908873150953195581U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18049755517524334107U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11204775359756474667U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2525984309543939465U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 3988529812023791571U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4566345170476825512U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14876612901557406267U;
            aOrbiterC = RotL64((aOrbiterC * 9047956948845135339U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14926290877038883931U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12710203178186614846U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 14841163494801662515U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterC, 60U)) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterF, 37U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterD, 43U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15847U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 13930U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 13916U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((aIndex + 9045U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9551U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14889U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14927U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = (((aWandererA + RotL64(aScatter, 35U)) + 1297415699043177788U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 58U)) + 17583786534509260153U) + aNonceWordD;
            aOrbiterI = (aWandererE + RotL64(aIngress, 19U)) + 643197858925708798U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 27U)) + 5062653766915694874U) + aNonceWordP;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 7034273638367180511U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 2026909726972916996U) + aNonceWordN;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 2785690475553211646U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2910341716302991892U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2834181605200829791U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1510617068750957651U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13323052600571281928U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 10434901530315760460U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 2042210188346767033U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 247903955625194782U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5196515747387257163U;
            aOrbiterB = RotL64((aOrbiterB * 1799024689023272275U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7196305682377987476U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14777739876892587484U;
            aOrbiterG = RotL64((aOrbiterG * 95220583948241581U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10609060796540136671U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8386027207212484155U;
            aOrbiterH = RotL64((aOrbiterH * 4855610536246556893U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 729659744301903424U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2350564261412606157U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16713856782349084977U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16611987556673864177U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1525195188708550503U;
            aOrbiterD = RotL64((aOrbiterD * 10045858602151004553U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterD, 21U)) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterB, 37U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 13U)) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterG, 29U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16836U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 18212U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17998U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 20289U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16592U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21420U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17775U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (aWandererC + RotL64(aPrevious, 19U)) + 16124889768301047791U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 11912338587186717280U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 30U)) + RotL64(aCarry, 35U)) + 8594012868813114354U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 43U)) + 18281043566156682815U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 5U)) + 16853106130200942302U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 57U)) + 2611212958619673086U) + aNonceWordG;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 18039472325066855180U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14495785571345122046U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4556063793412832418U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13166927543135467627U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14896419970271244358U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 880028529183500036U;
            aOrbiterD = RotL64((aOrbiterD * 14228281807461251361U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 2379557167489415783U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11854373946064529806U;
            aOrbiterI = RotL64((aOrbiterI * 150755294320438887U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1487252775956449964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12777924204511625545U;
            aOrbiterK = RotL64((aOrbiterK * 1366019527386994789U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15998631485222477969U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8864212892296191613U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 579242788050369815U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17069347835763226743U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7443008171694679791U;
            aOrbiterB = RotL64((aOrbiterB * 748894368884566607U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17334256152350782002U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8986626119086556393U;
            aOrbiterJ = RotL64((aOrbiterJ * 2258172145924120235U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + aNonceWordI);
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterD, 56U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordJ) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 21U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29716U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 27281U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 26283U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 28975U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25077U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28125U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 29480U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 14U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = (aWandererB + RotL64(aPrevious, 11U)) + 966899917801652720U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 57U)) + 10996327672320748649U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 4188171566846621107U) + aNonceWordA;
            aOrbiterD = ((aWandererD + RotL64(aCross, 21U)) + 5886209243097387959U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 44U)) + RotL64(aCarry, 19U)) + 14940428957136728111U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 27U)) + 179187285531914832U) + aNonceWordB;
            aOrbiterC = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 6685351948936817752U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1894506461704029700U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4182760368636977082U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 972988091869133921U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12523318028514940790U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5059306166973366892U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2857409765717296483U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5890872367917643851U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17747338389865221534U;
            aOrbiterK = RotL64((aOrbiterK * 5306740664798049267U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13906227834259884100U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7152105382899756368U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 6772157117358310485U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17868101884759619240U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11758843266314148347U;
            aOrbiterD = RotL64((aOrbiterD * 5919135169337501485U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13950566197090324859U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17278105609930477854U;
            aOrbiterB = RotL64((aOrbiterB * 11431842718945107359U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9556785965646738355U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 841298436857932987U;
            aOrbiterF = RotL64((aOrbiterF * 15077843186688841797U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 56U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterK, 5U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterK, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
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

void TwistExpander_BasketBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xECB02F0A99820267ULL + 0x8217EDFAB77576B9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9FAFF5E91D9B186DULL + 0xD10C3B80410567F5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB3EE4D18876C1809ULL + 0xDB40F9F14AC023A5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE618D5117D7BBBF9ULL + 0xCDCA63F0DDB93560ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF3B346EB23411185ULL + 0x9C0219772D2AD5BBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCEFD7FB53C611611ULL + 0x8FD241AF9B088DB4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC122E7134016DCE5ULL + 0x8BD6D06AD5E46843ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xACBD4C2726418ABFULL + 0xB3C1186239694536ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCA09CD5BCB919367ULL + 0xAD69BD747223D49CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9B4A8EAF6D5EAB23ULL + 0x8238B788B0DD3FEDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x941C6021AE0B139DULL + 0xF00E9AB46B3D3325ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF7366402148C1495ULL + 0xE673D320D61A3BAEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEBD808CEA07A1065ULL + 0xEC8C05ACDA98F03DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC916D1AE40E2BDA9ULL + 0xF2FD84590030B5B4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA31AB0249D43B525ULL + 0xE99E8E82870EDCA3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA0BCA3DA7227ED4FULL + 0x9DCD72A70EFC9CC0ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1112U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 2960U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 3745U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4919U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4708U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 19U)) + 16200278595895089008U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 1029614154810465897U) + aNonceWordB;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 41U)) + 7129562468705441295U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 14388903902433951274U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 1013568949315967455U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 47U)) + 3128823373497815651U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererF + RotL64(aCross, 11U)) + 14525694606889470589U) + aNonceWordN;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14443983602196782887U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12244220415328641190U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 15052949098014803181U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10477159225338766614U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2842870123078131566U;
            aOrbiterI = RotL64((aOrbiterI * 11522265477555954071U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8621138818955849917U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5038396344400303181U;
            aOrbiterE = RotL64((aOrbiterE * 14636756322207385447U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2768613802894372496U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2027754864051410015U;
            aOrbiterD = RotL64((aOrbiterD * 2461322540050569287U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 2848088309172056399U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15017458513904884651U;
            aOrbiterK = RotL64((aOrbiterK * 9926904679902843055U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9079797279596336139U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15424866642305110811U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12912331089970158845U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13751764050290602740U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7694557131324740282U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14980807690491467023U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 28U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 43U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 36U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aNonceWordF);
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 21U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 23U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 5828U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((aIndex + 6488U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 10074U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9437U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9133U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10808U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 6U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (aWandererI + RotL64(aPrevious, 60U)) + 18191288703716505885U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 51U)) + 9824014524910417136U) + aNonceWordN;
            aOrbiterK = ((((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 11953012029254917548U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aWandererE + RotL64(aScatter, 11U)) + 6297568011027199089U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 39U)) + 2576999400457367975U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 13176139160575558254U) + aNonceWordG;
            aOrbiterE = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 9978408174563621810U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16765834875061607142U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16534507305459121344U;
            aOrbiterK = RotL64((aOrbiterK * 8943988574248229067U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3114710944346151807U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10240517868726718592U;
            aOrbiterF = RotL64((aOrbiterF * 4645691562915606463U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10721450637990777883U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16689590768796583952U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3046344179729901637U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2427422768928450209U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13495584061816457831U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 6670984773768885119U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7058636403765106682U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9897341853944713767U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14286816859999869231U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17749559755733386064U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12515645083926326659U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6582878478865838245U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2625692458813609962U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10596240255026143019U;
            aOrbiterE = RotL64((aOrbiterE * 11605800195771080135U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 50U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 10U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13578U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 12019U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 14432U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15998U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((aIndex + 10968U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 12980104182836602177U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 29U)) + 3172622203188863995U) + aNonceWordD;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 11U)) + 1170974132219980203U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 35U)) + 6035201940965047490U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 18033907118424996722U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 14604813424800580304U) + aNonceWordF;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 58U)) + 13720232492851066035U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3902659710585257448U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8331560652661619868U;
            aOrbiterG = RotL64((aOrbiterG * 11418103770615560205U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4485014147538689794U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 168202636924512424U;
            aOrbiterB = RotL64((aOrbiterB * 13711020666131492091U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16227825670092707848U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4792781933944671365U;
            aOrbiterI = RotL64((aOrbiterI * 15859849676231455283U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12636865372722601282U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 18198291399585556632U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 18155803890313399795U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3650053185419807206U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5897288963905408776U;
            aOrbiterE = RotL64((aOrbiterE * 3706949366974086151U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9922308113622901726U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 13352279749091561510U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 4025213180483632557U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14969461950939646117U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10231661776135056651U;
            aOrbiterJ = RotL64((aOrbiterJ * 11284575051455238501U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 54U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 14U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17431U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((aIndex + 20027U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 20820U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16505U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneD[((aIndex + 17851U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 5U)) + 11039986441331892533U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 43U)) + 6256024955965426119U;
            aOrbiterB = ((((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 29U)) + 9857443189988995666U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 11900944813380998208U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 51U)) + 8422577734978875541U;
            aOrbiterI = ((((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 3100835100713928724U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererH + RotL64(aCross, 35U)) + 11871553509810206993U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17614749493763417027U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3638372131856199916U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 480683274898147025U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6582275259281025770U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17016882418498941958U;
            aOrbiterD = RotL64((aOrbiterD * 4269869255230867823U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1747214688658984715U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9356088987044015278U;
            aOrbiterH = RotL64((aOrbiterH * 16221733545319753695U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4056238112133473456U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16013150119949532998U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12913648646318115315U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16076621211111834889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9940824359571581765U;
            aOrbiterJ = RotL64((aOrbiterJ * 11624767861336495331U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15624084004784515753U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7630989544834680335U;
            aOrbiterK = RotL64((aOrbiterK * 12261063237156822067U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18003586430673313786U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1654118743290334161U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1153250137357176071U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 42U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterD, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 25176U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22212U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24606U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 26176U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 47U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 5171470532667965920U) + aNonceWordG;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 22U)) + 750549462358682403U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 3325689257577120525U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 18031575461559790826U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 57U)) + 13874739537012288677U) + aNonceWordB;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 37U)) + 4250029868785016865U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 29U)) + 8211158803112611161U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1083939790236786027U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3446525462376962464U;
            aOrbiterF = RotL64((aOrbiterF * 13603702473750888213U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6973817815000417325U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15230876489676945543U;
            aOrbiterH = RotL64((aOrbiterH * 7737039082964537651U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9359727659738755880U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8775170107816327654U;
            aOrbiterD = RotL64((aOrbiterD * 6910680458261008653U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11958941755525038545U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16966819714283167348U;
            aOrbiterE = RotL64((aOrbiterE * 16363457661846050749U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14556087985619763243U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17915047508377045221U;
            aOrbiterA = RotL64((aOrbiterA * 6727635453185130109U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8578745677485367222U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7002181668717618866U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12329703532414955235U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 3569939503066735457U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2956247934282522184U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 9946650822131152531U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 42U)) + aOrbiterE) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aScatter, 30U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 27U)) + aOrbiterH) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 29484U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32515U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32538U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31027U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 11U)) + 1142447269198373880U) + aNonceWordC;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 10581460640040336191U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 37U)) + 14703062773878202900U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 15737525756286914746U) + aNonceWordA;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 19U)) + 16178774478273186999U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 2514897053906809160U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 28U)) + 13702496607592508464U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18030885275418337965U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5241783876161655984U;
            aOrbiterC = RotL64((aOrbiterC * 10970981186787227937U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2807052676283587925U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8022804576763271327U;
            aOrbiterJ = RotL64((aOrbiterJ * 11727096043219370577U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15597099852232205860U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1538435607932096400U;
            aOrbiterE = RotL64((aOrbiterE * 7900752511710516981U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11147868774413615365U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9325213746830411568U;
            aOrbiterK = RotL64((aOrbiterK * 561819005818948769U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13792300423550555634U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 3134856508983945719U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 4271845067763664863U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8654966018053784882U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8937113935476779267U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 7386875687217705855U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4135676350355234788U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11407912615743682678U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2773506587480714695U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 28U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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

void TwistExpander_BasketBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9CB3602098D7EB73ULL + 0xB7310983EC2598C0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEF4441AE82439903ULL + 0xDE0DB79E5603563FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8367541CECC06533ULL + 0xD0A1FFC769BDFF6EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF0EAD3917B931D4DULL + 0x97F31227853A99F7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC37B9825577F897FULL + 0xB3439B762FE878DDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD70ED8E3858CD3EFULL + 0xB6193F51B893322CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8BD75560D956E0BDULL + 0xC29352638D68829CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFB6416267A2369A5ULL + 0xB95699E1DE626E6DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA02B6635826728D1ULL + 0x99CCD03F41E98586ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDD16129B01033A39ULL + 0xB7F494AFDD4C29EDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBD6085401826D72DULL + 0x9965560386782A62ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB7F5234C0E186549ULL + 0xABCD7BF49B3883CFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8D0C242C9EB55D23ULL + 0xE6D5F3633919537CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD0594D2902225183ULL + 0xB0B2E1771F80747CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB500350A3842EDA7ULL + 0xB0BF312951C182F6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEA73469FDBEFCA1FULL + 0xA0B294F7118C41F1ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3689U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 4729U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 297U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5695U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7856U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 413U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 52U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 35U)) + 13687218104610230596U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 43U)) + 6841550124960692709U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 51U)) + 17418968668458764131U) + aNonceWordO;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 8303537912696948204U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 6U)) + 12376614417285936537U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 14215749063579232654U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 57U)) + 4111736931433665347U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 37U)) + 11250375934571631522U) + aNonceWordL;
            aOrbiterD = (aWandererG + RotL64(aCross, 3U)) + 5367367837773331275U;
            aOrbiterF = ((((aWandererD + RotL64(aPrevious, 28U)) + RotL64(aCarry, 27U)) + 15514089192382674434U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 47U)) + 1475991716685034960U) + aNonceWordM;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5531622777788629748U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8363822215908303335U;
            aOrbiterC = RotL64((aOrbiterC * 17850203366840994883U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3741256932685720414U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11634667238062155772U;
            aOrbiterK = RotL64((aOrbiterK * 15925089729784547403U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18180546911210417155U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5123234656838556335U;
            aOrbiterB = RotL64((aOrbiterB * 15362857462853398025U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11215734271189250284U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16863747802158398092U;
            aOrbiterE = RotL64((aOrbiterE * 1828035970246160023U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9859050606636646323U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9331300036643654675U;
            aOrbiterG = RotL64((aOrbiterG * 2502263410556166281U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15028845665427209759U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8916444839488901676U;
            aOrbiterJ = RotL64((aOrbiterJ * 6646561894156038791U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 8024631140949068570U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1116378858490660031U;
            aOrbiterA = RotL64((aOrbiterA * 4247798531910227367U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5066486214537899212U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9346312092322423057U;
            aOrbiterD = RotL64((aOrbiterD * 13443190089768875191U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11651011617027950122U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11308862427412671711U;
            aOrbiterH = RotL64((aOrbiterH * 12167147966934334703U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3850136281462840708U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13461307727665667424U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 10788040812090673421U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17824744996404571928U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13687218104610230596U;
            aOrbiterI = RotL64((aOrbiterI * 325803029547254631U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 46U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + aNonceWordK);
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + RotL64(aOrbiterG, 19U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 29U));
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 40U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 10U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10346U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 9256U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9353U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8291U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8865U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13875U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11992U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 38U)) + 13499155707765393469U;
            aOrbiterD = ((((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 3740324981823726185U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 5470765363949735652U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 3U)) + 3446436171274452326U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 19U)) + 1778929412631211933U) + aNonceWordC;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 35U)) + 14666308799855220954U) + aNonceWordL;
            aOrbiterA = (aWandererB + RotL64(aCross, 27U)) + 4548410236791175055U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 41U)) + 5829739767694190372U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 21U)) + 14319231414903675748U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 1513851750246111405U) + aNonceWordJ;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 48U)) + 1685620217748986019U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16284162182006054402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6271539598462003309U;
            aOrbiterH = RotL64((aOrbiterH * 13923286694131331137U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12669312437565969473U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11894755313393001665U;
            aOrbiterD = RotL64((aOrbiterD * 12556759675372354075U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 6315983824634946566U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17106616474222892782U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 167205520766791073U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13350266700180455548U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4608846311203767162U;
            aOrbiterA = RotL64((aOrbiterA * 2504857468837437365U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14195866746143604365U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7917977448256795054U;
            aOrbiterE = RotL64((aOrbiterE * 5927771378657284557U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10707336923305131629U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17122696159336995392U;
            aOrbiterF = RotL64((aOrbiterF * 13953518568670659191U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5182322763573586116U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6503754948502556246U;
            aOrbiterJ = RotL64((aOrbiterJ * 14749002194140663519U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14907832047832987341U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 6258064448676621346U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 4407960312705621487U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1180234574888070795U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 801686887651085881U;
            aOrbiterI = RotL64((aOrbiterI * 433981853631548041U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11810494591997709554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9343740505955858127U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 8733378485648720323U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12816829575386720695U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13499155707765393469U;
            aOrbiterB = RotL64((aOrbiterB * 9937924703928730369U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterI, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + aNonceWordP);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 44U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 42U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20151U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 20867U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 16463U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 22372U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21311U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19097U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 18747U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 3U)) + 13174219512651137892U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 29U)) + 2715455762789269341U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererD + RotL64(aIngress, 47U)) + 1338018183235594313U;
            aOrbiterF = (aWandererG + RotL64(aCross, 41U)) + 16566866551729552930U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 6901845297307236726U) + aNonceWordA;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 56U)) + RotL64(aCarry, 37U)) + 2476078302049201718U) + aNonceWordB;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 11U)) + 15531109473927052260U) + aNonceWordJ;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 4087849380858572351U;
            aOrbiterA = (aWandererK + RotL64(aCross, 13U)) + 5167830630098599644U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 44U)) + 7275995452428627217U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 37U)) + 14794340370010024117U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8509217403041662849U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2321522025240806996U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 113568101672878697U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5676672952755594051U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 2304681269233504384U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 15731441084605554497U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8383399721062437300U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13181984036942227666U;
            aOrbiterE = RotL64((aOrbiterE * 1648761328771932069U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13602604532551684210U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12725687663616352843U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4684699861686199753U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5831790822416009806U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4535048543735457407U;
            aOrbiterC = RotL64((aOrbiterC * 12076777878870257053U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10617608605149381858U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5244225377862618630U;
            aOrbiterB = RotL64((aOrbiterB * 15307177251167023999U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18229989093139888456U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9728120630096192811U;
            aOrbiterD = RotL64((aOrbiterD * 16052574428163231023U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1312233443099767304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8043115602160128619U;
            aOrbiterI = RotL64((aOrbiterI * 9365756845731616963U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4679339316686216023U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 211799535650113758U;
            aOrbiterA = RotL64((aOrbiterA * 1478368466990144107U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13307123762743628190U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7093673238704478497U;
            aOrbiterF = RotL64((aOrbiterF * 13273906568866802561U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16396459072175632290U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13174219512651137892U;
            aOrbiterG = RotL64((aOrbiterG * 7581008806810219369U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 18U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 44U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterG, 39U));
            aWandererA = aWandererA + ((RotL64(aIngress, 52U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 18U)) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + aNonceWordK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 14U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31842U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 32476U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 30682U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 31975U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27965U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26932U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 24635U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererK + RotL64(aIngress, 53U)) + 6467297102954816305U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 7921154109831114952U) + aNonceWordF;
            aOrbiterC = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 5701131763215638919U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 58U)) + 10022999076719002684U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 19U)) + 4367135243038982316U) + aNonceWordJ;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 14445846824810383592U) + aNonceWordE;
            aOrbiterJ = (aWandererH + RotL64(aCross, 29U)) + 7683697954545773253U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 23U)) + 17517006750428030899U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 12U)) + 2052484792684025476U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 47U)) + 6279463052085808926U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 21U)) + 679280153651813684U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2939516520188460569U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1960616434964712325U;
            aOrbiterC = RotL64((aOrbiterC * 15145998415466343039U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12273819390719947361U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5685033154709449397U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9845666295874714959U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 9314494172199500653U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15757631834636427621U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15483543888965744529U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10878078046389399574U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3583495913766365232U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2913540984990155225U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7385544065754622301U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16839599460207922881U;
            aOrbiterK = RotL64((aOrbiterK * 240651605910592561U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13038163804940349251U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2587538594933924000U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 3091149760401278671U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13109518583364738004U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2447689055742474261U;
            aOrbiterA = RotL64((aOrbiterA * 12100180201235703193U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5752044906692668618U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6637725371036522120U;
            aOrbiterG = RotL64((aOrbiterG * 6021986525167161115U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16549229877442298618U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12825651879441561108U;
            aOrbiterD = RotL64((aOrbiterD * 9079931351967033993U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16088338999978085987U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12584648360998154782U;
            aOrbiterF = RotL64((aOrbiterF * 2109996837220975261U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7526256599938771686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6467297102954816305U;
            aOrbiterH = RotL64((aOrbiterH * 9289442676936248653U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 52U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF + (((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 48U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterE, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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

void TwistExpander_BasketBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD8C8B9B7BD9798D1ULL + 0xB0CC41293AC7A4E0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAC0FE723F4D58FDBULL + 0xC75F0C131EC7B47EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA87586A8AB0FEDB5ULL + 0xE68625243E5D58DFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD70BC446D6CA0C2BULL + 0x95792B2F083AB95DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBB5C4716368F1B19ULL + 0xADB7E3979048C53BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFED06D5D76EC6FD5ULL + 0x9A97A5B7151DC695ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8CEA34B15FB34FBFULL + 0xF06ACB1C1598A6C7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD69DA27E43B40831ULL + 0xC34C06432E39519AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x96726D993B79F6E3ULL + 0xF9AFF14880D99F39ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8448723777E3B255ULL + 0xF46AC00EBD6C7279ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF0164E47B95CF0D3ULL + 0xF6B18094633AB3A9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCE67857F902B2D4FULL + 0xDCC671410C8AAB08ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBE77E537B84AFBA1ULL + 0xF2593811CF379C5EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBF2647D7E57DB287ULL + 0xBF89960EFC4FB8DFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE584ECCFDE98E467ULL + 0xD650E287F87E6C99ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD6C06FFD21D4D59DULL + 0xCB001E18A97AF439ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7421U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 6519U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7327U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8122U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1351U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5825U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 56U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 2617613537256538553U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 56U)) + RotL64(aCarry, 5U)) + 16642868916835132715U) + aNonceWordD;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 10860291124337073254U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 47U)) + 6432511273906902472U) + aNonceWordP;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 35U)) + 7505375005848241910U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 19U)) + 11086616004678821329U) + aNonceWordE;
            aOrbiterB = (aWandererF + RotL64(aCross, 27U)) + 3298830587569881951U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 52U)) + 9775143140064220979U) + aNonceWordO;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 41U)) + 4147601326580823120U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12245920269898100415U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8391940489176734499U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9119606167674098007U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17876893379544668477U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 18301882058180370541U) ^ aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 16680384667098921309U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6869225862715140102U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15404118372589259800U;
            aOrbiterB = RotL64((aOrbiterB * 5766851935950389915U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17757381020518233814U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17677969146092374455U;
            aOrbiterG = RotL64((aOrbiterG * 3469432916562405063U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15783378556632870114U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5792858258663697864U;
            aOrbiterI = RotL64((aOrbiterI * 12008981883482080427U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11737803388202260296U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16001927091970715330U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 3062030309852922061U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1749586939123286632U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 6169421068855905938U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 12374789910763348695U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10073586820719728062U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17744171227198661555U;
            aOrbiterE = RotL64((aOrbiterE * 10658375268803957647U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1149819647337612792U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7725598665625892006U;
            aOrbiterC = RotL64((aOrbiterC * 15097586655234391559U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 10U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 37U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 48U)) + aOrbiterJ) + aNonceWordB);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 41U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterF) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterJ, 52U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15729U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 14194U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 14546U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 9003U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9574U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10144U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12028U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 5088525177670191619U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 23U)) + 9966456257813932112U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererB + RotL64(aIngress, 58U)) + 7707646574027146307U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 53U)) + 75480203757681173U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 39U)) + 384659134071835163U;
            aOrbiterK = (aWandererD + RotL64(aCross, 35U)) + 3158769775373307778U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 17360830943513941272U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 18U)) + 5317278822721604586U;
            aOrbiterF = ((((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 43U)) + 1371427105215954781U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3162710551223553423U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5332921933853550756U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 11709546145149357887U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10572462410297815854U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10234389605554817892U;
            aOrbiterJ = RotL64((aOrbiterJ * 2130374833440291193U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13421365517991380605U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10186643614984034083U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 8554471709467808453U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4742438973260817120U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6081590345899008846U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7069396301823124931U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15360092808493795340U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12186413069553132646U;
            aOrbiterF = RotL64((aOrbiterF * 3815981440611914267U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16756221656224451552U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12232880965861373143U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14196910735715726471U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10090954323470840557U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15615770271463853537U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13544181592829027283U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 556029032505658411U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13311879111583579039U;
            aOrbiterB = RotL64((aOrbiterB * 3924744868168749003U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8646360871497847336U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2064833941982069154U;
            aOrbiterK = RotL64((aOrbiterK * 10016546852137913163U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 20U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 42U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterG, 58U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterK, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererH, 38U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17153U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 16431U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21183U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 17975U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23750U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17793U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18522U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 47U)) + 9446153639709651566U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 19U)) + 10550762260670758167U) + aNonceWordB;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 7062634922142578383U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 9178499097812764515U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 6887103379773525538U) + aNonceWordP;
            aOrbiterI = (aWandererD + RotL64(aScatter, 35U)) + 6239750312052010257U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 23U)) + 17645022614523287959U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 4U)) + 3639618183259408272U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 53U)) + 3131737117548745095U) + aNonceWordN;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7253994382396406554U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15217993711938379561U;
            aOrbiterA = RotL64((aOrbiterA * 17853313384747259923U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12594152227603630033U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11250170200489647869U;
            aOrbiterK = RotL64((aOrbiterK * 546800378327864723U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12936942656624279424U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10990736056052106149U;
            aOrbiterH = RotL64((aOrbiterH * 7123916809953459187U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12787293075893090465U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17154990205620778151U;
            aOrbiterI = RotL64((aOrbiterI * 10031369940028159521U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1270827262969060301U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17337623431665013136U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1517262088236356107U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 830330490987911853U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6828309232554560547U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 9742464176986145819U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11470087853413986203U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 10470148870747884420U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 6766079738799967443U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18315536891901859637U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12264670822285914271U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 5841574505408674119U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10931842095884524879U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11134871340959676257U;
            aOrbiterE = RotL64((aOrbiterE * 11714837622285605745U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 24U) + aOrbiterG) + RotL64(aOrbiterD, 5U)) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterA, 24U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterG, 19U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27949U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 26088U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 25900U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 31849U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24683U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26095U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26481U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 3U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (aWandererK + RotL64(aIngress, 13U)) + 9888431329297626900U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 2937735167534624403U) + aNonceWordC;
            aOrbiterE = ((aWandererH + RotL64(aCross, 18U)) + RotL64(aCarry, 39U)) + 17626022970343789617U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 51U)) + 5665660859333693743U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 3U)) + 1060537034632076669U) + aNonceWordN;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 23U)) + 743777763907175800U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 3U)) + 5744905970181808845U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 35U)) + 3545351394494002180U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 29U)) + 4877547088414106007U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 11669378338379598445U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2961072441706158212U;
            aOrbiterE = RotL64((aOrbiterE * 2677988507090705371U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13984945589234919765U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1433097875470903205U;
            aOrbiterF = RotL64((aOrbiterF * 451996840039906781U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 716415411025451152U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8542286150858297810U;
            aOrbiterI = RotL64((aOrbiterI * 9139015340823332449U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12932391786479661299U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14005503313299177013U;
            aOrbiterK = RotL64((aOrbiterK * 802663466907819743U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9382792812676318046U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5138554251079724724U;
            aOrbiterD = RotL64((aOrbiterD * 6386016499265056247U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8522380066269546172U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11825536408101906458U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17042837108792016849U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15504062350899452495U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1219010998820336744U;
            aOrbiterH = RotL64((aOrbiterH * 10650635772711590803U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6442717843380349632U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1047843426279085117U;
            aOrbiterC = RotL64((aOrbiterC * 4074561571072878005U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10611039527108679173U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5092816736177358221U;
            aOrbiterJ = RotL64((aOrbiterJ * 14342779343820140833U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterE, 42U)) + RotL64(aCarry, 29U)) + aNonceWordO) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 4U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 51U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterD, 37U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_BasketBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x97EB0A735E78E5F3ULL + 0xF179D084DA005997ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD0B2FF7E18068A3BULL + 0xB2F314A4D86613E5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBAFD28C6BF05BEA3ULL + 0xF777AD463D381741ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC9B5AC1AFA710C57ULL + 0x8B5D497D5EEBC23CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFC10998D4CEBC0BBULL + 0xE5AAC35271A7DACFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF56295B1ED70B895ULL + 0xA6108BA476A39C73ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA82F68C3611753A9ULL + 0xFA2AC521E0BE7F13ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBB1A8A784982212BULL + 0xDCB13C8BF3EFDA2BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC5B9C567A552F53BULL + 0xDC630B225CB5BE5EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA8F4E331DD1B6343ULL + 0x854661AF76AAF921ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8CEE642CF8E732DDULL + 0x9A526A6CE5DB9603ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA37030DC3E26B0BDULL + 0x9ABC28346C659A7EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEFFFB1FA9E4657EBULL + 0xC92125C0BD1CF252ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFA0E5C270067D019ULL + 0x982CA1D4349F3444ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE952A6C6E8370491ULL + 0x8AD03B15FD028DC4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9AC350669620852DULL + 0x816A9E3BDAB14D25ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 630U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 3266U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4381U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7416U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7552U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 504U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 14U)) + 16124889768301047791U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 5U)) + 11912338587186717280U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 8594012868813114354U) + aNonceWordO;
            aOrbiterF = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 18281043566156682815U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 16853106130200942302U) + aNonceWordJ;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 27U)) + 2611212958619673086U;
            aOrbiterK = (aWandererK + RotL64(aCross, 21U)) + 18039472325066855180U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14495785571345122046U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4556063793412832418U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 13166927543135467627U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14896419970271244358U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 880028529183500036U;
            aOrbiterJ = RotL64((aOrbiterJ * 14228281807461251361U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2379557167489415783U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11854373946064529806U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1487252775956449964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12777924204511625545U;
            aOrbiterK = RotL64((aOrbiterK * 1366019527386994789U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15998631485222477969U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8864212892296191613U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 579242788050369815U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17069347835763226743U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7443008171694679791U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 748894368884566607U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17334256152350782002U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8986626119086556393U;
            aOrbiterC = RotL64((aOrbiterC * 2258172145924120235U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 5U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15975U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((aIndex + 13570U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 10580U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 9901U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13303U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10610U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12019U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 14U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 2974056819475622600U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 7345051759236356098U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 47U)) + 12738468816846628882U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 34U)) + RotL64(aCarry, 53U)) + 7694520596043297922U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 41U)) + 5530753590015084774U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 3U)) + 3776309161718383105U) + aNonceWordL;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 27U)) + 784780304358106404U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8999942326995036509U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5194986506064092779U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 15070787038006135963U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7920040007459652762U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11311997270710107937U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6227571709361790209U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5365231114813547251U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8630110234623825263U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2735881715888325759U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2358235238039571072U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18059414891616491807U;
            aOrbiterE = RotL64((aOrbiterE * 17150786106857185467U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 14526050556461782864U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6937282036603272474U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 14954512365270028029U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10105832250694931310U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3884223553012098137U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16340956813003906195U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10385284339549648087U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1257633893341505930U;
            aOrbiterK = RotL64((aOrbiterK * 2669950791270500977U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 51U)) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 42U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19752U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 21976U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 17094U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18728U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18860U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21502U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17259U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 43U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = (aWandererA + RotL64(aScatter, 19U)) + 785861751704720606U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 11U)) + 15968088718435606299U) + aNonceWordI;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 27U)) + 1393976526590347151U) + aNonceWordE;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 17240750947292745884U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 4921576136163183137U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 34U)) + RotL64(aCarry, 3U)) + 3334047873553153032U) + aNonceWordM;
            aOrbiterA = (((aWandererE + RotL64(aCross, 57U)) + 15086509978458408698U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 892391205397581998U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2965686403183767521U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 709160942482770225U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14632215393655706170U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15740589515342377322U;
            aOrbiterH = RotL64((aOrbiterH * 15677716942904794913U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11131164813943086445U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6988080581278900960U;
            aOrbiterA = RotL64((aOrbiterA * 6412189142344044255U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16021254613117657178U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6183615599897921154U;
            aOrbiterI = RotL64((aOrbiterI * 9976411093264211033U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12533992547026652747U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3104325358982904219U;
            aOrbiterG = RotL64((aOrbiterG * 14977348108778147265U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3878525937957474644U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2120435259884368445U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 15964718652193073177U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14928658302694194856U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9121310461310309348U;
            aOrbiterK = RotL64((aOrbiterK * 17304439784647477491U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 44U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 37U)) + aOrbiterA) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31997U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 27547U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 28795U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 29754U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30410U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27109U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 29336U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((((aWandererJ + RotL64(aCross, 38U)) + RotL64(aCarry, 5U)) + 13296600294247799698U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 5818503518080877515U) + aNonceWordG;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 6735784238734173597U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 57U)) + 7368398209488856201U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 21U)) + 961734029066455638U) + aNonceWordO;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 5U)) + 797011946660892011U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 51U)) + 12841876018396622350U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16213253970483895623U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15186950557113470375U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4647470430467908107U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5117930310827477341U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12265429373166094162U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 1522823535151532249U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13920531346698601568U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14695405206998211456U;
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7851960904825938443U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9501511171732550190U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 5614164120361489613U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5663365182245722077U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9607860124321315555U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 3461820361914280601U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18171052650586819280U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3442698321538580861U;
            aOrbiterH = RotL64((aOrbiterH * 6317525514963824829U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1491052813469258970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3956599824067616133U;
            aOrbiterG = RotL64((aOrbiterG * 2928600779267623085U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterE, 26U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD46AF631224C118FULL + 0x931ECCE2570045B8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEBC9A12A23EFE6C1ULL + 0xBA2A9DC145694EE0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE075B1C9CB9A32C1ULL + 0x9A9B7AADABD0AAA6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9E6065478D5E1C37ULL + 0xCC7CD13A0F8E6F6FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA24A7A9F485FD437ULL + 0xA374828F6F2B0061ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC4596B95C4463F41ULL + 0x98C3D4C99D7E6E11ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA5C60E36DEE14C93ULL + 0xB9043DC390D7315DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA8CA18E2A0743AC7ULL + 0xFA9BB8C254B86427ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAAC8DE69485368A7ULL + 0xF1546BEC8306A177ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9FF6838132ADFE4FULL + 0xF7E5561B23DD3DDDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE714C1DB94F745E5ULL + 0xEA51E25F82AD9C9FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB1DA55B42EB2AD87ULL + 0xBC9EB57C39BDB0D3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x87649D4B330A8261ULL + 0xC620FCF129BD8528ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFA2302D32BC05D79ULL + 0xE26D02518B106CC5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEFA0C5668E62E1F7ULL + 0xACEBFD9310584255ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE5EF0A4AF2238B55ULL + 0xF4AB0F1681D86B57ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 646U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1544U)) & W_KEY1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1667U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 1160U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 26U)) + (RotL64(aCross, 43U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 16462052553719977502U) + aNonceWordD;
            aOrbiterD = (aWandererA + RotL64(aCross, 51U)) + 12337064059566619581U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 35U)) + 15801005007094515447U) + aNonceWordA;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 8228706742665081656U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 44U)) + 11006723027845190869U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + 18173765337829177450U) + aNonceWordC;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 530215083653542558U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6608611827035564511U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2246051826221626809U;
            aOrbiterK = RotL64((aOrbiterK * 6333352641495253539U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5228575308895381421U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10999213210689606857U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 5467601259546342925U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3773371037240485696U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8887985779436152504U;
            aOrbiterE = RotL64((aOrbiterE * 698713082830739677U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11150566414723818350U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8336366151003049546U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9033771197242493699U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13233968794237090787U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8172558473508478819U;
            aOrbiterD = RotL64((aOrbiterD * 17837070423649268435U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 133564480283347997U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15104810248883567064U;
            aOrbiterH = RotL64((aOrbiterH * 706802420642303533U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9138629520201127075U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13993086066341664080U;
            aOrbiterJ = RotL64((aOrbiterJ * 4875046427147105077U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 51U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + aNonceWordG) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 44U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3895U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 3666U)) & W_KEY1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4876U)) & W_KEY1], 43U) ^ RotL64(mSource[((aIndex + 2908U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 38U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 15652862298542575895U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 29U)) + 16925323928418184554U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aWandererE + RotL64(aCross, 57U)) + 4413861484961668394U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 3U)) + 2215946422098155969U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 14975185533513111110U) + aNonceWordB;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 50U)) + RotL64(aCarry, 41U)) + 9711613814905834552U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 43U)) + 13154957291850149471U) + aNonceWordF;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5058313016418534840U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15011423472941211620U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6125316151731105673U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2030053257469580168U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 150530795186791193U;
            aOrbiterJ = RotL64((aOrbiterJ * 11106050063717096073U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10878237472104183427U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11724672539469573109U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16158741837357985395U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9589700906445846956U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 1367381624958248949U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 8459515089081211977U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12003215666757518106U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11232479330848006729U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 10993290955464593033U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13013910456628561621U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6092509838924105265U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 805601154718006061U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11999225836250312801U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14421271973875748413U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9529010940887430157U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 60U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 11U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + aNonceWordO);
            aWandererC = aWandererC + (((((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 60U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordC) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7805U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 6215U)) & W_KEY1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5999U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6055U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6558U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 22U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 5U)) + 16124889768301047791U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 53U)) + 11912338587186717280U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 29U)) + 8594012868813114354U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererK + RotL64(aCross, 21U)) + 18281043566156682815U) + aNonceWordD;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 40U)) + RotL64(aCarry, 13U)) + 16853106130200942302U) + aPhaseEOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 2611212958619673086U) + aNonceWordM;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 18039472325066855180U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14495785571345122046U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4556063793412832418U;
            aOrbiterA = RotL64((aOrbiterA * 13166927543135467627U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14896419970271244358U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 880028529183500036U;
            aOrbiterK = RotL64((aOrbiterK * 14228281807461251361U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2379557167489415783U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 11854373946064529806U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 150755294320438887U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1487252775956449964U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12777924204511625545U;
            aOrbiterJ = RotL64((aOrbiterJ * 1366019527386994789U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15998631485222477969U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8864212892296191613U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 579242788050369815U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17069347835763226743U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7443008171694679791U;
            aOrbiterF = RotL64((aOrbiterF * 748894368884566607U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17334256152350782002U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8986626119086556393U;
            aOrbiterD = RotL64((aOrbiterD * 2258172145924120235U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterK, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterF, 38U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 36U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + aNonceWordB);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8557U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadB[((aIndex + 10874U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(mSource[((aIndex + 9771U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9221U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8596U)) & W_KEY1], 5U) ^ RotL64(aFireLaneB[((aIndex + 8918U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + 18191288703716505885U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 29U)) + 9824014524910417136U) + aNonceWordI;
            aOrbiterF = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 11953012029254917548U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 51U)) + 6297568011027199089U) + aNonceWordO;
            aOrbiterI = ((aWandererK + RotL64(aCross, 11U)) + 2576999400457367975U) + aNonceWordF;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 11U)) + 13176139160575558254U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 27U)) + 9978408174563621810U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16765834875061607142U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16534507305459121344U;
            aOrbiterF = RotL64((aOrbiterF * 8943988574248229067U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3114710944346151807U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10240517868726718592U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 4645691562915606463U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10721450637990777883U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 16689590768796583952U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 3046344179729901637U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2427422768928450209U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13495584061816457831U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6670984773768885119U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7058636403765106682U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9897341853944713767U;
            aOrbiterB = RotL64((aOrbiterB * 14286816859999869231U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17749559755733386064U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12515645083926326659U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6582878478865838245U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2625692458813609962U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10596240255026143019U;
            aOrbiterC = RotL64((aOrbiterC * 11605800195771080135U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + aNonceWordN);
            aWandererD = aWandererD + (((((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 21U)) + aNonceWordC) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterG, 60U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12653U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 12259U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13250U)) & W_KEY1], 19U) ^ RotL64(mSource[((aIndex + 11914U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11037U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12496U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneC[((aIndex + 13420U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 13350544654542863236U) + aPhaseFOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 21U)) + 12364346790125404372U) + aNonceWordI;
            aOrbiterD = ((aWandererI + RotL64(aCross, 6U)) + 9738750172849512764U) + aNonceWordG;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 13U)) + 3781373837635491421U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 35U)) + 16635020317512702337U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 5383653921676231276U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 10181959815492056493U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10005510924273927017U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9524687662265740565U;
            aOrbiterD = RotL64((aOrbiterD * 13687380438646756931U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4259138552009771014U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8973051213213726023U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12625091476068190979U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17602611840127337490U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8218984546932905269U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17504305273683304231U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18102186122213487888U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2629927500298092976U;
            aOrbiterC = RotL64((aOrbiterC * 6983280164448292723U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2491581597835795234U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9506602492971620955U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 9559829640915637163U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13422942713680612924U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15037354693234876601U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12692376075738621447U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12896066842192894694U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2202952306291905855U;
            aOrbiterF = RotL64((aOrbiterF * 6779368532763429997U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterI, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 23U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 53U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE + ((((RotL64(aCross, 18U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + aNonceWordL) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 15519U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 15042U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16244U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16323U)) & W_KEY1], 21U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15787U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15566U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 15090U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 11U)) + 13915875634607599122U) + aNonceWordL;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 1695770381382411673U) + aNonceWordH;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + 3709105579778295511U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 28U)) + 7673376335333251804U) + aNonceWordD;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 8814147709738503518U;
            aOrbiterJ = ((((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 13451412605350381172U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererC + RotL64(aIngress, 57U)) + 6447870234069609538U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13419487997946496825U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5478309847615220345U;
            aOrbiterF = RotL64((aOrbiterF * 12953043149543448765U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3635184969215610049U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12527903812035294828U;
            aOrbiterG = RotL64((aOrbiterG * 12540800512035534967U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1684685110885338814U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12860354576326835090U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 12743745087733307255U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9081823570147481835U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14369321778210049109U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 17865953349448767035U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11518132079084873250U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11893535026126957389U;
            aOrbiterA = RotL64((aOrbiterA * 15751374986135615095U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7084079180579206226U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2999676609847603277U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14602698397511266403U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17683445810614029153U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11576460512964896969U;
            aOrbiterJ = RotL64((aOrbiterJ * 5243651036457051155U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 20U)) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 22U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16491U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 17546U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(mSource[((aIndex + 18236U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((aIndex + 17608U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18065U)) & W_KEY1], 43U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18848U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 17273U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererI + RotL64(aScatter, 41U)) + 77518479758428414U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 60U)) + 4832061802166300011U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 11695291171006574112U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 7467412817843260094U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 17801484124471154757U) + aNonceWordB;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 47U)) + 5555455638503958639U) + aNonceWordJ;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 13U)) + 5669470540733721606U) + aNonceWordA;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3042388456327784163U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2236734925228156691U;
            aOrbiterJ = RotL64((aOrbiterJ * 10076582424701705531U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14459720401528685450U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4814967631216658856U;
            aOrbiterH = RotL64((aOrbiterH * 18288097536171386643U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16950679344449075945U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6262238639302011050U;
            aOrbiterB = RotL64((aOrbiterB * 9942659897425088183U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3522256359074996724U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12524717897707074242U;
            aOrbiterD = RotL64((aOrbiterD * 6787771338063891989U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13891759914865623828U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11910250571469028666U;
            aOrbiterA = RotL64((aOrbiterA * 12311343917878428995U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2240189915640314069U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5365912986308810837U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 15133972552032469957U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9323732721344489753U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13087326560957916553U;
            aOrbiterE = RotL64((aOrbiterE * 14659491687401151733U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE) + aPhaseGWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 50U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterA, 13U)) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterH, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 36U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19440U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 19246U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19689U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19465U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20045U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21370U)) & W_KEY1], 56U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20810U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19227U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 60U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 3U)) + 1210605127156905516U) + aNonceWordH;
            aOrbiterE = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 11964595428173569519U) + aNonceWordC;
            aOrbiterA = (aWandererA + RotL64(aScatter, 60U)) + 16277319029916258482U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 41U)) + 12369497463101824572U) + aPhaseGOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 6201248574067068202U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 1727477025667206661U) + aPhaseGOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 51U)) + 1404510627789806851U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6948213591282018925U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 6688865181284421478U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 12619122841662247279U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3351130769402360855U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12681032488906270823U;
            aOrbiterI = RotL64((aOrbiterI * 3680893896579741263U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3591412591193726763U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16153817571210878589U;
            aOrbiterF = RotL64((aOrbiterF * 4165137036092246349U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3808228354421006630U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1427373776207504205U;
            aOrbiterC = RotL64((aOrbiterC * 4534374093769595531U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1831554180932501132U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 1114853085120949215U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 4264176108298812905U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2080935638828366835U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16104777999646489828U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 15205199362011777473U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9782806013673440791U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3721620299829386454U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 6286765834910272409U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aIngress, 20U) + aOrbiterE) + RotL64(aOrbiterI, 28U)) + RotL64(aCarry, 41U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + aPhaseGWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterC, 51U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23401U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 23389U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24084U)) & W_KEY1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22604U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23338U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24437U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23154U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneD[((aIndex + 22126U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 14U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 6654158889644956636U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 60U)) + 9045779659363991870U) + aNonceWordC;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 11U)) + 3888897662136993491U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 6882016842864459345U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 15601891715956172291U;
            aOrbiterG = (aWandererF + RotL64(aCross, 35U)) + 5176811598629335350U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 27U)) + 12519945150889074325U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 4552583214397603278U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 14225482701804864688U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8526052833180466359U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5485298070606280363U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11237713257388094289U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11032429223099413011U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14340345895626142788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16275167270553643347U;
            aOrbiterE = RotL64((aOrbiterE * 7308578867128951199U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14041860597556520250U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1436068974197066343U;
            aOrbiterJ = RotL64((aOrbiterJ * 3938460345031496843U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11483155566419547004U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4608508534724289325U;
            aOrbiterG = RotL64((aOrbiterG * 13461385011638899485U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2389196334288832895U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4062682330273866602U;
            aOrbiterA = RotL64((aOrbiterA * 8787682133271101901U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5655656046585592034U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7977947821249746880U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 10082104644185964787U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aIngress, 6U) + RotL64(aOrbiterB, 41U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 35U)) + aOrbiterF) + aNonceWordO) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterG, 51U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aNonceWordJ) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25255U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 27266U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25302U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27239U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26692U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26078U)) & S_BLOCK1], 38U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25861U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25652U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 12U) ^ RotL64(aIngress, 29U)) + (RotL64(aPrevious, 43U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 2177539223979303669U) + aNonceWordA;
            aOrbiterB = (aWandererH + RotL64(aScatter, 43U)) + 3962004686551521471U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 8457602312617147662U) + aNonceWordG;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 3U)) + 18011802451816510632U) + aNonceWordC;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 57U)) + 9046101759168876832U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 11135620637431969597U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 18U)) + 15913029940697999701U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16304193109948135982U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13208892298820080981U;
            aOrbiterF = RotL64((aOrbiterF * 15093751072618884859U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4182377898949419225U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13970137023071326151U;
            aOrbiterJ = RotL64((aOrbiterJ * 9075061559681739865U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8402396284835248583U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 8859190834060657829U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 13552418608113716117U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9760005337757990392U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14108277760135744897U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4474681104256093885U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12226316121949012350U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 3456392186754113960U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 8704729827929941215U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5004087958637038973U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7176881295123125567U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 15272157962928021009U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10889800478505074438U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13728832441482547824U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 17588477761978646139U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE + (((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 5U)) + aNonceWordD) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + aPhaseHWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterF, 29U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 10U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27326U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 29870U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27622U)) & W_KEY1], 60U) ^ RotL64(aWorkLaneC[((aIndex + 29078U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 30017U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29388U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29069U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 27931U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 21U)) + 18087125778766689269U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 35U)) + 13710545066503235196U;
            aOrbiterK = (aWandererI + RotL64(aCross, 3U)) + 1701939704736254645U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 8064093611384019909U) + aNonceWordH;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 16623332751533885431U) + aNonceWordO;
            aOrbiterB = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 15590129153794910109U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 10U)) + 7413312683079107383U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4186064478651458810U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 5501191643940735954U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14254804649177125269U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11064645242200570835U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13825922087298055833U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 7529317892716108867U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5944980709887369970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8181136916070569646U;
            aOrbiterG = RotL64((aOrbiterG * 395183021205661827U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15442336949157292482U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11580554435240641337U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 6654637892858767739U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11240018128174598322U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2027565596050777471U;
            aOrbiterE = RotL64((aOrbiterE * 18048186560314431815U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16425887196883725233U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16828683527588834095U;
            aOrbiterI = RotL64((aOrbiterI * 17746289103235902485U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9923829146479008804U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6669171007279929454U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 681823450939955099U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 36U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 11U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 18U)) + aOrbiterK) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30281U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadA[((aIndex + 32409U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32002U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30316U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32568U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 31976U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 22U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 12632404972795375757U) + aNonceWordP;
            aOrbiterK = (aWandererG + RotL64(aScatter, 37U)) + 5351879979055988456U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 3597737727467443413U) + aNonceWordC;
            aOrbiterF = ((aWandererI + RotL64(aCross, 29U)) + 2830846754917852318U) + aPhaseHOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 44U)) + 17311925960294518018U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 2083584640523695383U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 21U)) + 15049343611387010158U) + aNonceWordA;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6443050378205811147U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6021965178697344070U;
            aOrbiterG = RotL64((aOrbiterG * 6054064448935006741U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5080289878758029976U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 576927745306972983U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16008958833683246115U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4728489691382690859U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6184355840165758855U;
            aOrbiterJ = RotL64((aOrbiterJ * 1515043910404156423U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11220539885798595450U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11091438724966718214U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 8225347114759391961U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17184210490020062419U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2150997767099116408U;
            aOrbiterE = RotL64((aOrbiterE * 8058553821648892499U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7021953562676903717U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17159676348343312834U;
            aOrbiterD = RotL64((aOrbiterD * 13877284519668483549U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 10367891770525239784U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11922478487264201233U;
            aOrbiterF = RotL64((aOrbiterF * 9195137452661956029U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aNonceWordI) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 37U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterG, 44U)) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 27U)) + aOrbiterI) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD3E55C1A58C34351ULL + 0xB8D3E29D1CC7B3DCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF0D3A02260F9165DULL + 0x92F2F5EF40AE653EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCA964ACDD8C44B49ULL + 0xCD249A9291F056C9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFD167E1C740903BDULL + 0xDBEBA08D0748787AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA8A585046B287A89ULL + 0x8838DD263CDC6558ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA712B9FE424942F3ULL + 0xF26051C11AA8A76EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA55641D5FDA5AA4DULL + 0xBBAC2D2309481606ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF829248317455915ULL + 0xEB840CB8A6C3B4F8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBE4575DBE207533FULL + 0xDF44FC2A06354BECULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF81BA72854DB6833ULL + 0xB108ACCAF05F9CCBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA336BEFC6FC6BD77ULL + 0xD25C2BB650D18060ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9415C6B3CE4BC133ULL + 0x93467FFFE13FB211ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCE974116D981592BULL + 0xE979BC069AC76ACCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD916183BC4787541ULL + 0xAC14E91C72927C31ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA56C3D96D3A58A59ULL + 0x97C322925A56B045ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE0E626CE7C8D979BULL + 0xBA34A6E086CB4B6BULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 827U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 2593U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5425U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3031U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 62U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 653U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 18U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 7651355040951791298U) + aNonceWordG;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 13988210277931659312U) + aNonceWordI;
            aOrbiterC = (aWandererH + RotL64(aCross, 47U)) + 9846849412579537783U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 12746719939495876158U) + aPhaseAOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 6U)) + 11498066185182895284U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11101058955193080232U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15513734459555672046U;
            aOrbiterC = RotL64((aOrbiterC * 6974281215677538561U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 15711108675349394643U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4771231759949468556U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9806191054594333615U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11449258010811305256U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17036938391509986723U;
            aOrbiterE = RotL64((aOrbiterE * 7411466953205347639U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6999245666776654250U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2106819066263369528U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13005885810757743129U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12716183358903477216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16752724547046059889U;
            aOrbiterG = RotL64((aOrbiterG * 11475905692393034141U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 40U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + aPhaseAWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterA, 12U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterG, 39U)) + aOrbiterI) + aNonceWordA);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 35U)) + aNonceWordF) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6521U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 9262U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6708U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6569U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10060U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5588U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5897U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 34U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 17081642665820489793U) + aPhaseAOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 58U)) + 14468854040067229623U) + aNonceWordM;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 2249450222593057429U;
            aOrbiterI = (aWandererB + RotL64(aCross, 29U)) + 14964389079511378664U;
            aOrbiterH = ((((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 17003491054252360650U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12710882240582032588U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9887078182156755359U;
            aOrbiterC = RotL64((aOrbiterC * 8205865025853482573U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7665284531810584704U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7304284015511876717U;
            aOrbiterH = RotL64((aOrbiterH * 6193179739025093929U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5517927023543751734U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17704756310857362759U;
            aOrbiterB = RotL64((aOrbiterB * 15826832172923213591U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11347400363019508578U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11696395232760991243U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9725231749679442003U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10875780291242873583U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7808740614343437672U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 8889516201913716283U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 14U) + aOrbiterC) + RotL64(aOrbiterH, 23U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 12U)) + aNonceWordB) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13058U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 14309U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 11799U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12260U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 11983U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 826930775230515406U;
            aOrbiterC = ((((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 5137814617363250861U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 11U)) + 14761561947426681616U) + aNonceWordL;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 39U)) + 12773023438753662590U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 50U)) + 7331345852207096322U) + aPhaseAOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3899381212671247460U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10072004147620068599U;
            aOrbiterK = RotL64((aOrbiterK * 5663583566047763435U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3424585039401897560U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8246760141625966321U;
            aOrbiterC = RotL64((aOrbiterC * 11478879365443736383U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3655992860610853290U) + aNonceWordF;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 11154618022505863898U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 4791494171286145231U), 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 15629361991059709973U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10842068502278489664U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 17223002513104960799U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5571312349016336686U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 589313823745748879U;
            aOrbiterD = RotL64((aOrbiterD * 1356685926549786027U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + aPhaseAWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 10U) + aOrbiterF) + RotL64(aOrbiterK, 18U)) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterK, 39U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19998U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((aIndex + 20024U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 20062U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17818U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19560U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 29U)) + 7948891781097675369U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 13928362874228230226U) + aNonceWordM;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 21U)) + 10776180542602258926U) + aNonceWordL;
            aOrbiterJ = ((((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 5735115172149470447U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 47U)) + 5353591822981766987U) + aNonceWordB;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 562301708107268570U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10467810247578364868U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 10449089554007059823U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14541630141152308564U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2350076897065139429U;
            aOrbiterC = RotL64((aOrbiterC * 12222554362482034393U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17519109078651162228U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6061035173339902910U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 10021905773432907835U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15654836633731000065U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13723521735153718904U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2849680038315532197U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17336102435576647923U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10984689101753586739U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 38U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 48U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21972U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 23532U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 22679U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22291U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26399U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (((aWandererA + RotL64(aScatter, 54U)) + RotL64(aCarry, 27U)) + 785861751704720606U) + aNonceWordH;
            aOrbiterG = ((((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 15968088718435606299U) + aPhaseAOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererG + RotL64(aCross, 39U)) + 1393976526590347151U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 17240750947292745884U) + aNonceWordK;
            aOrbiterA = (((aWandererC + RotL64(aCross, 5U)) + 4921576136163183137U) + aPhaseAOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3334047873553153032U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15086509978458408698U;
            aOrbiterJ = RotL64((aOrbiterJ * 2162818176367899893U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 892391205397581998U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2965686403183767521U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 709160942482770225U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14632215393655706170U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 15740589515342377322U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 15677716942904794913U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 11131164813943086445U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 6988080581278900960U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 6412189142344044255U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16021254613117657178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6183615599897921154U;
            aOrbiterE = RotL64((aOrbiterE * 9976411093264211033U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 48U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 30U) + aOrbiterG) + RotL64(aOrbiterC, 54U)) + aNonceWordG);
            aWandererD = aWandererD + (((((RotL64(aCross, 21U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordI) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterG, 27U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31963U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 31689U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31622U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28742U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31226U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 16802219662864902427U) + aNonceWordL;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 11U)) + 14332033461409490629U) + aPhaseAOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 37U)) + 8781794298640286845U;
            aOrbiterD = ((((aWandererD + RotL64(aScatter, 46U)) + RotL64(aCarry, 11U)) + 8459933908074937264U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 1883580287986004426U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17500258188004626118U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7934811305150872870U;
            aOrbiterB = RotL64((aOrbiterB * 10039004285642030761U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6380363892361098905U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12623079132626676910U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 12406671746344127399U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10455208121949202703U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8805532707916767629U;
            aOrbiterH = RotL64((aOrbiterH * 666082374369701881U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9161544391400377699U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3501434325829663268U;
            aOrbiterI = RotL64((aOrbiterI * 7933545151293799637U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 651783304096081996U) + aNonceWordI;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 441505031509930622U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 8045355432310956143U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 12U) + aOrbiterI) + RotL64(aOrbiterD, 14U)) + aNonceWordA);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 37U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + aNonceWordF) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_BasketBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x99449F9E4BE3C923ULL + 0xE96661F4C9A82A70ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD84A33C3B3269137ULL + 0x8FCE1AF650AC4765ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC376B17B69245563ULL + 0xEA75B061A262B8E9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA692C95E24C7723FULL + 0xB565C24B73E2B472ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xACD2024299C1E49DULL + 0x90AD75960A0D8B39ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE8A1E62B3458DB4FULL + 0x86A29F3A4724BF4BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x85CE198373E5D69FULL + 0x9B646EDAC770F587ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x900B70E1FFF4227DULL + 0x9192D80F900549BAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC888AE65FF909E5FULL + 0xA27EE946DC8EF069ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA5E385FE41FE3F5DULL + 0xFB3BE6FBB1A44C8AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE98AD31EB645A6D5ULL + 0xD9657E2151CC8565ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8557FDB047F6F885ULL + 0x902A53C0704D1A5BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x86C183B58F2A14F1ULL + 0xF65215306E485620ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC424C63B59CD2989ULL + 0xC80852D81E1892A1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x80BC33E5019A0CCBULL + 0xE438B44F5E90184AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x823AEDE0BFA37E43ULL + 0xE10A0A591AE6F3B7ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 774U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 5273U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3540U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6614U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7111U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6795U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 48U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (aWandererH + RotL64(aScatter, 6U)) + 4752759164691497960U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 12088872623537639782U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 35U)) + 3734943577379734227U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 19U)) + 8854778183012444234U) + aPhaseBOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 23U)) + 16948373492893967275U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 43U)) + 7962415690046184385U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 10U)) + 1872682375669714454U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 7776801806943853566U) + aNonceWordN;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 16665439117257230732U) + aNonceWordA;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11088186766134265676U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10850237991780969350U;
            aOrbiterH = RotL64((aOrbiterH * 7547414856143095121U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6464817712131305812U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 244557182884209844U;
            aOrbiterD = RotL64((aOrbiterD * 2394270354887582889U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13261563971157415841U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2323811103717827362U;
            aOrbiterI = RotL64((aOrbiterI * 11483723582415081925U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12338803568475493422U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2811342930111104982U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5020981755203607757U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5554497011738996057U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12712169745460598698U;
            aOrbiterG = RotL64((aOrbiterG * 1985586486150377769U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17415058661427002973U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9430421222715343818U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 10321140659099470811U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3926618548181233180U) + aNonceWordM;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 6172453297026957838U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 1161551082037835233U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 8633288765997226004U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17270881130844274342U;
            aOrbiterB = RotL64((aOrbiterB * 8888559940161770791U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12232950994807835262U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15352600312956742750U;
            aOrbiterC = RotL64((aOrbiterC * 6140396356904933003U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 36U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterH, 6U)) + aOrbiterE) + aPhaseBWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterB, 51U)) + aPhaseBWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 56U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterE, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10678U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 12693U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 14880U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 10675U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11138U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14791U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9538U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (aWandererG + RotL64(aScatter, 51U)) + 1210605127156905516U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 23U)) + 11964595428173569519U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 5U)) + 16277319029916258482U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 10U)) + 12369497463101824572U) + aNonceWordE;
            aOrbiterE = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 6201248574067068202U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 1727477025667206661U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 43U)) + 1404510627789806851U) + aNonceWordJ;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 6948213591282018925U) + aNonceWordP;
            aOrbiterA = (aWandererA + RotL64(aIngress, 34U)) + 6688865181284421478U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3351130769402360855U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12681032488906270823U;
            aOrbiterD = RotL64((aOrbiterD * 3680893896579741263U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3591412591193726763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16153817571210878589U;
            aOrbiterE = RotL64((aOrbiterE * 4165137036092246349U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3808228354421006630U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1427373776207504205U;
            aOrbiterH = RotL64((aOrbiterH * 4534374093769595531U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1831554180932501132U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 1114853085120949215U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 4264176108298812905U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2080935638828366835U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 16104777999646489828U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 15205199362011777473U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9782806013673440791U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3721620299829386454U;
            aOrbiterG = RotL64((aOrbiterG * 6286765834910272409U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4013706412064296527U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5751022780695158579U;
            aOrbiterF = RotL64((aOrbiterF * 13766736471646116397U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17684546333240329338U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1106947111128020920U;
            aOrbiterK = RotL64((aOrbiterK * 3158839453318658951U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11564229705849500598U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1585817314460274286U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12687162159791577431U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 38U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 36U)) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 51U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterB, 21U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterD, 26U)) + aNonceWordI) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 41U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19760U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 18967U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 19899U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 24346U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19549U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22170U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 19922U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererE + RotL64(aCross, 10U)) + 6342299552323486695U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 12692748514781367538U) + aNonceWordH;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 29U)) + 8202639945493229155U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 51U)) + 4439975701793231639U) + aNonceWordM;
            aOrbiterK = (aWandererJ + RotL64(aCross, 35U)) + 16774235182859553759U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 8764155413335405667U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 5U)) + 7167848811974967685U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 19U)) + 16768278912125334220U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 9090838954826296201U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7644075729758006298U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17326182797908071215U;
            aOrbiterJ = RotL64((aOrbiterJ * 2408330168749256075U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16158809721888137555U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8029938783858263694U;
            aOrbiterI = RotL64((aOrbiterI * 12628072435324195483U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8716553521415553404U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7012599977009208840U;
            aOrbiterE = RotL64((aOrbiterE * 8775355876188948851U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13250558696578541499U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 13705957059101025396U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 16889495686487056367U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2796775206291902461U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13741676263512390669U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 10455782033465595947U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1691908360612389252U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4114939415206031540U;
            aOrbiterD = RotL64((aOrbiterD * 2797401802892718297U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2374911514440738727U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12377616933668803091U;
            aOrbiterB = RotL64((aOrbiterB * 2505164835116651215U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 681094033415259645U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13841322124900463362U;
            aOrbiterK = RotL64((aOrbiterK * 4210414203856902329U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18082983557580381338U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15731122225678626778U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 7785999919955613789U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterA, 24U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + aNonceWordP) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 60U)) + aOrbiterG) + aNonceWordC) + aPhaseBWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 41U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 6U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28236U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 26225U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 29297U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 25080U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30606U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32511U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32375U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 42U)) + (RotL64(aIngress, 13U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 11450949896247900941U) + aNonceWordJ;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 30U)) + RotL64(aCarry, 57U)) + 3905542253538116335U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 19U)) + 9529740545977785305U) + aNonceWordP;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 39U)) + 1856876631533143492U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 57U)) + 84253466320181686U) + aPhaseBOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererD + RotL64(aIngress, 53U)) + 12577480918745432444U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 35U)) + 5625703170397704029U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 10U)) + RotL64(aCarry, 13U)) + 694608607323629282U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 47U)) + 3993981243536262204U) + aPhaseBOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4119215953484892051U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8785040118556157146U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 17113521266125471625U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16234403619456882890U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10398727475672860610U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5086871400049644715U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18327987141759096769U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2645964788056875452U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 8778681366114628045U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2859452497983106129U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7196557924940881076U;
            aOrbiterG = RotL64((aOrbiterG * 14415389907490256711U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 930127943984174668U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15673596916054795749U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7505660488733199479U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16673140529110941163U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2258448294877833760U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 1821550319748977445U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6870209259643931219U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12749790107942194104U;
            aOrbiterK = RotL64((aOrbiterK * 4871407285968611725U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17131374134617173866U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6426448390733751612U;
            aOrbiterF = RotL64((aOrbiterF * 12490559588384058417U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15592826434339731146U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 14182944418026376183U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7218860482893476233U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 24U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 39U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterG, 14U)) + aOrbiterD);
            aWandererG = aWandererG + (((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aNonceWordI) + aPhaseBWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + aNonceWordB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aNonceWordE);
            aWandererF = aWandererF + ((((RotL64(aCross, 48U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + aNonceWordD) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_BasketBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD66C8EAC363ED805ULL + 0xBAF1066AF0367C38ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x93F9C1BF77E83451ULL + 0x9344A3416FA3B9A8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB54C703E6B173A65ULL + 0x944FF3F59FA24749ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFC7D647CB4B7B809ULL + 0x9DFF54E43B4B92AEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB945499AF063C651ULL + 0xD3FC29CBD729867AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB9F1A2AFE314B343ULL + 0x9A0B9F393BC1531DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x981C498260D1001FULL + 0xEA016B5E8A359F56ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8F1E16742094E59FULL + 0xE84380005C4132A9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8A1A03266E124AD5ULL + 0xD28B8B40A1B5A4A7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA031C86DCB0CE5E9ULL + 0xE7815CC275127F55ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE8937D5C4DBFE293ULL + 0xED022E52DF9CC3BFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8F41EDF9134C7489ULL + 0xD625D9C746FCD301ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF80012549AA05607ULL + 0xA86CE0E5A6B250A6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDDEEEE2A76D3C2FDULL + 0x866F94356357C0BBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE5415D94ED72571DULL + 0x828138FB83D42C93ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x95205876FA32056BULL + 0xA69037FB77902BD6ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3772U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 5131U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4838U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4808U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 750U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5419U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 38U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 10U)) + RotL64(aCarry, 23U)) + 6916817163240024692U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 19U)) + 14554930751292077817U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 1098305064484336101U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 12192821172420471527U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 57U)) + 2435134991707318845U) + aNonceWordH;
            aOrbiterK = (aWandererH + RotL64(aIngress, 29U)) + 1896745368738512624U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 35U)) + 1114996424222923873U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 9839135798371512656U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 8037967239603177043U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 7848951103759663025U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15185468738487237432U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4912098316394854543U;
            aOrbiterD = RotL64((aOrbiterD * 3072785550384399929U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13142688607850380888U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4507379759608945839U;
            aOrbiterA = RotL64((aOrbiterA * 2989332387754215967U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7299006009652289342U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5390655277207053627U;
            aOrbiterC = RotL64((aOrbiterC * 10973744708856143715U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6744737023577785725U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15539737698867067285U;
            aOrbiterK = RotL64((aOrbiterK * 4686092035261336911U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13329866734681377952U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13284937458969166257U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3965985432462699445U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 8695002088915702168U) + aNonceWordP;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 3858059421620839286U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 9559783727301092937U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + aNonceWordO) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterK, 4U)) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 23U)) + aOrbiterK) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5942U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 9252U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 7302U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6786U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8333U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9502U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8041U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 18U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 1898718075389870739U) + aNonceWordC;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 29U)) + 5631794889237247403U) + aNonceWordB;
            aOrbiterA = (((aWandererK + RotL64(aCross, 57U)) + 18219714659484524607U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 15419581386225732921U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 37U)) + 9125575431710198210U;
            aOrbiterI = (aWandererE + RotL64(aCross, 6U)) + 12205871520544965505U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 7617534300497343422U) + aPhaseDOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 18017579105368135814U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10693882161946020042U;
            aOrbiterA = RotL64((aOrbiterA * 2326507900303932855U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11669615701700895306U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11045110212889232165U;
            aOrbiterG = RotL64((aOrbiterG * 5965171269273719849U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 18019107802806469913U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12315940560472528716U;
            aOrbiterB = RotL64((aOrbiterB * 4505122470351404065U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4899009736070044310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17412253404253730364U;
            aOrbiterD = RotL64((aOrbiterD * 10791901166391946485U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4826286251927854181U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4523455921321845084U;
            aOrbiterF = RotL64((aOrbiterF * 14534103906736598099U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4132514462154182215U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7164745605985109269U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14107325508977225261U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6297434295807635654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8813887638672996646U;
            aOrbiterH = RotL64((aOrbiterH * 17495632530773158201U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 20U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + aPhaseDWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aIngress, 50U) + RotL64(aOrbiterH, 41U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterF, 60U)) + aNonceWordM) + aPhaseDWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13408U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 14588U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11715U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13334U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16276U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 24U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 27U)) + 13204735390996728477U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 14U)) + 851171359595647173U) + aNonceWordK;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 35U)) + 16745304202825290723U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 562392736584913979U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 57U)) + 3244267012529053918U) + aNonceWordL;
            aOrbiterE = ((((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 17282536111067869133U) + aPhaseDOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 14851130066471729068U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5256130407952363129U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2904742485828362001U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12941135856735075457U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3723346325449225387U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5344621093694027341U;
            aOrbiterB = RotL64((aOrbiterB * 9044881458629673499U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 12919263300833603026U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17989801264160996071U;
            aOrbiterF = RotL64((aOrbiterF * 15468293047311883751U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5022175042377172157U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16684822380107847758U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 2834049270263837537U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2740326510600876682U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13981423865219318820U;
            aOrbiterK = RotL64((aOrbiterK * 14593082145080056441U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 231945878229848395U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14139797734944312580U;
            aOrbiterE = RotL64((aOrbiterE * 6492256080432266407U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16704102101387552373U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8506734780526852552U;
            aOrbiterI = RotL64((aOrbiterI * 4684566118627414659U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 4U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aNonceWordB) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + aNonceWordA) + aPhaseDWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterH, 37U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 21U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19295U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 20020U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 18322U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18325U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 21013U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 48U)) + (RotL64(aCross, 35U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 22U)) + RotL64(aCarry, 39U)) + 14249093584376402677U) + aPhaseDOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererC + RotL64(aCross, 13U)) + 8756965951816492264U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 53U)) + 11221139480258176330U) + aNonceWordF;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 17218894445564194851U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 3U)) + 8064642692524949490U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 35U)) + 5822093203710704646U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 3217799620158102238U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2613757677892120843U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13647481499551657237U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5517563514031899891U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3545714196663685016U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9735422670576621521U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7276207208162697249U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3911046580637583767U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9315984027042049203U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 12568550776487242469U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8926367674641729058U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11035347490524961446U;
            aOrbiterH = RotL64((aOrbiterH * 10948288997163592463U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10748158733051120339U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2467801787989056455U;
            aOrbiterG = RotL64((aOrbiterG * 12621934274702358977U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9244415080474351390U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8517784887959492079U;
            aOrbiterF = RotL64((aOrbiterF * 17022899813765884147U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8409307332803038455U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11043806021873232950U;
            aOrbiterC = RotL64((aOrbiterC * 8294888329708842989U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterA, 21U)) + aNonceWordL) + aPhaseDWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aPhaseDWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterH, 27U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 58U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24793U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 26932U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26496U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22634U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 21931U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 13499155707765393469U;
            aOrbiterE = (aWandererF + RotL64(aCross, 43U)) + 3740324981823726185U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 37U)) + 5470765363949735652U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 23U)) + 3446436171274452326U;
            aOrbiterG = ((((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 1778929412631211933U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 4U)) + 14666308799855220954U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 4548410236791175055U) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5829739767694190372U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 14319231414903675748U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 4966501102515775601U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1513851750246111405U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1685620217748986019U;
            aOrbiterG = RotL64((aOrbiterG * 9286548037413609445U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16284162182006054402U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6271539598462003309U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 13923286694131331137U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12669312437565969473U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11894755313393001665U;
            aOrbiterH = RotL64((aOrbiterH * 12556759675372354075U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6315983824634946566U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17106616474222892782U;
            aOrbiterE = RotL64((aOrbiterE * 167205520766791073U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13350266700180455548U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4608846311203767162U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 2504857468837437365U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14195866746143604365U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7917977448256795054U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5927771378657284557U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterG, 60U)) + aNonceWordA) + aPhaseDWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 50U) + RotL64(aOrbiterH, 41U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB) + aNonceWordE);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31812U)) & S_BLOCK1], 18U) ^ RotL64(aInvestLaneA[((aIndex + 31415U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 32104U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31793U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 29291U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 10U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 60U)) + 15726877954695761686U) + aPhaseDOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aWandererD + RotL64(aCross, 3U)) + 14187652171881943587U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 8420423151313882782U) + aPhaseDOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 53U)) + 14942322692433259283U) + aNonceWordC;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 7272331475919796255U) + aNonceWordH;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 154504365041805840U;
            aOrbiterE = (aWandererG + RotL64(aCross, 43U)) + 17475491222554948786U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5759181483165339605U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5993060214499322845U;
            aOrbiterJ = RotL64((aOrbiterJ * 10799489831896153301U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10901786237875941844U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17135786595614068473U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15923538730142047043U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5208202073886811165U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6821452921018900631U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 13119330055184115669U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13348064837402206969U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8967943922403445136U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 300168481725373093U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8130283784171430891U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6351113882502502876U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 15960622823993072903U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6894708729226455769U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12065058511247133944U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5432601727436935831U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17138279326229372741U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12987698199066890628U;
            aOrbiterK = RotL64((aOrbiterK * 12665716655177320977U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aNonceWordE);
            aWandererF = aWandererF + ((((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 41U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_BasketBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF5F57D1019CC59A9ULL + 0x8C142D5F60B1629FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE7DE4F29C5021F47ULL + 0xB8227E78991A7BC0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA1BC0D6504FAD353ULL + 0xF58CD1AD9A1FDEC7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFDC54984FC163A63ULL + 0xE7C46784D5E9C404ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDF614FCDEC1FB785ULL + 0x8CB714DBE33D7432ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBEF966E181795A9DULL + 0xF43915500D9894DEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCB207E0E71923D8BULL + 0x900DCA21B6A5E79AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA51877442095A609ULL + 0xD6F8B52633F2A9C3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA566F82AD363F1B3ULL + 0xFAFFE9A4BE0E3BDDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCC35EBB3C6E5FD79ULL + 0x9BA04EBFE3583BB8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB51BF4F0CC09CC6DULL + 0xA805D55EA3789C45ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD6513CFFCF84502DULL + 0x9CECEF5003A9443DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC079040EFBC4287FULL + 0xEC5D5A625F088748ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD92EEBABFDE6E45BULL + 0xEED20ACD9BF9778AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCD7EDAA3DA95E18DULL + 0x953513E4BD66040BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF40D7CA2C26ECF69ULL + 0xE3C48E24E13C1783ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4520U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((aIndex + 2897U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3133U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2896U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1966U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 365U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 1142447269198373880U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 53U)) + 10581460640040336191U) + aNonceWordP;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 14703062773878202900U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 50U)) + 15737525756286914746U) + aNonceWordF;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 23U)) + 16178774478273186999U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 11U)) + 2514897053906809160U) + aNonceWordN;
            aOrbiterI = (aWandererA + RotL64(aScatter, 37U)) + 13702496607592508464U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 19U)) + 18030885275418337965U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 5241783876161655984U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 39U)) + 2807052676283587925U) + aNonceWordC;
            aOrbiterH = (aWandererD + RotL64(aIngress, 34U)) + 8022804576763271327U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15597099852232205860U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1538435607932096400U;
            aOrbiterA = RotL64((aOrbiterA * 7900752511710516981U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11147868774413615365U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9325213746830411568U;
            aOrbiterC = RotL64((aOrbiterC * 561819005818948769U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13792300423550555634U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3134856508983945719U;
            aOrbiterK = RotL64((aOrbiterK * 4271845067763664863U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8654966018053784882U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8937113935476779267U;
            aOrbiterG = RotL64((aOrbiterG * 7386875687217705855U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4135676350355234788U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11407912615743682678U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 2773506587480714695U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10966950663872392059U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6686634993700944582U;
            aOrbiterJ = RotL64((aOrbiterJ * 2509459942163678241U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 14154407529749257990U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18054640398549782388U;
            aOrbiterI = RotL64((aOrbiterI * 7830759861389060149U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14623473030642960240U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1857945571104460086U;
            aOrbiterH = RotL64((aOrbiterH * 18039903315045620079U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17650774450811065797U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9458168381246672881U;
            aOrbiterD = RotL64((aOrbiterD * 3452665113988737563U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16604923466236483242U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12447748535184711684U;
            aOrbiterB = RotL64((aOrbiterB * 5982708155382249061U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9589720286549780720U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1142447269198373880U;
            aOrbiterE = RotL64((aOrbiterE * 8176719948031280789U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 20U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 56U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK) + aNonceWordI) + aPhaseEWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterI, 37U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterG, 28U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 53U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10653U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 7261U)) & S_BLOCK1], 36U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 5977U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10914U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9541U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8756U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6155U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (aWandererG + RotL64(aPrevious, 20U)) + 6916817163240024692U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 43U)) + 14554930751292077817U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 11U)) + 1098305064484336101U) + aNonceWordO;
            aOrbiterC = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 12192821172420471527U) + aPhaseEOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 2435134991707318845U) + aNonceWordC;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 1896745368738512624U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 23U)) + 1114996424222923873U) + aPhaseEOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 13U)) + 9839135798371512656U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 5U)) + 8037967239603177043U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 27U)) + 15185468738487237432U;
            aOrbiterE = (aWandererE + RotL64(aCross, 52U)) + 4912098316394854543U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13142688607850380888U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4507379759608945839U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 2989332387754215967U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7299006009652289342U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5390655277207053627U;
            aOrbiterF = RotL64((aOrbiterF * 10973744708856143715U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6744737023577785725U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15539737698867067285U;
            aOrbiterD = RotL64((aOrbiterD * 4686092035261336911U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13329866734681377952U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13284937458969166257U;
            aOrbiterG = RotL64((aOrbiterG * 3965985432462699445U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8695002088915702168U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3858059421620839286U;
            aOrbiterK = RotL64((aOrbiterK * 9559783727301092937U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6609163873243179836U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 9416165620556710540U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 240385043740268229U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1578449067529000433U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14309000104419489303U;
            aOrbiterE = RotL64((aOrbiterE * 7599078306153684729U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15785180680737461320U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10099222679918382021U;
            aOrbiterB = RotL64((aOrbiterB * 2012232597046182581U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10666287769220108179U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13648647399222807034U;
            aOrbiterA = RotL64((aOrbiterA * 10772381733103127201U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9292207828896796810U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9155130791347443553U;
            aOrbiterJ = RotL64((aOrbiterJ * 16838229790655977057U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11334395119119245556U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6916817163240024692U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9640906826978028183U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 35U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 24U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterG, 29U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 46U)) + aOrbiterD) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 28U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 37U)) + aOrbiterF) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterC) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12588U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((aIndex + 12090U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11431U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12823U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12333U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 46U)) + RotL64(aCarry, 11U)) + 2786079456995203065U) + aNonceWordA;
            aOrbiterH = ((((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 7237256119153857253U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererE + RotL64(aCross, 41U)) + 9310834010563647604U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 21U)) + 17361734905706517877U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 51U)) + 15837111231884647451U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 43U)) + 18065431964418026445U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 39U)) + 3029123922999952652U) + aNonceWordC;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 54U)) + RotL64(aCarry, 19U)) + 5166926595573507837U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 23U)) + 1918425684273807598U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 37U)) + 4724551751012661440U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 5U)) + 1818014487579644390U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6670090372241084216U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8485757110007268693U;
            aOrbiterD = RotL64((aOrbiterD * 11876760095108618363U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4928130251509514742U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2528788422725346792U;
            aOrbiterG = RotL64((aOrbiterG * 1855982047967756661U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2860387120895147503U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12927802338151379368U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8876144125458603029U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18029699867733207083U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13361836994951253312U;
            aOrbiterB = RotL64((aOrbiterB * 5349767426256597073U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11957294454794128079U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3755417922063414648U;
            aOrbiterH = RotL64((aOrbiterH * 13896364063651241401U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 18001157153447913032U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16214145724690286854U;
            aOrbiterI = RotL64((aOrbiterI * 5874139687703360515U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3860958772090975562U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12395621524459640173U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 722817135977510161U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3402035664910754484U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2139099117325745602U;
            aOrbiterK = RotL64((aOrbiterK * 14008983756425796029U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7769274487425053026U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6492669707749367728U;
            aOrbiterA = RotL64((aOrbiterA * 5149771861620757839U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14963366447884375043U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11398874662567519691U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8221521452475029835U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7168445485232814860U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2786079456995203065U;
            aOrbiterE = RotL64((aOrbiterE * 14258367164534307955U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 12U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterB, 21U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterC, 4U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterF, 48U)) + aOrbiterK) + aNonceWordK) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20743U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((aIndex + 21348U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 17286U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21232U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19250U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 12206125048349568300U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 13U)) + 5843520589343188818U;
            aOrbiterK = (aWandererK + RotL64(aCross, 48U)) + 12195046124287121687U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 19U)) + 16769779119214020640U) + aPhaseEOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 5257603646260695833U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 37U)) + 8523523946234886745U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 56U)) + 7316024684200084096U;
            aOrbiterJ = ((((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 11996978575084115207U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aWandererD + RotL64(aIngress, 11U)) + 15491711479085513628U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 53U)) + 6036648530996821484U) + aNonceWordK;
            aOrbiterC = (aWandererE + RotL64(aCross, 41U)) + 926323222234121863U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2700323841295743492U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5852273765810284935U;
            aOrbiterK = RotL64((aOrbiterK * 16665696735016345215U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11697397483133538067U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17777142964957007194U;
            aOrbiterH = RotL64((aOrbiterH * 6338967222543284999U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 10892176201151170298U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11759700374509499684U;
            aOrbiterB = RotL64((aOrbiterB * 14247697264744736081U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11343756773329590643U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15785048929757652350U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17208103574389502597U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7508839228498497238U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 13088508510402094665U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 15730279447009669103U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16259236641717377699U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11228995722951003980U;
            aOrbiterC = RotL64((aOrbiterC * 4870092259515181323U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13775851561528617086U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3023564646900497080U;
            aOrbiterF = RotL64((aOrbiterF * 9936548213275464131U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 154952467284609583U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 14239675888632174461U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 1370550680736926425U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 168749514558708557U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5070416708211422927U;
            aOrbiterI = RotL64((aOrbiterI * 13631900152346927703U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1961290602001581341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12235345489656113478U;
            aOrbiterE = RotL64((aOrbiterE * 14403534235273302211U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2295581049708176078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12206125048349568300U;
            aOrbiterD = RotL64((aOrbiterD * 6008868846674396181U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 27U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 13U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 4U)) + aOrbiterJ) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 60U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 56U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + aNonceWordF);
            aWandererH = aWandererH + ((RotL64(aCross, 48U) + aOrbiterD) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26817U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneB[((aIndex + 25533U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27130U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22580U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 22058U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 24U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 56U)) + RotL64(aCarry, 11U)) + 15188686795415908074U;
            aOrbiterF = (aWandererC + RotL64(aCross, 47U)) + 17310049041983079779U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 13U)) + 8246925977992441471U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 27U)) + 8644260919918112781U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 13401663736874819483U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 53U)) + 7940358935238314973U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 29U)) + 13278990328548007839U) + aNonceWordO;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 11346868298353840706U) + aNonceWordG;
            aOrbiterI = ((aWandererI + RotL64(aCross, 50U)) + 2374077904806833579U) + aNonceWordE;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 35U)) + 6978903378645019166U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 41U)) + 11951633297870965212U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17398460995357409673U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1215437945597836770U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 9322970054123481621U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 1878751468043972239U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5343002808239712390U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 11878640995447558811U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9884918450053276861U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15894599082080422550U;
            aOrbiterK = RotL64((aOrbiterK * 8359936745539546131U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13917339232771145459U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18101134009493720683U;
            aOrbiterG = RotL64((aOrbiterG * 15835859435306756387U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3830086372356903769U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15894394599564584010U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9513921913446609263U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5127590955274245812U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9410946933309720054U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 14507476989423060561U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15544384157294987085U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 998801294460434123U;
            aOrbiterD = RotL64((aOrbiterD * 5946968142746472745U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16442095194965452163U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14294936349037516932U;
            aOrbiterC = RotL64((aOrbiterC * 14655345374740882581U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16680659892463349201U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10921918150041635666U;
            aOrbiterA = RotL64((aOrbiterA * 2908474941036821745U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15350264522133299871U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16413848767507968239U;
            aOrbiterI = RotL64((aOrbiterI * 10226942289998651355U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11963105565077056299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15188686795415908074U;
            aOrbiterF = RotL64((aOrbiterF * 13002484121826831091U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 46U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterD, 56U));
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + aNonceWordP) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterA) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aIngress, 42U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterB, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30356U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 28440U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31685U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27339U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 28528U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererI + RotL64(aIngress, 41U)) + 6521330037475130256U) + aPhaseEOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererF + RotL64(aScatter, 56U)) + 12611880456055428940U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 12061611078130934708U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 35U)) + 1558112410801116984U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 43U)) + 10509115227850160786U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 13U)) + 4045915960688792066U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 1196541286513243082U) + aNonceWordE;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 20U)) + RotL64(aCarry, 27U)) + 15564991032722373702U) + aNonceWordM;
            aOrbiterC = (aWandererH + RotL64(aScatter, 37U)) + 4897765238703641798U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 39U)) + 12327429514907752733U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 53U)) + 6189189797708711636U) + aNonceWordL;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6374267075282018852U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1888758503831341439U;
            aOrbiterA = RotL64((aOrbiterA * 74387714918264257U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14956857689299491800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14879361107223331957U;
            aOrbiterH = RotL64((aOrbiterH * 9166712966729591953U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16086885494838105042U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8069724185844303923U;
            aOrbiterK = RotL64((aOrbiterK * 8878470736758734353U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10854345917959911439U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7078313614360332089U;
            aOrbiterD = RotL64((aOrbiterD * 9864025732292844871U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15083669236062255011U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 594879695916679116U;
            aOrbiterI = RotL64((aOrbiterI * 9852515479152735283U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6721466068234534523U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 475816724162626782U;
            aOrbiterG = RotL64((aOrbiterG * 4799725182757588407U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4341655358154605899U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15477254302340298586U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13961520225881974201U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10179091913200895775U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6310490897546909571U;
            aOrbiterF = RotL64((aOrbiterF * 15080621088825477613U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13462682513035460711U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16739138858084100385U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16386371811268298031U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13608837667062268989U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12902415667552110103U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 16398790854093048017U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16596211634603915761U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6521330037475130256U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 631958426544321145U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 4U);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterA, 42U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 26U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterC, 40U)) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8A8F580B654FFBFBULL + 0xD1DBF7DDA6B9A528ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA213287718F775B5ULL + 0xE235E16ABD60058BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC3DD3D144AE22989ULL + 0xDF41CDA1E11236A6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD1E4F497A69452A9ULL + 0xF87C8AAEAA3767E6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEC5D1ECD25EB6CE3ULL + 0xF7AB5CC96487F946ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD25A168351013D6DULL + 0xDACFD65A995CFFCCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFF7B2D0388FF8A09ULL + 0x9D83DC22DC0BB520ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xABFFA06E0161DF4BULL + 0xB488494330CAE3EFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAE7362CFA65D203FULL + 0x933652693ABF6C0BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8D34D13158D2A479ULL + 0x9413559B0318DD60ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB127EF9387DDA327ULL + 0xA2323F6849AFC290ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB8A982E14A3C2BC9ULL + 0xF9FF597AA26D00C1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDB72A116E20813CBULL + 0xE306233F550328E5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFC86266991D4EB0FULL + 0xF17990C8F6B6C441ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8C2E82A138C8A76DULL + 0x90ADEABCDDA50468ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC731057E518B49B1ULL + 0xB3F8384CE75018F4ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1528U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 3403U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1357U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5056U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2002U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2242U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = ((aWandererH + RotL64(aCross, 58U)) + 16016931609704150191U) + aPhaseFOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 14511433515861302636U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 29U)) + 11691237442613269593U) + aNonceWordP;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 43U)) + 16383220587320484649U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 51U)) + 14293015313458219868U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 21U)) + 4407695248205526670U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 14U)) + 1158323195324398372U) + aNonceWordN;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 6577683409653864555U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 171080079472863843U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5766333425872228205U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16173508656917582960U;
            aOrbiterI = RotL64((aOrbiterI * 12187968015372936695U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11781450063402219202U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13033139686637576694U;
            aOrbiterE = RotL64((aOrbiterE * 4331137994135472025U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 4006310759400926020U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13156817947481574467U;
            aOrbiterB = RotL64((aOrbiterB * 563189239835001483U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12791290558893516411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 989729955679243234U;
            aOrbiterA = RotL64((aOrbiterA * 8757228712495095017U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 838379839663022790U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2830743864262313606U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10173947177104802797U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2146646527331684652U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4629168181742174906U;
            aOrbiterH = RotL64((aOrbiterH * 9046124907945045131U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1150129989168501777U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 619659995945229440U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 13734821008174603409U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8120315647582116952U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13754584116324996165U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 12295486140772079747U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6084566798869999580U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5731665119233722504U;
            aOrbiterD = RotL64((aOrbiterD * 5921510209025133639U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 6U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterD, 42U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + aPhaseFWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + aNonceWordI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 38U)) + aOrbiterA) + aNonceWordJ) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 12U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9156U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 5484U)) & S_BLOCK1], 22U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9545U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 9862U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8819U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8086U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5958U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 47U)) + 15316464782468770057U) + aNonceWordB;
            aOrbiterA = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 6642872057476351588U) + aNonceWordH;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 38U)) + 660732654689529192U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 43U)) + 7235418086884000655U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 14784518476694580493U) + aNonceWordK;
            aOrbiterB = ((aWandererI + RotL64(aCross, 5U)) + 12222433977933449375U) + aNonceWordG;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 8573001207708329927U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 34U)) + 16035256260815013172U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 19U)) + 15767726974121910203U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17712217935322939971U) + aNonceWordO;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 13488963456923357159U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 16785285630840310405U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10222949131965611079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1495561412321657209U;
            aOrbiterC = RotL64((aOrbiterC * 9706305581868526265U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16156530750584361434U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7773792489045606309U;
            aOrbiterJ = RotL64((aOrbiterJ * 10730624207715601393U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11544578291333360613U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3665587867634242865U;
            aOrbiterH = RotL64((aOrbiterH * 4840528190844842595U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15248434984650998090U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15487979645426567581U;
            aOrbiterK = RotL64((aOrbiterK * 10868107809356766183U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 6972347795052712690U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16074994810010431338U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1262655238856775853U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16851139687900415292U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14630026837021552812U;
            aOrbiterE = RotL64((aOrbiterE * 9577900853521254603U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14236330619137368169U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17778707026111136216U;
            aOrbiterF = RotL64((aOrbiterF * 16239561893843454747U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9390961969105999083U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1174881758316573228U;
            aOrbiterB = RotL64((aOrbiterB * 6602061268277529311U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + aNonceWordI) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterK, 60U));
            aWandererC = aWandererC + ((RotL64(aScatter, 14U) + aOrbiterG) + RotL64(aOrbiterK, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 42U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13901U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 13601U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12971U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12009U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 15959U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 22U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 3238389262925516513U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 47U)) + 12381787182611386995U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 18U)) + 7883885539305181549U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 1185413044597727092U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 27U)) + 15219353497204773135U) + aNonceWordO;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 53U)) + 7533774715626734082U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 2599930450937763464U;
            aOrbiterI = (aWandererK + RotL64(aCross, 5U)) + 16074720663961214284U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 36U)) + 15483613196360051221U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9396557867081376268U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9668459976852660245U;
            aOrbiterD = RotL64((aOrbiterD * 11748505665890567063U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9037269914643207212U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16936742640861088240U;
            aOrbiterK = RotL64((aOrbiterK * 1040172193161012227U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16481274825758546398U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 481851372837611166U;
            aOrbiterB = RotL64((aOrbiterB * 2225030139210599207U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13608921517203544108U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16930740723286214636U;
            aOrbiterF = RotL64((aOrbiterF * 2605108503821980865U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 902242902582149908U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1510861213079342977U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3309753895727400707U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7116243600304980310U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6631412278359709602U;
            aOrbiterE = RotL64((aOrbiterE * 11452627691392637463U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9246698682265275165U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 8594373032014031450U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 2550138341089957033U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15912837963877821048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11404583513022627609U;
            aOrbiterJ = RotL64((aOrbiterJ * 17715204726760125357U), 39U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 17295214920690244319U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18315664494984189344U;
            aOrbiterG = RotL64((aOrbiterG * 17398893532076312945U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 24U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterE, 34U)) + aOrbiterD) + aNonceWordE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 60U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 47U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 24U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16656U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneA[((aIndex + 19619U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21171U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17891U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16831U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererJ + RotL64(aScatter, 29U)) + 16802219662864902427U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 56U)) + RotL64(aCarry, 3U)) + 14332033461409490629U) + aNonceWordM;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 41U)) + 8781794298640286845U) + aPhaseFOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 8459933908074937264U) + aNonceWordC;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 1883580287986004426U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 35U)) + 17500258188004626118U) + aNonceWordF;
            aOrbiterG = (aWandererC + RotL64(aCross, 12U)) + 7934811305150872870U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 51U)) + 6380363892361098905U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 3U)) + 12623079132626676910U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10455208121949202703U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8805532707916767629U;
            aOrbiterC = RotL64((aOrbiterC * 666082374369701881U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9161544391400377699U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3501434325829663268U;
            aOrbiterF = RotL64((aOrbiterF * 7933545151293799637U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 651783304096081996U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 441505031509930622U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8045355432310956143U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1771159983581326424U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15227946417377695989U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1563141188972797601U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4153717524193279095U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4404521756523902829U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 1410342912973206203U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6231945075461813285U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3864780227164426690U;
            aOrbiterG = RotL64((aOrbiterG * 18031353247480673617U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1509699687948576558U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17316114302489411191U;
            aOrbiterB = RotL64((aOrbiterB * 15490661284980281585U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2250572827340157410U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6403966113144372915U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 726441947009132383U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2329903609147403156U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2486330017319455238U;
            aOrbiterJ = RotL64((aOrbiterJ * 17427461345935191757U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + aNonceWordI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 4U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterC, 14U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 42U) + RotL64(aOrbiterG, 19U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterF, 6U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterE, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23645U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 24156U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25540U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24114U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneA[((aIndex + 22024U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 4U)) + 16424657151168221875U) + aNonceWordD;
            aOrbiterD = (aWandererC + RotL64(aCross, 23U)) + 17150123681886380361U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 16041993588694572757U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 9871185846434828537U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 41U)) + 11227236398354430757U) + aPhaseFOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 51U)) + 5399325217402192631U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 9248828789282890454U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aScatter, 46U)) + 9041370494203701062U) + aNonceWordG;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 37U)) + 14944424084524970764U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5481938174456671041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14783648629543752715U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 7260164783191886395U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12355573914530445723U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9863991559011968318U;
            aOrbiterH = RotL64((aOrbiterH * 8495251211794343179U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16149688605937250965U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 106041828692026825U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 12199934305374582599U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8076098639554567792U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11155119311895580013U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1495180896564818647U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6847612160595917702U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16094377920388017367U;
            aOrbiterI = RotL64((aOrbiterI * 4875801863643206333U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13584719866672696684U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13446209321646234607U;
            aOrbiterC = RotL64((aOrbiterC * 9945349065094781529U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15829806645369560988U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12573767256739062550U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 5649504278826069077U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3850030870300393809U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11857593987748189858U;
            aOrbiterB = RotL64((aOrbiterB * 15942863910931814193U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5505918410521728373U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12949653497121247860U;
            aOrbiterG = RotL64((aOrbiterG * 90944913639560027U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterB, 24U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterK, 14U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 40U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32454U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 29031U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 32637U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30375U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32206U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 56U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 14U)) + RotL64(aCarry, 21U)) + 17081642665820489793U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 57U)) + 14468854040067229623U) + aNonceWordH;
            aOrbiterK = (aWandererF + RotL64(aIngress, 51U)) + 2249450222593057429U;
            aOrbiterF = ((((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 14964389079511378664U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aWandererD + RotL64(aIngress, 36U)) + 17003491054252360650U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 12710882240582032588U;
            aOrbiterD = (aWandererI + RotL64(aCross, 19U)) + 9887078182156755359U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 47U)) + 7665284531810584704U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aIngress, 41U)) + 7304284015511876717U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5517927023543751734U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17704756310857362759U;
            aOrbiterK = RotL64((aOrbiterK * 15826832172923213591U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11347400363019508578U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11696395232760991243U;
            aOrbiterE = RotL64((aOrbiterE * 9725231749679442003U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10875780291242873583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7808740614343437672U;
            aOrbiterD = RotL64((aOrbiterD * 8889516201913716283U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3145390996141902032U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 16080636485642732615U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 7445756373012217305U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3929263288176983844U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 18210228766683996806U;
            aOrbiterA = RotL64((aOrbiterA * 13178080076505449091U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13948962323541421431U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3037683309790156893U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 13406672352222636739U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17827265198532699474U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7270895262023504864U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13467417362477308167U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6431243064980879185U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6680205390976259885U;
            aOrbiterG = RotL64((aOrbiterG * 10421386694108590789U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15910655919164357152U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8046213498216027383U;
            aOrbiterI = RotL64((aOrbiterI * 18061867495824063553U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 47U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 12U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererD = aWandererD + (((((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 11U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 18U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9EA85466F4B7D8F5ULL + 0xBB3362E42D3340C7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x80E583AA8AEE6969ULL + 0x8CD424CB8CCFED7CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x83EB453797659699ULL + 0xE974E2B7BEDD8577ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDCA0C77D67CE89BDULL + 0x9778976DA3CD5C5DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFBC3589BE40DC6B9ULL + 0xD5C17E4C5BA45810ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF42CC43347F9B795ULL + 0xA1EE7C68610E805BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8441AD3A0DE2F98DULL + 0xB7D1328E130F19A2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFE2BF4EB1F051EEDULL + 0x8513644060AB523DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE910F46ABADD46B7ULL + 0xEB6F62C56FE1234DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9097F6BD6258790FULL + 0xC045AC1A85A03B06ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF0BBD817A9DCB003ULL + 0xEFEB0D4DED3247D7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x94A3C9C06EB81ED5ULL + 0x94322E1C9606C6E6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9ED420BFC30E69E1ULL + 0xA2FA51B5353B8B86ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x980228BDFBC9AFD3ULL + 0xB2D1EF06BDCF5928ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x972CC13AC7AE5B01ULL + 0xE848EFCFD306C290ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x90929ECF70668BEDULL + 0x949EDE088C3FB7F5ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 100U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((aIndex + 3918U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2350U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3332U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1948U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1345U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererI + RotL64(aIngress, 37U)) + 5088525177670191619U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 19U)) + 9966456257813932112U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 7707646574027146307U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 3U)) + 75480203757681173U) + aNonceWordD;
            aOrbiterD = ((((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 384659134071835163U) + aPhaseHOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 3158769775373307778U) + aNonceWordG;
            aOrbiterK = (aWandererF + RotL64(aCross, 56U)) + 17360830943513941272U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 5317278822721604586U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1371427105215954781U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10956603063464438611U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3162710551223553423U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5332921933853550756U;
            aOrbiterD = RotL64((aOrbiterD * 11709546145149357887U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10572462410297815854U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10234389605554817892U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2130374833440291193U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13421365517991380605U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10186643614984034083U;
            aOrbiterC = RotL64((aOrbiterC * 8554471709467808453U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4742438973260817120U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 6081590345899008846U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 7069396301823124931U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15360092808493795340U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12186413069553132646U;
            aOrbiterB = RotL64((aOrbiterB * 3815981440611914267U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16756221656224451552U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12232880965861373143U;
            aOrbiterK = RotL64((aOrbiterK * 14196910735715726471U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 28U) + aOrbiterC) + RotL64(aOrbiterE, 47U));
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD) + aNonceWordP);
            aWandererF = aWandererF + (((((RotL64(aCross, 53U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordE) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 60U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7311U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 6530U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 8283U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 9214U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 5545U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6436U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10069U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 53U)) + (RotL64(aCarry, 22U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 8866844335448071821U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererI + RotL64(aCross, 29U)) + 15159698739856430085U) + aPhaseHOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 9582805772989594633U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 21U)) + 1438538239931588373U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 3U)) + 10862044156620436139U) + aNonceWordI;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 13682173320058164615U) + aNonceWordB;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 60U)) + 8351013291045977592U) + aNonceWordO;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15777857431516633916U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16178966745333885377U;
            aOrbiterE = RotL64((aOrbiterE * 7545129923202147703U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9031889187993001617U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6308472367425865347U;
            aOrbiterC = RotL64((aOrbiterC * 17118710301967158153U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 642109145903321046U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9186268569255318035U;
            aOrbiterI = RotL64((aOrbiterI * 10714674348507516749U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6091345356803675860U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 13218507921880873749U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15415157927185637717U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 4266652275234474616U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4391422098164506195U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17634679403195085867U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5160682323243635577U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10351728852161347404U;
            aOrbiterK = RotL64((aOrbiterK * 11105410036471745951U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3950932176454814023U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9536466386833427441U;
            aOrbiterD = RotL64((aOrbiterD * 18064984243491293435U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 20U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + aPhaseHWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI) + aNonceWordK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11351U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneA[((aIndex + 11220U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 13113U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11826U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15764U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 3970829908171131502U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 7040283759419531991U) + aPhaseHOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 29U)) + 11856292169397052901U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 41U)) + 819598588791819022U) + aPhaseHOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 10U)) + 2176451710970866848U) + aNonceWordN;
            aOrbiterF = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 6454704928613390494U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 53U)) + 11792122387218053841U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9254780213489752211U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16591812589999846482U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5425771603523423167U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1471246223935074832U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1424843083106386453U;
            aOrbiterB = RotL64((aOrbiterB * 15020536982657410783U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1856469958050891629U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6331743690452052712U;
            aOrbiterE = RotL64((aOrbiterE * 15327924647897459645U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10351075711345476487U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9518585245330480185U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 3792179827396760391U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17787514620244712033U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14182328067398162557U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 18107337388659070197U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12798088948801072444U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9563215159275202323U;
            aOrbiterD = RotL64((aOrbiterD * 7058145016617349141U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9904919772580498232U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16579777394992143043U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 10516761340320196661U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 60U)) + aOrbiterE) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + aNonceWordJ) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 48U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19160U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 18889U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20086U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19302U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18699U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererF + RotL64(aIngress, 3U)) + 3684295017013759987U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 21U)) + 6740408842457292881U) + aPhaseHOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 13U)) + 4563975890702399441U) + aNonceWordB;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 797804144825287940U) + aNonceWordP;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 41U)) + 2763779540450101303U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 13211846164102089685U) + aNonceWordM;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 15214578447281401982U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13745208628754232427U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17358621225969190747U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 5325024317338823061U), 37U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 779739369960480023U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4370963533701407813U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 3123135216876641039U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6061333005507739975U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3589705340762734456U;
            aOrbiterB = RotL64((aOrbiterB * 16499293983611196967U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10607697666369230567U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9356757995305239271U;
            aOrbiterC = RotL64((aOrbiterC * 10945513661439954731U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10093033335903048138U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11037328061699834100U;
            aOrbiterA = RotL64((aOrbiterA * 11189760551792389605U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 558431161176115540U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17795680919453449358U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3910117359996283803U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6096779391116214109U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17594243286880690775U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12655610181937429915U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererH = aWandererH + ((((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterI, 37U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterA, 21U)) + aNonceWordD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26364U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 24497U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 26968U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22179U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 22260U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCross, 43U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 41U)) + 4980738603982643969U) + aNonceWordP;
            aOrbiterG = (aWandererI + RotL64(aScatter, 21U)) + 17660278413018470020U;
            aOrbiterI = ((((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 17598114429859543466U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 10993929335279994739U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 29U)) + 17967203122976322481U) + aPhaseHOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 57U)) + 1872290205549034384U) + aNonceWordF;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 5U)) + 16607778671782810797U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4895226930754394376U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 14960359005982301383U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 8546231310054433721U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9921642352377700630U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 893281964367208693U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2345509157333444217U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8232519988397858732U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4433022122758913407U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 834240393225479419U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12689609831247168353U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 404535388957472176U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 14534020545479806593U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3349108201964013155U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4386449511297371730U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9596273264321140229U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14314587717949070586U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10923886625271054985U;
            aOrbiterA = RotL64((aOrbiterA * 7838969002623486809U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17634909585329833520U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2021301459918350372U;
            aOrbiterF = RotL64((aOrbiterF * 1388242915918642741U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 43U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterG) + aNonceWordC) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27378U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 30733U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31063U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29744U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 32506U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 12U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 9654059367478508868U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 53U)) + 6473006635864677427U) + aNonceWordA;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 29U)) + 6944184481315853243U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 19U)) + 4061496421939102306U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 23U)) + 15791809275719085463U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 3U)) + 14050798802646323055U) + aNonceWordO;
            aOrbiterI = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 12072905924741758266U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17639076509231343896U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12195388285571234715U;
            aOrbiterK = RotL64((aOrbiterK * 4317060502521195769U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4325404419499496529U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5910567888204238382U;
            aOrbiterE = RotL64((aOrbiterE * 11503787177122206937U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13092940059929942699U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13381962590820308761U;
            aOrbiterJ = RotL64((aOrbiterJ * 6345904465930943295U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15622862439323440527U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14027151901132249793U;
            aOrbiterI = RotL64((aOrbiterI * 2273573821630510087U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4584410023907605157U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15763755180625487157U;
            aOrbiterA = RotL64((aOrbiterA * 6755736130607297639U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17023059745666559199U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5298529579288492971U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 2483562793328357721U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2870152867331654736U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12017191100173748848U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 9958191466506480519U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterE, 41U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 57U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterC, 56U));
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 35U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_BasketBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1389U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1794U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2417U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 787U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 43U)) + 1557680213571812384U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 7387349725778021121U;
            aOrbiterC = (aWandererH + RotL64(aCross, 39U)) + 15379264067601586976U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 3730195724576043708U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 27U)) + 9637070085323827066U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 1170865717363676184U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 23U)) + 2750833653175252030U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 15118992811225568305U) + aPhaseAOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aScatter, 56U)) + 4974092922102988451U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10625719096296719514U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 855167122475471865U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7441090331293158773U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11322911068958340262U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4334591909425429835U;
            aOrbiterI = RotL64((aOrbiterI * 10059025861172038183U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14263701737208936392U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 678723206735649084U;
            aOrbiterJ = RotL64((aOrbiterJ * 10823239851733632227U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15652053114252065230U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1705225940224061401U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3626023093533713579U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6826394665732900206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11902946775066981141U;
            aOrbiterE = RotL64((aOrbiterE * 18300629262162694137U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9802212958998591310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14001358545610206524U;
            aOrbiterD = RotL64((aOrbiterD * 13172645840788327099U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4299184726135884309U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7288757011999872416U;
            aOrbiterK = RotL64((aOrbiterK * 16806027820468277393U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 233801262480580205U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14208660347238680268U;
            aOrbiterG = RotL64((aOrbiterG * 6299693448313154603U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9217797359740446104U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 18165073197136050838U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11677479094709512887U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 30U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 18U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + aPhaseAWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD + ((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 18U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + aPhaseAWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 5312U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[((aIndex + 4482U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2892U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4695U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 20U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 57U)) + 17225673071833726819U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 10301458382103627331U) + aPhaseAOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 19U)) + 3960233050857362414U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 24U)) + RotL64(aCarry, 11U)) + 17768665685046605837U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 13U)) + 14471018461213959767U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 29U)) + 10730597892721340453U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 5U)) + 14863394003122760542U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 3U)) + 9948587274816688296U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 35U)) + 3573569431435100993U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8153670675740450590U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16438856577722561424U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4689247488336908827U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15765587867581925041U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1082039522061775213U;
            aOrbiterD = RotL64((aOrbiterD * 17023740047246402641U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4202521649260798876U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15877659681260461141U;
            aOrbiterF = RotL64((aOrbiterF * 11369910758551088173U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2551560426129646123U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3005102326163906320U;
            aOrbiterK = RotL64((aOrbiterK * 4241583192662435107U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1675501058857208089U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12774812270956702043U;
            aOrbiterC = RotL64((aOrbiterC * 5488437008504905105U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1044886020922563597U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4857445127457225171U;
            aOrbiterI = RotL64((aOrbiterI * 13223560654459705259U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11548725551787560962U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2434677823189765161U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4283026044563670969U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9606875320524736294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13732615866277657704U;
            aOrbiterA = RotL64((aOrbiterA * 3905528919281629775U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13921743663803299567U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13350829301153929899U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11858642286713079795U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 14U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 56U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aIngress, 24U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 47U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 51U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aScatter, 10U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + aPhaseAWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterA, 24U)) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterB, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 8156U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 7955U)) & W_KEY1], 46U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6535U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7365U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5651U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 1042610313571524121U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 3505725321008825582U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 52U)) + 12584654563843782991U) + aPhaseAOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 23U)) + 6645399144515770935U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 47U)) + 3608978423753715584U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 11U)) + 8089198857670370983U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 15207251813516399879U;
            aOrbiterK = (aWandererC + RotL64(aCross, 18U)) + 9579268660105824516U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 27U)) + 16055044469473802812U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 583811872609805949U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7027491967970873942U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12686754713465826139U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 18256061823189677508U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12708429127816136937U;
            aOrbiterA = RotL64((aOrbiterA * 12593886633108075321U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12169216645156306078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12694325407567795065U;
            aOrbiterD = RotL64((aOrbiterD * 3711789483877261899U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16109994660203297503U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4234704064165718913U;
            aOrbiterG = RotL64((aOrbiterG * 730085881474787681U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14119541943554602878U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8777769004811352951U;
            aOrbiterI = RotL64((aOrbiterI * 2556957257736134223U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15642663488392549609U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11594468530833278624U;
            aOrbiterC = RotL64((aOrbiterC * 6639306656361601143U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7365350535791499871U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5965170981970155956U;
            aOrbiterK = RotL64((aOrbiterK * 1898702752753066851U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9115232101451815522U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9433983580038990072U;
            aOrbiterJ = RotL64((aOrbiterJ * 1951249217843992179U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8810565477444156140U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12081286530401844859U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1991383259486140229U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 34U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 42U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + aPhaseAWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterG, 4U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aPhaseAWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 57U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8815U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 10696U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(mSource[((aIndex + 8525U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9578U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10364U)) & W_KEY1], 43U) ^ RotL64(aFireLaneB[((aIndex + 8579U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 9774364261626083532U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 3U)) + 18059001521926116420U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 10615626210406381148U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 50U)) + RotL64(aCarry, 39U)) + 10536484278007898620U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 23U)) + 13320663045139972700U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 11U)) + 17127001787268166583U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 16742574590844166551U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 19U)) + 8347719720758228053U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 58U)) + 13502468705946051986U) + aPhaseBOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3512687886188904904U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 495660316165795934U;
            aOrbiterC = RotL64((aOrbiterC * 6724596801190194913U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5092722552034477356U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15641128019608284015U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3621036395703527059U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15421873776811085458U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17978775513204574125U;
            aOrbiterD = RotL64((aOrbiterD * 18359600395119440183U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16617179197537669849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1931805387534012528U;
            aOrbiterK = RotL64((aOrbiterK * 3400139345857733775U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9544923119559308431U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12930999400470173353U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16791006919271490005U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13673733276226249890U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2032263473309124738U;
            aOrbiterF = RotL64((aOrbiterF * 3088728329261360607U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14868502349358414206U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10116495537187552321U;
            aOrbiterJ = RotL64((aOrbiterJ * 1380512121796709469U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5341113995358179244U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8415417980279705731U;
            aOrbiterH = RotL64((aOrbiterH * 8521501372683793821U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2462819265072352463U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7657062767608441931U;
            aOrbiterA = RotL64((aOrbiterA * 15554638801273540163U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 46U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 12U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 12U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 60U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterH, 37U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11807U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 12513U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13650U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 12252U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12500U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13405U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12607U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 24U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aCross, 42U)) + 12046647397183218524U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 2760779375026461991U) + aPhaseBOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 11U)) + 13735454443176855650U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 4370377000586647724U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 14566322384189969094U;
            aOrbiterH = (aWandererF + RotL64(aCross, 19U)) + 5056565959818422786U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 24U)) + 8795403810686579209U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 47U)) + 9625947666256011567U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 37U)) + 1703669290934254701U) + aPhaseBOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6664070663184147951U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2104148316797553431U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12887842067180975983U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1197910004222596145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9922977170060903197U;
            aOrbiterH = RotL64((aOrbiterH * 13047828062605568603U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2048376210852567829U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12568990647075931409U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9860242601194210927U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15026894775772902751U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3439447160137900629U;
            aOrbiterI = RotL64((aOrbiterI * 1813754963043785165U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6532671388552829796U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17261098369835997661U;
            aOrbiterB = RotL64((aOrbiterB * 568292591215203521U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3171300991007459947U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 5935563269327662024U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11271790283157765003U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14290941734320455612U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12371794745736518824U;
            aOrbiterE = RotL64((aOrbiterE * 12208762336145168647U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8782840145467637373U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4067525421190366741U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6671002797916227485U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11854812920571789853U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17564890418553131451U;
            aOrbiterD = RotL64((aOrbiterD * 16657184504366731805U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 24U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 46U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 28U) + aOrbiterJ) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aPhaseBWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterB, 11U)) + aPhaseBWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterF, 42U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 16219U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15251U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15042U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15171U)) & W_KEY1], 34U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15552U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13809U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 14713U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 28U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 2571116506511057880U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 13U)) + 13112435411509707292U) + aPhaseBOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 37U)) + 10403251762787357256U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 52U)) + RotL64(aCarry, 47U)) + 8461951095541400405U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 5U)) + 9890793478557463815U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 43U)) + 3030229465991783707U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 7273848154043719247U) + aPhaseBOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 47U)) + 10681774862516028276U;
            aOrbiterB = (aWandererI + RotL64(aCross, 60U)) + 7105082755586853104U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6588579345319551129U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14616333550242386092U;
            aOrbiterF = RotL64((aOrbiterF * 2934574715879306337U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 15439666290229654921U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3360304356760164799U;
            aOrbiterI = RotL64((aOrbiterI * 5164191920584106237U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14438730801970761889U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14515616787452085729U;
            aOrbiterH = RotL64((aOrbiterH * 2041601927968559821U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4167853822635132419U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8950982233003320239U;
            aOrbiterA = RotL64((aOrbiterA * 887144270884244907U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12391327853728029953U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7100871010552394421U;
            aOrbiterG = RotL64((aOrbiterG * 16552349374101955967U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 15381697462381887944U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6801677551341079401U;
            aOrbiterE = RotL64((aOrbiterE * 13325954438427340703U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 947011315719204867U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6356920162398333481U;
            aOrbiterK = RotL64((aOrbiterK * 5566721941682667419U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8910262020598577378U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8778455415977526457U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4092470497616637283U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5585696961453127223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9670655481681494412U;
            aOrbiterJ = RotL64((aOrbiterJ * 7863197168965036383U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 18U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 60U) + RotL64(aOrbiterB, 18U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + aPhaseBWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 44U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 27U));
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16677U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 16703U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(mSource[((aIndex + 17043U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18336U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18089U)) & W_KEY1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16491U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16972U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 42U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 58U)) + 1457104756581596530U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 3U)) + 6127240317844622874U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 23U)) + 16492290056044189421U) + aPhaseCOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 39U)) + 10963676850938416468U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 27U)) + 4872917367399752405U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 47U)) + 15218882377875616148U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 5934166612122118251U) + aPhaseCOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 14215280930872003003U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 43U)) + 11428034799044600979U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5453003654321728726U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14273775120265649389U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5139018128323795309U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 328723770018440271U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13032190719588211088U;
            aOrbiterG = RotL64((aOrbiterG * 13363368478932798315U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2386881543033598494U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1649501123340887116U;
            aOrbiterF = RotL64((aOrbiterF * 11148976582360499033U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16462401546754210583U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1510579201823042227U;
            aOrbiterE = RotL64((aOrbiterE * 16287912400104043275U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6889066000014251983U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11324594596597724357U;
            aOrbiterK = RotL64((aOrbiterK * 15344987814648586023U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12237796033168436537U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17306069670330000343U;
            aOrbiterA = RotL64((aOrbiterA * 3167451351403385259U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14197284538008811658U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4754134852883071927U;
            aOrbiterI = RotL64((aOrbiterI * 3484427259538998699U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17201907781639753736U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8318419319239859855U;
            aOrbiterB = RotL64((aOrbiterB * 10320390501983802091U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16012488623961565780U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15583721012865354925U;
            aOrbiterJ = RotL64((aOrbiterJ * 10656414363201743961U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 52U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 51U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH + ((RotL64(aCross, 12U) + RotL64(aOrbiterB, 18U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 3U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            aWandererB = aWandererB + (((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterK, 30U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21439U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 21648U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20386U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneA[((aIndex + 19785U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21475U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19294U)) & W_KEY1], 22U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20219U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21541U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 36U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 23U)) + 2974056819475622600U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 43U)) + 7345051759236356098U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 4U)) + 12738468816846628882U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 7694520596043297922U;
            aOrbiterH = (aWandererK + RotL64(aCross, 37U)) + 5530753590015084774U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 57U)) + 3776309161718383105U) + aPhaseCOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 784780304358106404U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 51U)) + 8999942326995036509U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 18U)) + RotL64(aCarry, 3U)) + 5194986506064092779U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7920040007459652762U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11311997270710107937U;
            aOrbiterI = RotL64((aOrbiterI * 6227571709361790209U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5365231114813547251U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8630110234623825263U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2735881715888325759U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2358235238039571072U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18059414891616491807U;
            aOrbiterK = RotL64((aOrbiterK * 17150786106857185467U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14526050556461782864U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6937282036603272474U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14954512365270028029U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10105832250694931310U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3884223553012098137U;
            aOrbiterC = RotL64((aOrbiterC * 16340956813003906195U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10385284339549648087U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1257633893341505930U;
            aOrbiterJ = RotL64((aOrbiterJ * 2669950791270500977U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5528890519572824318U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15664241747527713256U;
            aOrbiterB = RotL64((aOrbiterB * 16670884497088220497U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14264122979415331887U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17985061405540198036U;
            aOrbiterF = RotL64((aOrbiterF * 2729487440173395133U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1663986734997903415U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3706166884286400587U;
            aOrbiterG = RotL64((aOrbiterG * 10549736618301955745U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 6U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 14U));
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 38U) + RotL64(aOrbiterC, 36U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23666U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 24145U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23471U)) & W_KEY1], 54U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24316U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24201U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22205U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22414U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 23935U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 22U)) + 12136097566601676613U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 7969431322248040056U;
            aOrbiterK = (aWandererB + RotL64(aCross, 43U)) + 10530676021510553889U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 51U)) + 8740777303075445264U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 13249434169895564739U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 15529577005925628472U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 39U)) + 344627093687331562U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 57U)) + 8824277416519988893U) + aPhaseCOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 18U)) + 5636276438449709875U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2079413361031851552U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7807998179168655561U;
            aOrbiterK = RotL64((aOrbiterK * 961456853699784753U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13589392896232029112U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10733011474804473996U;
            aOrbiterI = RotL64((aOrbiterI * 361749145931578805U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15934162328347805968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7573511217796245232U;
            aOrbiterJ = RotL64((aOrbiterJ * 10694563909931636155U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4828475187337891975U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13284974329890393113U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10831075817642374287U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13173869918669643112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15841507674783398167U;
            aOrbiterF = RotL64((aOrbiterF * 15632933198136963277U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14168272451055700516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11134471485501999898U;
            aOrbiterB = RotL64((aOrbiterB * 8019507184494591705U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2611858916687822610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17863271539727513641U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4987884722174985677U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8874401993454249066U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5131480593493950665U;
            aOrbiterD = RotL64((aOrbiterD * 8585874663602346121U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9366563022381918996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7890729519928340296U;
            aOrbiterC = RotL64((aOrbiterC * 11428572374057899517U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 44U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 28U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aPhaseCWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + aPhaseCWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 28U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24942U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 24658U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26759U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25225U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25680U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25993U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25758U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneD[((aIndex + 26897U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 13U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aPrevious, 60U)) + 12380376990224645149U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 18296928500297384014U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 29U)) + 3550626816361145100U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 13U)) + 2667792936946706027U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 53U)) + 12020969779370926953U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 19U)) + 737340727886903447U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 1681797651799760502U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 34U)) + RotL64(aCarry, 13U)) + 2956186342689489064U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 47U)) + 1876852870402977177U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6433205819353555071U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9065076854974222998U;
            aOrbiterF = RotL64((aOrbiterF * 5459675878087242021U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3254410578766789992U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2005081975473815576U;
            aOrbiterH = RotL64((aOrbiterH * 9947701153722014085U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15992999234834560419U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3458344156815120948U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1668460113964608051U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17069783053664877727U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1260234710193913099U;
            aOrbiterB = RotL64((aOrbiterB * 4561226779897414381U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3825186451876061335U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2905344294992827535U;
            aOrbiterG = RotL64((aOrbiterG * 2469896090698580795U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18141402347899180617U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8760129857609925066U;
            aOrbiterC = RotL64((aOrbiterC * 2507999156108123047U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 594052473780678210U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13216719212966128379U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10691355329696722303U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10029948739466316169U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11912428807431992996U;
            aOrbiterD = RotL64((aOrbiterD * 85016510811938307U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8735634019801417287U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12785916159063273545U;
            aOrbiterI = RotL64((aOrbiterI * 1161917531260663357U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 10U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + aPhaseDWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterI, 58U));
            aWandererI = aWandererI + ((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 43U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 53U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD + ((((RotL64(aCross, 4U) + RotL64(aOrbiterH, 26U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27508U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 29257U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27812U)) & W_KEY1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28929U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29729U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29931U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28110U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28147U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 22U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 11U)) + 3684295017013759987U) + aPhaseDOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 34U)) + RotL64(aCarry, 3U)) + 6740408842457292881U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 39U)) + 4563975890702399441U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 3U)) + 797804144825287940U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 47U)) + 2763779540450101303U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 13211846164102089685U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 15214578447281401982U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 43U)) + 13745208628754232427U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 58U)) + 17358621225969190747U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 779739369960480023U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4370963533701407813U;
            aOrbiterD = RotL64((aOrbiterD * 3123135216876641039U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6061333005507739975U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3589705340762734456U;
            aOrbiterB = RotL64((aOrbiterB * 16499293983611196967U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10607697666369230567U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9356757995305239271U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10945513661439954731U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10093033335903048138U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11037328061699834100U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11189760551792389605U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 558431161176115540U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17795680919453449358U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3910117359996283803U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6096779391116214109U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17594243286880690775U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12655610181937429915U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15414704802398002423U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18040588240488602196U;
            aOrbiterH = RotL64((aOrbiterH * 16344249573086571225U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14636298592697156931U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9677305688594936561U;
            aOrbiterJ = RotL64((aOrbiterJ * 8354776999961642997U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16408025751875050713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10018342878801454965U;
            aOrbiterG = RotL64((aOrbiterG * 10349132962708124117U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 44U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 28U) + aOrbiterA) + RotL64(aOrbiterJ, 21U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterJ, 50U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30461U)) & S_BLOCK1], 26U) ^ RotL64(aKeyRowReadA[((aIndex + 31269U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30220U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30294U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31310U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30150U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 52U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aIngress, 37U)) + 18191288703716505885U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 47U)) + 9824014524910417136U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 52U)) + RotL64(aCarry, 43U)) + 11953012029254917548U;
            aOrbiterG = (aWandererD + RotL64(aCross, 13U)) + 6297568011027199089U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 2576999400457367975U;
            aOrbiterE = (aWandererB + RotL64(aCross, 23U)) + 13176139160575558254U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 3U)) + 9978408174563621810U) + aPhaseDOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 23U)) + 16765834875061607142U;
            aOrbiterB = (aWandererH + RotL64(aCross, 19U)) + 16534507305459121344U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3114710944346151807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10240517868726718592U;
            aOrbiterJ = RotL64((aOrbiterJ * 4645691562915606463U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10721450637990777883U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16689590768796583952U;
            aOrbiterE = RotL64((aOrbiterE * 3046344179729901637U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2427422768928450209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13495584061816457831U;
            aOrbiterK = RotL64((aOrbiterK * 6670984773768885119U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7058636403765106682U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9897341853944713767U;
            aOrbiterA = RotL64((aOrbiterA * 14286816859999869231U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17749559755733386064U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12515645083926326659U;
            aOrbiterG = RotL64((aOrbiterG * 6582878478865838245U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2625692458813609962U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10596240255026143019U;
            aOrbiterB = RotL64((aOrbiterB * 11605800195771080135U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12374290338067865540U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1507386663796330249U;
            aOrbiterD = RotL64((aOrbiterD * 1210241080424446087U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9288099549484146726U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15159312464747000702U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 500055502081347757U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14998608679505446229U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17625038109437732009U;
            aOrbiterI = RotL64((aOrbiterI * 14785862243019841689U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 14U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 60U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterD, 20U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterC, 43U));
            aWandererD = aWandererD + (((RotL64(aCross, 10U) + aOrbiterI) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 26U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_BasketBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2497U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 7025U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7565U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 430U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 840U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3132U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 1393781663398437180U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 35U)) + 17414594746688585273U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 2823888497053071250U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 17032631958617884859U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 51U)) + 15222697630461125019U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 42U)) + 15737414920751551780U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 57U)) + 1357196111055783001U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5315122321649251691U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7893744655508595974U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17863000246694319149U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16721939414324611738U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3444375866323610848U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10874157227815775661U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1825716513674511632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15582066843912467318U;
            aOrbiterD = RotL64((aOrbiterD * 12765146555943757373U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15673590949193923915U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13887365046280406413U;
            aOrbiterA = RotL64((aOrbiterA * 3169061375011420121U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12730414371734709356U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4819112390640821927U;
            aOrbiterI = RotL64((aOrbiterI * 8782547948627685451U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3089925954422937464U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7180179304678622530U;
            aOrbiterJ = RotL64((aOrbiterJ * 16118051565147747413U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17030269962085008657U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6675917351883004046U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14134335325316949687U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 24U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 12U) + aOrbiterE) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8882U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 8570U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11926U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneC[((aIndex + 13604U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13195U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9135U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 14621U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererK + RotL64(aCross, 37U)) + 13880995121909552664U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 26U)) + 14534942818069300546U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 51U)) + 17745973100886007133U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 2249805580771946872U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 4460116116396439410U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 3378683994078106878U;
            aOrbiterA = (aWandererI + RotL64(aCross, 11U)) + 3992996501048809123U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12057768808864451929U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4115362079047921130U;
            aOrbiterB = RotL64((aOrbiterB * 12263015903331031345U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15297384955502206698U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17623548383481905636U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7487278217901483685U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3559213898000162417U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12311605719074507335U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3982199462062847697U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14807313864347885885U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11222085523291581822U;
            aOrbiterH = RotL64((aOrbiterH * 12580941911587215653U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 916681229436292462U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2441350114032314686U;
            aOrbiterJ = RotL64((aOrbiterJ * 7336079498999018067U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7361470539894653271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12153585147213579808U;
            aOrbiterA = RotL64((aOrbiterA * 3040327545467672961U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13566300726101613579U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14875254144748509128U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13699179902908972403U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 40U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterG, 13U));
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 5U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 48U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 16693U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 17678U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17894U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 21920U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16535U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21214U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20996U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 20U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererE + RotL64(aScatter, 3U)) + 4476099022490972343U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 16836423700375760429U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 8850577488928703557U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 43U)) + 7091631824560042743U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 12560498899956759494U;
            aOrbiterB = (aWandererF + RotL64(aCross, 35U)) + 7797973377112012161U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 58U)) + 6173820673874805794U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10805025132310245348U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7139216143268029968U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8349754682635765573U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8241544862261635722U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 4735527016563596150U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6621354217673598381U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5166171126690294033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11117641762075368393U;
            aOrbiterF = RotL64((aOrbiterF * 4980156869201219393U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6312932356458415421U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1304139291184508668U;
            aOrbiterD = RotL64((aOrbiterD * 90744653170922319U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10085025354842771067U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16745854428789531080U;
            aOrbiterH = RotL64((aOrbiterH * 1945983905747274355U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2497187958708890337U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16069701876646548995U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16606039730973709495U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17242004368025978091U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12334315722243232121U;
            aOrbiterB = RotL64((aOrbiterB * 16528598396696346719U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 4U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterG, 37U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 20U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29177U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 30093U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25531U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31107U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27978U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32670U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 26797U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 34U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 16462052553719977502U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 12337064059566619581U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 15801005007094515447U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 51U)) + 8228706742665081656U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 5U)) + 11006723027845190869U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 57U)) + 18173765337829177450U) + aPhaseEOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 38U)) + 530215083653542558U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6608611827035564511U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2246051826221626809U;
            aOrbiterJ = RotL64((aOrbiterJ * 6333352641495253539U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5228575308895381421U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10999213210689606857U;
            aOrbiterB = RotL64((aOrbiterB * 5467601259546342925U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3773371037240485696U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8887985779436152504U;
            aOrbiterF = RotL64((aOrbiterF * 698713082830739677U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11150566414723818350U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8336366151003049546U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9033771197242493699U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13233968794237090787U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8172558473508478819U;
            aOrbiterH = RotL64((aOrbiterH * 17837070423649268435U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 133564480283347997U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15104810248883567064U;
            aOrbiterE = RotL64((aOrbiterE * 706802420642303533U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9138629520201127075U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13993086066341664080U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4875046427147105077U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterE, 60U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_BasketBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3676U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 61U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 564U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6590U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4534U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3932U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 2915859148137000694U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 210680583721444425U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 24U)) + 6668118118775650387U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 37U)) + 15794200818099010989U;
            aOrbiterK = (aWandererG + RotL64(aCross, 43U)) + 6565076707062828369U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 47U)) + 16323164497808856719U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 7965435318816716560U) + aPhaseFOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 51U)) + 7390281030573369017U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 3U)) + 2269738866911824875U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 26U)) + 9664014216039993873U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 53U)) + 18284857398028357633U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 367667619795303009U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7935945060956274197U;
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16683666162337789540U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10655658270998102390U;
            aOrbiterK = RotL64((aOrbiterK * 15231596813382239841U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8307037916581540297U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3247742749860703524U;
            aOrbiterC = RotL64((aOrbiterC * 15052136713218656641U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10446792483683818139U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16374602929344972364U;
            aOrbiterA = RotL64((aOrbiterA * 12599903932725787599U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2411334498322777183U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1093701164116833765U;
            aOrbiterB = RotL64((aOrbiterB * 13129220206835381729U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17018480952982840635U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17348395690080029814U;
            aOrbiterG = RotL64((aOrbiterG * 6212591395713433257U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16111252311283623152U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12776492920397785951U;
            aOrbiterF = RotL64((aOrbiterF * 6136009241593081821U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12214538600808144816U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10043377462096783363U;
            aOrbiterI = RotL64((aOrbiterI * 14639467375095185877U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5101561512438055661U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3683207847147603335U;
            aOrbiterE = RotL64((aOrbiterE * 14355438383379198639U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14446947359104987749U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7596096688268335354U;
            aOrbiterH = RotL64((aOrbiterH * 13522935803383107145U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14015424109468938015U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2915859148137000694U;
            aOrbiterD = RotL64((aOrbiterD * 3653144205211106817U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterD, 14U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterE, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererH = aWandererH + ((RotL64(aCross, 54U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 37U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 23U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 52U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12333U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 12279U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12147U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12420U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11971U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15862U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14756U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aCross, 21U)) + 13278949403988203974U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 41U)) + 9213599924054673756U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aPrevious, 36U)) + 1255746482932381798U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 11575321997144516122U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 15881587525529432437U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 5U)) + 9846195809864862707U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 29U)) + 12319815691858217670U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 16322617427294439587U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 43U)) + 16332130810525887437U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aIngress, 39U)) + 4920951156015336794U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 18U)) + 16767126455124552329U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12553595911087945223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1437522202135436142U;
            aOrbiterK = RotL64((aOrbiterK * 2001992794165550905U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12313100454852227143U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2761983020631055729U;
            aOrbiterJ = RotL64((aOrbiterJ * 3874839760378039509U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17635303588421554367U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 788212489507463763U;
            aOrbiterD = RotL64((aOrbiterD * 17896475584538528059U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5192552894670654434U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6784748488807738811U;
            aOrbiterG = RotL64((aOrbiterG * 8077237651953896479U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16113417046719114943U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1096874945215225916U;
            aOrbiterB = RotL64((aOrbiterB * 17308604412622879833U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7610274704570171595U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10466070212284342550U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6449728258497920613U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6777845928873855221U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5251515022021984126U;
            aOrbiterA = RotL64((aOrbiterA * 9018277343404261611U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13849343158824111498U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7977711210181714021U;
            aOrbiterE = RotL64((aOrbiterE * 4182053966171053577U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6494539818728106982U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11314590450226080781U;
            aOrbiterF = RotL64((aOrbiterF * 12455979257225599157U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 552687702594328012U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 14961304171192292246U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 846375892915484717U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9771874402848476494U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13278949403988203974U;
            aOrbiterI = RotL64((aOrbiterI * 2119203863777871233U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 42U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterB, 37U));
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterE, 54U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 60U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterK, 5U));
            aWandererH = aWandererH + (((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 27U)) + aOrbiterC) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 20U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18884U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((aIndex + 20290U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21527U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 23815U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17687U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18580U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 22553U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 51U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 4980738603982643969U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 6U)) + 17660278413018470020U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 35U)) + 17598114429859543466U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 10993929335279994739U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 27U)) + 17967203122976322481U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 14U)) + 1872290205549034384U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 16607778671782810797U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 11U)) + 4895226930754394376U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 21U)) + 14960359005982301383U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 19U)) + 9921642352377700630U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 47U)) + 893281964367208693U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8232519988397858732U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4433022122758913407U;
            aOrbiterC = RotL64((aOrbiterC * 834240393225479419U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12689609831247168353U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 404535388957472176U;
            aOrbiterB = RotL64((aOrbiterB * 14534020545479806593U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3349108201964013155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4386449511297371730U;
            aOrbiterF = RotL64((aOrbiterF * 9596273264321140229U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14314587717949070586U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10923886625271054985U;
            aOrbiterK = RotL64((aOrbiterK * 7838969002623486809U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17634909585329833520U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2021301459918350372U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1388242915918642741U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5219599112498224367U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10641339455385046206U;
            aOrbiterI = RotL64((aOrbiterI * 1022283727595400719U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5003342156562330058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10951027475628404336U;
            aOrbiterG = RotL64((aOrbiterG * 17836928292555158461U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13040991872592235460U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11149099984302782267U;
            aOrbiterA = RotL64((aOrbiterA * 4248667283139686251U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2202253777854402763U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16679038924474862612U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2624443661523083597U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1959650241410955571U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8415989510614674816U;
            aOrbiterD = RotL64((aOrbiterD * 16340289102832732519U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2344501711730399821U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4980738603982643969U;
            aOrbiterE = RotL64((aOrbiterE * 6419275275477478723U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 56U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 44U) + aOrbiterG) + RotL64(aOrbiterK, 56U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 21U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 29U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterA, 36U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 40U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29561U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 24989U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 32758U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30757U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30503U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26245U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 27412U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 13U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 41U)) + 13854738573712660276U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 39U)) + 16835460633412286294U;
            aOrbiterA = (aWandererK + RotL64(aCross, 30U)) + 6785859293758091931U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 23U)) + 126317283127992659U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 53U)) + 7568963536291415413U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 12294016745653004819U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 57U)) + 18269588932920281147U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 3U)) + 5872406424994751026U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 7764434758831474129U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 14U)) + RotL64(aCarry, 29U)) + 4804168969415573371U;
            aOrbiterK = (aWandererF + RotL64(aCross, 47U)) + 959601763507651280U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9257644462479293048U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14332699366894494579U;
            aOrbiterA = RotL64((aOrbiterA * 8829304078930625541U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10487012596470786004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 612729229562321440U;
            aOrbiterI = RotL64((aOrbiterI * 11380387280507726003U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7845523921295625315U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12742115479740024747U;
            aOrbiterJ = RotL64((aOrbiterJ * 15578543510683986421U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10294667720904610944U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14369711143154904567U;
            aOrbiterF = RotL64((aOrbiterF * 13753005602288309379U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10918344717497681894U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18136794828308636957U;
            aOrbiterE = RotL64((aOrbiterE * 17899418637978002409U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14378638206724886404U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7077588188450008059U;
            aOrbiterC = RotL64((aOrbiterC * 485375960462924335U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8941870012851971932U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15242087859620352399U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4963002810455992839U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10395280254030875387U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6826595516076975980U;
            aOrbiterG = RotL64((aOrbiterG * 6198886240333178001U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10407910809564430664U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6368255889263255730U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3809496492809859731U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6365669830464231626U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 596785214258266904U;
            aOrbiterH = RotL64((aOrbiterH * 6338109335634389561U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4807438574488830717U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 13854738573712660276U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6954368463489446551U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 46U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aPrevious, 20U) + aOrbiterD) + RotL64(aOrbiterA, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 27U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 29U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 39U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterD, 18U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_BasketBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7273U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 1589U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3880U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 909U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5862U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 4760U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 51U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 1364174714924216027U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 4U)) + 13561796874229506613U) + aPhaseGOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 11845572344206238305U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 15762708240326773763U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 57U)) + 1157119665207900473U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6823546624372055260U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14465564210523945121U;
            aOrbiterH = RotL64((aOrbiterH * 10957323253786161255U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10667464548080807531U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13445737493224316575U;
            aOrbiterB = RotL64((aOrbiterB * 12137295000900795711U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3009837893785957665U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2886920524111083752U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15308180928967762543U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10886177449328249656U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15067759884678100433U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5724566815989860041U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18307930462682331536U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8791864377579255801U;
            aOrbiterC = RotL64((aOrbiterC * 9265158882471421767U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterH, 27U)) + aPhaseGWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererC = aWandererC + (((RotL64(aScatter, 6U) + RotL64(aOrbiterA, 18U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterI, 53U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13399U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 10371U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13973U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13217U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10389U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13751U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 60U)) + (RotL64(aCross, 43U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 15910560457440369082U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 5U)) + 17953072986407436888U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 13U)) + 15446940721193538669U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 52U)) + RotL64(aCarry, 23U)) + 3020785262774422009U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 7001288645424994404U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13385250665458462689U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4841895644623005949U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3898487345974386945U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13053476783239482065U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 641996979335975244U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3697673197256549833U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16211238020928688299U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12715448751323279480U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2116880429675303291U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17784406727699995290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16626339815786580778U;
            aOrbiterA = RotL64((aOrbiterA * 13940754474750138041U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9035070625716345139U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6085848172494001945U;
            aOrbiterH = RotL64((aOrbiterH * 10405728912339646693U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 14U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 19U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 38U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 57U)) + aOrbiterB) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22803U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 22889U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 19243U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21961U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18254U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 21105U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 23U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 47U)) + 6521330037475130256U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 12611880456055428940U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 12061611078130934708U) + aPhaseGOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 23U)) + 1558112410801116984U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 5U)) + 10509115227850160786U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4045915960688792066U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1196541286513243082U;
            aOrbiterG = RotL64((aOrbiterG * 5454309408259753479U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15564991032722373702U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4897765238703641798U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9693901276712946763U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12327429514907752733U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6189189797708711636U;
            aOrbiterI = RotL64((aOrbiterI * 9017615866338877651U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6374267075282018852U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1888758503831341439U;
            aOrbiterA = RotL64((aOrbiterA * 74387714918264257U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14956857689299491800U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14879361107223331957U;
            aOrbiterB = RotL64((aOrbiterB * 9166712966729591953U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterA, 48U));
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31884U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 27866U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28532U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24890U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32663U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 28658U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 2672739400294801233U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 3U)) + 8475624545015101850U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 1252755112289831257U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 7938039507649183387U;
            aOrbiterG = (aWandererG + RotL64(aCross, 28U)) + 8167413146948861022U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17712313989694374353U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7637042279892596975U;
            aOrbiterE = RotL64((aOrbiterE * 13056020836704050293U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15770412950033467341U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3951812021898608685U;
            aOrbiterI = RotL64((aOrbiterI * 6623127125223204737U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8656983621098246507U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17943342344730687317U;
            aOrbiterD = RotL64((aOrbiterD * 16495519451034883813U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3087677463651608668U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16493240011924342788U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16898479041530771871U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7750923317452683057U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2185924841611106546U;
            aOrbiterH = RotL64((aOrbiterH * 708072658250726381U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 38U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 54U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + aPhaseGWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterD, 14U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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

void TwistExpander_BasketBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1581U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 2112U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 622U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4740U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4529U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 5642U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 54U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 36U)) + 6916817163240024692U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 14554930751292077817U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 1098305064484336101U) + aPhaseHOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 12192821172420471527U;
            aOrbiterG = (aWandererF + RotL64(aCross, 57U)) + 2435134991707318845U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 1896745368738512624U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1114996424222923873U;
            aOrbiterH = RotL64((aOrbiterH * 6248754732325773087U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9839135798371512656U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8037967239603177043U;
            aOrbiterI = RotL64((aOrbiterI * 7848951103759663025U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15185468738487237432U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4912098316394854543U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3072785550384399929U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13142688607850380888U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4507379759608945839U;
            aOrbiterE = RotL64((aOrbiterE * 2989332387754215967U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7299006009652289342U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5390655277207053627U;
            aOrbiterG = RotL64((aOrbiterG * 10973744708856143715U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 5U)) + aOrbiterE) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterH, 54U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9423U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 14967U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 13395U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11602U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9310U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14741U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 42U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 77518479758428414U) + aPhaseHOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 4832061802166300011U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 35U)) + 11695291171006574112U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 14U)) + RotL64(aCarry, 47U)) + 7467412817843260094U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 5U)) + 17801484124471154757U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5555455638503958639U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5669470540733721606U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17219613748084498879U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3042388456327784163U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2236734925228156691U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10076582424701705531U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14459720401528685450U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4814967631216658856U;
            aOrbiterC = RotL64((aOrbiterC * 18288097536171386643U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16950679344449075945U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6262238639302011050U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9942659897425088183U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3522256359074996724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12524717897707074242U;
            aOrbiterF = RotL64((aOrbiterF * 6787771338063891989U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 30U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 53U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterF, 36U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + aPhaseHWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20984U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 19293U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24289U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21265U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23695U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 20722U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 14U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererD + RotL64(aIngress, 54U)) + RotL64(aCarry, 5U)) + 9888431329297626900U) + aPhaseHOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 2937735167534624403U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 21U)) + 17626022970343789617U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 43U)) + 5665660859333693743U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 1060537034632076669U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 743777763907175800U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5744905970181808845U;
            aOrbiterE = RotL64((aOrbiterE * 17426701505806885785U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3545351394494002180U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4877547088414106007U;
            aOrbiterC = RotL64((aOrbiterC * 5416792889338547109U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11669378338379598445U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2961072441706158212U;
            aOrbiterI = RotL64((aOrbiterI * 2677988507090705371U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13984945589234919765U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1433097875470903205U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 451996840039906781U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 716415411025451152U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8542286150858297810U;
            aOrbiterD = RotL64((aOrbiterD * 9139015340823332449U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 46U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterK, 37U)) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 54U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 10U)) + aOrbiterK) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25918U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 27629U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29364U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29715U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27789U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 31053U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 13854738573712660276U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 16835460633412286294U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 13U)) + 6785859293758091931U) + aPhaseHOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 126317283127992659U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 4U)) + 7568963536291415413U) + aPhaseHOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12294016745653004819U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 18269588932920281147U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9031152619272892317U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5872406424994751026U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7764434758831474129U;
            aOrbiterH = RotL64((aOrbiterH * 3772146788188420071U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4804168969415573371U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 959601763507651280U;
            aOrbiterE = RotL64((aOrbiterE * 4647396592804833217U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9257644462479293048U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 14332699366894494579U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8829304078930625541U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10487012596470786004U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 612729229562321440U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11380387280507726003U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 4U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 29U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 60U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterG, 39U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
