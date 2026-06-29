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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA4235345417BD445ULL + 0xCB7B72CE4012A83DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC9B738EADF311043ULL + 0xBA7A9AC2DCDCA61EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB34D5EE7BA468191ULL + 0x96A92039C1D35554ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA3C22898726DA0C3ULL + 0xC8BC776AD9BBC5A2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8A370821AFE23487ULL + 0x8B6E9FC393B8534EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBE70389A241D96B1ULL + 0xB860EC0E96764A1FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEF7579D9E13F86C7ULL + 0xB8CA90669B5C57EEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBCF15A5CA4C0C05BULL + 0xB32C2120ECC36829ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8946F1520373B143ULL + 0xB76646A863D6892BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA3C60D2DA78DC3CBULL + 0x9683255A5C253B25ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE8D2B3D7CACB1ED9ULL + 0xA424C4656A137FE2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDD6EEB31311CFA1DULL + 0xD21089D07B00FEC6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDE5555DA1837F66FULL + 0x9277D5E3A5164FCDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8D90896DB0C24BD3ULL + 0xEC2DE78FFBEFC21BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x87A981194F705EC7ULL + 0x95A1E65CB2084C30ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x878367B22201C25DULL + 0x8FEFDDE2095F4AB2ULL);
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
        // read from: mSource, pSnow, aWorkLaneA, aWorkLaneB, aFireLaneA, aFireLaneB, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD
    
        // kdf_a_loop_a loop 1
        // ingress from: mSource, pSnow
        // ingress directions: mSource forward forced, pSnow forward/backward random
        // cross from: pSnow, mSource
        // cross directions: pSnow backward forced, mSource backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(mSource[((aIndex + 2715U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((aIndex + 3038U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2996U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1876U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 54U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 14U)) + RotL64(aCarry, 19U)) + 4773124477323378268U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 57U)) + 16848723289435796005U) + aNonceWordI;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 13846642134917107058U) + aNonceWordD;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 6472057872482789939U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 21U)) + 2747019500690707226U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 29U)) + 9003965289739733880U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 5U)) + 3013390651936257377U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 42U)) + 3331004709895625067U) + aNonceWordE;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 37U)) + 15355010435553517129U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 27U)) + 7709870658004280052U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 47U)) + 13568728443963926564U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12409548853419307131U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 969183352023661537U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15370309834426476775U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3896803894396631184U;
            aOrbiterC = RotL64((aOrbiterC * 11018830202891911603U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10848873633291935766U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12885336509190543440U;
            aOrbiterE = RotL64((aOrbiterE * 1487357252619221365U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8252290890093788010U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9201553615601641350U;
            aOrbiterA = RotL64((aOrbiterA * 420321130559162915U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14014209645503188472U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4015071464301844550U;
            aOrbiterF = RotL64((aOrbiterF * 17444195018239904971U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16173085647514027347U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16916627014974363360U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 7699587344277490953U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1591680303404522110U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16499606051269327916U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 814405848002794813U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6932673635509444619U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8745681160108707944U;
            aOrbiterG = RotL64((aOrbiterG * 14565255558668084787U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10387263947888920455U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2553335462317280031U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7253573275397985211U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 17449861295444216249U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15716408844914738774U;
            aOrbiterD = RotL64((aOrbiterD * 10132631423215542589U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16974370193820578179U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4773124477323378268U;
            aOrbiterK = RotL64((aOrbiterK * 8982190762960590543U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 38U) + aOrbiterH) + RotL64(aOrbiterI, 18U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + aNonceWordG);
            aWandererC = aWandererC + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterH, 14U));
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterA, 27U)) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 37U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 3U));
            aWandererI = aWandererI + ((RotL64(aCross, 40U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterF, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // ingress from: aWorkLaneA, mSource
        // ingress directions: aWorkLaneA forward forced, mSource forward/backward random
        // cross from: aWorkLaneA, pSnow
        // cross directions: aWorkLaneA backward forced, pSnow backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 10252U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10688U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6609U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((aIndex + 9106U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 56U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 57U)) + 12809562813316740345U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 11U)) + 17084212535326321199U) + aNonceWordK;
            aOrbiterC = (aWandererA + RotL64(aIngress, 48U)) + 16074921689983846769U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 43U)) + 14027986153007120145U) + aNonceWordI;
            aOrbiterI = (aWandererC + RotL64(aIngress, 21U)) + 7633455951809250227U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 41U)) + 340989348513370174U) + aNonceWordD;
            aOrbiterA = ((aWandererE + RotL64(aCross, 39U)) + 5307820377645020116U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 18U)) + RotL64(aCarry, 47U)) + 5605285015771527274U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 53U)) + 5293500434746182790U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 7263156475892261811U) + aNonceWordF;
            aOrbiterE = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 10672879570907433005U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16659226780900986107U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9774892622769850665U;
            aOrbiterC = RotL64((aOrbiterC * 7487477727543183211U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10728057184108279042U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5032485856947407217U;
            aOrbiterH = RotL64((aOrbiterH * 16651577903809154285U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14642241075374862345U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8386481273395203518U;
            aOrbiterD = RotL64((aOrbiterD * 11649977733867003445U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2874153265304098104U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11519900149177261000U;
            aOrbiterG = RotL64((aOrbiterG * 2010158758971864505U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8885690878540115768U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 4482143389870987714U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 7105332459437434281U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17469068567801886615U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5121422018622394837U;
            aOrbiterI = RotL64((aOrbiterI * 14823827133212643467U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3130788210672745618U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6139244627510113216U;
            aOrbiterF = RotL64((aOrbiterF * 2640754184921507389U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10488511756324474710U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1760223670304953696U;
            aOrbiterK = RotL64((aOrbiterK * 4007062295003769311U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 2232708414171096783U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17497492434939621063U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 9850565931511937725U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8199114561613022892U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15432482434863050835U;
            aOrbiterJ = RotL64((aOrbiterJ * 14271143436318169871U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14991531324947777062U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12809562813316740345U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4487021480964944879U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 28U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterE, 14U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 27U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 34U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 39U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // ingress from: aWorkLaneB, mSource
        // ingress directions: aWorkLaneB forward forced, mSource forward/backward random
        // cross from: pSnow, aWorkLaneA
        // cross directions: pSnow backward forced, aWorkLaneA backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneB[((aIndex + 11309U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 12554U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 11084U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13161U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererI + RotL64(aPrevious, 42U)) + 17081642665820489793U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 37U)) + 14468854040067229623U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 2249450222593057429U;
            aOrbiterG = (aWandererE + RotL64(aCross, 53U)) + 14964389079511378664U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 39U)) + 17003491054252360650U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 5U)) + 12710882240582032588U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 9887078182156755359U) + aNonceWordB;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 57U)) + 7665284531810584704U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 57U)) + 7304284015511876717U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 51U)) + 5517927023543751734U) + aNonceWordP;
            aOrbiterI = ((aWandererC + RotL64(aCross, 29U)) + 17704756310857362759U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11347400363019508578U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11696395232760991243U;
            aOrbiterK = RotL64((aOrbiterK * 9725231749679442003U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10875780291242873583U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7808740614343437672U;
            aOrbiterJ = RotL64((aOrbiterJ * 8889516201913716283U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3145390996141902032U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16080636485642732615U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 7445756373012217305U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3929263288176983844U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 18210228766683996806U;
            aOrbiterC = RotL64((aOrbiterC * 13178080076505449091U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 13948962323541421431U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3037683309790156893U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13406672352222636739U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17827265198532699474U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7270895262023504864U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13467417362477308167U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6431243064980879185U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6680205390976259885U;
            aOrbiterB = RotL64((aOrbiterB * 10421386694108590789U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15910655919164357152U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8046213498216027383U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 18061867495824063553U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2521111689480478597U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13892876610454681741U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 17776392934374483875U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16009217514890880809U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1221573458193626679U;
            aOrbiterA = RotL64((aOrbiterA * 73477765605619369U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9275704218554025797U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17081642665820489793U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5613316790159527375U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 51U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterG, 34U));
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH + ((((RotL64(aCross, 37U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterE, 44U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 41U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererA, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // ingress from: aFireLaneA, aWorkLaneA
        // ingress directions: aFireLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: mSource, pSnow, aWorkLaneB
        // cross directions: mSource backward forced, pSnow backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 18547U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 19744U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 17854U)) & S_BLOCK1], 56U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17069U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20606U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 7722279280863371124U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 11584220561732385598U) + aNonceWordD;
            aOrbiterJ = (aWandererD + RotL64(aCross, 5U)) + 7834679350105534657U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 57U)) + 11347994382444180879U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 10U)) + 9449903188047063431U;
            aOrbiterI = (aWandererH + RotL64(aCross, 29U)) + 6516243976652795170U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 35U)) + 8420815253991184777U) + aNonceWordA;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 27U)) + 9081386852515170937U) + aNonceWordH;
            aOrbiterH = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 14375955191735286867U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 21U)) + 880757589768436072U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 18U)) + 3349856625725164229U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7826309957607577207U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8057435761214313635U;
            aOrbiterJ = RotL64((aOrbiterJ * 4718430712767038607U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9565237500443303103U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15893066735310588501U;
            aOrbiterF = RotL64((aOrbiterF * 8457633439171452397U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3276844534476430842U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6828644383891274120U;
            aOrbiterC = RotL64((aOrbiterC * 979580351653410157U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2815676923011504251U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5030251870850928417U;
            aOrbiterH = RotL64((aOrbiterH * 7075653570570819253U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13464083008377887034U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8994560761846897590U;
            aOrbiterI = RotL64((aOrbiterI * 9892839554658865143U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8398813387154468736U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8136429428340910892U;
            aOrbiterA = RotL64((aOrbiterA * 3348811490733577295U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 418587250696862341U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4111667833838312094U;
            aOrbiterK = RotL64((aOrbiterK * 860949442143849147U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6075478294190926371U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2208124955874142264U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15741988616251072075U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4726538724576443010U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6524078248882840425U;
            aOrbiterB = RotL64((aOrbiterB * 9784875566721689069U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14521003220464811621U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16916247868211621303U;
            aOrbiterD = RotL64((aOrbiterD * 1911638054294853877U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18207293125461843123U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7722279280863371124U;
            aOrbiterE = RotL64((aOrbiterE * 14303108475807941791U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 52U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 56U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 48U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterE, 51U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 37U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterJ, 54U)) + aOrbiterK) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // ingress from: aFireLaneB, mSource, pSnow, aWorkLaneA
        // ingress directions: aFireLaneB forward forced, mSource forward forced, pSnow forward forced, aWorkLaneA forward/backward random
        // cross from: aFireLaneA, aWorkLaneB
        // cross directions: aFireLaneA backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 22203U)) & S_BLOCK1], 34U) ^ RotL64(mSource[((aIndex + 24221U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25874U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 21930U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24467U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 21862U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 11U)) + 9751314027302668907U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 56U)) + 12175450995523107056U) + aNonceWordG;
            aOrbiterI = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 17519694958730119552U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 9093525527925682263U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 43U)) + 3713831321786810138U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 46U)) + 10108355209191835040U) + aNonceWordC;
            aOrbiterA = (aWandererH + RotL64(aIngress, 39U)) + 12956307447311314768U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 53U)) + 1904298513945877359U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aPrevious, 3U)) + 4658049993308574460U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 9826333658248851902U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 23U)) + 12058666914724365134U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2516574707110528099U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13335308331049750235U;
            aOrbiterI = RotL64((aOrbiterI * 5880227828760598587U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8230749255538495304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16536559486797811486U;
            aOrbiterE = RotL64((aOrbiterE * 7097036838156464969U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12387639130570188998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8459259798142872020U;
            aOrbiterA = RotL64((aOrbiterA * 8001346480955847013U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16083784052002800300U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1957284290736468379U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5046501301740813065U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7349538179311335863U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16395170077006105258U;
            aOrbiterF = RotL64((aOrbiterF * 4230485452156662763U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3317652065873784068U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5517155804799120700U;
            aOrbiterD = RotL64((aOrbiterD * 9789270651974719183U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5568525912112200094U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9334250662962319598U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 5034887614541768961U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5641394627075994165U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 13524971148931512745U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3699457147759854357U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15124425790244392471U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 7896294947517723306U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 7526632360108129915U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15241686066829586263U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12099799118961857495U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 10456171163074630861U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17529688916595727188U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 9751314027302668907U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 521888849578281715U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterF, 53U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 30U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterG, 44U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ) + aNonceWordP);
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 58U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // ingress from: aFireLaneC, pSnow, aFireLaneA
        // ingress directions: aFireLaneC forward forced, pSnow forward forced, aFireLaneA forward/backward random
        // cross from: aFireLaneB, mSource, aWorkLaneB
        // cross directions: aFireLaneB backward forced, mSource backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 32482U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 31139U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29053U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30037U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29992U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29581U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 57U)) + 964165145848253292U) + aNonceWordD;
            aOrbiterG = ((aWandererK + RotL64(aCross, 6U)) + RotL64(aCarry, 47U)) + 10645976767204934746U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 27U)) + 8241612229349212650U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 3U)) + 4159196033256913347U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 21U)) + 7194795864620233507U) + aNonceWordG;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 39U)) + 7638928444536778384U) + aNonceWordM;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 19U)) + 11819105916503968109U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 18052213302858186237U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aCross, 29U)) + 8663575313970041570U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 13U)) + 16644136720439299786U) + aNonceWordA;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 23U)) + 16930316530442679864U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16251107616988250593U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7171986193609401665U;
            aOrbiterK = RotL64((aOrbiterK * 3543709971414550087U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17885046834432626644U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7757069274715713557U;
            aOrbiterB = RotL64((aOrbiterB * 15766885299397923879U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 2212805322061155615U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6368539134638838822U;
            aOrbiterA = RotL64((aOrbiterA * 13383744883433594259U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 5264326094252925613U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6126345334815012938U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17180934809764905307U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13826731214018407061U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6621261811613643620U;
            aOrbiterE = RotL64((aOrbiterE * 2823596473596114171U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5964406317285863781U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2167324450276308078U;
            aOrbiterG = RotL64((aOrbiterG * 1098346374733634905U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16740710162977859724U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8236083581048717923U;
            aOrbiterD = RotL64((aOrbiterD * 4364887787000704039U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13967473987446124012U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5136051802217149813U;
            aOrbiterI = RotL64((aOrbiterI * 13997246005108872883U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5842999397215390366U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8621394946580065499U;
            aOrbiterC = RotL64((aOrbiterC * 11658023035736362355U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18086875424872976900U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7429246355923896047U;
            aOrbiterH = RotL64((aOrbiterH * 5077079237334961761U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18123753993386959014U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 964165145848253292U;
            aOrbiterF = RotL64((aOrbiterF * 3178072569980307307U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterF, 50U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 47U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterC, 21U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 52U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 24U) + aOrbiterB) + RotL64(aOrbiterG, 13U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterA, 54U)) + RotL64(aCarry, 13U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 19U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF2BC61572B9507B9ULL + 0x980A5E2E3AA57F5BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8750DC79C86BF847ULL + 0xE6AAF8804A1F6B49ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF449A85CAFAA31BDULL + 0xD9E1B81E28623718ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA0821C17DAC1AB03ULL + 0xDB90F964FE1D4899ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCEFADB0C54E98BADULL + 0x81D35B4068F9203EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAA5E26788033AEAFULL + 0xB0B4FC50EEB3A0A5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC9FC20A52D7CBC53ULL + 0xC1DC0E1ACE9BB832ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC21DCA925C6C95F1ULL + 0xB15D8887EDA87786ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD7381FA473921B59ULL + 0xF41610730F814B98ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x926E0835EC87064FULL + 0xD42951882901AF5BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF4BCE2B54781DC3BULL + 0xB3CD631843552A3EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCA4A090C64862159ULL + 0xE006AAB3AB1FA866ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xADD5359C47DB9A19ULL + 0xCD3A6BA396354D76ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE36270421460BCF9ULL + 0x8C92CF949EE9BF53ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAF730EF3E8A4E90BULL + 0xA5CD2379B66292B6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCB77EEFB7B6EBFCFULL + 0xD0CABC9B65325EB4ULL);
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
        // read from: aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_a_loop_b loop 1
        // ingress from: aFireLaneA, aFireLaneB
        // ingress directions: aFireLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aFireLaneC, aFireLaneD
        // cross directions: aFireLaneC backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 7542U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 7759U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 45U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2494U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCross, 28U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 43U)) + 7893287783892523139U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 39U)) + 10257331997383491153U) + aNonceWordD;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 19U)) + 14562226733652231753U) + aNonceWordE;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 56U)) + 14320342577110737851U) + aNonceWordB;
            aOrbiterB = (aWandererD + RotL64(aScatter, 51U)) + 9816717579822880756U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 9558926960095881953U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 9230371862654338324U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 47U)) + 6414274291252913420U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 10U)) + RotL64(aCarry, 35U)) + 13868546184398350849U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16940736952569949038U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2866957764814864371U;
            aOrbiterJ = RotL64((aOrbiterJ * 3554702178644797003U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7916721976073979724U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1602444214978842275U;
            aOrbiterB = RotL64((aOrbiterB * 11072503711308122385U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9529061385251008037U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8402775110887376588U;
            aOrbiterF = RotL64((aOrbiterF * 13980225144628227381U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15003592180290390713U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14195681406520825751U;
            aOrbiterI = RotL64((aOrbiterI * 11455000833788877217U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3263577002367714202U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12019422062655581928U;
            aOrbiterG = RotL64((aOrbiterG * 5002313835338447799U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8508638054582582917U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6536618106353552880U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6233964121117511885U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9654542989321430868U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7019594782797863244U;
            aOrbiterE = RotL64((aOrbiterE * 1234877854354279981U), 39U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 8256061220727519919U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9232754129467036130U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 17556001874302369781U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5608829951337740378U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12632120498473345701U;
            aOrbiterH = RotL64((aOrbiterH * 6994794653605831925U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 14U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 4U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 5U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 51U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 28U)) + aOrbiterD) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 2
        // ingress from: aOperationLaneA, aFireLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aFireLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aFireLaneA, aFireLaneD
        // cross directions: aFireLaneA backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15991U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 12841U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15131U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8757U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16193U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 42U)) + RotL64(aCarry, 19U)) + 4752759164691497960U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 12088872623537639782U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 51U)) + 3734943577379734227U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 19U)) + 8854778183012444234U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 38U)) + 16948373492893967275U) + aNonceWordH;
            aOrbiterI = ((aWandererK + RotL64(aCross, 47U)) + 7962415690046184385U) + aNonceWordO;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 1872682375669714454U) + aNonceWordN;
            aOrbiterE = (aWandererC + RotL64(aScatter, 57U)) + 7776801806943853566U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 27U)) + 16665439117257230732U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11088186766134265676U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 10850237991780969350U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7547414856143095121U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6464817712131305812U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 244557182884209844U;
            aOrbiterC = RotL64((aOrbiterC * 2394270354887582889U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 13261563971157415841U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2323811103717827362U;
            aOrbiterK = RotL64((aOrbiterK * 11483723582415081925U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12338803568475493422U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2811342930111104982U;
            aOrbiterA = RotL64((aOrbiterA * 5020981755203607757U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5554497011738996057U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12712169745460598698U;
            aOrbiterF = RotL64((aOrbiterF * 1985586486150377769U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17415058661427002973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9430421222715343818U;
            aOrbiterE = RotL64((aOrbiterE * 10321140659099470811U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3926618548181233180U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6172453297026957838U;
            aOrbiterI = RotL64((aOrbiterI * 1161551082037835233U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8633288765997226004U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17270881130844274342U;
            aOrbiterJ = RotL64((aOrbiterJ * 8888559940161770791U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 12232950994807835262U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15352600312956742750U;
            aOrbiterH = RotL64((aOrbiterH * 6140396356904933003U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 14U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterE, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 44U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 40U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 48U)) + aOrbiterG) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 3
        // ingress from: aOperationLaneB, aFireLaneD, aFireLaneA
        // ingress directions: aOperationLaneB forward forced, aFireLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aFireLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aFireLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20789U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 23263U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21639U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21247U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23649U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23268U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 12U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 39U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (aWandererF + RotL64(aScatter, 41U)) + 8866844335448071821U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 19U)) + 15159698739856430085U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 4U)) + RotL64(aCarry, 29U)) + 9582805772989594633U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 1438538239931588373U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 57U)) + 10862044156620436139U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 47U)) + 13682173320058164615U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 23U)) + 8351013291045977592U) + aNonceWordG;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 51U)) + 15777857431516633916U;
            aOrbiterA = ((((aWandererH + RotL64(aPrevious, 28U)) + RotL64(aCarry, 21U)) + 16178966745333885377U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9031889187993001617U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6308472367425865347U;
            aOrbiterH = RotL64((aOrbiterH * 17118710301967158153U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 642109145903321046U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9186268569255318035U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10714674348507516749U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6091345356803675860U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13218507921880873749U;
            aOrbiterD = RotL64((aOrbiterD * 15415157927185637717U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4266652275234474616U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4391422098164506195U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 17634679403195085867U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5160682323243635577U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10351728852161347404U;
            aOrbiterA = RotL64((aOrbiterA * 11105410036471745951U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3950932176454814023U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9536466386833427441U;
            aOrbiterG = RotL64((aOrbiterG * 18064984243491293435U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9927425919978776529U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6819384090527481081U;
            aOrbiterB = RotL64((aOrbiterB * 18032965969184368561U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1646274931424218507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16166524473976135097U;
            aOrbiterF = RotL64((aOrbiterF * 11672192658072663849U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11252501968059485262U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16847854447987609067U;
            aOrbiterC = RotL64((aOrbiterC * 6326299154627028295U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 60U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererG = aWandererG ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + aNonceWordI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 56U)) + aOrbiterG) + aNonceWordP) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 4
        // ingress from: aOperationLaneC, aFireLaneC, aOperationLaneA
        // ingress directions: aOperationLaneC forward forced, aFireLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aOperationLaneB, aFireLaneD, aFireLaneA
        // cross directions: aOperationLaneB backward forced, aFireLaneD backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25425U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((aIndex + 30432U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26113U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30870U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29098U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 26461U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 15316464782468770057U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 6642872057476351588U) + aNonceWordP;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 53U)) + 660732654689529192U) + aNonceWordH;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 37U)) + 7235418086884000655U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 30U)) + 14784518476694580493U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 47U)) + 12222433977933449375U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 8573001207708329927U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 19U)) + 16035256260815013172U;
            aOrbiterB = (aWandererF + RotL64(aCross, 24U)) + 15767726974121910203U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17712217935322939971U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13488963456923357159U;
            aOrbiterF = RotL64((aOrbiterF * 16785285630840310405U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 10222949131965611079U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1495561412321657209U;
            aOrbiterK = RotL64((aOrbiterK * 9706305581868526265U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16156530750584361434U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7773792489045606309U;
            aOrbiterI = RotL64((aOrbiterI * 10730624207715601393U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11544578291333360613U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3665587867634242865U;
            aOrbiterA = RotL64((aOrbiterA * 4840528190844842595U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15248434984650998090U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15487979645426567581U;
            aOrbiterJ = RotL64((aOrbiterJ * 10868107809356766183U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6972347795052712690U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16074994810010431338U;
            aOrbiterH = RotL64((aOrbiterH * 1262655238856775853U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 16851139687900415292U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14630026837021552812U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9577900853521254603U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14236330619137368169U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17778707026111136216U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 16239561893843454747U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9390961969105999083U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1174881758316573228U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 6602061268277529311U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 56U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 28U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterF, 6U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterK, 27U)) + aOrbiterG) + aNonceWordF);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 36U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF69BAB4572C55B61ULL + 0xA44E2B894A1990CCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x949A7E245E371F55ULL + 0x9CD1B622C826C13EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBC056E3FCA930D71ULL + 0xBEDB8886CFBF6230ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDEEE4D737565D8B9ULL + 0xF114850A3AF24B1EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD1533EDFF6B4C8CFULL + 0x8842892298A36B48ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBA6CFED2BE7E71C5ULL + 0x9CAF4066F99167BCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x87AF29BBD5722BD7ULL + 0xD642D25E77EF39A5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x881E029A984B0489ULL + 0xCF2A654EB775DBD1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x835CBE6AE0131CA1ULL + 0xFF6A86A19BD4610FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC47178273A0F1D1DULL + 0xE1054366C180B7FFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x83329C71A67A939FULL + 0xE7DC0C562B7187D4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD8CB15EAE75B4277ULL + 0xD97972C911BB2751ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAEEE40D7FF86DCA1ULL + 0xC824E74BE084E67DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9672145B9384FB4FULL + 0xC94474FB71553D9CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9966A7C175D584CDULL + 0x818DDE7C8A45EB86ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA4BD29A9B8AD6BA3ULL + 0x8249098A5C6B681DULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneA, aWorkLaneC, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6318U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 6736U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 6936U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8004U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 4134U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 34U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererF + RotL64(aScatter, 47U)) + 9080426856729228705U) + aNonceWordK;
            aOrbiterA = (((aWandererE + RotL64(aCross, 13U)) + 7851218321653539276U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 24U)) + RotL64(aCarry, 5U)) + 7023344692919298036U;
            aOrbiterD = ((((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 9772846154227440734U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 12008298632429608431U) + aNonceWordD;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12201090455849562875U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9498721803411445471U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 6511810500788451775U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 351203764023093632U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 4966360430644539250U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10138518378274592739U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9194167899071345693U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 4922477697284269116U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 8444814161720407881U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15742625291642356429U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7528703106518431730U;
            aOrbiterD = RotL64((aOrbiterD * 11530049278751507567U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15279053574704935317U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2425839793660355555U;
            aOrbiterB = RotL64((aOrbiterB * 11486964816849830667U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 14U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + aNonceWordA) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 39U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10102U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 9907U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 8949U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10872U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13369U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10005U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 5U)) + 13350544654542863236U) + aNonceWordC;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 23U)) + 12364346790125404372U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aScatter, 14U)) + RotL64(aCarry, 11U)) + 9738750172849512764U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 3781373837635491421U) + aNonceWordE;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 16635020317512702337U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5383653921676231276U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10181959815492056493U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14784636206508715141U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10005510924273927017U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9524687662265740565U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 13687380438646756931U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4259138552009771014U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8973051213213726023U;
            aOrbiterA = RotL64((aOrbiterA * 12625091476068190979U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17602611840127337490U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8218984546932905269U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 17504305273683304231U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 18102186122213487888U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2629927500298092976U;
            aOrbiterC = RotL64((aOrbiterC * 6983280164448292723U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 26U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterF, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23731U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((aIndex + 23787U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20704U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23025U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22795U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 22035U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 14U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((aWandererI + RotL64(aIngress, 11U)) + 12692813903177772178U) + aNonceWordD;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 7112496446691277899U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 57U)) + 2112247138290568813U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 48U)) + RotL64(aCarry, 21U)) + 3699421080882855947U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 13761832028354380922U) + aNonceWordE;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9243822514887600214U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6863833516853046129U;
            aOrbiterB = RotL64((aOrbiterB * 775478131159266165U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8863897995943098018U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13346785686701467520U;
            aOrbiterG = RotL64((aOrbiterG * 18074843497158380703U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 15309543066305531619U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17515530938817919111U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16625193986319048245U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 760493237816424254U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7282586354117620860U;
            aOrbiterK = RotL64((aOrbiterK * 2327153408185290635U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4129706068526969105U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 7020175432730888755U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 10095158356907592239U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterK, 19U)) + aNonceWordJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + aNonceWordC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 39U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 52U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24824U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 27573U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 25991U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27826U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28469U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25058U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 31466U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 3684295017013759987U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 6740408842457292881U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 4563975890702399441U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 37U)) + 797804144825287940U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 60U)) + 2763779540450101303U) + aNonceWordI;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13211846164102089685U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15214578447281401982U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12107189619131483661U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13745208628754232427U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17358621225969190747U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 5325024317338823061U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 779739369960480023U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4370963533701407813U;
            aOrbiterE = RotL64((aOrbiterE * 3123135216876641039U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6061333005507739975U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3589705340762734456U;
            aOrbiterH = RotL64((aOrbiterH * 16499293983611196967U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10607697666369230567U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9356757995305239271U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10945513661439954731U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + aNonceWordC);
            aWandererF = aWandererF + (((((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 29U)) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 47U)) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterG, 50U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE8B94CE3433AB83DULL + 0xE5A103BA4E7F3D22ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDC557D745C70AB19ULL + 0x8A61363E26CD3857ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA876FAC27BA3F931ULL + 0xC993EBD2DDF00D04ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE9C1D3F816C54C5BULL + 0xA6F70F8ACD87DDB8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF8AED2333BF230D1ULL + 0xA69C960402BC8443ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA56EE94BCAEB86B7ULL + 0xA4286FD3E1EDBF26ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDF20DB6CB2A45D3FULL + 0xAD466A93A861F005ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x919BF3E13BA8F6A3ULL + 0x83B6B707D7E514ADULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA9B5790F0C043F1DULL + 0xDBFD2A519D5DCD68ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEEBDFCF15B444473ULL + 0x9CF88758C283A3EDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA4AD0F914E1B6B99ULL + 0xCA28B52BCBD882B9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD08FC95FD9E8DCEBULL + 0xB971C672F625B230ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE5E372C176F29911ULL + 0xFF141745F1A66436ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x88603A6DDF6E3BFFULL + 0xE1DC6128C2715ED3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA5B7CB8BE53B3875ULL + 0xCF2C77FB9F45FBE0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF8679B39433C5EA3ULL + 0xE395433A57D1127FULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneB, aFireLaneA, aFireLaneD, aWorkLaneC, aOperationLaneB, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8044U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((aIndex + 3755U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8003U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3072U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4018U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7504U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 6U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererB + RotL64(aCross, 47U)) + 16424657151168221875U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 17150123681886380361U) + aNonceWordI;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 11U)) + 16041993588694572757U) + aNonceWordK;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 58U)) + 9871185846434828537U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 11227236398354430757U) + aNonceWordH;
            aOrbiterA = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 5399325217402192631U) + aNonceWordL;
            aOrbiterB = (aWandererI + RotL64(aScatter, 41U)) + 9248828789282890454U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9041370494203701062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14944424084524970764U;
            aOrbiterK = RotL64((aOrbiterK * 10283363059424655079U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5481938174456671041U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14783648629543752715U;
            aOrbiterI = RotL64((aOrbiterI * 7260164783191886395U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12355573914530445723U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9863991559011968318U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8495251211794343179U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16149688605937250965U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 106041828692026825U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 12199934305374582599U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 8076098639554567792U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11155119311895580013U;
            aOrbiterH = RotL64((aOrbiterH * 1495180896564818647U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6847612160595917702U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16094377920388017367U;
            aOrbiterA = RotL64((aOrbiterA * 4875801863643206333U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13584719866672696684U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13446209321646234607U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 9945349065094781529U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 37U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 60U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13605U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 12987U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 10277U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15288U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11483U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14951U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 22U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (aWandererE + RotL64(aCross, 3U)) + 3448371607470865612U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 35U)) + 3743742913651580573U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aWandererG + RotL64(aIngress, 51U)) + 13069491287948807280U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 58U)) + RotL64(aCarry, 41U)) + 16872779275586545632U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 17945792656755062795U) + aNonceWordG;
            aOrbiterB = (aWandererI + RotL64(aIngress, 41U)) + 18199747196793731853U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 15953311878379809513U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 941268763494588338U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10090221530365796809U;
            aOrbiterE = RotL64((aOrbiterE * 14035236086292997613U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8335698093307607001U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6147498804734306100U;
            aOrbiterC = RotL64((aOrbiterC * 6904444049941211327U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5980246079567570090U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4152167624425912978U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10019421651535123573U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14990418790239735916U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3418668387496597219U;
            aOrbiterF = RotL64((aOrbiterF * 12814077238529863119U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4206650904177199425U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3905470780938996069U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16030122739273137005U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9968672788233080924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 602258075661864866U;
            aOrbiterH = RotL64((aOrbiterH * 2615726693066300065U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17751667243048041383U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2414054413585296027U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 1049512574773201893U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterB, 53U)) + aNonceWordM);
            aWandererG = aWandererG + ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 12U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterE, 28U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17614U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 18056U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23000U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22826U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24074U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 16744U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 13U)) + 13053031069776604052U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 29U)) + 1331396630251085122U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 35U)) + 15879286043343942393U) + aNonceWordI;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 13590365633321406830U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 14569235423040242618U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 20U)) + 11397370636618371560U) + aNonceWordA;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 3455933494593971847U) + aNonceWordH;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1307153376443784593U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10688618762584786871U;
            aOrbiterG = RotL64((aOrbiterG * 9503823896874842411U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17746248451153600096U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8512568600755410158U;
            aOrbiterD = RotL64((aOrbiterD * 16648320170768234063U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8950230550112591092U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17790968369472845496U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 5104988920132008913U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12583323865381967534U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11243927099685293887U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12867003042486433971U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9690268715525781389U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7466066217365074653U;
            aOrbiterB = RotL64((aOrbiterB * 17565696765505320889U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3673528673209875118U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14079103852360952255U;
            aOrbiterJ = RotL64((aOrbiterJ * 17449228863409999629U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 6747836856132250630U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5027692924422297153U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 2492421273167124437U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterG, 44U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31091U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 25533U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26082U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28014U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32407U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 28734U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 47U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 15910560457440369082U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 17953072986407436888U) + aNonceWordK;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 29U)) + 15446940721193538669U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 41U)) + 3020785262774422009U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 12U)) + 7001288645424994404U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 13385250665458462689U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 47U)) + 4841895644623005949U) + aNonceWordP;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13053476783239482065U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 641996979335975244U;
            aOrbiterJ = RotL64((aOrbiterJ * 3697673197256549833U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16211238020928688299U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12715448751323279480U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2116880429675303291U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17784406727699995290U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 16626339815786580778U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 13940754474750138041U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9035070625716345139U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6085848172494001945U;
            aOrbiterE = RotL64((aOrbiterE * 10405728912339646693U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1177103851507561053U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2281901691017816407U;
            aOrbiterH = RotL64((aOrbiterH * 3142197009403602497U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9040984343694325070U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13334258224023902365U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4782523727707164869U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1079824790138592518U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14024082692012948652U;
            aOrbiterA = RotL64((aOrbiterA * 3219489374333737903U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterA, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 52U) + aOrbiterE) + RotL64(aOrbiterA, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 53U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 14U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAE31068B56F2A873ULL + 0xCC6757D2BFAACF16ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBEFE509CF79B5BF5ULL + 0xD66E95AEFF9CC3EAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDE14C347A43ED0E7ULL + 0x97D2E91F7E1591D1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE5BF7356FC278E31ULL + 0xAA0813AF72EDCD72ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEF85F3366FC1359FULL + 0xC53BD3D16CE07BF7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x919EE98B590C267BULL + 0xCD583D9091F6502DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE16E3D106A3730E7ULL + 0xFD5B166849020AE1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE9F1147E4CDE7E7DULL + 0xDFA94EADF3B70959ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x948BD05436ACC019ULL + 0xAB405288ADBBD4E1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE6E465FA36AA2981ULL + 0xF38C1DA31AE37466ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xADBDCA1DAB7532B7ULL + 0xB603D49792CC2B5CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBD82587C4F76C137ULL + 0xE416584501CA147DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAD785EF82EA0ACBDULL + 0xF2119B6E476071A2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEDA74B1E35DE451FULL + 0xB0A2A7948FE8427CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCE9681647D6C493BULL + 0xD86549AB8815DBB3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC347A1DB4E0C3707ULL + 0xF95F086BEA726D94ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneD, aExpandLaneA, aFireLaneB, aFireLaneC, aExpandLaneB, aOperationLaneA, aOperationLaneC, aExpandLaneC, aOperationLaneB, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4629U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 4352U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1909U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7260U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 406U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6442U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 3U)) + 5568146815535263910U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 39U)) + 7736084960873834666U) + aNonceWordG;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 1336413621817562093U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 3U)) + 5218462026934984692U) + aNonceWordO;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 7048890985969555935U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 47U)) + 13415955213864702118U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 13U)) + 5657023257021528548U) + aNonceWordC;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14338310943137497116U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12305161641833950473U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 11949964304435964395U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14514226578370459131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12692904083266024340U;
            aOrbiterI = RotL64((aOrbiterI * 14800805065279908839U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11012959130001327964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7106471380403489078U;
            aOrbiterB = RotL64((aOrbiterB * 515626559384817223U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3718101961355280891U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 13364192077222322664U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 1411328915372590283U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6720867800318913440U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14497243926965866546U;
            aOrbiterE = RotL64((aOrbiterE * 13595058589060114653U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5789056168233262435U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14438482587495779937U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 10593535547917767263U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 313917798940179945U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15241845511889502917U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16483477103771326107U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 28U)) + aOrbiterI);
            aWandererF = aWandererF + (((((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 53U)) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 52U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10081U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 10318U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11000U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14148U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16158U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 12925U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 24U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 13499155707765393469U) + aNonceWordK;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 53U)) + 3740324981823726185U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 5470765363949735652U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 5U)) + 3446436171274452326U) + aNonceWordO;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 43U)) + 1778929412631211933U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 11U)) + 14666308799855220954U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 27U)) + 4548410236791175055U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5829739767694190372U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14319231414903675748U;
            aOrbiterG = RotL64((aOrbiterG * 4966501102515775601U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1513851750246111405U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1685620217748986019U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 9286548037413609445U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16284162182006054402U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6271539598462003309U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13923286694131331137U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12669312437565969473U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11894755313393001665U;
            aOrbiterJ = RotL64((aOrbiterJ * 12556759675372354075U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6315983824634946566U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17106616474222892782U;
            aOrbiterC = RotL64((aOrbiterC * 167205520766791073U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13350266700180455548U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4608846311203767162U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2504857468837437365U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14195866746143604365U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 7917977448256795054U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 5927771378657284557U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 57U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 13U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 28U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18358U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 18142U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21821U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23724U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22215U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21081U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 36U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 11U)) + 785861751704720606U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 15968088718435606299U) + aNonceWordB;
            aOrbiterE = (aWandererE + RotL64(aScatter, 19U)) + 1393976526590347151U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 17240750947292745884U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 35U)) + 4921576136163183137U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 3334047873553153032U) + aNonceWordO;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 28U)) + 15086509978458408698U) + aNonceWordC;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 892391205397581998U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2965686403183767521U;
            aOrbiterE = RotL64((aOrbiterE * 709160942482770225U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14632215393655706170U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15740589515342377322U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15677716942904794913U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11131164813943086445U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6988080581278900960U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 6412189142344044255U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16021254613117657178U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6183615599897921154U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 9976411093264211033U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 12533992547026652747U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3104325358982904219U;
            aOrbiterJ = RotL64((aOrbiterJ * 14977348108778147265U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3878525937957474644U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2120435259884368445U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 15964718652193073177U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14928658302694194856U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9121310461310309348U;
            aOrbiterK = RotL64((aOrbiterK * 17304439784647477491U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 20U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterB, 12U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 50U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32482U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 26566U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 29137U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25659U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28023U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28635U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 2786079456995203065U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 12U)) + 7237256119153857253U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aWandererD + RotL64(aIngress, 3U)) + 9310834010563647604U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 17361734905706517877U) + aNonceWordH;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 35U)) + 15837111231884647451U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 18065431964418026445U) + aNonceWordA;
            aOrbiterE = (aWandererF + RotL64(aCross, 47U)) + 3029123922999952652U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5166926595573507837U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 1918425684273807598U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 16616641579714896719U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4724551751012661440U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1818014487579644390U;
            aOrbiterA = RotL64((aOrbiterA * 14904092108647864911U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6670090372241084216U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8485757110007268693U;
            aOrbiterD = RotL64((aOrbiterD * 11876760095108618363U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4928130251509514742U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2528788422725346792U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 1855982047967756661U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 2860387120895147503U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12927802338151379368U;
            aOrbiterH = RotL64((aOrbiterH * 8876144125458603029U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 18029699867733207083U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13361836994951253312U;
            aOrbiterG = RotL64((aOrbiterG * 5349767426256597073U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11957294454794128079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3755417922063414648U;
            aOrbiterB = RotL64((aOrbiterB * 13896364063651241401U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 20U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 46U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aNonceWordN);
            aWandererB = aWandererB + (((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 41U)) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 14U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBA7BC761300E6457ULL + 0xABB8AC6F88C698F3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEA0BB659EE6AFAC5ULL + 0x88DAB99A4C08AE18ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x970844DA78545493ULL + 0xCD450BEB5105171FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEEE3D44A8B611601ULL + 0xA1A6B03858DD0441ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC1A1229ED8B4B17DULL + 0xABB2E4EBE95439C4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF3250C55D277AE7FULL + 0xFBCE3A39FFDE31F3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE5A73CCE82BA724BULL + 0xC199FBF24DD38E30ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE217FB3D81479D05ULL + 0xB5EF4E623445B0D0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD6A8424A9D4F8C33ULL + 0xC849D09210C156BCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDC786BEC7CBB276DULL + 0x9C57CE99EA918634ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDA8DCC2DA756F98FULL + 0x87B78F69ABB15121ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8B5A56305A4D0DDFULL + 0xFEFE54B9C7B0606FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF6FBA2C60E17B0B9ULL + 0xFA0889B3DA0F0ED3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC161D18FA4D23EF3ULL + 0xFAFD198C19138307ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDBB3F086207EB735ULL + 0xEBB51F8F12EC0355ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAFF379EAE08A32FFULL + 0x8A0FDD9C17BE04F0ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD, aWorkLaneA, aOperationLaneA, aFireLaneD, aWorkLaneB, aOperationLaneB, aWorkLaneD, aFireLaneB, aOperationLaneC, aFireLaneA, aFireLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2640U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 1008U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4527U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7990U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6866U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 2410U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 23U)) + 7948891781097675369U) + aNonceWordF;
            aOrbiterG = (aWandererH + RotL64(aCross, 42U)) + 13928362874228230226U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 5U)) + 10776180542602258926U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 27U)) + 5735115172149470447U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 5353591822981766987U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 562301708107268570U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 10467810247578364868U) + aNonceWordE;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 21U)) + 14541630141152308564U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 11U)) + 2350076897065139429U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 37U)) + 17519109078651162228U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 18U)) + 6061035173339902910U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15654836633731000065U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13723521735153718904U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2849680038315532197U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17336102435576647923U;
            aOrbiterI = RotL64((aOrbiterI * 10984689101753586739U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7671010488872356142U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11485114338165600777U;
            aOrbiterC = RotL64((aOrbiterC * 4162584865462407791U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8759060657343458985U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11009137869375286581U;
            aOrbiterF = RotL64((aOrbiterF * 8741417343929809115U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15792999392743144135U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6180808423175992479U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13681230339693676907U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 361487389591183005U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15292753806514404853U;
            aOrbiterK = RotL64((aOrbiterK * 17478232597253311153U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14929153438443362045U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7904556383593914086U;
            aOrbiterD = RotL64((aOrbiterD * 2484130486635511403U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3793180909904286848U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10391957637467171320U;
            aOrbiterB = RotL64((aOrbiterB * 505484041943467117U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11648765065563798353U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17601185776537566611U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4753179291885740011U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2907499704986356444U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17048858067202291241U;
            aOrbiterA = RotL64((aOrbiterA * 2607549567999666889U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4340465159886930775U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7948891781097675369U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12913104720552907335U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 22U) + RotL64(aOrbiterE, 5U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 24U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + RotL64(aOrbiterA, 41U)) + aOrbiterH) + aNonceWordP) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterG, 46U)) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 12U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11761U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 15952U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14497U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9551U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15382U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15598U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 11U)) + (RotL64(aCross, 24U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererA + RotL64(aScatter, 5U)) + 826930775230515406U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 5137814617363250861U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 47U)) + 14761561947426681616U) + aNonceWordN;
            aOrbiterB = (aWandererG + RotL64(aCross, 10U)) + 12773023438753662590U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 7331345852207096322U) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 19U)) + 3899381212671247460U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 57U)) + 10072004147620068599U;
            aOrbiterI = (aWandererD + RotL64(aCross, 13U)) + 3424585039401897560U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 23U)) + 8246760141625966321U;
            aOrbiterG = (aWandererK + RotL64(aCross, 26U)) + 3655992860610853290U;
            aOrbiterA = ((((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 11154618022505863898U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15629361991059709973U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 10842068502278489664U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17223002513104960799U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5571312349016336686U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 589313823745748879U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 1356685926549786027U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13633457935771935260U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12684602052812183096U;
            aOrbiterI = RotL64((aOrbiterI * 4689206269919806711U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5711307583717354204U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7181854170553728211U;
            aOrbiterF = RotL64((aOrbiterF * 9835601115561325911U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1884620014396115821U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1471516373272364262U;
            aOrbiterE = RotL64((aOrbiterE * 5126319375714848029U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 742739371092077733U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8075893317715227838U;
            aOrbiterJ = RotL64((aOrbiterJ * 11208274111743259795U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8179547722249281263U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 15305282712174742323U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 7951986906055462929U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1430543231751281079U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14585341768267283387U;
            aOrbiterG = RotL64((aOrbiterG * 313213844964269133U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8123889986027932297U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2081696191347150910U;
            aOrbiterC = RotL64((aOrbiterC * 4869653441012615053U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10166788886199265936U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15927074835525735601U;
            aOrbiterB = RotL64((aOrbiterB * 6747650218540675523U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6997764816848988590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 826930775230515406U;
            aOrbiterA = RotL64((aOrbiterA * 9943232461538279601U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 38U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 54U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterE, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 36U)) + aOrbiterG) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18439U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 20537U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23685U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23104U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21544U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 17331U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 50U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 3255291173184001106U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererF + RotL64(aScatter, 27U)) + 15308468160116255528U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 19U)) + 18186972408589866656U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 3U)) + 4439324265978331914U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 41U)) + 13099263173016322486U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 58U)) + 7041561081767500660U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 39U)) + 6196422612687812971U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 7664260932541281413U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 47U)) + 17802347823020441056U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 54U)) + 4253107484061190446U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 13799496534030645312U) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14252892847595951926U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5663527578664291422U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 18314294235895182465U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11148755959699137661U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17036900929333594592U;
            aOrbiterE = RotL64((aOrbiterE * 16041243617369003291U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2403828181385259549U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17813580350434928194U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 13666780980793857831U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5623611126885414523U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7293224381174846969U;
            aOrbiterB = RotL64((aOrbiterB * 7032561584670788117U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10602620906929686163U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 18015916257203385982U;
            aOrbiterI = RotL64((aOrbiterI * 10684090189688871993U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13592915735376305773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13995866908043417505U;
            aOrbiterD = RotL64((aOrbiterD * 3802175869395887331U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8200465989447697618U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9866671660800629464U;
            aOrbiterF = RotL64((aOrbiterF * 2138851839905326265U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11557528777230608777U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 131060617338185060U;
            aOrbiterC = RotL64((aOrbiterC * 11068705423012265209U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13404720733342982167U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13128574378042136042U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 5805270317312187011U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15879295432652112238U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9433361543323748909U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 3592390041363796221U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6262775775981534941U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3255291173184001106U;
            aOrbiterG = RotL64((aOrbiterG * 2748492753337241005U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterC, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterI, 39U)) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 48U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 14U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 20U)) + aOrbiterG) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneC
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25726U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 24824U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 29735U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29664U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25884U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 32386U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (aWandererG + RotL64(aPrevious, 47U)) + 5906639480605353429U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 5293518570213287605U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 41U)) + 15383185501428521377U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aIngress, 53U)) + 15364072512743978902U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 34U)) + 4525473357144014271U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 43U)) + 10400911938125603074U) + aNonceWordP;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 57U)) + 16417506293824627550U) + aNonceWordO;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 27U)) + 2419329331753341815U) + aNonceWordM;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 10U)) + RotL64(aCarry, 13U)) + 14929222427923332069U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 16771573504983922586U) + aNonceWordA;
            aOrbiterG = (aWandererF + RotL64(aScatter, 39U)) + 1863466450051787622U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12895350137096692415U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3700979086526298327U;
            aOrbiterE = RotL64((aOrbiterE * 10279730254867618193U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1977099106211282426U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6144698304096915742U;
            aOrbiterJ = RotL64((aOrbiterJ * 5039822990560519609U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3858895556659724975U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1283646340363435327U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 11622421841377018069U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6240532051889108891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 757364889381634634U;
            aOrbiterC = RotL64((aOrbiterC * 943852137901972945U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5272945693977418174U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6850528198786172283U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 1966383079897679953U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14431587733859573714U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16124590257870999553U) ^ aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7755796211433191143U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14912695018110241411U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11098623474413346520U;
            aOrbiterB = RotL64((aOrbiterB * 15167688959990872051U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3484847683376368686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2295388097292719800U;
            aOrbiterF = RotL64((aOrbiterF * 1240808318176106909U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 923199510066894111U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 311875852510926196U;
            aOrbiterI = RotL64((aOrbiterI * 9797881750305289335U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3543141837224843684U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12889943043568922084U;
            aOrbiterK = RotL64((aOrbiterK * 8682278766727990427U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 6105656539077757510U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5906639480605353429U;
            aOrbiterG = RotL64((aOrbiterG * 9555916235293954383U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 44U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 51U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 39U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterD, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 37U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterH, 43U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterK, 34U)) + aOrbiterD) + aNonceWordH);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 27U)) + aNonceWordI) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8493C46D626A4275ULL + 0xC689E029134965DBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC8AB494AB8AC40DFULL + 0xAF3F26ECA62CC0E1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF5BABFE35E72EAAFULL + 0xA5999FBCEC5115A0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFF1BC6F0FE83A5D7ULL + 0xB63D4DE777968114ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDB752EA10B1DC6DBULL + 0x8445119481C848A3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB5E97A463E727BC3ULL + 0xA204057ACED4B117ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE8BD4374B21DB76DULL + 0xF4311ECFCC4A1C2BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x864654BEA7BF0621ULL + 0xCDBC26C82363ABB4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFD6F21940BC55117ULL + 0x929783A29D11845FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x809408AAF191597FULL + 0xBCE90B73E49425DBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA9AD283C3AB6EC43ULL + 0xF2C92CB837FCAD03ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE9B17CB15E1D9E65ULL + 0xFE17F11FB6FD1A51ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xABA297EF3D5961DFULL + 0xF4030C49D4D6891BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC3CB46D61D3B5D41ULL + 0xECC963F5B5179EF0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA64C92C4AB9BBF6DULL + 0xE3F55C8E33C90126ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB07C64743CB25DB1ULL + 0xBBEFB61030DDF4ACULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD, aExpandLaneA, aFireLaneC, aWorkLaneB, aExpandLaneB, aFireLaneA, aWorkLaneA, aExpandLaneC, aFireLaneD, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3366U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 729U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 3940U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4676U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1776U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7903U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 17074147006464019918U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 38U)) + RotL64(aCarry, 41U)) + 10559516626129419928U) + aNonceWordD;
            aOrbiterG = (aWandererE + RotL64(aIngress, 43U)) + 13280363679503946221U;
            aOrbiterB = (aWandererK + RotL64(aCross, 11U)) + 17657115422132457413U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 23U)) + 13325837013304973008U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 19U)) + 3059707750486106037U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aWandererG + RotL64(aCross, 3U)) + 4529045702503050852U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 47U)) + 10726578475550904292U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 21U)) + 14832537837996659885U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 220094417441809246U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15343130035105342194U;
            aOrbiterG = RotL64((aOrbiterG * 7984652435043810845U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16592263353426409884U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15649290906447931918U;
            aOrbiterJ = RotL64((aOrbiterJ * 8405875177836650731U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11437410545843708269U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5859769136073011444U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 1065016088086441107U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15188064100307340341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4367466521843260049U;
            aOrbiterD = RotL64((aOrbiterD * 15916715854192820923U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8482617283860566845U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2585745804937342972U;
            aOrbiterE = RotL64((aOrbiterE * 8267269625632139809U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1687641344403425541U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13667916445979421400U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8191322670355590027U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7684258716388029228U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14764266202380443369U;
            aOrbiterI = RotL64((aOrbiterI * 1746254773647650741U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12685190466981675661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9958374400222383893U;
            aOrbiterK = RotL64((aOrbiterK * 12696606920219838929U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 1352584794098160330U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16057453941015251708U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6051546505117202495U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 36U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 38U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 6U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 34U)) + aOrbiterE) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15763U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 12012U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11086U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11645U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10766U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 15640U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 4622023259121087483U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 23U)) + 10253505250223501352U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 34U)) + 17133877904420462669U) + aNonceWordI;
            aOrbiterA = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 6162827793741796700U) + aNonceWordE;
            aOrbiterK = (aWandererI + RotL64(aScatter, 3U)) + 9610986424765907615U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 11210747154264753754U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 12U)) + 16554205219580654546U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aCross, 57U)) + 10352576357413766388U) + aNonceWordF;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 51U)) + 3651845783283479752U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18145542190463500476U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5415609566767162857U;
            aOrbiterI = RotL64((aOrbiterI * 6474184559323816389U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2033734872464201570U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3507213117125813345U;
            aOrbiterK = RotL64((aOrbiterK * 5453058336688881113U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8716253393049851856U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 695984869565941856U;
            aOrbiterC = RotL64((aOrbiterC * 8377921610764044735U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7661578828878284931U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 906654265099155956U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 8117625377607536949U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6050049984731254612U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17882717590338190821U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 10807367411402733215U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 4996521991532815957U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4246460672800604436U;
            aOrbiterJ = RotL64((aOrbiterJ * 12047466401960824903U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8700148116452518842U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 10039050281847466206U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 11884791271239660157U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4513844680425845372U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3037563127442815153U;
            aOrbiterA = RotL64((aOrbiterA * 18363509277992292407U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1005237931570968724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1373258132025712065U;
            aOrbiterH = RotL64((aOrbiterH * 10458020799382532395U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 42U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterA, 6U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterH, 27U)) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 46U) + aOrbiterF) + RotL64(aOrbiterA, 34U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18125U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 20268U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21428U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23247U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23738U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17510U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 20U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 47U)) + 3970829908171131502U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 57U)) + 7040283759419531991U) + aNonceWordD;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 11856292169397052901U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 6U)) + 819598588791819022U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 11U)) + 2176451710970866848U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 6454704928613390494U) + aNonceWordJ;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 11792122387218053841U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 19U)) + 9254780213489752211U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 26U)) + 16591812589999846482U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1471246223935074832U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1424843083106386453U;
            aOrbiterH = RotL64((aOrbiterH * 15020536982657410783U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 1856469958050891629U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6331743690452052712U;
            aOrbiterG = RotL64((aOrbiterG * 15327924647897459645U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10351075711345476487U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9518585245330480185U;
            aOrbiterA = RotL64((aOrbiterA * 3792179827396760391U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17787514620244712033U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 14182328067398162557U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18107337388659070197U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12798088948801072444U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9563215159275202323U;
            aOrbiterI = RotL64((aOrbiterI * 7058145016617349141U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9904919772580498232U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16579777394992143043U;
            aOrbiterB = RotL64((aOrbiterB * 10516761340320196661U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6344049286854588503U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 3531503618941046788U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 10855385899703024105U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 11334308840132700377U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11093833870078787770U;
            aOrbiterJ = RotL64((aOrbiterJ * 16105889714648555755U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3831491136025364271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12505259454860591372U;
            aOrbiterC = RotL64((aOrbiterC * 6135450888433504093U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 38U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 39U)) + aOrbiterA) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 44U)) + aNonceWordA);
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterE, 13U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 58U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30306U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 31415U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25986U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25333U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29472U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 25923U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aIngress, 43U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererG + RotL64(aCross, 39U)) + 11998579547770778580U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 58U)) + 8409465187298704610U) + aNonceWordH;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 19U)) + 3470222286110333500U;
            aOrbiterC = ((((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 5704486785203069994U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 10334944660253279633U;
            aOrbiterG = (aWandererB + RotL64(aCross, 27U)) + 7626852700722567477U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 14631310754943209743U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 43U)) + 807160297237854120U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 52U)) + 5624154783624196107U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4971444394698940423U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6340057638461027062U;
            aOrbiterB = RotL64((aOrbiterB * 12027586111086798629U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9003019862787819481U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13632057463595873033U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12575202147280216765U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12766104026871797746U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 4062118445824915939U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 13130770039048080701U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5258212525426469978U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9956946981015983939U;
            aOrbiterI = RotL64((aOrbiterI * 8106382657040497669U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10837606223056473999U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13292864885504191134U;
            aOrbiterJ = RotL64((aOrbiterJ * 4445739587553669471U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 166087925900318658U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6786842221885441388U;
            aOrbiterD = RotL64((aOrbiterD * 4411147600413147773U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16888086378070246404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5240855484445974002U;
            aOrbiterK = RotL64((aOrbiterK * 402652898573422271U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6874866669211571608U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 732890824978127460U;
            aOrbiterA = RotL64((aOrbiterA * 3776365957702257453U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5541380495707308058U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17947326584411475765U;
            aOrbiterC = RotL64((aOrbiterC * 10920952349981652899U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 52U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 18U) + aOrbiterG) + RotL64(aOrbiterA, 18U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 27U));
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterI, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 39U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 48U));
            aWandererF = aWandererF + (((RotL64(aIngress, 36U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 34U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Rugby_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBC3EBEAEF2D110A5ULL + 0xBBD0A2859A77A1AAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBB0005DAEAA1C755ULL + 0xFB295D4E0AFDD487ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBFFC79D6015E5BBBULL + 0x9600E71DE072F2FCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA1FE4D62673B8475ULL + 0xCF7DE90A43291DA8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC36F6C4AE220A071ULL + 0xEB4F3C874C6D6C92ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCD6B596D189BD247ULL + 0xA7525CB9C81DCFFFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD697B6C97A09514DULL + 0xEC93107B4C0178BEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE57738015230FB83ULL + 0xC9192942A6D564A1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFEBD012DC9EF14C1ULL + 0xCDE2F6BD6721B1ACULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBC6BDB4F74595A4FULL + 0xFF6BCC7BD61E1C44ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8CF79DFEDC2DE0B3ULL + 0xA948DC8FF78FEC6EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x818607374D867899ULL + 0xA93C9E2171368D2FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8557839F0F8B1165ULL + 0x8CBE378E7506AC0BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD222572271CFD979ULL + 0x8B7410B915999DF1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA88CA32D83605271ULL + 0x859C55DA1146F72BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF018D51088C0CF8FULL + 0x909BBC336ECF422EULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneC, aExpandLaneA, aFireLaneC, aOperationLaneA, aExpandLaneB, aFireLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneD, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3968U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 935U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3863U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 420U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5315U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2637U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 3U)) + 6973892330986118220U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 35U)) + 9886813896272094864U) + aNonceWordK;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 10996306582517553173U;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 56U)) + RotL64(aCarry, 57U)) + 8490648283899856223U) + aNonceWordD;
            aOrbiterH = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 105141713530704655U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 41U)) + 3114337422810562588U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 29U)) + 980857684690886131U) + aNonceWordL;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6562042345807072665U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15665371138706353619U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8086237578564620623U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18113013571374375028U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 17405346422601997299U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 11162604605443005253U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5130876096426182506U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1813821672299154629U;
            aOrbiterK = RotL64((aOrbiterK * 15478100342425611875U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15793814882743306728U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13925299440495476399U;
            aOrbiterF = RotL64((aOrbiterF * 12049601510660117401U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9924458846049579438U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7810034662781768090U;
            aOrbiterJ = RotL64((aOrbiterJ * 10310594595026622513U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12812586478656872854U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5709576448057435237U;
            aOrbiterD = RotL64((aOrbiterD * 9101555233909853025U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 7839807649914541516U) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4717944526755429647U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8515229146471335721U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 22U) + aOrbiterC) + RotL64(aOrbiterG, 53U)) + aNonceWordM);
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + aNonceWordG);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 60U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterD, 21U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9800U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 10897U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10484U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10285U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8906U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 11942U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 4634399531433127141U) + aNonceWordE;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 16961792729406903200U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 5U)) + 4105280732301137738U) + aNonceWordP;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 47U)) + 15692013501147331191U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 58U)) + 1252216715968780587U) + aNonceWordL;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 7958289043012473752U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 29U)) + 6611577301818896615U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8506226754305949140U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3648813120449403353U;
            aOrbiterK = RotL64((aOrbiterK * 9521367946879238849U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5195245426245535735U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 542948051600803051U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4631106308856448475U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11974253551208964789U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10596463592332655367U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10941161258815714641U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12015129484061440159U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8254944355710109060U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3233697992479357615U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2754858806943915419U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 5007802002906662779U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 15613733948331639723U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6262190752136523216U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10528977986487821428U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 1184258264034585525U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8511097226098211854U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12091864735686692582U;
            aOrbiterA = RotL64((aOrbiterA * 6128140528141411237U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterH, 6U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 47U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18859U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 22782U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 22411U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22018U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23445U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19902U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 48U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 12583180859826261500U) + aNonceWordG;
            aOrbiterC = (aWandererD + RotL64(aCross, 11U)) + 9067093488553721468U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 47U)) + 12173106198862881754U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 35U)) + 11333491014394592654U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 3511883526940919554U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 53U)) + 7416810692106273044U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 18U)) + RotL64(aCarry, 5U)) + 8341174972619784110U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2220852854836962979U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 8090781422229383825U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 578293950675644397U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2338801236599102223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12484514711848308104U;
            aOrbiterG = RotL64((aOrbiterG * 10364216764253366067U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13684861340589131816U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 12796636819991873058U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5533508014234835669U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7634198650894837690U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10240326122201201762U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 8758703497719125901U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4162814763739453934U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2766504649149048469U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16731843453895178671U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11051393030148769655U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17687055068651386665U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 1042927176246229537U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3353615315436983420U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5971640796220306310U;
            aOrbiterC = RotL64((aOrbiterC * 15804313508835034807U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 41U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 5U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 34U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordD) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24657U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 31719U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32422U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27300U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25986U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31819U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 42U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 12U)) + RotL64(aCarry, 57U)) + 13880995121909552664U) + aNonceWordM;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 14534942818069300546U) + aNonceWordA;
            aOrbiterA = (aWandererF + RotL64(aCross, 41U)) + 17745973100886007133U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 5U)) + 2249805580771946872U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 29U)) + 4460116116396439410U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 3378683994078106878U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 47U)) + 3992996501048809123U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12057768808864451929U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4115362079047921130U;
            aOrbiterA = RotL64((aOrbiterA * 12263015903331031345U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15297384955502206698U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17623548383481905636U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 7487278217901483685U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3559213898000162417U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12311605719074507335U;
            aOrbiterK = RotL64((aOrbiterK * 3982199462062847697U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14807313864347885885U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11222085523291581822U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 12580941911587215653U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 916681229436292462U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2441350114032314686U;
            aOrbiterJ = RotL64((aOrbiterJ * 7336079498999018067U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7361470539894653271U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12153585147213579808U;
            aOrbiterE = RotL64((aOrbiterE * 3040327545467672961U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13566300726101613579U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14875254144748509128U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13699179902908972403U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 26U) + RotL64(aOrbiterA, 37U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterA, 44U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC07BE2BD2909F8F3ULL + 0xDDB23F55B35FA23EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA1F5ABE7B5055171ULL + 0x97F74186FF49B49CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAA3D0939CEB23B4BULL + 0xDF38CE8AD9F1C88BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB6E0024AF09F3BDBULL + 0xD611F2FFE4633646ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE0D4D3926149DFE7ULL + 0x925BC8E655A443FAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x94E67A0310B4BC03ULL + 0x8A9372E3C25BED94ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE6C247EECC0B17C5ULL + 0xCFB759EAC96906C4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE916CB8408389F67ULL + 0x9D6CC602EA700038ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE8D6C0B107EEF7FDULL + 0xE9AD54AC0A5BF19AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEFBB5FB709EC1F77ULL + 0x83D899385F1340FEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x85D16E874CDDDCD3ULL + 0xF7E09F56D9B4AD96ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF206DDB8C2787281ULL + 0x8D6D8F67A22F94EBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF39A0B24FDB3F36DULL + 0xCC25AB2D9B76E529ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAE5F9A6FCEFB273BULL + 0xB4B2780EE4B367EBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEB48765031B8AB17ULL + 0xA9A3EC58F6B5F740ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEB21CE969DF4D827ULL + 0xF3BF5A633A57A670ULL);
    // GSeedRunSeed_A seed_loop_a (start)
    {
        // GSeedRunSeed_A seed_loop_a lane group
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2567U)) & W_KEY1], 4U) ^ RotL64(aKeyRowReadB[((aIndex + 1650U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 123U)) & W_KEY1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2518U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (aWandererA + RotL64(aCross, 37U)) + 17668251151213543491U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 16101602509895104517U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 58U)) + 9083915270773304935U) + aNonceWordM;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 19U)) + 12810720730318214811U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 18113428002071925621U) + aPhaseEOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 51U)) + 1582208899354109878U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 4180688104819188154U) + aNonceWordJ;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8954598189262820611U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15360094153175355879U;
            aOrbiterC = RotL64((aOrbiterC * 8177798855402983685U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8383954114668216260U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15626783326234049197U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 15058420415480073793U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10609978564404958066U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17656516608997517984U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4590620354119899777U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 760077259110786536U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 3597338735888033063U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 6548831472863517621U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4431777844935985157U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10710423172154671296U;
            aOrbiterE = RotL64((aOrbiterE * 16267496318491473315U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 10240882795242085185U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7826053487019825891U;
            aOrbiterJ = RotL64((aOrbiterJ * 15053729937684375907U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9418883403715727353U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11507423614799075545U;
            aOrbiterI = RotL64((aOrbiterI * 16189463984557044693U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 42U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterD, 5U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 50U)) + aNonceWordH) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 28U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aWorkLaneA, aKeyRowReadA
        // ingress directions: aWorkLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 4134U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3643U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3089U)) & W_KEY1], 20U) ^ RotL64(mSource[((aIndex + 3032U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 23U)) + 16160838483846078448U) + aNonceWordN;
            aOrbiterK = ((aWandererD + RotL64(aCross, 29U)) + 15404960896190227946U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 57U)) + 16904160594024977199U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 17790460246821031802U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 16395168254086971959U) + aNonceWordD;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 12U)) + 7484373204039901786U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 18026814691322913510U) + aNonceWordM;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15244817793136966450U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5795491730356335666U;
            aOrbiterI = RotL64((aOrbiterI * 13253529465289332171U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3163873518027801504U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2690791759507349172U;
            aOrbiterB = RotL64((aOrbiterB * 16677948635136515083U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17898067251167087906U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8028010015006604239U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5601629670521300241U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7304739457289910555U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6476837815096530043U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 16380545138701113267U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14242499233467960602U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17305645693017634630U;
            aOrbiterC = RotL64((aOrbiterC * 14442976693206929569U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9772864059444171908U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7897200728282156408U;
            aOrbiterD = RotL64((aOrbiterD * 816306719390807411U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4890999319172950996U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8165132649356094963U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17297706071263690189U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterC, 47U)) + aPhaseEWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 51U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterA, 53U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterK, 22U)) + aOrbiterB) + aNonceWordI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aWorkLaneB, aKeyRowReadB
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aWorkLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneB[((aIndex + 6915U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadB[((aIndex + 6240U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8025U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6088U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7816U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 3561491146322798260U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 12U)) + 7075025056181885339U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 37U)) + 9230910887904171613U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 4119781172609908917U) + aNonceWordE;
            aOrbiterH = ((aWandererD + RotL64(aCross, 43U)) + 17155609083870983149U) + aNonceWordA;
            aOrbiterA = ((((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 2423018561430181695U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererK + RotL64(aIngress, 21U)) + 12957280305617615744U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2461704174772065813U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7907123257849391997U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9416171962847312179U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7257868138318960007U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16425903703085702285U;
            aOrbiterE = RotL64((aOrbiterE * 7996935869077231999U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2990822664594079467U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5654819006718953817U;
            aOrbiterG = RotL64((aOrbiterG * 4465096036756887801U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12183676471235678779U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15026286960542123922U;
            aOrbiterF = RotL64((aOrbiterF * 17199049329995315279U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 12169080607071830522U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2906296852254787499U;
            aOrbiterH = RotL64((aOrbiterH * 6754514406846040163U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3029858695410344584U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14406410317495954566U;
            aOrbiterI = RotL64((aOrbiterI * 9663780721657983421U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11048818178401163861U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13622063920319445043U;
            aOrbiterA = RotL64((aOrbiterA * 2516025554421589857U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 51U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 14U)) + aOrbiterH) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterH, 43U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aWorkLaneC, aKeyRowReadB, mSource, aWorkLaneA
        // ingress directions: aWorkLaneC forward forced, aKeyRowReadB forward forced, mSource forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, aWorkLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8947U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 8293U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 8395U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8687U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8514U)) & W_KEY1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8988U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 14U)) + (RotL64(aCarry, 27U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 6068543441070417854U) + aNonceWordM;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 41U)) + 2995980468193441856U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 18020277482171594003U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 60U)) + 4293807434721230702U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aWandererG + RotL64(aCross, 35U)) + 7980599111583893156U;
            aOrbiterB = ((((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 8593141111851052016U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aWandererH + RotL64(aIngress, 27U)) + 5903487523900084325U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15112035513447930209U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9854037263057006439U;
            aOrbiterJ = RotL64((aOrbiterJ * 396276470208637283U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 16759760289688823193U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12622628933030601390U;
            aOrbiterK = RotL64((aOrbiterK * 2151912984825538321U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 1264668857268123425U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16302812053619101593U;
            aOrbiterC = RotL64((aOrbiterC * 18291400055836111547U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16087995784896123610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7970269262800468363U;
            aOrbiterD = RotL64((aOrbiterD * 14924752223305807461U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5331477046030959632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16534913204255550893U;
            aOrbiterB = RotL64((aOrbiterB * 1013433634373673565U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11042821902537871209U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8069677512345031660U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 13622218526054132397U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5737130058129936372U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1076627182956662997U;
            aOrbiterF = RotL64((aOrbiterF * 14342191224014199929U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterB, 51U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 54U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterI, 12U)) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aWorkLaneD, aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneB
        // ingress directions: aWorkLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aWorkLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneC backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13401U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 11739U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11148U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 12249U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13415U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12370U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 13009U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 52U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (aWandererJ + RotL64(aCross, 19U)) + 16462052553719977502U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 41U)) + 12337064059566619581U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 13U)) + 15801005007094515447U) + aNonceWordD;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 8228706742665081656U;
            aOrbiterB = (aWandererH + RotL64(aCross, 47U)) + 11006723027845190869U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 18173765337829177450U) + aNonceWordJ;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 4U)) + RotL64(aCarry, 27U)) + 530215083653542558U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6608611827035564511U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2246051826221626809U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6333352641495253539U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5228575308895381421U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 10999213210689606857U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 5467601259546342925U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 3773371037240485696U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8887985779436152504U;
            aOrbiterG = RotL64((aOrbiterG * 698713082830739677U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11150566414723818350U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8336366151003049546U;
            aOrbiterB = RotL64((aOrbiterB * 9033771197242493699U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13233968794237090787U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8172558473508478819U;
            aOrbiterK = RotL64((aOrbiterK * 17837070423649268435U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 133564480283347997U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15104810248883567064U;
            aOrbiterH = RotL64((aOrbiterH * 706802420642303533U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 9138629520201127075U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13993086066341664080U;
            aOrbiterI = RotL64((aOrbiterI * 4875046427147105077U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 12U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + aNonceWordC);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 28U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterG, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 20U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aFireLaneA, aWorkLaneC
        // ingress directions: aFireLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneB, aWorkLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aWorkLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 15636U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16002U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15063U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14188U)) & W_KEY1], 13U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14174U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16313U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15837U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 8375305456876489425U;
            aOrbiterA = (aWandererB + RotL64(aCross, 53U)) + 16193562952772453047U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 18088652458594816223U) + aNonceWordL;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 29U)) + 767344788620249944U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 7705194930396368752U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 5U)) + 3829736891311272834U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 11U)) + 9881681671347640061U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1721196560190164264U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3002652618388454213U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 15289749311593032657U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9811621464004005202U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5652598941069986530U;
            aOrbiterJ = RotL64((aOrbiterJ * 4797973356708091621U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6250499348327316328U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16025054277615264530U;
            aOrbiterF = RotL64((aOrbiterF * 16446892258704281903U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13800298546867243172U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12256104592865905782U;
            aOrbiterG = RotL64((aOrbiterG * 16983140179497142713U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17817225416918329229U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17738671327352776217U;
            aOrbiterA = RotL64((aOrbiterA * 393488251327705063U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6816031224188400541U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16989563985059237014U;
            aOrbiterK = RotL64((aOrbiterK * 8677884225771717797U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16891524847268207549U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1833508573940405571U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9709196587703979539U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterF, 3U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 56U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 7
        // ingress from: aFireLaneB, aKeyRowReadA, mSource, aWorkLaneA
        // ingress directions: aFireLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadB, aWorkLaneD, aFireLaneA
        // cross directions: aKeyRowReadB backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 17714U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 17973U)) & W_KEY1], 12U));
            aIngress ^= (RotL64(mSource[((aIndex + 18783U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 17902U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17419U)) & W_KEY1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18375U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 19037U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 13650869943246163567U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 3435284932011770999U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 43U)) + 12388155658186776579U) + aNonceWordO;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 50U)) + RotL64(aCarry, 19U)) + 2374345913955712039U;
            aOrbiterA = (aWandererH + RotL64(aCross, 29U)) + 6095094526980292156U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 23U)) + 4965147025852444174U) + aNonceWordH;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 11U)) + 3261881216269075298U) + aPhaseGOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 4939780217097329222U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3019862009792676287U;
            aOrbiterE = RotL64((aOrbiterE * 2452316208025448747U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 901910626217143974U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3647055146712366383U;
            aOrbiterA = RotL64((aOrbiterA * 1792602402476450009U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7731765438957392967U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13409819457393479741U;
            aOrbiterH = RotL64((aOrbiterH * 3345078200262410715U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5415832109107794258U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8876738832313114471U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1304277600444504135U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17135570542519390359U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2373193062766802082U;
            aOrbiterC = RotL64((aOrbiterC * 4213691513185791519U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 16318403285501718552U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8456043288604687045U;
            aOrbiterF = RotL64((aOrbiterF * 10556964529144571683U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10572534930284516528U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14616251186735204677U;
            aOrbiterB = RotL64((aOrbiterB * 2048651204265459805U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 30U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordK) + aPhaseGWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterJ, 20U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + aNonceWordI) + aPhaseGWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 8
        // ingress from: aFireLaneC, mSource, aFireLaneA, aWorkLaneA
        // ingress directions: aFireLaneC forward forced, mSource forward forced, aFireLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aFireLaneB, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aFireLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 20660U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 20418U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20022U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21619U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20620U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20034U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20282U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21032U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 22U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 13U)) + 3973833383430652211U;
            aOrbiterC = ((((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 5760227042747169187U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 4923009065139227286U) + aPhaseGOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aCross, 6U)) + RotL64(aCarry, 11U)) + 1477807307009107590U) + aNonceWordM;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 53U)) + 5707194514329007301U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 21U)) + 5340439728375269724U) + aNonceWordF;
            aOrbiterA = (aWandererC + RotL64(aIngress, 43U)) + 17080457898946572387U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 281559150259472813U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16160633048230910560U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16883442583309073785U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9003989610509592121U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10579322462808454333U;
            aOrbiterC = RotL64((aOrbiterC * 100832431598087235U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 15059383289528723069U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10417647757852880956U;
            aOrbiterF = RotL64((aOrbiterF * 1457919230286043137U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14484665027393813330U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12344463053485837974U;
            aOrbiterG = RotL64((aOrbiterG * 5762654194001525041U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5826453246659297805U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12547902286376986223U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 2982850000322672789U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9637855144278126174U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2132744427444501938U;
            aOrbiterA = RotL64((aOrbiterA * 5911587798564836199U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9248933938130311231U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 13274297928717090383U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 2901398809555237563U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 58U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + aNonceWordN) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + aNonceWordP);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterK, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 9
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, aFireLaneC
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aFireLaneC forward/backward random
        // cross from: mSource, aFireLaneA, aWorkLaneC, aWorkLaneD
        // cross directions: mSource backward forced, aFireLaneA backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 24304U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 22628U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22886U)) & W_KEY1], 53U) ^ RotL64(aFireLaneC[((aIndex + 22376U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22910U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22994U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22129U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((aIndex + 23903U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 44U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 10812151398716051703U) + aNonceWordD;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 18202551453336003710U) + aPhaseGOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 21U)) + 9434410809101973752U) + aPhaseGOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 14U)) + 12955829998028534045U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 41U)) + 12271740641929640181U) + aNonceWordG;
            aOrbiterK = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 14009351527014534752U) + aNonceWordO;
            aOrbiterD = (aWandererE + RotL64(aScatter, 5U)) + 4316296955679133450U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16473324966997442872U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15735123324965019802U;
            aOrbiterC = RotL64((aOrbiterC * 5624078184997601019U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17656375090484080236U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16066325053456055298U;
            aOrbiterK = RotL64((aOrbiterK * 17912970706985130327U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12908968778503516903U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12761433987676836197U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1023329467480907925U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12737513138040664509U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14535795767570998392U;
            aOrbiterE = RotL64((aOrbiterE * 15560519667062222269U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14370908061811284364U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7001358781208669795U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11641248025734015835U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 7298578161120090849U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10498302152357484629U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 13144110412179037175U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11447343228638006767U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 18284143620422655675U;
            aOrbiterD = RotL64((aOrbiterD * 572862190073605651U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aNonceWordJ) + aPhaseGWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 12U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterH, 41U)) + aNonceWordK) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aFireLaneD, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aFireLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aFireLaneC, aWorkLaneD
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aFireLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25253U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 25671U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27198U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27109U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25634U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25411U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25718U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 26867U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 34U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (((aWandererA + RotL64(aScatter, 35U)) + 3917730204724097072U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 1874642340716212824U) + aNonceWordL;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 41U)) + 6900165757434854160U) + aPhaseHOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 12750946097023807161U) + aNonceWordN;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 6563216048479513594U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 5U)) + 14960240191349450795U) + aNonceWordK;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 22U)) + 16306180275951788289U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6502066618271045547U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6219852857850888738U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10892297250334325283U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2272931312452845850U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3028929882263199463U;
            aOrbiterH = RotL64((aOrbiterH * 11005324285856805069U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6067393030073568112U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10094809900437037258U;
            aOrbiterA = RotL64((aOrbiterA * 18095564940730322769U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5962414178157074575U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15755563045799129417U;
            aOrbiterC = RotL64((aOrbiterC * 3692603590609922031U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6321455513889880590U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1197435601998121700U;
            aOrbiterB = RotL64((aOrbiterB * 17693996266260557625U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12496949381666299968U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 6357070235648527030U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2931486644220862433U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8423760160877540210U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8090246492554850768U;
            aOrbiterI = RotL64((aOrbiterI * 2949407491181921633U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + aPhaseHWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 37U));
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterH, 30U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aCross, 24U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + aNonceWordC);
            aWandererI = aWandererI + (((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 23U)) + aNonceWordH) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 11
        // ingress from: aExpandLaneB, aFireLaneD, aKeyRowReadB, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aFireLaneD forward forced, aKeyRowReadB forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29045U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((aIndex + 28974U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28246U)) & W_KEY1], 36U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27885U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29311U)) & W_KEY1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27613U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27699U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28583U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 43U) + RotL64(aIngress, 30U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 29U)) + 6381335981879993247U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 15595429101600023172U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 5449234297249826461U) + aNonceWordO;
            aOrbiterA = (aWandererD + RotL64(aScatter, 35U)) + 11213734849329731168U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 16438473952464514248U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 3U)) + 7357872882115186976U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 54U)) + 394402075160738643U) + aPhaseHOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11112941985410283532U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14955125011182736212U;
            aOrbiterG = RotL64((aOrbiterG * 10711684773326395603U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 14770727009821304070U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 11286366598129204910U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15884310771003021989U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7358400908565425780U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15635109923749114761U;
            aOrbiterI = RotL64((aOrbiterI * 12415152149408700329U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13826842523738623579U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1072811298828325231U;
            aOrbiterC = RotL64((aOrbiterC * 9662800288646215083U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4017334196009350776U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8812213572751410831U;
            aOrbiterH = RotL64((aOrbiterH * 12744171921566782795U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 6723457786170634403U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9785583533999417673U;
            aOrbiterA = RotL64((aOrbiterA * 7776915427605471097U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10265132640322153964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8435670887514808087U;
            aOrbiterB = RotL64((aOrbiterB * 2706263045620662131U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + aNonceWordJ);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 54U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 14U)) + aOrbiterG) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterB) + aPhaseHWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aFireLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aFireLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 30253U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31335U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30129U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31030U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31837U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 31176U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 54U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 9630214189402543339U) + aNonceWordC;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 4072576573737526819U;
            aOrbiterK = (aWandererA + RotL64(aCross, 5U)) + 15994787452709618869U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 13U)) + 6403240137132259482U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 10229266900170507720U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 37U)) + 5025294577989748989U) + aPhaseHOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 50U)) + 16696461238217956883U) + aPhaseHOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9878318855341719119U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16086635438116177346U;
            aOrbiterK = RotL64((aOrbiterK * 5585682357395705671U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12295437783084203730U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7681150419912842402U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7289497379725191451U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2639104034287637448U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12298170009332243573U;
            aOrbiterE = RotL64((aOrbiterE * 9397919591171238575U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3485932317267669626U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16569551670038752475U;
            aOrbiterH = RotL64((aOrbiterH * 8139802826402217631U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4448490103784103954U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14510534073046885941U;
            aOrbiterA = RotL64((aOrbiterA * 7777192047386438305U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4286195398675733451U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15790355933840266463U;
            aOrbiterF = RotL64((aOrbiterF * 13342257823027075501U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6362891510370156055U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15121822034579983174U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7268045994574844937U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 54U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 35U)) + aNonceWordM) + aPhaseHWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterC, 27U)) + aNonceWordN);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 27U) + RotL64(aOrbiterH, 34U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCA33DB99613C16B3ULL + 0xBD1777BB0F426752ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD66A79E92EA7B6AFULL + 0xE0EEBDC5A6E7B572ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC3956659A4127B23ULL + 0xAA4C7F3B5ADB8ECFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE0F1323B9477B2F1ULL + 0xAA64B8819DE74D10ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x86579C95B2D581D3ULL + 0xFD585CE0FBD617CDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF3C2C901ECE70737ULL + 0xB04AC9CF1C062E11ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE9C1637F5F6DBE2BULL + 0xFB5E720EC7D2EB24ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x98D85A37A4367589ULL + 0xE5D4F0FF24A545A5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8153B28BB5B8DA07ULL + 0xA91867DF7A404600ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8DEFA746CD96F38FULL + 0xF2714EA1F4B0EDCCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD51B1DB705E381FDULL + 0xE7D06B4448113645ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA0FEE51541338BDFULL + 0xE44E71981AA13C29ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAC96B166FFDB8199ULL + 0xD2DB47970AB75A52ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBB0F787530F8AA7FULL + 0xCA558FAB69591309ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD128B5C57A22C3EBULL + 0xC6F81D1F34E8A455ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFF894E83373DC997ULL + 0xAC09ACB527991488ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneA, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1696U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 169U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 506U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1353U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 3572U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 26U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 5568146815535263910U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 38U)) + RotL64(aCarry, 29U)) + 7736084960873834666U;
            aOrbiterB = ((((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 1336413621817562093U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 11U)) + 5218462026934984692U) + aNonceWordM;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 19U)) + 7048890985969555935U) + aPhaseAOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13415955213864702118U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5657023257021528548U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 5200798937081797819U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14338310943137497116U) + aNonceWordC;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 12305161641833950473U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 11949964304435964395U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14514226578370459131U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 12692904083266024340U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14800805065279908839U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11012959130001327964U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7106471380403489078U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 515626559384817223U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3718101961355280891U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13364192077222322664U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1411328915372590283U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 46U)) + aOrbiterD) + aPhaseAWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 42U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6875U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 7615U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10734U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5573U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9586U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 4U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 8767379393098711499U) + aNonceWordI;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 7168159491580816433U) + aNonceWordK;
            aOrbiterC = ((aWandererF + RotL64(aCross, 28U)) + 9879279829061883406U) + aNonceWordA;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 10537167136053399303U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aCross, 19U)) + 2839070018069188936U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13844278063968429732U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11278946626186474646U;
            aOrbiterC = RotL64((aOrbiterC * 6601953972456332355U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11798425216660557799U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7618446090703335192U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7168757300685156779U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 695423597006983660U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14344728202803488813U;
            aOrbiterH = RotL64((aOrbiterH * 5168825904902285909U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11656100506575697086U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10384358779985773937U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 247494692039140973U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17585001605131977341U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9964478171465522911U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13484044854790175315U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 54U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 40U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + aNonceWordL) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + aNonceWordB);
            aWandererD = aWandererD + ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + aNonceWordM) + aPhaseAWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 4U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15112U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 12244U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 14902U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12288U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14261U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16027U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 17081642665820489793U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererG + RotL64(aCross, 3U)) + 14468854040067229623U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 2249450222593057429U) + aNonceWordM;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 14964389079511378664U) + aNonceWordC;
            aOrbiterH = ((aWandererA + RotL64(aCross, 30U)) + 17003491054252360650U) + aPhaseAOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12710882240582032588U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 9887078182156755359U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 8205865025853482573U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7665284531810584704U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7304284015511876717U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6193179739025093929U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 5517927023543751734U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17704756310857362759U;
            aOrbiterH = RotL64((aOrbiterH * 15826832172923213591U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11347400363019508578U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11696395232760991243U;
            aOrbiterB = RotL64((aOrbiterB * 9725231749679442003U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10875780291242873583U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7808740614343437672U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 8889516201913716283U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordF) + aPhaseAWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterJ, 28U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21389U)) & S_BLOCK1], 44U) ^ RotL64(aInvestLaneA[((aIndex + 21817U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 16992U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19780U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17087U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17108U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 29U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 21U)) + 16451272412693907816U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 3U)) + 10099485419723255462U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 17668900099534923192U) + aNonceWordN;
            aOrbiterD = ((((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 5497093724143181753U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 19U)) + 10354044773550071706U) + aNonceWordF;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 12728258851198019099U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4144050505314242618U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13629477513971467419U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14133805325480076530U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 308863673210602899U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2672613556981540433U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11741180130160569753U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12926863156769180448U;
            aOrbiterI = RotL64((aOrbiterI * 9726030996091054939U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 211920854786494259U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13234608842479411078U;
            aOrbiterG = RotL64((aOrbiterG * 2556747209733759467U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9164711974854618892U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 6667377062281954219U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 2603737166987437649U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 56U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + aNonceWordP);
            aWandererB = aWandererB + ((((RotL64(aIngress, 14U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterI, 36U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + aNonceWordE) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aOperationLaneB, aOperationLaneA, aExpandLaneB
        // ingress directions: aOperationLaneB forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aExpandLaneC, aInvestLaneA, aInvestLaneB
        // cross directions: aExpandLaneC backward forced, aInvestLaneA backward forced, aInvestLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23850U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 22427U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 25774U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26062U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26490U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23611U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 51U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 1457104756581596530U) + aPhaseAOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 6127240317844622874U) + aNonceWordL;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 13U)) + 16492290056044189421U) + aPhaseAOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 10963676850938416468U) + aNonceWordI;
            aOrbiterJ = (aWandererA + RotL64(aCross, 54U)) + 4872917367399752405U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15218882377875616148U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5934166612122118251U;
            aOrbiterB = RotL64((aOrbiterB * 10365045124180379919U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14215280930872003003U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 11428034799044600979U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 12162528943733976177U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5453003654321728726U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14273775120265649389U;
            aOrbiterD = RotL64((aOrbiterD * 5139018128323795309U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 328723770018440271U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13032190719588211088U;
            aOrbiterJ = RotL64((aOrbiterJ * 13363368478932798315U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 2386881543033598494U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1649501123340887116U;
            aOrbiterK = RotL64((aOrbiterK * 11148976582360499033U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 6U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + aNonceWordD);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterF, 22U)) + RotL64(aCarry, 37U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aOperationLaneC, aExpandLaneA, aExpandLaneB
        // ingress directions: aOperationLaneC forward forced, aExpandLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneB, aOperationLaneA, aInvestLaneB
        // cross directions: aOperationLaneB backward forced, aOperationLaneA backward forced, aInvestLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27439U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 32480U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27924U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28231U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30675U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32308U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererI + RotL64(aScatter, 57U)) + 18255347001097480328U) + aPhaseAOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 48U)) + RotL64(aCarry, 53U)) + 13679246790311505735U) + aNonceWordE;
            aOrbiterC = ((aWandererF + RotL64(aCross, 5U)) + 10565839529765027116U) + aNonceWordN;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 14327172566224769901U;
            aOrbiterI = ((((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 16239024612038195174U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13800012174212131890U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13900288860157577583U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13177682776510523095U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4144386119777112740U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3154558262670631372U;
            aOrbiterJ = RotL64((aOrbiterJ * 13236911910092437063U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7456728543137614001U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11709519851158935384U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 7016689518570071587U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15607438907832240304U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9276575329661725624U;
            aOrbiterI = RotL64((aOrbiterI * 8879744070762412745U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6459435969129449226U) + aNonceWordO;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 6442382118416542275U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 2921027306686588233U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 50U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterI, 60U)) + aNonceWordP) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + aNonceWordH) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8FE78FB7EAB6C401ULL + 0x99F61736ACB603A0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAB89451308C2DC29ULL + 0xB7AAD59135C8D1B2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBB3A6E5EBB4D272DULL + 0xCCFFB5C1BB8FAED0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA5A225532ADFDAF3ULL + 0xC5A5CBB93D7212ABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9E67B65CC3931605ULL + 0xCABE5886680BBC0BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA726CAFE85784CC7ULL + 0x8ED2B3AD325A623AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE364AD667CC2C639ULL + 0xEE62CA036E60206BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF08B2BCEF8B61E19ULL + 0xCC0815F2AEE3F515ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF6287C4F3D8CD5F5ULL + 0xB8F85B8DCF0AEA9DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB239AA8D21BEB8DFULL + 0x836F740FF074FE02ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAEC3DE362A013E3DULL + 0xD03F4C736AB21A53ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCEED49EE0DD7482DULL + 0x8ACBCA45DB6F2BFCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD3CB51390A5F51CFULL + 0xF4FD2BAF05C99FC9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x896311ED06D14EC7ULL + 0xB7CD2A9D38169EB4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9F6AE4D2D126016BULL + 0xD2352C6DAE28888EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE69E46CE0AEBCF5BULL + 0xE0C4B9C9EB8CC43EULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB, aInvestLaneC, aExpandLaneC, aFireLaneD, aInvestLaneD, aExpandLaneD, aWorkLaneA, aExpandLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aFireLaneA
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1908U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 2224U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1988U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1515U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2938U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2165U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 10U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 14686411261024919129U) + aNonceWordM;
            aOrbiterD = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 7514582233957632005U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 57U)) + 6520710480103365552U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 1983621978676188036U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 10U)) + 9003524602590749672U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 19U)) + 6428568234045228995U) + aPhaseBOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 23U)) + 8656552687136446989U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 5U)) + 16916248288415922490U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aWandererG + RotL64(aIngress, 42U)) + 9740237548002535784U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 907561000814618339U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4751108900841197631U;
            aOrbiterG = RotL64((aOrbiterG * 4545395964730641957U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 167774899400732287U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11907484918310854962U;
            aOrbiterE = RotL64((aOrbiterE * 7213139491146402985U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14910318613649863924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14882888155751455276U;
            aOrbiterD = RotL64((aOrbiterD * 11394136445442060201U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16175942562693781908U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11022373758481651102U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 6836331461393816027U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12548405399045031548U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10850926364556828443U;
            aOrbiterB = RotL64((aOrbiterB * 16231561687709867431U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13391684887911141790U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14648937281264822988U;
            aOrbiterC = RotL64((aOrbiterC * 6533299316940026059U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8298658887198526821U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13822977698661348891U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 17769262972278410937U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 7505646847564645719U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3238749538197209166U;
            aOrbiterA = RotL64((aOrbiterA * 15394286542600778567U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15853506915123709257U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8426329899401071248U;
            aOrbiterH = RotL64((aOrbiterH * 1330397096577715113U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 28U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 6U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aCross, 6U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterF, 60U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterE, 11U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterG, 29U)) + aNonceWordL) + aPhaseBWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterJ, 19U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 57U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9221U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 8042U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6698U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 8736U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9734U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10648U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8966U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 13U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 56U)) + RotL64(aCarry, 51U)) + 2558105147674438050U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 15856662514774702561U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 11U)) + 13346869226246584582U) + aPhaseBOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 27U)) + 7632111846116243973U) + aPhaseBOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 41U)) + 2102101361626976279U) + aNonceWordP;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 5605968705067851563U;
            aOrbiterC = (aWandererG + RotL64(aCross, 51U)) + 6842483186584326681U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 60U)) + 5559797213819425064U) + aNonceWordE;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 21U)) + 12422313931331576759U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2751024420047872601U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11031320239359798610U;
            aOrbiterI = RotL64((aOrbiterI * 8607639453141148025U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14366375309473793217U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11971479429768505316U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10063001532313098203U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3947595951884469542U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17882767922372770896U;
            aOrbiterA = RotL64((aOrbiterA * 3361906348965810211U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 513871456983509223U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5951677013597794294U;
            aOrbiterF = RotL64((aOrbiterF * 8508629569649935293U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 437626309049021931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 466674061172005705U;
            aOrbiterG = RotL64((aOrbiterG * 1310502572084891157U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12362602809233133718U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10525852878882195702U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 17755022180514914325U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17927000184308583095U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 566723721423470052U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17710534355278632573U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9504585484034413577U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4614306037721859929U;
            aOrbiterK = RotL64((aOrbiterK * 170807293799483539U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1463218357720031588U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4036696102163560633U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 15389914226155130065U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 48U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 42U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterI, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aCross, 12U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 22U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aNonceWordK) + aPhaseBWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 18U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneD
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12407U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 14303U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 12340U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11667U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15397U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 60U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 12222235191147985484U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aWandererF + RotL64(aCross, 22U)) + 16367317014523328414U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 47U)) + 3511378091284703789U) + aNonceWordF;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 15247492830966725949U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 57U)) + 7745995913390407897U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 36U)) + 6463593307540108810U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 5U)) + 1101669311005268630U) + aNonceWordJ;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 51U)) + 12988052764067518580U) + aNonceWordA;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 11U)) + 17717179747434679772U) + aPhaseBOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11662190906682400416U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6563014073547628748U;
            aOrbiterA = RotL64((aOrbiterA * 16967910471722117761U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13099094932059419219U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16342730862261868847U;
            aOrbiterH = RotL64((aOrbiterH * 10988124108686164829U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16855346813127524624U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6570063128502306944U;
            aOrbiterE = RotL64((aOrbiterE * 4571570049463124831U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11328352033809240501U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11640986648833160901U;
            aOrbiterB = RotL64((aOrbiterB * 2895830492089678919U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2675226158571501666U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17700531248266458165U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 2231403813970188657U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 7729597396731910874U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15172374484412053756U;
            aOrbiterJ = RotL64((aOrbiterJ * 149009041406406517U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9178769489257842683U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9020154972097834926U;
            aOrbiterI = RotL64((aOrbiterI * 8910504667566521429U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1317403761217790562U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17151528554929201571U;
            aOrbiterD = RotL64((aOrbiterD * 3735945655450625203U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11621882033959669977U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10289504450815075623U;
            aOrbiterF = RotL64((aOrbiterF * 13365982786836243195U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 11U));
            aWandererC = aWandererC + ((((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF) + aNonceWordL) + aPhaseBWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 54U));
            aWandererE = aWandererE + ((RotL64(aIngress, 12U) + RotL64(aOrbiterI, 23U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aExpandLaneA
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aExpandLaneA forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19558U)) & S_BLOCK1], 18U) ^ RotL64(aInvestLaneC[((aIndex + 19593U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18825U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20179U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18667U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 24U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((aWandererH + RotL64(aScatter, 23U)) + 11039986441331892533U) + aNonceWordP;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 30U)) + RotL64(aCarry, 47U)) + 6256024955965426119U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 39U)) + 9857443189988995666U) + aNonceWordB;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 19U)) + 11900944813380998208U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 47U)) + 8422577734978875541U) + aNonceWordE;
            aOrbiterH = (aWandererA + RotL64(aIngress, 10U)) + 3100835100713928724U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 11871553509810206993U) + aPhaseBOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 17614749493763417027U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 3U)) + 3638372131856199916U) + aNonceWordG;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6582275259281025770U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17016882418498941958U;
            aOrbiterD = RotL64((aOrbiterD * 4269869255230867823U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 1747214688658984715U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9356088987044015278U;
            aOrbiterF = RotL64((aOrbiterF * 16221733545319753695U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4056238112133473456U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16013150119949532998U;
            aOrbiterJ = RotL64((aOrbiterJ * 12913648646318115315U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16076621211111834889U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9940824359571581765U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11624767861336495331U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15624084004784515753U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7630989544834680335U;
            aOrbiterH = RotL64((aOrbiterH * 12261063237156822067U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18003586430673313786U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1654118743290334161U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1153250137357176071U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3254189676528343910U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15629083361573065165U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 17024833368570949107U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10056859810555674806U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15976683222786846254U;
            aOrbiterC = RotL64((aOrbiterC * 2801754232182942635U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11872378594829637933U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7633773773528713489U;
            aOrbiterB = RotL64((aOrbiterB * 8218288492011593353U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + aPhaseBWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterC, 18U)) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21975U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((aIndex + 25503U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 22469U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27019U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22926U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 57U)) + 7960325128608297381U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 39U)) + 12773836012104052042U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererK + RotL64(aScatter, 13U)) + 3173972621347773016U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 4U)) + 3708401356314308171U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 950774285720019449U) + aNonceWordD;
            aOrbiterK = (aWandererB + RotL64(aCross, 29U)) + 4170092315705438265U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 17000449130864980747U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 24U)) + RotL64(aCarry, 19U)) + 8793910540062893860U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 47U)) + 520277969543516469U) + aNonceWordE;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12762214857389827271U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2932451184340207695U;
            aOrbiterI = RotL64((aOrbiterI * 7513337346940091655U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11062179998786293839U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7919119215271524178U;
            aOrbiterB = RotL64((aOrbiterB * 9053677007180081359U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1774988449597115155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3799792889466518953U;
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1815062051307896589U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15260373951371654483U;
            aOrbiterG = RotL64((aOrbiterG * 2208604434669491625U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12867546628945676853U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7772820973895846946U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 7581704643538761985U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14213957831821966834U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16561105721170419454U;
            aOrbiterF = RotL64((aOrbiterF * 2540533987337175367U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16556502948339949526U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9706742922075498974U;
            aOrbiterK = RotL64((aOrbiterK * 8527361328901355457U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13455756934917486016U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9107769876332723454U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1722386100852683783U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15793099079168487016U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7968278803691283365U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11644765391940099387U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 4U)) + aOrbiterD) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterA, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterI) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 30U) + aOrbiterK) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 12U)) + aOrbiterA) + aNonceWordK) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29272U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 30244U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28139U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28978U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 31199U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 40U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (aWandererI + RotL64(aScatter, 29U)) + 7722279280863371124U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 19U)) + 11584220561732385598U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 24U)) + 7834679350105534657U;
            aOrbiterJ = ((((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 11347994382444180879U) + aPhaseBOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aWandererC + RotL64(aScatter, 43U)) + 9449903188047063431U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 6516243976652795170U) + aNonceWordH;
            aOrbiterI = (aWandererH + RotL64(aIngress, 47U)) + 8420815253991184777U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 51U)) + 9081386852515170937U;
            aOrbiterH = ((((aWandererG + RotL64(aIngress, 6U)) + RotL64(aCarry, 5U)) + 14375955191735286867U) + aPhaseBOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 880757589768436072U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3349856625725164229U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 681514212582331781U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7826309957607577207U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8057435761214313635U;
            aOrbiterK = RotL64((aOrbiterK * 4718430712767038607U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9565237500443303103U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15893066735310588501U;
            aOrbiterJ = RotL64((aOrbiterJ * 8457633439171452397U), 43U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 3276844534476430842U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6828644383891274120U;
            aOrbiterI = RotL64((aOrbiterI * 979580351653410157U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2815676923011504251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5030251870850928417U;
            aOrbiterH = RotL64((aOrbiterH * 7075653570570819253U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13464083008377887034U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8994560761846897590U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 9892839554658865143U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8398813387154468736U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 8136429428340910892U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 3348811490733577295U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 418587250696862341U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4111667833838312094U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 860949442143849147U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6075478294190926371U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2208124955874142264U;
            aOrbiterD = RotL64((aOrbiterD * 15741988616251072075U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterH, 52U)) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterI) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterJ, 24U));
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK) + aNonceWordO) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEDE536C16C43CC3FULL + 0x9104BDDFDEC7B62FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x92FD8C2B6B1E35B9ULL + 0xFF4399B611A27431ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAA70027BCBE83CF1ULL + 0xCE7686172B321E51ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE30751DA1F9D465BULL + 0xC12F90F88EF2F7A0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF139D1BCB91394DBULL + 0xBCD54678D490A5EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x81AA16EE511782AFULL + 0x80CC2D16D27D8318ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC7BE1FA0EB6C02D1ULL + 0xAD0415D9B6EFF8E0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD49E27A66556A379ULL + 0xDACBD431ED6C1581ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE8E29232398D370BULL + 0xA0D53586CB4A6560ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x84A7E7B1A34133BFULL + 0xA87B9EC26AE7B712ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC262930F2B82D1D7ULL + 0xB7DE0A91009014C2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9BDEFA0413D90B2FULL + 0xC00018774DB3683EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE6396D96A80523E7ULL + 0xE492AFA2514F9664ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA945CAB8150ECB41ULL + 0x926AE6A3DD3AE37AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB1B94D73638A90C9ULL + 0xA96D753687116F74ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAD7DF285731FB179ULL + 0xFF574A84B47E7040ULL);
    // GSeedRunSeed_D seed_loop_d (start)
    {
        // GSeedRunSeed_D seed_loop_d lane group
        // read from: aExpandLaneA, aExpandLaneB, aInvestLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneB, aSnowLaneA, aInvestLaneC, aInvestLaneD, aSnowLaneB, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD
        // write to: aSnowLaneA, aSnowLaneB, aInvestLaneA, aInvestLaneB, aInvestLaneC, aInvestLaneD
    
        // seed_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aInvestLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2172U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 171U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 385U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2381U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2044U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 1951U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 28U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererC + RotL64(aCross, 5U)) + 12615321415808640429U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 15712784676459931207U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 11013335427004930046U) + aNonceWordG;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 26U)) + 8298733856304768806U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 6207732959150824216U) + aPhaseDOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 43U)) + 9769864876127544038U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 19U)) + 10782181918651152563U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5790454015845620939U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15606578025386733803U;
            aOrbiterE = RotL64((aOrbiterE * 7079287329365566355U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5522352539991175304U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5993355818572869649U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 15221467311057431139U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10864534396947622047U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12090053126235913528U;
            aOrbiterH = RotL64((aOrbiterH * 7250801471645972261U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14191181677234981396U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2258570108233924592U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8307541155393855209U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8448114811381534603U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2702389315763499817U;
            aOrbiterG = RotL64((aOrbiterG * 6710443836432274393U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17202184076718780200U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 150549910056015002U;
            aOrbiterK = RotL64((aOrbiterK * 195034681254956335U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4910512055808124967U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 4783477997418403079U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 861977492146512865U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 58U));
            aWandererF = aWandererF + (((RotL64(aCross, 10U) + aOrbiterJ) + RotL64(aOrbiterG, 23U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + aNonceWordM) + aPhaseDWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + aNonceWordC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterB, 37U));
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // ingress from: aSnowLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aInvestLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8151U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 7848U)) & S_BLOCK1], 42U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 5804U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 6095U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8959U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7045U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 6497U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 60U)) + 4848316479321533394U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 13U)) + 6919360256662636195U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 53U)) + 9897013582181108544U) + aNonceWordJ;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 7319353809896158678U) + aNonceWordI;
            aOrbiterG = (aWandererC + RotL64(aScatter, 37U)) + 2848175435514849859U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 6967780718720437934U) + aPhaseDOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 10143884766603388136U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8675965006150972051U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16350117755560994281U;
            aOrbiterJ = RotL64((aOrbiterJ * 15072308930382994425U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17976597517118423760U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1399631141355370237U;
            aOrbiterG = RotL64((aOrbiterG * 16537788276543236833U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 3590613762034716792U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 5134624314245932157U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13077589037975283371U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10082236952942943654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4015535035905433450U;
            aOrbiterH = RotL64((aOrbiterH * 4961808568701908559U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 611474103801573800U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5786708483794098001U;
            aOrbiterB = RotL64((aOrbiterB * 7694007039340089267U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5201943497363274455U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 9282160506938328489U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 5368182164239021367U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4932320527498940158U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11576526341731392916U;
            aOrbiterF = RotL64((aOrbiterF * 1712051774729439363U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 21U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterD, 14U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // ingress from: aSnowLaneB, aExpandLaneA, aFireLaneA
        // ingress directions: aSnowLaneB forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneA, aExpandLaneC
        // cross directions: aSnowLaneA backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15628U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 15046U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16145U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14674U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 16251U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererB + RotL64(aScatter, 51U)) + 14624277139785904404U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 6966977309498165611U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 57U)) + 205536824352530761U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 16629575265808255692U) + aNonceWordB;
            aOrbiterG = (aWandererI + RotL64(aIngress, 40U)) + 596881340147972746U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 5U)) + 11944412799107412650U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 4615021315668210206U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 8497630055977606216U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11131601107309336885U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 18028349768453554935U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5935883479805510099U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15629346719765798174U;
            aOrbiterE = RotL64((aOrbiterE * 8535523790685945275U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5279128339113651273U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16778365912440331821U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 705421028266789241U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16003052937645491524U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6723226158737614764U;
            aOrbiterF = RotL64((aOrbiterF * 16690657664909260573U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9785784358981219543U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10055457337292292710U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 17919129940751761111U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11779163108592974175U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1177999477942202687U;
            aOrbiterH = RotL64((aOrbiterH * 13475069421684114643U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9190694445141492214U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15605342360346353457U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14547769706392595647U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 24U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // ingress from: aInvestLaneA, aSnowLaneA, aFireLaneB
        // ingress directions: aInvestLaneA forward forced, aSnowLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneB, aExpandLaneD
        // cross directions: aSnowLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17364U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneA[((aIndex + 16977U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17374U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19357U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 17646U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 3550722402315312207U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 13U)) + 16724184551669522754U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 43U)) + 981751330116773021U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 57U)) + 7891159229704944868U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 23U)) + 13618396711464799841U) + aNonceWordC;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 57U)) + 5969291018449003648U;
            aOrbiterA = ((((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 14595540413313640042U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3287990436916111762U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12534369400200483704U;
            aOrbiterD = RotL64((aOrbiterD * 2345945228434740707U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2277312067930392274U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10026320559261334353U;
            aOrbiterK = RotL64((aOrbiterK * 11020464940995912637U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11258082063135659551U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1445958517675746990U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10062265337488757971U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1011298251290970844U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6487834862470043744U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15477913837027179675U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9966279022928268335U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10285993486057704393U;
            aOrbiterH = RotL64((aOrbiterH * 15965714363201157535U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16005362468813966136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 223843444699390781U;
            aOrbiterB = RotL64((aOrbiterB * 665392038954573081U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 18178876294968532775U) + aNonceWordP;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 12490136112181806806U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 16380841616662993709U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + aNonceWordH) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterB, 36U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 5
        // ingress from: aInvestLaneB, aSnowLaneB, aFireLaneC
        // ingress directions: aInvestLaneB forward forced, aSnowLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneA, aSnowLaneA
        // cross directions: aInvestLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23853U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneB[((aIndex + 24408U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22736U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22240U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 24759U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 44U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 11U)) + 9023059520606551446U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 662441755115638133U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 30U)) + RotL64(aCarry, 53U)) + 16957253361196144712U) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 37U)) + 7840955025765308605U) + aPhaseDOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 19U)) + 346855809270395799U) + aNonceWordA;
            aOrbiterC = ((aWandererH + RotL64(aCross, 57U)) + 16099139781586668343U) + aPhaseDOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 3706457327118322098U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12166825885547622870U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7792658665720344200U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16305542632794270697U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7128477606152986326U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11116533962780290084U;
            aOrbiterD = RotL64((aOrbiterD * 11993485572912492297U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10443889548568288532U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4402387036946561017U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 9032964741841833277U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13002706161178447654U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 13929727277530310708U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7005639090871200285U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10949073760696935106U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15405923432006783533U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17989565878445202495U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 18096057968822208905U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3032155040484574973U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 448597307502544605U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17462076466907467134U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15471015427013701406U;
            aOrbiterB = RotL64((aOrbiterB * 6113474000571976139U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aCross, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordD) + aPhaseDWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterD, 4U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + aNonceWordO) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 54U) + aOrbiterJ) + RotL64(aOrbiterA, 27U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 6
        // ingress from: aInvestLaneC, aInvestLaneA, aFireLaneD
        // ingress directions: aInvestLaneC forward forced, aInvestLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneB
        // cross directions: aInvestLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31846U)) & S_BLOCK1], 24U) ^ RotL64(aInvestLaneA[((aIndex + 28612U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29392U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31774U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 29864U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (((aWandererC + RotL64(aCross, 51U)) + 16183871922837164759U) + aPhaseDOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 21U)) + 7002058258090219055U) + aNonceWordM;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 5650868611888303705U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 10U)) + RotL64(aCarry, 21U)) + 11899839660943876690U) + aNonceWordC;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 15349649504488111111U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 3U)) + 14060149569086744970U) + aNonceWordJ;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 41U)) + 12920917574225030112U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2831994965175330135U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18312543585028439192U;
            aOrbiterD = RotL64((aOrbiterD * 11618182708195744321U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11657562205118394239U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10850792819281246052U;
            aOrbiterG = RotL64((aOrbiterG * 10663100544207879337U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17810371216216125323U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7963413941144223128U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 534217972450595401U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5498715358793875584U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9256727548911651373U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 10498848323914000989U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17246360111302191699U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 18309978718113983369U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18267472694666221077U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3100998994319502921U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8129301860291235970U;
            aOrbiterI = RotL64((aOrbiterI * 17847033539279176187U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1889641029473279114U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16538494307002917945U;
            aOrbiterA = RotL64((aOrbiterA * 8081488217920885783U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aNonceWordH);
            aWandererK = aWandererK + (((((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 57U)) + aNonceWordK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 44U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB1049D2258A30049ULL + 0xA645C53E596965ABULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDFA259FF91022CB3ULL + 0xF150405A1FFB95C0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x82816BBB229DB47BULL + 0x88DB4F675F14440BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x91664E1C808EF34BULL + 0x941870CF22376D1EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC2594339A0D7F4B7ULL + 0xBC3DF0DEE6A5536BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8BABCCD569E99B8FULL + 0xFCEF5E47302C6636ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAE5E2FDFBAE42201ULL + 0x92F89A1D77C0949EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE1F53E4D4753F929ULL + 0xA1C70B04F45AFDDCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x823EEB0D1FC48DFBULL + 0xF0D5F794781F089BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB9D14BB03CBFCD81ULL + 0xF45412B4C9EBC8B6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB8BCD9628BD5249BULL + 0xA52A0611242D96E6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCF20CADD35788D05ULL + 0x892A37C58AF80A39ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA11D9603FDA58A99ULL + 0xF5069644375E7813ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCE84D07CE0394B6DULL + 0xC17E7825D9A3A42AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFB87E724FAC8DD09ULL + 0xF6257AAE77CC79BBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCB89858227CD30FFULL + 0xC555A6AF3904875FULL);
    // GSeedRunSeed_E seed_loop_e (start)
    {
        // GSeedRunSeed_E seed_loop_e lane group
        // read from: aInvestLaneA, aInvestLaneB, aFireLaneA, aInvestLaneC, aInvestLaneD, aFireLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aOperationLaneA, aWorkLaneD, aOperationLaneB, aFireLaneC, aOperationLaneC, aFireLaneD
        // write to: aFireLaneA, aFireLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_e loop 1
        // ingress from: aInvestLaneA, aInvestLaneB, aFireLaneA
        // ingress directions: aInvestLaneA forward forced, aInvestLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aInvestLaneD, aFireLaneB
        // cross directions: aInvestLaneC backward forced, aInvestLaneD backward forced, aFireLaneB backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 1321U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((aIndex + 118U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1160U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4166U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1337U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1838U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 19U)) + 10812151398716051703U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 18202551453336003710U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 21U)) + 9434410809101973752U) + aNonceWordD;
            aOrbiterG = ((aWandererC + RotL64(aCross, 10U)) + 12955829998028534045U) + aNonceWordN;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 23U)) + 12271740641929640181U) + aNonceWordB;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 57U)) + 14009351527014534752U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 4316296955679133450U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 16473324966997442872U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 41U)) + 15735123324965019802U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 43U)) + 17656375090484080236U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 34U)) + 16066325053456055298U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12908968778503516903U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12761433987676836197U;
            aOrbiterA = RotL64((aOrbiterA * 1023329467480907925U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12737513138040664509U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14535795767570998392U;
            aOrbiterK = RotL64((aOrbiterK * 15560519667062222269U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14370908061811284364U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7001358781208669795U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11641248025734015835U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7298578161120090849U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10498302152357484629U;
            aOrbiterE = RotL64((aOrbiterE * 13144110412179037175U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11447343228638006767U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18284143620422655675U;
            aOrbiterD = RotL64((aOrbiterD * 572862190073605651U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5918253208127360199U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3910541329178205943U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4550654545328228103U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10357053096941367910U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5610891501128498748U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 8676370811772047449U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9049881176058575811U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6307599924966452216U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 5551444450572055895U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17109966783467892046U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11563095828344462249U;
            aOrbiterC = RotL64((aOrbiterC * 15463753739272001875U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3739147427725509014U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5324449517615050698U;
            aOrbiterH = RotL64((aOrbiterH * 5926079615575226853U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5706251076252597592U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10812151398716051703U;
            aOrbiterB = RotL64((aOrbiterB * 5666491216813197045U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 28U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG + ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterC, 10U)) + aNonceWordM);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterE, 35U)) + aNonceWordP) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 22U) + aOrbiterA) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 20U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 2
        // ingress from: aFireLaneA, aInvestLaneC, aInvestLaneD, aWorkLaneA
        // ingress directions: aFireLaneA forward forced, aInvestLaneC forward forced, aInvestLaneD forward forced, aWorkLaneA forward/backward random
        // cross from: aInvestLaneA, aInvestLaneB, aWorkLaneB
        // cross directions: aInvestLaneA backward forced, aInvestLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 8875U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 9579U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 6498U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 10882U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9240U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9997U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 8791U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 10U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 2558105147674438050U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 14U)) + RotL64(aCarry, 5U)) + 15856662514774702561U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 51U)) + 13346869226246584582U) + aNonceWordB;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + 7632111846116243973U) + aNonceWordP;
            aOrbiterH = (aWandererH + RotL64(aScatter, 19U)) + 2102101361626976279U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 57U)) + 5605968705067851563U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 4U)) + 6842483186584326681U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 27U)) + 5559797213819425064U) + aPhaseEOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 39U)) + 12422313931331576759U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 2751024420047872601U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 47U)) + 11031320239359798610U) + aPhaseEOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 14366375309473793217U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11971479429768505316U;
            aOrbiterE = RotL64((aOrbiterE * 10063001532313098203U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3947595951884469542U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17882767922372770896U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3361906348965810211U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 513871456983509223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5951677013597794294U;
            aOrbiterI = RotL64((aOrbiterI * 8508629569649935293U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 437626309049021931U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 466674061172005705U;
            aOrbiterB = RotL64((aOrbiterB * 1310502572084891157U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12362602809233133718U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10525852878882195702U;
            aOrbiterK = RotL64((aOrbiterK * 17755022180514914325U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17927000184308583095U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 566723721423470052U;
            aOrbiterH = RotL64((aOrbiterH * 17710534355278632573U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9504585484034413577U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4614306037721859929U;
            aOrbiterC = RotL64((aOrbiterC * 170807293799483539U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1463218357720031588U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4036696102163560633U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 15389914226155130065U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9907678911300898726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11804311892289601322U;
            aOrbiterJ = RotL64((aOrbiterJ * 13986106774841242253U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6514645538508331396U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17246364354815744899U;
            aOrbiterG = RotL64((aOrbiterG * 12800661037742526999U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6725706155285333764U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2558105147674438050U;
            aOrbiterD = RotL64((aOrbiterD * 6752457079901154727U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 4U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + aNonceWordK);
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 46U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterC, 39U)) + aNonceWordI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterF) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterC, 5U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterK, 53U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 42U) + aOrbiterE) + RotL64(aOrbiterC, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 30U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 3
        // ingress from: aFireLaneB, aInvestLaneA, aWorkLaneC
        // ingress directions: aFireLaneB forward forced, aInvestLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aFireLaneA, aInvestLaneC
        // cross directions: aFireLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 14120U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 13041U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 13313U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12725U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12768U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 14686411261024919129U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 3U)) + 7514582233957632005U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 51U)) + 6520710480103365552U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 5U)) + 1983621978676188036U) + aNonceWordE;
            aOrbiterD = (aWandererA + RotL64(aScatter, 41U)) + 9003524602590749672U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 12U)) + RotL64(aCarry, 19U)) + 6428568234045228995U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 8656552687136446989U;
            aOrbiterE = (aWandererK + RotL64(aCross, 35U)) + 16916248288415922490U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 57U)) + 9740237548002535784U;
            aOrbiterA = (aWandererD + RotL64(aCross, 39U)) + 907561000814618339U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 54U)) + 4751108900841197631U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 167774899400732287U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11907484918310854962U;
            aOrbiterK = RotL64((aOrbiterK * 7213139491146402985U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14910318613649863924U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14882888155751455276U;
            aOrbiterD = RotL64((aOrbiterD * 11394136445442060201U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16175942562693781908U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11022373758481651102U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6836331461393816027U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 12548405399045031548U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10850926364556828443U;
            aOrbiterB = RotL64((aOrbiterB * 16231561687709867431U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13391684887911141790U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14648937281264822988U;
            aOrbiterG = RotL64((aOrbiterG * 6533299316940026059U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8298658887198526821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13822977698661348891U;
            aOrbiterA = RotL64((aOrbiterA * 17769262972278410937U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7505646847564645719U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3238749538197209166U;
            aOrbiterJ = RotL64((aOrbiterJ * 15394286542600778567U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15853506915123709257U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8426329899401071248U;
            aOrbiterH = RotL64((aOrbiterH * 1330397096577715113U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14848635392815613098U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3549927798350175044U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 1899044682313056949U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1798973117197750802U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13056711228618953977U;
            aOrbiterF = RotL64((aOrbiterF * 9102877396419306689U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1395893547965799281U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14686411261024919129U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 17075377081365066067U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 18U)) + aOrbiterD) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterA, 39U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + aNonceWordC);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 28U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 30U)) + aOrbiterB) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 4
        // ingress from: aOperationLaneA, aFireLaneA, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aFireLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aFireLaneB, aInvestLaneD
        // cross directions: aFireLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19903U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((aIndex + 21288U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17828U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20056U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneD[((aIndex + 17819U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 12980104182836602177U) + aNonceWordN;
            aOrbiterB = (aWandererC + RotL64(aCross, 57U)) + 3172622203188863995U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 39U)) + 1170974132219980203U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 10U)) + 6035201940965047490U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 23U)) + 18033907118424996722U;
            aOrbiterA = (aWandererE + RotL64(aCross, 41U)) + 14604813424800580304U;
            aOrbiterJ = ((((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 13720232492851066035U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 3902659710585257448U;
            aOrbiterE = (aWandererH + RotL64(aCross, 3U)) + 8331560652661619868U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 60U)) + 4485014147538689794U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererK + RotL64(aScatter, 35U)) + 168202636924512424U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16227825670092707848U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4792781933944671365U;
            aOrbiterC = RotL64((aOrbiterC * 15859849676231455283U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12636865372722601282U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 18198291399585556632U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18155803890313399795U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3650053185419807206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5897288963905408776U;
            aOrbiterH = RotL64((aOrbiterH * 3706949366974086151U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9922308113622901726U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13352279749091561510U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4025213180483632557U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14969461950939646117U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10231661776135056651U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 11284575051455238501U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10621934544068320859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6029116920305246887U;
            aOrbiterG = RotL64((aOrbiterG * 6087523725059376905U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12887482425168671195U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8351351557123783853U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3839381627914762245U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5405938210926464973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 385145802287899406U;
            aOrbiterD = RotL64((aOrbiterD * 8330751480464271445U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7907749190875916461U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5138733192253468642U;
            aOrbiterA = RotL64((aOrbiterA * 17028325976353263843U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14382272868178763187U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14354777100157531233U;
            aOrbiterE = RotL64((aOrbiterE * 7095764230272037767U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4390647647193363824U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12980104182836602177U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 11124472075872147333U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 48U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 24U) + RotL64(aOrbiterD, 14U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + aNonceWordE);
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 21U)) + aOrbiterH) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 6U) + RotL64(aOrbiterF, 24U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterG, 39U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 37U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 5
        // ingress from: aOperationLaneB, aFireLaneB, aFireLaneC
        // ingress directions: aOperationLaneB forward forced, aFireLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aFireLaneA, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aFireLaneA backward forced, aInvestLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24422U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 25719U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27003U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26643U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26847U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23527U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 56U)) ^ (RotL64(aPrevious, 43U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 6068543441070417854U;
            aOrbiterC = (aWandererI + RotL64(aCross, 19U)) + 2995980468193441856U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 27U)) + 18020277482171594003U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 4293807434721230702U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 56U)) + 7980599111583893156U) + aPhaseEOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 53U)) + 8593141111851052016U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 41U)) + 5903487523900084325U) + aNonceWordM;
            aOrbiterF = ((aWandererD + RotL64(aCross, 35U)) + 15112035513447930209U) + aNonceWordO;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 43U)) + 9854037263057006439U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 24U)) + RotL64(aCarry, 27U)) + 16759760289688823193U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 47U)) + 12622628933030601390U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1264668857268123425U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16302812053619101593U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18291400055836111547U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16087995784896123610U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7970269262800468363U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 14924752223305807461U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5331477046030959632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16534913204255550893U;
            aOrbiterI = RotL64((aOrbiterI * 1013433634373673565U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11042821902537871209U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8069677512345031660U;
            aOrbiterG = RotL64((aOrbiterG * 13622218526054132397U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5737130058129936372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1076627182956662997U;
            aOrbiterB = RotL64((aOrbiterB * 14342191224014199929U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13911061091801078190U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15397603151098990373U;
            aOrbiterC = RotL64((aOrbiterC * 1802890451633592245U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15137326716738637972U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11248737008959896786U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 90789374131547005U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1847847987633923657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10560748778679145431U;
            aOrbiterA = RotL64((aOrbiterA * 2919333327817231099U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2703726238610290251U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12950671360471467310U;
            aOrbiterD = RotL64((aOrbiterD * 7490327691501537047U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10331504168520449467U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1541527607705280906U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14197400812600186171U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9135056476214341809U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6068543441070417854U;
            aOrbiterF = RotL64((aOrbiterF * 14102524444094948875U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 54U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterD, 21U)) + aNonceWordE) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 57U));
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 18U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aNonceWordJ) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterB, 36U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererB, 36U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 6
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28244U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 31251U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 28194U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31180U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((aIndex + 32198U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (aWandererJ + RotL64(aCross, 20U)) + 5960680319644404115U;
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 16050752633567034185U) + aPhaseEOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aWandererC + RotL64(aIngress, 11U)) + 8447503223226854741U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 41U)) + 14176813813397917591U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 43U)) + 10534915376130006644U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 6866224454375302514U;
            aOrbiterH = ((((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 16506374165041008396U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererG + RotL64(aCross, 47U)) + 7167814023968794098U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 58U)) + 13870852197416596664U) + aNonceWordG;
            aOrbiterB = (aWandererI + RotL64(aCross, 27U)) + 18064038854848993105U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 13U)) + 9869630811507771691U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 863613100452759380U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16597969741225436529U;
            aOrbiterK = RotL64((aOrbiterK * 2680793528887208903U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6575347108051310653U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17062262265485019063U;
            aOrbiterF = RotL64((aOrbiterF * 7601045488473620019U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7193399224636409133U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 14146747818810433849U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 5273185769989530041U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9441449106442431427U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4303295336545399503U;
            aOrbiterH = RotL64((aOrbiterH * 8829695296836242587U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12604760768543193458U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 15779327512379787715U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14000905201441272597U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15553000781122708728U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17162740616060079717U;
            aOrbiterE = RotL64((aOrbiterE * 9458662233556750239U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1032374679817715156U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16413393156165548232U;
            aOrbiterC = RotL64((aOrbiterC * 549659738811935015U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 14056855000013992045U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7399202019042538829U;
            aOrbiterA = RotL64((aOrbiterA * 6103508549612077695U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2218389473339103389U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4679497280975967770U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9228353578259815023U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7620538119914173747U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3118355627808424159U;
            aOrbiterJ = RotL64((aOrbiterJ * 12481319980496032783U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16787092219237931175U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5960680319644404115U;
            aOrbiterI = RotL64((aOrbiterI * 10727217147056112401U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 54U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + aNonceWordF);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterH, 37U)) + aNonceWordK) + aPhaseEWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB + (((RotL64(aScatter, 46U) + RotL64(aOrbiterF, 20U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC850268EB3D33ADBULL + 0x8C2E5F6254876F56ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8CA063D41FB8E611ULL + 0xFCCD0B0E0AE8CD27ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB4734C7FC23BA8D7ULL + 0xEF937EFFCDAE789CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD5396DA8BA8F68D9ULL + 0xABE0D8650114E32DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF76A5F1D048A3491ULL + 0x90C4D1557559DFCAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA0259D23C590669DULL + 0xB1F1198533BBF283ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBAE479966B325081ULL + 0xECCF4DA00193B687ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE8844D995D71F0F9ULL + 0xEDB21DEAA429EE9FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x80709571F5F0BE99ULL + 0x8AA253ECB8DB6AC1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDEA1ED66AC0A7F6FULL + 0xD150B9B06B81811FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE969B6927CA23AE3ULL + 0x913A3D0E10A23678ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFAF5463EBA1C5F5BULL + 0x98CC0A0D38BA3330ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC3646735943797EBULL + 0xA469A9A8D6C99687ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC400687C972814D5ULL + 0xD6259889F8E2F64CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8127E0CE494FCB33ULL + 0xAA87A97954B2E1A4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB8336D87E70CF65FULL + 0x9A77CFE9977FDC4DULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneC, aSnowLaneC, aSnowLaneA, aInvestLaneC, aSnowLaneD, aInvestLaneA, aExpandLaneA, aWorkLaneD, aExpandLaneB, aInvestLaneB, aExpandLaneC, aSnowLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5149U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 3863U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4672U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 626U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1687U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3167U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 38U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 5U)) + 5573188770530340913U) + aNonceWordH;
            aOrbiterG = (aWandererI + RotL64(aCross, 53U)) + 1431772230889897111U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 4809192776429682319U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 14U)) + RotL64(aCarry, 27U)) + 5576603692574369341U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 57U)) + 2720143226007220386U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 17220328778565331629U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 19U)) + 9629485808442089423U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 34U)) + 1136998437010390983U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aWandererK + RotL64(aCross, 43U)) + 11893390497814523841U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1764986431917532370U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1741014798007010376U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13414914086049500731U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12221368453236547044U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7694538641172350430U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8439120733670016501U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17472344518811560603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3308740700728172984U;
            aOrbiterE = RotL64((aOrbiterE * 15290400462887712083U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9535358833412446771U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11192312491731312451U;
            aOrbiterH = RotL64((aOrbiterH * 17405609148475445743U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14850451970047190039U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11932493299452443256U;
            aOrbiterB = RotL64((aOrbiterB * 7964808728820467795U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5972619895614731870U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17174497535809891690U;
            aOrbiterA = RotL64((aOrbiterA * 15471084511364572533U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17412894714378898351U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14675615208706549810U;
            aOrbiterC = RotL64((aOrbiterC * 7864845089606499769U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16116792108013658523U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9702262005960966336U;
            aOrbiterK = RotL64((aOrbiterK * 970452849653781703U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17337264966818542841U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7004462033775827275U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 11943575980344402681U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterC, 23U)) + aNonceWordJ);
            aWandererI = aWandererI + ((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 6U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 29U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 14U) + aOrbiterC) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterH, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aSnowLaneA
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9209U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 7229U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6021U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8759U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9008U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9077U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 9522U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 20U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererH + RotL64(aScatter, 3U)) + 2177539223979303669U) + aNonceWordO;
            aOrbiterA = (aWandererI + RotL64(aIngress, 35U)) + 3962004686551521471U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 8457602312617147662U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 51U)) + 18011802451816510632U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 18U)) + 9046101759168876832U) + aNonceWordC;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 11135620637431969597U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 39U)) + 15913029940697999701U;
            aOrbiterD = (aWandererA + RotL64(aCross, 27U)) + 16304193109948135982U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 44U)) + RotL64(aCarry, 3U)) + 13208892298820080981U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4182377898949419225U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13970137023071326151U;
            aOrbiterK = RotL64((aOrbiterK * 9075061559681739865U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 8402396284835248583U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8859190834060657829U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 13552418608113716117U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9760005337757990392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14108277760135744897U;
            aOrbiterB = RotL64((aOrbiterB * 4474681104256093885U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12226316121949012350U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3456392186754113960U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8704729827929941215U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5004087958637038973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7176881295123125567U;
            aOrbiterE = RotL64((aOrbiterE * 15272157962928021009U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10889800478505074438U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13728832441482547824U;
            aOrbiterF = RotL64((aOrbiterF * 17588477761978646139U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17345665880706866772U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 301139993853297566U;
            aOrbiterD = RotL64((aOrbiterD * 5812445396758354505U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2061389844760610160U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13631862266139238355U;
            aOrbiterI = RotL64((aOrbiterI * 143613352104722701U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10767186080827509622U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4893486019456886013U;
            aOrbiterA = RotL64((aOrbiterA * 5194746459545610901U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterC, 43U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 18U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 52U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + aNonceWordK);
            aWandererH = aWandererH + (((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordL) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 12U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterA, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 16049U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 12956U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15415U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 13196U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13803U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 51U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 53U)) + 2617613537256538553U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 46U)) + 16642868916835132715U) + aNonceWordN;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 29U)) + 10860291124337073254U) + aNonceWordH;
            aOrbiterH = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 6432511273906902472U) + aNonceWordA;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 7505375005848241910U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 24U)) + 11086616004678821329U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 13U)) + 3298830587569881951U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 3U)) + 9775143140064220979U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 4147601326580823120U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12245920269898100415U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8391940489176734499U;
            aOrbiterD = RotL64((aOrbiterD * 9119606167674098007U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17876893379544668477U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 18301882058180370541U;
            aOrbiterC = RotL64((aOrbiterC * 16680384667098921309U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6869225862715140102U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15404118372589259800U;
            aOrbiterE = RotL64((aOrbiterE * 5766851935950389915U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 17757381020518233814U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17677969146092374455U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 3469432916562405063U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15783378556632870114U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5792858258663697864U;
            aOrbiterF = RotL64((aOrbiterF * 12008981883482080427U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11737803388202260296U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16001927091970715330U;
            aOrbiterA = RotL64((aOrbiterA * 3062030309852922061U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1749586939123286632U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6169421068855905938U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12374789910763348695U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10073586820719728062U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17744171227198661555U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 10658375268803957647U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1149819647337612792U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7725598665625892006U;
            aOrbiterK = RotL64((aOrbiterK * 15097586655234391559U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 20U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 26U) + aOrbiterJ) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 14U)) + aOrbiterH) + aNonceWordF) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aNonceWordO) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterI, 35U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 10U)) + aOrbiterC) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aWorkLaneD
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19101U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneC[((aIndex + 17158U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20777U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 16967U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 17349U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 50U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (aWandererH + RotL64(aCross, 23U)) + 2571116506511057880U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 51U)) + 13112435411509707292U) + aNonceWordD;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 10403251762787357256U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 40U)) + 8461951095541400405U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 47U)) + 9890793478557463815U) + aPhaseFOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 3U)) + 3030229465991783707U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 35U)) + 7273848154043719247U) + aNonceWordA;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 14U)) + RotL64(aCarry, 19U)) + 10681774862516028276U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 7105082755586853104U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6588579345319551129U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14616333550242386092U;
            aOrbiterC = RotL64((aOrbiterC * 2934574715879306337U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15439666290229654921U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3360304356760164799U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 5164191920584106237U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14438730801970761889U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 14515616787452085729U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 2041601927968559821U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4167853822635132419U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8950982233003320239U;
            aOrbiterI = RotL64((aOrbiterI * 887144270884244907U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12391327853728029953U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7100871010552394421U;
            aOrbiterF = RotL64((aOrbiterF * 16552349374101955967U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15381697462381887944U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6801677551341079401U;
            aOrbiterA = RotL64((aOrbiterA * 13325954438427340703U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 947011315719204867U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6356920162398333481U;
            aOrbiterG = RotL64((aOrbiterG * 5566721941682667419U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8910262020598577378U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8778455415977526457U;
            aOrbiterK = RotL64((aOrbiterK * 4092470497616637283U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5585696961453127223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9670655481681494412U;
            aOrbiterJ = RotL64((aOrbiterJ * 7863197168965036383U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterF, 18U)) + aOrbiterE) + aNonceWordO);
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG + ((((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + aNonceWordG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 12U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneB
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22532U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 25816U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 25664U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24640U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 24106U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 39U)) + 8866844335448071821U) + aNonceWordI;
            aOrbiterC = (aWandererC + RotL64(aIngress, 5U)) + 15159698739856430085U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 19U)) + 9582805772989594633U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 60U)) + 1438538239931588373U) + aNonceWordH;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 35U)) + 10862044156620436139U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 13682173320058164615U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 8351013291045977592U) + aNonceWordG;
            aOrbiterE = (aWandererI + RotL64(aIngress, 43U)) + 15777857431516633916U;
            aOrbiterH = ((((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 3U)) + 16178966745333885377U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9031889187993001617U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6308472367425865347U;
            aOrbiterF = RotL64((aOrbiterF * 17118710301967158153U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 642109145903321046U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9186268569255318035U;
            aOrbiterC = RotL64((aOrbiterC * 10714674348507516749U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6091345356803675860U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13218507921880873749U;
            aOrbiterB = RotL64((aOrbiterB * 15415157927185637717U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4266652275234474616U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4391422098164506195U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 17634679403195085867U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5160682323243635577U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10351728852161347404U;
            aOrbiterJ = RotL64((aOrbiterJ * 11105410036471745951U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3950932176454814023U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9536466386833427441U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18064984243491293435U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9927425919978776529U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6819384090527481081U;
            aOrbiterE = RotL64((aOrbiterE * 18032965969184368561U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1646274931424218507U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16166524473976135097U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 11672192658072663849U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11252501968059485262U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16847854447987609067U;
            aOrbiterH = RotL64((aOrbiterH * 6326299154627028295U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 58U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + ((((RotL64(aCross, 39U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterI, 58U));
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterC) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterH, 46U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aSnowLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aSnowLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28699U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 31121U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 29177U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28948U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 29460U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 44U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 8793908991006073956U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 58U)) + 2932916283348441943U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 11069042087940968262U) + aNonceWordI;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 14369628676782894441U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 51U)) + 8602903272780978282U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 42U)) + 3827036107178568820U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 35U)) + 8905245209036772489U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 23U)) + 13331387530760017893U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 11U)) + 9880107580289737823U) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10199619040626900278U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2466307560891374281U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 6295342978834217571U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13973403407981259448U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2851460278409385243U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11226902976321781743U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10365453393815690776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2382382358987358791U;
            aOrbiterI = RotL64((aOrbiterI * 481563628980705781U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5058198848163792422U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10500434740387593487U;
            aOrbiterG = RotL64((aOrbiterG * 5946747708776079787U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11289798395177667084U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14327152153231286666U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 18155778059595245561U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8065137263811956313U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3865153574847924816U;
            aOrbiterF = RotL64((aOrbiterF * 9495741102667755161U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 18102279969722473375U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6306428427188742325U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17826782872351406167U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16953348204663693724U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11950791817032898613U;
            aOrbiterE = RotL64((aOrbiterE * 1498946055469611133U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11980823193543752994U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17845490308799454871U;
            aOrbiterA = RotL64((aOrbiterA * 16385153013485463791U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 20U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 56U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 29U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterE) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 38U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9C635DB9592E307BULL + 0x8DFACA1B25618727ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9BC4F9D9E6F1A127ULL + 0x8AAEF12237C18204ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x874A0EC1551F8371ULL + 0xFC733F793CE0EF23ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE43C7B7AA3D874F5ULL + 0xC6510AE8F7DB5BF0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE52199E2802AA1F1ULL + 0xC9F0DDFA7FE93FAAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC32F31741BA78465ULL + 0xEF7DA47F71F0A92DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA69667F3570C7D59ULL + 0xAE5CE1F8DD371B15ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE544599CE73808EFULL + 0xB002D37D8F132A78ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB2C37D5FD6F0A1D7ULL + 0xDAB18775B70DE28EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9F2EBAF694849F2DULL + 0xCC972E09E1186BC5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC421BC8FD1DE4B9FULL + 0xF6EB221EE5B7F977ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9ABF1D34E4B0DE69ULL + 0x800C54DD915D43FDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x857ACB27F7EF338BULL + 0x9834DA3C39A4FCA8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8C2176BB21283CFBULL + 0x942CF65F938EF11EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF5BAAA3710FE0D29ULL + 0xAC8941AE91152A6BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x84F8543DB9D30D67ULL + 0x96A63BF23CDD6AD7ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneB, aSnowLaneC, aSnowLaneD, aFireLaneD, aWorkLaneA, aInvestLaneD, aFireLaneC, aWorkLaneB, aInvestLaneA, aExpandLaneA, aFireLaneB, aExpandLaneB, aFireLaneA, aExpandLaneC, aInvestLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5127U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 778U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 2374U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 214U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 5392U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1024U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 10U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 57U)) + 11521331427196538632U) + aNonceWordH;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 41U)) + 16653824187682957632U) + aPhaseHOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 28U)) + RotL64(aCarry, 11U)) + 11654676587350088289U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 8010313317412193584U) + aPhaseHOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 51U)) + 1108775560502907471U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 13U)) + 243952321439823521U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 2324945800401240403U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 9257554497543369657U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16701314607244592540U;
            aOrbiterH = RotL64((aOrbiterH * 8790054741039817107U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3900445848034341782U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7652316487347103658U;
            aOrbiterJ = RotL64((aOrbiterJ * 11480123491361589799U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14980368605272070578U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2001165460948764796U;
            aOrbiterB = RotL64((aOrbiterB * 8110980921827107649U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1911044015666991050U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 11366207111147818339U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 17234439040652553865U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16469329744002456607U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8062793687044950815U;
            aOrbiterI = RotL64((aOrbiterI * 5856142259851144369U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15364721421972807872U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8979915611483540231U;
            aOrbiterK = RotL64((aOrbiterK * 10899377466171153383U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7654234623563110457U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1526832460342135008U;
            aOrbiterD = RotL64((aOrbiterD * 12766083052650723051U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 36U);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 22U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterB, 35U)) + aPhaseHWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + aNonceWordK) + aPhaseHWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6390U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneC[((aIndex + 6213U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 8154U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 5470U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7960U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6269U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 6748U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 53U)) + (RotL64(aIngress, 34U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 17470880031634374199U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 3U)) + 757565846006937746U) + aNonceWordJ;
            aOrbiterG = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 9419282475801345674U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 11U)) + 2014248014107898196U;
            aOrbiterA = (aWandererA + RotL64(aCross, 26U)) + 15113928519446490441U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 37U)) + 7346126964886259935U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 5594123113093162359U) + aNonceWordD;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5659237263369402005U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11565709683423969703U;
            aOrbiterG = RotL64((aOrbiterG * 16731289017588574671U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16782863743534856287U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13499100900072115907U;
            aOrbiterA = RotL64((aOrbiterA * 5567729598873214433U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11414447651044205242U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7545993795121430538U;
            aOrbiterF = RotL64((aOrbiterF * 10758488381206257261U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11778229237616454988U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2544793391976514665U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4021060413798523299U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9972156716619459164U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17651030383827445664U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 6742914240706775487U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17439147296849134543U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 10021926927948343656U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 18139540407315440909U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9309867875882669289U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14951424455944346337U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10569523948169951309U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aNonceWordN) + aPhaseHWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 52U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 41U)) + aOrbiterC) + aNonceWordI);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + aNonceWordL) + aPhaseHWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13659U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneA[((aIndex + 15417U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 14242U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13622U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneC[((aIndex + 14533U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 50U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 57U)) + 1866656689936219099U) + aNonceWordO;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 2312314528139448289U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 3554037526469185237U) + aNonceWordD;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 405707755060974111U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 29U)) + 1862976326004007697U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 47U)) + 12992483065443288263U) + aPhaseHOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 12U)) + 3793854946371595197U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4244007978867369382U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10280867500312580308U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 13729899124177931289U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 472563452959164242U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12041770406895816553U;
            aOrbiterA = RotL64((aOrbiterA * 17811798500132002631U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6118634015704900486U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13637107920449233307U;
            aOrbiterK = RotL64((aOrbiterK * 17712028184714868053U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16673735670669318830U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8602681273646630496U;
            aOrbiterB = RotL64((aOrbiterB * 6995213887710749241U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 7683264695930369476U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9146674871199188218U;
            aOrbiterI = RotL64((aOrbiterI * 7403427067419261981U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 3012935612827493084U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1259789268731661945U;
            aOrbiterJ = RotL64((aOrbiterJ * 2372843620327050137U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5623690455471160780U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 18355567776031865462U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9553862670107886679U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 28U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + aNonceWordG) + aPhaseHWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterF, 54U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterB, 43U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterK, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19435U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 16423U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 18278U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17721U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17342U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 20U)) + (RotL64(aCarry, 47U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 47U)) + 16519040829220310189U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 6888002778416941825U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 1310832187746534025U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 20U)) + 5890888009051281674U) + aNonceWordE;
            aOrbiterA = ((((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 5143864838362464857U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererD + RotL64(aCross, 13U)) + 15591534069452660003U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 37U)) + 1466867671765325096U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13931443680107902488U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15400747367673245552U;
            aOrbiterK = RotL64((aOrbiterK * 7011651369456453127U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2836975369734495759U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2370720358274970117U;
            aOrbiterF = RotL64((aOrbiterF * 4615571902817575375U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3470677184188006133U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7175584278499266723U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10067096593682482345U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6095078817776863055U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2176637999243513070U;
            aOrbiterD = RotL64((aOrbiterD * 12215701810843975501U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 5580391239754903129U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15196125567953871184U;
            aOrbiterI = RotL64((aOrbiterI * 12686361960729564519U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12787014151503209931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1523153207064063495U;
            aOrbiterA = RotL64((aOrbiterA * 3113907543551927561U), 37U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 12973289026485937829U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9087439766232078173U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5817029335999350327U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterE, 41U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 4U)) + aOrbiterF) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 22U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24411U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 23455U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23265U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22382U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 23889U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 12583180859826261500U) + aNonceWordM;
            aOrbiterB = (aWandererF + RotL64(aScatter, 47U)) + 9067093488553721468U;
            aOrbiterE = (aWandererK + RotL64(aCross, 28U)) + 12173106198862881754U;
            aOrbiterJ = ((((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 11333491014394592654U) + aPhaseHOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 3511883526940919554U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 19U)) + 7416810692106273044U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 41U)) + 8341174972619784110U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2220852854836962979U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8090781422229383825U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 578293950675644397U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2338801236599102223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12484514711848308104U;
            aOrbiterG = RotL64((aOrbiterG * 10364216764253366067U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13684861340589131816U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12796636819991873058U;
            aOrbiterH = RotL64((aOrbiterH * 5533508014234835669U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7634198650894837690U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10240326122201201762U;
            aOrbiterJ = RotL64((aOrbiterJ * 8758703497719125901U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 4162814763739453934U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2766504649149048469U;
            aOrbiterB = RotL64((aOrbiterB * 16731843453895178671U), 41U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 11051393030148769655U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17687055068651386665U;
            aOrbiterA = RotL64((aOrbiterA * 1042927176246229537U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3353615315436983420U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5971640796220306310U;
            aOrbiterF = RotL64((aOrbiterF * 15804313508835034807U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + aPhaseHWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 56U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + aNonceWordN) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 12U) + RotL64(aOrbiterG, 41U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31249U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 29976U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 28426U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29578U)) & S_BLOCK1], 14U) ^ RotL64(aSnowLaneB[((aIndex + 27665U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 54U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 51U)) + 5131645209694953015U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 27U)) + 12070391048835379854U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 43U)) + 2604295836242338724U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 37U)) + 14042039029284001596U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 51U)) + 8914654543854559327U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 2185619407969359869U) + aNonceWordP;
            aOrbiterE = ((((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 5187406295103352574U) + aPhaseHOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8022832481290871217U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8783061916740573472U;
            aOrbiterD = RotL64((aOrbiterD * 3309891377744201773U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10711028365596196301U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13387065038269133571U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12444578026365205255U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11187001318931801582U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14191473173276034019U;
            aOrbiterK = RotL64((aOrbiterK * 2491253922434756431U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16207761776716426435U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9677408414452078760U;
            aOrbiterB = RotL64((aOrbiterB * 5487303383095129949U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17812460332794370649U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 7736423148554132028U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 15588733747232852555U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17293203944059014763U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13487243633338010243U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9468688858740539095U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15979293016815060755U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17645215484691359547U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 1449450767288733995U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 12U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 12U) + RotL64(aOrbiterI, 23U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + aNonceWordB) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 37U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
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
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneA, aWorkLaneB, aInvestLaneA, aInvestLaneB, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aInvestLaneA, aInvestLaneB, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // twist_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2715U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 1851U)) & W_KEY1], 12U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2363U)) & W_KEY1], 36U) ^ RotL64(mSource[((aIndex + 341U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 60U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 10038936806177516123U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 1773168435195292638U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 22U)) + RotL64(aCarry, 5U)) + 10655711161526628072U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 41U)) + 14422295664639740437U;
            aOrbiterG = (aWandererC + RotL64(aCross, 53U)) + 4125228715513159576U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 11U)) + 3670449653158650845U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 47U)) + 17553727567180813057U) + aPhaseAOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 27U)) + 5111401772713882743U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 60U)) + 7688573124662314413U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9438375825507814395U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14177477039902118886U;
            aOrbiterB = RotL64((aOrbiterB * 6467406626985022537U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16329942595859623928U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3990536794006836672U;
            aOrbiterK = RotL64((aOrbiterK * 579024714339065373U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5072881436583180756U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16789727877867289997U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8766246302636197905U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17313956922306689438U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11530878396329822041U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11356860047841383129U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3612616532321160196U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4172189825359187763U;
            aOrbiterF = RotL64((aOrbiterF * 12938945495299393177U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8677279703778052804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1912172980909479362U;
            aOrbiterD = RotL64((aOrbiterD * 10053289257955474143U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1460085850227494500U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12116763868122868147U;
            aOrbiterG = RotL64((aOrbiterG * 6076945628020280957U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17571840610366424432U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15581362592611080868U;
            aOrbiterE = RotL64((aOrbiterE * 1129054058044872003U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14434700039977611666U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4534294602623329152U;
            aOrbiterC = RotL64((aOrbiterC * 5860911553425182045U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 58U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 24U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterJ, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterK, 53U));
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererA, 20U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // ingress from: aWorkLaneA, aKeyRowReadA
        // ingress directions: aWorkLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 3820U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 4107U)) & W_KEY1], 44U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5002U)) & W_KEY1], 54U) ^ RotL64(mSource[((aIndex + 3488U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 47U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aScatter, 18U)) + 4634399531433127141U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 16961792729406903200U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 47U)) + 4105280732301137738U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 15692013501147331191U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 5U)) + 1252216715968780587U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 43U)) + 7958289043012473752U;
            aOrbiterB = (aWandererE + RotL64(aCross, 13U)) + 6611577301818896615U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 8506226754305949140U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 34U)) + 3648813120449403353U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5195245426245535735U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 542948051600803051U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4631106308856448475U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11974253551208964789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10596463592332655367U;
            aOrbiterE = RotL64((aOrbiterE * 10941161258815714641U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12015129484061440159U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8254944355710109060U;
            aOrbiterH = RotL64((aOrbiterH * 3233697992479357615U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2754858806943915419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5007802002906662779U;
            aOrbiterG = RotL64((aOrbiterG * 15613733948331639723U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6262190752136523216U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10528977986487821428U;
            aOrbiterA = RotL64((aOrbiterA * 1184258264034585525U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8511097226098211854U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12091864735686692582U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6128140528141411237U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4970966265236842566U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10728884018459718341U;
            aOrbiterD = RotL64((aOrbiterD * 18205183219769602827U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13760057185629905360U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6590269178744829056U;
            aOrbiterI = RotL64((aOrbiterI * 14482684769712170123U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 765826377665103262U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9364759196106579706U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10315111163659289329U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 6U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterB, 56U));
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 14U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 50U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // ingress from: aWorkLaneB, aKeyRowReadB
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aWorkLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aWorkLaneA backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneB[((aIndex + 6120U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadB[((aIndex + 5646U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6773U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6718U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7879U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 39U)) + 16519040829220310189U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 6888002778416941825U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 41U)) + 1310832187746534025U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 21U)) + 5890888009051281674U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 47U)) + 5143864838362464857U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 51U)) + 15591534069452660003U) + aPhaseAOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 1466867671765325096U;
            aOrbiterB = (aWandererK + RotL64(aCross, 35U)) + 13931443680107902488U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 12U)) + 15400747367673245552U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2836975369734495759U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2370720358274970117U;
            aOrbiterI = RotL64((aOrbiterI * 4615571902817575375U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3470677184188006133U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7175584278499266723U;
            aOrbiterJ = RotL64((aOrbiterJ * 10067096593682482345U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6095078817776863055U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2176637999243513070U;
            aOrbiterB = RotL64((aOrbiterB * 12215701810843975501U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5580391239754903129U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15196125567953871184U;
            aOrbiterD = RotL64((aOrbiterD * 12686361960729564519U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12787014151503209931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1523153207064063495U;
            aOrbiterA = RotL64((aOrbiterA * 3113907543551927561U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12973289026485937829U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9087439766232078173U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5817029335999350327U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16318022893068674015U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11089160685103562409U;
            aOrbiterH = RotL64((aOrbiterH * 17087834321385147603U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8680037953925067235U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3112588943274158119U;
            aOrbiterF = RotL64((aOrbiterF * 9214011370307670371U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16749015684369649821U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9419550535891334966U;
            aOrbiterG = RotL64((aOrbiterG * 5421312787569114811U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            aWandererD = aWandererD + ((RotL64(aIngress, 24U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterB, 53U));
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterI, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 4
        // ingress from: aInvestLaneA, aKeyRowReadB, mSource, aWorkLaneA
        // ingress directions: aInvestLaneA forward forced, aKeyRowReadB forward forced, mSource forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, aWorkLaneB backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9815U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 10524U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 8911U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 10610U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8462U)) & W_KEY1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8357U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 43U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 29U)) + 701291026547470433U) + aPhaseBOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 43U)) + 17283292650462111643U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 38U)) + 9969124091931303406U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 5U)) + 889176772718046988U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 23U)) + 6054541844643748084U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 14703226235143028132U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 13U)) + 7977975878522921062U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 16894322614172266274U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 47U)) + 12160451749345900570U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10870847008043897470U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8159920947172520247U;
            aOrbiterE = RotL64((aOrbiterE * 4833194641611011805U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2440099120969517932U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2428396147731468007U;
            aOrbiterG = RotL64((aOrbiterG * 9363073341539598441U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2213226274394673479U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7079731443427765333U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16918930776877030559U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 958896789550478970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10788682955708075458U;
            aOrbiterB = RotL64((aOrbiterB * 913321215613559729U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2003386579317564870U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8419686358774204999U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6547052526438697621U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6989167615157578904U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17636634003643824148U;
            aOrbiterH = RotL64((aOrbiterH * 11038576417283732937U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13824962118933907859U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9543912892587859646U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14736710162285997415U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15729878041027706114U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9542137475454825463U;
            aOrbiterA = RotL64((aOrbiterA * 11420547128115090491U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5327302277575009955U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2707383132257428583U;
            aOrbiterK = RotL64((aOrbiterK * 6120763309390182129U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 18U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 52U)) + aOrbiterB) + aPhaseBWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            aWandererK = aWandererK + (((RotL64(aScatter, 28U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 34U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 10U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 5
        // ingress from: aInvestLaneB, aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneB
        // ingress directions: aInvestLaneB forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aWorkLaneB forward/backward random
        // cross from: aWorkLaneA, aInvestLaneA
        // cross directions: aWorkLaneA backward forced, aInvestLaneA backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12050U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 11060U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11231U)) & W_KEY1], 56U) ^ RotL64(mSource[((aIndex + 12753U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12564U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11849U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneA[((aIndex + 12174U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 52U)) + RotL64(aCarry, 3U)) + 7632760812370906911U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 5U)) + 6007174525479723089U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 47U)) + 3362829642521821048U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 11U)) + 18009548556107978286U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 57U)) + 17880909432272697327U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 35U)) + 15961567935420752568U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 10136559064656837921U) + aPhaseBOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 42U)) + RotL64(aCarry, 41U)) + 17622019364405410277U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 27U)) + 6927494824421416306U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7125170407794874847U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12342273503071032250U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 867417849555857179U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14997696377476124836U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14874498694181230698U;
            aOrbiterB = RotL64((aOrbiterB * 4026127545746010937U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2549397729130885686U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4217995818662767955U;
            aOrbiterC = RotL64((aOrbiterC * 5525525344485251063U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4706089044415442525U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17983900172670031015U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 541552737180932879U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1904937798143929988U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10620877287033139483U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16711012562024287213U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15681091173163181525U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2655543246639000084U;
            aOrbiterH = RotL64((aOrbiterH * 16686375598149755947U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2647895110857289213U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5581609212017175954U;
            aOrbiterF = RotL64((aOrbiterF * 15330263616699031311U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13609076329627787987U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6244266279516622070U;
            aOrbiterG = RotL64((aOrbiterG * 12488345779236971095U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5289624364508923581U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16351476803965903112U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9012522724650442597U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 34U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 18U) + aOrbiterC) + RotL64(aOrbiterE, 24U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + aPhaseBWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + aPhaseBWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterE, 11U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 14U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterE, 6U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 6
        // ingress from: aFireLaneA, aInvestLaneA
        // ingress directions: aFireLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aWorkLaneB, aWorkLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aWorkLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 16072U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15370U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14181U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14520U)) & W_KEY1], 4U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15775U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13985U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15539U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 22U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aScatter, 23U)) + 5960680319644404115U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 16050752633567034185U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 38U)) + 8447503223226854741U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 14176813813397917591U) + aPhaseBOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 5U)) + 10534915376130006644U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 47U)) + 6866224454375302514U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 16506374165041008396U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 34U)) + 7167814023968794098U;
            aOrbiterF = (aWandererB + RotL64(aCross, 57U)) + 13870852197416596664U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 18064038854848993105U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9869630811507771691U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13723164383800461387U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 863613100452759380U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16597969741225436529U;
            aOrbiterD = RotL64((aOrbiterD * 2680793528887208903U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6575347108051310653U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17062262265485019063U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7601045488473620019U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7193399224636409133U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14146747818810433849U;
            aOrbiterC = RotL64((aOrbiterC * 5273185769989530041U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9441449106442431427U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4303295336545399503U;
            aOrbiterH = RotL64((aOrbiterH * 8829695296836242587U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12604760768543193458U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15779327512379787715U;
            aOrbiterF = RotL64((aOrbiterF * 14000905201441272597U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15553000781122708728U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17162740616060079717U;
            aOrbiterK = RotL64((aOrbiterK * 9458662233556750239U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1032374679817715156U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16413393156165548232U;
            aOrbiterJ = RotL64((aOrbiterJ * 549659738811935015U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14056855000013992045U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7399202019042538829U;
            aOrbiterG = RotL64((aOrbiterG * 6103508549612077695U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 38U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + aPhaseBWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 18U) + aOrbiterG) + RotL64(aOrbiterF, 56U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 41U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 34U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aPhaseBWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 7
        // ingress from: aFireLaneB, aKeyRowReadA, mSource, aWorkLaneA
        // ingress directions: aFireLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadB, aInvestLaneB, aFireLaneA
        // cross directions: aKeyRowReadB backward forced, aInvestLaneB backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 18578U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 18216U)) & W_KEY1], 12U));
            aIngress ^= (RotL64(mSource[((aIndex + 17481U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18314U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17854U)) & W_KEY1], 4U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16488U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17036U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 56U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 3U)) + 16424657151168221875U) + aPhaseCOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 51U)) + 17150123681886380361U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 60U)) + 16041993588694572757U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 27U)) + 9871185846434828537U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 19U)) + 11227236398354430757U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 43U)) + 5399325217402192631U) + aPhaseCOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 47U)) + 9248828789282890454U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 9041370494203701062U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 35U)) + 14944424084524970764U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5481938174456671041U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14783648629543752715U;
            aOrbiterA = RotL64((aOrbiterA * 7260164783191886395U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12355573914530445723U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9863991559011968318U;
            aOrbiterH = RotL64((aOrbiterH * 8495251211794343179U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16149688605937250965U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 106041828692026825U;
            aOrbiterF = RotL64((aOrbiterF * 12199934305374582599U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8076098639554567792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11155119311895580013U;
            aOrbiterG = RotL64((aOrbiterG * 1495180896564818647U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6847612160595917702U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16094377920388017367U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4875801863643206333U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13584719866672696684U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13446209321646234607U;
            aOrbiterC = RotL64((aOrbiterC * 9945349065094781529U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15829806645369560988U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12573767256739062550U;
            aOrbiterB = RotL64((aOrbiterB * 5649504278826069077U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3850030870300393809U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11857593987748189858U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15942863910931814193U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5505918410521728373U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12949653497121247860U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 90944913639560027U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 22U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterB, 23U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterK, 52U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 26U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 60U));
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 8
        // ingress from: aFireLaneC, mSource, aFireLaneA, aWorkLaneA
        // ingress directions: aFireLaneC forward forced, mSource forward forced, aFireLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aFireLaneB, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aFireLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 20876U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 19662U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19354U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21043U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21042U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20312U)) & W_KEY1], 21U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21540U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21593U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 40U)) + 12426357877879529292U) + aPhaseCOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 57U)) + 12604900366173639176U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 13511119007338929401U) + aPhaseCOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 9878720081166788060U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 19U)) + 15463195409806395076U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 6407922778852833423U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 6U)) + 7690427254160734016U;
            aOrbiterC = (aWandererK + RotL64(aCross, 53U)) + 18030974031722143619U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 13U)) + 17983938038322737041U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16605512170117753884U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 681802273302348322U;
            aOrbiterK = RotL64((aOrbiterK * 14608920184802647123U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15550312921312083819U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17824154101711884508U;
            aOrbiterD = RotL64((aOrbiterD * 7358612830654795357U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1939207786756735430U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3132864634777826569U;
            aOrbiterE = RotL64((aOrbiterE * 13606281919426730325U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12822929773923954849U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16576106045887115660U;
            aOrbiterH = RotL64((aOrbiterH * 16370914370769903051U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2398825881649235260U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13700821892926092479U;
            aOrbiterA = RotL64((aOrbiterA * 10830623703416956043U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2439833784883391606U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15870638514107637833U;
            aOrbiterC = RotL64((aOrbiterC * 3797380922767479287U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9165457123134229670U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8736642509192659417U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16219277537523484065U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9232719746484835693U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7826680628853322541U;
            aOrbiterF = RotL64((aOrbiterF * 12578050118133526187U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14323652326982518782U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2254524512851399313U;
            aOrbiterI = RotL64((aOrbiterI * 4119339547645451149U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterK, 18U));
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 37U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterD, 12U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 46U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 9
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, aFireLaneC
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aFireLaneC forward/backward random
        // cross from: mSource, aFireLaneA, aInvestLaneA, aInvestLaneB
        // cross directions: mSource backward forced, aFireLaneA backward forced, aInvestLaneA backward forced, aInvestLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 24226U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 22515U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24250U)) & W_KEY1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22483U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24059U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23204U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23686U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneB[((aIndex + 21951U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererF + RotL64(aCross, 34U)) + 17668251151213543491U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 51U)) + 16101602509895104517U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 5U)) + 9083915270773304935U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 57U)) + 12810720730318214811U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 18113428002071925621U) + aPhaseCOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 12U)) + RotL64(aCarry, 11U)) + 1582208899354109878U) + aPhaseCOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 4180688104819188154U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 21U)) + 8954598189262820611U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 47U)) + 15360094153175355879U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8383954114668216260U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15626783326234049197U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15058420415480073793U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10609978564404958066U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17656516608997517984U;
            aOrbiterC = RotL64((aOrbiterC * 4590620354119899777U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 760077259110786536U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3597338735888033063U;
            aOrbiterI = RotL64((aOrbiterI * 6548831472863517621U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4431777844935985157U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10710423172154671296U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16267496318491473315U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10240882795242085185U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7826053487019825891U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15053729937684375907U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9418883403715727353U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11507423614799075545U;
            aOrbiterB = RotL64((aOrbiterB * 16189463984557044693U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11545217316421066655U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 617921402135485341U;
            aOrbiterH = RotL64((aOrbiterH * 8182920764965471653U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14456933220749921009U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7990243583564535387U;
            aOrbiterE = RotL64((aOrbiterE * 5994900368027985469U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14023633125757654751U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11319146808574958827U;
            aOrbiterG = RotL64((aOrbiterG * 13676159969338309307U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 14U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterA, 34U));
            aWandererC = aWandererC + (((RotL64(aCross, 14U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 36U) + aOrbiterA) + RotL64(aOrbiterK, 44U)) + aPhaseCWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aFireLaneD, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aFireLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aFireLaneC, aInvestLaneB
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aFireLaneC backward forced, aInvestLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 27287U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 25674U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24865U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26587U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26977U)) & W_KEY1], 12U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26865U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24620U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((aIndex + 24694U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 50U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererK + RotL64(aPrevious, 37U)) + 6733949564325516029U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 7304098437143918796U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 48U)) + 3923949518391777800U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 29U)) + 14243591003388927124U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 18329498724605410406U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 23U)) + 13118172167747037249U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 3U)) + 5272025143849174212U) + aPhaseDOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 16075917179214318424U) + aPhaseDOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 12U)) + 15263590648674658399U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13730046728289525921U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7703141464499623408U;
            aOrbiterI = RotL64((aOrbiterI * 5886009900621521987U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1382279753822135359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2973369221699098292U;
            aOrbiterE = RotL64((aOrbiterE * 7440242040663550631U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11578274119583013219U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3419411247737896674U;
            aOrbiterC = RotL64((aOrbiterC * 17814942652262802991U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2582783513078999303U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3959762790273529677U;
            aOrbiterK = RotL64((aOrbiterK * 383974377372162751U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 465795011576934604U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17880826624185821135U;
            aOrbiterH = RotL64((aOrbiterH * 4445949147592860913U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10819659185349413173U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17298208553586835030U;
            aOrbiterB = RotL64((aOrbiterB * 1965860510614222093U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12585880006661489402U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16650193903267408586U;
            aOrbiterF = RotL64((aOrbiterF * 5781132589396936615U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 885882046325991589U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 869560078374809974U;
            aOrbiterJ = RotL64((aOrbiterJ * 13440973563438747181U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11871305571797951851U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12137095015607196226U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7618152256560808581U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 46U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 6U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 60U));
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 54U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 11
        // ingress from: aExpandLaneB, aFireLaneD, aKeyRowReadB, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aFireLaneD forward forced, aKeyRowReadB forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27464U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneD[((aIndex + 28047U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29759U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((aIndex + 29028U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29270U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29445U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28248U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 28517U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 24U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 9855743441035905047U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 39U)) + 8426286937143990276U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 7146752367170267002U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 12947210066678101726U;
            aOrbiterB = (aWandererK + RotL64(aCross, 29U)) + 15902163559925328965U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 5U)) + 8506649889346449469U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 47U)) + 8226286036430263052U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 51U)) + 2703047093452420216U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 34U)) + 6769351326360139560U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9857025533281333281U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 238297452132277585U;
            aOrbiterD = RotL64((aOrbiterD * 12974709749856065985U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7203572312072908931U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12497027346166575632U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1703586436725662307U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 473851890609048879U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1664484956453886047U;
            aOrbiterG = RotL64((aOrbiterG * 8566500756326590209U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4635095143004754116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17695676150967345793U;
            aOrbiterI = RotL64((aOrbiterI * 5780416541584439301U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15628965269863402796U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9190117464399730235U;
            aOrbiterC = RotL64((aOrbiterC * 5586437438425999715U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17835918238346011086U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4398005402429282682U;
            aOrbiterE = RotL64((aOrbiterE * 14828737209913317463U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10902589938246551273U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15124274429081385923U;
            aOrbiterA = RotL64((aOrbiterA * 13524180348258805367U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8747233520702236018U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5445611443463112371U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10294109295823410447U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16296005217836151910U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6468336224317602364U;
            aOrbiterH = RotL64((aOrbiterH * 7369779919748367133U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 22U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 44U) + aOrbiterF) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterE, 10U));
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 41U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 46U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aFireLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aFireLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 30980U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 31352U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31744U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32006U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30079U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31917U)) & W_KEY1], 48U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 35U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererG + RotL64(aIngress, 41U)) + 4739486756133131180U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 34U)) + 16089707555501328184U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 15310047330238536453U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 7901411596386834955U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 11U)) + 4357555491060982163U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 57U)) + 15667085602825720102U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 5U)) + 8520635334382269253U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 53U)) + 1772509779231068315U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 18U)) + RotL64(aCarry, 3U)) + 15336170957886025677U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8628770833489469980U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15469234024247246228U;
            aOrbiterI = RotL64((aOrbiterI * 8905266995119987947U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10796430900884288328U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10660110397012853289U;
            aOrbiterG = RotL64((aOrbiterG * 9140007610912037461U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11202284258711214794U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17509491802893182994U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9329107599972703671U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16212572740740103554U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2190030203761579226U;
            aOrbiterJ = RotL64((aOrbiterJ * 3101886685668871045U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12014337082293041909U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3733531010807001506U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5797362244066062299U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7100994963061975529U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17837541162838600258U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8745987361678166553U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3311518938023146951U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7709505172646831553U;
            aOrbiterC = RotL64((aOrbiterC * 7121143171245765213U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4979968094554018443U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16822214821463034107U;
            aOrbiterF = RotL64((aOrbiterF * 8618262120451291765U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8376124175020587079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11084586282092424876U;
            aOrbiterD = RotL64((aOrbiterD * 5835632742522563537U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 20U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 6U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterD) + aPhaseDWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 30U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 43U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 52U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 60U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 44U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 666U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2101U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4876U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 1242U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 18U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 14157904117287696136U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 13U)) + 7369512677371640676U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 39U)) + 8411250745902073798U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 5002041814539710275U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 53U)) + 9538041410816283124U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 47U)) + 5210700103927513061U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 21U)) + 7600709399101287982U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2366369466696580499U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5544575244203019109U;
            aOrbiterC = RotL64((aOrbiterC * 16231219246786333057U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8710073749110329779U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15998211310115361630U;
            aOrbiterK = RotL64((aOrbiterK * 15275657696897688955U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15354357553877376422U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10657523549259276169U;
            aOrbiterA = RotL64((aOrbiterA * 13695239532898311073U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10405750198355464768U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3465819693133515142U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14678343718277562799U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16724189641701408630U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3484340153620198872U;
            aOrbiterF = RotL64((aOrbiterF * 17247547677520703125U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7420442404884871126U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11138445997256757636U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11167543379937571127U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1428191560884663125U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16950093140800653985U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4423012306984814805U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 58U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneA
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9601U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 5577U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8606U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10309U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 9188U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 11274974230580265396U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 53U)) + 16658438747342741547U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 35U)) + 16612986966106053844U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 4U)) + 9329502236843231290U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 14088261356708344656U) + aPhaseEOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 13692608802007789581U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 27U)) + 6824473946645682398U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2072915876348570040U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7420507753044460759U;
            aOrbiterC = RotL64((aOrbiterC * 13239288539564571257U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4677557318688502593U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15081678577055628459U;
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7026792817486507482U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14871665922943969918U;
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6807734532159292872U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17882797335141303280U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15439872930381050291U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9233542707022629190U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1205501586581350876U;
            aOrbiterF = RotL64((aOrbiterF * 2596053290311090589U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 10878718669747466677U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8066049063548639241U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3031382633089381605U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 861295180226875235U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9134969787937288583U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7565008208670843555U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 4U) + aOrbiterE) + RotL64(aOrbiterF, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 48U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterH, 39U));
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 48U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15317U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 11806U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11575U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11727U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10928U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 15552U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 18U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererH + RotL64(aScatter, 13U)) + 13350544654542863236U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 12364346790125404372U) + aPhaseEOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 19U)) + 9738750172849512764U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 35U)) + 3781373837635491421U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 47U)) + 16635020317512702337U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 6U)) + RotL64(aCarry, 5U)) + 5383653921676231276U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 10181959815492056493U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10005510924273927017U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9524687662265740565U;
            aOrbiterA = RotL64((aOrbiterA * 13687380438646756931U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4259138552009771014U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8973051213213726023U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12625091476068190979U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17602611840127337490U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8218984546932905269U;
            aOrbiterC = RotL64((aOrbiterC * 17504305273683304231U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18102186122213487888U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2629927500298092976U;
            aOrbiterI = RotL64((aOrbiterI * 6983280164448292723U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2491581597835795234U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9506602492971620955U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9559829640915637163U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13422942713680612924U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15037354693234876601U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12692376075738621447U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12896066842192894694U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2202952306291905855U;
            aOrbiterH = RotL64((aOrbiterH * 6779368532763429997U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 12U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 13U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 6U) + RotL64(aOrbiterG, 4U)) + aOrbiterC) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16863U)) & S_BLOCK1], 44U) ^ RotL64(aInvestLaneC[((aIndex + 18894U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 19150U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17239U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16706U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 16555U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 26U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 17074147006464019918U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 43U)) + 10559516626129419928U) + aPhaseEOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 13280363679503946221U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 6U)) + 17657115422132457413U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 13325837013304973008U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 19U)) + 3059707750486106037U;
            aOrbiterK = (aWandererA + RotL64(aCross, 27U)) + 4529045702503050852U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10726578475550904292U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14832537837996659885U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 808060368961520519U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 220094417441809246U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15343130035105342194U;
            aOrbiterE = RotL64((aOrbiterE * 7984652435043810845U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16592263353426409884U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15649290906447931918U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8405875177836650731U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11437410545843708269U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5859769136073011444U;
            aOrbiterJ = RotL64((aOrbiterJ * 1065016088086441107U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15188064100307340341U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4367466521843260049U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15916715854192820923U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8482617283860566845U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2585745804937342972U;
            aOrbiterB = RotL64((aOrbiterB * 8267269625632139809U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1687641344403425541U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13667916445979421400U;
            aOrbiterK = RotL64((aOrbiterK * 8191322670355590027U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 28U)) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 5U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 20U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 5
        // ingress from: aOperationLaneB, aOperationLaneA, aExpandLaneB
        // ingress directions: aOperationLaneB forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aExpandLaneC, aInvestLaneC, aInvestLaneD
        // cross directions: aExpandLaneC backward forced, aInvestLaneC backward forced, aInvestLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27134U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((aIndex + 23188U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24163U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25775U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23358U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 24153U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 34U)) + RotL64(aCarry, 37U)) + 785861751704720606U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 57U)) + 15968088718435606299U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 1393976526590347151U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 43U)) + 17240750947292745884U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 27U)) + 4921576136163183137U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 3334047873553153032U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 11U)) + 15086509978458408698U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 892391205397581998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2965686403183767521U;
            aOrbiterF = RotL64((aOrbiterF * 709160942482770225U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14632215393655706170U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15740589515342377322U;
            aOrbiterH = RotL64((aOrbiterH * 15677716942904794913U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11131164813943086445U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6988080581278900960U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6412189142344044255U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16021254613117657178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6183615599897921154U;
            aOrbiterE = RotL64((aOrbiterE * 9976411093264211033U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12533992547026652747U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3104325358982904219U;
            aOrbiterI = RotL64((aOrbiterI * 14977348108778147265U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3878525937957474644U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2120435259884368445U;
            aOrbiterK = RotL64((aOrbiterK * 15964718652193073177U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14928658302694194856U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9121310461310309348U;
            aOrbiterA = RotL64((aOrbiterA * 17304439784647477491U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 34U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 27U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 41U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterH, 60U));
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 6
        // ingress from: aOperationLaneC, aExpandLaneA, aExpandLaneB
        // ingress directions: aOperationLaneC forward forced, aExpandLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneB, aOperationLaneA, aInvestLaneD
        // cross directions: aOperationLaneB backward forced, aOperationLaneA backward forced, aInvestLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27461U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 32582U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32738U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32428U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28682U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 31696U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 50U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 38U)) + 12692813903177772178U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 11U)) + 7112496446691277899U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 27U)) + 2112247138290568813U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 21U)) + 3699421080882855947U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 13761832028354380922U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 9243822514887600214U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 6863833516853046129U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8863897995943098018U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13346785686701467520U;
            aOrbiterA = RotL64((aOrbiterA * 18074843497158380703U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15309543066305531619U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17515530938817919111U;
            aOrbiterK = RotL64((aOrbiterK * 16625193986319048245U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 760493237816424254U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7282586354117620860U;
            aOrbiterB = RotL64((aOrbiterB * 2327153408185290635U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4129706068526969105U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7020175432730888755U;
            aOrbiterD = RotL64((aOrbiterD * 10095158356907592239U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9102258982216515596U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10822031305361453690U;
            aOrbiterH = RotL64((aOrbiterH * 2036205056490578491U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12571477440964330246U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8436347026653095199U;
            aOrbiterE = RotL64((aOrbiterE * 17930734781213681573U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14214789872073941940U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12915911919403385001U;
            aOrbiterG = RotL64((aOrbiterG * 13161681603528031511U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 26U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 54U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 41U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneA, aExpandLaneC, aExpandLaneB, aSnowLaneB, aExpandLaneD, aWorkLaneA, aExpandLaneA, aWorkLaneB, aInvestLaneA, aWorkLaneC, aInvestLaneD
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3529U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((aIndex + 2536U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 336U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2297U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4976U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 673U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 37U)) + 13350544654542863236U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 13U)) + 12364346790125404372U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 9738750172849512764U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 54U)) + RotL64(aCarry, 57U)) + 3781373837635491421U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 57U)) + 16635020317512702337U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 47U)) + 5383653921676231276U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 3U)) + 10181959815492056493U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 43U)) + 10005510924273927017U;
            aOrbiterB = (aWandererK + RotL64(aCross, 41U)) + 9524687662265740565U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 18U)) + RotL64(aCarry, 53U)) + 4259138552009771014U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 39U)) + 8973051213213726023U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17602611840127337490U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8218984546932905269U;
            aOrbiterF = RotL64((aOrbiterF * 17504305273683304231U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 18102186122213487888U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2629927500298092976U;
            aOrbiterH = RotL64((aOrbiterH * 6983280164448292723U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2491581597835795234U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9506602492971620955U;
            aOrbiterG = RotL64((aOrbiterG * 9559829640915637163U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13422942713680612924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15037354693234876601U;
            aOrbiterI = RotL64((aOrbiterI * 12692376075738621447U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12896066842192894694U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2202952306291905855U;
            aOrbiterK = RotL64((aOrbiterK * 6779368532763429997U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12160313482450599313U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10812986281270407756U;
            aOrbiterC = RotL64((aOrbiterC * 7786608700746771809U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12474638293190144525U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5882870951276225224U;
            aOrbiterB = RotL64((aOrbiterB * 15532427302173572457U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3782896138051179209U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10965680631059882311U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14060923998307082385U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15650420683333746952U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4110674660963676864U;
            aOrbiterE = RotL64((aOrbiterE * 11724979274890265275U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 694817156953099464U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4402927404825116007U;
            aOrbiterA = RotL64((aOrbiterA * 579586789292520113U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6849178151532923489U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13350544654542863236U;
            aOrbiterJ = RotL64((aOrbiterJ * 2416097748778941523U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 44U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 29U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterG, 24U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterI, 53U));
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 51U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterD, 5U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 40U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6194U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 8447U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6292U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((aIndex + 5665U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5561U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6237U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 7441U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererA + RotL64(aPrevious, 48U)) + 10726035965553989335U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 967354339530195662U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 10834593005478605624U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 27U)) + 1012888282838656933U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 11U)) + 15283530351725183253U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 23U)) + 11724495956731703750U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 39U)) + 4288330117317505776U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 54U)) + RotL64(aCarry, 51U)) + 10894778070022873473U;
            aOrbiterE = (aWandererK + RotL64(aCross, 37U)) + 15563886747621617467U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 41U)) + 11182488628562891937U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 29U)) + 10420140066310588580U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11775138062167543111U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16545391898578161683U;
            aOrbiterC = RotL64((aOrbiterC * 14588306527161321535U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1550144656312299266U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14903504853138279883U;
            aOrbiterI = RotL64((aOrbiterI * 8003033561266164387U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 309935535526750396U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13991265868040011411U;
            aOrbiterF = RotL64((aOrbiterF * 2887531132228588441U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1755976294857114222U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2259275858478396846U;
            aOrbiterE = RotL64((aOrbiterE * 7416165760067878161U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4838175912944552936U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12307900457200936013U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14719363144850838805U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18025411832912225805U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 981375022769564523U;
            aOrbiterB = RotL64((aOrbiterB * 15869361544011831483U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3174014054982742562U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8119692378748963609U;
            aOrbiterD = RotL64((aOrbiterD * 3072354179707448489U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14502863160788675807U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1207582534593709516U;
            aOrbiterA = RotL64((aOrbiterA * 3045412087535529357U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5838011917777875072U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 434594114594643600U;
            aOrbiterH = RotL64((aOrbiterH * 1591023655239709931U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15711060039063734443U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8307150522686198490U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2082452039297764679U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5805686529930815226U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10726035965553989335U;
            aOrbiterK = RotL64((aOrbiterK * 5563221485243331689U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 34U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 56U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterI, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterK, 14U));
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13987U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((aIndex + 12906U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16198U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14168U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13462U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererJ + RotL64(aCross, 34U)) + 15036852811491820366U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 27U)) + 305637140752898475U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 41U)) + 11948631574496129610U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 5321623592482991426U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 36U)) + 4075270159062690728U;
            aOrbiterH = (aWandererH + RotL64(aCross, 57U)) + 15111580500356908928U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 7244150695504160363U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 51U)) + 5131563519577488862U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 5881954992088651371U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 11U)) + 12780935808751507998U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 5U)) + 12599159643925470226U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9466589929741834066U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6093158735705189789U;
            aOrbiterA = RotL64((aOrbiterA * 7453778295800853653U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17461243886150519249U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15456408913739900718U;
            aOrbiterC = RotL64((aOrbiterC * 16093292401746174671U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11260643903290392780U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7870342756041882616U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2431528656086173419U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 134484990005888936U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10626896209992890407U;
            aOrbiterB = RotL64((aOrbiterB * 12034131076645285597U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14031164129515132292U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1771835705730244212U;
            aOrbiterJ = RotL64((aOrbiterJ * 186981668443596623U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16395472745067254664U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1455944290845294254U;
            aOrbiterK = RotL64((aOrbiterK * 6757824754363319079U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17866422769075350837U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10226884082632410805U;
            aOrbiterG = RotL64((aOrbiterG * 206035536985843815U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14474587247775371703U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8501763445324525303U;
            aOrbiterD = RotL64((aOrbiterD * 5298694643596784007U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 222650368553738561U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3901452368735982094U;
            aOrbiterF = RotL64((aOrbiterF * 18347115513126660483U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3063093906728331146U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9026710562384443411U;
            aOrbiterE = RotL64((aOrbiterE * 8411243802199203035U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11282041925238364080U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15036852811491820366U;
            aOrbiterI = RotL64((aOrbiterI * 18185121326941087841U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterB, 50U));
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterB, 11U));
            aWandererB = aWandererB + (((RotL64(aScatter, 52U) + aOrbiterG) + RotL64(aOrbiterB, 47U)) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 36U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 6U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17450U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneA[((aIndex + 19937U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 20619U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19583U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16960U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 27U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aScatter, 11U)) + 18191288703716505885U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 13U)) + 9824014524910417136U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 54U)) + 11953012029254917548U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 6297568011027199089U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 23U)) + 2576999400457367975U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 13176139160575558254U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 47U)) + 9978408174563621810U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 44U)) + 16765834875061607142U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 16534507305459121344U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 5U)) + 3114710944346151807U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 57U)) + 10240517868726718592U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10721450637990777883U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16689590768796583952U;
            aOrbiterE = RotL64((aOrbiterE * 3046344179729901637U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2427422768928450209U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13495584061816457831U;
            aOrbiterG = RotL64((aOrbiterG * 6670984773768885119U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7058636403765106682U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9897341853944713767U;
            aOrbiterB = RotL64((aOrbiterB * 14286816859999869231U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17749559755733386064U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12515645083926326659U;
            aOrbiterD = RotL64((aOrbiterD * 6582878478865838245U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2625692458813609962U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10596240255026143019U;
            aOrbiterF = RotL64((aOrbiterF * 11605800195771080135U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12374290338067865540U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1507386663796330249U;
            aOrbiterK = RotL64((aOrbiterK * 1210241080424446087U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9288099549484146726U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15159312464747000702U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 500055502081347757U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14998608679505446229U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17625038109437732009U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14785862243019841689U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10543192232885637211U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10330547522729618042U;
            aOrbiterJ = RotL64((aOrbiterJ * 7635903835474874057U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5753298214283941201U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15943436872588208065U;
            aOrbiterC = RotL64((aOrbiterC * 17704547766822075741U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5757218926946874970U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18191288703716505885U;
            aOrbiterH = RotL64((aOrbiterH * 2644970408001409575U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 42U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterF, 52U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 50U) + aOrbiterA) + RotL64(aOrbiterJ, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 26U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 26U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterE, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 21U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererD, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24678U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneB[((aIndex + 23074U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22399U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25263U)) & S_BLOCK1], 14U) ^ RotL64(aSnowLaneA[((aIndex + 23453U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 40U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 23U)) + 7075016829833562104U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 43U)) + 8783765886115517036U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 60U)) + 2996723892384565829U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 9494134707342189476U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 5U)) + 5052642981395679904U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 39U)) + 8766787055127962238U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 14U)) + 4467211954388738079U;
            aOrbiterH = (aWandererE + RotL64(aCross, 37U)) + 8030255604633658608U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 16962408063455702251U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 57U)) + 3768222186567699076U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 14930990410207899871U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14179761938395502502U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1879084742719898108U;
            aOrbiterG = RotL64((aOrbiterG * 16783034788172670121U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5535012408925981515U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12792553516710295939U;
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8979253163346099252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5559189896063990740U;
            aOrbiterH = RotL64((aOrbiterH * 8832485423727331621U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13937564337299044079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2393376759689394948U;
            aOrbiterB = RotL64((aOrbiterB * 2352815657830413941U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12647519563697356479U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 10946871249960389549U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6272580371881237173U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13376798695582123147U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10958115913599631271U;
            aOrbiterC = RotL64((aOrbiterC * 18233981473003345217U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4283914227806672773U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 910842005516235816U;
            aOrbiterF = RotL64((aOrbiterF * 6722229871617873429U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 1509644316619370324U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 165987596716078174U;
            aOrbiterD = RotL64((aOrbiterD * 13600064054240185123U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12491315345199091186U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5982431705686495125U;
            aOrbiterE = RotL64((aOrbiterE * 2547243804779022665U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 231183123382412440U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2872632389683254396U;
            aOrbiterK = RotL64((aOrbiterK * 1972278820468847241U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15259314110008210315U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7075016829833562104U;
            aOrbiterJ = RotL64((aOrbiterJ * 8350093877370898869U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 54U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 26U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 13U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterB, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 24U) + aOrbiterE) + RotL64(aOrbiterD, 30U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 57U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterE, 39U)) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 51U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31220U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((aIndex + 32086U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 28385U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31201U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30282U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 20U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererG + RotL64(aScatter, 13U)) + 4752759164691497960U) + aPhaseFOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 44U)) + 12088872623537639782U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 39U)) + 3734943577379734227U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 8854778183012444234U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 21U)) + 16948373492893967275U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 47U)) + 7962415690046184385U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 6U)) + 1872682375669714454U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 19U)) + 7776801806943853566U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 41U)) + 16665439117257230732U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 11088186766134265676U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 10850237991780969350U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6464817712131305812U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 244557182884209844U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2394270354887582889U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13261563971157415841U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2323811103717827362U;
            aOrbiterC = RotL64((aOrbiterC * 11483723582415081925U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12338803568475493422U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2811342930111104982U;
            aOrbiterF = RotL64((aOrbiterF * 5020981755203607757U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5554497011738996057U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12712169745460598698U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1985586486150377769U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17415058661427002973U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9430421222715343818U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10321140659099470811U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3926618548181233180U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6172453297026957838U;
            aOrbiterJ = RotL64((aOrbiterJ * 1161551082037835233U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8633288765997226004U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17270881130844274342U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8888559940161770791U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12232950994807835262U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15352600312956742750U;
            aOrbiterK = RotL64((aOrbiterK * 6140396356904933003U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5614120002595447983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1920822446545182835U;
            aOrbiterH = RotL64((aOrbiterH * 17049182594382482085U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 625576652179261739U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2362773059031414585U;
            aOrbiterA = RotL64((aOrbiterA * 17049048587829564949U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16749690978107177915U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4752759164691497960U;
            aOrbiterI = RotL64((aOrbiterI * 8442185754037031199U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 22U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterC, 54U));
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 44U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterD, 26U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 878U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 7247U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 2312U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 419U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6697U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 524U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 47U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 53U)) + 7896237440058555694U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 11870529476037558635U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 37U)) + 9158983227801569448U) + aPhaseGOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 4710172270996950329U) + aPhaseGOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 23U)) + 14634482800356647630U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8822207952170610891U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 13755891414028982553U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5173750624716006485U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4555293067488040719U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2816805148093762081U;
            aOrbiterH = RotL64((aOrbiterH * 16838149138341713943U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2122631477965135190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4592922416380416071U;
            aOrbiterI = RotL64((aOrbiterI * 11644507904538573165U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7102471666524164715U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17274623547879474204U;
            aOrbiterK = RotL64((aOrbiterK * 5443572270546181789U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 938587316977094680U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 18258015823797023523U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6068819567674605919U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 44U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 20U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterE, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13224U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 16130U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12166U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11371U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15558U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 11216U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 24U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 8101351470141807662U) + aPhaseGOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 28U)) + RotL64(aCarry, 29U)) + 6965474099521076705U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 6803828268885684784U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 11U)) + 13454235922950972488U) + aPhaseGOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 57U)) + 11678091885751244777U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5307134544628507141U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4873703518950429353U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2680442582958424915U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8542156221858586039U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3993726182905296513U;
            aOrbiterI = RotL64((aOrbiterI * 11331376012938127609U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12113047622035464386U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1944244448665721151U;
            aOrbiterJ = RotL64((aOrbiterJ * 7010050836758762003U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12914188029425467576U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2486762763475327024U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12319769994433811617U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14580191602982245481U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12093414832400135066U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12720286833215690663U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 14U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 42U) + aOrbiterJ) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterK, 5U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 53U)) + aPhaseGWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21092U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 22841U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19788U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23656U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16861U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 20553U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 24U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererE + RotL64(aCross, 3U)) + 6733949564325516029U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 21U)) + 7304098437143918796U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 3923949518391777800U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 30U)) + RotL64(aCarry, 23U)) + 14243591003388927124U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 18329498724605410406U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13118172167747037249U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5272025143849174212U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9935990954321437743U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16075917179214318424U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15263590648674658399U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9918239923411740337U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13730046728289525921U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7703141464499623408U;
            aOrbiterF = RotL64((aOrbiterF * 5886009900621521987U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1382279753822135359U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2973369221699098292U;
            aOrbiterB = RotL64((aOrbiterB * 7440242040663550631U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 11578274119583013219U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3419411247737896674U;
            aOrbiterI = RotL64((aOrbiterI * 17814942652262802991U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterF, 53U));
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + RotL64(aOrbiterI, 4U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 12U) + RotL64(aOrbiterI, 21U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 35U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27888U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 31201U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 28594U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30968U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24963U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31815U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aIngress, 57U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 47U)) + 252059974543142812U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 11690823093681457368U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 13282189752890971123U) + aPhaseGOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 57U)) + 9507416294305708435U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 43U)) + 14053038174390776539U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14605253312318725009U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18138286582677863671U;
            aOrbiterJ = RotL64((aOrbiterJ * 10595905899691011321U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8530091235978489988U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14381731677571170073U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11675896999665768253U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13316413456378978456U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3910529530149320706U;
            aOrbiterG = RotL64((aOrbiterG * 16000139333493588429U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6302070286831566901U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12324134652758551396U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17136438281540250165U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4773478557638475048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4031153435446078944U;
            aOrbiterC = RotL64((aOrbiterC * 3876928995240982769U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterI, 39U));
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

    std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3462U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 1239U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 5387U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4468U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1477U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3487U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 30U)) + 5568146815535263910U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 7736084960873834666U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 1336413621817562093U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 5218462026934984692U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 47U)) + 7048890985969555935U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13415955213864702118U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5657023257021528548U;
            aOrbiterH = RotL64((aOrbiterH * 5200798937081797819U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14338310943137497116U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12305161641833950473U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11949964304435964395U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14514226578370459131U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12692904083266024340U;
            aOrbiterD = RotL64((aOrbiterD * 14800805065279908839U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11012959130001327964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7106471380403489078U;
            aOrbiterK = RotL64((aOrbiterK * 515626559384817223U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3718101961355280891U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13364192077222322664U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1411328915372590283U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 14U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 53U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterD, 41U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 36U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13757U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 15649U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 12367U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8850U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14567U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13696U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 13U)) + 17668251151213543491U) + aPhaseHOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 16101602509895104517U) + aPhaseHOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 9083915270773304935U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 12810720730318214811U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 46U)) + 18113428002071925621U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1582208899354109878U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 4180688104819188154U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3391785441902730815U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8954598189262820611U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15360094153175355879U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8177798855402983685U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8383954114668216260U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15626783326234049197U;
            aOrbiterF = RotL64((aOrbiterF * 15058420415480073793U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10609978564404958066U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17656516608997517984U;
            aOrbiterK = RotL64((aOrbiterK * 4590620354119899777U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 760077259110786536U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3597338735888033063U;
            aOrbiterC = RotL64((aOrbiterC * 6548831472863517621U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 50U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 22U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + aPhaseHWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22684U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 22632U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 22253U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19825U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20385U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24444U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 5U)) + 12849591986267890852U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 8232614804696815750U) + aPhaseHOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 56U)) + RotL64(aCarry, 41U)) + 12141567259210877281U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 2928641981037885644U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 13U)) + 980733350554783938U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 2683985177993350746U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14532148403815527355U;
            aOrbiterI = RotL64((aOrbiterI * 15985362037094864225U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7736296629433884203U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10428437770166310549U;
            aOrbiterE = RotL64((aOrbiterE * 326634742742373401U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 18327174144859461029U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6810436935194432002U;
            aOrbiterJ = RotL64((aOrbiterJ * 2715987179577753597U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12606153309690753435U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17123256945895150555U;
            aOrbiterD = RotL64((aOrbiterD * 13469111258504672565U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9057777759026189541U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16478485918911194442U;
            aOrbiterG = RotL64((aOrbiterG * 11054247078884894131U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 54U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25826U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 25048U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 26842U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25711U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31145U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32290U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 37U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 4U)) + 2330952702412094686U) + aPhaseHOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 7820188225935060799U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 9347644591709839145U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 2288624878446846870U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 35U)) + 9358977729492824128U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1858511275052455039U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13715478509322292552U;
            aOrbiterI = RotL64((aOrbiterI * 15552121744869003235U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16413396625604260455U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17714322215518432705U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1904184102419934333U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16188315436202861122U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5564445841368207813U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14125834616162835983U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13717068949900594673U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14143659432287313765U;
            aOrbiterD = RotL64((aOrbiterD * 17281441046722262917U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5729546141908425670U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4297827922736712074U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13631630436759768885U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterD, 22U)) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 11U));
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
